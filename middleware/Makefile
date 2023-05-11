CC := gcc 
CXX := g++

BIN_AMD64 = coreboot_bios_amd64
LLVM_SHARED_OBJ = /usr/lib/llvm-10/libLLVM-10.so
# Specify the output file to be filename.
# Make the output be LLVM bitcode (with -c) 
# or assembly (with -s) instead of native object (or assembly). 
# If -emit-llvm is given without either -c or -S it has no effect.
LLVM_ASM_OUT = llvm-gcc -o $(BIN_AMD64) -emit-llvm -s
LLVM_OBJCOPY = llvm-objcopy

TARGET_EXEC := main
OUT_DIR := ./output
CORE_DIRS := ./core

SRCS := $(shell find $(CORE_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS%=$(OUT_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

LIB_DIRS := $(shell find $(CORE_DIRS) -type d)
LIB_FLAGS := $(addprefix -I,$(LIB_DIRS))

CFLAGS := -g -Wall
CPPFLAGS := $(LIB_FLAGS) -MMD -MP
LDFLAGS := -g -Wall

$(OUT_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OUT_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CXX-) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OUT_DIR)

-include $(DEPS)

x86_64: ./core/main.cpp
	$(CXX-$(AMD64)) $(INCLUDES) 
	$(CXX-$(AMD64)) $(LIBS) $(LDFLAGS) # coreboot cli commands arguments

objcopy_shared:
	$(LLVM_ASM_OUT)
	$(LLVM_OBJCOPY) -O binary $(BIN_AMD64).o $(BIN_AMD64).bin
