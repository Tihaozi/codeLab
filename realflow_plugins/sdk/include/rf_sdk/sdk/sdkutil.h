
#ifndef _NL_RFSDK_UTIL_H
#define _NL_RFSDK_UTIL_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // SdkUtil:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL SdkUtil
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      SdkUtil( void );

      /// Destructor
      ~SdkUtil( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // getSdkNodeTypeFromRfNodeType
      static NL_UINT64 getSdkNodeTypeFromRfNodeType( NL_UINT64 rfNodeType )
      {
        return rfNodeType;
      }

   
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_UTIL_H...





