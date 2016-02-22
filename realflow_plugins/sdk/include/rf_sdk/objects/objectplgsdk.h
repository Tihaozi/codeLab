
#ifndef _NL_RFSDK_OBJECT_PLG_SDK_H
#define _NL_RFSDK_OBJECT_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/sdkversion.h"
  //  REST
#include "rf_sdk/sdk/pb_emitter.h"
#include "rf_sdk/plugin/rfplgsdk.h"

// RF_SDK_DECLARE_OBJECT_PLUGIN
#define RF_SDK_DECLARE_OBJECT_PLUGIN( type )                                          \
  RF_SDK_LIB_EXPORT_DLL nextlimit::rf_sdk::ObjectPlgSdk* createObjectPlgSdk( void )   \
  {                                                                                   \
    return (nextlimit::rf_sdk::ObjectPlgSdk*) new type( );                            \
  }                                                                                   \
                                                                                      \
  RF_SDK_LIB_EXPORT_DLL NL_INDEX32 getSdkVersion( void )                              \
  {                                                                                   \
    return ( SdkVersion::SDK_VERSION );                                               \
  }     

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{ 

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class Object;

    //-----------------------------------------------------------------------------------
    //
    // ObjectPlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL ObjectPlgSdk : public RFPlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      ObjectPlgSdk() {}

      /// Destructor
      virtual ~ObjectPlgSdk() {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
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

    };

  };

} // NameSpace NextLimit...
#endif // _NL_RFSDK_OBJECT_PLG_SDK_H...


