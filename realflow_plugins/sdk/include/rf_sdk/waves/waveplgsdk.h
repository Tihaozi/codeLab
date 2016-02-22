
#ifndef _NL_RFSDK_WAVE_PLG_SDK_H
#define _NL_RFSDK_WAVE_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/sdkversion.h"
  //  REST
#include "rf_sdk/sdk/vertex.h"
#include <rf_sdk/sdk/wave.h>
#include "rf_sdk/plugin/rfplgsdk.h"

// RF_SDK_DECLARE_WAVE_PLUGIN
#define RF_SDK_DECLARE_WAVE_PLUGIN( type )                                        \
  RF_SDK_LIB_EXPORT_DLL nextlimit::rf_sdk::WavePlgSdk* createWavePlgSdk( void )   \
  {                                                                               \
    return (nextlimit::rf_sdk::WavePlgSdk*) new type( );                          \
  }                                                                               \
                                                                                  \
  RF_SDK_LIB_EXPORT_DLL NL_INDEX32 getSdkVersion( void )                          \
  {                                                                               \
    return ( SdkVersion::SDK_VERSION );                                           \
  }    


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{ 

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS


    //-----------------------------------------------------------------------------------
    //
    // WavePlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL WavePlgSdk : public RFPlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      WavePlgSdk() {}

      /// Destructor
      virtual ~WavePlgSdk() {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      //#--------------------------------------------------
      //# Function: updateWave 
      //# This function is called by the simulation engine 
      //# when it is time to update the wave. 
      //# The parameter is the list of vertices that you have 
      //# to update. Only values in the Y axis are used. 
      //#--------------------------------------------------

      virtual void updateWave( nl::rf_sdk::Wave* plgThis                   , 
                               std::vector<Vertex>& vertices           ,
                               const std::vector<Vector>& initPosVrtxs  ) = 0; 

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
#endif // _NL_RFSDK_WAVE_PLG_SDK_H...


