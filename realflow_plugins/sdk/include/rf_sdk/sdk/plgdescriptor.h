
#ifndef _NL_RFSDK_PLG_CLASS_H
#define _NL_RFSDK_PLG_CLASS_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES
#include <rf_sdk/util/ptrwrprchkr.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include <rf_sdk/sdk/ppty.h>

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  // FORWARD DECLARATIONS
  class PlgDescriptor;

  template < class T1, class T2, class T3 >
  class DllPlgDescriptor;

  template < class T1, class T2, class T3 >
  class PythonPlgDescriptor;

  template < class T1, class T2, class T3 >
  class GraphPlgDescriptor;

  template < class T1, class T2, class T3 >
  class RF_ActionPlgDescriptor;
  
  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // PlgDescriptor:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL PlgDescriptor
    {

      typedef nl::PlgDescriptor NativeObjType ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      PlgDescriptor( NativeObjType* nativeObj ) : nativeObj_( nativeObj ) {};

    public:
      /// Destructor
      ~PlgDescriptor( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      // addPpty
      bool addPpty( const nl::rf_sdk::Ppty& ppty );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:
      
      PtrWrprChkr<NativeObjType>& getNativeObj()
      {
        return nativeObj_;
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      PtrWrprChkr<NativeObjType> nativeObj_;

      template < class T1, class T2, class T3 >
      friend class nl::DllPlgDescriptor;

      template < class T1, class T2, class T3 >
      friend class nl::PythonPlgDescriptor;

      template < class T1, class T2, class T3 >
      friend class nl::GraphPlgDescriptor;

      template < class T1, class T2, class T3 >
      friend class nl::RF_ActionPlgDescriptor;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_PLG_CLASS_H...





