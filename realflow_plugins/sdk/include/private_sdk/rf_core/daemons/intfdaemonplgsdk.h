
#ifndef _NL_RFSDK_INTF_DAEMON_PLG_SDK_H
#define _NL_RFSDK_INTF_DAEMON_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <rf_core/plugin/plgsdk.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_core/rf_coredefs.h"
  //  REST

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{ 
  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class Daemon;

    //-----------------------------------------------------------------------------------
    //
    // IntfDaemonPlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_CORE_EXPORTS_DLL IntfDaemonPlgSdk : public PlgSdk
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      IntfDaemonPlgSdk() {}

      /// Destructor
      virtual ~IntfDaemonPlgSdk() {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // Flag that determines the type of objects that are affected by this Daemon.
      virtual int canAffect( nl::rf_sdk::Daemon* plgThis ) const = 0;

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
#endif // _NL_RFSDK_INTF_DAEMON_PLG_SDK_H...


