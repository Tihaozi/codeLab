
#ifndef _NL_SDK_COLOR4_H
#define _NL_SDK_COLOR4_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/util/sdk_vector3.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //FORWARD DECLARATIONS
    class Object;
    class Particle;

    //-----------------------------------------------------------------------------------
    //
    // Color4:
    //
    //-----------------------------------------------------------------------------------
    template<class T>    
    class RF_SDK_EXPORTS_DLL Color4
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor from void
      Color4( void ) : r_( 0.0 ),
                       g_( 0.0 ),
                       b_( 0.0 ),
                       a_( 1.0 ) {};

      /// Constructor from another color.
      /// @param v [in] Source color.
      Color4( const Color4& c ) : r_( c.r_ ),
                                  g_( c.g_ ),
                                  b_( c.b_ ),
                                  a_( c.a_ ) 
      {
        NL_ASSERT( isValid() );
      }




      /// Constructor from vector3 and alpha
      /// @param v3 [in] Source vector3.
      /// @param a [in] Source alpha.
      explicit Color4( const rf_sdk::Vector& v, const T& a = 1 ) : r_( v[0] ),
                                                                   g_( v[1] ),
                                                                   b_( v[2] ),
                                                                   a_( a )
      {
        NL_ASSERT( isValid() );
      }

      /// Constructor from the color components.
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      Color4( const T& r,
              const T& g,
              const T& b,
              const T& a = 1 ) : r_( r ),
                                 g_( g ),
                                 b_( b ),
                                 a_( a )
      {
        NL_ASSERT( isValid() );
      }

      /// Constructor from the color FLOATING components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      template< class U >
      Color4( const U& r,
              const U& g,
              const U& b,
              const U& a ): r_( NL_castNumber<T>( r ) ),
                            g_( NL_castNumber<T>( g ) ),
                            b_( NL_castNumber<T>( b ) ),
                            a_( NL_castNumber<T>( a ) )
      {
        NL_ASSERT( NL_isFloating<U>() );
        NL_ASSERT( isValid() );
      }

      /// Constructor from the color FLOATING components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      template< class U >
      Color4( const U& r,
              const U& g,
              const U& b ): r_( NL_castNumber<T>( r ) ),
                            g_( NL_castNumber<T>( g ) ),
                            b_( NL_castNumber<T>( b ) ),
                            a_( NL_castNumber<T>( 1 ) )
      {
        NL_ASSERT( NL_isFloating<U>() );
        NL_ASSERT( isValid() );
      }

      /// Constructor from the color NL_BYTE components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      Color4( const NL_BYTE& r,
              const NL_BYTE& g,
              const NL_BYTE& b,
              const NL_BYTE& a )
      {
        setInteger( r, g, b, a );
      }

      /// Constructor from the color NL_BYTE components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      Color4( const NL_BYTE& r,
              const NL_BYTE& g,
              const NL_BYTE& b)
      {
        setInteger( r, g, b );
      }

      /// Constructor from the color NL_INT components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      Color4( const NL_INT& r,
              const NL_INT& g,
              const NL_INT& b,
              const NL_INT& a )
      {
        setInteger( r, g, b, a );
      }

      /// Constructor from the color NL_INT components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      Color4( const NL_INT& r,
              const NL_INT& g,
              const NL_INT& b)
      {
        setInteger( r, g, b );
      }

      /// Constructor from a value to initialize all the components.
      /// @param c [in] Value for the three components.
      explicit Color4( const T& gray ) : r_( gray ),
                                         g_( gray ),
                                         b_( gray ),
                                         a_( 1 )
      {
        NL_ASSERT( isValid() );
      }

      /// Destructor
      ~Color4( void ) {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Access:
      //  @{ 
    public:

      /// @return as const Vector3.
      const Vector3<T>& getVector3() const { return( v4().v3() ); }

      /// @return as const Vector3.
      const Vector3<T>& v3() const { return( getVector3() ); }

      /// @return as Vector3.
      Vector3<T>& v3() { return( getVector3() ); }

      /// @return true if is Valid
      NL_BOOL isValid( void ) const 
      { 
        return_and5( getTuple4().isValid(),
          NL_isInsideInterval<T>( r_, (T)0.0, (T)1.0 ),
          NL_isInsideInterval<T>( g_, (T)0.0, (T)1.0 ),
          NL_isInsideInterval<T>( b_, (T)0.0, (T)1.0 ),
          NL_isInsideInterval<T>( a_, (T)0.0, (T)1.0 ) );
      }

      /// @return reference coord at index "i".
      template<class I>
      T& operator[]( const I& i ) { return( v4()[i] ); }

      /// @return const reference coord at index "i".
      template<class I>
      const T& operator[]( const I& i ) const { return( v4()[i] ); }

      /// @return get red color
      const T& getRed( void ) const { return( r_ ); };

      template< class M >
      const M getRedDiscrete( void ) const 
      { 
        return(  NL_minimum<M>() + NL_castNumber<M>( r_ * ( NL_maximum<M>() - NL_minimum<M>() ) ) );
      }

      /// @return get green color
      const T& getGreen( void ) const { return( g_ ); };

      template< class M >
      const M getGreenDiscrete( void ) const 
      { 
        return(  NL_minimum<M>() + NL_castNumber<M>( g_ * ( NL_maximum<M>() - NL_minimum<M>() ) ) );
      }

      /// @return get blue color
      const T& getBlue( void ) const { return( b_ ); };

      template< class M >
      const M getBlueDiscrete( void ) const 
      { 
        return(  NL_minimum<M>() + NL_castNumber<M>( b_ * ( NL_maximum<M>() - NL_minimum<M>() ) ) );
      }

      /// @return alpha
      const T& getAlpha( void ) const { return( a_ ); };

      template< class M >
      const M getAlphaDiscrete( void ) const 
      { 
        return(  NL_minimum<M>() +  NL_castNumber<M>( a_ * ( NL_maximum<M>() - NL_minimum<M>() ) ) );
      }

      /// castToPtr
      T* castToPtr() { return( (T*) this ); }

      /// castToPtr
      const T* castToPtr() const { return( ( const T*) this ); }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Access Static:
      //  @{ 
    public:

      static       Color4& castFromPtr(       T* pointer ) { return( *( (      Color4*) pointer ) ); }
      static const Color4& castFromPtr( const T* pointer ) { return( *( (const Color4*) pointer ) ); }

      static const Color4& colorWhite () { return( castFromPtr( constants::get_P1_P1_P1_P1<T>() ) ); }
      static const Color4& colorBlack () { return( castFromPtr( constants::get_Z0_Z0_Z0_P1<T>() ) ); }

      static const Color4& colorRed   () { return( castFromPtr( constants::get_P1_Z0_Z0_P1<T>() ) ); }
      static const Color4& colorGreen () { return( castFromPtr( constants::get_Z0_P1_Z0_P1<T>() ) ); }
      static const Color4& colorBlue  () { return( castFromPtr( constants::get_Z0_Z0_P1_P1<T>() ) ); }

      static const Color4& colorYellow() { return( castFromPtr( constants::get_P1_P1_Z0_P1<T>() ) ); }
      static const Color4& colorCyan  () { return( castFromPtr( constants::get_Z0_P1_P1_P1<T>() ) ); }
      static const Color4& colorPink  () { return( castFromPtr( constants::get_P1_Z0_P1_P1<T>() ) ); }

      static const Color4& colorBasic( const NL_INDEX& i )
      { 
        switch( i % 7 )
        {
          CASE  0: return( colorRed   () );
          CASE  1: return( colorGreen () );
          CASE  2: return( colorBlue  () );
          CASE  3: return( colorYellow() );
          CASE  4: return( colorCyan  () );
          CASE  5: return( colorPink  () );
          CASE  6: return( colorWhite () );

          DEFAULT:
          return( colorWhite() );
        }
      }

      static Color4 colorBasic49( const NL_INDEX& i )
      {
        NL_INDEX i0 = i % 7;
        NL_INDEX i1 = ( i0 + i / 7 ) % 7;

        Color4 c0 = colorBasic( i0 );
        Color4 c1 = colorBasic( i1 );

        Color4 c;
        c.setInterpolation( c0, c1, T(0.25) );
        return( c );
      }

      static const Color4& colorBasicRand()
      {
        return( colorBasic( rand() % 6 ) );
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Set:
      //  @{ 
    public:

      /// Set the color components values.
      /// @param r [in] X color coord.
      /// @param g [in] Y color coord.
      /// @param b [in] Z color coord.
      void set( const T& r,
        const T& g,
        const T& b,
        const T& a = T(1) ) 
      { 
        NL_ASSERT_4( NL_isInsideInterval<T>( r, (T)0.0, (T)1.0 ),
          NL_isInsideInterval<T>( g, (T)0.0, (T)1.0 ),
          NL_isInsideInterval<T>( b, (T)0.0, (T)1.0 ),
          NL_isInsideInterval<T>( a, (T)0.0, (T)1.0 ) );
        v4().set( r, g, b, a ); 
      }

      /// Constructor from the color INTEGER components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      template< class U >
      void setInteger( const U& r,
        const U& g,
        const U& b,
        const U& a )
      {
        NL_ASSERT( NL_isInteger<U>() );
        r_ = NL_rateInterval<T,U>( r, 0, 255 );
        g_ = NL_rateInterval<T,U>( g, 0, 255 );
        b_ = NL_rateInterval<T,U>( b, 0, 255 );
        a_ = NL_rateInterval<T,U>( a, 0, 255 );
        NL_ASSERT( isValid() );
      }

      /// Constructor from the color INTEGER components
      /// @param r [in]
      /// @param g [in]
      /// @param b [in]
      /// @param a [in]
      template< class U >
      void setInteger( const U& r,
        const U& g,
        const U& b )
      {
        NL_ASSERT( NL_isInteger<U>() );
        r_ = NL_rateInterval<T,U>( r, 0, 255 );
        g_ = NL_rateInterval<T,U>( g, 0, 255 );
        b_ = NL_rateInterval<T,U>( b, 0, 255 );
        a_ = T(1);
        NL_ASSERT( isValid() );
      }

      /// Set the color components values.
      /// @param t [in] tuple4 of floats
      template< class U >
      void set( const Tuple4<U>& t )
      {
        set( t[0], t[1], t[2], t[3] );
      }

      /// Set the color components values.
      /// @param t [in] tuple4 of integers
      template< class U >
      void setInteger( const Tuple4<U>& t )
      {
        setInteger( t[0], t[1], t[2], t[3] );
      }

      /// Set the color components values.
      /// @param t [in] tuple3 of floats
      template< class U >
      void set( const Tuple3<U>& t )
      {
        set( t[0], t[1], t[2] );
      }

      /// Set the color components values.
      /// @param t [in] tuple3 of integers
      template< class U >
      void setInteger( const Tuple3<U>& t )
      {
        setInteger( t[0], t[1], t[2] );
      }

      /// Set to other color.
      /// @param v [in] color desired .
      void set( const Color4& v ) 
      { 
        NL_ASSERT( v.isValid );
        operator=( v ); 
      }

      /// Set all rgb values to gray
      /// @param gray [in] desired value for all the components.
      void setGray( const T& gray, const T& alpha = T(1) ) 
      { 
        NL_ASSERT( NL_isInsideInterval<T>( gray,  (T)0.0, (T)1.0 ) );
        NL_ASSERT( NL_isInsideInterval<T>( alpha, (T)0.0, (T)1.0 ) );
        r_ = gray;
        g_ = gray;
        b_ = gray;
        a_ = alpha; 
      }

      /// Set components casting to T
      template< class N >
      void setCast( const N& r,
        const N& g,
        const N& b,
        const N& a ) 
      { 
        v4().setCast( r, g, b, a );      
      }

      /// @param r [in] New value for the red component
      void setRed( const T& r ) 
      { 
        NL_ASSERT( NL_isInsideInterval<T>( r, (T)0.0, (T)1.0 ) );
        r_ = r; 
      }

      /// @param g [in] New value for the green component
      void setGreen( const T& g ) 
      { 
        NL_ASSERT( NL_isInsideInterval<T>( g, (T)0.0, (T)1.0 ) );
        g_ = g; 
      }

      /// @param b [in] New value for the blue component
      void setBlue( const T& b ) 
      { 
        NL_ASSERT( NL_isInsideInterval<T>( b, (T)0.0, (T)1.0 ) );
        b_ = b; 
      }

      /// @param a [in] New value for the alpha component
      void setAlpha( const T& a ) 
      { 
        NL_ASSERT( NL_isInsideInterval<T>( a, (T)0.0, (T)1.0 ) );
        a_ = a; 
      }

      /// Set the color components to 0.
      void setZero( void ) { operator=( colorBlack() ); }

      /// Set sum of colors c and d Allowed use this as c or d
      void setSum( const Color4& c, const Color4& d ) 
      { 
        NL_ASSERT_2( c.isValid(), d.isValid() );
        v4().setSum( c.v4(), d.v4() ); 
      }

      /// Set the difference of colors c and d. Allowed use this as d or d
      void setSub( const Color4& c, const Color4& d ) 
      { 
        NL_ASSERT_2( c.isValid(), d.isValid() );
        v4().setSub( c.v4(), d.v4() ); 
      }

      /// Set the color interpolated c * ( 1 - rate ) + d * rate
      /// @param d [in] color to set if rate == 0
      /// @param d [in] color to set if rate == 1
      /// @param rate [in] parameter of interpolation
      void setInterpolation( const Color4& c, const Color4& d, const T& rate )
      {
        NL_ASSERT( NL_isInsideInterval<T>( rate, (T)0.0, (T)1.0 ) );
        NL_ASSERT_2( c.isValid(), d.isValid() );
        v4().setInterpolation( c.v4(), d.v4(), rate );
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: =
      //  @{ 
    public:

      /// Assignment operator.
      void operator= ( const Color4& c ) 
      { 
        NL_ASSERT( c.isValid() );
        v4() = c.v4(); 
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: Compare
      //  @{ 
    public:

      /// Equality operator.
      NL_BOOL operator== ( const Color4& c ) const
      { 
        return( v4() == c.v4() );
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: +, -
      //  @{ 
    public:

      /// Negate color components.
      Color4 operator- ( void ) const
      { 
        return( Color4( -v4() ) );		
      }

      /// Return Sum
      Color4 operator+ ( const Color4& c ) const
      { 
        NL_ASSERT( c.isValid() );
        return( Color4( v3() + c.v3() ) );		
      }

      /// Return Difference
      Color4 operator- ( const Color4& c ) const
      { 
        NL_ASSERT( c.isValid() );
        return( Color4( v3() - c.v3() ) );		
      }

      /// Add other color to this
      void operator+= ( const Color4& c )
      { 
        NL_ASSERT( c.isValid() );
        v3() += c.v3();
      }

      /// Subtract other color to this
      void operator-= ( const Color4& c )
      { 
        NL_ASSERT( c.isValid() );
        v3() -= c.v3();
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: *, /
      //  @{ 
    public:

      /// Multiply color by scalar.
      Color4 operator* ( const T& scalar ) const
      { 
        return( Color4( v3() * scalar ) );		
      }

      /// Divide color by scalar.
      Color4 operator/ ( const T& scalar ) const
      { 
        return( Color4( v3() / scalar ) );		
      }

      /// Multiply this by scalar
      void operator*= ( const T& scalar )
      { 
        v3() *= scalar;
      }

      /// Divide this color by scalar.
      void operator/= ( const T& scalar )
      { 
        v3() /= scalar;
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operations:
      //  @{ 
    public:

      /// Negate the color.
      void negate()
      {
        v3().negate();
      }

      /// Scale every coord of this with every coord of v.
      void scale( const Color4& c )
      {
        NL_ASSERT( c.isValid() );
        v3().scale( c.v3() );
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      // !@name Data Members:
      //  @{
    public:

      T r_;
      T g_;
      T b_;
      T a_;

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_COLOR4_H...





