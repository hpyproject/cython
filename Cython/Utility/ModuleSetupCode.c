/////////////// InitLimitedAPI ///////////////

#if defined(CYTHON_LIMITED_API) && 0  /* disabled: enabling Py_LIMITED_API needs more work */
  #ifndef Py_LIMITED_API
    #if CYTHON_LIMITED_API+0 > 0x03070000
      #define Py_LIMITED_API CYTHON_LIMITED_API
    #else
      #define Py_LIMITED_API 0x03070000
    #endif
  #endif
#endif


/////////////// CModulePreamble ///////////////

#include <stddef.h> /* For offsetof */
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif

#if !defined(_WIN32) && !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif

#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif

// For use in DL_IMPORT/DL_EXPORT macros.
#define __PYX_COMMA ,

#ifndef HAVE_LONG_LONG
  // CPython has required PY_LONG_LONG support for years, even if HAVE_LONG_LONG is not defined for us
  #define HAVE_LONG_LONG
#endif

#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif

#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif

// For the limited API it often makes sense to use Py_LIMITED_API rather than PY_VERSION_HEX
// when doing version checks.
#define __PYX_LIMITED_VERSION_HEX PY_VERSION_HEX

#if defined(GRAALVM_PYTHON)
  /* For very preliminary testing purposes. Most variables are set the same as PyPy.
     The existence of this section does not imply that anything works or is even tested */
  // GRAALVM_PYTHON test comes before PyPy test because GraalPython unhelpfully defines PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 1
  #define CYTHON_COMPILING_IN_NOGIL 0

  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_TYPE_SPECS
  #define CYTHON_USE_TYPE_SPECS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #ifndef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_GIL
  #define CYTHON_FAST_GIL 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #undef CYTHON_USE_MODULE_STATE
  #define CYTHON_USE_MODULE_STATE 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif

#elif defined(PYPY_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 0
  #define CYTHON_COMPILING_IN_NOGIL 0

  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #ifndef CYTHON_USE_TYPE_SPECS
    #define CYTHON_USE_TYPE_SPECS 0
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #ifndef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_GIL
  #define CYTHON_FAST_GIL 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #if PY_VERSION_HEX < 0x03090000
    #undef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #elif !defined(CYTHON_PEP489_MULTI_PHASE_INIT)
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #undef CYTHON_USE_MODULE_STATE
  #define CYTHON_USE_MODULE_STATE 0
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PYPY_VERSION_NUM >= 0x07030C00)
  #endif
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif

#elif defined(CYTHON_LIMITED_API)
  // EXPERIMENTAL !!
  #ifdef Py_LIMITED_API
    #undef __PYX_LIMITED_VERSION_HEX
    #define __PYX_LIMITED_VERSION_HEX Py_LIMITED_API
  #endif
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 1
  #define CYTHON_COMPILING_IN_GRAAL 0
  #define CYTHON_COMPILING_IN_NOGIL 0

  // CYTHON_CLINE_IN_TRACEBACK is currently disabled for the Limited API
  #undef CYTHON_CLINE_IN_TRACEBACK
  #define CYTHON_CLINE_IN_TRACEBACK 0

  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_TYPE_SPECS
  #define CYTHON_USE_TYPE_SPECS 1
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #endif
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_GIL
  #define CYTHON_FAST_GIL 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_MODULE_STATE
  #define CYTHON_USE_MODULE_STATE 1
  #ifndef CYTHON_USE_TP_FINALIZE
    // PyObject_CallFinalizerFromDealloc is missing and not easily replaced
    #define CYTHON_USE_TP_FINALIZE 0
  #endif
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif

#elif defined(Py_GIL_DISABLED) || defined(Py_NOGIL)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 0
  #define CYTHON_COMPILING_IN_NOGIL 1

  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #ifndef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE 1
  #endif
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0

#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #define CYTHON_COMPILING_IN_LIMITED_API 0
  #define CYTHON_COMPILING_IN_GRAAL 0
  #define CYTHON_COMPILING_IN_NOGIL 0

  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #ifndef CYTHON_USE_TYPE_SPECS
    #define CYTHON_USE_TYPE_SPECS 0
  #endif
  #ifndef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #ifndef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #ifndef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX >= 0x030B00A2
    // Python 3.11a2 hid _PyLong_FormatAdvancedWriter and _PyFloat_FormatAdvancedWriter
    // therefore disable unicode writer until a better alternative appears
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  // CYTHON_AVOID_BORROWED_REFS - Avoid borrowed references and always request owned references directly instead.
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  // CYTHON_ASSUME_SAFE_MACROS - Assume that macro calls do not fail and do not raise exceptions.
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_GIL
    // FIXME: FastGIL can probably be supported also in CPython 3.12 but needs to be adapted.
    // The gain is unclear, however, since the GIL handling itself became faster in recent CPython versions.
    #define CYTHON_FAST_GIL (PY_VERSION_HEX < 0x030C00A6)
  #endif
  #ifndef CYTHON_METH_FASTCALL
    // CPython 3.6 introduced METH_FASTCALL but with slightly different
    // semantics. It became stable starting from CPython 3.7.
    #define CYTHON_METH_FASTCALL 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP487_INIT_SUBCLASS
    #define CYTHON_PEP487_INIT_SUBCLASS 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  // CYTHON_USE_MODULE_STATE - Use a module state/globals struct tied to the module object.
  #ifndef CYTHON_USE_MODULE_STATE
    // EXPERIMENTAL !!
    #define CYTHON_USE_MODULE_STATE 0
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE 1
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    // Python 3.12a5 deprecated "ma_version_tag"
    #define CYTHON_USE_DICT_VERSIONS  (PY_VERSION_HEX < 0x030C00A5)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK 1
  #endif
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 1
  #endif
#endif

#if defined(HPY)
  #define CYTHON_USING_HPY 1
  #if PY_MAJOR_VERSION < 3
  #error "Cython/HPy requires Python 3 or newer"
  #endif
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  /* Module state is not yet supported in HPy */
  #define CYTHON_USE_MODULE_STATE 0
  /* Any Python objects are generally opaque in HPy */
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_USE_TYPE_SPECS
  #define CYTHON_USE_TYPE_SPECS 1
  #undef CYTHON_COMPILING_IN_LIMITED_API
  #define CYTHON_COMPILING_IN_LIMITED_API 1
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  /* We don't use refnanny in HPy since it has the debug mode */
  #undef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
  #undef CYTHON_METH_FASTCALL
  #define CYTHON_METH_FASTCALL 1
  #undef CYTHON_CLINE_IN_TRACEBACK
  #define CYTHON_CLINE_IN_TRACEBACK 0 //Is disabled for the Limited API - probably safest to disable it for HPy then
#else
  #define CYTHON_USING_HPY 0
#endif

#ifndef CYTHON_FAST_PYCCALL
#define CYTHON_FAST_PYCCALL  CYTHON_FAST_PYCALL
#endif

#ifndef CYTHON_VECTORCALL
#define CYTHON_VECTORCALL  (CYTHON_FAST_PYCCALL && PY_VERSION_HEX >= 0x030800B1)
#endif

/* Whether to use METH_FASTCALL with a fake backported implementation of vectorcall */
#define CYTHON_BACKPORT_VECTORCALL (!CYTHON_USING_HPY && CYTHON_METH_FASTCALL && PY_VERSION_HEX < 0x030800B1)

#if CYTHON_USE_PYLONG_INTERNALS
  /* These short defines from the PyLong header can easily conflict with other code */
  #undef SHIFT
  #undef BASE
  #undef MASK
  /* Compile-time sanity check that these are indeed equal.  Github issue #2670. */
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif

#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif

#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif

// restrict
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif

// unused attribute
#ifndef CYTHON_UNUSED
  #if defined(__cplusplus)
    /* for clang __has_cpp_attribute(maybe_unused) is true even before C++17
     * but leads to warnings with -pedantic, since it is a C++17 feature */
    #if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
      #if __has_cpp_attribute(maybe_unused)
        #define CYTHON_UNUSED [[maybe_unused]]
      #endif
    #endif
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif

#ifndef CYTHON_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_UNUSED_VAR(x) (void)(x)
#  endif
#endif

#ifndef CYTHON_MAYBE_UNUSED_VAR
  #define CYTHON_MAYBE_UNUSED_VAR(x) CYTHON_UNUSED_VAR(x)
#endif

#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif

#ifndef CYTHON_USE_CPP_STD_MOVE
  // msvc doesn't set __cplusplus to a useful value
  #if defined(__cplusplus) && ( \
    __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1600))
    #define CYTHON_USE_CPP_STD_MOVE 1
  #else
    #define CYTHON_USE_CPP_STD_MOVE 0
  #endif
#endif

#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)

#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
            typedef unsigned char     uint8_t;
            typedef unsigned short    uint16_t;
            typedef unsigned int      uint32_t;
        #else
            typedef unsigned __int8   uint8_t;
            typedef unsigned __int16  uint16_t;
            typedef unsigned __int32  uint32_t;
        #endif
    #endif
    #if _MSC_VER < 1300
        #ifdef _WIN64
            typedef unsigned long long  __pyx_uintptr_t;
        #else
            typedef unsigned int        __pyx_uintptr_t;
        #endif
    #else
        #ifdef _WIN64
            typedef unsigned __int64    __pyx_uintptr_t;
        #else
            typedef unsigned __int32    __pyx_uintptr_t;
        #endif
    #endif
