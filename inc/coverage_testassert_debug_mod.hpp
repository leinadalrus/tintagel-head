#ifndef COVERAGE_TESTASSERT_DEBUG_MOD_HPP
#define COVERAGE_TESTASSERT_DEBUG_MOD_HPP

enum FileCodeCoverts {
  RESERVE_FLAG,
  CURRENT_COLUMN,
  SHORT_OFFSET,
};

#ifndef DXINPUT_TESTASSERT_VARGS
#define DXINPUT_TESTASSERT_VARGS(_f, _b, ...)                                  \
  {                                                                            \
    FILE *file = fopen("/~/bios/bin/dwarfelf.bin", "wb");                      \
    const char *buffer;                                                        \
    fwrite(#_b, sizeof(*#_b), sizeof(const char *), file);                     \
    _str = __LINE__; /*TODO*/                                                  \
    fclose(file);                                                              \
  }
#endif // !DXINPUT_TESTASSERT_VARGS

#ifndef DXOUTPUT_TESTMESSAGE_C
#define DXOUTPUT_TESTMESSAGE_C(_f, _b, ...)                                    \
  {                                                                            \
    FILE *#_f = fopen("/~/bios/bin/dwarfelf.bin", "r");                        \
    char *#_b, *res;                                                           \
    fclose(#_f);                                                               \
  }
#endif // !DXOUTPUT_TESTMESSAGE_C

#ifndef COVER_TESTASSERT_IF
#define COVER_TESTASSERT_IF(_ifstate, _str, ...)                               \
  {                                                                            \
    if (#_ifstate || #_str == "if") {                                          \
      switch (CURRENT_COLUMN) {                                                \
      case _ifstate:                                                           \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_ifstate, #_str);                 \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_IF

#ifndef COVER_TESTASSERT_FOR
#define COVER_TESTASSERT_FOR(_forloop, _str, ...)                              \
  {                                                                            \
    if (#_forloop || #_str == "for") {                                         \
      switch (CURRENT_COLUMN) {                                                \
      case _forloop:                                                           \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_forloop, #_str);                 \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_FOR

#ifndef COVER_TESTASSERT_WHILE
#define COVER_TESTASSERT_WHILE(_whileloop, _str, ...)                          \
  {                                                                            \
    if (#_whileloop || #_str == "while") {                                     \
      switch (CURRENT_COLUMN) {                                                \
      case _whileloop:                                                         \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_whileloop, #_str);               \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_WHILE

#ifndef COVER_TESTASSERT_SWITCHSTATE
#define COVER_TESTASSERT_SWITCHSTATE(_opaqueswitch, _str, ...)                 \
  {                                                                            \
    if (#_opaqueswitch || #_str == "switch") {                                 \
      switch (CURRENT_COLUMN) {                                                \
      case _opaqueswitch:                                                      \
      case _str:                                                               \
      default:                                                                 \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_opaqueswitch, #_str);            \
      }                                                                        \
    }                                                                          \
  }

#endif // !COVER_TESTASSERT_SWITCHSTATE
#endif // !COVERAGE_TESTASSERT_DEBUG_MOD_HPP
