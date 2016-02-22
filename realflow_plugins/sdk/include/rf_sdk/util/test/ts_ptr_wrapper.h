
#ifndef _NL_TS_PTR_WRAPPER_H_
#define _NL_TS_PTR_WRAPPER_H_

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
#include "rf_common/nl_cxxtest/test_suite.h"
#include "rf_sdk/util/ptrwrapper.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace nl_cxxtest
  {

    //-----------------------------------------------------------------------------------
    //
    // TS_SmartPointers:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL TS_PtrWrapper : public TestSuite
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      TS_PtrWrapper() {};

      /// Destructor
      ~TS_PtrWrapper() {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      void testLifeCycle( void )
      {
        //int* ptrInt = new int( 12 );
        //PtrWrapper_ScpPtr< int, PtrPolicy_ROBUSTNESS > ptr( ptrInt );
        
       //std::cout << " Value of Ptr = " << *ptr << std::endl;
        //Constructor 1
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
#endif // _NL_TS_PTR_WRAPPER_H_
