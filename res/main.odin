package controllers
// My modules
import "core:fmt"
import "core:c"

ODIN_OS :: ""

when ODIN_OS == "windows" do foreign import ctl "system:nmemdlcfn.lib"
when ODIN_OS == "linux"   do foreign import ctl "system:nmemdlcfn" // equivalent to a: `.a` linked static libraryl

// foreign ctl {
//     add :: proc(a, b: c.int) -> c.int ---
// }

@export
cAdd :: proc "c" (a, b: i32) -> i32 {
    return a + b
}

main :: proc() {
    setup()
    fmt.println(cAdd(1, 1))
}