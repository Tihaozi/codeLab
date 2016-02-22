
#ifndef _NL_RFSDK_SDK_EXCPT_MESSG_H
#define _NL_RFSDK_SDK_EXCPT_MESSG_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"

// FORWARD DECLARATIONS

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class Sdk_Excpt;
    class RF_Null_Excpt;

    //-----------------------------------------------------------------------------------
    //
    // SdkExcptMessg:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL SdkExcptMessg
    {

     // typedef ANIFloatBase NativeObjType ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      SdkExcptMessg();

    public:
      /// Destructor
      ~SdkExcptMessg() {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      //
      static void msgForExcpt( Sdk_Excpt& e                  ,
                               const std::string& sdkObjName   ,   
                               const std::string& sdkFunctName   );

      //
      static void msgForExcpt( RF_Null_Excpt& e              , 
                               const std::string& sdkObjName   ,   
                               const std::string& sdkFunctName   );

      //
      static void Show_RF_Unknown_Msg( const std::string& sdkClassName  ,   
                                          const std::string&  sdkFunctName   );

      //
      static void throw_RF_WrongArgs_Excpt( const std::string& sdkObjName   ,   
                                            const std::string& sdkFunctName   );

      //
      static void throw_RF_ParamNotFound_Excpt( const std::string& paramName );

      //
      static void throw_RF_ParamWrongTypeValue_Excpt( const std::string& paramName  );

      //
      static void throw_WrongTypeCast( const std::string& sdkClassName ,   
                                       const std::string& sdkFunctName  );

      //
      static void throw_RF_ParamWrongTypeCast_Excpt( const std::string& paramName  );

      //
      static void throw_GlobalVarNotDefined( const std::string& globarVarName );

      //
      static void throw_GlobalVarAlreadyDefined( const std::string& globarVarName );
      

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

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

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_SDK_EXCPT_MESSG_H...





