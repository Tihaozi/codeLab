
#ifndef _NL_SDK_COLOR_H
#define _NL_SDK_COLOR_H

// BASIC INCLUDES
#include <core/nl_basic.h>
//#include <color/nl_color4.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/vector.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  //FORWARD DECLARATIONS
  template< class T >
  class Tuple4;

  template< class T >
  class Vector3;

  template< class T >
  class Vector4;

  template< class T >
  class Color4;

  namespace rf_sdk
  {

    template< class T >
    class RFBaseObj;

    //FORWARD DECLARATIONS
    class Object;
    class PB_Particle;

    //-----------------------------------------------------------------------------------
    //
    // Color:
    //
    //-----------------------------------------------------------------------------------  
    class RF_SDK_EXPORTS_DLL Color
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor from void
      Color( void );

      /// Constructor from another color.
      /// @param v [in] Source color.
      Color( const Color& c );

      /// Constructor from vector3 and alpha
      /// @param v3 [in] Source vector3.
      /// @param a [in] Source alpha.
      explicit Color( const Vector& v, const NL_FLOAT& a = 1 );

      /// Constructor from the color components.
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      Color(  const NL_FLOAT& r,
              const NL_FLOAT& g,
              const NL_FLOAT& b,
              const NL_FLOAT& a = 1 );

      /// Constructor from the color NL_BYTE components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      Color(  const NL_BYTE& r,
              const NL_BYTE& g,
              const NL_BYTE& b,
              const NL_BYTE& a );

      /// Constructor from the color NL_BYTE components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      Color(  const NL_BYTE& r,
              const NL_BYTE& g,
              const NL_BYTE& b  );

      /// Constructor from the color NL_INT components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      Color( const NL_INT& r,
             const NL_INT& g,
             const NL_INT& b,
             const NL_INT& a );

      /// Constructor from the color NL_INT components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      Color( const NL_INT& r,
             const NL_INT& g,
             const NL_INT& b );

      /// Constructor from a value to initialize all the components.
      /// @param c [in] Value for the three components.
      explicit Color( const NL_FLOAT& gray );

      /// Destructor
      ~Color( void );

    protected:
      explicit Color( const Vector4<NL_FLOAT>& v );
      explicit Color( const Vector3<NL_FLOAT>& v, const NL_FLOAT& a = 1 );
      explicit Color( const Color4<NL_FLOAT>& c );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Access:
      //  @{ 
    public:

      /// @return true if is Valid
      NL_BOOL isValid( void ) const;

      /// @return reference coord at index "i".
      NL_FLOAT& operator[]( const NL_INT& i );

      /// @return const reference coord at index "i".
      const NL_FLOAT& operator[]( const NL_INT& i ) const;

      /// @return get red color
      const NL_FLOAT& getRed( void ) const;

      /// @return get green color
      const NL_FLOAT& getGreen( void ) const;

      /// @return get blue color
      const NL_FLOAT& getBlue( void ) const;

      /// @return alpha
      const NL_FLOAT& getAlpha( void ) const;

      /// castToPtr
      NL_FLOAT* castToPtr();

      /// castToPtr
      const NL_FLOAT* castToPtr() const;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Access Static:
      //  @{ 
    public:

      static       Color& castFromPtr(       NL_FLOAT* pointer );
      static const Color& castFromPtr( const NL_FLOAT* pointer );

      static const Color& colorWhite ();
      static const Color& colorBlack ();

      static const Color& colorRed   ();
      static const Color& colorGreen ();
      static const Color& colorBlue  ();

      static const Color& colorYellow();
      static const Color& colorCyan  ();
      static const Color& colorPink  ();


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Set:
      //  @{ 
    public:

      /// Set the color components values.
      /// @param r [in] X color coord.
      /// @param g [in] Y color coord.
      /// @param b [in] Z color coord.
      void set( const NL_FLOAT& r,
                const NL_FLOAT& g,
                const NL_FLOAT& b,
                const NL_FLOAT& a = NL_FLOAT(1) );

      /// Constructor from the color INTEGER components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      void setInteger( const NL_INT& r,
                       const NL_INT& g,
                       const NL_INT& b,
                       const NL_INT& a );

      /// Constructor from the color INTEGER components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      void setInteger( const NL_INT& r,
                       const NL_INT& g,
                       const NL_INT& b );

      /// Set to other color.
      /// @param v [in] color desired .
      void set( const Color& v );

      /// Set all rgb values to gray
      /// @param gray [in] desired value for all the components.
      void setGray( const NL_FLOAT& gray, const NL_FLOAT& alpha = NL_FLOAT(1) );

      /// @param r [in] New value for the red component
      void setRed( const NL_FLOAT& r );

      /// @param g [in] New value for the green component
      void setGreen( const NL_FLOAT& g );

      /// @param b [in] New value for the blue component
      void setBlue( const NL_FLOAT& b );

      /// @param a [in] New value for the alpha component
      void setAlpha( const NL_FLOAT& a );

      /// Set the color components to 0.
      void setZero( void );

      /// Set sum of colors c and d Allowed use this as c or d
      void setSum( const Color& c, const Color& d );

      /// Set the difference of colors c and d. Allowed use this as d or d
      void setSub( const Color& c, const Color& d );

      /// Set the color interpolated c * ( 1 - rate ) + d * rate
      /// @param d [in] color to set if rate == 0
      /// @param d [in] color to set if rate == 1
      /// @param rate [in] parameter of interpolation
      void setInterpolation( const Color& c, const Color& d, const NL_FLOAT& rate );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: =
      //  @{ 
    public:

      /// Assignment operator.
      void operator= ( const Color& c );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: Compare
      //  @{ 
    public:

      /// Equality operator.
      NL_BOOL operator== ( const Color& c ) const;


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: +, -
      //  @{ 
    public:

      /// Negate color components.
      Color operator- ( void ) const;

      /// Return Sum
      Color operator+ ( const Color& c ) const;

      /// Return Difference
      Color operator- ( const Color& c ) const;

      /// Add other color to this
      void operator+= ( const Color& c );

      /// Subtract other color to this
      void operator-= ( const Color& c );


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: *, /
      //  @{ 
    public:

      /// Multiply color by scalar.
      Color operator* ( const NL_FLOAT& scalar ) const;

      /// Divide color by scalar.
      Color operator/ ( const NL_FLOAT& scalar ) const;

      /// Multiply this by scalar
      void operator*= ( const NL_FLOAT& scalar );

      /// Divide this color by scalar.
      void operator/= ( const NL_FLOAT& scalar );


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operations:
      //  @{ 
    public:

      /// Negate the color.
      void negate();

      /// Scale every coord of this with every coord of v.
      void scale( const Color& c );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      //
      const Tuple4<NL_FLOAT>& getTuple4() const;

      //
      const Vector4<NL_FLOAT>& v4() const;
 
      //
      Vector4<NL_FLOAT>& v4();
 
      //
      const Vector4<NL_FLOAT>& getVector4() const;

      //
      Vector4<NL_FLOAT>& getVector4();

      //
      const Vector3<NL_FLOAT>& getVector3() const;

      //
      Vector3<NL_FLOAT>& getVector3();

      //
      const Vector3<NL_FLOAT>& v3() const;

      //
      Vector3<NL_FLOAT>& v3();

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      // !@name Data Members:
      //  @{
    public:

      NL_FLOAT r_;
      NL_FLOAT g_;
      NL_FLOAT b_;
      NL_FLOAT a_;
      // nl::Color4<NL_FLOAT> _color4F;


      template< class T >
      friend class RFBaseObj;
    };

    //typedef Color<NL_INT> ColorInt;

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_COLOR_H...





