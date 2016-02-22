/////////////////////////////////////////////////////////////////////////////////////////
//
//  NEXT LIMIT
//
//  File:        basic.h
//  Description: Basic Types, Macros, Functions...
//
/////////////////////////////////////////////////////////////////////////////////////////


#ifndef NL_BASIC_H_
#define NL_BASIC_H_

#include "nl_basic_config.h"

#include <math.h>
#include <float.h>
#include <limits.h>
#include <string>
#include <map>

#include <global/nl_basic_global.h>

#if defined ( _WINDOWS )
#include <io.h>
#endif

#if defined( _MACOSX ) || defined( _IOS )
#include <stdlib.h>
#include <unistd.h>
#if defined(USE_COCOA)
#else
//#include <Carbon/Carbon.h>
#endif
#endif

#ifdef _LINUX
#include <stdlib.h>
#include <math.h>
#endif

#if !defined(__cplusplus)
#error C++ language is required. Use 'cpp' files instead of 'c' files.
#endif


//-----------------------------------------------------------------------------------
//
// 64 bits stuff
//
//-----------------------------------------------------------------------------------

#if defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined( _M_X64 ) || defined (__LP64__)
#if !defined(NL_OS_64)
# define NL_OS_64
#endif
#endif

//-----------------------------------------------------------------------------------
//
// C++11 support
//
//-----------------------------------------------------------------------------------

#if ( _MSC_VER >= 1700 ) || defined( _MACOSX ) && ( __cplusplus > 199711L )
# if !defined( NL_CPP11_SUPPORT )
#  define NL_CPP11_SUPPORT
// TODO: Linux implementation is missing!
# endif
#endif


//-----------------------------------------------------------------------------------
//
// pragma warnings _WINDOWS
//
//-----------------------------------------------------------------------------------
#ifdef _WINDOWS
#pragma warning (disable:4201)
#pragma warning (disable:4251) // ... needs to have dll-interface to be used by clients of class ...
#pragma warning (disable:4275) // ... non dll-interface class 'x' used as base for dll-interface class 'y'
#pragma warning (disable:4996) // ... "function x" was declared deprecated
//#pragma warning (disable:4221) // ... "this object file does not define any previously undefined public symbols - We wanted to disable LNK4221 warning
#endif

//-----------------------------------------------------------------------------------
//
// includes to avoid warning messages for header files
//
// NL_BEGIN_DISABLE_WARNINGS_NO_CHECK doesn't check if the pair begin/end is correct.
// Useful for nested includes.
//
//-----------------------------------------------------------------------------------

#define NL_BEGIN_DISABLE_WARNINGS           <core/nl_begin_disable_warnings.h>
#define NL_BEGIN_DISABLE_WARNINGS_NO_CHECK  <core/nl_begin_disable_warnings_no_check.h>
#define NL_END_DISABLE_WARNINGS             <core/nl_end_disable_warnings.h>


  // *example*
  // #include NL_BEGIN_DISABLE_WARNINGS
  // ....includes...
  // #include NL_END_DISABLE_WARNINGS

//-----------------------------------------------------------------------------------
//
// pragma for writing the name of the header file that is being compiled
//
//-----------------------------------------------------------------------------------

#ifdef NL_COMPILING_VERBOSE
# ifdef _WINDOWS
#  define NL_VERBOSE_HEADER_FILE message( __FILE__ )
# endif
#else
# define NL_VERBOSE_HEADER_FILE
#endif


//-----------------------------------------------------------------------------------
//
// local pragma warnings _WINDOWS
//
//-----------------------------------------------------------------------------------
#ifdef _WINDOWS
# define NL_WARNING_PUSH  warning(push)
# define NL_WARNING_POP   warning(pop)
# define NL_WARNING_DISABLE_Constant_In_Conditional warning (disable:4127)
# define NL_WARNING_DISABLE_Unreferenced_Formal_Parameter warning (disable:4100)
# define NL_WARNING_DISABLE_Signed_Unsigned_Mismatch warning (disable:4018)
# define NL_WARNING_DISABLE_Local_Variable_Not_Referenced warning (disable:4189)
# define NL_WARNING_DISABLE_Performance warning (disable:4800)
# define NL_WARNING_DISABLE_Size_t_Casting warning (disable:4267)
# define NL_WARNING_DISABLE_Truncation_Constant_Value warning ( disable:4309)
# define NL_WARNING_DISABLE_Unreachable_Code warning ( disable:4702)
# define NL_WARNING_DISABLE_Definition_for_explicit_instantiation warning ( disable:4661 )
# define NL_WARNING_DISABLE_Minus_Applied_to_Unsigned warning( disable : 4146 )

# define NL_PRAGMA(x) __pragma(x)

# define NL_PRAGMA_WARNING_PUSH NL_PRAGMA( warning(push) )
# define NL_PRAGMA_WARNING_POP  NL_PRAGMA( warning(pop) )
# define NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional NL_PRAGMA( warning (disable:4127) )
# define NL_PRAGMA_WARNING_DISABLE_Unreferenced_Formal_Parameter NL_PRAGMA( warning (disable:4100) )
# define NL_PRAGMA_WARNING_DISABLE_Signed_Unsigned_Mismatch NL_PRAGMA( warning (disable:4018) )
# define NL_PRAGMA_WARNING_DISABLE_Local_Variable_Not_Referenced NL_PRAGMA( warning (disable:4189) )
# define NL_PRAGMA_WARNING_DISABLE_Performance NL_PRAGMA( warning (disable:4800) )
# define NL_PRAGMA_WARNING_DISABLE_Size_t_Casting NL_PRAGMA( warning (disable:4267) )
# define NL_PRAGMA_WARNING_DISABLE_Truncation_Constant_Value NL_PRAGMA( warning ( disable:4309) )
# define NL_PRAGMA_WARNING_DISABLE_Unreachable_Code NL_PRAGMA( warning ( disable:4702) )
# define NL_PRAGMA_WARNING_DISABLE_Definition_for_explicit_instantiation NL_PRAGMA( warning ( disable:4661 ) )
# define NL_PRAGMA_WARNING_DISABLE_Minus_Applied_to_Unsigned NL_PRAGMA( warning ( disable:4146 ) )

  // *example*
  // NL_PRAGMA_WARNING_PUSH
  // #pragma NL_WARNING_DISEABLE_Constant_In_Conditional
  // ... code ...
  // NL_PRAGMA_WARNING_POP

#elif defined ( __llvm__ )

# define NL_PRAGMA(x) _Pragma (#x)

# define NL_WARNING_PUSH clang diagnostic push
# define NL_WARNING_POP clang diagnostic pop
# define NL_WARNING_DISABLE_Constant_In_Conditional
# define NL_WARNING_DISABLE_Unreferenced_Formal_Parameter
# define NL_WARNING_DISABLE_Signed_Unsigned_Mismatch
# define NL_WARNING_DISABLE_Local_Variable_Not_Referenced
# define NL_WARNING_DISABLE_Performance
# define NL_WARNING_DISABLE_Size_t_Casting
# define NL_WARNING_DISABLE_Truncation_Constant_Value
# define NL_WARNING_DISABLE_Minus_Applied_to_Unsigned

# define NL_PRAGMA_WARNING_PUSH NL_PRAGMA( clang diagnostic push )
# define NL_PRAGMA_WARNING_POP  NL_PRAGMA( clang diagnostic pop )
# define NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional NL_PRAGMA( clang diagnostic ignored "-Wtautological-compare" )
# define NL_PRAGMA_WARNING_DISABLE_Unreferenced_Formal_Parameter NL_PRAGMA( clang diagnostic ignored "-Wunused-parameter" )
# define NL_PRAGMA_WARNING_DISABLE_Signed_Unsigned_Mismatch NL_PRAGMA(  )
# define NL_PRAGMA_WARNING_DISABLE_Local_Variable_Not_Referenced NL_PRAGMA(  )
# define NL_PRAGMA_WARNING_DISABLE_Performance NL_PRAGMA(  )
# define NL_PRAGMA_WARNING_DISABLE_Size_t_Casting NL_PRAGMA(  )
# define NL_PRAGMA_WARNING_DISABLE_Truncation_Constant_Value NL_PRAGMA(  )
# define NL_PRAGMA_WARNING_DISABLE_Unreachable_Code NL_PRAGMA(  )
# define NL_PRAGMA_WARNING_DISABLE_Definition_for_explicit_instantiation NL_PRAGMA( )
# define NL_PRAGMA_WARNING_DISABLE_Minus_Applied_to_Unsigned NL_PRAGMA( )

#else

# define NL_PRAGMA(x) _Pragma (#x)

# define NL_PRAGMA_WARNING_PUSH
# define NL_PRAGMA_WARNING_POP
# define NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional
# define NL_PRAGMA_WARNING_DISABLE_Unreferenced_Formal_Parameter
# define NL_PRAGMA_WARNING_DISABLE_Signed_Unsigned_Mismatch
# define NL_PRAGMA_WARNING_DISABLE_Local_Variable_Not_Referenced
# define NL_PRAGMA_WARNING_DISABLE_Performance
# define NL_PRAGMA_WARNING_DISABLE_Size_t_Casting
# define NL_PRAGMA_WARNING_DISABLE_Truncation_Constant_Value
# define NL_PRAGMA_WARNING_DISABLE_Unreachable_Code
# define NL_PRAGMA_WARNING_DISABLE_Definition_for_explicit_instantiation
# define NL_WARNING_DISABLE_Minus_Applied_to_Unsigned

# define NL_WARNING_PUSH
# define NL_WARNING_POP
# define NL_WARNING_DISABLE_Constant_In_Conditional warning
# define NL_WARNING_DISABLE_Unreferenced_Formal_Parameter warning
# define NL_WARNING_DISABLE_Signed_Unsigned_Mismatch warning
# define NL_WARNING_DISABLE_Local_Variable_Not_Referenced
# define NL_WARNING_DISABLE_Performance
# define NL_WARNING_DISABLE_Size_t_Casting
# define NL_WARNING_DISABLE_Truncation_Constant_Value
# define NL_WARNING_DISABLE_Unary_Minus_Applied_to_Unsigned_warning
# define NL_PRAGMA_WARNING_DISABLE_Minus_Applied_to_Unsigned
#endif

/// trick to avoid warning variable not referenced
#define NL_VARIABLE_MAYBE_NOT_REFERENCED(a) &a;
#define NL_VARIABLE_MAYBE_NOT_REFERENCED2(a,b) &a; &b;
#define NL_VARIABLE_MAYBE_NOT_REFERENCED3(a,b,c) &a; &b; &c;
#define NL_VARIABLE_MAYBE_NOT_REFERENCED4(a,b,c,d) &a; &b; &c; &d;
#define NL_VARIABLE_MAYBE_NOT_REFERENCED5(a,b,c,d,e) &a; &b; &c; &d; &e;
#define NL_VARIABLE_MAYBE_NOT_REFERENCED6(a,b,c,d,e,f) &a; &b; &c; &d; &e; &f;

/// For functions not implemented yet.
#define NL_NOT_IMPLEMENTED_YET NL_BREAKPOINT

/// For functions not implemented yet.
#define NL_NOT_IMPLEMENTED_YET_IF( a ) NL_ASSERT( !a );

/// For deprecated functions.
#define NL_DEPRECATED NL_BREAKPOINT

/// For functions implemented but not tested yet.
#define NL_IMPLEMENTED_BUT_NOT_TESTED_YET NL_BREAKPOINT

/// For parts of the code that never should be reached.
#define NL_CODE_SHOULD_NOT_BE_REACHABLE NL_BREAKPOINT

/// ET
#define ET_THIS_DOES_NOT_COMPILE_ON_LINUX NL_BREAKPOINT

// ALEX
#if defined( DEVELOPER_IS_ALEX ) && ( defined ( _DEBUG ) || defined ( _DEBUG_RELEASE ) )
#define NL_NOT_IMPLEMENTED_YET_MSG_ALEX \
{ NL_CHAR not_implemented_yet; \
  NL_TRACE_ALEX( "*** NOT IMPLEMENTED YET %s [%s:%d]", __FUNCTION__, __FILE__, __LINE__ ); }
#else
#define NL_NOT_IMPLEMENTED_YET_MSG_ALEX
#endif


//-----------------------------------------------------------------------------------
//
// ISNAN, FINITE
//
//-----------------------------------------------------------------------------------
#ifdef _WINDOWS
# define ISNAN _isnan
# define FINITE _finite
#else
# ifdef _IOS
#  define ISNAN isnan
#  define FINITE isfinite
# elif defined( _MACOSX )
#  define ISNAN NL_isnan_OSX
#  define FINITE finite
#  if ( __MAC_OS_X_VERSION_MAX_ALLOWED > 1060 )
#    define NL_isnan_OSX(x)	\
        (	sizeof (x) == sizeof(float )	?	__inline_isnanf((float)(x))	 \
        :	sizeof (x) == sizeof(double)	?	__inline_isnand((double)(x)) \
        :	__inline_isnanl ((long double)(x)))
#  else
#  define NL_isnan_OSX(x)	\
          (	sizeof (x) == sizeof(float )	?	__inline_isnanf((float)(x))	 \
          :	sizeof (x) == sizeof(double)	?	__inline_isnand((double)(x)) \
          :	__inline_isnan ((long double)(x)))
#    endif
# else
#  define ISNAN isnan
#  define FINITE finite
# endif
#endif

//-----------------------------------------------------------------------------------
//
// FORCE INLINE
//
//-----------------------------------------------------------------------------------
#if   defined(__INTEL_COMPILER)
# define NL_FORCE_INLINE inline
#elif defined(_MSC_VER)
# define NL_FORCE_INLINE __forceinline
#elif defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
# define NL_FORCE_INLINE inline __attribute__ ((always_inline))
#else
# define NL_FORCE_INLINE inline
#endif

//-----------------------------------------------------------------------------------
//
// RESTRICT
//
//-----------------------------------------------------------------------------------
#if   defined(__INTEL_COMPILER)
# define NL_RESTRICT_HINT restrict
#elif defined(_MSC_VER)
# define NL_RESTRICT_HINT __restrict
#elif defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
# define NL_RESTRICT_HINT __restrict__
#else
# define NL_RESTRICT_HINT
#endif

//-----------------------------------------------------------------------------------
//
// defines MAX_PATH, NULL, FALSE, TRUE
//
//-----------------------------------------------------------------------------------
#ifndef MAX_PATH
#define MAX_PATH	260
#endif

#ifndef NULL
#define NULL	0
#endif

#ifndef FALSE
#define FALSE	0
#endif

#ifndef TRUE
#define TRUE	1
#endif

#define NL_true  true
#define NL_false false

#define return_true  return NL_true
#define return_false return NL_false
#define return_null  return NULL
#define return_if_null( p ) if ( NULL == p ) return;
#define return_if_empty( a ) if ( a.empty() ) return;


//-----------------------------------------------------------------------------------
//
// PLATFORM and NL_PLATFORM_BIG_ENDIAN
//
//-----------------------------------------------------------------------------------

// PPC
#if   defined(__ppc__)     \
   || defined(__PPC__)     \
   || defined(__powerpc__) \
   || defined(__powerpc)   \
   || defined(__POWERPC__) \
   || defined(_M_PPC)      \
   || defined(__PPC)
# define NL_PLATFORM_PPC
# define NL_PLATFORM_BIG_ENDIAN 1
#endif

// PPC64
#if   defined(__ppc64__) || defined(__PPC64__)
# define NL_PLATFORM_PPC64
# define NL_PLATFORM_BIG_ENDIAN 1
#endif

// ARM
#if defined(arm) || defined(__arm__)
# define NL_PLATFORM_ARM
# if defined(__ARMEB__)
#  define NL_PLATFORM_BIG_ENDIAN 1
# elif defined(__ARMEL__)
#  define NL_PLATFORM_LITTLE_ENDIAN 1
# elif !defined(__ARM_EABI__)
#  error Middle endian architectures are not supported.
# endif
#endif

// X86
#if   defined(__i386__) \
   || defined(i386)     \
   || defined(_M_IX86)  \
   || defined(_X86_)    \
   || defined(__THW_INTEL)
# define NL_PLATFORM_LITTLE_ENDIAN 1
# define NL_PLATFORM_X86
#endif

