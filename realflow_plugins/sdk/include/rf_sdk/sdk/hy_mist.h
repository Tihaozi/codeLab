
#ifndef _NL_SDK_RF_HY_MIST_H
#define _NL_SDK_RF_HY_MIST_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"

//
// FORWARD DECLARATIONS
//
namespace nextlimit
{
  namespace realflow
  {
    class FS_GridFluidMist3;
  }
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD REFERENCES
    class Scene;
    class NodeAccesor;

    //-----------------------------------------------------------------------------------
    //
    // Emitter:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC HY_Mist 
      : public RFNodeType< nl::rf::FS_GridFluidMist3, nl::rf_sdk::Node_ExpRsc >
    {

    public:

      static const int EXPORT_GRID_MIST_F3D;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      HY_Mist( nl::rf::FS_GridFluidMist3* nativeObjPtr ) 
        : RFNodeType< nl::rf::FS_GridFluidMist3, nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~HY_Mist( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// sdkExport:  
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_MIST; };
      
      /// addDensity:
      /// Adds density at specific world position.
      void addDensity( const float& density, const Vector& position );

      /// getDensity:
      /// Gets the density at specific world position.
      float getDensity( const Vector& position );

      /// addVelocity:
      /// Adds velocity at specific world position.
      void addVelocity( const Vector& velocity, const Vector& position );

      /// getGridPoints:
      /// Gets the list of the grid points positions in world space.
      void getGridPoints( ArrSdkVectors& points ) const;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::MIST_TYPE; };

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
      friend class NodeAccesor;

    };

  }; // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_RF_HY_MIST_H...





