#ifndef CELLBE_HARVARD_STYLE_CACHE_H
#define CELLBE_HARVARD_STYLE_CACHE_H

#include "amd64_command_ring_buffer.h"
#include "cellbe_memorymap.h"
#include "cellbe_spu_command_handler.h"
#include "cellbe_vector_simd_pem.h"

// VirtualAddressSpace
// must be larger than the EffectiveAddressSpace
//
// NOTE Harvard Style Cache Model
// NOTE CombinedCacheModel

typedef struct PpuMemoryEntity {
} PpuMemoryEntity;

typedef struct PpuSegmentLookasideBuffer {
} PpuSegmentLookasideBuffer;

typedef struct PpuPageTable {
} PpuPageTable;

typedef struct PpuTranslationLookasideBuffer {
  signed char address_offset; // int8_t equivalent?
} PpuTranslationLookasideBuffer;

typedef struct PpuOffsetLookasideBuffer {
  enum RingBufferStatusCodes rb_status_code;
  PpuMemoryEntity ppe_memory_entity;
  PpuSegmentLookasideBuffer ppe_segment_lookaside_buffer;
  PpuTranslationLookasideBuffer ppe_translation_lookaside_buffer;
} PpuOffsetLookasideBuffer;

typedef struct SpuMemoryEntity {
} SpuMemoryEntity;

typedef struct SpuSgementLookasideBuffer {
} SpuSgementLookasideBuffer;

typedef struct SpuPageTable {
} SpuPageTable;

typedef struct SpuTranslationLookasideBuffer {
} SpuTranslationLookasideBuffer;

typedef struct SpuOffsetLookasideBuffer {
  enum RingBufferStatusCodes rb_status_code;
  SpuMemoryEntity spu_memory_entity;
  SpuSgementLookasideBuffer spu_segment_lookaside_buffer;
  SpuTranslationLookasideBuffer spu_translation_lookaside_buffer;
} SpuOffsetLookasideBuffer;

// The cache management instructions allow programs to perform the following
// functions: Invalidate the copy of storage in an instruction cache block
// (icbi) Provide a hint that the program will probably soon access a specified
// data cache block (dcbt, dcbtst) Set the contents of a data cache block to
// zeros (dcbz) Copy the contents of a modified data cache block to main storage
// (dcbst) Copy the contents of a modified data cache block to main storage and
// make the copy of the block in the data cache invalid (dcbf)

const int *invalidate_cache_block_instruction();
const int *access_specified_data_cache_block(PpuSegmentLookasideBuffer *dcbt,
                                             PpuSegmentLookasideBuffer *dcbtst);
const int *set_data_cache_block_to_zero(PpuSegmentLookasideBuffer *dcbz);
const int *copy_modified_data_cache_block(PpuSegmentLookasideBuffer *dcbf);
const int *
invalidate_modified_data_cache_block(PpuSegmentLookasideBuffer *dcbf);

// NOTE functions to-do:
// Bring a range of effective addresses into the SL1 (sdcrt and sdcrtst)
// Write zeros to the contents of a range of effective addresses (sdcrz)
// Store the modified contents of a range of effective addresses (sdcrst)
// Store the modified contents of a range of effective addresses and invalidate
// the block (sdcrf)

#endif // CELLBE_HARVARD_STYLE_CACHE_H