// X86_64
#if   defined(__x86_64__) \
   || defined(__ia64__) \
   || defined(_M_X64)
# define NL_PLATFORM_LITTLE_ENDIAN 1
#define NL_PLATFORM_X86_64
#endif

// SPARC64
#if defined(__sparc64__)
#define NL_PLATFORM_SPARC64
#define NL_PLATFORM_BIG_ENDIAN 1
#endif

//-----------------------------------------------------------------------------------
//
// elseif CASE, DEFAULT, COND_TRUE_FALSE
//
//-----------------------------------------------------------------------------------
#define elseif else if
#define CASE break; case
#define DEFAULT break; default
#define DEFAULT_BREAKPOINT break; default: NL_BREAKPOINT;
#define ELSE_BREAKPOINT else{ NL_BREAKPOINT };
#define COND_TRUE_FALSE( cond, statTrue, statFalse ) cond ? statTrue : statFalse;
#define IF_THEN( cond, statement ) if ( cond ) statement;
#define ELSE_IF_THEN( cond, statement ) else if ( cond ) statement;
#define IF_THEN_RETURN( cond ) if ( cond ) return;
#define IF_THEN_RETURN_TRUE( cond ) if ( cond ) return_true;
#define IF_THEN_RETURN_FALSE( cond ) if ( cond ) return_false;
#define IF_THEN_RETURN_NULL( cond ) if ( cond ) return_null;
#define IF_NOT_THEN_RETURN( cond ) if ( !(cond) ) return;
#define IF_NOT_THEN_RETURN_TRUE( cond ) if ( !(cond) ) return_true;
#define IF_NOT_THEN_RETURN_FALSE( cond ) if ( !(cond) ) return_false;
#define IF_NOT_THEN_RETURN_NULL( cond ) if ( !(cond) ) return_null;
#define IF_NULL_THEN( ptr, statement ) if ( ptr == NULL ) statement;
#define IF_NULL_THEN_RETURN( ptr ) if ( ptr == NULL ) return;
#define IF_NULL_THEN_RETURN_TRUE( ptr ) if ( ptr == NULL ) return_true;
#define IF_NULL_THEN_RETURN_FALSE( ptr ) if ( ptr == NULL ) return_false;
#define IF_NULL_THEN_RETURN_NULL( ptr ) if ( ptr == NULL ) return_null;
#define IF_NOT_NULL_THEN( ptr, statement ) if ( ptr != NULL ) statement;
#define IF_NOT_NULL_THEN_RETURN( ptr ) if ( ptr != NULL ) return;
#define IF_NOT_NULL_THEN_RETURN_TRUE( ptr ) if ( ptr != NULL ) return_true;
#define IF_NOT_NULL_THEN_RETURN_FALSE( ptr ) if ( ptr != NULL ) return_false;
#define IF_NOT_NULL_THEN_RETURN_NULL( ptr ) if ( ptr != NULL ) return_null;
#define IF_THEN_CONTINUE( cond ) if ( cond ) continue;
#define IF_NOT_THEN_CONTINUE( cond ) if ( !(cond) ) continue;
#define IF_NULL_THEN_CONTINUE( ptr ) if ( ptr == NULL ) continue;
#define IF_NOT_NULL_THEN_CONTINUE( ptr ) if ( ptr != NULL ) continue;
#define IF_THEN_BREAK( cond ) if ( cond ) break;
#define IF_NOT_THEN_BREAK( cond ) if ( !(cond) ) break;
#define IF_NULL_THEN_BREAK( ptr ) if ( ptr == NULL ) break;
#define IF_NOT_NULL_THEN_BREAK( ptr ) if ( ptr != NULL ) break;
#define IF_NOT_THEN( cond, statement ) if ( !(cond) ) statement;
#define IF_NOT_THEN_THROW( cond, exception ) if ( !(cond) ) throw ( exception );
#define IF_THEN_THROW( cond, exception ) if ( cond ) throw ( exception );
#define IF_THEN_ELSE( cond, statTrue, statFalse ) \
          if ( cond ) { statTrue; } else { statFalse; }

//-----------------------------------------------------------------------------------
// List of Basic Types
//
//  NL_VOID;
//  NL_BOOL;  NL_INTBOOL;
//
//  NL_CHAR;  NL_WCHAR;
//  NL_BYTE;  NL_WORD; NL_DWORD; NL_QWORD;
//
//  NL_INT8;  NL_UINT8;
//  NL_INT16; NL_UINT16;
//  NL_INT32; NL_UINT32;
//  NL_INT64; NL_UINT64;
//
//  NL_INT;   NL_UINT;
//  NL_LONG;  NL_ULONG;
//
//  NL_FLOAT; NL_DOUBLE;
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
//
// LINUX TYPES
//
//-----------------------------------------------------------------------------------
#if defined (_LINUX)

  typedef void            NL_VOID;

  typedef bool            NL_BOOL;    // true / false
  typedef int             NL_INTBOOL;	// TRUE / FALSE (0-1)

  typedef char				    NL_CHAR;
  typedef unsigned char   NL_UCHAR;
  typedef unsigned short	NL_WCHAR;

  typedef unsigned char		NL_BYTE;
  typedef unsigned short	NL_WORD;
  typedef unsigned int		NL_DWORD;
  typedef long long				NL_QWORD;

  typedef char            NL_INT8;
  typedef unsigned char   NL_UINT8;

  typedef short int       NL_INT16;
  typedef unsigned short  NL_UINT16;

  typedef int             NL_INT32;
  typedef unsigned int    NL_UINT32;

  typedef int             NL_INT;
  typedef unsigned int    NL_UINT;

  typedef long            NL_LONG;
  typedef unsigned long   NL_ULONG;

  typedef float           NL_FLOAT;
  typedef double          NL_DOUBLE;

  typedef long long           NL_INT64;
  typedef unsigned long long	NL_UINT64;

  typedef long NL_POINTER;

#endif

//-----------------------------------------------------------------------------------
//
// WINDOWS TYPES
//
//-----------------------------------------------------------------------------------
#if defined (_WINDOWS)

	typedef void			      	NL_VOID;

	typedef bool              NL_BOOL;	  // true / false
	typedef int               NL_INTBOOL;	// TRUE / FALSE (0-1)

	typedef char              NL_CHAR;
  typedef unsigned char     NL_UCHAR;
	typedef unsigned short		NL_WCHAR;

	typedef unsigned char     NL_BYTE;
	typedef unsigned short    NL_WORD;
	typedef unsigned __int32  NL_DWORD;
	typedef unsigned __int64  NL_QWORD;

	typedef __int8            NL_INT8;
	typedef unsigned __int8   NL_UINT8;

  typedef __int16           NL_INT16;
  typedef unsigned __int16  NL_UINT16;

  typedef __int32           NL_INT32;
  typedef unsigned __int32  NL_UINT32;

	typedef __int64           NL_INT64;
	typedef unsigned __int64	NL_UINT64;

  typedef int               NL_INT;
  typedef unsigned int      NL_UINT;

  typedef long              NL_LONG;
	typedef unsigned long     NL_ULONG;

	typedef float             NL_FLOAT;
	typedef double            NL_DOUBLE;

# if defined ( NL_OS_64 )
  typedef long long NL_POINTER;
# else
  typedef long NL_POINTER;
# endif

#endif

//-----------------------------------------------------------------------------------
//
// MAC TYPES
//
//-----------------------------------------------------------------------------------
#if defined (__MACOS__) || defined (_MAC) || defined( _MACOSX ) || defined( _IOS )
  typedef void		      NL_VOID;

  typedef bool		      NL_BOOL;    // true / false
  typedef int		      NL_INTBOOL;	// TRUE / FALSE (0-1)

  typedef char                NL_CHAR;	// single character
  typedef unsigned char       NL_UCHAR;
  typedef unsigned short      NL_WCHAR;	// wide character

  typedef unsigned char	      NL_BYTE;
  typedef unsigned short      NL_WORD;
  typedef unsigned int        NL_DWORD;
  typedef unsigned long long  NL_QWORD;

  typedef char                NL_INT8;
  typedef unsigned char       NL_UINT8;

  typedef short int           NL_INT16;
  typedef unsigned short      NL_UINT16;

  typedef int                 NL_INT32;
  typedef unsigned int        NL_UINT32;

  typedef long long           NL_INT64;
  typedef unsigned long long  NL_UINT64;

  typedef int                 NL_INT;
  typedef unsigned int        NL_UINT;

  typedef long                NL_LONG;
  typedef unsigned long       NL_ULONG;

  typedef float		      NL_FLOAT;
  typedef double	      NL_DOUBLE;

  typedef long NL_POINTER;

#endif



//-----------------------------------------------------------------------------------
//
// NL_isBuiltInType
//
//-----------------------------------------------------------------------------------
template< class T >
NL_BOOL NL_isBuiltInType()
{
  return( NL_false );
}

template<> inline NL_BOOL NL_isBuiltInType < NL_INT8   >() { return( NL_true ); }
template<> inline NL_BOOL NL_isBuiltInType < NL_UINT8  >() { return( NL_true ); }

template<> inline NL_BOOL NL_isBuiltInType < NL_INT16  >() { return( NL_true ); }
template<> inline NL_BOOL NL_isBuiltInType < NL_UINT16 >() { return( NL_true ); }

template<> inline NL_BOOL NL_isBuiltInType < NL_INT32  >() { return( NL_true ); }
template<> inline NL_BOOL NL_isBuiltInType < NL_UINT32 >() { return( NL_true ); }

template<> inline NL_BOOL NL_isBuiltInType < NL_INT64  >() { return( NL_true ); }
template<> inline NL_BOOL NL_isBuiltInType < NL_UINT64 >() { return( NL_true ); }

template<> inline NL_BOOL NL_isBuiltInType < NL_FLOAT  >() { return( NL_true ); }
template<> inline NL_BOOL NL_isBuiltInType < NL_DOUBLE >() { return( NL_true ); }

#if defined( _MACOSX ) || defined( _IOS )
# if defined ( NL_OS_64 )
  template<> inline NL_BOOL NL_isBuiltInType < NL_ULONG >() { return( NL_true ); }
# else
  template<> inline NL_BOOL NL_isBuiltInType < NL_ULONG >() { return( NL_true ); }
# endif
#endif


//-----------------------------------------------------------------------------------
//
// NL_OutputDebugString_Ansi
//
//-----------------------------------------------------------------------------------
namespace nextlimit
{
  #if defined (_WINDOWS)

    NL_BASIC_EXPORTS_DLL void NL_OutputDebugString_Ansi( const char* charInput );

  #else

    inline void NL_OutputDebugString_Ansi( const char* ){};

  #endif
}

//-----------------------------------------------------------------------------------
//
// NL_TRACE_ENTER_FUNCTION
// NL_TRACE_LEAVE_FUNCTION
//
//-----------------------------------------------------------------------------------

#if defined ( _DEBUG ) || defined ( _DEBUG_RELEASE )

  #if defined ( NL_TRACING_ENTER_LEAVE_FUNCTION )

    #define NL_TRACE_ENTER_FUNCTION \
            NL_TRACE( "Entering \"%s\" function", __FUNCTION__ );

    #define NL_TRACE_LEAVE_FUNCTION \
            NL_TRACE( "Leaving \"%s\" function", __FUNCTION__ );
  #else

    #define NL_TRACE_ENTER_FUNCTION
    #define NL_TRACE_LEAVE_FUNCTION

  #endif

#else

  #define NL_TRACE_ENTER_FUNCTION
  #define NL_TRACE_LEAVE_FUNCTION

#endif

//-----------------------------------------------------------------------------------
//
// ASSERT CODE TO DELETE, WORKING, CODE TO NL_CODE_TO_DISABLE
//
//-----------------------------------------------------------------------------------
namespace nextlimit
{
#if defined (_DEBUG) || defined ( _DEBUG_RELEASE )

  NL_BASIC_EXPORTS_DLL NL_BOOL NL_skipCodeToDeleteBreakpoint();
  #define NL_CODE_TO_DELETE NL_ASSERT( NL_skipCodeToDeleteBreakpoint() );
  #define NL_CODE_TO_DELETE_BEGIN NL_CODE_TO_DELETE
  #define NL_CODE_TO_DELETE_END   NL_CODE_TO_DELETE

  NL_BASIC_EXPORTS_DLL NL_BOOL NL_skipCodeToDeleteBreakpoint();
  #define NL_WORKING NL_ASSERT( NL_skipCodeToDeleteBreakpoint() );
  #define NL_WORKING_BEGIN NL_WORKING
  #define NL_WORKING_END   NL_WORKING

  NL_BASIC_EXPORTS_DLL NL_BOOL NL_skipCodeToDisableBreakpoint();
  #define NL_CODE_TO_DISABLE NL_ASSERT( NL_skipCodeToDisableBreakpoint() );
  #define NL_CODE_TO_DISABLE_BEGIN NL_CODE_TO_DISABLE
  #define NL_CODE_TO_DISABLE_END   NL_CODE_TO_DISABLE

  #define NL_CODE_MODIFIED_BECAUSE_OF_EXCEPTIONAL_REASONS        NL_ASSERT( NL_false );
  #define NL_CODE_MODIFIED_BECAUSE_OF_EXCEPTIONAL_REASONS_BEGIN  NL_ASSERT( NL_false );
  #define NL_CODE_MODIFIED_BECAUSE_OF_EXCEPTIONAL_REASONS_END    NL_ASSERT( NL_false );

#else

  #define NL_CODE_TO_DELETE
  #define NL_CODE_TO_DELETE_BEGIN
  #define NL_CODE_TO_DELETE_END

  #define NL_WORKING
  #define NL_WORKING_BEGIN
  #define NL_WORKING_END

  #define NL_CODE_TO_DISABLE
  #define NL_CODE_TO_DISABLE_BEGIN
  #define NL_CODE_TO_DISABLE_END

  #define NL_CODE_MODIFIED_BECAUSE_OF_EXCEPTIONAL_REASONS
  #define NL_CODE_MODIFIED_BECAUSE_OF_EXCEPTIONAL_REASONS_BEGIN
  #define NL_CODE_MODIFIED_BECAUSE_OF_EXCEPTIONAL_REASONS_END

#endif
}



//-----------------------------------------------------------------------------------
//
// TRACE OUTPUT
//
//-----------------------------------------------------------------------------------
namespace nextlimit
{
#if defined (_DEBUG) || defined ( _DEBUG_RELEASE )

  NL_BASIC_EXPORTS_DLL FILE* NL_getTraceOutputFile();
  NL_BASIC_EXPORTS_DLL void NL_setTraceOutput( const NL_CHAR* const traceOutput );

#else

  #define NL_getTraceOutputFile(a)
  #define NL_setTraceOutput(a)

#endif
}


//-----------------------------------------------------------------------------------
//
// NL_DELIBERATED_COMPILATION_ERROR
//
//-----------------------------------------------------------------------------------
#if defined ( _WINDOWS )
# define NL_DELIBERATED_COMPILATION_ERROR nl_deliberated_compilation_error;
#else
# define NL_DELIBERATED_COMPILATION_ERROR NL_BREAKPOINT
#endif



//-----------------------------------------------------------------------------------
//
// _DEBUG_WITH_ASSERTS
//
//-----------------------------------------------------------------------------------
#if defined ( _DEBUG ) || defined ( NL_ASSERT_IS_TRACE )

  #define _DEBUG_WITH_ASSERTS

#endif



//-----------------------------------------------------------------------------------
//
// WARNING NL_DEBUGGING_CODE
//
//-----------------------------------------------------------------------------------
namespace nextlimit
{
#if !defined ( _DEBUG_WITH_ASSERTS )
  NL_BASIC_EXPORTS_DLL void NL_writeDebuggingCodeWarningText();
  #define NL_DEBUGGING_CODE NL_writeDebuggingCodeWarningText()
#else
  #define NL_DEBUGGING_CODE
#endif
}


//-----------------------------------------------------------------------------------
//
// IF_ASSERT_LEVEL_NON_ZERO
//
//-----------------------------------------------------------------------------------
#if defined ( _DEBUG_WITH_ASSERTS )

#define IF_ASSERT_LEVEL_NON_ZERO if ( NL_getAssertLevel() > 0 )

#endif



