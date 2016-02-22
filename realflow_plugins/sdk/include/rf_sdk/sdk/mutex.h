
#ifndef _NL_MUTEX_H
#define _NL_MUTEX_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"

// FORWARD DECLARATIONS

namespace nextlimit
{
  class Mutex;
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // Mutex:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Mutex
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Life Cycle:
      //  @{ 
    public:

      NL_ALIGNED_NEW_OPERATORS(4);

      /// Constructor
      Mutex();

      /// Destructor
      ~Mutex();

    private:
      Mutex( const Mutex& ) {}
      void operator =( const Mutex& ) {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// lock:  
      /// 
      /// Lock the mutex.
      /// 
      //
      void lock();

      /// unlock:  
      /// 
      /// Unlock the mutex.
      /// 
      //
      void unlock();

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      // !@name Data Members:
      //  @{
    protected:

      nl::Mutex* mutex_;
   
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_MUTEX_SHORT_H...