#else
    #include <stdint.h>
    typedef uintptr_t  __pyx_uintptr_t;
#endif


#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus)
    /* for clang __has_cpp_attribute(fallthrough) is true even before C++17
     * but leads to warnings with -pedantic, since it is a C++17 feature */
    #if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
      #if __has_cpp_attribute(fallthrough)
        #define CYTHON_FALLTHROUGH [[fallthrough]]
      #endif
    #endif

    #ifndef CYTHON_FALLTHROUGH
      #if __has_cpp_attribute(clang::fallthrough)
        #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
      #elif __has_cpp_attribute(gnu::fallthrough)
        #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
      #endif
    #endif
  #endif

  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif

  #if defined(__clang__) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000 /* Xcode < 7.0 */
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifdef __cplusplus
  template <typename T>
  struct __PYX_IS_UNSIGNED_IMPL {static const bool value = T(0) < T(-1);};
  #define __PYX_IS_UNSIGNED(type) (__PYX_IS_UNSIGNED_IMPL<type>::value)
#else
  #define __PYX_IS_UNSIGNED(type) (((type)-1) > 0)
#endif

#if CYTHON_COMPILING_IN_PYPY == 1
  #define __PYX_NEED_TP_PRINT_SLOT  (PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x030A0000)
#else
  #define __PYX_NEED_TP_PRINT_SLOT  (PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000)
#endif
// reinterpret

// TODO: refactor existing code to use those macros
#define __PYX_REINTERPRET_FUNCION(func_pointer, other_pointer) ((func_pointer)(void(*)(void))(other_pointer))
// #define __PYX_REINTERPRET_POINTER(pointer_type, pointer) ((pointer_type)(void *)(pointer))
// #define __PYX_RUNTIME_REINTERPRET(type, var) (*(type *)(&var))


/////////////// CInitCode ///////////////

// inline attribute
#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif


/////////////// CppInitCode ///////////////

#ifndef __cplusplus
  #error "Cython files generated with the C++ option must be compiled with a C++ compiler."
#endif

// inline attribute
#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #else
    #define CYTHON_INLINE inline
  #endif
#endif

// Work around clang bug https://stackoverflow.com/questions/21847816/c-invoke-nested-template-class-destructor
template<typename T>
void __Pyx_call_destructor(T& x) {
    x.~T();
}

// Used for temporary variables of "reference" type.
template<typename T>
class __Pyx_FakeReference {
  public:
    __Pyx_FakeReference() : ptr(NULL) { }
    // __Pyx_FakeReference(T& ref) : ptr(&ref) { }
    // Const version needed as Cython doesn't know about const overloads (e.g. for stl containers).
    __Pyx_FakeReference(const T& ref) : ptr(const_cast<T*>(&ref)) { }
    T *operator->() { return ptr; }
    T *operator&() { return ptr; }
    operator T&() { return *ptr; }
    // TODO(robertwb): Delegate all operators (or auto-generate unwrapping code where needed).
    template<typename U> bool operator ==(const U& other) const { return *ptr == other; }
    template<typename U> bool operator !=(const U& other) const { return *ptr != other; }
    template<typename U> bool operator==(const __Pyx_FakeReference<U>& other) const { return *ptr == *other.ptr; }
    template<typename U> bool operator!=(const __Pyx_FakeReference<U>& other) const { return *ptr != *other.ptr; }
  private:
    T *ptr;
};


/////////////// HPyInitCode ///////////////
//@substitute: naming

#if CYTHON_USING_HPY
  #define HPY_CONTEXT_CNAME $hpy_context_cname
  #define HPY_CONTEXT_TYPE HPyContext *
  #define HPY_CONTEXT_ONLY_ARG_DEF HPY_CONTEXT_TYPE HPY_CONTEXT_CNAME
  #define HPY_CONTEXT_ONLY_ARG_CALL HPY_CONTEXT_CNAME
  #define HPY_CONTEXT_FIRST_ARG_DEF HPY_CONTEXT_TYPE HPY_CONTEXT_CNAME,
  #define HPY_CONTEXT_FIRST_ARG_CALL HPY_CONTEXT_CNAME,

  #define API_SSIZE_T HPy_ssize_t

  #define PYOBJECT_TYPE HPy
  #define PYTYPEOBJECT_TYPE HPy
  #define PYOBJECT_FIELD_TYPE HPyField
  #define PYOBJECT_FIELD_STORE(owner, field, h) HPyField_Store(HPY_CONTEXT_CNAME, owner, &field, h)
  #define PYOBJECT_FIELD_LOAD(owner, field) HPyField_Load(HPY_CONTEXT_CNAME, owner, field)
  #define PYOBJECT_GLOBAL_TYPE HPyGlobal
  #define PYTYPEOBJECT_GLOBAL_TYPE HPyGlobal
  #define PYOBJECT_GLOBAL_STORE(global, h) HPyGlobal_Store(HPY_CONTEXT_CNAME, &global, h)
  #define PYOBJECT_GLOBAL_LOAD(global) HPyGlobal_Load(HPY_CONTEXT_CNAME, global)
  #define PYOBJECT_GLOBAL_CLOSEREF(ref) HPy_Close(HPY_CONTEXT_CNAME, ref)
  #define CAPI_IS_POINTER
  #define CAPI_NEEDS_DEREFERENCE

  #define PYOBJECT_NEWREF(h) HPy_Dup(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_XNEWREF(h) HPy_Dup(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_CLOSEREF(h) HPy_Close(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_XCLOSEREF(h) HPy_Close(HPY_CONTEXT_CNAME, h)
  #define REFNANNY_CLOSEREF(func, h) PYOBJECT_CLOSEREF(h)

  #define API_CALL_FUNC(callable, args, nargs, kwnames) HPy_Call(HPY_CONTEXT_CNAME, callable, args, nargs, kwnames)

  #define PYERR_OCCURRED() HPyErr_Occurred(HPY_CONTEXT_CNAME)
  #define PYERR_CLEAR() HPyErr_Clear(HPY_CONTEXT_CNAME)
  #define PYERR_EXCEPTIONMATCHES(exc) HPyErr_ExceptionMatches(HPY_CONTEXT_CNAME, (exc))

  #define PYOBJECT_FROM_LONG(i) HPyLong_FromLong(HPY_CONTEXT_CNAME, i)
  #define PYOBJECT_FROM_DOUBLE(f) HPyFloat_FromDouble(HPY_CONTEXT_CNAME, f)
  #define PYOBJECT_FROM_STRING(s) HPyUnicode_FromString(HPY_CONTEXT_CNAME, s) //not yet needed in C API version

  #define PYOBJECT_LONG_AS_SSIZE(l) HPyLong_AsSsize_t(HPY_CONTEXT_CNAME, l)

  #define HPY_LEGACY_OBJECT_FROM(o) HPy_FromPyObject(HPY_CONTEXT_CNAME, o)
  #define HPY_LEGACY_OBJECT_AS(o) HPy_AsPyObject(HPY_CONTEXT_CNAME, o)
  #define HPY_LEGACY_OBJECT_ARRAY_AS(o, ssize) HPy_AsPyObjectArray(HPY_CONTEXT_CNAME, o, ssize)

  #define PYMODULEDEF_TYPE HPyModuleDef
  #define PYMETHODDEF_TYPE HPyDef
  #define TYPESPEC_TYPE HPyType_Spec
  #define TYPE_FROM_MOD_AND_SPEC(m, s, b) HPyType_FromModuleAndSpec(HPY_CONTEXT_CNAME, m, &s, b)
  #define TYPESPEC_GET(s, field) s.field
  #define TYPE_CHECK(o) HPy_TypeCheck(HPY_CONTEXT_CNAME, (o), HPY_CONTEXT_CNAME->h_TypeType)

  #define API_NULL_VALUE HPy_NULL
  #define API_DEFAULT_VALUE HPy_NULL
  #define API_IS_NULL(h) HPy_IsNull(h)
  #define API_IS_NOT_NULL(h) !HPy_IsNull(h)
  #define API_IS_EQUAL(a, b) HPy_Is(HPY_CONTEXT_CNAME, a, b)
  #define API_ASSIGN_NONE HPy_Dup(HPY_CONTEXT_CNAME, HPY_CONTEXT_CNAME->h_None)
  #define API_IS_TRUE(h) HPy_IsTrue(HPY_CONTEXT_CNAME, h)
  #define API_IS_FALSE(h) !HPy_IsTrue(HPY_CONTEXT_CNAME, h)

  /* constants */
  #define API_NONE_VALUE HPY_CONTEXT_CNAME->h_None
  #define API_TRUE HPY_CONTEXT_CNAME->h_True
  #define API_FALSE HPY_CONTEXT_CNAME->h_False
  #define API_EXC_ATTRIBUTEERROR HPY_CONTEXT_CNAME->h_AttributeError
  #define API_EXC(name) (HPY_CONTEXT_CNAME->h_ ## name)

  #define API_VECTORCALLFUNC HPyCallFunction

  #define DICT_NEW() HPyDict_New(HPY_CONTEXT_CNAME)
  #define DICT_GET_ITEM(o, attr_name) HPy_GetItem(HPY_CONTEXT_CNAME, o, attr_name)
  #define DICT_SET_ITEM(o, attr_name, attr_val) HPy_SetItem(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define DICT_GET_ITEM_STR(o, attr_name) HPy_GetItem_s(HPY_CONTEXT_CNAME, o, attr_name)
  #define DICT_SET_ITEM_STR(o, attr_name, attr_val) HPy_SetItem_s(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define DICT_CHECK(o) HPyDict_Check(HPY_CONTEXT_CNAME, o)

  #define PYOBJECT_GET_ITEM(o, attr_name) HPy_GetItem(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ITEM(o, attr_name, attr_val) HPy_SetItem(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR(o, attr_name) HPy_GetAttr(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ATTR(o, attr_name, attr_val) HPy_SetAttr(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR_STR(o, attr_name) HPy_GetAttr_s(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ATTR_STR(o1, attr_name, o2) HPy_SetAttr_s(HPY_CONTEXT_CNAME, o1, attr_name, o2)

  #define PYMODULE_GETDICT_ATTR(mod) HPy_GetAttr_s(HPY_CONTEXT_CNAME, mod, "__dict__")

  #define BYTES_FROM_STR_AND_SIZE(str, size) HPyBytes_FromStringAndSize(HPY_CONTEXT_CNAME, str, size)

  #define TUPLE_CREATE_EMPTY() HPyTuple_FromArray(HPY_CONTEXT_CNAME, NULL, 0)
  #define TUPLE_GET_ITEM(h, pos) HPy_GetItem(HPY_CONTEXT_CNAME, h, PYOBJECT_FROM_LONG(pos))
  #define TUPLE_GET_SIZE(h) HPy_Length(HPY_CONTEXT_CNAME, (h))
  #define TUPLE_BUILDER_TYPE HPyTupleBuilder
  #define TUPLE_CREATE_START(target, builder, size) builder = HPyTupleBuilder_New(HPY_CONTEXT_CNAME, size)
  #define TUPLE_CREATE_ASSIGN(tuple, builder, index, item) HPyTupleBuilder_Set(HPY_CONTEXT_CNAME, builder, index, item)
  #define TUPLE_CREATE_FINALISE(target, builder) target = HPyTupleBuilder_Build(HPY_CONTEXT_CNAME, builder);
  #define TUPLE_PACK(num_args, ...) HPyTuple_Pack(HPY_CONTEXT_CNAME, num_args, __VA_ARGS__)

  #define UNICODE_FROM_FORMAT(format_str, ...) HPyUnicode_FromFormat(HPY_CONTEXT_CNAME, format_str, __VA_ARGS__)