//-----------------------------------------------------------------------------------
//
// ASSERT LEVEL
// to remove asserts in execution time, use:
//          NL_pushAssertLevel( 0, "i dont want asserts because this reason" );
//          { here comes code without asserts; }
//          NL_popAssertLevel;
//
//-----------------------------------------------------------------------------------
namespace nextlimit
{
#if defined ( _DEBUG_WITH_ASSERTS )

  NL_BASIC_EXPORTS_DLL_STATIC extern NL_INT32 g_assertLevel;
  inline NL_INT32 NL_getAssertLevel() { return( g_assertLevel ); }

  NL_BASIC_EXPORTS_DLL void NL_setAssertLevel( NL_INT32 assertLevel );
  NL_BASIC_EXPORTS_DLL void NL_pushAssertLevel( NL_INT32 assertLevel, const char* psz );
  NL_BASIC_EXPORTS_DLL void NL_pushAssertLevelDesc( const char* psz );
  NL_BASIC_EXPORTS_DLL void NL_popAssertLevel();

#else

  inline void NL_setAssertLevel() {}
  inline void NL_pushAssertLevel( NL_INT32, const char* ) {}
  inline void NL_pushAssertLevelDesc( const char* ) {}
  inline void NL_popAssertLevel() {}

#endif
}

//-----------------------------------------------------------------------------------
//
// DEBUG & DEBUG_RELEASE: NL_TRACE
//
//-----------------------------------------------------------------------------------
#if defined ( _DEBUG ) || defined ( _DEBUG_RELEASE )

  #include <assert.h>
  #include <stdio.h>
  #include <stdarg.h>

  inline void NL_TRACE( const unsigned int n, const char* psFormat, ... )
  {
    va_list args;
    va_start( args, psFormat );

    char* szBuffer;

  #if defined ( _MSC_VER )
    const int count = _vscprintf( psFormat, args );
    szBuffer = new char[ count + 1 ];
    vsprintf( szBuffer, psFormat, args );
  #elif defined ( __GNUC__)
    vasprintf( &szBuffer, psFormat, args );
  #else
  # error "Compiler not supported"
  #endif

    for( unsigned int i = 0; i < n; i++ )
    {
      FILE* output = nextlimit::NL_getTraceOutputFile();
      IF_THEN( output == NULL, output = stderr );
      assert( output != NULL );

      ::fprintf( output, "%s\n", szBuffer );
      ::fflush( output );
    }

    va_end( args );

  #if defined ( _MSC_VER )
    delete( szBuffer );
  #elif defined ( __GNUC__)
    free( szBuffer );
  #else
    # error "Compiler not supported"
  #endif
  }

  inline void NL_TRACE( const char* psFormat, ... )
  {
    va_list args;
    va_start( args, psFormat );

    char* szBuffer;

  #if defined ( _MSC_VER )
    const int count = _vscprintf( psFormat, args );
    szBuffer = new char[ count + 1 ];
    vsprintf( szBuffer, psFormat, args );
  #elif defined ( __GNUC__)
    vasprintf( &szBuffer, psFormat, args );
  #else
  # error "Compiler not supported"
  #endif

    FILE* output = nextlimit::NL_getTraceOutputFile();
    IF_THEN( output == NULL, output = stderr );
    assert( output != NULL );

    ::fprintf( output, "%s\n", szBuffer );
    ::fflush( output );

    va_end( args );

  #if defined ( _MSC_VER )
    delete( szBuffer );
  #elif defined ( __GNUC__)
    free( szBuffer );
  #else
    # error "Compiler not supported"
  #endif
  }


//
// NO DEBUG: NLTRACE
//
#else

  inline void NL_TRACE ( const unsigned int, const char*, ... ) {}
  inline void NL_TRACE ( const char*, ... ) {}

#endif //_DEBUG...

//-----------------------------------------------------------------------------------
//
// DEBUG & DEBUG_RELEASE: NL_TRACE_DEVELOPER
//
//-----------------------------------------------------------------------------------

#define NL_TRACE_EMPTY( name )\
  inline void NL_TRACE_##name ( const char*, ... ) {}\
  inline void NL_TRACE_##name( const unsigned int n, const char* psFormat, ... )\
  { \
    NL_VARIABLE_MAYBE_NOT_REFERENCED2( n, psFormat );\
  }

#if defined ( _DEBUG ) || defined ( _DEBUG_RELEASE )

  #include <assert.h>
  #include <stdio.h>
  #include <stdarg.h>

#if defined ( _MSC_VER )
# define NL_TRACE_DEVELOPER( name ) \
  inline void NL_TRACE_##name( const unsigned int n, const char* psFormat, ... ) \
  {\
    va_list args;\
    va_start( args, psFormat );\
    char* szBuffer;\
    const int count = _vscprintf( psFormat, args );\
    szBuffer = new char[ count + 1 ];\
    vsprintf( szBuffer, psFormat, args );\
    for( unsigned int i = 0; i < n; i++ )\
    {\
      FILE* output = nextlimit::NL_getTraceOutputFile();\
      IF_THEN( output == NULL, output = stderr );\
      assert( output != NULL );\
      ::fprintf( output, "%s\n", szBuffer );\
      ::fflush( output );\
    }\
    va_end( args );\
    delete( szBuffer ); \
  } \
  inline void NL_TRACE_##name( const char* psFormat, ... ) \
  {\
    va_list args;\
    va_start( args, psFormat );\
    char* szBuffer;\
    const int count = _vscprintf( psFormat, args );\
    szBuffer = new char[ count + 1 ];\
    vsprintf( szBuffer, psFormat, args );\
    FILE* output = nextlimit::NL_getTraceOutputFile();\
    IF_THEN( output == NULL, output = stderr );\
    assert( output != NULL );\
    ::fprintf( output, "%s\n", szBuffer );\
    ::fflush( output );\
    va_end( args );\
    delete( szBuffer ); \
  }
#elif defined ( __GNUC__)
# define NL_TRACE_DEVELOPER( name ) \
  inline void NL_TRACE_##name( const unsigned int n, const char* psFormat, ... )\
  {\
    va_list args;\
    va_start( args, psFormat );\
    char* szBuffer;\
    vasprintf( &szBuffer, psFormat, args );\
    for( unsigned int i = 0; i < n; i++ )\
    {\
      FILE* output = nextlimit::NL_getTraceOutputFile();\
      IF_THEN( output == NULL, output = stderr );\
      assert( output != NULL );\
      ::fprintf( output, "%s\n", szBuffer );\
      ::fflush( output );\
    }\
    va_end( args );\
    free( szBuffer );\
  }\
  inline void NL_TRACE_##name( const char* psFormat, ... ) \
  {\
    va_list args;\
    va_start( args, psFormat );\
    char* szBuffer;\
    vasprintf( &szBuffer, psFormat, args );\
    FILE* output = nextlimit::NL_getTraceOutputFile();\
    IF_THEN( output == NULL, output = stderr );\
    assert( output != NULL );\
    ::fprintf( output, "%s\n", szBuffer );\
    ::fflush( output );\
    va_end( args );\
    free( szBuffer );\
  }
#else
# define NL_TRACE_DEVELOPER( name ) \
    #error "Compiler not supported"
#endif

#else

#define NL_TRACE_DEVELOPER( name ) NL_TRACE_EMPTY( name )

#endif

#if defined ( DEVELOPER_IS_ET )
  NL_TRACE_DEVELOPER( ET )
#else
  NL_TRACE_EMPTY( ET )
#endif

#if defined ( DEVELOPER_IS_ENRIQUE )
  NL_TRACE_DEVELOPER( ENRIQUE )
#else
  NL_TRACE_EMPTY( ENRIQUE )
#endif

#if defined ( DEVELOPER_IS_ATT )
  NL_TRACE_DEVELOPER( ATT )
#else
  NL_TRACE_EMPTY( ATT )
#endif

#if defined ( DEVELOPER_IS_ANGEL )
  NL_TRACE_DEVELOPER( ANGEL )
#else
  NL_TRACE_EMPTY( ANGEL )
#endif

#if defined ( DEVELOPER_IS_ALEX )
  NL_TRACE_DEVELOPER( ALEX )
#else
  NL_TRACE_EMPTY( ALEX )
#endif

#if defined ( DEVELOPER_IS_HECTOR )
  NL_TRACE_DEVELOPER( HECTOR )
#else
  NL_TRACE_EMPTY( HECTOR )
#endif

#if defined ( DEVELOPER_IS_IVAN )
  NL_TRACE_DEVELOPER( IVAN )
#else
  NL_TRACE_EMPTY( IVAN )
#endif

#if defined ( DEVELOPER_IS_REALFLOW )
  NL_TRACE_DEVELOPER( REALFLOW )
#else
  NL_TRACE_EMPTY( REALFLOW )
#endif

//-----------------------------------------------------------------------------------
//
// NL_ASSERT, NL_ASSERT_NOT_NULL, NL_ASSERT_SIZE
//
//-----------------------------------------------------------------------------------
#define NL_ASSERT(expr) NL_BREAK(expr)
#define NL_ASSERT_2( expr0, expr1 ) NL_ASSERT( NL_and2( expr0, expr1 ) )
#define NL_ASSERT_3( expr0, expr1, expr2 ) NL_ASSERT( NL_and3( expr0, expr1, expr2 ) )
#define NL_ASSERT_4( expr0, expr1, expr2, expr3 ) NL_ASSERT( NL_and4( expr0, expr1, expr2, expr3 ) )
#define NL_ASSERT_5( expr0, expr1, expr2, expr3, expr4 ) NL_ASSERT( NL_and5( expr0, expr1, expr2, expr3, expr4 ) )
#define NL_ASSERT_6( expr0, expr1, expr2, expr3, expr4, expr5 ) NL_ASSERT( NL_and6( expr0, expr1, expr2, expr3, expr4, expr5 ) )

#define NL_ASSERT_NOT_NULL(expr) NL_ASSERT(expr != NULL)
#define NL_ASSERT_NOT_NULL_2( expr0, expr1 ) NL_ASSERT( NL_and2( expr0 != NULL, expr1 != NULL ) )
#define NL_ASSERT_NOT_NULL_3( expr0, expr1, expr2 ) NL_ASSERT( NL_and3( expr0 != NULL, expr1 != NULL, expr2 != NULL ) )
#define NL_ASSERT_IS_NULL(expr) NL_ASSERT(expr == NULL)
#define NL_ASSERT_IS_NULL_2( expr0, expr1 ) NL_ASSERT( NL_and2( expr0 == NULL, expr1 == NULL ) )
#define NL_ASSERT_IS_NULL_3( expr0, expr1, expr2 ) NL_ASSERT( NL_and3( expr0 == NULL, expr1 == NULL, expr2 == NULL ) )

#define NL_ASSERT_NOT_ZERO(expr) NL_ASSERT( expr != 0 )
#define NL_ASSERT_IS_ZERO(expr) NL_ASSERT( expr == 0 )

#define NL_ASSERT_NOT_EMPTY( a ) NL_ASSERT( a.size() != 0 )
#define NL_ASSERT_IS_EMPTY( a ) NL_ASSERT( a.size() == 0 )

#define NL_ASSERT_SIZE( a, b ) NL_ASSERT( a.size() == b.size() )
#define NL_ASSERT_SIZE_3( a, b, c ) NL_ASSERT( a.size() == b.size() ); NL_ASSERT( a.size() == c.size() )

//-----------------------------------------------------------------------------------
//
// NL_ASSERT_VARIABLE_AND_MAYBE_NOT_REFERENCED
// NOTE: Not valid for expressions, only for variables
//
//-----------------------------------------------------------------------------------
#define NL_ASSERT_VARIABLE_AND_MAYBE_NOT_REFERENCED(a) \
  NL_VARIABLE_MAYBE_NOT_REFERENCED(a) \
  NL_BREAK(a)


//-----------------------------------------------------------------------------------
//
// NL_ASSERT_ALWAYS
//
//-----------------------------------------------------------------------------------
#define NL_ASSERT_ALWAYS(expr) NL_BREAK_ALWAYS(expr)

//-----------------------------------------------------------------------------------
//
// NL_CONTINUE_AFTER_FIRST_EXECUTION
// NL_RETURN_AFTER_FIRST_EXECUTION
//
//-----------------------------------------------------------------------------------
#define NL_CONTINUE_AFTER_FIRST_EXECUTION         \
    { static NL_BOOL firstExecution = NL_true;    \
    IF_NOT_THEN_CONTINUE( firstExecution );       \
    firstExecution = NL_false; }

#define NL_RETURN_AFTER_FIRST_EXECUTION           \
    { static NL_BOOL firstExecution = NL_true;    \
    IF_NOT_THEN_RETURN( firstExecution );         \
    firstExecution = NL_false; }

//-----------------------------------------------------------------------------------
//
// NL_BREAK, NL_BREAKPOINT
//
//-----------------------------------------------------------------------------------

#if defined( NL_ASSERT_IS_TRACE )

  #if defined (_DEBUG) || defined (_DEBUG_RELEASE )
  #define NL_BREAK(a)   { using namespace nextlimit; \
                          static bool bTrace = true; \
                          if( (NL_getAssertLevel()>0) && bTrace ) \
                          { bool cond = static_cast<bool>( a ); \
                          if( !cond ) \
                          { bTrace = false; \
                          NL_TRACE( "Assert at File:\"%s\" Line:\"%d\"", \
                                    __FILE__, __LINE__ ); } } }
  #else
  #define NL_BREAK(a)
  #endif

#else

#if defined (_DEBUG)

  #if defined (_WINDOWS)
  #define NL_BREAK(a)   { using namespace nextlimit; \
                          static bool bStop = true; \
                          if( (NL_getAssertLevel()>0) && bStop ) \
                          { bool cond = static_cast<bool>( a ); \
                          if( !cond ) { bStop = false; __debugbreak(); } } }

  #elif defined( _MACOSX ) || defined( _IOS )
  #define NL_BREAK(a)     { using namespace nextlimit; \
                            static bool bStop = true; \
                            if( (NL_getAssertLevel()>0) && bStop ) \
                            { bool cond = static_cast<bool>( a ); \
                            if( !cond ) { bStop = false; nextlimit::NL_BREAK_MACOSX(); } } }

  #elif defined (_LINUX )  && !defined(DEVELOPER_IS_ET)
  #define NL_BREAK(a)   { using namespace nextlimit; \
                          static bool bStop = true; \
                          if( (NL_getAssertLevel()>0) && bStop ) \
                          { bool cond = static_cast<bool>( a ); \
  if( !cond ) { bStop = false; /*asm("int $3");*/ } } }


  #else
    #define NL_BREAK(a)
  #endif

#else

  #define NL_BREAK(a)

#endif

#endif

#define NL_BREAKPOINT NL_BREAK( false )
#define NL_BREAKPOINTABLE { int aux = 0; NL_VARIABLE_MAYBE_NOT_REFERENCED( aux ); }


//-----------------------------------------------------------------------------------
//
// NL_BREAK_ALWAYS, NL_BREAKPOINT_ALWAYS
//
//-----------------------------------------------------------------------------------
#if defined (_DEBUG)

  #if defined (_WINDOWS)
  #define NL_BREAK_ALWAYS(a)   { using namespace nextlimit; \
                               if( NL_getAssertLevel()>0 ) \
                               { bool cond = static_cast<bool>( a ); \
                               if( !cond ) { __debugbreak(); } } }

  #elif defined( _MACOSX ) || defined( _IOS )
  #define NL_BREAK_ALWAYS(a)   { using namespace nextlimit; \
                               if( NL_getAssertLevel()>0 ) \
                               { bool cond = static_cast<bool>( a ); \
                               if( !cond ) { try{ throw 99; }catch(int e){}; } } }

  #elif defined (_LINUX)
  #define NL_BREAK_ALWAYS(a)   { using namespace nextlimit; \
                               if( NL_getAssertLevel()>0 ) \
                               { bool cond = static_cast<bool>( a ); \
                               if( !cond ) { asm("int $3"); } } }


  #else
  #define NL_BREAK_ALWAYS(a)
  #endif

#else

  #define NL_BREAK_ALWAYS(a)

#endif


  #define NL_BREAKPOINT_ALWAYS NL_BREAK_ALWAYS( false )


