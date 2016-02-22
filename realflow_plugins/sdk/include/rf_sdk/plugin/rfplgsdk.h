
#ifndef _NL_RFSDK_RFPLG_SDK_H
#define _NL_RFSDK_RFPLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#include <indexes/nl_index.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES
#include <rf_core/plugin/plgsdk.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{ 

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // PlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL RFPlgSdk : public PlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      RFPlgSdk( )
      {
      }

      /// Destructor
      virtual ~RFPlgSdk() {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // getSdkVersion
      virtual NL_INDEX32 getSdkVersion() const
      {
        return ( SdkVersion::SDK_VERSION );
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @internal Operations:
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @helper Operations:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

    };

  };

} // NameSpace NextLimit...
#endif // _NL_RFSDK_RFPLG_SDK_H...





