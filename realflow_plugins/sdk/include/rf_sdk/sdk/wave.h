
#ifndef _NL_SDK_WAVE_H
#define _NL_SDK_WAVE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfbaseobj.h"

// FORWARD REFERENCES

namespace nextlimit
{
  class Wave;
  class SDKPlgWave;

  namespace rf_sdk
  {
    class Scene;
    class PB_Particle;
    class RFSdkBasicLib;
    class RealWave;
  }
}


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{
  
  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // Wave:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Wave : public RFBaseObj< nl::Wave >
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Wave( nl::Wave* nativeObjPtr ) : RFBaseObj< nl::Wave >( nativeObjPtr )  {};

    public:
      /// Destructor
      virtual ~Wave( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // INTERFACE
      /// getName:  
      ///
      /// Gets the Wave 's name
      ///
      /// @return : Wave 's name
      //
      virtual std::string getName() const;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::WAVE_TYPE; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class nl::rf_sdk::Scene;
      friend class nl::rf_sdk::PB_Particle;
      friend class nl::rf_sdk::RFSdkBasicLib;
      friend class nl::SDKPlgWave;
      friend class nl::rf_sdk::RealWave;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_WAVE_H...





