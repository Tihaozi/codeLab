
#ifndef _RF_COMMON_DEFS_H
#define _RF_COMMON_DEFS_H

//-----------------------------------------------------------------------------------
//
// DllMode
//
//-----------------------------------------------------------------------------------
#include <global/nl_basic_global.h>

//-----------------------------------------------------------------------------------
//
// RF_COMMON_EXPORTS_DLL, RF_COMMON_EXPORTS_DLL_STATIC
//
//-----------------------------------------------------------------------------------
#ifdef RF_COMMON_EXPORTS
# define RF_COMMON_EXPORTS_DLL          DllExport
# define RF_COMMON_EXPORTS_DLL_STATIC   DllExport
# define RF_COMMON_IMPORTS_STATIC      
# define RF_COMMON_EXTERN
#else
# define RF_COMMON_EXPORTS_DLL
# define RF_COMMON_EXPORTS_DLL_STATIC   DllImport
# define RF_COMMON_IMPORTS_STATIC       DllImport
# define RF_COMMON_EXTERN               extern 
#endif

//-----------------------------------------------------------------------------------
//
// GLOBAL MACROS
//
//-----------------------------------------------------------------------------------
#define MAKESUREPATHEXISTS_CHECKING( x ) {\
        IF_NOT_THEN( ::makeSurePathExists( x ), \
             callbackCenterSgt->messageId( MSG_ID_ERROR_CREATE_FOLDER, x ) ) };

#define NAMESPACE_G( decl ) \
  namespace g{ decl; }


#endif // _RF_COMMON_DEFS_H...
