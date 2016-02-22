
#ifndef _NL_SDK_COLOR_GRADIENT_H
#define _NL_SDK_COLOR_GRADIENT_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#include <vector>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/util/sdk_colorgradient.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //FORWARD DECLARATIONS
    class Object;
    class PB_Particle;

    //-----------------------------------------------------------------------------------
    //
    // ColorGradient:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL ColorGradient
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      ColorGradient( void ){};

      /// Destructor
      ~ColorGradient( void ) {};

    protected:
      ColorGradient( const Sdk_ColorGradient& gradient ) : colorGradient_( gradient ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: =
      //  @{ 
    public:

      /// Assignment operator
      void operator= ( const ColorGradient& v )
      {
        colorGradient_.operator=( v.colorGradient_ );
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: Compare
      //  @{ 
    public:

      /// Equality operator.
      NL_BOOL operator== ( const ColorGradient& v) const
      { 
        return colorGradient_.operator==( v.colorGradient_ );
      }

      /// Equality operator.
      NL_BOOL operator!= ( const ColorGradient& v ) const
      { 
        return colorGradient_.operator!=( v.colorGradient_ );
      }

      /// @return The gradient color at the specified position.
      void evaluate( const float& position, std::vector< float >& outColor ) const
      {
        return colorGradient_.evaluate( position, outColor );
      }
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @private Methods:
      //  @{ 
    protected:

      // getRefAsNl_Vec
      const Sdk_ColorGradient& getRefAsNl_Vec() const { return colorGradient_; }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:
      Sdk_ColorGradient colorGradient_;

      friend class RFSdkBasicLib;
      friend class Object;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_VECTOR_H...





