#include "cellbe_memorymap.h"
#ifndef COVERAGE_TESTASSERT_DEBUG_MOD_H
#define COVERAGE_TESTASSERT_DEBUG_MOD_H
#define COVERAGE_DEBUG_LOCAL_STORE_START SPE0_LOCAL_STORE_START
#define COVERAGE_DEBUG_LOCAL_STORE_END SPE0_LOCAL_STORE_END

enum FileCodeCoverts {
  RESERVE_FLAG,
  CURRENT_COLUMN,
  SHORT_OFFSET,
};

#ifndef DXINPUT_TESTASSERT_ITEM
#define DXINPUT_TESTASSERT_ITEM(_f, _b, ...)                                   \
  {                                                                            \
    FILE *file = fopen("/~/bios/bin/dwarfelf.bin", "wb");                      \
    const char *buffer;                                                        \
    fwrite(#_b, sizeof(*#_b), sizeof(const char *), file);                     \
    _str = __LINE__; /*TODO*/                                                  \
    fclose(file);                                                              \
  }
#endif // !DXINPUT_TESTASSERT_ITEM

#ifndef DXOUTPUT_TESTMESSAGE_ITEM
#define DXOUTPUT_TESTMESSAGE_ITEM(_f, _b, ...)                                 \
  {                                                                            \
    FILE *#_f = fopen("/~/bios/bin/dwarfelf.bin", "r");                        \
    char *#_b, *res;                                                           \
    fclose(#_f);                                                               \
  }
#endif // !DXOUTPUT_TESTMESSAGE_ITEM

#ifndef COVER_TESTASSERT_IF
#define COVER_TESTASSERT_IF(_ifstate, _str, ...)                               \
  {                                                                            \
    if (#_ifstate || #_str == L"if") {                                         \
      switch (CURRENT_COLUMN) {                                                \
      case COVERAGE_DEBUG_LOCAL_STORE_START:                                   \
      case COVERAGE_DEBUG_LOCAL_STORE_END:                                     \
      case _ifstate:                                                           \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%s:\n\tStored Value: %s", #_ifstate, #_str);                 \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_IF

#ifndef COVER_TESTASSERT_FOR
#define COVER_TESTASSERT_FOR(_forloop, _str, ...)                              \
  {                                                                            \
    if (#_forloop || #_str == L"for") {                                        \
      switch (CURRENT_COLUMN) {                                                \
      case COVERAGE_DEBUG_LOCAL_STORE_START:                                   \
      case COVERAGE_DEBUG_LOCAL_STORE_END:                                     \
      case _forloop:                                                           \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%s:\n\tStored Value: %s", #_forloop, #_str);                 \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_FOR

#ifndef COVER_TESTASSERT_WHILE
#define COVER_TESTASSERT_WHILE(_whileloop, _str, ...)                          \
  {                                                                            \
    if (#_whileloop || #_str == L"while") {                                    \
      switch (CURRENT_COLUMN) {                                                \
      case COVERAGE_DEBUG_LOCAL_STORE_START:                                   \
      case COVERAGE_DEBUG_LOCAL_STORE_END:                                     \
      case _whileloop:                                                         \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%s:\n\tStored Value: %s", #_whileloop, #_str);               \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_WHILE

#ifndef COVER_TESTASSERT_SWITCHSTATE
#define COVER_TESTASSERT_SWITCHSTATE(_opaqueswitch, _str, ...)                 \
  {                                                                            \
    if (#_opaqueswitch || #_str == L"switch") {                                \
      switch (CURRENT_COLUMN) {                                                \
      case COVERAGE_DEBUG_LOCAL_STORE_START:                                   \
      case COVERAGE_DEBUG_LOCAL_STORE_END:                                     \
      case _opaqueswitch:                                                      \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%s:\n\tStored Value: %s", #_opaqueswitch, #_str);            \
      }                                                                        \
    }                                                                          \
  }

#endif // !COVER_TESTASSERT_SWITCHSTATE
#endif // !COVERAGE_TESTASSERT_DEBUG_MOD_H
