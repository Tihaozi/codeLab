
#ifndef _NL_RFSDK_PARTICLE_SOLVER_PLG_SDK_H
#define _NL_RFSDK_PARTICLE_SOLVER_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/sdkversion.h"
  //  REST
#include "rf_sdk/sdk/particlesolver.h"
#include "rf_sdk/sdk/vertex.h"
#include "rf_sdk/sdk/wave.h"
#include "rf_sdk/sdk/pb_emitter.h"
#include "rf_sdk/plugin/rfplgsdk.h"

// RF_SDK_DECLARE_PARTICLE_SOLVER_PLUGIN
#define RF_SDK_DECLARE_PARTICLE_SOLVER_PLUGIN( type )                                                 \
  RF_SDK_LIB_EXPORT_DLL nextlimit::rf_sdk::ParticleSolverPlgSdk* createParticleSolverPlgSdk( void )   \
  {                                                                                                   \
    return (nextlimit::rf_sdk::ParticleSolverPlgSdk*) new type( );                                    \
  }                                                                                                   \
                                                                                                      \
  RF_SDK_LIB_EXPORT_DLL NL_INDEX32 getSdkVersion( void )                                              \
  {                                                                                                   \
    return ( SdkVersion::SDK_VERSION );                                                               \
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
    // ParticleSolverPlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL ParticleSolverPlgSdk : public RFPlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      ParticleSolverPlgSdk() {}

      /// Destructor
      virtual ~ParticleSolverPlgSdk() {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // preComputeInternalForces
      virtual void preComputeInternalForces(  ParticleSolver* particleSolver,
                                              PB_Emitter* emitter )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( particleSolver, emitter );
      };

      // computeInternalForces
      virtual void computeInternalForces( ParticleSolver* particleSolver,
                                          PB_Emitter* emitter, 
                                          int nThread, 
                                          RFEmitter_It iter ) 
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED4( particleSolver, emitter, nThread, iter );
      };

      // integrate
      virtual void integrate( ParticleSolver* particleSolver,
                              PB_Emitter* emitter,                               
                              int nThread, 
                              RFEmitter_It iter,
                              float dt )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( emitter, iter );
        NL_ASSERT_NOT_NULL( particleSolver );
        particleSolver->integrateEuler( nThread, dt );
      };

      // getIntegrationTime
      virtual float getIntegrationTime( nl::rf_sdk::ParticleSolver* particleSolver ) const
      {
        NL_ASSERT_NOT_NULL( particleSolver );
        return ( particleSolver->getIntegrationTime() );
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
#endif // _NL_RFSDK_PARTICLE_SOLVER_PLG_SDK_H...