#else
  #define HPY_CONTEXT_CNAME
  #define HPY_CONTEXT_ONLY_ARG_DEF void
  #define HPY_CONTEXT_ONLY_ARG_CALL
  #define HPY_CONTEXT_FIRST_ARG_DEF
  #define HPY_CONTEXT_FIRST_ARG_CALL

  #define API_SSIZE_T Py_ssize_t

  #define PYOBJECT_TYPE PyObject *
  #define PYTYPEOBJECT_TYPE PyTypeObject *
  #define PYOBJECT_FIELD_TYPE PyObject *
  #define PYOBJECT_FIELD_STORE(owner, field, h) field = h
  #define PYOBJECT_FIELD_LOAD(owner, field) field
  #define PYOBJECT_GLOBAL_TYPE PyObject *
  #define PYTYPEOBJECT_GLOBAL_TYPE PyTypeObject *
  #define PYOBJECT_GLOBAL_STORE(global, h) global = h
  #define PYOBJECT_GLOBAL_LOAD(global) global
  #define PYOBJECT_GLOBAL_CLOSEREF(ref) /* nop */
  #define CAPI_IS_POINTER * //Some types are sometimes pointers and sometimes not (i.e. PyModuleDef) where the type is always the same in HPy
  #define CAPI_NEEDS_DEREFERENCE &

  #define PYOBJECT_NEWREF(h) Py_NewRef(h)
  #define PYOBJECT_XNEWREF(h) Py_XNewRef(h)
  #define PYOBJECT_CLOSEREF(h) Py_DECREF(h)
  #define PYOBJECT_XCLOSEREF(h) Py_XDECREF(h)
  #define REFNANNY_CLOSEREF(func, h) func(h)

  #define PYERR_OCCURRED() (!!PyErr_Occurred())
  #define PYERR_CLEAR() PyErr_Clear()
  #define PYERR_EXCEPTIONMATCHES(exc) PyErr_ExceptionMatches((exc))

  #define API_CALL_FUNC(callable, args, nargs, kwnames) PyObject_Call(HPY_CONTEXT_CNAME, callable, args, kwnames)

  #define PYOBJECT_FROM_LONG(i) PyInt_FromLong(i)
  #define PYOBJECT_FROM_DOUBLE(f) PyFloat_FromDouble(f)

  #define PYOBJECT_LONG_AS_SSIZE(l) PyLong_AsSsize_t(l)

  #define HPY_LEGACY_OBJECT_FROM(o) o
  #define HPY_LEGACY_OBJECT_AS(o) o
  #define HPY_LEGACY_OBJECT_ARRAY_AS(o, ssize) o

  #define PYMODULEDEF_TYPE struct PyModuleDef
  #define PYMETHODDEF_TYPE PyMethodDef
  #define TYPESPEC_TYPE PyType_Spec
  #define TYPE_FROM_MOD_AND_SPEC(m, s, b) PyType_FromModuleAndSpec(m, s, b)
  #define TYPESPEC_GET(s, field) s->field
  #define TYPE_CHECK(o) PyType_Check(o)

  #define API_NULL_VALUE NULL
  #define API_DEFAULT_VALUE 0
  #define API_IS_NULL(h) !h //Both are here as otherwise we would get !!h for API_IS_NOT_NULL, which is hard to read - but it can be made so if necessary
  #define API_IS_NOT_NULL(h) h
  #define API_IS_EQUAL(a, b) a==b
  #define API_ASSIGN_NONE Py_None
  #define API_IS_TRUE(h) PyObject_IsTrue(h)
  #define API_IS_FALSE(h) !PyObject_Not(h)

  /* constants */
  #define API_NONE_VALUE Py_None
  #define API_TRUE Py_True
  #define API_FALSE Py_False
  #define API_EXC(name) (PyExc_ ## name)

  #define DICT_NEW() PyDict_New()
  #define DICT_GET_ITEM(o, attr_name) PyDict_GetItem(o, attr_name)
  #define DICT_SET_ITEM(o, attr_name, attr_val) PyDict_SetItem(o, attr_name, attr_val)
  #define DICT_GET_ITEM_STR(o, attr_name) PyDict_GetItemString(o, attr_name)
  #define DICT_SET_ITEM_STR(o, attr_name, attr_val) PyDict_SetItemString(o, attr_name, attr_val)
  #define DICT_CHECK(o) PyDict_Check(o)

  #define PYOBJECT_GET_ITEM(o, attr_name) PyObject_GetItem(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ITEM(o, attr_name, attr_val) PyObject_SetItem(o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR(o, attr_name) PyObject_GetAttr(o, attr_name)
  #define PYOBJECT_SET_ATTR(o, attr_name, attr_val) PyObject_SetAttr(o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR_STR(o, attr_name) PyObject_GetAttrString(o, attr_name)
  #define PYOBJECT_SET_ATTR_STR(o1, attr_name, o2) PyObject_SetAttrString(o1, attr_name, o2)

  #define PYMODULE_GETDICT_ATTR(mod) PyModule_GetDict(mod)

  #define BYTES_FROM_STR_AND_SIZE(str, size) PyBytes_FromStringAndSize(str, size)

  #define TUPLE_CREATE_EMPTY() PyTuple_New(0)
  #define TUPLE_GET_ITEM(h, pos) __Pyx_PySequence_ITEM(HPY_CONTEXT_CNAME, h, pos)
  #define TUPLE_GET_SIZE(h) PyTuple_GET_SIZE(h)
  #define TUPLE_BUILDER_TYPE PyObject * //Not used, just needed to prevent errors
  #define TUPLE_CREATE_START(target, builder, size) target=PyTuple_New(size)
  #define TUPLE_CREATE_ASSIGN(tuple, builder, index, item) __Pyx_PyTuple_SET_ITEM(tuple, index, item)
  #define TUPLE_CREATE_FINALISE(target, null)
  #define TUPLE_PACK(num_args, ...) PyTuple_Pack(num_args, __VA_ARGS__)

  #define UNICODE_FROM_FORMAT(format_str, ...) PyUnicode_FromFormat(format_str, __VA_ARGS__)

#endif

/////////////// PythonCompatibility ///////////////

#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"

// TODO: remove this block
#define __Pyx_BUILTIN_MODULE_NAME "builtins"
#define __Pyx_DefaultClassType PyType_Type

