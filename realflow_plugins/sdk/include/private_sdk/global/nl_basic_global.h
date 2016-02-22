
#ifndef _NL_BASIC_GLOBAL_H_
#define _NL_BASIC_GLOBAL_H_


//-----------------------------------------------------------------------------------
//
// DllMode
//
//-----------------------------------------------------------------------------------
#ifdef _NL_STATIC_LINKING

#ifndef DllExport
  #define DllExport
#endif

#ifndef DllImport
  #define DllImport
#endif

#elif defined _NL_SINGLE_DLL_LINKING

  #ifndef DllExport
  # ifdef _WINDOWS
  #   define DllExport __declspec( dllexport )
  # else
  #		define DllExport __attribute__( ( visibility( "default" ) ) )
  #	endif
  #endif

  #ifndef DllImport
  # ifdef _WINDOWS
  #   define DllImport
  # else
  #		define DllImport
  #	endif
  #endif

#else

  #ifndef DllExport
  # ifdef _WINDOWS
  #   define DllExport __declspec( dllexport )
  # else
  #		define DllExport __attribute__( ( visibility( "default" ) ) )
  #	endif
  #endif

  #ifndef DllImport
  # ifdef _WINDOWS
  #   define DllImport __declspec( dllimport )
  # else
  #		define DllImport
  #	endif
  #endif

#endif


//-----------------------------------------------------------------------------------
//
// NL_BASIC_EXPORTS_DLL, NL_BASIC_EXPORTS_DLL_STATIC
//
//-----------------------------------------------------------------------------------
#ifdef NL_BASIC_EXPORTS
# define NL_BASIC_EXPORTS_DLL        DllExport
# define NL_BASIC_EXPORTS_DLL_STATIC DllExport
#else
# define NL_BASIC_EXPORTS_DLL
# define NL_BASIC_EXPORTS_DLL_STATIC DllImport
#endif



#endif //_NL_BASIC_GLOBAL_H_



