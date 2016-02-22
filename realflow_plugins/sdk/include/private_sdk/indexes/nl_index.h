
#ifndef _NL_INDEX_H_
#define _NL_INDEX_H_

#include "core/nl_basic.h"


//-----------------------------------------------------------------------------------
//
// NL_INDEX, NL_INDEX16, NL_INDEX8
//
// Important: type definitions are out of nextlimit namespace
// Important: NL_INDEX is assured 32 bits !!!!!!!!
//-----------------------------------------------------------------------------------
typedef NL_UINT32 NL_INDEX;
typedef NL_UINT64 NL_INDEX64;
typedef NL_UINT32 NL_INDEX32;
typedef NL_UINT16 NL_INDEX16;
typedef NL_UINT8  NL_INDEX8;

const NL_INDEX8 NL_INDEX8_LAST_BIT    = 0x80;
const NL_INDEX8 NL_INDEX8_NOT_FOUND   = 0xFF;
const NL_INDEX8 NL_INDEX8_MAX         = 0x7F;       // if ( index > NL_INDEX8_MAX ) interpret index as invalid 

const NL_INDEX16 NL_INDEX16_LAST_BIT  = 0x8000;
const NL_INDEX16 NL_INDEX16_NOT_FOUND = 0xFFFF;
const NL_INDEX16 NL_INDEX16_MAX       = 0x7FFF;     // if ( index > NL_INDEX16_MAX ) interpret index as invalid 

const NL_INDEX NL_INDEX32_LAST_BIT    = 0x80000000;
const NL_INDEX NL_INDEX32_NOT_FOUND   = 0xFFFFFFFF;
const NL_INDEX NL_INDEX32_MAX         = 0x7FFFFFFF; // if ( index > NL_INDEX_MAX ) interpret index as invalid 

const NL_INDEX NL_INDEX_LAST_BIT      = 0x80000000;
const NL_INDEX NL_INDEX_NOT_FOUND     = 0xFFFFFFFF;
const NL_INDEX NL_INDEX_MAX           = 0x7FFFFFFF; // if ( index > NL_INDEX_MAX ) interpret index as invalid 

const NL_INDEX64 NL_INDEX64_LAST_BIT  = 0x8000000000000000ULL;
const NL_INDEX64 NL_INDEX64_NOT_FOUND = 0xFFFFFFFFFFFFFFFFULL;
const NL_INDEX64 NL_INDEX64_MAX       = 0x7FFFFFFFFFFFFFFFULL; // if ( index > NL_INDEX64_MAX ) interpret index as invalid 



//
// NameSpace NextLimit
//
namespace nextlimit
{


//-----------------------------------------------------------------------------------
//
// NL_indexFoundMaximum
//
//-----------------------------------------------------------------------------------
template< class T >
T NL_indexFoundMaximum()
{
  NL_BREAKPOINT;
  return( T(1) );
}

template<> inline NL_INDEX8  NL_indexFoundMaximum < NL_INDEX8  >() { return( NL_INDEX8_MAX  ); }
template<> inline NL_INDEX16 NL_indexFoundMaximum < NL_INDEX16 >() { return( NL_INDEX16_MAX ); }
template<> inline NL_INDEX32 NL_indexFoundMaximum < NL_INDEX32 >() { return( NL_INDEX32_MAX ); }
template<> inline NL_INDEX64 NL_indexFoundMaximum < NL_INDEX64 >() { return( NL_INDEX64_MAX ); }


//-----------------------------------------------------------------------------------
//
// NL_indexLastBit
//
//-----------------------------------------------------------------------------------
template< class T >
T NL_indexLastBit()
{
  NL_BREAKPOINT;
  return( T(1) );
}

template<> inline NL_INDEX8  NL_indexLastBit < NL_INDEX8  >() { return( NL_INDEX8_LAST_BIT  ); }
template<> inline NL_INDEX16 NL_indexLastBit < NL_INDEX16 >() { return( NL_INDEX16_LAST_BIT ); }
template<> inline NL_INDEX32 NL_indexLastBit < NL_INDEX32 >() { return( NL_INDEX32_LAST_BIT ); }
template<> inline NL_INDEX64 NL_indexLastBit < NL_INDEX64 >() { return( NL_INDEX64_LAST_BIT ); }


//-----------------------------------------------------------------------------------
//
// Not found indices
//
//-----------------------------------------------------------------------------------
template< class T>
T NL_indexNotFound()
{
  NL_ASSERT( NL_isUnsignedInteger<T>() );
  return( NL_maximum<T>() );
}

template< class T>
NL_BOOL NL_isFound( const T& index )
{
  return( index != NL_indexNotFound<T>() );
}

template< class T>
NL_BOOL NL_noFound( const T& index )
{
  return( index == NL_indexNotFound<T>() );
}

template< class T>
void NL_setNotFound( T& index )
{
  index = NL_indexNotFound<T>();
}

template< class T>
void NL_setFound( T& index, const T& val )
{
  NL_ASSERT( NL_isFound( val ) );
  index = val;
}

template< class T>
void NL_flipToNotFound( T& index )
{
  NL_ASSERT( NL_isFound( index ) );
  NL_setNotFound( index );
}

template< class T>
void NL_flipToFound( T& index, const T& val )
{
  NL_ASSERT( NL_noFound( index ) );
  NL_setFound( index, val );
}


//-----------------------------------------------------------------------------------
//
// Not found indices counting down 
//
//-----------------------------------------------------------------------------------
template< NL_INDEX8 countDown, class T >
T NL_indexNotFoundN()
{
  NL_ASSERT( NL_isUnsignedInteger<T>() );
  return( NL_maximum<T>() - countDown );
}

template< NL_INDEX8 countDown, class T >
void NL_setNotFoundN( T& index )
{
  index = NL_indexNotFoundN< countDown, T >();
}

template< NL_INDEX8 countDown, class T >
NL_BOOL NL_isFoundN( const T& index )
{
  return( index != NL_indexNotFoundN<countDown, T >() );
}

template< NL_INDEX8 countDown, class T >
NL_BOOL NL_noFoundN( const T& index )
{
  return( index == NL_indexNotFoundN< countDown, T >() );
}

// Constants
const NL_INDEX nl_index_A = 0;
const NL_INDEX nl_index_B = 1;
const NL_INDEX nl_index_C = 2;
const NL_INDEX nl_index_D = 3;
const NL_INDEX nl_index_E = 4;
const NL_INDEX nl_index_F = 5;
const NL_INDEX nl_index_G = 6;
const NL_INDEX nl_index_H = 7;


}      // NameSpace NextLimit...
#endif // _NL_INDEX_H_
