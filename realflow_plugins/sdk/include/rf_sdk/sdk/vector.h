
#ifndef _NL_SDK_VECTOR_H
#define _NL_SDK_VECTOR_H

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
    class PB_Particle;

    //-----------------------------------------------------------------------------------
    //
    // Vector:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Vector
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      Vector( void ) : vector_( nl_init_to_0 ) {};

      Vector
        (  
          const float& x,
          const float& y,
          const float& z ) : vector_( x, y, z ) {};

      /// Destructor
      ~Vector( void ) {};

    protected:
      Vector( const Sdk_Vector3F& vector ) : vector_( vector ) {};

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
      void operator= ( const Vector& v )
      {
        return vector_.operator=( v.vector_ );	
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: Compare
      //  @{ 
    public:

      /// Equality operator.
      NL_BOOL operator== ( const Vector& v) const
      { 
        return vector_.operator==( v.vector_ );	
      }

      /// Equality operator.
      NL_BOOL operator!= ( const Vector& v ) const
      { 
        return vector_.operator!=( v.vector_ );	
      }

      /// @retval True if both vectors are nearly equal
      NL_BOOL isEqual( const Vector& v,
                       const float tolerance = NL_epsilon( 100.0f ) ) const
      {
        return vector_.isEqual( v.vector_, tolerance );	
      }


      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: +, -
      //  @{ 
    public:

      /// Negate vector coords.
      Vector operator- ( void ) const
      { 
        return Vector( vector_.operator-() );	
      }

      /// Return Sum
      Vector operator+ ( const Vector& v ) const
      { 
        return Vector( vector_.operator+( v.vector_ ) );	
      }

      /// Return Difference
      Vector operator- ( const Vector& v ) const
      { 
        return Vector( vector_.operator-( v.vector_ ) );	
      }

      /// Add other vector to this
      void operator+= ( const Vector& v )
      { 
        vector_.operator+=( v.vector_ );	
      }

      /// Subtract other vector to this
      void operator-= ( const Vector& v )
      { 
        vector_.operator-=( v.vector_ );	
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operators: *, /
      //  @{ 
    public:

      /// Multiply vector by scalar.
      Vector operator* ( const float& c ) const
      { 
        return Vector( vector_.operator*( c ) );	
      }

      /// Divide vector by scalar.
      Vector operator/ ( const float& c ) const
      { 
        return Vector( vector_.operator/( c ) );	
      }

      /// Multiply this by scalar
      void operator*= ( const float& c )
      { 
        vector_.operator*=( c );		
      }

      /// Divide this vector by scalar.
      void operator/= ( const float& c )
      { 
        vector_.operator/=( c );		
      }

      /// Access function for the X coord.
      /// @return X vector coord.
      float getX( void ) const
      {
        return vector_.getX();
      }

      /// Access function for the Y coord.
      /// @return Y vector coord.
      float getY( void ) const
      {
        return vector_.getY();
      }

      /// Access function for the Y coord.
      /// @return Y vector coord.
      float getZ( void ) const
      {
        return vector_.getZ();
      }

      /// Set the X coord value.
      /// @param value [in] New value for the X coord.
      void setX( const float& x )
      {
        vector_.setX( x );
      }

      /// Set the Y coord value.
      /// @param value [in] New value for the Y coord.
      void setY( const float& y )
      {
        vector_.setY( y );
      }

      /// Set the Z coord value.
      /// @param value [in] New value for the Z coord.
      void setZ( const float& z )
      {
        vector_.setZ( z );
      }

      /// Set the vector coords values.
      /// @param x [in] X vector coord.
      /// @param y [in] Y vector coord.
      /// @param z [in] Z vector coord.
      void set
        ( const float& x,
          const float& y,
          const float& z 
        ) 
      {
        vector_.set( x, y, z );
      }

      /// Set the vector to 0.
      void setZero( void ) { vector_.setZero(); }

      /// @retval True if is Zero vector
      NL_BOOL isZero() const
      {
        return vector_.isZero();
      }

      /// @return The vector's module.
      float module( void ) const
      {
        return vector_.module();
      }

      /// Calculate cross product of this vector with vector v
      Vector cross( const Vector& v ) const
      {
        return ( Vector( rf_sdk::cross( vector_, v.vector_ ) ) );
      }// cross...

      /// Calculate cross product of vectors v1 and v2
      static Vector cross( const Vector& v1,
                                   const Vector& v2  )
      {
        return ( Vector( rf_sdk::cross( v1.vector_, v2.vector_ ) ) );
      }// dot( a, b...

      /// Calculate Dot product of this vector with vector v
      float dot( const Vector& v  ) const
      {
        return ( nl::rf_sdk::dot( vector_, v.vector_ ) );
      }// dot( a, b...

      /// Calculate Dot product of vectors v1 and v2
      static float dot( const Vector& v1,
                        const Vector& v2  )
      {
        return ( nl::rf_sdk::dot( v1.vector_, v2.vector_ ) );
      }// dot( a, b...


      /// calculate Angle between of this vector with vector v
      float calculateAngle( const Vector& v ) const
      {
        return ( nl::rf_sdk::Sdk_Vector3F::calculateAngle( vector_, v.vector_ ) );
      }// calculateAngle...

      /// calculate Angle between vectors v1 and v2
      static float calculateAngle( const Vector& v1,
                                   const Vector& v2  )
      {
        return ( nl::rf_sdk::Sdk_Vector3F::calculateAngle( v1.vector_, v2.vector_ ) );
      }// calculateAngle...

      /// Normalizes the vector.
      void normalize( void )
      {
        vector_.normalize();
      }

      /// Calculate distance between this vector and vector v
      float distance( const Vector& v ) const
      {
        return ( nl::rf_sdk::distance( vector_, v.vector_ ) );
      }// distance...

      /// Scale
      void scale( const float& scale )
      {
        vector_.scale( scale );
      }// Scale...

      /// @return const reference coord at index "i". (0,1,2)
      const float& operator[]( int i ) const
      {
        return vector_[i];
      }

      /// @return const reference coord at index "i". (0,1,2)
      float& operator[]( int i ) 
      {
        return vector_[i];
      }

      /// getEulerAngles
      Vector getEulerAngles( Vector vec );

      /// rotate
      Vector rotate( float x, float y, float z ); 

      /// rotateAroundAxis
      Vector rotateAroundAxis( Vector rotAxis, float angle ); 
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name cast
      //  @{ 
    public:

      /// castToPtr
      float* castToPtr() { return( (float*) this ); }

      /// castFromPtr
      Vector& castFromPtr(       float* pointer ) { return( *( (      Vector*) pointer ) ); }

      /// castFromPtr
      const Vector& castFromPtr( const float* pointer ) { return( *( (const Vector*) pointer ) ); }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @private Methods:
      //  @{ 
    protected:

      // getRefAsNl_Vec
      const Sdk_Vector3F& getRefAsNl_Vec() const { return vector_; }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:
      Sdk_Vector3F vector_;

      friend class rf_sdk::PB_Particle;
      friend class RFSdkBasicLib;
      friend class Object;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_VECTOR_H...





