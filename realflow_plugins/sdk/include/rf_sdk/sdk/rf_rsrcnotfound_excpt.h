
#ifndef _RF_RSRC_NOT_FOUND_EXCPT_H
#define _RF_RSRC_NOT_FOUND_EXCPT_H

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
    // RF_RsrcNotFound_Excpt:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL RF_RsrcNotFound_Excpt : public Sdk_Excpt
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      RF_RsrcNotFound_Excpt( ) : Sdk_Excpt()  {};

      RF_RsrcNotFound_Excpt( const std::string& errMsg ) :Sdk_Excpt( errMsg ) {};

      /// Destructor
      ~RF_RsrcNotFound_Excpt( void ) throw() {};
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_RSRC_NOT_FOUND_EXCPT_H...





