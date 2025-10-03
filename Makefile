# Generic Makefile used for C/C++ Projects
#
# Created 4/1/2021. Based off of Nicholas Hamilton's answer on this StackOverflow post:
# https://stackoverflow.com/questions/5178125/how-to-place-object-files-in-separate-subdirectory
#
# Modified by Ethan Link, particularly the dependency creation.

#Compiler and Linker
CC          := gcc

# Name of output program
TARGET      := aquarium

# Variables for keeping track of different directories
SRC_DIR     := src
INC_DIR     := inc
OBJ_DIR	    := obj
BIN_DIR     := bin
DEP_DIR     := dep
#RES_DIR     := res
SRC_EXT     := c
DEP_EXT     := d
OBJ_EXT     := o

#Flags, Libraries and Includes
CFLAGS      := -Werror -Wall -std=gnu99 
DEBUG_FLAGS := -Werror -Wall -std=gnu99 -g
LFLAGS      := -fopenmp -lm
#INC        := -I$(INC_DIR) -I/usr/local/include
#INCDEP     := -I$(INC_DIR)
INC		    := -I$(INC_DIR)

#---------------------------------------------------------------------------------
# Shouldn't need to edit below this line
#---------------------------------------------------------------------------------
#SOURCES    := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
SOURCES     := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJECTS     := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT)))
DEPENDS     := $(patsubst $(OBJ_DIR)/%,$(DEP_DIR)/%,$(OBJECTS:.$(OBJ_EXT)=.$(DEP_EXT)))

# Default Make
#all: resources $(TARGET)
all: $(TARGET)

# Remake
redo: cleaner all

# Copy Resources from Resources Directory to Target Directory
resources: directories
	cp $(RES_DIR)/* $(BIN_DIR)/

# Make the Directories
directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(DEP_DIR)

# Clean out intermediate files
clean:
	-rm -f $(BIN_DIR)/*
	-rm -f $(OBJ_DIR)/*.$(OBJ_EXT)
	-rm -f $(DEP_DIR)/*.$(DEP_EXT)

# Full Clean, Objects, Dependencies, and Binaries, with directories
cleaner: clean
	-rmdir $(BIN_DIR) 
	-rmdir $(OBJ_DIR)
	-rmdir $(DEP_DIR)

# Pull in dependency info from existing .d files
-include $(DEPENDS)
#-include $(OBJECTS:.$(OBJ_EXT)=.$(DEP_EXT)

# Link (Combine .o files into a binary target)
$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(BIN_DIR)/$(TARGET) $^

# Compile (Create .o files)
$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) $(CFLAGS) $(INC) -c -MD -MP -MF $(DEP_DIR)/$*.$(DEP_EXT) -o $@ $<


#Non-File Targets
.PHONY: all redo clean cleaner resources directories