#if CYTHON_COMPILING_IN_LIMITED_API
    // Note that the limited API doesn't know about PyCodeObject, so the type of this
    // is PyObject (unlike for the main API)
    static CYTHON_INLINE PyObject* __Pyx_PyCode_New(int a, int p, int k, int l, int s, int f,
                                                    PyObject *code, PyObject *c, PyObject* n, PyObject *v,
                                                    PyObject *fv, PyObject *cell, PyObject* fn,
                                                    PyObject *name, int fline, PyObject *lnos) {
        // Backout option for generating a code object.
        // PyCode_NewEmpty isn't in the limited API. Therefore the two options are
        //  1. Python call of the code type with a long list of positional args.
        //  2. Generate a code object by compiling some trivial code, and customize.
        // We use the second because it's less sensitive to changes in the code type
        // constructor with version.
        PyObject *exception_table = NULL;
        PyObject *types_module=NULL, *code_type=NULL, *result=NULL;
        #if __PYX_LIMITED_VERSION_HEX < 0x030B0000
        PyObject *version_info; // borrowed
        PyObject *py_minor_version = NULL;
        #endif
        long minor_version = 0;
        PyObject *type, *value, *traceback;

        // we must be able to call this while an exception is happening - thus clear then restore the state
        PyErr_Fetch(&type, &value, &traceback);

        #if __PYX_LIMITED_VERSION_HEX >= 0x030B0000
        minor_version = 11; // we don't yet need to distinguish between versions > 11
        // Note that from 3.13, when we do we can use Py_Version
        #else
        if (!(version_info = PySys_GetObject("version_info"))) goto end;
        if (!(py_minor_version = PySequence_GetItem(version_info, 1))) goto end;
        minor_version = PyLong_AsLong(py_minor_version);
        Py_DECREF(py_minor_version);
        if (minor_version == -1 && PyErr_Occurred()) goto end;
        #endif

        if (!(types_module = PyImport_ImportModule("types"))) goto end;
        if (!(code_type = PyObject_GetAttrString(types_module, "CodeType"))) goto end;

        if (minor_version <= 7) {
            // 3.7:
            // code(argcount, kwonlyargcount, nlocals, stacksize, flags, codestring,
            //        constants, names, varnames, filename, name, firstlineno,
            //        lnotab[, freevars[, cellvars]])
            (void)p;
            result = PyObject_CallFunction(code_type, "iiiiiOOOOOOiOO", a, k, l, s, f, code,
                          c, n, v, fn, name, fline, lnos, fv, cell);
        } else if (minor_version <= 10) {
            // 3.8, 3.9, 3.10
            // code(argcount, posonlyargcount, kwonlyargcount, nlocals, stacksize,
            //    flags, codestring, constants, names, varnames, filename, name,
            //    firstlineno, lnotab[, freevars[, cellvars]])
            // 3.10 switches lnotab for linetable, but is otherwise the same
            result = PyObject_CallFunction(code_type, "iiiiiiOOOOOOiOO", a,p, k, l, s, f, code,
                          c, n, v, fn, name, fline, lnos, fv, cell);
        } else {
            // 3.11, 3.12
            // code(argcount, posonlyargcount, kwonlyargcount, nlocals, stacksize,
            //    flags, codestring, constants, names, varnames, filename, name,
            //    qualname, firstlineno, linetable, exceptiontable, freevars=(), cellvars=(), /)
            // We use name and qualname for simplicity
            if (!(exception_table = PyBytes_FromStringAndSize(NULL, 0))) goto end;
            result = PyObject_CallFunction(code_type, "iiiiiiOOOOOOOiOO", a,p, k, l, s, f, code,
                          c, n, v, fn, name, name, fline, lnos, exception_table, fv, cell);
        }

    end:
        Py_XDECREF(code_type);
        Py_XDECREF(exception_table);
        Py_XDECREF(types_module);
        if (type) {
            PyErr_Restore(type, value, traceback);
        }
        return result;
    }

    // Cython uses these constants but they are not available in the limited API.
    // (it'd be nice if there was a more robust way of looking these up)
    #ifndef CO_OPTIMIZED
    #define CO_OPTIMIZED 0x0001
    #endif
    #ifndef CO_NEWLOCALS
    #define CO_NEWLOCALS 0x0002
    #endif
    #ifndef CO_VARARGS
    #define CO_VARARGS 0x0004
    #endif
    #ifndef CO_VARKEYWORDS
    #define CO_VARKEYWORDS 0x0008
    #endif
    #ifndef CO_ASYNC_GENERATOR
    #define CO_ASYNC_GENERATOR 0x0200
    #endif
    #ifndef CO_GENERATOR
    #define CO_GENERATOR 0x0020
    #endif
    #ifndef CO_COROUTINE
    #define CO_COROUTINE 0x0080
    #endif
#elif PY_VERSION_HEX >= 0x030B0000
  static CYTHON_INLINE PyCodeObject* __Pyx_PyCode_New(int a, int p, int k, int l, int s, int f,
                                                    PyObject *code, PyObject *c, PyObject* n, PyObject *v,
                                                    PyObject *fv, PyObject *cell, PyObject* fn,
                                                    PyObject *name, int fline, PyObject *lnos) {
    // As earlier versions, but
    //  1. pass an empty bytes string as exception_table
    //  2. pass name as qualname (TODO this might implementing properly in future)
    PyCodeObject *result;
    PyObject *empty_bytes = PyBytes_FromStringAndSize("", 0);  // we don't have access to __pyx_empty_bytes here
    if (!empty_bytes) return NULL;
    result =
      #if PY_VERSION_HEX >= 0x030C0000
        PyUnstable_Code_NewWithPosOnlyArgs
      #else
        PyCode_NewWithPosOnlyArgs
      #endif
        (a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, name, fline, lnos, empty_bytes);
    Py_DECREF(empty_bytes);
    return result;
  }
#elif PY_VERSION_HEX >= 0x030800B2 && !CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyCode_New(a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos) \
          PyCode_NewWithPosOnlyArgs(a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, p, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos) \
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif

#if PY_VERSION_HEX >= 0x030900A4 || defined(Py_IS_TYPE)
  #define __Pyx_IS_TYPE(ob, type) Py_IS_TYPE(ob, type)
#else
  #define __Pyx_IS_TYPE(ob, type) (((const PyObject*)ob)->ob_type == (type))
#endif

#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_Is)
  #define __Pyx_Py_Is(x, y)  Py_Is(x, y)
#else
  #define __Pyx_Py_Is(x, y) ((x) == (y))
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_IsNone)
  #define __Pyx_Py_IsNone(ob) Py_IsNone(ob)
#else
  #define __Pyx_Py_IsNone(ob) __Pyx_Py_Is((ob), Py_None)
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_IsTrue)
  #define __Pyx_Py_IsTrue(ob) Py_IsTrue(ob)
#else
  #define __Pyx_Py_IsTrue(ob) __Pyx_Py_Is((ob), Py_True)
#endif
#if PY_VERSION_HEX >= 0x030A00B1 || defined(Py_IsFalse)
  #define __Pyx_Py_IsFalse(ob) Py_IsFalse(ob)
#else
  #define __Pyx_Py_IsFalse(ob) __Pyx_Py_Is((ob), Py_False)
#endif
#define __Pyx_NoneAsNull(obj)  (__Pyx_Py_IsNone(obj) ? NULL : (obj))

#if PY_VERSION_HEX >= 0x030900F0 && !CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyObject_GC_IsFinalized(o) PyObject_GC_IsFinalized(o)
#else
  #define __Pyx_PyObject_GC_IsFinalized(o) _PyGC_FINALIZED(o)
#endif

#ifndef CO_COROUTINE
  #define CO_COROUTINE 0x80
#endif
#ifndef CO_ASYNC_GENERATOR
  #define CO_ASYNC_GENERATOR 0x200
#endif

#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef Py_TPFLAGS_SEQUENCE
  #define Py_TPFLAGS_SEQUENCE 0
#endif
#ifndef Py_TPFLAGS_MAPPING
  #define Py_TPFLAGS_MAPPING 0
#endif

#ifndef METH_STACKLESS
  // already defined for Stackless Python (all versions) and C-Python >= 3.7
  // value if defined: Stackless Python < 3.6: 0x80 else 0x100
  #define METH_STACKLESS 0
#endif
#ifndef METH_FASTCALL
  // new in CPython 3.6, but changed in 3.7 - see
  // positional-only parameters:
  //   https://bugs.python.org/issue29464
  // const args:
  //   https://bugs.python.org/issue32240
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  // new in CPython 3.7, used to be old signature of _PyCFunctionFast() in 3.6
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif

#if CYTHON_METH_FASTCALL
  #define __Pyx_METH_FASTCALL METH_FASTCALL
  #define __Pyx_PyCFunction_FastCall __Pyx_PyCFunctionFast
  #define __Pyx_PyCFunction_FastCallWithKeywords __Pyx_PyCFunctionFastWithKeywords
#else
  #define __Pyx_METH_FASTCALL METH_VARARGS
  #define __Pyx_PyCFunction_FastCall PyCFunction
  #define __Pyx_PyCFunction_FastCallWithKeywords PyCFunctionWithKeywords
#endif

#if CYTHON_VECTORCALL
  #define __pyx_vectorcallfunc vectorcallfunc
  #define __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET  PY_VECTORCALL_ARGUMENTS_OFFSET
  #define __Pyx_PyVectorcall_NARGS(n)  PyVectorcall_NARGS((size_t)(n))