//-----------------------------------------------------------------------------------
//
// NL_ASSERT_RELEASE
//
//-----------------------------------------------------------------------------------
extern NL_BASIC_EXPORTS_DLL
void NL_messageBoxError( char* desc );

#ifdef _DEBUG_RELEASE
  #define NL_ASSERT_RELEASE(desc,expr) { static NL_BOOL bStop = NL_true; \
                                         NL_BOOL cond = static_cast<NL_BOOL>( expr ); \
                                         if( !(cond) && bStop ) \
                                         { bStop = NL_false; \
                                         NL_messageBoxError( desc ); } }
#else
  #define NL_ASSERT_RELEASE(desc,expr)
#endif


//-----------------------------------------------------------------------------------
//
// NL_ASSERT_TYPES_SHOULD_BE_EQUAL
//
//-----------------------------------------------------------------------------------
template <class Z>
void TYPES_SHOULD_BE_EQUALS( Z&, Z& )
{
  // ---------------------------------------------------------- //
  // If the compiler complains here, it is because              //
  // there have been an NL_ASSERT_TYPES_SHOULD_BE_EQUAL( a, b ) //
  // call that have failed.                                     //
  //                                                            //
  // Being this an assert, check the types you have passed      //
  // to the template using it.                                  //
  // ---------------------------------------------------------- //
}

template <class T, class Q>
void TYPES_SHOULD_BE_EQUALS_GIVEN_TYPES()
{
  T* ptrType1 = 0;
  Q* ptrType2 = 0;
  TYPES_SHOULD_BE_EQUALS(*ptrType1, *ptrType2);
}

#define NL_ASSERT_IS_SAME_TYPE( a, b ) \
    TYPES_SHOULD_BE_EQUALS_GIVEN_TYPES<  a, b>();

#define NL_ASSERT_IS_SAME_TYPE_3( a, b, c ) \
    NL_ASSERT_IS_SAME_TYPE( a, b ); \
    NL_ASSERT_IS_SAME_TYPE( a, c );


//-----------------------------------------------------------------------------------
//
// NL_isSameType
//
//-----------------------------------------------------------------------------------
template< class A >
NL_BOOL NL_isSameType( const A&, const A& )
{
  return_true;
}

template< class A >
NL_BOOL NL_isSameType( const A&, const A&, const A& )
{
  return_true;
}

template< class A, class B >
NL_BOOL NL_isSameType( const A&, const B& )
{
  return_false;
}

template< class A, class B, class C >
NL_BOOL NL_isSameType( const A&, const B&, const C& )
{
  return_false;
}

template< class A, class B >
NL_BOOL NL_isSameType()
{
  A* a = NULL;
  B* b = NULL;
  return( NL_isSameType(a,b) );
}

template< class A, class B, class C >
NL_BOOL NL_isSameType()
{
  A* a = NULL;
  B* b = NULL;
  C* c = NULL;
  return( NL_isSameType(a,b,c) );
}


//-----------------------------------------------------------------------------------
//
// Result type
//
//-----------------------------------------------------------------------------------
typedef NL_INT32 NL_CODE_RESULT;

// Build error code from 3 numbers
//	t     .- type (0 - 1 / success - fail)
//	mod	  .- module identifier (0 - 2047)
//	code  .- code (0 - 65535)
#define MAKE_NL_CODE_RESULT(t,mod,code) \
	((NL_CODE_RESULT) (((NL_UINT32) (t) << 31) | \
	((NL_UINT32) (mod) << 16) | ((NL_UINT32) (code))))

// Evaluation return code
#define NL_SUCCEEDED(status)	( (NL_CODE_RESULT) (status) >= 0 )
#define NL_FAILED(status)	    ( (NL_CODE_RESULT) (status) <  0 )

// Errors
#define NLR_OK            MAKE_NL_CODE_RESULT (0, 0, 0)
#define NLR_FAIL          MAKE_NL_CODE_RESULT (1, 0, 1)
#define NLR_OUTOFMEMORY   MAKE_NL_CODE_RESULT (1, 0, 2)
#define NLR_NOTIMPL       MAKE_NL_CODE_RESULT (1, 0, 3)
#define NLR_POINTER       MAKE_NL_CODE_RESULT (1, 0, 4)
#define NLR_INVALIDARG    MAKE_NL_CODE_RESULT (1, 0, 5)
#define NLR_UNEXPECTED    MAKE_NL_CODE_RESULT (1, 0, 6)

// access( const char *path, int amode )
// funtion cheks the accessibility of the file named by path
// for the access permissions indicated by amode
 #if defined(_WINDOWS )
 #define ACCESS _access
 #else
 #define ACCESS access
 #endif


//-----------------------------------------------------------------------------------
//
// Base Exception Class
//
//-----------------------------------------------------------------------------------

class NL_Exception : public std::exception
{
  public:

    NL_Exception( const NL_CODE_RESULT& nlresult = NLR_FAIL ) :
        nlresult_( nlresult ),
        errMsg_( "" )
        {}

        NL_Exception( const NL_CODE_RESULT& nlresult, const std::string& errMsg ) :
      nlresult_( nlresult ),
      errMsg_( errMsg )
      {}

    std::string& errMsg() { return errMsg_; }
    NL_CODE_RESULT errCode() { return nlresult_; }
    virtual ~NL_Exception() throw() {}
    NL_CODE_RESULT nlresult_;
    std::string errMsg_;
};

//-----------------------------------------------------------------------------------
//
// OSX Breakpoint function
//
//-----------------------------------------------------------------------------------

#if defined ( _MACOSX )

namespace nextlimit
{
  NL_BASIC_EXPORTS_DLL void NL_BREAK_MACOSX( void );
}

#endif

//-----------------------------------------------------------------------------------
//
// NL_TRY_CATCH_HANDLE (handy for one line exception catching and handling).
//
//-----------------------------------------------------------------------------------

#define NL_TRY_CATCH_HANDLE( nl_try, nl_catch, nl_handle )  \
  try { nl_try; } catch ( const nl_catch& e ) { nl_handle(e); }

//-----------------------------------------------------------------------------------
//
// Pointer to output console function
//
//-----------------------------------------------------------------------------------
typedef void ( *NL_PfnConsoleOutput ) ( const char* );



// NameSpace NextLimit
// NameSpace NextLimit
// NameSpace NextLimit
namespace nextlimit
{

//-----------------------------------------------------------------------------------
//
// pointers task NL_safeDelete, NL_safeDeleteArray, NL_safeAssign
//
//-----------------------------------------------------------------------------------

template <class T>
void NL_safeDelete( T*& p )
{
  if( p )
  {
    T* pTemp = p;
    p = NULL;         // [AG] Important set NULL before delete() because p is now without service !!!
    delete( pTemp );
  }
}

template <class T>
void NL_safeDeleteArray( T*& p )
{
  if( p )
  {
    T* pTemp = p;
    p = NULL;         // [AG] Important set NULL before delete() because p is now without service !!!
    delete[]( pTemp );
  }
}

template <class T, class U>
void NL_safeAssign( T*& pDest, U* pOrig )
{
  NL_ASSERT( pOrig != NULL );
  NL_ASSERT( ( pDest == NULL ) || ( pDest == pOrig ) );
  pDest = pOrig;
}

template <class T>
void NL_safeNew( T*& p )
{
  NL_ASSERT( p == NULL );
  p = new T();
}


// NL_PREDECLARABLE_AUTODELETE macro
// put this after class definition
// and then using counterpart NL_PREDECLARABLE_AUTODELETE, you can use ArrayOfPtrAutodelete without including .h of class
// note: it is supposed you use this inside the namespace indicated
#define NL_PREDECLARABLE_AUTODELETE( namespaceName, className ) \
} \
template<> inline void NL_safeDelete( namespaceName::className*& p ) \
{ \
  if( p ) \
  { \
    namespaceName::className* pTemp = p; \
    p = NULL;  \
    delete( pTemp );  \
  } \
} \
namespace namespaceName {


// NL_PREDECLARATION_AUTODELETE macro
// put this for pre-declaration class used in ArrayOfPtrAutodelete without including .h of class
// note: it is supposed you use this inside the namespace indicated
#define NL_PREDECLARATION_AUTODELETE( namespaceName, className ) \
class className; \
} \
template<> inline void NL_safeDelete( namespaceName::className*& p ); \
namespace namespaceName \
{


/*
template <class T>
void NL_safeDelete_forwardDeclaration( T*& p );

template <class T>
T* NL_new_forwardDeclaration();

template <class T, class T_PARAM>
T* NL_new_forwardDeclaration( const T_PARAM& param );

template <class T, class T_PARAM_1, class T_PARAM_2>
T* NL_new_forwardDeclaration( const T_PARAM_1& param_1, const T_PARAM_2& param_2 );


template <class T>
void NL_safeNew_forwardDeclaration( T*& p )
{
  NL_ASSERT( p == NULL );
  p = NL_new_forwardDeclaration<T>();
}
*/


//-----------------------------------------------------------------------------------
//
// aligned stuff specific WINDOWS
//
//-----------------------------------------------------------------------------------
#ifdef _WINDOWS

  template<size_t bytes_alignment>
  inline void* NL_newAligned_bytes( size_t size )
  {
    return( _aligned_malloc( size, bytes_alignment ) );
  }

  inline void NL_deleteAligned( void* p )
  {
    _aligned_free( p );
  }

  #define NL_ALIGN_BEGIN( bytes_alignment ) __declspec(align(bytes_alignment))
  #define NL_ALIGN_END( bytes_alignment )

#endif
//-----------------------------------------------------------------------------------
//
// aligned stuff specific _MACOSX
//
//-----------------------------------------------------------------------------------
#if defined( _MACOSX ) || defined( _IOS )
//Memory in OS X is always aligned to 16 byte boundaries, making this function irrelevant
  template<size_t bytes_alignment>
  inline void* NL_newAligned_bytes( size_t size )
  {
    //NL_BREAKPOINT;
    return(malloc( size));
  }

  inline void NL_deleteAligned( void* p )
  {
    //NL_BREAKPOINT;
    free( p );
  }

  #define NL_ALIGN_BEGIN( bytes_alignment )
  #define NL_ALIGN_END( bytes_alignment ) __attribute__ ((aligned (bytes_alignment)))

#endif
//-----------------------------------------------------------------------------------
//
// aligned stuff specific _LINUX
//
//-----------------------------------------------------------------------------------
#ifdef _LINUX

  inline size_t getPowerOf2Ceil( const size_t n )
  {
    size_t ret = sizeof( void* );
    while ( n > ret )
    {
      ret *= 2;
    }
    return( ret );
  }

  template<size_t bytes_alignment>
  inline void* NL_newAligned_bytes( size_t size )
  {
    size_t bytes_alignment_ok = getPowerOf2Ceil( bytes_alignment );
    void* memory;
    posix_memalign( &memory, bytes_alignment_ok, size );
    return memory;
  }


  inline void NL_deleteAligned( void* p )
  {
    free( p );
  }

