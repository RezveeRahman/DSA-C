########################################################################
# @author           : Rezvee Rahman                                    #
# @date             : 
# @description      : Basic make file                                  #
#                                                                      #
########################################################################

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

SRC_DIR = ./src
OBJ_DIR = ./src/.obj


