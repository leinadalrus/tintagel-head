package main
// My modules
import "res:headers"
import "core:fmt"
import "core:c"

when ODIN_OS == "windows" do foreign import ctl "system:nmemdlcfn.lib"
when ODIN_OS == "linux"   do foreign import ctl "system:nmemdlcfn" // equivalent to a: `.a` linked static library

foreign add {
    add :: proc(a, b: c.int) -> c.int ---
}

@export
add :: proc "c" (a, b: i32) -> i32 {
    return a + b
}

main :: proc() {
    headers.setup()
    fmt.println(add(1, 1))
}