  #define NL_ALIGN_BEGIN( bytes_alignment )
  #define NL_ALIGN_END( bytes_alignment ) __attribute__((aligned(bytes_alignment)))

#endif



//-----------------------------------------------------------------------------------
//
// aligned stuff Platform independent
//
//-----------------------------------------------------------------------------------
inline void NL_safeDeleteAligned( void*& p )
{
  if( p )
  {
    void* pTemp = p;
    p = NULL;    
    NL_deleteAligned( pTemp );
  }
}


#define NL_ALIGNED_NEW_OPERATORS( bytes_alignment ) \
  void* operator new( size_t size ) { return( NL_newAligned_bytes<bytes_alignment>(size) ); }   \
  void* operator new[]( size_t size ) { return( NL_newAligned_bytes<bytes_alignment>(size) ); } \
  void operator delete( void* p ) { if (p) { NL_deleteAligned(p); } }                           \
  void operator delete[]( void* p ) { if (p) { NL_deleteAligned(p); } }

#define NL_ALIGN_BEGIN_2_bytes  NL_ALIGN_BEGIN(2)
#define NL_ALIGN_BEGIN_4_bytes  NL_ALIGN_BEGIN(4)
#define NL_ALIGN_BEGIN_8_bytes  NL_ALIGN_BEGIN(8)
#define NL_ALIGN_BEGIN_16_bytes NL_ALIGN_BEGIN(16)
#define NL_ALIGN_BEGIN_32_bytes NL_ALIGN_BEGIN(32)
#define NL_ALIGN_BEGIN_64_bytes NL_ALIGN_BEGIN(64)

#define NL_ALIGN_BEGIN_16_bits NL_ALIGN_BEGIN(2)
#define NL_ALIGN_BEGIN_32_bits NL_ALIGN_BEGIN(4)
#define NL_ALIGN_BEGIN_64_bits NL_ALIGN_BEGIN(8)

#define NL_ALIGN_END_2_bytes  NL_ALIGN_END(2)
#define NL_ALIGN_END_4_bytes  NL_ALIGN_END(4)
#define NL_ALIGN_END_8_bytes  NL_ALIGN_END(8)
#define NL_ALIGN_END_16_bytes NL_ALIGN_END(16)
#define NL_ALIGN_END_32_bytes NL_ALIGN_END(32)
#define NL_ALIGN_END_64_bytes NL_ALIGN_END(64)

#define NL_ALIGN_END_16_bits NL_ALIGN_END(2)
#define NL_ALIGN_END_32_bits NL_ALIGN_END(4)
#define NL_ALIGN_END_64_bits NL_ALIGN_END(8)

inline void* NL_newAligned_2_bytes ( size_t size ) { return( NL_newAligned_bytes<2> ( size ) ); }
inline void* NL_newAligned_4_bytes ( size_t size ) { return( NL_newAligned_bytes<4> ( size ) ); }
inline void* NL_newAligned_8_bytes ( size_t size ) { return( NL_newAligned_bytes<8> ( size ) ); }
inline void* NL_newAligned_16_bytes( size_t size ) { return( NL_newAligned_bytes<16>( size ) ); }
inline void* NL_newAligned_32_bytes( size_t size ) { return( NL_newAligned_bytes<32>( size ) ); }
inline void* NL_newAligned_64_bytes( size_t size ) { return( NL_newAligned_bytes<64>( size ) ); }

inline void* NL_newAligned_16_bits( size_t size ) { return( NL_newAligned_2_bytes( size ) ); }
inline void* NL_newAligned_32_bits( size_t size ) { return( NL_newAligned_4_bytes( size ) ); }
inline void* NL_newAligned_64_bits( size_t size ) { return( NL_newAligned_8_bytes( size ) ); }

template<size_t bytes_alignment,class T>
NL_BOOL NL_isAligned( const T* const p )
{
  size_t dir = (size_t)p;
  return( ( dir & (bytes_alignment-1) ) == 0 );
}

template<class T> NL_BOOL NL_isAligned_2_bytes ( const T* const p ) { return( NL_isAligned<2> ( p ) ); }
template<class T> NL_BOOL NL_isAligned_4_bytes ( const T* const p ) { return( NL_isAligned<4> ( p ) ); }
template<class T> NL_BOOL NL_isAligned_8_bytes ( const T* const p ) { return( NL_isAligned<8> ( p ) ); }
template<class T> NL_BOOL NL_isAligned_16_bytes( const T* const p ) { return( NL_isAligned<8> ( p ) ); }
template<class T> NL_BOOL NL_isAligned_32_bytes( const T* const p ) { return( NL_isAligned<32>( p ) ); }
template<class T> NL_BOOL NL_isAligned_64_bytes( const T* const p ) { return( NL_isAligned<64>( p ) ); }

template<class T> NL_BOOL NL_isAligned_16_bits( const T* const p ) { return( NL_isAligned<2> ( p ) ); }
template<class T> NL_BOOL NL_isAligned_32_bits( const T* const p ) { return( NL_isAligned<4> ( p ) ); }
template<class T> NL_BOOL NL_isAligned_64_bits( const T* const p ) { return( NL_isAligned<8> ( p ) ); }

#define NL_ASSERT_IS_ALIGNED_2_bytes(p) NL_ASSERT( NL_isAligned_2_bytes(p) )
#define NL_ASSERT_IS_ALIGNED_4_bytes(p) NL_ASSERT( NL_isAligned_4_bytes(p) )
#define NL_ASSERT_IS_ALIGNED_8_bytes(p) NL_ASSERT( NL_isAligned_8_bytes(p) )
#define NL_ASSERT_IS_ALIGNED_16_bytes(p) NL_ASSERT( NL_isAligned_16_bytes(p) )
#define NL_ASSERT_IS_ALIGNED_32_bytes(p) NL_ASSERT( NL_isAligned_32_bytes(p) )
#define NL_ASSERT_IS_ALIGNED_64_bytes(p) NL_ASSERT( NL_isAligned_64_bytes(p) )

#define NL_ASSERT_IS_ALIGNED_16_bits(p) NL_ASSERT( NL_isAligned_16_bits(p) )
#define NL_ASSERT_IS_ALIGNED_32_bits(p) NL_ASSERT( NL_isAligned_32_bits(p) )
#define NL_ASSERT_IS_ALIGNED_64_bits(p) NL_ASSERT( NL_isAligned_64_bits(p) )


//-----------------------------------------------------------------------------------
//
// NL_PER_THREAD
//
//-----------------------------------------------------------------------------------
#ifdef _WINDOWS
#define NL_PER_THREAD __declspec( thread )
#elif defined( _MACOSX ) || defined( _IOS )
#define NL_PER_THREAD __thread /////esto no funciona en OSX tengo que hacerlo con pthreads
#elif _LINUX
#define NL_PER_THREAD __thread
#endif


//-----------------------------------------------------------------------------------
//
// NL_isValid
//
//-----------------------------------------------------------------------------------
template< class T> inline
NL_BOOL NL_isValid( const T& value )
{
  return( value.isValid() );
}

template<> inline NL_BOOL NL_isValid( const NL_UINT8&  ) { return_true; }
template<> inline NL_BOOL NL_isValid( const NL_UINT16& ) { return_true; }
template<> inline NL_BOOL NL_isValid( const NL_UINT32& ) { return_true; }
template<> inline NL_BOOL NL_isValid( const NL_UINT64& ) { return_true; }

#if ( defined( _MACOSX ) || defined( _IOS )|| defined (_LINUX) ) && defined (NL_OS_64)
template<> inline NL_BOOL NL_isValid( const size_t& ) { return_true; }
template<> inline NL_BOOL NL_isValid( const long int& ) { return_true; }
#else
template<> inline NL_BOOL NL_isValid( const long int& ) { return_true; }
template<> inline NL_BOOL NL_isValid( const long unsigned int& ) { return_true; }
#endif


template<> inline NL_BOOL NL_isValid( const NL_INT8&  value ) { return( ( *(NL_UINT8* )&value ) !=                 0x80 ); }
template<> inline NL_BOOL NL_isValid( const NL_INT16& value ) { return( ( *(NL_UINT16*)&value ) !=               0x8000 ); }
template<> inline NL_BOOL NL_isValid( const NL_INT32& value ) { return( ( *(NL_UINT32*)&value ) !=           0x80000000 ); }
template<> inline NL_BOOL NL_isValid( const NL_INT64& value ) { return( ( *(NL_UINT64*)&value ) != 0x8000000000000000LL ); }

template<> inline NL_BOOL NL_isValid( const NL_DOUBLE& value ) { return( ( ISNAN( value ) == 0 ) && ( FINITE( value ) != 0 ) ); }
template<> inline NL_BOOL NL_isValid( const NL_FLOAT&  value ) { return( ( ISNAN( value ) == 0 ) && ( FINITE( value ) != 0 ) ); }

#define NL_ASSERT_IS_VALID( a ) NL_ASSERT( NL_isValid( a ) );
#define NL_ASSERT_IS_VALID2( a, b ) NL_ASSERT_IS_VALID( a ); NL_ASSERT_IS_VALID( b );
#define NL_ASSERT_IS_VALID3( a, b, c ) NL_ASSERT_IS_VALID( a ); NL_ASSERT_IS_VALID( b ); NL_ASSERT_IS_VALID( c );
#define NL_ASSERT_IS_VALID4( a, b, c, d ) NL_ASSERT_IS_VALID( a ); NL_ASSERT_IS_VALID( b ); NL_ASSERT_IS_VALID( c ); NL_ASSERT_IS_VALID( d );
#define NL_ASSERT_IS_VALID5( a, b, c, d , e) NL_ASSERT_IS_VALID( a ); NL_ASSERT_IS_VALID( b ); NL_ASSERT_IS_VALID( c ); NL_ASSERT_IS_VALID( d ); NL_ASSERT_IS_VALID( e );

#define NL_ASSERT_IS_VALID_POSITIVE( a ) NL_ASSERT( NL_isValid( a ) ); NL_ASSERT( a > 0 );


//-----------------------------------------------------------------------------------
//
// NL_isBool
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isBool()
{
  return_false;
}

template<> inline NL_BOOL NL_isBool <NL_BOOL > () { return_true; }


//-----------------------------------------------------------------------------------
//
// NL_isInteger
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isInteger()
{
  return_false;
}

template<> inline NL_BOOL NL_isInteger <NL_UINT8 > () { return_true; }
template<> inline NL_BOOL NL_isInteger <NL_UINT16> () { return_true; }
template<> inline NL_BOOL NL_isInteger <NL_UINT32> () { return_true; }
template<> inline NL_BOOL NL_isInteger <NL_UINT64> () { return_true; }

template<> inline NL_BOOL NL_isInteger <NL_INT8 > () { return_true; }
template<> inline NL_BOOL NL_isInteger <NL_INT16> () { return_true; }
template<> inline NL_BOOL NL_isInteger <NL_INT32> () { return_true; }
template<> inline NL_BOOL NL_isInteger <NL_INT64> () { return_true; }


//-----------------------------------------------------------------------------------
//
// NL_isUnsignedInteger
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isUnsignedInteger()
{
  return_false;
}

template<> inline NL_BOOL NL_isUnsignedInteger <NL_UINT8 > () { return_true; }
template<> inline NL_BOOL NL_isUnsignedInteger <NL_UINT16> () { return_true; }
template<> inline NL_BOOL NL_isUnsignedInteger <NL_UINT32> () { return_true; }
template<> inline NL_BOOL NL_isUnsignedInteger <NL_UINT64> () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isUnsignedInteger8
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isUnsignedInteger8()
{
  return_false;
}

template<> inline NL_BOOL NL_isUnsignedInteger8< NL_UINT8 > () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isUnsignedInteger16
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isUnsignedInteger16()
{
  return_false;
}

template<> inline NL_BOOL NL_isUnsignedInteger16< NL_UINT16 > () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isUnsignedInteger32
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isUnsignedInteger32()
{
  return_false;
}

template<> inline NL_BOOL NL_isUnsignedInteger32< NL_UINT32 > () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isUnsignedInteger64
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isUnsignedInteger64()
{
  return_false;
}

template<> inline NL_BOOL NL_isUnsignedInteger64< NL_UINT64 > () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isSignedInteger
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isSignedInteger()
{
  return_false;
}

template<> inline NL_BOOL NL_isSignedInteger <NL_INT8 > () { return_true; }
template<> inline NL_BOOL NL_isSignedInteger <NL_INT16> () { return_true; }
template<> inline NL_BOOL NL_isSignedInteger <NL_INT32> () { return_true; }
template<> inline NL_BOOL NL_isSignedInteger <NL_INT64> () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isReal
//
// TODO: This should be changed to NL_isReal [att]
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isReal()
{
  return_false;
}

template<> inline NL_BOOL NL_isReal< NL_FLOAT >  () { return_true; }
template<> inline NL_BOOL NL_isReal< NL_DOUBLE > () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isFloating
//
// TODO: This should be changed to NL_isReal [att]
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isFloating()
{
  return_false;
}

template<> inline NL_BOOL NL_isFloating< NL_FLOAT >  () { return_true; }
template<> inline NL_BOOL NL_isFloating< NL_DOUBLE > () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isFloat
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isFloat()
{
  return_false;
}

template<> inline NL_BOOL NL_isFloat< NL_FLOAT >  () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_isDouble
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_isDouble()
{
  return_false;
}

template<> inline NL_BOOL NL_isDouble< NL_DOUBLE >  () { return_true; }

//-----------------------------------------------------------------------------------
//
// NL_maximum
//
//-----------------------------------------------------------------------------------
template< class T >
T NL_maximum()
{
  NL_BREAKPOINT;
  return( T(1) );
}

template<> inline NL_INT8   NL_maximum < NL_INT8   >() { return( 127  ); }
template<> inline NL_UINT8  NL_maximum < NL_UINT8  >() { return( 0xff ); }

template<> inline NL_INT16  NL_maximum < NL_INT16  >() { return( 32767  ); }
template<> inline NL_UINT16 NL_maximum < NL_UINT16 >() { return( 0xffff ); }

template<> inline NL_INT32  NL_maximum < NL_INT32  >() { return( 2147483647 ); }
template<> inline NL_UINT32 NL_maximum < NL_UINT32 >() { return( 0xffffffff ); }

template<> inline NL_INT64  NL_maximum < NL_INT64  >() { return( 0x7fffffffffffffffLL ); }
template<> inline NL_UINT64 NL_maximum < NL_UINT64 >() { return( 0xffffffffffffffffULL ); }

template<> inline NL_FLOAT  NL_maximum < NL_FLOAT  >() { return( FLT_MAX  ); }
template<> inline NL_DOUBLE NL_maximum < NL_DOUBLE >() { return( DBL_MAX  ); }

#ifndef  _WINDOWS
# if defined ( NL_OS_64 )
  template<> inline NL_ULONG NL_maximum < NL_ULONG >() { return( 0xffffffffffffffffULL ); }
# else
  template<> inline NL_ULONG NL_maximum < NL_ULONG >() { return( 0xffffffff ); }
# endif
#endif

#define NL_maximumD NL_maximum<NL_DOUBLE>()
#define NL_maximumF NL_maximum<NL_FLOAT >()


//-----------------------------------------------------------------------------------
//
// NL_minimum
//
//-----------------------------------------------------------------------------------
template< class T >
T NL_minimum()
{
  return( -NL_maximum<T>() );
}

template<> inline NL_UINT8  NL_minimum < NL_UINT8  >()  { return( 0 ); }
template<> inline NL_UINT16 NL_minimum < NL_UINT16 >()  { return( 0 ); }
template<> inline NL_UINT32 NL_minimum < NL_UINT32 >()  { return( 0 ); }
template<> inline NL_UINT64 NL_minimum < NL_UINT64 >()  { return( 0 ); }

#define NL_minimumD NL_minimum<NL_DOUBLE>()
#define NL_minimumF NL_minimum<NL_FLOAT >()


//-----------------------------------------------------------------------------------
//
// NL_minimumPositive
//
//-----------------------------------------------------------------------------------
template< class T >
T NL_minimumPositive()
{
  return( 1 );
}

template<> inline NL_FLOAT  NL_minimumPositive < NL_FLOAT  >() { return( FLT_MIN  ); }
template<> inline NL_DOUBLE NL_minimumPositive < NL_DOUBLE >() { return( DBL_MIN  ); }


#define NL_minimumPositiveD NL_minimumPositive<NL_DOUBLE>()
#define NL_minimumPositiveF NL_minimumPositive<NL_FLOAT >()

//-----------------------------------------------------------------------------------
//
// NL_abs:
//
//-----------------------------------------------------------------------------------

template <class T>
T NL_abs( const T& a )
{
  NL_PRAGMA_WARNING_PUSH
  NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional
  NL_PRAGMA_WARNING_DISABLE_Minus_Applied_to_Unsigned

  NL_ASSERT_IS_VALID( a );
  return( a < T(0) ? T(-a) : a );

  NL_PRAGMA_WARNING_POP
}

template<> inline NL_UINT64 NL_abs( const NL_UINT64& a ) { return( a ); }
template<> inline NL_UINT32 NL_abs( const NL_UINT32& a ) { return( a ); }
template<> inline NL_UINT16 NL_abs( const NL_UINT16& a ) { return( a ); }
template<> inline NL_UINT8  NL_abs( const NL_UINT8&  a ) { return( a ); }

template<> inline NL_DOUBLE NL_abs( const NL_DOUBLE& a ) { return( fabs (a) ); }
template<> inline NL_FLOAT  NL_abs( const NL_FLOAT&  a ) { return( fabsf(a) ); }

template <class T>
T NL_absDiff( const T& a, const T& b )
{
  NL_ASSERT_IS_VALID2( a, b );
  return( ( a > b ) ? ( a - b ) : ( b - a ) );
}


// [AG][TODO] at least for windows introduce:
// _copysign( double, double )
// _chgsign(  double x );
// __max( type a, type b );



//-----------------------------------------------------------------------------------
//
//  NL_isNull, NL_noNull
//
//-----------------------------------------------------------------------------------

// NL_isNull
template< class T > inline
NL_BOOL NL_isNull( const T* p )
{
  return( p == NULL );
}

// NL_noNull
template< class T > inline
NL_BOOL NL_noNull( const T* p )
{
  return( p != NULL );
}

#define if_isNull( a ) if ( NL_isNull( a ) )
#define if_noNull( a ) if ( NL_noNull( a ) )


//-----------------------------------------------------------------------------------
//
// NL_zero, NL_setZero, NL_isZero
//
//-----------------------------------------------------------------------------------
template< class T > inline
T NL_zero()
{
  return( T(0) );
}

// NL_setZero
template< class T > inline
void NL_setZero( T& a )
{
  a.setZero();
}

template<> inline void NL_setZero( NL_INT8&   a ) { a = 0; }
template<> inline void NL_setZero( NL_UINT8&  a ) { a = 0; }

template<> inline void NL_setZero( NL_INT16&  a ) { a = 0; }
template<> inline void NL_setZero( NL_UINT16& a ) { a = 0; }

template<> inline void NL_setZero( NL_INT32&  a ) { a = 0; }
template<> inline void NL_setZero( NL_UINT32& a ) { a = 0; }

template<> inline void NL_setZero( NL_INT64&  a ) { a = 0; }
template<> inline void NL_setZero( NL_UINT64& a ) { a = 0; }

template<> inline void NL_setZero( NL_FLOAT&  a ) { a = 0; }
template<> inline void NL_setZero( NL_DOUBLE& a ) { a = 0; }

// NL_isZero
template< class T > inline
NL_BOOL NL_isZero( const T& a )
{
  return( a.isZero() );
}

template<> inline NL_BOOL NL_isZero( const NL_INT8&   a ) { return( a == 0 ); }
template<> inline NL_BOOL NL_isZero( const NL_UINT8&  a ) { return( a == 0 ); }

template<> inline NL_BOOL NL_isZero( const NL_INT16&  a ) { return( a == 0 ); }
template<> inline NL_BOOL NL_isZero( const NL_UINT16& a ) { return( a == 0 ); }

template<> inline NL_BOOL NL_isZero( const NL_INT32&  a ) { return( a == 0 ); }
template<> inline NL_BOOL NL_isZero( const NL_UINT32& a ) { return( a == 0 ); }

template<> inline NL_BOOL NL_isZero( const NL_FLOAT&  a ) { return( a == 0 ); }
template<> inline NL_BOOL NL_isZero( const NL_DOUBLE& a ) { return( a == 0 ); }


//-----------------------------------------------------------------------------------
//
// NL_one
//
//-----------------------------------------------------------------------------------
template< class T > inline
T NL_one()
{
  return( T(1) );
}

template< class T > inline
void NL_setOne( T& a )
{
  a.set1();
}

template<> inline void NL_setOne( NL_INT8&  a  ) { a = 1; }
template<> inline void NL_setOne( NL_UINT8& a  ) { a = 1; }

template<> inline void NL_setOne( NL_INT16&  a ) { a = 1; }
template<> inline void NL_setOne( NL_UINT16& a ) { a = 1; }

template<> inline void NL_setOne( NL_INT32&  a ) { a = 1; }
template<> inline void NL_setOne( NL_UINT32& a ) { a = 1; }

template<> inline void NL_setOne( NL_FLOAT&  a ) { a = 1; }
template<> inline void NL_setOne( NL_DOUBLE& a ) { a = 1; }


//-----------------------------------------------------------------------------------
//
// NL_negate
//
//-----------------------------------------------------------------------------------

template< class T > inline
void NL_negate( T& a )
{
  a.negate();
}

template<> inline void NL_negate( NL_INT8&  a  ) { a = -a; }
template<> inline void NL_negate( NL_INT16&  a ) { a = -a; }
template<> inline void NL_negate( NL_INT32&  a ) { a = -a; }

template<> inline void NL_negate( NL_UINT8&  ) { NL_BREAKPOINT; }
template<> inline void NL_negate( NL_UINT16& ) { NL_BREAKPOINT; }
template<> inline void NL_negate( NL_UINT32& ) { NL_BREAKPOINT; }

template<> inline void NL_negate( NL_FLOAT&  a ) { a = -a; }
template<> inline void NL_negate( NL_DOUBLE& a ) { a = -a; }


//-----------------------------------------------------------------------------------
//
// NL_epsilon
//
//-----------------------------------------------------------------------------------
template< class T> inline
T NL_epsilon()
{
  NL_BREAKPOINT;
  return( T(0) );
}

template<> inline NL_FLOAT  NL_epsilon <NL_FLOAT > () { return( FLT_EPSILON ); }
template<> inline NL_DOUBLE NL_epsilon <NL_DOUBLE> () { return( DBL_EPSILON ); }

template< class T>
T NL_epsilon( const T& epsilonMultiplier )
{
  return( NL_epsilon<T>() * epsilonMultiplier );
}

#define NL_epsilonF ( NL_epsilon<NL_FLOAT  >() )
#define NL_epsilonD ( NL_epsilon<NL_DOUBLE >() )



//-----------------------------------------------------------------------------------
//
// NL_epsilonSq, NL_epsilonSqSq, NL_epsilonSqrt
//
//-----------------------------------------------------------------------------------
template <class T>
T NL_sq( const T& a )
{
  NL_ASSERT_IS_VALID( a );
  return( a * a );
}
  
template< class T>
T NL_epsilonSq()
{
  return( NL_sq( NL_epsilon<T>() ) );
}

template< class T>
T NL_epsilonSq( const T& epsilonMultiplier )
{
  return( NL_sq( NL_epsilon<T>( epsilonMultiplier ) ) );
}

#define NL_epsilonSqF ( NL_epsilonSq<NL_FLOAT  >() )
#define NL_epsilonSqD ( NL_epsilonSq<NL_DOUBLE >() )

template< class T>
T NL_epsilonSqSq()
{
  return( NL_sq( NL_epsilonSq<T>() ) );
}

#define NL_epsilonSqSqF ( NL_epsilonSqSq<NL_FLOAT  >() )
#define NL_epsilonSqSqD ( NL_epsilonSqSq<NL_DOUBLE >() )

template< class T>
T NL_epsilonSqrt()
{
  return( T( sqrt( NL_epsilon<T>() ) ) );
}

template< class T>
T NL_epsilonSqrt( const T& epsilonMultiplier )
{
  return( T( sqrt( NL_epsilon<T>( epsilonMultiplier ) ) ) );
}

#define NL_epsilonSqrtF ( NL_epsilonSqrt<NL_FLOAT  >() )
#define NL_epsilonSqrtD ( NL_epsilonSqrt<NL_DOUBLE >() )


//-----------------------------------------------------------------------------------
//
// NL_increaseMinimally, NL_decreaseMinimally
//
// Return value changed as indicated, with the minimum possible change
//
//-----------------------------------------------------------------------------------
template< class T >
inline T NL_increaseMinimally( const T& x )
{
  NL_BREAKPOINT;
  NL_VARIABLE_MAYBE_NOT_REFERENCED( x );
  return( T(0) );
}

template<>
inline NL_FLOAT NL_increaseMinimally <NL_FLOAT > ( const NL_FLOAT& x )
{
  NL_ASSERT ( x < NL_maximumF );

  NL_FLOAT retVal = x;
  if ( x == 0.0f )
  {
    retVal = FLT_MIN;
  }
  else
  {
    retVal += NL_abs( x ) * NL_epsilonF;
  }

  // changed and minimum change?
  NL_ASSERT ( retVal > x );
  NL_ASSERT ( x + ( retVal - x ) * 0.95f == x );

  return ( retVal );
}

template<>
inline NL_DOUBLE NL_increaseMinimally <NL_DOUBLE> ( const NL_DOUBLE& x )
{
  NL_ASSERT ( x < NL_maximumD );

  NL_DOUBLE retVal = x;
  if ( x == 0.0f )
  {
    retVal = DBL_MIN;
  }
  else
  {
    retVal += NL_abs( x ) * NL_epsilonD;
  }

  // changed and minimum change?
  NL_ASSERT ( retVal > x );
  NL_ASSERT ( x + ( retVal - x ) * 0.95 == x );

  return ( retVal );
}

template< class T >
inline T NL_decreaseMinimally( const T& x )
{
  NL_VARIABLE_MAYBE_NOT_REFERENCED( x )
  NL_BREAKPOINT;
  return( T(0) );
}

template<>
inline NL_FLOAT NL_decreaseMinimally <NL_FLOAT > ( const NL_FLOAT& x )
{
  NL_ASSERT ( x > NL_minimumF );

  NL_FLOAT retVal = x;
  if ( x == 0.0f )
  {
    retVal = -FLT_MIN;
  }
  else
  {
    retVal -= NL_abs( x ) * NL_epsilonF;
  }

  // changed and minimum change?
  NL_ASSERT ( retVal < x );
  NL_ASSERT ( x - ( retVal - x ) * 0.95f == x );

  return ( retVal );
}

template<>
inline NL_DOUBLE NL_decreaseMinimally <NL_DOUBLE > ( const NL_DOUBLE& x )
{
  NL_ASSERT ( x > NL_minimumD );

  NL_DOUBLE retVal = x;
  if ( x == 0.0f )
  {
    retVal = -DBL_MIN;
  }
  else
  {
    retVal -= NL_abs( x ) * NL_epsilonD;
  }

  // changed and minimum change?
  NL_ASSERT ( retVal < x );
  NL_ASSERT ( x - ( retVal - x ) * 0.95 == x );

  return ( retVal );
}


//-----------------------------------------------------------------------------------
//
// NL_epsilonNormalizer, NL_max10Exp
//
//-----------------------------------------------------------------------------------
template< class T> inline
T NL_epsilonNormalizer()
{
  NL_ASSERT( NULL );
  return( T(0) );
}

template<> inline NL_FLOAT  NL_epsilonNormalizer <NL_FLOAT>  () { return( 1.0e-14F ); }
template<> inline NL_DOUBLE NL_epsilonNormalizer <NL_DOUBLE> () { return( 1.0e-28 ); }

template< class T> inline
T NL_epsilonNormalizerSq()
{
  return( NL_sq( NL_epsilonNormalizer<T>() ) );
}


template< class T> inline
T NL_max10Exp()
{
  NL_BREAKPOINT;
  return( T(0) );
}

template<> inline NL_FLOAT  NL_max10Exp <NL_FLOAT>  () { return( FLT_MAX_10_EXP ); }
template<> inline NL_DOUBLE NL_max10Exp <NL_DOUBLE> () { return( DBL_MAX_10_EXP ); }


//-----------------------------------------------------------------------------------
//
// NL_normalizeAllowedBy, NL_divisorAllowed, NL_divisionAllowed
//
//-----------------------------------------------------------------------------------
template< class T>
NL_BOOL NL_normalizeAllowedBy( const T& divisor )
{
  return( divisor > NL_epsilonNormalizer<T>() );
}

template< class T>
NL_BOOL NL_divisorAllowed( const T& divisor )
{
  return( NL_abs( divisor ) > NL_epsilonNormalizer<T>() );
}

template< class T>
NL_BOOL NL_divisionAllowed( const T& number, const T& divisor )
{
  if( divisor == T( 0 ) )
  {
    return_false;
  }

  NL_DOUBLE numberLog  = log10( NL_abs( number  ) );
  NL_DOUBLE divisorLog = log10( NL_abs( divisor ) );
  return( NL_abs( numberLog - divisorLog ) < NL_max10Exp<T>() );
}


//-----------------------------------------------------------------------------------
//
// NL_1k, NL_2k, NL_4k, ...
//
//-----------------------------------------------------------------------------------

#define NL_1k 1024
#define NL_2k 2048
#define NL_4k 4096
#define NL_8k 8192

#define NL_16k 16384
#define NL_32k 32768
#define NL_64k 65536

#define NL_128k 131072
#define NL_256k 262144
#define NL_512k 524288

#define NL_1M 1048576
#define NL_2M 2097152
#define NL_4M 4194304
#define NL_8M 8388608

#define NL_16M 16777216
#define NL_32M 33554432
#define NL_64M 67108864

#define NL_128M 134217728
#define NL_256M 268435456
#define NL_512M 536870912

#define NL_1G 1073741824
#define NL_4G 4294967296
#define NL_8G 8589934592


//-----------------------------------------------------------------------------------
//
// Remove const
//
//-----------------------------------------------------------------------------------
template< class T >
T& NL_removeConst( const T& val )
{
  return ( const_cast<T&>( val ) );
}

template< class T >
T*& NL_removeConst( const T*& val )
{
  return ( const_cast<T*&>( val ) );
}

template< class T >
T*& NL_removeConst( const T* const& val )
{
  return ( const_cast<T*&>( val ) );
}



//-----------------------------------------------------------------------------------
//
// formal classes YES, NO, CAST, NORMALIZE, SORT, SAFE, NL_INIT, NEXT, PREV...
// 0-9 ( classes INDEXOR )
//
//-----------------------------------------------------------------------------------
class NL_YES               {};
class NL_NO                {};
class NL_CAST              {};
class NL_CAST_NUMBER: public NL_CAST {};
class NL_NORMALIZE         {};
class NL_NORMALIZE_SAFE    {};
class NL_NORMALIZE_TRY     {};
class NL_SORT              {};
class NL_SAFE              {};
class NL_CHECK             {};
class NL_INIT              {};
class NL_INIT_NULL         {};
class NL_INIT_TO_0         {};
class NL_INIT_TO_1         {};
class NL_INIT_TO_NOT_FOUND {};
class NL_INIT_TO_MAXIMUM   {};
class NL_INIT_BY_CENTER    {};
class NL_BEGIN             {};
class NL_END               {};
class NL_FAST              {};
class NL_NEXT_LINEAL       {};
class NL_PREV_LINEAL       {};
class NL_NEXT_CIRCULAR     {};
class NL_PREV_CIRCULAR     {};
class NL_READ              {};
class NL_WRITE             {};
class NL_INVERSE           {};
class NL_TRANSPOSED        {};
class NL_DELTA             {};
class NL_CONJUGATE         {};
class NL_INTERSECT         {};
class NL_ASSIGN_ID         {};
class NL_INIT_TO_NEGATIVE  {};
class NL_SOLID             {};
class NL_SHELL             {};

class NL_0 {};
class NL_1 {};
class NL_2 {};
class NL_3 {};
class NL_4 {};
class NL_5 {};
class NL_6 {};
class NL_7 {};
class NL_8 {};
class NL_9 {};

#if defined( __GNUC__) && (__GNUC__ < 4 )
  #define NL_USE_CLASS_PARENTHESIS
#endif
#if defined NL_USE_CLASS_PARENTHESIS
  #define nl_yes               NL_YES()
  #define nl_no                NL_NO()
  #define nl_cast              NL_CAST()
  #define nl_cast_number       NL_CAST_NUMBER()
  #define nl_normalize         NL_NORMALIZE()
  #define nl_normalize_safe    NL_NORMALIZE_SAFE()
  #define nl_normalize_try     NL_NORMALIZE_TRY()
  #define nl_sort              NL_SORT()
  #define nl_safe              NL_SAFE()
  #define nl_check             NL_CHECK()
  #define nl_init              NL_INIT()
  #define nl_init_null         NL_INIT_NULL()
  #define nl_init_to_0         NL_INIT_TO_0()
  #define nl_init_to_1         NL_INIT_TO_1()
  #define nl_init_to_not_found NL_INIT_TO_NOT_FOUND()
  #define nl_init_to_maximum   NL_INIT_TO_MAXIMUM()
  #define nl_init_by_center    NL_INIT_BY_CENTER()
  #define nl_begin             NL_BEGIN()
  #define nl_end               NL_END()
  #define nl_fast              NL_FAST()
  #define nl_next_lineal       NL_NEXT_LINEAL  ()
  #define nl_prev_lineal       NL_PREV_LINEAL  ()
  #define nl_next_circular     NL_NEXT_CIRCULAR()
  #define nl_prev_circular     NL_PREV_CIRCULAR()
  #define nl_copy              NL_NEXT()
  #define nl_prev              NL_PREV()
  #define nl_read              NL_READ()
  #define nl_write             NL_WRITE()
  #define nl_inverse           NL_INVERSE()
  #define nl_delta             NL_DELTA()
  #define nl_conjugate         NL_CONJUGATE()
  #define nl_intersect         NL_INTERSECT()
  #define nl_assign_id         NL_ASSIGN_ID()
  #define nl_init_to_negative  NL_INIT_TO_NEGATIVE()
  #define nl_solid             NL_SOLID()
  #define nl_shell             NL_SHELL()

