
#ifndef _NL_SDK_EXCPT_H
#define _NL_SDK_EXCPT_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // Sdk_Excpt:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Sdk_Excpt : public NL_Exception
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      Sdk_Excpt( ) : NL_Exception()  {};

      Sdk_Excpt( const std::string& errMsg ) : NL_Exception( NLR_FAIL, errMsg )  {};

      /// Destructor
      ~Sdk_Excpt( void ) throw() {};
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_EXCPT_H...





