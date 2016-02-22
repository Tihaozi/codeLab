
#ifndef _NL_RFSDK_CMD_H
#define _NL_RFSDK_CMD_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfbaseobj.h"
  //  REST"


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  // FORWARD DECLARATIONS
  class PlgCmd;
  class SDKPlgCmd;
  

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class CmdPythonPlgSdk;
    class CmdGraphPlgSdk;

    //-----------------------------------------------------------------------------------
    //
    // RFEvntCmd:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Cmd : public RFBaseObj<nl::PlgCmd>
    {

      typedef nl::PlgCmd NativeObjType ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Cmd( NativeObjType* nativeObj ) : RFBaseObj<nl::PlgCmd>( nativeObj ) {};

    public:
      /// Destructor
      virtual ~Cmd( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class nl::SDKPlgCmd;
      friend class nl::rf_sdk::CmdPythonPlgSdk;
      friend class nl::rf_sdk::CmdGraphPlgSdk;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_CMD_H...





