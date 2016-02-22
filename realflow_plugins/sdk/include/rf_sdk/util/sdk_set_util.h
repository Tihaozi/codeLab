
#ifndef _SDK_SET_UTIL_H
#define _SDK_SET_UTIL_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#include <nl_vector3.h>
#include <core/nl_set.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include NL_END_DISABLE_WARNINGS


// EXTERNAL INCLUDES
#include <rf_common/core/nl_set_check.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  // REST
#include "rf_sdk/util/sdk_vector3.h"
#include "rf_sdk/sdk/vector.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //  
  // NL_set for vectors
  //
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  
  template< class T_DEST, class T_ORIG >
  void NL_set_vec( T_DEST& dest, const T_ORIG& orig )
  {
    NL_set( dest[ 0 ], orig[ 0 ] );
    NL_set( dest[ 1 ], orig[ 1 ] );
    NL_set( dest[ 2 ], orig[ 2 ] );
  }

  // assigns 
  template<> inline
  void NL_set( nl::Vector3F& dest, const nl::rf_sdk::Sdk_Vector3F& orig )
  {
    NL_set_vec( dest, orig );
  }

  // assigns 
  template<> inline
  void NL_set( nl::Vector3F& dest, const nl::rf_sdk::Vector& orig )
  {
    NL_set_vec( dest, orig );
  }

  // assigns 
  template<> inline
    void NL_set( std::vector<int>& dest, const nl::Vector3<NL_INT>& orig )
  {
    NL_ASSERT( dest.size() == 3 );

    NL_set_vec( dest, orig );
  }

  // assigns 
  template<> inline
  void NL_set( nl::Tuple3_INT& dest, const std::vector<int>& orig )
  {
    NL_set_vec( dest, orig );
  }

  // assigns 
  template<> inline
  void NL_set( nl::rf_sdk::Vector& dest, const Vector3F& orig )
  {
    NL_set_vec( dest, orig );
  }

  // assigns 
  template<> inline
  void NL_set( nl::Vector3D& dest, const nl::rf_sdk::Vector& orig )
  {
    NL_set_vec( dest, orig );
  }

  // assigns 
  template<> inline
    void NL_set( nl::rf_sdk::Vector& dest, const nl::Vector3D& orig )
  {
    NL_set_vec( dest, orig );
  }

  //
  template< class T_ORIG >
  const nl::rf_sdk::Vector& NL_cast_ToSdkVector( const T_ORIG& orig )
  {
    NL_BREAKPOINT;
    return nl::rf_sdk::Vector();
  }  

  //
  template< class T_ORIG >
  nl::rf_sdk::Vector& NL_cast_ToSdkVector( T_ORIG& orig )
  {
    NL_BREAKPOINT;
    static nl::rf_sdk::Vector NON_VALID_VALUE;
    return NON_VALID_VALUE;
  }  

  //
  template<> inline
  nl::rf_sdk::Vector& NL_cast_ToSdkVector( nl::Vector3F& orig )
  {
    return ( ( nl::rf_sdk::Vector& ) orig );
  }

  //
  template<> inline
  const nl::rf_sdk::Vector& NL_cast_ToSdkVector( const nl::Vector3F& orig )
  {
    return ( ( const nl::rf_sdk::Vector& ) orig );
  }

  //
  template< class T_ORIG >
  const nl::Vector3F& NL_cast_ToVector3F( const T_ORIG& orig )
  {
    NL_BREAKPOINT;
    return Vector3F();
  }

  //
  template< class T_ORIG >
  nl::Vector3F& NL_cast_ToVector3F( T_ORIG& orig )
  {
    NL_BREAKPOINT;
    static Vector3F NON_VALID_VALUE;
    return NON_VALID_VALUE;
  }

  //
  template<> inline
  nl::Vector3F& NL_cast_ToVector3F( nl::rf_sdk::Vector& orig )
  {
    return ( ( nl::Vector3F& ) orig );
  }

  //
  template<> inline
  const nl::Vector3F& NL_cast_ToVector3F( const nl::rf_sdk::Vector& orig )
  {
    return ( ( const nl::Vector3F& ) orig );
  }

  //
  //template< class SDK_CLASS, class RF_CLASS > inline
  //void NL_set( std::vector< SDK_CLASS >& dest, const std::vector< RF_CLASS* >& orig )
  //{
  //  dest.clear();

  //  I_FOR( orig )
  //  { setWaveParameter( string, string, any ) 
  //    dest.push_back( SDK_CLASS( orig[ i ] ) );
  //  }
  //}  

  //
  //template<> inline
  //  void NL_set( std::vector< nl::rf_sdk::Vector >& dest, const std::vector< nl::Vector3F >& orig )
  //{
  //  dest.clear();

  //  I_FOR( orig )
  //  {
  //    nl::rf_sdk::Vector sdkVec;
  //    NL_set( sdkVec, orig[ i ] );
  //    dest.push_back( sdkVec );
  //  }
  //}  

 
} // NameSpace NextLimit...
#endif // _SDK_SET_UTIL_H...





