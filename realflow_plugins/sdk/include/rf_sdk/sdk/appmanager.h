
#ifndef _NL_SDK_APP_MANAGER_H
#define _NL_SDK_APP_MANAGER_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD REFERENCES
    class Scene;
    class RFSdkBasicLib;
    class PB_Emitter;

    //-----------------------------------------------------------------------------------
    //
    // AppManager:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC AppManager
    {
      
    public:                                               
      static AppManager* instance( void );                      
   
    private:                                              
        AppManager( const AppManager& ) {}                              
        AppManager& operator= ( const AppManager& ) { return( *this ); }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      AppManager( void );

    public:

      /// Destructor
      ~AppManager( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:


      /// getCurrentScene:  
      /// @return the main Scene
      nl::rf_sdk::Scene& getCurrentScene( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations: Simulation Context:
      //  @                ---------------------
      //  @{ 
    protected:

      /// State of simulation
      bool            isAnimated          ( void );
      bool            isPlaying           ( void );
//      executionModes  getExecutionMode    ( void );
      bool            isTouch             ( void );
      void            setTouch            ( bool touch );
      bool            isMainScriptRunning ( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:
      
      nl::rf_sdk::Scene* scene_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class RFSdkBasicLib;
      friend class Scene;
      friend class PB_Emitter;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_APP_MANAGER_H...





