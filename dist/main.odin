package main

import "core:fmt"
import "core:c"

when ODIN_OS == "windows" do foreign import ftl "system:main.lib"
when ODIN_OS == "linux"   do foreign import ftl "system:main"

foreign add {
    add :: proc(a, b: c.int) -> c.int ---
}

@export
add :: proc "c" (a, b: i32) -> i32 {
    return a + b
}

main :: proc() {
    fmt.println(add(1, 1))
}