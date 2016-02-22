
#ifndef _SDK_VECTOR_3_H
#define _SDK_VECTOR_3_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL_BASIC
#include "indexes/nl_index.h"

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"

#ifdef _DEBUG_VECTOR3
  #define V3_ASSERT_IS_VALID( a ) NL_ASSERT_IS_VALID( a )
  #define V3_ASSERT_IS_VALID2( a, b ) NL_ASSERT_IS_VALID2( a, b )
  #define V3_ASSERT_IS_VALID3( a, b, c ) NL_ASSERT_IS_VALID3( a, b, c )
  #define V3_ASSERT_IS_VALID4( a, b, c, d ) NL_ASSERT_IS_VALID4( a, b, c, d )
#else
  #define V3_ASSERT_IS_VALID( a )
  #define V3_ASSERT_IS_VALID2( a, b )
  #define V3_ASSERT_IS_VALID3( a, b, c )
  #define V3_ASSERT_IS_VALID4( a, b, c, d )
#endif

#if !defined( NL_PI )
# define NL_PI   3.1415926535897932384626433832795
#endif

#if !defined( NL_PI_f )
# define NL_PI_f 3.1415926535897932384626433832795f
#endif

/// @return square of input
template <class T>
T NL_sq( const T& a )
{
  NL_ASSERT_IS_VALID( a );
  return( a * a );
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {


    /// @return true if a and b are equal with tolerance
    template <class T>
    NL_BOOL NL_isEqualScalar( const T& a, const T& b, const T& tolerance )
    {
      NL_ASSERT_IS_VALID3( a, b, tolerance );
      NL_ASSERT( tolerance >= T(0) );
      if ( a < b )
      {
        return( a + tolerance >= b  );
      }
      else
      {
        return( b + tolerance >= a  );
      }
    }


    //-----------------------------------------------------------------------------------
    //
    // Sdk_Vector3:
    //
    //-----------------------------------------------------------------------------------
    template <class T>
    class RF_SDK_EXPORTS_DLL Sdk_Vector3
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor init 0
      explicit Sdk_Vector3( NL_INIT_TO_0 )
          : x_( NL_zero<T>() ),
            y_( NL_zero<T>() ),
            z_( NL_zero<T>() ) {}

      /// Constructor from the vector coords.
      /// @param x [in] X vector coord.
      /// @param y [in] Y vector coord.
      /// @param z [in] Z vector coord.
      Sdk_Vector3(  const T& x,
                    const T& y,
                    const T& z ) : x_( x ),
                               y_( y ),
                               z_( z )
      {
        V3_ASSERT_IS_VALID( *this );
      }

      /// Constructor copy from another vector.
      /// @param v [in] Source vector.
      Sdk_Vector3( const Sdk_Vector3& v )
          : x_( v.x_ ),
            y_( v.y_ ),
            z_( v.z_ )
      {
        V3_ASSERT_IS_VALID( *this );
      }

      /// Constructor of vector from point a to point b
      /// @param a [in] a start point.
      /// @param b [in] b end point.
      Sdk_Vector3( const Sdk_Vector3& a,
                   const Sdk_Vector3& b ) : x_( b.x_ - a.x_ ),
        y_( b.y_ - a.y_ ),
        z_( b.z_ - a.z_ )
      {
        V3_ASSERT_IS_VALID2( a, b );
      }

      /// Destructor
      ~Sdk_Vector3( void ) {};


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
      void operator= ( const Sdk_Vector3& v )
      {
        V3_ASSERT_IS_VALID( v );
        x_ = v.x_;
        y_ = v.y_; 
        z_ = v.z_;
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: Compare
      //  @{ 
    public:

      /// Equality operator.
      NL_BOOL operator== ( const Sdk_Vector3& v ) const
      { 
        V3_ASSERT_IS_VALID2( *this, v );
        return        ( x_ == v.x_ &&
                        y_ == v.y_ &&
                        z_ == v.z_    );
      }

      /// Equality operator.
      NL_BOOL operator!= ( const Sdk_Vector3& v ) const
      { 
        V3_ASSERT_IS_VALID2( *this, v );
        return  ( x_ != v.x_ ||
                  y_ != v.y_ ||
                  z_ != v.z_    );
      }

      /// @retval True if both vectors are nearly equal
      NL_BOOL isEqual( const Sdk_Vector3& v,
                       const T tolerance = NL_epsilon( T( 100.0 ) ) ) const
      {
        V3_ASSERT_IS_VALID3( *this, v, tolerance );
        return        ( NL_isEqualScalar( x_, v.x_, tolerance ) &&
                        NL_isEqualScalar( y_, v.y_, tolerance ) &&
                        NL_isEqualScalar( z_, v.z_, tolerance )     );
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: +, -
      //  @{ 
    public:

      /// Negate vector coords.
      Sdk_Vector3 operator- ( void ) const
      { 
        V3_ASSERT_IS_VALID( *this );
        return( Sdk_Vector3( -x_, -y_, -z_ ) );		
      }

      /// Return Sum
      Sdk_Vector3 operator+ ( const Sdk_Vector3& v ) const
      { 
        V3_ASSERT_IS_VALID2( *this, v );
        return( Sdk_Vector3(  x_ + v.x_,
                              y_ + v.y_,
                              z_ + v.z_ ) );	
      }

      /// Return Difference
      Sdk_Vector3 operator- ( const Sdk_Vector3& v ) const
      { 
        V3_ASSERT_IS_VALID2( *this, v );
        return( Sdk_Vector3(  x_ - v.x_,
                              y_ - v.y_,
                              z_ - v.z_ ) );	
      }

      /// Add other vector to this
      void operator+= ( const Sdk_Vector3& v )
      { 
        V3_ASSERT_IS_VALID2( *this, v );
        x_ += v.x_;
        y_ += v.y_;
        z_ += v.z_;		
      }

      /// Subtract other vector to this
      void operator-= ( const Sdk_Vector3& v )
      { 
        V3_ASSERT_IS_VALID2( *this, v );
        x_ -= v.x_;
        y_ -= v.y_;
        z_ -= v.z_;		
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: *, /
      //  @{ 
    public:

      /// Multiply vector by scalar.
      Sdk_Vector3 operator* ( const float& c ) const
      { 
        V3_ASSERT_IS_VALID2( *this, c );
        return( Sdk_Vector3(  x_ * c,
                              y_ * c,
                              z_ * c ) );	
      }

      /// Divide vector by scalar.
      Sdk_Vector3 operator/ ( const float& c ) const
      { 
        V3_ASSERT_IS_VALID2( *this, c );
        NL_ASSERT( NL_divisorAllowed( c ) );
        
        T inverseC = 1 / c;
        return( Sdk_Vector3(  x_ * inverseC,
                              y_ * inverseC,
                              z_ * inverseC ) );		
      }

      /// Multiply this by scalar
      void operator*= ( const float& c )
      { 
        V3_ASSERT_IS_VALID2( *this, c );
        x_ *= c;
        y_ *= c;
        z_ *= c;		
      }

      /// Divide this vector by scalar.
      void operator/= ( const float& c )
      { 
        V3_ASSERT_IS_VALID2 ( *this, c );
        NL_ASSERT( NL_divisorAllowed( c ) );
        T inverseC = 1 / c;
        operator *= ( inverseC );
      }

      /// Access function for the X coord.
      /// @return X vector coord.
      const T& getX( void ) const
      {
        V3_ASSERT_IS_VALID( *this );
        return( x_ );
      }

      /// Access function for the Y coord.
      /// @return Y vector coord.
      const T& getY( void ) const
      {
        V3_ASSERT_IS_VALID( *this );
        return( y_ );
      }

      /// Access function for the Y coord.
      /// @return Y vector coord.
      const T& getZ( void ) const
      {
        V3_ASSERT_IS_VALID( *this );
        return( z_ );
      }

      /// Set the X coord value.
      /// @param value [in] New value for the X coord.
      void setX( const T& x )
      {
        V3_ASSERT_IS_VALID( x );
        x_ = x;
      }

      /// Set the Y coord value.
      /// @param value [in] New value for the Y coord.
      void setY( const T& y )
      {
        V3_ASSERT_IS_VALID( y );
        y_ = y;
      }

      /// Set the Z coord value.
      /// @param value [in] New value for the Z coord.
      void setZ( const T& z )
      {
        V3_ASSERT_IS_VALID( z );
        z_ = z;
      }

      /// Set the vector coords values.
      /// @param x [in] X vector coord.
      /// @param y [in] Y vector coord.
      /// @param z [in] Z vector coord.
      void set( const T& x,
                const T& y,
                const T& z ) {  x_ = x;
                                y_ = y;
                                z_ = z;
                                V3_ASSERT_IS_VALID( *this ); }

      /// Set the vector to 0.
      void setZero( void ) { T zero(0);
                             x_= zero;
                             y_= zero;
                             z_= zero; }

      /// @retval True if is Zero vector
      NL_BOOL isZero() const
      {
        V3_ASSERT_IS_VALID( *this );
        return     ( x_ == 0 &&
                     y_ == 0 &&
                     z_ == 0    );
      }

      /// @return The vector module.
      T module( void ) const
      {
        return( T( moduleDouble() ) );
      }

      /// @return The vector module as double.
      NL_DOUBLE moduleDouble( void ) const
      {
        return( sqrt( (NL_DOUBLE) moduleSq() ) );
      }

      /// @return The vector module square.
      T moduleSq( void ) const
      {
        V3_ASSERT_IS_VALID( *this );
        return(   x_ * x_
                + y_ * y_ 
                + z_ * z_ );
      }

      /// Normalizes the vector.
      void normalize( void )
      {
        const T moduleaux = module(); 
        NL_ASSERT( NL_normalizeAllowedBy( moduleaux ) );
        operator /= ( moduleaux );
      }

      /// Scale
      void scale( const T& scale )
      {
        operator *= ( scale );
      }// Scale...

      /// @return const reference coord at index "i".
      template<class I>
      const T& operator[]( const I& i ) const
      {
        V3_ASSERT_IS_VALID( *this );
        return( at(i) );
      }

      /// @return reference coord at index "i".
      template<class I>
      T& operator[]( const I& i )
      {
        V3_ASSERT_IS_VALID( *this );
        return( at(i) );
      }

      template<class T_INDEX>
      T& at( const T_INDEX& i ) const
      {
        NL_ASSERT( NL_isInteger<T_INDEX>() );
        NL_ASSERT( isInRange( i ) );
        return( ( (T*) this )[ i ] );
      }

      static NL_INDEX size() { return( NL_INDEX( 3 ) ); }

      // isInRange
      static NL_BOOL isInRange( const NL_INDEX& index )
      {
        return( index < size() );
      }

      /// @return true if is Valid
      NL_BOOL isValid( void ) const
      {
        return ( NL_isValid( x_ ) &&
                 NL_isValid( y_ ) &&
                 NL_isValid( z_ ) );
      }

      /// calculate Angle between vA and vB
      static T calculateAngle( const Sdk_Vector3& vA,
                               const Sdk_Vector3& vB )
      {
        const NL_DOUBLE aSq_bSq = vA.moduleSq() * vB.moduleSq();
        const NL_DOUBLE dot_ab = dot( vA, vB );

        if ( aSq_bSq > NL_epsilonSqSq<T>() )
        {
          const NL_DOUBLE cos_ab = dot_ab / sqrt( aSq_bSq );
          const NL_DOUBLE abs_cos_ab = NL_abs( cos_ab );
          if ( abs_cos_ab >= 1.0 )
          {
            NL_ASSERT( ( abs_cos_ab - 1.0 ) < 0.0001f );
            return( 0 );
          }

          const T angle = static_cast<T>( acos( cos_ab ) );
          return( angle );
        }
        else
        {
          if ( dot_ab >= 0 )
          {
            return( 0 );
          }
          else
          {
            return( -NL_PI_f );
          }
        }

      }// calculateAngle...

      // getEulerAngles
      /*Sdk_Vector3 getEulerAngles( Sdk_Vector3 vec )
      {
        return (Sdk_Vector3) vector_.getEulerAngles( (Sdk_Vector3F) vec );
      }
*/

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    public:
      T x_;
      T y_;
      T z_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:


      // friend class rf_sdk::PB_Particle;
      //  friend class RFSdkBasicLib;
      //  friend class nl::rf_sdk::Object;
    };


    /// Calculate cross product of vectors a and b
    template <class T>
    Sdk_Vector3<T> cross( const Sdk_Vector3<T>& a, const Sdk_Vector3<T>& b )
    {
      V3_ASSERT_IS_VALID2( a, b );
      return( Sdk_Vector3<T>( a.y_ * b.z_ - a.z_ * b.y_, 
                              a.z_ * b.x_ - a.x_ * b.z_,
                              a.x_ * b.y_ - a.y_ * b.x_ ) );

    }// cross...


    /// Calculate Dot product of vectors a and b
    template <class T>
    T dot( const Sdk_Vector3<T>& a,
           const Sdk_Vector3<T>& b )
    {
      V3_ASSERT_IS_VALID2( a, b );
      return(   a.x_ * b.x_ 
              + a.y_ * b.y_ 
              + a.z_ * b.z_ );

    }// dot( a, b...

    /// Calculate distance between points a and b
    template <class T>
    T distanceSq( const Sdk_Vector3<T>& a,
      const Sdk_Vector3<T>& b )
    {
      V3_ASSERT_IS_VALID2( a, b );
      Sdk_Vector3<T> ab( a, b );
      return( ab.moduleSq() );

    }// distanceSq...


    /// Calculate distance between points a and b
    template <class T>
    T distance( const Sdk_Vector3<T>& a,
      const Sdk_Vector3<T>& b )
    {
      V3_ASSERT_IS_VALID2( a, b );
      Sdk_Vector3<T> ab( a, b );
      return( ab.module() );

    }// distance...


    //-----------------------------------------------------------------------------------
    //
    // Typedefs Sdk_Vector3:
    //
    //-----------------------------------------------------------------------------------
    typedef Sdk_Vector3< NL_FLOAT  > Sdk_Vector3F;
    typedef Sdk_Vector3< NL_DOUBLE > Sdk_Vector3D;
    typedef Sdk_Vector3< NL_INT >    Sdk_Vector3I;

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _SDK_VECTOR_3_H...





