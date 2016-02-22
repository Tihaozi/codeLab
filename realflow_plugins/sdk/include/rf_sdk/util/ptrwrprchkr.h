
#ifndef _NL_PTR_WRPR_CHKR_H
#define _NL_PTR_WRPR_CHKR_H

// BASIC INCLUDES 
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/rf_null_excpt.h"


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  //-----------------------------------------------------------------------------------
  //
  // PtrWrprChkr:
  //
  //-----------------------------------------------------------------------------------
  template <class TYPE_PTR>
  class RF_SDK_EXPORTS_DLL PtrWrprChkr
  {

    ///////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  public :

    /// Constructor
    PtrWrprChkr( TYPE_PTR* ptr ) : ptr_( ptr ) {};

    /// Copy Constructors
    explicit PtrWrprChkr( const PtrWrprChkr& other )
    {
      this->ptr_ = other.ptr_;
    }

    ///
    PtrWrprChkr& operator= ( const PtrWrprChkr& other )
    { 
      this->ptr_ = other.ptr_;

      return (*this); 
    }

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Operations:
    //  @{ 
  public:

    TYPE_PTR& operator*()
    {
      return ( *( getSafe() ) );
    }

    TYPE_PTR* operator->()
    {
      return ( getSafe() );
    }

    const TYPE_PTR* operator->() const
    {
      return ( getSafe() );
    }

    bool isNull() const
    {
      return ( ptr_ == NULL );
    }

    TYPE_PTR* getSafe()
    {
      if ( ptr_ == NULL )
      {
        throw nl::rf_sdk::RF_Null_Excpt();
      }
      else
      {
        return ( ptr_ );
      }
    }

    const TYPE_PTR* getSafe() const
    {
      if ( ptr_ == NULL )
      {
        throw nl::rf_sdk::RF_Null_Excpt();
      }
      else
      {
        return ( ptr_ );
      }
    }

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    // !@name Data Members:
    //  @{
  protected:

    TYPE_PTR*  ptr_;

  };


} // NameSpace NextLimit...
#endif // _NL_PTR_WRPR_CHKR_H...





