########################################################################
#                                                                      #
# @author: Rezvee                                                      #
# @date: 09/24/2024                                                    #
#                                                                      #
# @description: Simple makefile script testing.                        #
#                                                                      #
########################################################################

# Default shell. If you are not using `bash` please change
# it to the appropriate shell of your system e.g. ksh, zsh, etc...
SHELL=/bin/bash

# Fancy Rules
# C related items
CC = gcc
CFLAGS = -Og -Wall -std=c99 -fanalyzer
# C++ related items
CXX = g++
CXXFLAGS =
# Pre-processor flags
CPPFLAGS =
# LDFLAGS
LDFLAGS =

# OPERATING SYSTEM INFORMATION
OS_ARCH=$(shell uname -m)


# TARGET DIRECTORIES
EXEC_DIR=${OS_ARCH}/exec
SRC_DIRS=$(shell find . -name "*.c")
HEADER_DIR=$(shell find . -name "*.h")
DEBUG_DIRS:=${OS_ARCH}/.debug
OBJ_DIRS:=${OS_ARCH}/obj
ASM_DIRS:=${OS_ARCH}/asm
PREP_DIRS:=${OS_ARCH}/preprocessor
SRC_FILES:=$(SRC_FILES)
OBJ_FILES:=$(SRC_FILES)

# FUNCTIONS CALLS
SRC_FILES=$(foreach item, \
		  $(SRC_DIRS), \
		  $(shell echo $(item) | sed 's,^.*\(/[^/]*\)$$,\1,' | cut -d'/' -f2))

OBJ_FILES=$(foreach item, ${SRC_FILES}, $(patsubst %.c, %.o, $(item))!)

all_srcs=$(patsubst %.c, %.o, $(shell ls -la $(src)))

# BLANKS (We use this for the build so recommended not to touch)
${SRC_FILES} :
${SRC_DIRS} :
# PHONY TARGETS: Put file names here so we don't confuse
# targets and recipies. (you can replace `all` with
# more explicit something
.PHONY: all

%::
	@echo "Call `make build` or `make clean`"

build : object
	@if [ -d ${EXEC_DIR} ]; then \
		echo "${EXEC_DIR} exists. Will not delete unless hard delete is specified"; \
	else \
		mkdir ${OS_ARCH}; \
		mkdir ${EXEC_DIR}; \
	fi
	$(CC) $(CFLAGS) -fPIE ${OBJ_DIRS}/*.o -o ${EXEC_DIR}/final

object: ${SRC_DIRS}
	@if [ -d ${OBJ_DIRS} ]; then \
		echo "${OBJ_DIRS} exists. Will not delete unless hard delete is specified"; \
	else \
		mkdir ${OS_ARCH}; \
		mkdir ${OBJ_DIRS}; \
	fi
	$(CC) $(CFLAGS) -c $^ -O
	@mv *.o ${OBJ_DIRS}

assemble: ${SRC_DIRS}
	@if [ -d ${ASM_DIRS} ]; then \
		echo "${ASM_DIRS} exists. Will not delete unless hard delete is specified"; \
	else \
		mkdir ${OS_ARCH}; \
		mkdir ${ASM_DIRS}; \
	fi
	$(CC) $(CFLAGS) $^ -S
	@mv *.s ${ASM_DIRS}

debug: ${SRC_DIRS}
	@if [ -d ${DEBUG_DIRS} ]; then \
		echo "${DEBUG_DIRS} exists. Will not delete unless hard delete is specified"; \
	else \
		mkdir ${OS_ARCH}; \
		mkdir ${DEBUG_DIRS}; \
	fi

clean :
	@if [ -d ${OS_ARCH} ]; then \
		rm -rf ${OS_ARCH}; \
	fi

%.o : %.c
	@echo "Building source files."
	@$(CC) -c $(CFLAGS) ${src}/$<.c -o $@
