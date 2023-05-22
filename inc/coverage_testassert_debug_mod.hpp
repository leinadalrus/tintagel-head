#ifndef COVERAGE_TESTASSERT_DEBUG_MOD_HPP
#define COVERAGE_TESTASSERT_DEBUG_MOD_HPP

#ifndef COVER_TESTASSERT_IF
#define COVER_TESTASSERT_IF(_ifstate, _str, ...)                               \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_ifstate || #_str == "for") {                                         \
      if (__LINE__ == #_ifstate) {                                             \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_ifstate, #_str);                 \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_IF

#ifndef COVER_TESTASSERT_FOR
#define COVER_TESTASSERT_FOR(_forloop, _str, ...)                              \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_forloop || #_str == "for") {                                         \
      if (__LINE__ == #_forloop) {                                             \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_forloop, #_str);                 \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_FOR

#ifndef COVER_TESTASSERT_WHILE
#define COVER_TESTASSERT_WHILE(_whileloop, _str, ...)                          \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_whileloop || #_str == "while") {                                     \
      if (__LINE__ == #_whileloop) {                                           \
        \ printf("%s\n:\t%d", __FILE__, __LINE__);                             \
        printf("\n%v:\n\tStored Value: %v", #_whileloop, #_str);               \
      }                                                                        \
    }                                                                          \
  }
#endif // !COVER_TESTASSERT_WHILE

#ifndef COVER_TESTASSERT_ANYOPAQUE
#define COVER_TESTASSERT_ANYOPAQUE(_opaqueswitch, _str, ...)                   \
  {                                                                            \
    FILE *file;                                                                \
    const char *buffer;                                                        \
    if (#_opaqueswitch || #_str == "switch") {                                 \
      if (__LINE__ == #_opaqueswitch) {                                        \
        printf("%s\n:\t%d", __FILE__, __LINE__);                               \
        printf("\n%v:\n\tStored Value: %v", #_opaqueswitch, #_str);            \
      }                                                                        \
    }                                                                          \
  }

#endif // !COVER_TESTASSERT_ANYOPAQUE
#endif // !COVERAGE_TESTASSERT_DEBUG_MOD_HPP