#elif CYTHON_BACKPORT_VECTORCALL
#if CYTHON_USING_HPY
#error "cannot use HPy when backporting vectorcall impl"
#endif
  typedef PyObject *(*__pyx_vectorcallfunc)(PyObject *callable, PyObject *const *args,
                                            size_t nargsf, PyObject *kwnames);
  #define __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET  ((size_t)1 << (8 * sizeof(size_t) - 1))
  #define __Pyx_PyVectorcall_NARGS(n)  ((Py_ssize_t)(((size_t)(n)) & ~__Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET))
#else
  #define __Pyx_PY_VECTORCALL_ARGUMENTS_OFFSET  0
  #define __Pyx_PyVectorcall_NARGS(n)  ((Py_ssize_t)(n))
#endif

// These PyCFunction related macros get redefined in CythonFunction.c.
// We need our own copies because the inline functions in CPython have a type-check assert
// that breaks with a CyFunction in debug mode.
#if PY_VERSION_HEX >= 0x030900B1
#define __Pyx_PyCFunction_CheckExact(func)  PyCFunction_CheckExact(func)
#else
#define __Pyx_PyCFunction_CheckExact(func)  PyCFunction_Check(func)
#endif
#define __Pyx_CyOrPyCFunction_Check(func)  PyCFunction_Check(func)

#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_CyOrPyCFunction_GET_FUNCTION(func)  (((PyCFunctionObject*)(func))->m_ml->ml_meth)
#elif !CYTHON_COMPILING_IN_LIMITED_API
// It's probably easier for non-CPythons to support PyCFunction_GET_FUNCTION() than the object struct layout.
#define __Pyx_CyOrPyCFunction_GET_FUNCTION(func)  PyCFunction_GET_FUNCTION(func)
// Unused in CYTHON_COMPILING_IN_LIMITED_API.
#endif
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_CyOrPyCFunction_GET_FLAGS(func)  (((PyCFunctionObject*)(func))->m_ml->ml_flags)
static CYTHON_INLINE PyObject* __Pyx_CyOrPyCFunction_GET_SELF(PyObject *func) {
    return (__Pyx_CyOrPyCFunction_GET_FLAGS(func) & METH_STATIC) ? NULL : ((PyCFunctionObject*)func)->m_self;
}
// Only used if CYTHON_COMPILING_IN_CPYTHON.
#endif
static CYTHON_INLINE int __Pyx__IsSameCFunction(PyObject *func, void *cfunc) {
#if CYTHON_COMPILING_IN_LIMITED_API
    return PyCFunction_Check(func) && PyCFunction_GetFunction(func) == (PyCFunction) cfunc;
#else
    return PyCFunction_Check(func) && PyCFunction_GET_FUNCTION(func) == (PyCFunction) cfunc;
#endif
}
#define __Pyx_IsSameCFunction(func, cfunc)   __Pyx__IsSameCFunction(func, cfunc)

// PEP-573: PyCFunction holds reference to defining class (PyCMethodObject)
#if __PYX_LIMITED_VERSION_HEX < 0x030900B1
  #define __Pyx_PyType_FromModuleAndSpec(m, s, b)  ((void)m, PyType_FromSpecWithBases(s, b))
  typedef PyObject *(*__Pyx_PyCMethod)(PyObject *, PyTypeObject *, PyObject *const *, size_t, PyObject *);
#else
  #define __Pyx_PyType_FromModuleAndSpec(m, s, b)  TYPE_FROM_MOD_AND_SPEC(m, s, b)
  #define __Pyx_PyCMethod  PyCMethod
#endif
#ifndef METH_METHOD
  #define METH_METHOD 0x200
#endif

#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif

#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif

#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyThreadState_Current PyThreadState_Get()
#elif !CYTHON_FAST_THREAD_STATE
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x030d00A1
  #define __Pyx_PyThreadState_Current PyThreadState_GetUnchecked()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#endif

#if CYTHON_COMPILING_IN_LIMITED_API
static CYTHON_INLINE void *__Pyx_PyModule_GetState(PyObject *op)
{
    void *result;

    result = PyModule_GetState(op);
    if (!result)
        Py_FatalError("Couldn't find the module state");
    return result;
}
#endif

#define __Pyx_PyObject_GetSlot(obj, name, func_ctype)  __Pyx_PyType_GetSlot(Py_TYPE(obj), name, func_ctype)
#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyType_GetSlot(type, name, func_ctype)  ((func_ctype) PyType_GetSlot((type), Py_##name))
#else
  #define __Pyx_PyType_GetSlot(type, name, func_ctype)  ((type)->name)
#endif

#if CYTHON_USING_HPY
#define __Pyx_PyDict_NewPresized(n) DICT_NEW()
#elif CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030d0000 || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif

#define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
#define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)

#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030d0000 && CYTHON_USE_UNICODE_INTERNALS
// _PyDict_GetItem_KnownHash() existed from CPython 3.5 to 3.12, but it was
// dropping exceptions in 3.5. Since 3.6, exceptions are kept.
#define __Pyx_PyDict_GetItemStrWithError(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
static CYTHON_INLINE PyObject * __Pyx_PyDict_GetItemStr(PyObject *dict, PyObject *name) {
    PyObject *res = __Pyx_PyDict_GetItemStrWithError(dict, name);
    if (res == NULL) PyErr_Clear();
    return res;
}
#elif !CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07020000
#define __Pyx_PyDict_GetItemStrWithError  PyDict_GetItemWithError
#define __Pyx_PyDict_GetItemStr(dict, name)           DICT_GET_ITEM(dict, name)
#else
static CYTHON_INLINE PyObject * __Pyx_PyDict_GetItemStrWithError(PyObject *dict, PyObject *name) {
    // This is tricky - we should return a borrowed reference but not swallow non-KeyError exceptions. 8-|
    // But: this function is only used in Py2 and older PyPys,
    // and currently only for argument parsing and other non-correctness-critical lookups
    // and we know that 'name' is an interned 'str' with pre-calculated hash value (only comparisons can fail),
    // thus, performance matters more than correctness here, especially in the "not found" case.
#if CYTHON_COMPILING_IN_PYPY
    // So we ignore any exceptions in old PyPys ...
    return PyDict_GetItem(dict, name);
#else
    // and hack together a stripped-down and modified PyDict_GetItem() in CPython 2.
    PyDictEntry *ep;
    PyDictObject *mp = (PyDictObject*) dict;
    long hash = ((PyStringObject *) name)->ob_shash;
    assert(hash != -1); /* hash values of interned strings are always initialised */
    ep = (mp->ma_lookup)(mp, name, hash);
    if (ep == NULL) {
        // error occurred
        return NULL;
    }
    // found or not found
    return ep->me_value;
#endif
}
#define __Pyx_PyDict_GetItemStr(dict, name)           DICT_GET_ITEM(dict, name)
#endif

/* Type slots */

#if CYTHON_USE_TYPE_SLOTS
  #define __Pyx_PyType_GetFlags(tp)   (((PyTypeObject *)tp)->tp_flags)
  #define __Pyx_PyType_HasFeature(type, feature)  ((__Pyx_PyType_GetFlags(type) & (feature)) != 0)
  #define __Pyx_PyObject_GetIterNextFunc(obj)  (Py_TYPE(obj)->tp_iternext)
#else
  #define __Pyx_PyType_GetFlags(tp)   (PyType_GetFlags((PyTypeObject *)tp))
  #define __Pyx_PyType_HasFeature(type, feature)  PyType_HasFeature(type, feature)
  #define __Pyx_PyObject_GetIterNextFunc(obj)  PyIter_Next
#endif

#if CYTHON_COMPILING_IN_LIMITED_API
  // Using PyObject_GenericSetAttr to bypass types immutability protection feels
  // a little hacky, but it does work in the limited API .
  // (It doesn't work on PyPy but that probably isn't a bug.)
  #define __Pyx_SetItemOnTypeDict(tp, k, v) PyObject_GenericSetAttr((PyObject*)tp, k, v)
#else
  #define __Pyx_SetItemOnTypeDict(tp, k, v) PyDict_SetItem(tp->tp_dict, k, v)
#endif

#if CYTHON_USE_TYPE_SPECS && PY_VERSION_HEX >= 0x03080000
// In Py3.8+, instances of heap types need to decref their type on deallocation.
// https://bugs.python.org/issue35810
#define __Pyx_PyHeapTypeObject_GC_Del(obj)  { \
    PyTypeObject *type = Py_TYPE((PyObject*)obj); \
    assert(__Pyx_PyType_HasFeature(type, Py_TPFLAGS_HEAPTYPE)); \
    PyObject_GC_Del(obj); \
    Py_DECREF(type); \
}
#else
#define __Pyx_PyHeapTypeObject_GC_Del(obj)  PyObject_GC_Del(obj)
#endif