  #define nl_0 NL_0()
  #define nl_1 NL_1()
  #define nl_2 NL_2()
  #define nl_3 NL_3()
  #define nl_4 NL_4()
  #define nl_5 NL_5()
  #define nl_6 NL_6()
  #define nl_7 NL_7()
  #define nl_8 NL_8()
  #define nl_9 NL_9()
#else
  #define nl_yes               (NL_YES())
  #define nl_no                (NL_NO())
  #define nl_cast              (NL_CAST())
  #define nl_cast_number       (NL_CAST_NUMBER())
  #define nl_normalize         (NL_NORMALIZE())
  #define nl_normalize_safe    (NL_NORMALIZE_SAFE())
  #define nl_normalize_try     (NL_NORMALIZE_TRY())
  #define nl_sort              (NL_SORT())
  #define nl_safe              (NL_SAFE())
  #define nl_check             (NL_CHECK())
  #define nl_init              (NL_INIT())
  #define nl_init_null         (NL_INIT_NULL())
  #define nl_init_to_0         (NL_INIT_TO_0())
  #define nl_init_to_1         (NL_INIT_TO_1())
  #define nl_init_to_not_found (NL_INIT_TO_NOT_FOUND())
  #define nl_init_to_maximum   (NL_INIT_TO_MAXIMUM())
  #define nl_init_by_center    (NL_INIT_BY_CENTER())
  #define nl_begin             (NL_BEGIN())
  #define nl_end               (NL_END())
  #define nl_fast              (NL_FAST())
  #define nl_next_lineal       (NL_NEXT_LINEAL())
  #define nl_prev_lineal       (NL_PREV_LINEAL())
  #define nl_next_circular     (NL_NEXT_CIRCULAR())
  #define nl_prev_circular     (NL_PREV_CIRCULAR())
  #define nl_read              (NL_READ())
  #define nl_write             (NL_WRITE())
  #define nl_inverse           (NL_INVERSE())
  #define nl_transposed        (NL_TRANSPOSED())
  #define nl_delta             (NL_DELTA())
  #define nl_conjugate         (NL_CONJUGATE())
  #define nl_intersect         (NL_INTERSECT())
  #define nl_assign_id         (NL_ASSIGN_ID())
  #define nl_init_to_negative  (NL_INIT_TO_NEGATIVE())
  #define nl_solid             (NL_SOLID())
  #define nl_shell             (NL_SHELL())

