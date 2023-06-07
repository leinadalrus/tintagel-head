#ifndef CELLBE_VECTOR_SIMD_PEM_H
#define CELLBE_VECTOR_SIMD_PEM_H

enum CellMemoryOperandAlignments {
  BYTE = 0x1111,
  HALFWORD = 0x0111,
  WORD = 0x0011,
  QUADWORD = 0x0000,
}; // NOTE: An x in an address bit position indicates that the bit can be ‘0’ or
   // ‘1’ independent of the state of other bits in the address.
#endif // !CELLBE_VECTOR_SIMD_PEM_H
