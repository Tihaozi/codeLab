
#ifndef _PTR_CREATOR_H
#define _PTR_CREATOR_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#include <utils/nl_singleton.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  //-----------------------------------------------------------------------------------
  //
  // PtrCreator:
  //
  // This class creates smart pointers and raw pointers given a policy to follow:
  //    If the policy is SPEED then all pointers returned will be raw, they be
  //      the same passed to the method.
  //    If the policy is ROBUSTNESS then all the pointers will be smart pointers, such
  //      as SharedPtr, WeakPtr.
  //
  //  In Any case once a pointer has been created the PtrCreator is not its owner anymore,
  //  it is the sole responsibility of the caller to destroy it.
  //-----------------------------------------------------------------------------------
  class RF_SDK_EXPORTS_DLL PtrCreator
  {

    enum PtrPolicy
    {
      SPEED,
      ROBUSTNESS
    };

    ///////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  private:

    /// Constructor
    PtrCreator( PtrPolicy policiy = ROBUSTNESS ) : policy_( policiy ) {};


    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Operations:
    //  @{ 
  public:

    /// Creates a shared pointer from a raw pointer 
    template<X> PtrWrapper createSharedPtr( X* ptr )
    {
      switch ( policy_ )
      {
        case ROBUSTNESS :

          break;

        case SPEED :
          return PtrWrapper( );
          break;
        
        default:
          NL_BREAK( "Should not get Here!" );
      };
    }

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    // !@name Data Members:
    //  @{
  private:

    PtrPolicy  policy_;


  };

} // NameSpace NextLimit...
#endif // _RF_APP_MANAGER_H...





