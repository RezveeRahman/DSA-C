#########################################################################
# @author           : Rezvee Rahman										#
# @date             : 09/02/2024										#
#																		#
# @description      : We will be building pointer example				#
#																		#
#########################################################################

# SHELL VARIABLE
SHELL = /bin/bash

# ENVIRONMNET VARIABKES
CC = /bin/gcc
C_FLAGS = -Og

# I don't know why I thought these were a good idea but OK...
SAO = -Wno-analyzer-va-list-leak \
	-Wno-analyzer-possible-null-dereference \
	-Wno-analyzer-use-after-free \
	-Wno-analyzer-malloc-leak

WARN = -Wall \
	-Wno-overflow

# SUFFIXES
.SUFFIXES:
.SUFFIXES: .c .o

SRC_DIR = .
OBJ_DIR = ${SRC_DIR}/.obj

.PHONY : test
test :
	$(wildcard {SRC_DIR}/*)

# build the source (src) directory

.PHONY : build
build : clean
	@printf "\033[38;5;2mBuilding C files\033[0;0;0m \n"
	@mkdir ${OBJ_DIR}
	@$(CC) ${SRC_DIR}/pointer.c -o ${OBJ_DIR}/pointer.o ${C_FLAGS} ${SAO} ${WARN}

.PHONY : clean
clean :
	@printf "\033[38;5;1m Removing files in the directory \
		\033[0;0;0m \n"
	@rm -rf ${OBJ_DIR}