  #define nl_0 (NL_0())
  #define nl_1 (NL_1())
  #define nl_2 (NL_2())
  #define nl_3 (NL_3())
  #define nl_4 (NL_4())
  #define nl_5 (NL_5())
  #define nl_6 (NL_6())
  #define nl_7 (NL_7())
  #define nl_8 (NL_8())
  #define nl_9 (NL_9())
#endif


#define NL_CULLING_YES NL_YES
#define NL_CULLING_NO  NL_NO

#define nl_culling_yes nl_yes
#define nl_culling_no  nl_no


template< class T >
NL_BOOL getBool()
{
  NL_BREAKPOINT;
  return_false;
}

template<> inline NL_BOOL getBool< NL_YES >() { return_true;  }
template<> inline NL_BOOL getBool< NL_NO  >() { return_false; }


template< class T >
NL_BOOL isAffimartion()
{
  NL_BREAKPOINT;
  return_false;
}

template<> inline NL_BOOL isAffimartion< NL_YES >() { return_true;  }
template<> inline NL_BOOL isAffimartion< NL_NO  >() { return_true; }


//-----------------------------------------------------------------------------------
//
// NL_CopyMode:
//
//-----------------------------------------------------------------------------------

enum NL_CopyMode
{
  Shallow = 0,
  Deep,
  Lazy
};


//-----------------------------------------------------------------------------------
//
// NL_Access:
//
//-----------------------------------------------------------------------------------

enum NL_Access
{
  R_Allocation = 0,
  R_Element,
  W_Element,
  W_Allocation
};

class _Ra { public: static const NL_Access val_ = R_Allocation; };
class _Re { public: static const NL_Access val_ = R_Element;    };
class _We { public: static const NL_Access val_ = W_Element;    };
class _Wa { public: static const NL_Access val_ = W_Allocation; };


#if defined NL_USE_CLASS_PARENTHESIS
#define _ra _Ra()
#define _re _Re()
#define _we _We()
#define _wa _Wa()
#else
#define _ra (_Ra())
#define _re (_Re())
#define _we (_We())
#define _wa (_Wa())
#endif


// NL_isAllowed
template< class T_ACCESS,
class U_ACCESS >
NL_BOOL NL_majorEqual( const T_ACCESS,
                       const U_ACCESS )
{
NL_PRAGMA_WARNING_PUSH
NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional
  return( T_ACCESS::val_ >= U_ACCESS::val_ );
NL_PRAGMA_WARNING_POP
}


// NL_ASSERT_ACCESS( acces_available, accessRequired )
#define NL_ASSERT_ACCESS( T_ACCESS_AVAILABLE, T_ACCESS_REQUIRED ) \
NL_ASSERT( NL_majorEqual( T_ACCESS_AVAILABLE(), T_ACCESS_REQUIRED() ) );


//-----------------------------------------------------------------------------------
//
// EXTRACT: template class to extract the scalar class of other
//
//-----------------------------------------------------------------------------------
template< class T_CLASS>
class NL_EXTRACT
{
  typedef T_CLASS SCALAR;
};

//-----------------------------------------------------------------------------------
//
// OBJECT MANAGEMENT
//
//-----------------------------------------------------------------------------------
template<class T>
T& NL_dereference( T* pT )
{
  NL_ASSERT( pT );
  return( *pT );
}

template<class T>
const T& NL_dereferenceConst( const T* pT )
{
  NL_ASSERT( pT );
  return( *pT );
}

template<class T>
T& NL_dereference( void* pT )
{
  NL_ASSERT( pT != NULL );
  return( *((T*)pT ) );
}

template<class T>
const T& NL_dereferenceConst( const void* pT )
{
  NL_ASSERT( pT != NULL );
  return( *((T*)pT ) );
}

template<class T, class U>
NL_BOOL NL_areTheSameObject( const T& rT, const U& rU )
{
  return( (void*) &rT == (void*) &rU );
}

template<class T, class U>
NL_BOOL NL_notTheSameObject( const T& rT, const U& rU )
{
  return( (void*) &rT != (void*) &rU );
}

template<class T, class U>
NL_BOOL NL_areTheSameObject( const T* pT, const U* pU )
{
  // DANGER: use objects not pointers to call NL_areTheSameObject!!!
  NL_BREAKPOINT;
  return( (void*) pT == (void*) pU );
}

template<class T, class U>
NL_BOOL NL_notTheSameObject( const T* pT, const U* pU )
{
  // DANGER: use objects not pointers to call NL_notTheSameObject!!!
  NL_BREAKPOINT;
  return( (void*) pT != (void*) pU );
}

//-----------------------------------------------------------------------------------
//
// NL_isPointer
//
//-----------------------------------------------------------------------------------
template<class T> NL_BOOL NL_isPointerAux( const T* const & ) { return( NL_true  ); }
template<class T> NL_BOOL NL_isPointerAux( const T* & )       { return( NL_true  ); }
template<class T> NL_BOOL NL_isPointerAux( T* const & )       { return( NL_true  ); }
template<class T> NL_BOOL NL_isPointerAux( T*& )              { return( NL_true  ); }
template<class T> NL_BOOL NL_isPointerAux( const T& )         { return( NL_false ); }


template< class T>
NL_BOOL NL_isPointer()
{
  T* p_T = NULL;
  return( NL_isPointerAux( *p_T ) );
}


//-----------------------------------------------------------------------------------
//
// NL_sizeof: Return the size of the type
//
//-----------------------------------------------------------------------------------
template < class T>
NL_UINT32 NL_sizeof()
{
  return( NL_UINT32( sizeof( T ) ) );
}


//-----------------------------------------------------------------------------------
//
// NL_sizeofBits: Return the size of the type in bits
//
//-----------------------------------------------------------------------------------
template < class T>
NL_UINT32 NL_sizeofBits()
{
  return ( NL_sizeof<T>() * NL_UINT32( 8 ) );
}


//-----------------------------------------------------------------------------------
//
// NL_cast
//
//-----------------------------------------------------------------------------------
template<class T, class U>
T NL_cast( const U& value )
{
  return ( static_cast<T>( value ) );
}

template<class T, class U>
T NL_cast( U& value )
{
  return ( static_cast<T>( value ) );
}


//-----------------------------------------------------------------------------------
//
// NL_reinterpretRef
//
//-----------------------------------------------------------------------------------
template< class T_NEW, class T_ORIG >
const T_NEW& NL_reinterpretRef( const T_ORIG& value )
{
  NL_ASSERT( sizeof( T_NEW ) <= sizeof( T_ORIG ) );
  return ( *( (const T_NEW*) ( &value ) ) );
}

template< class T_NEW, class T_ORIG >
T_NEW& NL_reinterpretRef( T_ORIG& value )
{
  NL_ASSERT( sizeof( T_NEW ) <= sizeof( T_ORIG ) );
  return ( *( (T_NEW*) ( &value ) ) );
}


//-----------------------------------------------------------------------------------
//
// NL_castToInterface
// Only use for auto-casting members of T_INTERFACE_FROM to its interfaces !!!
//
//-----------------------------------------------------------------------------------
template <class T_INTERFACE_TO, class T_INTERFACE_FROM>
const T_INTERFACE_TO& NL_castToInterface( const T_INTERFACE_FROM* pT )
{
  NL_PRAGMA_WARNING_PUSH
  NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional
  NL_ASSERT( sizeof( T_INTERFACE_FROM ) == sizeof( T_INTERFACE_TO ) );
  return( *( (T_INTERFACE_TO*) pT ) );
  NL_PRAGMA_WARNING_POP
}


//-----------------------------------------------------------------------------------
//
// T_IF formal classes conditional if
// Allow choose class between two using a bool
//
// Example:
// typedef typename T_IF< (N>1), T_CLASS_FOR_N_EQUAL_1, T_CLASS_FOR_N_BIGGER_THAN_1 >::T_SELECTED T_CLASS_CHOOSEN;
// T_CLASS_CHOOSEN objOfClassChoosen;
//
//-----------------------------------------------------------------------------------

template <NL_BOOL, class T_THEN, class T_ELSE>
struct T_IF
{
  typedef void T_SELECTED;
};

template <class T_THEN, class T_ELSE>
struct T_IF<NL_true, T_THEN, T_ELSE>
{
  typedef T_THEN T_SELECTED;
};

template <class T_THEN, class T_ELSE>
struct T_IF<NL_false, T_THEN, T_ELSE>
{
  typedef T_ELSE T_SELECTED;
};

//-----------------------------------------------------------------------------------
//
// TYPE_DETAIL
// formal description of a class
//
//-----------------------------------------------------------------------------------

template < class T >
class T_DETAIL_OBJ
{
  public:
  typedef T     TYPE_OBJ;
  typedef T*    TYPE_PTR;
  typedef T     TYPE_T;
  typedef NL_NO TYPE_IS_PTR;
};

template < class T >
class T_DETAIL_PTR
{
  public:
  typedef T       TYPE_OBJ;
  typedef T*      TYPE_PTR;
  typedef T*      TYPE_T;
  typedef NL_YES  TYPE_IS_PTR;
};

template < class T >
class T_DETAIL {};


#define NL_DETAIL_DECLARATION( className )  \
template<> class T_DETAIL<className >:public T_DETAIL_OBJ<className> {};  \
template<> class T_DETAIL<className*>:public T_DETAIL_PTR<className> {}


  // EXAMPLE USE T_DETAIL:
  //
  // NL_DETAIL_DECLARATION( Vector3F );
  // T_DETAIL<Vector3F >::TYPE_OBJ v; // v  is a Vector3F
  // T_DETAIL<Vector3F*>::TYPE_OBJ w; // w  is a Vector3F
  // T_DETAIL<Vector3F >::TYPE_T tv;  // tv is a Vector3F
  // T_DETAIL<Vector3F*>::TYPE_T tw;  // tw is a Vector3F*


//-----------------------------------------------------------------------------------
//
// comparators: default function-objects to compare
//
//-----------------------------------------------------------------------------------

//
// NL_ComparatorDefault:
template< class T >
class NL_ComparatorDefault
{
  public:

  // equals
  NL_BOOL equals( const T& a, const T& b ) const
  {
    return( a == b );
  }

  // strict comparator
  NL_BOOL strict( const T& a, const T& b ) const
  {
    return( a < b );
  }

  // no strict comparator
  NL_BOOL operator() ( const T& a, const T& b ) const
  {
    return( a <= b );
  }
};

//
// NL_ComparatorBackwardsDefault:
template< class T >
class NL_ComparatorBackwardsDefault
{
  public:

  // equals
  NL_BOOL equals( const T& a, const T& b ) const
  {
    return( a == b );
  }

  // strict comparator
  NL_BOOL strict( const T& a, const T& b ) const
  {
    return( a > b );
  }

  // no strict comparator
  NL_BOOL operator() ( const T& a, const T& b ) const
  {
    return( a >= b );
  }
};


//
// NL_ComparatorWithAsserts:
template< class T, class T_COMPARATOR >
class NL_ComparatorAssertingConsistency
{
  public:

    NL_ComparatorAssertingConsistency( T_COMPARATOR& cmp )
    : cmp_( cmp )
    {
    }

    // equals
    NL_BOOL equals( const T& a, const T& b ) const
    {
      NL_BOOL res = cmp_.equals(a,b);
      NL_ASSERT( res == ( cmp_(a,b) && !cmp_.strict(a,b) ) );
      return res;
    }

    // strict comparator
    NL_BOOL strict( const T& a, const T& b ) const
    {
      NL_BOOL res = cmp_.strict(a,b);
      NL_ASSERT( res == ( !cmp_.equals(a,b) && cmp_(a,b) ) );
      return res;
    }

    // no strict comparator
    NL_BOOL operator() ( const T& a, const T& b ) const
    {
      NL_BOOL res = cmp_(a,b);
      NL_ASSERT( res == ( cmp_.equals(a,b) || cmp_.strict(a,b) ) );
      return res;
    }
  private:
    T_COMPARATOR cmp_;
};


//-----------------------------------------------------------------------------------
//
// std compare functions:
//
//-----------------------------------------------------------------------------------
inline
int stdCompareUint32( const NL_UINT32* px,
                      const NL_UINT32* py )
{
  if ( *px < *py ) return -1;
  if ( *px > *py ) return +1;
  return 0;
}

inline
int stdCompareUint64( const NL_UINT64* px,
                      const NL_UINT64* py )
{
  if ( *px < *py ) return -1;
  if ( *px > *py ) return +1;
  return 0;
}

inline
int stdCompareInt32( const NL_INT32* px,
                     const NL_INT32* py )
{
  if ( *px < *py ) return -1;
  if ( *px > *py ) return +1;
  return 0;
}

inline
int stdCompareInt64( const NL_INT64* px,
                     const NL_INT64* py )
{
  if ( *px < *py ) return -1;
  if ( *px > *py ) return +1;
  return 0;
}

inline
int stdCompareFloat( const NL_FLOAT* px,
                     const NL_FLOAT* py )
{
  if ( *px < *py ) return -1;
  if ( *px > *py ) return +1;
  return 0;
}

inline
int stdCompareDouble( const NL_DOUBLE* px,
                      const NL_DOUBLE* py )
{
  if ( *px < *py ) return -1;
  if ( *px > *py ) return +1;
  return 0;
}


//-----------------------------------------------------------------------------------
//
// NL_wasteCpu
//
//-----------------------------------------------------------------------------------
inline void NL_wasteCpu( NL_UINT32 n )
{
  static NL_UINT32 withoutUse = 0;
  for ( NL_UINT32 i=0; i<n; ++i )
  {
    withoutUse ^= i;
    withoutUse += i;
  }
}

//-----------------------------------------------------------------------------------
//
// Ret
// use Ret<T_VALUE> for return T_VALUE in function asserting T_VALUE is received for the caller 
//
//-----------------------------------------------------------------------------------
#ifdef _DEBUG_WITH_ASSERT
template<class T>
class Ret
{
public:

  Ret( const T& t ):object_( t ), received_( NL_false ) {}
 ~Ret() { NL_ASSERT( received_ ); }
  operator const T&() { received_ = NL_true; return( object_ ); }

  T object_;
  NL_BOOL received_;
};
#else
template<class T>
class Ret: public T
{
public:

  Ret( const T& t ):T( t ) {}
  //operator const T&() { return( *this ); }

