
#ifndef _RF_SDK_DEFS_H
#define _RF_SDK_DEFS_H

//-----------------------------------------------------------------------------------
//
// DllMode
//
//-----------------------------------------------------------------------------------
#include <global/nl_basic_global.h>

//-----------------------------------------------------------------------------------
//
// RF_SDK_EXPORTS_DLL, RF_SDK_EXPORTS_DLL_STATIC
//
//-----------------------------------------------------------------------------------
#ifdef RF_SDK_EXPORTS
  # define RF_SDK_EXPORTS_DLL         DllExport
  # define RF_SDK_EXPORTS_DLL_STATIC  DllExport
#else
  # define RF_SDK_EXPORTS_DLL
  # define RF_SDK_EXPORTS_DLL_STATIC  DllImport
#endif

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {


  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_SDK_DEFS_H...





