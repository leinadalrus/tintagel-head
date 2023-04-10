project('tintagel_head', 'cpp', version : ‘0.1.0’, default_options : [‘warning_level=3’, ‘cpp_std=c++14’])

my_incs = include_directories('inc')
my_libs = static_library('lib')
my_deps = dependency(link_with: my_libs, include_directories: my_incs)

executable('tintagel_head', 'src/main.cpp',
    win_subsystem: 'windows',
    dependencies: my_deps)