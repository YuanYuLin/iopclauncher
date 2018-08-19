
TARGET = iopclauncher

CFLAGS += -I$(SDKSTAGE)/usr/include/libiopcdao
CFLAGS += -I$(SDKSTAGE)/usr/include/libiopcmisc
CFLAGS += -I$(SDKSTAGE)/usr/include/libiopctask
CFLAGS += -I$(SDKSTAGE)/usr/include/libiopccmd
CFLAGS += -I$(SDKSTAGE)/usr/include/libiopcnet
CFLAGS += -I$(SDKSTAGE)/usr/include/libjsonc
CFLAGS += -I$(SDKSTAGE)/usr/include/
CFLAGS += -I./include/

LDFLAGS += -L$(CC_SYSROOT)/usr/lib/ 
LDFLAGS += -L$(SDKSTAGE)/usr/lib/ 
LDFLAGS += -L$(SDKSTAGE)/lib/ 
LDFLAGS += -lc -lpthread -lrt -lz -lbz2
#LDFLAGS += -ldb -ltokyocabinet -ltokyotyrant 
LDFLAGS += -ljson-c 
#LDFLAGS += -llua5.1 
LDFLAGS += -lmicrohttpd -lgcrypt -lgnutls -lgpg-error  -lnettle -ltasn1 -lgmp
LDFLAGS += -lp11-kit -lffi -lidn -lhogweed 
LDFLAGS += -liopcdao -liopcmisc -liopctask -liopccmd -liopcnet
ifeq ($(SUPPORT_LXC), y)
CFLAGS += -I$(SDKSTAGE)/usr/include/lxc
CFLAGS += -DSUPPORT_LXC
LDFLAGS += -llxc -lselinux -lseccomp -lcap -lapparmor
LDFLAGS += -lnettle -lhogweed -lgmp -lidn -ltasn1 -lp11-kit -lffi -lpcre -lgnutls
endif
ifeq ($(SUPPORT_DRM), y)
CFLAGS += -I$(SDKSTAGE)/usr/include/libdrm
CFLAGS += -I$(SDKSTAGE)/usr/include/libdrm/libdrm
CFLAGS += -I$(SDKSTAGE)/usr/include/libiopcdrm
CFLAGS += -DSUPPORT_DRM
LDFLAGS += -ldrm -liopcdrm 
endif
ifeq ($(SUPPORT_RFB), y)
#CFLAGS += -I$(SDKSTAGE)/usr/include/libiopcrfb
#CFLAGS += -DSUPPORT_RFB
#LDFLAGS += -liopcrfb
endif

SRC = 
SRC += main.c

ifeq ($(SUPPORT_PLATFORM_AS_HOST),y)
CFLAGS += -DSUPPORT_PLATFORM_AS_HOST
endif
ifeq ($(SUPPORT_PLATFORM_AS_GUEST),y)
endif


include Makefile.include.app
