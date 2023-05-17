#!/bin/bash

conan profile detect --force
conan instaLL . --output-folder=build --build=missing

cd build
meson setup --native-file conan_meson_native.ini .. meson-src
meson compile -C meson-src
./meson-src/tintagel_head
