
#ifndef _NL_SDK_PLANE_H
#define _NL_SDK_PLANE_H

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

  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // Plane:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Plane : public Object
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Plane( RegularBody* nativeObjPtr ) : Object( nativeObjPtr )  {}

    public:
      /// Destructor
      virtual ~Plane( void ) {}

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      friend class Scene;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_PLANE_H...





