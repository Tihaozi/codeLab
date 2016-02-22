
#ifndef _NL_SDK_CAMERA_H
#define _NL_SDK_CAMERA_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"

//FORWARD DECLARATIONS
class SceneCamera;

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class NodeAccesor;
 
    //-----------------------------------------------------------------------------------
    //
    // Camera:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC Camera 
      : public RFNodeType< ::SceneCamera, nl::rf_sdk::Node_ExpRsc >
    {
    public:

      static const int EXPORT_CAMERA_ANIMATION;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Camera( SceneCamera* nativeObjPtr ) 
        : RFNodeType< ::SceneCamera, nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {}

    public: 

      /// Destructor
      virtual ~Camera( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_CAMERA; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::CAMERA_TYPE; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class Scene;
      friend class NodeAccesor;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_CAMERA_H...