#if CYTHON_COMPILING_IN_LIMITED_API
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GetLength(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_ReadChar(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((void)u, 1114111U)
  #define __Pyx_PyUnicode_KIND(u)         ((void)u, (0))
  // __Pyx_PyUnicode_DATA() and __Pyx_PyUnicode_READ() must go together, e.g. for iteration.
  #define __Pyx_PyUnicode_DATA(u)         ((void*)u)
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)k, PyUnicode_ReadChar((PyObject*)(d), i))
  //#define __Pyx_PyUnicode_WRITE(k, d, i, ch)  /* not available */
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GetLength(u))
#else
  #if PY_VERSION_HEX >= 0x030C0000
    // Py3.12 / PEP-623 removed wstr type unicode strings and all of the PyUnicode_READY() machinery.
    #define __Pyx_PyUnicode_READY(op)       (0)
  #else
    #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ? \
                                                0 : _PyUnicode_Ready((PyObject *)(op)))
  #endif

  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         ((int)PyUnicode_KIND(u))
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, (Py_UCS4) ch)
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #else
    #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03090000
    // Avoid calling deprecated C-API functions in Py3.9+ that PEP-623 schedules for removal in Py3.12.
    // https://www.python.org/dev/peps/pep-0623/
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : ((PyCompactUnicodeObject *)(u))->wstr_length))
    #else
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
    #endif
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ? \
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif

#if CYTHON_COMPILING_IN_PYPY
  #if !defined(PyUnicode_DecodeUnicodeEscape)
    #define PyUnicode_DecodeUnicodeEscape(s, size, errors)  PyUnicode_Decode(s, size, "unicode_escape", errors)
  #endif
  #if !defined(PyUnicode_Contains)
    #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
  #endif
  #if !defined(PyByteArray_Check)
    #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
  #endif
  #if !defined(PyObject_Format)
    #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
  #endif
#endif

// ("..." % x)  must call PyNumber_Remainder() if x is a string subclass that implements "__rmod__()".
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)

// TODO: remove this block
#define PyBaseString_Type            PyUnicode_Type
#define PyStringObject               PyUnicodeObject
#define PyString_Type                PyUnicode_Type
#define PyString_Check               PyUnicode_Check
#define PyString_CheckExact          PyUnicode_CheckExact
// PyPy3 used to define "PyObject_Unicode"
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif

#define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
#define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)

#if CYTHON_COMPILING_IN_CPYTHON
  #define __Pyx_PySequence_ListKeepNew(obj) \
    (likely(PyList_CheckExact(obj) && Py_REFCNT(obj) == 1) ? __Pyx_NewRef(obj) : PySequence_List(obj))
#else
  #define __Pyx_PySequence_ListKeepNew(obj)  PySequence_List(obj)
#endif

#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        __Pyx_IS_TYPE(obj, &PySet_Type)
#endif

#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif

#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_ITEM(o, i) PySequence_ITEM(o, i)
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
  #define __Pyx_PyTuple_SET_ITEM(o, i, v) (PyTuple_SET_ITEM(o, i, v), (0))
  #define __Pyx_PyList_SET_ITEM(o, i, v) (PyList_SET_ITEM(o, i, v), (0))
  #define __Pyx_PyTuple_GET_SIZE(o) PyTuple_GET_SIZE(o)
  #define __Pyx_PyList_GET_SIZE(o) PyList_GET_SIZE(o)
  #define __Pyx_PySet_GET_SIZE(o) PySet_GET_SIZE(o)
  #define __Pyx_PyBytes_GET_SIZE(o) PyBytes_GET_SIZE(o)
  #define __Pyx_PyByteArray_GET_SIZE(o) PyByteArray_GET_SIZE(o)
#else
  #define __Pyx_PySequence_ITEM(o, i) PySequence_GetItem(o, i)
  // NOTE: might fail with exception => check for -1
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
  // Note that this doesn't leak a reference to whatever's at o[i]
  #define __Pyx_PyTuple_SET_ITEM(o, i, v) PyTuple_SetItem(o, i, v)
  #define __Pyx_PyList_SET_ITEM(o, i, v) PyList_SetItem(o, i, v)
  #define __Pyx_PyTuple_GET_SIZE(o) PyTuple_Size(o)
  #define __Pyx_PyList_GET_SIZE(o) PyList_Size(o)
  #define __Pyx_PySet_GET_SIZE(o) PySet_Size(o)
  #define __Pyx_PyBytes_GET_SIZE(o) PyBytes_Size(o)
  #define __Pyx_PyByteArray_GET_SIZE(o) PyByteArray_Size(o)
#endif

#if PY_VERSION_HEX >= 0x030d00A1
  #define __Pyx_PyImport_AddModuleRef(name) PyImport_AddModuleRef(name)
#else
  static CYTHON_INLINE PyObject *__Pyx_PyImport_AddModuleRef(const char *name) {
      PyObject *module = PyImport_AddModule(name);
      Py_XINCREF(module);
      return module;
  }
#endif

// TODO: remove this block
#define PyIntObject                  PyLongObject
#define PyInt_Type                   PyLong_Type
#define PyInt_Check(op)              PyLong_Check(op)
#define PyInt_CheckExact(op)         PyLong_CheckExact(op)
#define PyInt_FromString             PyLong_FromString
#define PyInt_FromUnicode            PyLong_FromUnicode
#define PyInt_FromLong               PyLong_FromLong
#define PyInt_FromSize_t             PyLong_FromSize_t
#define PyInt_FromSsize_t            PyLong_FromSsize_t
#define PyInt_AsLong                 PyLong_AsLong
#define PyInt_AS_LONG                PyLong_AS_LONG
#define PyInt_AsSsize_t              PyLong_AsSsize_t
#define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
#define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
#define PyNumber_Int                 PyNumber_Long
#define PyBoolObject                 PyLongObject

#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_InternFromString)
  #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
#endif

// TODO: remove this block
#define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
#define __Pyx_PyInt_AsHash_t   __Pyx_PyIndex_AsSsize_t

// backport of PyAsyncMethods from Py3.5 to older Py3.x versions
// (mis-)using the "tp_reserved" type slot which is re-activated as "tp_as_async" in Py3.5
#if CYTHON_USE_ASYNC_SLOTS
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
#else
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
    #define __Pyx_PyType_AsAsync(obj) NULL
#endif


/////////////// IncludeStructmemberH.proto ///////////////

#include <structmember.h>


/////////////// SmallCodeConfig.proto ///////////////

#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif


/////////////// PyModInitFuncType.proto ///////////////

#ifndef CYTHON_NO_PYINIT_EXPORT
  #define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#else
  // define this to PyObject * manually because PyMODINIT_FUNC adds __declspec(dllexport) to it's definition.
  #ifdef __cplusplus
  #define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
  #else
  #define __Pyx_PyMODINIT_FUNC PyObject *
  #endif
#endif


/////////////// FastTypeChecks.proto ///////////////

#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
#define __Pyx_TypeCheck2(obj, type1, type2) __Pyx_IsAnySubtype2(Py_TYPE(obj), (PyTypeObject *)type1, (PyTypeObject *)type2)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);/*proto*/
static CYTHON_INLINE int __Pyx_IsAnySubtype2(PyTypeObject *cls, PyTypeObject *a, PyTypeObject *b);/*proto*/
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);/*proto*/
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);/*proto*/
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_TypeCheck2(obj, type1, type2) (PyObject_TypeCheck(obj, (PyTypeObject *)type1) || PyObject_TypeCheck(obj, (PyTypeObject *)type2))
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyErr_ExceptionMatches2(err1, err2)  __Pyx_PyErr_GivenExceptionMatches2(__Pyx_PyErr_CurrentExceptionType(), err1, err2)

#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)

/////////////// FastTypeChecks ///////////////
//@requires: Exceptions.c::PyThreadStateGet
//@requires: Exceptions.c::PyErrFetchRestore

#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = __Pyx_PyType_GetSlot(a, tp_base, PyTypeObject*);
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}

static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    // should only get here for incompletely initialised types, i.e. never under normal usage patterns
    return __Pyx_InBases(a, b);
}

static CYTHON_INLINE int __Pyx_IsAnySubtype2(PyTypeObject *cls, PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (cls == a || cls == b) return 1;
    mro = cls->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            PyObject *base = PyTuple_GET_ITEM(mro, i);
            if (base == (PyObject *)a || base == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    // should only get here for incompletely initialised types, i.e. never under normal usage patterns
    return __Pyx_InBases(cls, a) || __Pyx_InBases(cls, b);
}


static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    if (exc_type1) {
        return __Pyx_IsAnySubtype2((PyTypeObject*)err, (PyTypeObject*)exc_type1, (PyTypeObject*)exc_type2);
    } else {
        return __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
}

// so far, we only call PyErr_GivenExceptionMatches() with an exception type (not instance) as first argument
// => optimise for that case

static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
    // the tight subtype checking in Py3 allows faster out-of-order comparison
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
            // FIXME: Py3: PyErr_SetString(PyExc_TypeError, "catching classes that do not inherit from BaseException is not allowed");
        }
    }
    return 0;
}

static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
            // FIXME: Py3: PyErr_SetString(PyExc_TypeError, "catching classes that do not inherit from BaseException is not allowed");
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}

static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    // Only used internally with known exception types => pure safety check assertions.
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}

#endif


/////////////// MathInitCode ///////////////

#if defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS)
  #ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES
  #endif
#endif
#include <math.h>

#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  // Initialize NaN.  The sign is irrelevant, an exponent with all bits 1 and
  // a nonzero mantissa means NaN.  If the first bit in the mantissa is 1, it is
  // a quiet NaN.
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif

