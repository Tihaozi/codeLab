
#ifndef _SDK_COLOR_GRADIENT_H
#define _SDK_COLOR_GRADIENT_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL_BASIC
#include "indexes/nl_index.h"

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {


    //-----------------------------------------------------------------------------------
    //
    // Sdk_ColorGradient:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Sdk_ColorGradient
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor init 0
      Sdk_ColorGradient(){}

      /// Destructor
      ~Sdk_ColorGradient( void ) {};


 

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:
   
      /// Assignment operator
      void operator= ( const Sdk_ColorGradient& v )
      {
        NL_NOT_IMPLEMENTED_YET
      }
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: Compare
      //  @{
    public:
      
      /// Equality operator.
      NL_BOOL operator== ( const Sdk_ColorGradient& v) const
      {
        NL_NOT_IMPLEMENTED_YET
        return false;
      }
      
      /// Equality operator.
      NL_BOOL operator!= ( const Sdk_ColorGradient& v ) const
      {
        NL_NOT_IMPLEMENTED_YET
        return false;
      }
      
      /// @return The gradient color at the specified position.
      void evaluate( const float& position, std::vector< float >& outColor ) const
      {
        NL_NOT_IMPLEMENTED_YET
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:


      // friend class rf_sdk::PB_Particle;
      //  friend class RFSdkBasicLib;
      //  friend class nl::rf_sdk::Object;
    };



  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _SDK_COLOR_GRADIENT_H...