  //T object_;
};
#endif


//-----------------------------------------------------------------------------------
//
// DIRTY
//
//-----------------------------------------------------------------------------------
NL_PRAGMA_WARNING_PUSH
NL_PRAGMA_WARNING_DISABLE_Constant_In_Conditional
NL_PRAGMA_WARNING_DISABLE_Truncation_Constant_Value

/// NL_isDirty
template <class T>
NL_BOOL NL_isDirty( const T& t )
{
  if ( sizeof(T) >= 8 )
  {
    return( *( (NL_UINT64*) &t ) == 0xffffffffffffffffULL );
  }
  else
  {
    NL_ASSERT( sizeof(T) >= 4 );
    return( *( (NL_UINT32*) &t ) == 0xFFFFFFFF );
  }
}

/// NL_noDirty
template <class T>
NL_BOOL NL_noDirty( const T& t )
{
  if ( sizeof(T) >= 8 )
  {
    return( *( (NL_UINT64*) &t ) != 0xffffffffffffffffULL  );
  }
  else
  {
    NL_ASSERT( sizeof(T) >= 4 );
    return( *( (NL_UINT32*) &t ) != 0xFFFFFFFF );
  }
}

/// NL_setDirty
template <class T>
void NL_setDirty( T& t )
{
  if ( sizeof(T) >= 8 )
  {
    *( (NL_UINT64*) &t ) = 0xffffffffffffffffULL;
  }
  else
  {
    NL_ASSERT( sizeof(T) >= 4 );
    *( (NL_UINT32*) &t ) = 0xFFFFFFFF;
  }
}

/// NL_getDirty
template <class T>
T NL_getDirty( void )
{
  if ( sizeof(T) >= 8 )
  {
    return( (NL_UINT64) 0xffffffffffffffffULL );
  }

  NL_ASSERT( sizeof(T) >= 4 );
  return ( (NL_UINT32) 0xFFFFFFFF );
}

/// NL_getDirty explicit instantiations
template <>
inline NL_UINT64 NL_getDirty( void )
{
  NL_ASSERT( sizeof(NL_UINT64) == 8 );
  return( (NL_UINT64) 0xffffffffffffffffULL );
}

template <>
inline NL_UINT32 NL_getDirty( void )
{
  NL_ASSERT( sizeof(NL_UINT32) == 4 );
  return( (NL_UINT32) 0xffffffff );
}

template <>
inline NL_UINT16 NL_getDirty( void )
{
  NL_ASSERT( sizeof(NL_UINT16) == 2 );
  return ( (NL_UINT16) 0xffff );
}

#define if_noDirty( a ) if ( NL_noDirty( a ) )

/// dirty pointer
template < class T >
T* NL_getDirtyPointer ()
{
  return( (T*) ( (void*) (-1) ) );
}

NL_PRAGMA_WARNING_POP


//-----------------------------------------------------------------------------------
//
// STD VECTOR HELPERS
//
//-----------------------------------------------------------------------------------

#define DECLARE_STD_VECTOR_TYPES( type, name ) \
  typedef std::vector<type> Arr##name; \
  typedef Arr##name::iterator Arr##name##_it; \
  typedef Arr##name::const_iterator Arr##name##_cit;

//-----------------------------------------------------------------------------------
//
// STD LIST HELPERS
//
//-----------------------------------------------------------------------------------

#define DECLARE_STD_LIST_TYPES( type, name ) \
  typedef std::list<type> List##name; \
  typedef List##name::iterator List##name##_it; \
  typedef List##name::const_iterator List##name##_cit;

//-----------------------------------------------------------------------------------
//
// STD MAP HELPERS
//
//-----------------------------------------------------------------------------------

#define DECLARE_STD_MAP_TYPES( key, type, name ) \
  typedef std::map< key, type > Map##name; \
  typedef std::pair< key, type > Pair##name; \
  typedef Map##name::iterator Map##name##_it; \
  typedef Map##name::const_iterator Map##name##_cit; \
  typedef std::pair< Map##name##_it, NL_BOOL > Result##name;

//-----------------------------------------------------------------------------------
//
// STD MAP HELPERS
//
//-----------------------------------------------------------------------------------

#define DECLARE_STD_MAP_TYPES_USE_TYPENAME( key, type, name ) \
  typedef std::map< key, type > Map##name; \
  typedef std::pair< key, type > Pair##name; \
  typedef typename Map##name::iterator Map##name##_it; \
  typedef typename Map##name::const_iterator Map##name##_cit; \
  typedef std::pair< Map##name##_it, NL_BOOL > Result##name;

//-----------------------------------------------------------------------------------
//
// CLASS ATTRIBUTES
//
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_SET
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_SET( name_uc, name_lc, type )                  \
  void set##name_uc( const type& name_lc ) { name_lc##_ = name_lc; }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET( name_uc, name_lc, type )                  \
  const type& get##name_uc( void ) const {  return( name_lc##_ ); }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_PTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_PTR( name_uc, name_lc, type )                  \
  type* get##name_uc( void ) const {  return( name_lc##_ ); }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_SET_PTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_SET_PTR( name_uc, name_lc, type )        \
  type* get##name_uc( void ) const {  return( name_lc##_ ); }     \
  void set##name_uc( type* name_lc ) { name_lc##_ = name_lc; }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF_SET_PTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF_SET_PTR( name_uc, name_lc, type )        \
  type* get##name_uc( void ) const {  return( name_lc##_ ); }     \
  type*& ref##name_uc( void ) {  return( name_lc##_ ); }                     \
  void set##name_uc( type* name_lc ) { name_lc##_ = name_lc; }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_VALPTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_VALPTR( name_uc, name_lc, type )        \
  const type* get##name_uc( void ) const {  return( name_lc##_ ); }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_SET_VALPTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_SET_VALPTR( name_uc, name_lc, type )        \
  const type* get##name_uc( void ) const {  return( name_lc##_ ); }     \
  void set##name_uc( type* name_lc ) { name_lc##_ = name_lc; }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF_SET_VALPTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF_SET_VALPTR( name_uc, name_lc, type )        \
  const type* get##name_uc( void ) const {  return( name_lc##_ ); }     \
  type* ref##name_uc( void ) {  return( name_lc##_ ); }                     \
  void set##name_uc( type* name_lc ) { name_lc##_ = name_lc; }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF_VALPTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF_VALPTR( name_uc, name_lc, type )        \
  const type* get##name_uc( void ) const {  return( name_lc##_ ); }     \
  type* ref##name_uc( void ) {  return( name_lc##_ ); }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF_SET_MODI_VALPTR
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF_SET_MODI_VALPTR( name_uc, name_lc, type )             \
  const type* get##name_uc( void ) const {  return( name_lc##_ ); }     \
  type* ref##name_uc( void ) {  return( name_lc##_ ); }                     \
  {                                                                         \
    setModified( NL_true );                                                 \
    return( name_lc##_ );                                                   \
  }                                                                         \
  void set##name_uc( type* name_lc ) { name_lc##_ = name_lc; }              \
  {                                                                         \
    name_lc##_ = name_lc;                                                   \
    setModified( NL_true );                                                 \
  }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_SET
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_SET( name_uc, name_lc, type )                  \
  const type& get##name_uc( void ) const {  return( name_lc##_ ); }     \
  void set##name_uc( const type& name_lc ) { name_lc##_ = name_lc; }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF_SET
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF_SET( name_uc, name_lc, type )                  \
  const type& get##name_uc( void ) const {  return( name_lc##_ ); }         \
  type& ref##name_uc( void ) {  return( name_lc##_ ); }                     \
  void set##name_uc( const type& name_lc ) { name_lc##_ = name_lc; }


//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_SET_MODI
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_SET_MODI( name_uc, name_lc, type )             \
  const type& get##name_uc( void ) const {  return( name_lc##_ ); }         \
  void set##name_uc( const type& name_lc )                                  \
  {                                                                         \
    name_lc##_ = name_lc;                                                   \
    setModified( NL_true );                                                 \
  }


//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF_SET_MODI
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF_SET_MODI( name_uc, name_lc, type )             \
  const type& get##name_uc( void ) const {  return( name_lc##_ ); }         \
  type& ref##name_uc( void )                                                \
  {                                                                         \
    setModified( NL_true );                                                 \
    return( name_lc##_ );                                                   \
  }                                                                         \
  void set##name_uc( const type& name_lc )                                  \
  {                                                                         \
    name_lc##_ = name_lc;                                                   \
    setModified( NL_true );                                                 \
  }


//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_GET_REF
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_GET_REF( name_uc, name_lc, type )                  \
  const type& get##name_uc( void ) const {  return( name_lc##_ ); }         \
  type& ref##name_uc( void ) {  return( name_lc##_ ); }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_IS
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_IS( name_uc )                  \
  NL_BOOL is##name_uc( void ) const {  return( is##name_uc##_ ); }

//-----------------------------------------------------------------------------------
//
// NL_IMPLEMENT_IS_SET
//
//-----------------------------------------------------------------------------------

#define NL_IMPLEMENT_IS_SET( name_uc )                  \
  NL_BOOL is##name_uc( void ) const {  return( is##name_uc##_ ); }    \
  void set##name_uc( NL_BOOL is##name_uc ) { is##name_uc##_ = is##name_uc; }

//-----------------------------------------------------------------------------------
//
// _NL_DECLARE
//
//-----------------------------------------------------------------------------------

#define _NL_DECLARE( name_lc, type, visibility )  \
  visibility :                                   \
    type name_lc##_;

// _NL_DECLARE_PUBLIC
#define _NL_DECLARE_PUBLIC( name_lc, type )  \
  _NL_DECLARE( name_lc, type, public )

// _NL_DECLARE_PRIVATE
#define _NL_DECLARE_PRIVATE( name_lc, type )  \
_NL_DECLARE( name_lc, type, private )

// _NL_DECLARE_PROTECTED
#define _NL_DECLARE_PROTECTED( name_lc, type )  \
  _NL_DECLARE( name_lc, type, protected )

//-----------------------------------------------------------------------------------
//
// _NL_DECLARE_PTR
//
//-----------------------------------------------------------------------------------

#define _NL_DECLARE_PTR( name_lc, type, visibility )  \
  visibility :                                       \
    type* name_lc##_;

// _NL_DECLARE_PUBLIC_PTR
#define _NL_DECLARE_PUBLIC_PTR( name_lc, type )  \
  _NL_DECLARE_PTR( name_lc, type, publi )

// _NL_DECLARE_PRIVATE_PTR
#define _NL_DECLARE_PRIVATE_PTR( name_lc, type )  \
  _NL_DECLARE_PTR( name_lc, type, private )

  //_NL_DECLARE_PROTECTED_PTR
#define _NL_DECLARE_PROTECTED_PTR( name_lc, type )  \
  _NL_DECLARE_PTR( name_lc, type, protected )


//-----------------------------------------------------------------------------------
//
// NL_DECL_IMPL_GET_SET
//
//-----------------------------------------------------------------------------------

#define NL_DECL_IMPL_GET_SET( name_uc, name_lc, type, member_vis, function_vis ) \
  _NL_DECLARE( name_lc, type, member_vis )                          \
  function_vis:                                                     \
    NL_IMPLEMENT_GET_SET( name_uc, name_lc, type );

// NL_DECL_IMPL_GET_SET_PUBLIC
#define NL_DECL_IMPL_GET_SET_PUBLIC( name_uc, name_lc, type )       \
  _NL_DECLARE_PUBLIC( name_lc, type )                            \
  public:                                                           \
    NL_IMPLEMENT_GET_SET( name_uc, name_lc, type );

  // NL_DECL_IMPL_GET_SET_PRIVATE
#define NL_DECL_IMPL_GET_SET_PRIVATE( name_uc, name_lc, type )      \
  _NL_DECLARE_PRIVATE( name_lc, type )                            \
  private:                                                          \
    NL_IMPLEMENT_GET_SET( name_uc, name_lc, type );

  // NL_DECL_IMPL_GET_SET_PROTECTED
#define NL_DECL_IMPL_GET_SET_PROTECTED( name_uc, name_lc, type )    \
  _NL_DECLARE_PROTECTED( name_lc, type )                            \
  protected:                                                        \
    NL_IMPLEMENT_GET_SET( name_uc, name_lc, type );


//-----------------------------------------------------------------------------------
//
// NL_DECL_IMPL_GET_REF_SET
//
//-----------------------------------------------------------------------------------

#define NL_DECL_IMPL_GET_REF_SET( name_uc, name_lc, type, member_vis, function_vis ) \
  _NL_DECLARE( name_lc, type, member_vis )                           \
  function_vis:                                                      \
    NL_IMPLEMENT_GET_REF_SET( name_uc, name_lc, type );

// NL_DECL_IMPL_GET_REF_SET_PUBLIC
#define NL_DECL_IMPL_GET_REF_SET_PUBLIC( name_uc, name_lc, type )    \
  _NL_DECLARE_PUBLIC( name_lc, type )                                \
  public:                                                            \
    NL_IMPLEMENT_GET_REF_SET( name_uc, name_lc, type );

// NL_DECL_IMPL_GET_REF_SET_PRIVATE
#define NL_DECL_IMPL_GET_REF_SET_PRIVATE( name_uc, name_lc, type )   \
  _NL_DECLARE_PRIVATE( name_lc, type )                             \
  private:                                                           \
    NL_IMPLEMENT_GET_REF_SET( name_uc, name_lc, type );

// NL_DECL_IMPL_GET_REF_SET_PROTECTED
#define NL_DECL_IMPL_GET_REF_SET_PROTECTED( name_uc, name_lc, type ) \
  _NL_DECLARE_PROTECTED( name_lc, type )                             \
  protected:                                                         \
    NL_IMPLEMENT_GET_REF_SET( name_uc, name_lc, type );

//-----------------------------------------------------------------------------------
//
// NL_DECL_IMPL_GET_SET_PTR
//
//-----------------------------------------------------------------------------------

#define NL_DECL_IMPL_GET_SET_PTR( name_uc, name_lc, type, member_vis, function_vis ) \
  _NL_DECLARE_PTR( name_lc, type, member_vis )                       \
  function_vis:                                                      \
    NL_IMPLEMENT_GET_SET_PTR( name_uc, name_lc, type );

  // NL_DECL_IMPL_GET_SET_PUBLIC_PTR
#define NL_DECL_IMPL_GET_SET_PUBLIC_PTR( name_uc, name_lc, type )    \
  _NL_DECLARE_PUBPLIC_PTR( name_lc, type )                         \
  public:                                                            \
    NL_IMPLEMENT_GET_SET_PTR( name_uc, name_lc, type );

  // NL_DECL_IMPL_GET_SET_PRIVATE_PTR
#define NL_DECL_IMPL_GET_SET_PRIVATE_PTR( name_uc, name_lc, type )   \
  _NL_DECLARE_PRIVATE( name_lc, type )                             \
  private:                                                           \
    NL_IMPLEMENT_GET_SET_PTR( name_uc, name_lc, type );

  // NL_DECL_IMPL_GET_SET_PROTECTED_PTR
#define NL_DECL_IMPL_GET_SET_PROTECTED_PTR( name_uc, name_lc, type ) \
  _NL_DECLARE_PROTECTED( name_lc, type )                             \
  protected:                                                         \
    NL_IMPLEMENT_GET_SET_PTR( name_uc, name_lc, type );


//-----------------------------------------------------------------------------------
//
// NL_DISABLE_COPY
//
//-----------------------------------------------------------------------------------

#define NL_DISABLE_COPY( type )                                           \
  public:                                                                 \
      explicit type( const type& ) { NL_BREAKPOINT; };                    \
      type& operator=( const type& ) { NL_BREAKPOINT; return (*this); };  \
  private:

//-----------------------------------------------------------------------------------
//
// NL_DISABLE_ASSIGMENT_OPERATOR
//
//-----------------------------------------------------------------------------------

#define NL_DISABLE_ASSIGMENT_OPERATOR( type )                           \
  public:                                                               \
      type &operator=(const type &){ NL_BREAKPOINT; return (*this); };  \
  private:

//-----------------------------------------------------------------------------------
//
// NL_DISABLE_DEFAULT_CONSTRUCTOR
//
//-----------------------------------------------------------------------------------

#define NL_DISABLE_DEFAULT_CONSTRUCTOR( type )                           \
  public:                                                                \
      type(){ NL_BREAKPOINT; };                                          \
  private:

//-----------------------------------------------------------------------------------
//
// NL_PURE_VIRTUAL
// NL_PURE_VIRTUAL_RETURN
//
//-----------------------------------------------------------------------------------

#define NL_PURE_VIRTUAL \
        { NL_BREAKPOINT; };

#define NL_PURE_VIRTUAL_1( var1 ) \
        { NL_BREAKPOINT; NL_VARIABLE_MAYBE_NOT_REFERENCED( var1 ); };

#define NL_PURE_VIRTUAL_2( var1, var2 ) \
        { NL_BREAKPOINT; NL_VARIABLE_MAYBE_NOT_REFERENCED2( var1, var2 ); };

#define NL_PURE_VIRTUAL_3( var1, var2, var3 ) \
        { NL_BREAKPOINT; NL_VARIABLE_MAYBE_NOT_REFERENCED3( var1, var2, var3 ); };

#define NL_PURE_VIRTUAL_4( var1, var2, var3, var4 ) \
        { NL_BREAKPOINT; NL_VARIABLE_MAYBE_NOT_REFERENCED4( var1, var2, var3, var4 ); };

#define NL_PURE_VIRTUAL_RETURN( type ) \
        { NL_BREAKPOINT; return ( type() ); };

#define NL_PURE_VIRTUAL_RETURN_PTR( type ) \
        { NL_BREAKPOINT; return ( new type() ); };

#define NL_PURE_VIRTUAL_RETURN_1( type, var1 ) \
        { NL_VARIABLE_MAYBE_NOT_REFERENCED( var1 ); \
          NL_BREAKPOINT; return ( type() ); };

#define NL_PURE_VIRTUAL_RETURN_2( type, var1, var2 ) \
        { NL_VARIABLE_MAYBE_NOT_REFERENCED2( var1, var2 ); \
          NL_BREAKPOINT; return ( type() ); };

#define NL_PURE_VIRTUAL_RETURN_3( type, var1, var2, var3 ) \
        { NL_VARIABLE_MAYBE_NOT_REFERENCED3( var1, var2, var3 ); \
          NL_BREAKPOINT; return ( type() ); };

#define NL_PURE_VIRTUAL_RETURN_4( type, var1, var2, var3, var4 ) \
        { NL_VARIABLE_MAYBE_NOT_REFERENCED4( var1, var2, var3, var4 ); \
          NL_BREAKPOINT; return ( type() ); };

#define NL_PURE_VIRTUAL_RETURN_REF( ref ) \
        { NL_BREAKPOINT; return ( ref ); };


}// NameSpace nextlimit...

//-----------------------------------------------------------------------------------
//
// Nexlimit Namespace Alias:
//
//-----------------------------------------------------------------------------------
namespace nl = nextlimit;

#endif // NL_BASIC_H_
