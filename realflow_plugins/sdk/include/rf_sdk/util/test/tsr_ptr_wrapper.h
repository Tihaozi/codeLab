
#ifndef _NL_TSR_PTR_WRAPPER_H_
#define _NL_TSR_PTR_WRAPPER_H_


// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include <iostream>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_common/nl_cxxtest/test_runner.h"
#include "rf_sdk/util/test/ts_ptr_wrapper.h"


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace nl_cxxtest
  {

    //-----------------------------------------------------------------------------------
    //
    // TSR_PtrWrapper: 
    //
    //-----------------------------------------------------------------------------------
    class RF_CORE_EXPORTS_DLL TSR_PtrWrapper : public nl_cxxtest::TestRunner
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      TSR_PtrWrapper() {};

      /// Destructor
      ~TSR_PtrWrapper() {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      virtual int run( void )
      {
        TS_PtrWrapper ts;

        ts.testLifeCycle();

        return 0;
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @private Methods:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

    };

  }      // NameSpace nl_cxxtest...
}      // NameSpace NextLimit...
#endif // _NL_TSR_PTR_WRAPPER_H_
