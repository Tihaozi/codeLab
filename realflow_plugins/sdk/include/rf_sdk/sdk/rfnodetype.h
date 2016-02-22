
#ifndef _NL_RFSDK_NODE_TYPE_H
#define _NL_RFSDK_NODE_TYPE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
//#include <containers/nl_array.h>
//#include <rf_core/body/regular_body.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include <string>
#include <iostream>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnode.h"

// FORWARD DECLARATIONS
class Nodo;


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD REFERENCES
    class PB_Emitter;
    class Daemon;
    class Camera;
    class Spline;
    class Joint;
    class Group;
    class HY_Mist;
    class IDOC;

    //-----------------------------------------------------------------------------------
    //
    // RFNodeType<T, false, false>:
    //
    //-----------------------------------------------------------------------------------
    // template <class T, NL_BOOL EXPORT_RSRC = false, NL_BOOL EXPORT_RSRC_IMG = false>
    template <class RF_NODE_TYPE, class SDK_NODE_BASE_TYPE >
    class RF_SDK_EXPORTS_DLL_STATIC RFNodeType : public SDK_NODE_BASE_TYPE
    {
    
    typedef SDK_NODE_BASE_TYPE ParentClass;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{
    protected:

      /// Constructor
      RFNodeType( RF_NODE_TYPE* nativeObjPtr ); 

    public:
      /// Destructor
      virtual ~RFNodeType( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      PtrWrprChkr<RF_NODE_TYPE>& getNativeObj()
      {
        return reinterpret_cast< PtrWrprChkr<RF_NODE_TYPE> & >( ParentClass::getNativeObj() );
      }

      const PtrWrprChkr<RF_NODE_TYPE>& getNativeObj() const 
      {
        return reinterpret_cast< const PtrWrprChkr<RF_NODE_TYPE> & >( ParentClass::getNativeObj() );
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class nl::rf_sdk::PB_Emitter;
      friend class nl::rf_sdk::Daemon;
      friend class nl::rf_sdk::Camera;
      friend class nl::rf_sdk::Joint;
      friend class nl::rf_sdk::Spline;
      friend class nl::rf_sdk::Group;
      friend class nl::rf_sdk::HY_Mist;
      friend class nl::rf_sdk::IDOC;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_NODE_TYPE_H...





