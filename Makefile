#
# (C) Copyright 2000-2006
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundatio; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

ifneq ($(BUILD_DIR),)
saved-output := $(BUILD_DIR)

# Attempt to create a output directory.
$(shell [ -d ${BUILD_DIR} ] || mkdir -p ${BUILD_DIR})

# Verify if it was successful.
BUILD_DIR := $(shell cd $(BUILD_DIR) && /bin/pwd)
$(if $(BUILD_DIR),,$(error output directory "$(saved-output)" does not exist))
endif # ifneq ($(BUILD_DIR),)

OBJTREE		:= $(if $(BUILD_DIR),$(BUILD_DIR),$(CURDIR))
SRCTREE		:= $(CURDIR)
TOPDIR		:= $(SRCTREE)
LNDIR		:= $(OBJTREE)
export	TOPDIR SRCTREE OBJTREE

ifneq ($(OBJTREE),$(SRCTREE))
REMOTE_BUILD	:= 1
export REMOTE_BUILD
endif

# $(obj) and (src) are defined in config.mk but here in main Makefile
# we also need them before config.mk is included which is the case for
# some targets like unconfig, clean, clobber, distclean, etc.
ifneq ($(OBJTREE),$(SRCTREE))
obj := $(OBJTREE)/
src := $(SRCTREE)/
else
obj :=
src :=
endif
export obj src

#########################################################################

ARCH   = arm
CPU    = s3c64xx
BOARD  = smdk6410
VENDOR = samsung
SOC    = s3c6410
export	ARCH CPU BOARD VENDOR SOC

CROSS_COMPILE = arm-linux-
export	CROSS_COMPILE

# load other configuration
include $(TOPDIR)/config.mk

#########################################################################
# U-Boot objects....order is important (i.e. start must be first)

OBJS  = 

OBJS := $(addprefix $(obj),$(OBJS))

LIBS  = lib_generic/libgeneric.a

LIBS += board/$(BOARDDIR)/lib$(BOARD).a
LIBS += cpu/$(CPU)/$(SOC)/libarch.a
LIBS += lib_$(ARCH)/lib$(ARCH).a
LIBS += ucos2/libos.a

LIBS += common/libcommon.a
LIBS += $(BOARDLIBS)

LIBS := $(addprefix $(obj),$(LIBS))
.PHONY : $(LIBS)

# Add GCC lib
PLATFORM_LIBS += -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) -lgcc

# Don't include stuff already done in $(LIBS)
SUBDIRS	=
.PHONY : $(SUBDIRS)

__OBJS := $(subst $(obj),,$(OBJS))
__LIBS := $(subst $(obj),,$(LIBS))

#########################################################################
#########################################################################

ALL = $(obj)ucos2-6410.srec $(obj)ucos2-6410.bin $(obj)System.map

all:		$(ALL)

$(obj)ucos2-6410.hex:	$(obj)ucos2-6410
		$(OBJCOPY) ${OBJCFLAGS} -O ihex $< $@

$(obj)ucos2-6410.srec:	$(obj)ucos2-6410
		$(OBJCOPY) ${OBJCFLAGS} -O srec $< $@

$(obj)ucos2-6410.bin:	$(obj)ucos2-6410
		$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@
		$(OBJDUMP) -D $< > $<.dis

$(obj)ucos2-6410.dis:	$(obj)ucos2-6410
		$(OBJDUMP) -d $< > $@

$(obj)ucos2-6410:		depend $(SUBDIRS) $(OBJS) $(LIBS) $(LDSCRIPT)
		UNDEF_SYM=`$(OBJDUMP) -x $(LIBS) |sed  -n -e 's/.*\(__u_boot_cmd_.*\)/-u\1/p'|sort|uniq`;\
		cd $(LNDIR) && $(LD) $(LDFLAGS) $$UNDEF_SYM $(__OBJS) \
			--start-group $(__LIBS) --end-group $(PLATFORM_LIBS) \
			-Map ucos2-6410.map -o ucos2-6410

$(OBJS):
		$(MAKE) -C cpu/$(CPU) $(if $(REMOTE_BUILD),$@,$(notdir $@))

$(LIBS):
		$(MAKE) -C $(dir $(subst $(obj),,$@))

$(SUBDIRS):
		$(MAKE) -C $@ all

depend dep:
		for dir in $(SUBDIRS) ; do $(MAKE) -C $$dir _depend ; done

$(obj)System.map:	$(obj)ucos2-6410
		@$(NM) $< | \
		grep -v '\(compiled\)\|\(\.o$$\)\|\( [aUw] \)\|\(\.\.ng$$\)\|\(LASH[RL]DI\)' | \
		sort > $(obj)System.map

#########################################################################
#########################################################################
#########################################################################

clean:
	find $(OBJTREE) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*~' -o -name '.depend*' \
		-o -name '*.o'  -o -name '*.a'  \) -print \
		| xargs rm -f

clobber:	clean
	find $(OBJTREE) -type f \( -name .depend \
		-o -name '*.srec' -o -name '*.bin' -o -name ucos2-6410.img \) \
		-print0 \
		| xargs -0 rm -f
	rm -fr $(obj)*.*~
	rm -f $(obj)ucos2-6410 $(obj)ucos2-6410.map $(obj)ucos2-6410.hex $(ALL)


#########################################################################
