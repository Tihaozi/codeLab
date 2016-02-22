
#ifndef _NL_SDK_ROCKET_H
#define _NL_SDK_ROCKET_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/object.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  // FORWARD REFERENCES
  namespace rf_sdk
  {
    class Scene;
  }

  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // Rocket:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Rocket : public Object
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Rocket( RegularBody* nativeObjPtr ) : Object( nativeObjPtr )  {};

    public:
      /// Destructor
      virtual ~Rocket( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_ROCKET_H...





