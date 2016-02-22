
#ifndef _RF_PARTICLE_SOLVER_H
#define _RF_PARTICLE_SOLVER_H

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
  class SDKPlgParticleSolver;

  // FORWARD REFERENCES
  namespace rf_core
  {
    class ParticleSolver;
  };
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
    // ParticleSolver:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL ParticleSolver : public RFBaseObj<rf_core::ParticleSolver>
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      ParticleSolver( rf_core::ParticleSolver* nativeObjPtr ) 
            : RFBaseObj< rf_core::ParticleSolver >( nativeObjPtr )  {};

    public:
      /// Destructor
      ~ParticleSolver( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // INTERFACE
      
      // integrate
      void integrateEuler( const NL_UINT& cpuId, const NL_FLOAT& dt );

      // integrate
      void integrateLeapFrog( const NL_UINT& cpuId,
                              const NL_FLOAT& dt,
                              const NL_FLOAT& last_dt );

      // getIntegrationTime
      NL_FLOAT getIntegrationTime( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:


      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) 
      { 
        return sdk_type::PARTICLE_SOLVER_TYPE; 
      };

      //static const SdkType typeRFBs_ = WAVE_TYPE;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class nl::SDKPlgParticleSolver;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_PARTICLE_SOLVER_H...





