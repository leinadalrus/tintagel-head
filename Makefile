target_exec := app_main

build_dir := ./build
include_dir := ./inc

clang_files := $(shell find $(include_dir) -name '*.cpp' -or -name '*.c' -or  -name '*.s')

static_objs := $(clang_files:%=$(build_dir)/%.o)

proj_deps := $(static_objs:.o=.d)

items_dir := $(shell find $(include_dir) -type d)
items_flags := $(addprefix -I,$(items_dir))

cpp_flags := $(items_flags) -MMD -MP # generate makefiles with .d output

# The final build step.
$(build_dir)/$(target_exec): $(static_objs)
	$(CXX) $(static_objs) -o $@ $(LDFLAGS)

# Build step for C source
$(build_dir)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(build_dir)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
	clean:
		rm -r $(build_dir)

-include $(proj_deps)