#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif


/////////////// UtilityFunctionPredeclarations.proto ///////////////

typedef struct {PYOBJECT_GLOBAL_TYPE CAPI_IS_POINTER p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry; /*proto*/


/////////////// ForceInitThreads.proto ///////////////
//@proto_block: utility_code_proto_before_types

#ifndef __PYX_FORCE_INIT_THREADS
  #define __PYX_FORCE_INIT_THREADS 0
#endif


/////////////// ModuleCreationPEP489 ///////////////
//@substitute: naming

//#if CYTHON_PEP489_MULTI_PHASE_INIT
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))

    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}

#if CYTHON_COMPILING_IN_LIMITED_API
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *module, const char* from_name, const char* to_name, int allow_none)
#else
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none)
#endif
{
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
#if CYTHON_COMPILING_IN_LIMITED_API
            result = PyModule_AddObject(module, to_name, value);
#else
            result = PyDict_SetItemString(moddict, to_name, value);
#endif
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}

#if !CYTHON_USING_HPY
static CYTHON_SMALL_CODE PyObject* ${pymodule_create_func_cname}(PyObject *spec, PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    CYTHON_UNUSED_VAR(def);

    // For now, we only have exactly one module instance.
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (${module_cname})
        return __Pyx_NewRef(${module_cname});

    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;

    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;

#if CYTHON_COMPILING_IN_LIMITED_API
    moddict = module;
#else
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    // moddict is a borrowed reference
#endif

    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;

    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}
#endif
//#endif


/////////////// CodeObjectCache.proto ///////////////

#if !CYTHON_COMPILING_IN_LIMITED_API
typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;

struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};

static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};

static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);
#endif

/////////////// CodeObjectCache ///////////////
// Note that errors are simply ignored in the code below.
// This is just a cache, if a lookup or insertion fails - so what?

#if !CYTHON_COMPILING_IN_LIMITED_API
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}

static PyCodeObject *__pyx_find_code_object(int code_line) {
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    return __Pyx_NewRef(__pyx_code_cache.entries[pos].code_object);
}

static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}
#endif

/////////////// CodeObjectCache.cleanup ///////////////

  #if !CYTHON_COMPILING_IN_LIMITED_API
  if (__pyx_code_cache.entries) {
      __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
      int i, count = __pyx_code_cache.count;
      __pyx_code_cache.count = 0;
      __pyx_code_cache.max_count = 0;
      __pyx_code_cache.entries = NULL;
      for (i=0; i<count; i++) {
          Py_DECREF(entries[i].code_object);
      }
      PyMem_Free(entries);
  }
  #endif

/////////////// CheckBinaryVersion.proto ///////////////

static unsigned long __Pyx_get_runtime_version(void);
static int __Pyx_check_binary_version(unsigned long ct_version, unsigned long rt_version, int allow_newer);

/////////////// CheckBinaryVersion ///////////////

static unsigned long __Pyx_get_runtime_version(void) {
    // We will probably never need the alpha/beta status, so avoid the complexity to parse it.
#if __PYX_LIMITED_VERSION_HEX >= 0x030B00A4
    return Py_Version & ~0xFFUL;
#else
    const char* rt_version = Py_GetVersion();
    unsigned long version = 0;
    unsigned long factor = 0x01000000UL;
    unsigned int digit = 0;
    int i = 0;
    while (factor) {
        while ('0' <= rt_version[i] && rt_version[i] <= '9') {
            digit = digit * 10 + (unsigned int) (rt_version[i] - '0');
            ++i;
        }
        version += factor * digit;
        if (rt_version[i] != '.')
            break;
        digit = 0;
        factor >>= 8;
        ++i;
    }
    return version;
#endif
}

static int __Pyx_check_binary_version(unsigned long ct_version, unsigned long rt_version, int allow_newer) {
    // runtime version is: -1 => older, 0 => equal, 1 => newer
    const unsigned long MAJOR_MINOR = 0xFFFF0000UL;
    if ((rt_version & MAJOR_MINOR) == (ct_version & MAJOR_MINOR))
        return 0;
    if (likely(allow_newer && (rt_version & MAJOR_MINOR) > (ct_version & MAJOR_MINOR)))
        return 1;

    {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compile time Python version %d.%d "
                      "of module '%.100s' "
                      "%s "
                      "runtime version %d.%d",
                       (int) (ct_version >> 24), (int) ((ct_version >> 16) & 0xFF),
                       __Pyx_MODULE_NAME,
                       (allow_newer) ? "was newer than" : "does not match",
                       (int) (rt_version >> 24), (int) ((rt_version >> 16) & 0xFF)
       );
        // returns 0 or -1
        return PyErr_WarnEx(NULL, message, 1);
    }
}

/////////////// IsLittleEndian.proto ///////////////

static CYTHON_INLINE int __Pyx_Is_Little_Endian(void);

/////////////// IsLittleEndian ///////////////

static CYTHON_INLINE int __Pyx_Is_Little_Endian(void)
{
  union {
    uint32_t u32;
    uint8_t u8[4];
  } S;
  S.u32 = 0x01020304;
  return S.u8[0] == 4;
}

/////////////// Refnanny.proto ///////////////

#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif

#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, Py_ssize_t);
    void (*DECREF)(void*, PyObject*, Py_ssize_t);
    void (*GOTREF)(void*, PyObject*, Py_ssize_t);
    void (*GIVEREF)(void*, PyObject*, Py_ssize_t);
    void* (*SetupContext)(const char*, Py_ssize_t, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname); /*proto*/
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
  #define __Pyx_RefNannySetupContext(name, acquire_gil) \
          if (acquire_gil) { \
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure(); \
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), (__LINE__), (__FILE__)); \
              PyGILState_Release(__pyx_gilstate_save); \
          } else { \
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), (__LINE__), (__FILE__)); \
          }
  #define __Pyx_RefNannyFinishContextNogil() { \
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure(); \
              __Pyx_RefNannyFinishContext(); \
              PyGILState_Release(__pyx_gilstate_save); \
          }
  #define __Pyx_RefNannyFinishContextNogil() { \
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure(); \
              __Pyx_RefNannyFinishContext(); \
              PyGILState_Release(__pyx_gilstate_save); \
          }
  #define __Pyx_RefNannyFinishContext() \
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), (__LINE__))
  #define __Pyx_XINCREF(r)  do { if((r) == NULL); else {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) == NULL); else {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) == NULL); else {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) == NULL); else {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContextNogil()
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) PYOBJECT_NEWREF(r)
  #define __Pyx_DECREF(r) PYOBJECT_CLOSEREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) PYOBJECT_XNEWREF(r)
  #define __Pyx_XDECREF(r) PYOBJECT_XCLOSEREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif /* CYTHON_REFNANNY */

#if !CYTHON_USING_HPY
#define __Pyx_Py_XDECREF_SET(r, v) do {                         \
        PyObject *tmp = (PyObject *) r;                         \
        r = v; Py_XDECREF(tmp);                                 \
    } while (0)
#define __Pyx_XDECREF_SET(r, v) do {                            \
        PyObject *tmp = (PyObject *) r;                         \
        r = v; __Pyx_XDECREF(tmp);                              \
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {                             \
        PyObject *tmp = (PyObject *) r;                         \
        r = v; __Pyx_DECREF(tmp);                               \
    } while (0)
#else
#define __Pyx_Py_XDECREF_SET(r, v) do {                         \
        /*PYOBJECT_XCLOSEREF(r);*/                                  \
        r = v;                                                  \
    } while (0)
#define __Pyx_XDECREF_SET(r, v) do {                            \
        /*PYOBJECT_XCLOSEREF(r);*/                                  \
        r = v;                                                  \
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {                             \
        /*PYOBJECT_CLOSEREF(r);*/                                  \
        r = v;                                                  \
    } while (0)
#endif

#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)

/////////////// Refnanny ///////////////

#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif /* CYTHON_REFNANNY */


/////////////// ImportRefnannyAPI ///////////////

#if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif


/////////////// RegisterModuleCleanup.proto ///////////////
//@substitute: naming

static void ${cleanup_cname}(PyObject *self); /*proto*/

#if CYTHON_COMPILING_IN_PYPY
static int __Pyx_RegisterCleanup(void); /*proto*/
#else
#define __Pyx_RegisterCleanup() (0)
#endif

/////////////// RegisterModuleCleanup ///////////////
//@substitute: naming

#if CYTHON_COMPILING_IN_PYPY
static PyObject* ${cleanup_cname}_atexit(PyObject *module, PyObject *unused) {
    CYTHON_UNUSED_VAR(unused);
    ${cleanup_cname}(module);
    Py_INCREF(Py_None); return Py_None;
}

