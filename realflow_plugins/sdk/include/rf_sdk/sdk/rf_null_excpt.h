
#ifndef _RF_NULL_EXCPT_H
#define _RF_NULL_EXCPT_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include <rf_sdk/sdk/sdk_excpt.h>

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // RF_NullException:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL RF_Null_Excpt : public Sdk_Excpt
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      RF_Null_Excpt( ) : Sdk_Excpt()  {};

      RF_Null_Excpt( const std::string& errMsg ) : Sdk_Excpt( errMsg )  {};

      /// Destructor
      ~RF_Null_Excpt( void ) throw() {};
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_NULL_EXCPT_H...





