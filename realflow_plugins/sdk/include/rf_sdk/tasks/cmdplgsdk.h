
#ifndef _NL_RFSDK_CMD_PLG_SDK_H
#define _NL_RFSDK_CMD_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/sdkversion.h"

  //  REST
#include "rf_sdk/sdk/cmd.h"
#include "rf_sdk/plugin/rfplgsdk.h"

// RF_SDK_DECLARE_CMD_PLUGIN
#define RF_SDK_DECLARE_CMD_PLUGIN( type )                                             \
  RF_SDK_LIB_EXPORT_DLL nextlimit::rf_sdk::CmdPlgSdk* createCmdPlgSdk( void )         \
  {                                                                                   \
    return (nextlimit::rf_sdk::CmdPlgSdk*) new type( );                               \
  }                                                                                   \
                                                                                      \
  RF_SDK_LIB_EXPORT_DLL NL_INDEX32 getSdkVersion( void )                              \
  {                                                                                   \
  return ( nl::rf_sdk::SdkVersion::SDK_VERSION );                                               \
  }                                                         

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{ 

    // FORWARD DECLARATIONS

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // CmdPlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL CmdPlgSdk : public RFPlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      CmdPlgSdk() {}

      /// Destructor
      virtual ~CmdPlgSdk() {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // run
      virtual void run ( nl::rf_sdk::Cmd* plgThis ) = 0;

      // run
      virtual void runMethod ( nl::rf_sdk::Cmd* plgThis, const std::string& method )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, method );
      }

      // run
      virtual NL_BOOL hasMethod ( nl::rf_sdk::Cmd* plgThis, const std::string& method ) 
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, method );

        return NL_false; 
      };

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
#endif // _NL_RFSDK_CMD_PLG_SDK_H...