static int __Pyx_RegisterCleanup(void) {
    // Don't use Py_AtExit because that has a 32-call limit and is called
    // after python finalization.
    // Also, we try to prepend the cleanup function to "atexit._exithandlers"
    // in Py2 because CPython runs them last-to-first. Being run last allows
    // user exit code to run before us that may depend on the globals
    // and cached objects that we are about to clean up.

    static PyMethodDef cleanup_def = {
        "__cleanup", (PyCFunction)${cleanup_cname}_atexit, METH_NOARGS, 0};

    PyObject *cleanup_func = 0;
    PyObject *atexit = 0;
    PyObject *reg = 0;
    PyObject *args = 0;
    PyObject *res = 0;
    int ret = -1;

    cleanup_func = PyCFunction_New(&cleanup_def, 0);
    if (!cleanup_func)
        goto bad;

    atexit = PyImport_ImportModule("atexit");
    if (!atexit)
        goto bad;
    reg = PyObject_GetAttrString(atexit, "_exithandlers");
    if (reg && PyList_Check(reg)) {
        PyObject *a, *kw;
        a = PyTuple_New(0);
        kw = PyDict_New();
        if (!a || !kw) {
            Py_XDECREF(a);
            Py_XDECREF(kw);
            goto bad;
        }
        args = PyTuple_Pack(3, cleanup_func, a, kw);
        Py_DECREF(a);
        Py_DECREF(kw);
        if (!args)
            goto bad;
        ret = PyList_Insert(reg, 0, args);
    } else {
        if (!reg)
            PyErr_Clear();
        Py_XDECREF(reg);
        reg = PyObject_GetAttrString(atexit, "register");
        if (!reg)
            goto bad;
        args = PyTuple_Pack(1, cleanup_func);
        if (!args)
            goto bad;
        res = PyObject_CallObject(reg, args);
        if (!res)
            goto bad;
        ret = 0;
    }
bad:
    Py_XDECREF(cleanup_func);
    Py_XDECREF(atexit);
    Py_XDECREF(reg);
    Py_XDECREF(args);
    Py_XDECREF(res);
    return ret;
}
#endif

/////////////// FastGil.init ///////////////
__Pyx_FastGilFuncInit();

/////////////// NoFastGil.proto ///////////////
//@proto_block: utility_code_proto_before_types

#define __Pyx_PyGILState_Ensure PyGILState_Ensure
#define __Pyx_PyGILState_Release PyGILState_Release
#define __Pyx_FastGIL_Remember()
#define __Pyx_FastGIL_Forget()
#define __Pyx_FastGilFuncInit()

/////////////// FastGil.proto ///////////////
//@proto_block: utility_code_proto_before_types

#if CYTHON_FAST_GIL

struct __Pyx_FastGilVtab {
  PyGILState_STATE (*Fast_PyGILState_Ensure)(void);
  void (*Fast_PyGILState_Release)(PyGILState_STATE oldstate);
  void (*FastGIL_Remember)(void);
  void (*FastGIL_Forget)(void);
};

static void __Pyx_FastGIL_Noop(void) {}
static struct __Pyx_FastGilVtab __Pyx_FastGilFuncs = {
  PyGILState_Ensure,
  PyGILState_Release,
  __Pyx_FastGIL_Noop,
  __Pyx_FastGIL_Noop
};

static void __Pyx_FastGilFuncInit(void);

#define __Pyx_PyGILState_Ensure __Pyx_FastGilFuncs.Fast_PyGILState_Ensure
#define __Pyx_PyGILState_Release __Pyx_FastGilFuncs.Fast_PyGILState_Release
#define __Pyx_FastGIL_Remember __Pyx_FastGilFuncs.FastGIL_Remember
#define __Pyx_FastGIL_Forget __Pyx_FastGilFuncs.FastGIL_Forget

#ifndef CYTHON_THREAD_LOCAL
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #define CYTHON_THREAD_LOCAL thread_local
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112
    #define CYTHON_THREAD_LOCAL _Thread_local
  #elif defined(__GNUC__)
    #define CYTHON_THREAD_LOCAL __thread
  #elif defined(_MSC_VER)
    #define CYTHON_THREAD_LOCAL __declspec(thread)
  #endif
#endif

#else
#define __Pyx_PyGILState_Ensure PyGILState_Ensure
#define __Pyx_PyGILState_Release PyGILState_Release
#define __Pyx_FastGIL_Remember()
#define __Pyx_FastGIL_Forget()
#define __Pyx_FastGilFuncInit()
#endif

/////////////// FastGil ///////////////
// The implementations of PyGILState_Ensure/Release calls PyThread_get_key_value
// several times which is turns out to be quite slow (slower in fact than
// acquiring the GIL itself).  Simply storing it in a thread local for the
// common case is much faster.
// To make optimal use of this thread local, we attempt to share it between
// modules.

#if CYTHON_FAST_GIL

#define __Pyx_FastGIL_ABI_module __PYX_ABI_MODULE_NAME
#define __Pyx_FastGIL_PyCapsuleName "FastGilFuncs"
#define __Pyx_FastGIL_PyCapsule \
    __Pyx_FastGIL_ABI_module "." __Pyx_FastGIL_PyCapsuleName

#ifdef CYTHON_THREAD_LOCAL

#include "pythread.h"
#include "pystate.h"

static CYTHON_THREAD_LOCAL PyThreadState *__Pyx_FastGil_tcur = NULL;
static CYTHON_THREAD_LOCAL int __Pyx_FastGil_tcur_depth = 0;
static int __Pyx_FastGil_autoTLSkey = -1;

static CYTHON_INLINE void __Pyx_FastGIL_Remember0(void) {
  ++__Pyx_FastGil_tcur_depth;
}

static CYTHON_INLINE void __Pyx_FastGIL_Forget0(void) {
  if (--__Pyx_FastGil_tcur_depth == 0) {
    __Pyx_FastGil_tcur = NULL;
  }
}

static CYTHON_INLINE PyThreadState *__Pyx_FastGil_get_tcur(void) {
  PyThreadState *tcur = __Pyx_FastGil_tcur;
  if (tcur == NULL) {
    tcur = __Pyx_FastGil_tcur = (PyThreadState*)PyThread_get_key_value(__Pyx_FastGil_autoTLSkey);
  }
  return tcur;
}

static PyGILState_STATE __Pyx_FastGil_PyGILState_Ensure(void) {
  int current;
  PyThreadState *tcur;
  __Pyx_FastGIL_Remember0();
  tcur = __Pyx_FastGil_get_tcur();
  if (tcur == NULL) {
    // Uninitialized, need to initialize now.
    return PyGILState_Ensure();
  }
  current = tcur == __Pyx_PyThreadState_Current;
  if (current == 0) {
    PyEval_RestoreThread(tcur);
  }
  ++tcur->gilstate_counter;
  return current ? PyGILState_LOCKED : PyGILState_UNLOCKED;
}

static void __Pyx_FastGil_PyGILState_Release(PyGILState_STATE oldstate) {
  PyThreadState *tcur = __Pyx_FastGil_get_tcur();
  __Pyx_FastGIL_Forget0();
  if (tcur->gilstate_counter == 1) {
    // This is the last lock, do all the cleanup as well.
    PyGILState_Release(oldstate);
  } else {
    --tcur->gilstate_counter;
    if (oldstate == PyGILState_UNLOCKED) {
      PyEval_SaveThread();
    }
  }
}

static void __Pyx_FastGilFuncInit0(void) {
  /* Try to detect autoTLSkey. */
  int key;
  void* this_thread_state = (void*) PyGILState_GetThisThreadState();
  for (key = 0; key < 100; key++) {
    if (PyThread_get_key_value(key) == this_thread_state) {
      __Pyx_FastGil_autoTLSkey = key;
      break;
    }
  }
  if (__Pyx_FastGil_autoTLSkey != -1) {
    PyObject* capsule = NULL;
    PyObject* abi_module = NULL;
    __Pyx_PyGILState_Ensure = __Pyx_FastGil_PyGILState_Ensure;
    __Pyx_PyGILState_Release = __Pyx_FastGil_PyGILState_Release;
    __Pyx_FastGIL_Remember = __Pyx_FastGIL_Remember0;
    __Pyx_FastGIL_Forget = __Pyx_FastGIL_Forget0;
    capsule = PyCapsule_New(&__Pyx_FastGilFuncs, __Pyx_FastGIL_PyCapsule, NULL);
    if (capsule) {
        abi_module = __Pyx_PyImport_AddModuleRef(__Pyx_FastGIL_ABI_module);
        if (abi_module) {
          PyObject_SetAttrString(abi_module, __Pyx_FastGIL_PyCapsuleName, capsule);
          Py_DECREF(abi_module);
        }
    }
    Py_XDECREF(capsule);
  }
}

#else

static void __Pyx_FastGilFuncInit0(void) {
}

#endif

static void __Pyx_FastGilFuncInit(void) {
  struct __Pyx_FastGilVtab* shared = (struct __Pyx_FastGilVtab*)PyCapsule_Import(__Pyx_FastGIL_PyCapsule, 1);
  if (shared) {
    __Pyx_FastGilFuncs = *shared;
  } else {
   PyErr_Clear();
    __Pyx_FastGilFuncInit0();
  }
}

#endif

///////////////////// UtilityCodePragmas /////////////////////////

#ifdef _MSC_VER
#pragma warning( push )
/* Warning 4127: conditional expression is constant
 * Cython uses constant conditional expressions to allow in inline functions to be optimized at
 * compile-time, so this warning is not useful
 */
#pragma warning( disable : 4127 )
#endif

///////////////////// UtilityCodePragmasEnd //////////////////////

#ifdef _MSC_VER
#pragma warning( pop )  /* undo whatever Cython has done to warnings */
#endif
