
#ifndef _RF_CORE_DEFS_H
#define _RF_CORE_DEFS_H

//-----------------------------------------------------------------------------------
//
// DllMode
//
//-----------------------------------------------------------------------------------
#include <global/nl_basic_global.h>

//-----------------------------------------------------------------------------------
//
// RF_CORE_EXPORTS_DLL, RF_CORE_EXPORTS_DLL_STATIC
//
//-----------------------------------------------------------------------------------
#ifdef RFCORE_EXPORTS
# define RF_CORE_EXPORTS_DLL          DllExport
# define RF_CORE_EXPORTS_DLL_STATIC   DllExport
# define RF_CORE_IMPORTS_STATIC       
#else
# define RF_CORE_EXPORTS_DLL
# define RF_CORE_EXPORTS_DLL_STATIC   DllImport
# define RF_CORE_IMPORTS_STATIC       DllImport
#endif


#endif // _RF_CORE_DEFS_H...



