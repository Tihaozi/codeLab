
#ifndef _NL_SDK_RF_MULTIBODY_H
#define _NL_SDK_RF_MULTIBODY_H

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
//#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
//#include "rf_sdk/sdk/pb_particle.h"
#include "rf_sdk/sdk/vertex.h"
#include "rf_sdk/sdk/face.h"

//
// FORWARD DECLARATIONS
//
namespace nextlimit
{
  namespace realflow
  {
    class MultiBody;
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
    // MultiBody:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC MultiBody 
      : public RFNodeType< nl::rf::MultiBody, nl::rf_sdk::Node_ExpRsc >
    {

    public:

      static const int EXPORT_ANIMATION_SD;
    
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      MultiBody( nl::rf::MultiBody* nativeObjPtr ) 
        : RFNodeType< nl::rf::MultiBody, nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {}

    public:
      /// Destructor
      virtual ~MultiBody( void ) {}


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// sdkExport:  
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// fracture:
      ///
      /// Break every body into pieces.
      ///
      /// @param [in] numberOfPieces / Number of pieces after the breaking process.
      /// @param [in] seed / Random seed used for the breaking process.
      ///
      /// @return : MultiBody with the resulting pieces.
      MultiBody fracture(  const unsigned int& numberOfPieces,
                           const unsigned int& seed );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_MULTIBODY; };
      
      /// setForce:  
      ///
      /// Apply an external Force to THIS Object on a specific point
      ///
      /// @param [in] force / Force vector
      /// @param [in] position / Position in global coordinates where the force is applied
      void  setForce( const Vector& force, const Vector& position ); 

      /// setForce:  
      ///
      /// Apply an external Force to THIS Object
      ///
      /// @param [in] force / Force vector
      void  setForce( const Vector& force ); 

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::MULTIBODY_TYPE; };

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
      friend class Object;
      friend class HY_Mesh;
      friend class HY_Mesh_VDB;
      friend class ParticleMeshLegacy;
      friend class ParticleMesh;
      friend class ParticleMesh_VDB;
    };

  }; // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_RF_MULTIBODY_H...





