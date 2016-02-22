
#ifndef _PTR_WRAPPER_H
#define _PTR_WRAPPER_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <rf_common/smart_pointers/shared_ptr.h>
#include <rf_common/smart_pointers/scoped_ptr.h>
#include <rf_common/smart_pointers/weak_ptr.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{


  //Formal classes
  class PtrPolicy_SPEED      {};      // Raw pointers will be used
  class PtrPolicy_NORMAL     {};      // Smart pointers will be used but without checking validity 
  class PtrPolicy_ROBUSTNESS {};      // Smart pointers will be used & validity will be checked


  //-----------------------------------------------------------------------------------
  //
  // PtrWrapper:
  //
  //-----------------------------------------------------------------------------------
  template <class T, class SmrtPtr_T ,class Policy_T = PtrPolicy_SPEED>
  class RF_SDK_EXPORTS_DLL PtrWrapper
  {

    ///////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  public :

    /// Constructor
    PtrWrapper( T* smrtPtr )
    {
      ptr_ = smrtPtr;
    };

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Operations:
    //  @{ 
  public:

    T& operator*() const
    {
      return *( ptr_ );
    }

    T* operator->() const
    {
      return ptr_;
    }

    T* get() const
    {
      return ptr_;
    }

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    // !@name Data Members:
    //  @{
  protected:

    T*  ptr_;

  };

  template< class T , class SmrtPtr_T > 
  class PtrWrapper< T , SmrtPtr_T , PtrPolicy_NORMAL > 
  {

    ///////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  public :

    /// Constructor
    PtrWrapper( T* ptr ) : ptr_( ptr )
    {
    };

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Operations:
    //  @{ 
  public:

    T& operator*() const
    {
      return *( ptr_ );
    }

    T* operator->() const
    {
      return ptr_.operator ->();
    }

    T* get() const
    {
      return ptr_.get();
    }

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    // !@name Data Members:
    //  @{
  public:

    SmrtPtr_T  ptr_;

  };

  // ScopedPtr
  template< class T , class Policy_T = PtrPolicy_SPEED> 
  class PtrWrper_ScpPtr : public PtrWrapper< T, ScopedPtr<T>, Policy_T>
  {
  public:
    explicit PtrWrper_ScpPtr( T* ptr ) : PtrWrapper< T, ScopedPtr<T>, Policy_T>( ptr ) {};
  };

  // SharedPtr
  template< class T , class Policy_T = PtrPolicy_SPEED> 
  class PtrWrper_ShPtr : public PtrWrapper< T, SharedPtr<T>, Policy_T>
  {
  public:
    explicit PtrWrper_ShPtr( T* ptr ) : PtrWrapper< T, SharedPtr<T>, Policy_T>( ptr ) {};
  };

  // WeakPtr
  template< class T , class Policy_T = PtrPolicy_SPEED> 
  class PtrWrper_WkPtr : public PtrWrapper< T, WeakPtr<T>, Policy_T>
  {
  public:
    explicit PtrWrper_WkPtr( T* ptr ) : PtrWrapper< T, WeakPtr<T>, Policy_T>( ptr ) {};
    explicit PtrWrper_WkPtr( const WeakPtr<T>& smrtPtr ) : PtrWrapper< T, WeakPtr<T>, Policy_T>( smrtPtr.get() ) {};
  };


} // NameSpace NextLimit...
#endif // PtrWrapper...





