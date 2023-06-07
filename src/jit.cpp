#pragma GCC diagnostic warning "-Wformat"
#pragma GCC diagnostic error "-Wuninitialized"

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "../ext/asmjit-oldstable/src/asmjit/asmjit.h"

using namespace asmjit;

X86Gp getDstRegByValue() { return x86::ecx; }

void usingOperandsExample(X86Assembler &a) {
  int eq_comp_idx = 0; // mutable
  int eq_comp_ops = 0; // mutable
  // Create some operands.
  X86Gp dst = getDstRegByValue(); // Get `ecx` register returned by a function.
  X86Gp src = x86::rax; // Get `rax` register directly from the provided `x86`
                        // namespace.
  X86Gp idx = x86::gpq(10); // Construct `r10` dynamically.
  X86Mem m = x86::ptr(
      src,
      idx); // Construct [src + idx] memory address - referencing [rax + r10].

  // Examine `m`:
  m.getIndexType(); // Returns `X86Reg::kRegGpq`.
  m.getIndexId();   // Returns 10 (`r10`).

  // Reconstruct `idx` stored in mem:
  X86Gp idx_2 = X86Gp::fromTypeAndId(m.getIndexType(), m.getIndexId());
  if (idx == idx_2) // True, `idx` and idx_2` are identical.
    eq_comp_idx = 1;

  Operand op = m; // Possible.
  op.isMem();     // True (can be casted to Mem and X86Mem).

  if (m == op) // True, `op` is just a copy of `m`.
    eq_comp_ops = 1;
  static_cast<Mem &>(op).addOffset(1); // Static cast is fine and valid here.
  // m == op; // False, `op` now points to [rax + r10 + 1], which is not [rax +
  // r10].
  if (m == op)
    eq_comp_ops = 0;

  // Emitting 'mov'
  a.mov(dst, m); // Type-safe way.
                 // a.mov(dst, op); // Not possible, `mov` doesn't provide
                 // `X86Reg, Operand` overload.

  a.emit(X86Inst::kIdMov, dst, m); // Type-unsafe, but possible.
  a.emit(X86Inst::kIdMov, dst,
         op); // Also possible, `emit()` is typeless and can be used
              // dynamically.
}

int main() {
  auto *a = new X86Assembler;
  usingOperandsExample(*a);
  return 0;
}
