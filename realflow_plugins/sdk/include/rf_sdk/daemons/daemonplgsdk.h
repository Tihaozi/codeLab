
#ifndef _NL_RFSDK_DAEMON_PLG_SDK_H
#define _NL_RFSDK_DAEMON_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <rf_core/plugin/plgsdk.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/sdkversion.h"
  //  REST
#include "rf_sdk/sdk/pb_emitter.h"
#include "rf_sdk/plugin/rfplgsdk.h"

// RF_SDK_DECLARE_DAEMON_PLUGIN
#define RF_SDK_DECLARE_DAEMON_PLUGIN( type )                                          \
  RF_SDK_LIB_EXPORT_DLL nextlimit::rf_sdk::DaemonPlgSdk* createDaemonPlgSdk( void )   \
  {                                                                                   \
    return (nextlimit::rf_sdk::DaemonPlgSdk*) new type( );                            \
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
    class Daemon;
    class Object;
    class MultiBody;
    class HY_GridDomain;
    class HY_Mist;

    namespace daemon_affect
    { 
      RF_SDK_EXPORTS_DLL_STATIC extern const int AFFECT_EMITTER;
      RF_SDK_EXPORTS_DLL_STATIC extern const int AFFECT_OBJECT; 
      RF_SDK_EXPORTS_DLL_STATIC extern const int AFFECT_EMITER_AND_OBJECT;
    }


    //-----------------------------------------------------------------------------------
    //
    // DaemonPlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL DaemonPlgSdk : public RFPlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      DaemonPlgSdk() {}

      /// Destructor
      virtual ~DaemonPlgSdk() {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// applyForceToEmitter:  
      ///
      ///  This function is called by the simulation engine when external forces should be applied to the    
      ///  particles in the emitter. 
      ///
      /// @param [in/out] plgThis  / Sdk Daemon ( Owner of this Daemon Plugin )
      /// @param [in/out] emitter / Sdk Emitter which particles will be affected by external forces
      /// @param [in] iter / Iterator over the Emitter's Particles
      //
      virtual void applyForceToEmitter
        ( nl::rf_sdk::Daemon* plgThis, PB_Emitter* emitter, RFEmitter_It iter )
      {
        applyForceToEmitter( plgThis, emitter, 0, iter );
      }

      //--------------------------------------------------
      //  Function: applyForceToEmitter 
      //  This function is called by the simulation engine 
      //  when external forces should be applied to the    
      //  particles in the emitter.
      //  It is only used if the plugin is declared MultiThreading through the isMT method.
      //--------------------------------------------------
      virtual void applyForceToEmitter
        ( nl::rf_sdk::Daemon* plgThis, PB_Emitter* emitter, int nThread, RFEmitter_It iter )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED4( plgThis, emitter, nThread, iter );
      }

      //--------------------------------------------------
      // Function: applyForceToBody 
      // This function is called by the simulation engine 
      // when external forces should be applied to the body.                  
      //--------------------------------------------------
      virtual void applyForceToBody( nl::rf_sdk::Daemon* plgThis, nl::rf_sdk::Object* obj )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, obj );
      }

      //--------------------------------------------------
      // Function: applyForceToMultiBody 
      // This function is called by the simulation engine 
      // when external forces should be applied to the body.                  
      //--------------------------------------------------
      virtual void applyForceToMultiBody( nl::rf_sdk::Daemon* plgThis, nl::rf_sdk::MultiBody* obj )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, obj );
      }

      //--------------------------------------------------
      // Function: applyForceToMist 
      // This function is called by the simulation engine 
      // when external forces should be applied to the mist.                  
      //--------------------------------------------------
      virtual void applyForceToMist( nl::rf_sdk::Daemon* plgThis, nl::rf_sdk::HY_Mist* obj )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, obj );
      }

      //--------------------------------------------------
      // Function: applyForceToGridFluid 
      // This function is called by the simulation engine 
      // when external forces should be applied to the grid fluid.                  
      //--------------------------------------------------
      virtual void applyForceToGridFluid( nl::rf_sdk::Daemon* plgThis, nl::rf_sdk::HY_GridDomain* obj )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, obj );
      }          

      //--------------------------------------------------
      // Function: removeParticles 
      // This function is called by the simulation engine 
      // when it is safe to remove particles.                 
      //--------------------------------------------------
      virtual void removeParticles( nl::rf_sdk::Daemon* plgThis, PB_Emitter* obj )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, obj );
      }

      //--------------------------------------------------
      // Function: onSimulationBegin 
      // This function is called by the simulation engine 
      // when the simulation begins.               
      //--------------------------------------------------
      virtual void onSimulationBegin( nl::rf_sdk::Daemon* plgThis ) 
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED( plgThis );
      };

      //--------------------------------------------------
      // Function: onSimulationResume 
      // This function is called by the simulation engine 
      // when the simulation resumes.               
      //--------------------------------------------------
      virtual void onSimulationResume( nl::rf_sdk::Daemon* plgThis )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED( plgThis );
      };

      //--------------------------------------------------
      // Function: onSimulationStop 
      // This function is called by the simulation engine 
      // when the simulation stops.               
      //--------------------------------------------------
      virtual void onSimulationStop( nl::rf_sdk::Daemon* plgThis )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED( plgThis );
      };

      //--------------------------------------------------
      // Function: onSimulationFrame
      // This function is called by the simulation engine 
      // when the simulation starts the computation of
      // the next frame.
      //--------------------------------------------------
      virtual void onSimulationFrame( nl::rf_sdk::Daemon* plgThis,
                                      const unsigned int& frame )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED2( plgThis, frame );
      };


      // Flag that determines the type of objects that are affected by this Daemon.
      int canAffect( nl::rf_sdk::Daemon* plgThis ) const;

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
#endif // _NL_RFSDK_DAEMON_PLG_SDK_H...


