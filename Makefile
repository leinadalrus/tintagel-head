CC := gcc
CXX := g++

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

x86_64: ./core/main.cpp
	$(CXX-$(AMD64)) $(INCLUDES) 
	$(CXX-$(AMD64)) $(LIBS) $(LDFLAGS) # coreboot cli commands arguments

%.o: %.c
	$(CXX-) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OUT_DIR)

-include $(DEPS)
