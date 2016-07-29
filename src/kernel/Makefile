#######################################################################
#  Copyright 1999-2013 ALTIBASE Corporation or its subsidiaries.
#  All rights reserved
# 
#  Author: randyma
#  Date  : 2013/12/30
#  Usage:
# $> make [release] : release ºôµå
# $> make debug     : debug ºôµå
# $> make clean     : ºôµå clean
#######################################################################

#########################
# DIRECTORY
#########################
DIR = $(shell pwd)
SRC_DIR = $(DIR)/
INC_DIR = $(DIR)/include
OBJ_DIR = $(DIR)/objects

#########################
# BUILD OPTIONS
#########################
CC = gcc
RM = rm -f
CP = cp
AR = ar

CFLAGS  = -I/usr/local/include -Iinclude
TARGET  = $(DATASHARD_HOME)/lib/shardkernel.a
SUFFIX  = c

#########################
# LINUX / UBUNTU
#########################
ifeq ($(OS_NAME), linux)
	ifeq ($(ATS_BIT), 32)
		CFLAGS += -m32
	else
		CFLAGS += -m64
	endif
	CFLAGS += -Wall -Wno-unused -Wno-format
else
#########################
# AIX 5.3 / AIX 6.1
#########################
ifeq ($(OS_NAME), aix)
    $(error '$(OS_NAME)' not implemented yet)
else
#########################
# HP-UX
#########################
ifeq ($(OS_NAME), hpux)
    $(error '$(OS_NAME)' not implemented yet)
else
#########################
# HP-UX ia64
#########################
ifeq ($(OS_NAME), hpux-ia64)
    $(error '$(OS_NAME)' not implemented yet)
else
	$(error '$(OS_NAME)' not implemented yet)
endif
endif
endif
endif

#########################
# CHECK DEBUG MODE
#########################
ifneq "$(findstring debug, $(MAKECMDGOALS))" ""
    BUILD.OPTION = 1
else
	BUILD.OPTION = 0
endif

#########################
# SETTING WITH BUILD OPTION
#########################
ifeq ($(BUILD.OPTION), 1)
	CFLAGS += -DDEBUG -g
	CONFIG  = debug
else
	CFLAGS += -O2 -DNDEBUG
	CONFIG  = release
endif

.PHONY: debug release clean

#########################
# COMPILE & ARCHIVE
#########################
DIRS := $(shell find . -maxdepth 3 -type d)
TARGETS = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.$(SUFFIX)))
OBJECTS = $(patsubst %.c,%.o,$(TARGETS))
INCLUDE = $(foreach d,$(sort $(INC_DIR) $(SRC_DIR)),-I$d)

$(CONFIG): $(TARGET)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SUFFIX)
	@echo "CC" $@ 
	@$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	@$(RM) $@
	@$(AR) -rcvs $@ $(OBJECTS)
	@echo [make $(CONFIG)] finished.

clean:
	$(RM) -rf $(OBJECTS) $(TARGET)

