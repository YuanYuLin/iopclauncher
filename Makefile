
TARGET = iopclauncher.elf

CFLAGS += -I$(SDKSTAGE)/usr/include/iopccommon
CFLAGS += -I$(SDKSTAGE)/usr/include/
CFLAGS += -I$(SDKSTAGE)/usr/include/json-c
CFLAGS += -I./include/

LDFLAGS += -L$(SDKSTAGE)/usr/lib/ 
LDFLAGS += -lc -lpthread -lrt
LDFLAGS += -ljson-c
LDFLAGS += -liopccommon

#LDFLAGS += -I$(LXC_PACKAGE_DIR)/usr/include/lxc
LDFLAGS += -L$(LXC_PACKAGE_DIR)/usr/lib
#LDFLAGS += -llxc

SRC = 
SRC += main.c
#SRC += sysinit.c

#SRC += configs/platform.c

ifeq ($(SUPPORT_PLATFORM_AS_HOST),y)
CFLAGS += -DSUPPORT_PLATFORM_AS_HOST
endif
ifeq ($(SUPPORT_PLATFORM_AS_GUEST),y)
endif


include Makefile.include.app
