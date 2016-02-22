
#ifndef _NL_CLASS_UTIL_H_
#define _NL_CLASS_UTIL_H_

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
#include "rf_common/rf_commondefs.h"

// NameSpace NextLimit
// NameSpace NextLimit
// NameSpace NextLimit
namespace nextlimit
{

  template< class TO_DELETE >
  void NL_Deletor( void*& obj )
  {
    TO_DELETE*& objToDelete = ( TO_DELETE*& ) obj;
    nl::NL_safeDelete( objToDelete );
  }

  //-----------------------------------------------------------------------------------
  //
  // NL_RefTypeBase:
  // is base class of NL_RefType
  // NL_RefType<class TYPE_CLASS> would be a class that represents a reference
  // to an object of class TYPE_CLASS
  //
  //-----------------------------------------------------------------------------------
  class RF_COMMON_EXPORTS_DLL NL_RefTypeBase
  {
  
  public:     
    typedef void (*ptrDeletorFunc)( void*& );

    ///////////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  protected:

    /// Constructor.
    NL_RefTypeBase() {};

  public:
    /// Destructor.
    virtual ~NL_RefTypeBase() {};

    ///////////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Access:
    //  @{ 
  public:

    //
    virtual ptrDeletorFunc getRefDeletor( void )
    {
      return NULL;
    }

    //
    virtual void* getVoidPtrToRef( void )
    {
      return NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @helper methods:
    //  @{ 
  protected:

    /// Tag to make the class Polymorphic
    virtual void makeMePolimorphic(){};

  };


  //-----------------------------------------------------------------------------------
  //
  // NL_RefType:
  // 
  //  class that represents a reference to an object of class TYPE_CLASS
  //
  //-----------------------------------------------------------------------------------
  template< class TYPE_CLASS >
  class RF_COMMON_EXPORTS_DLL NL_RefType : public NL_RefTypeBase
  {
    ///////////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  public:

    /// Constructor.
    NL_RefType( TYPE_CLASS& obj ) : obj_( obj )
    {
    }

    /// Destructor.
    virtual ~NL_RefType()
    {
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Access:
    //  @{ 
  public:

    //
    TYPE_CLASS& getRef( void )
    {
      return ( obj_ ); 
    }

    //
    virtual void* getVoidPtrToRef( void )
    {
      return &obj_;
    }

    //
    virtual ptrDeletorFunc getRefDeletor( void )
    {
      return &( NL_Deletor<TYPE_CLASS> );
      //return &ffffff;
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @helper methods:
    //  @{ 
  protected:

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Data Members:
    //  @{ 

    TYPE_CLASS& obj_;

  };

  //-----------------------------------------------------------------------------------
  //
  // NL_Is_SameType: 
  // 
  //  Returns true if both vars are of the exact same type.
  //
  //-----------------------------------------------------------------------------------

  template< class T_DEST, class T_ORIG >
  NL_BOOL NL_Is_SameType( const T_DEST& destType, const T_ORIG& origType )
  {
    NL_BREAKPOINT;
    return 0;
    /*const nl::NL_RefType<T_ORIG> origType ( origType );

    const nl::NL_ClassType<T_DEST>* destType = 
      dynamic_cast< const nl::NL_RefType<T_DEST>* >( &origType );

    if ( destType == NULL )
    {
      return NL_false;
    }
    else
    {
      NL_true;
    }*/
  }


  //
  template< class T_DEST >
  NL_BOOL NL_Is_RefToType( const NL_RefTypeBase& origType )
  {
    const nl::NL_RefType<T_DEST>* destType = 
      dynamic_cast< const nl::NL_RefType<T_DEST>* >( &origType );

    if ( destType == NULL )
    {
      return NL_false;
    }
    else
    {
      return NL_true;
    }
  }

  ////
  //template< class T_DEST >
  //nl::NL_ClassType<T_DEST>* NL_CastTo( NL_ClassTypeBase* orig )
  //{
  //  if ( orig == NULL )
  //  {
  //    return NULL;
  //  }
  //  else
  //  {
  //    return dynamic_cast< nl::NL_ClassType<T_DEST>* >( orig );
  //  }
  //}

}      // NameSpace NextLimit...
#endif // _NL_CLASS_UTIL_H_
