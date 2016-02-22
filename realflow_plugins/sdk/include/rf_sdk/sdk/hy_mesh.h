
#ifndef _NL_SDK_HY_GRIDMESH_H
#define _NL_SDK_HY_GRIDMESH_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"

// FORWARD REFERENCES
namespace nextlimit
{
  namespace realflow
  {
    namespace fluid_wrapper
    {
      class GridFluidWrapper_RK;
    }
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
    class Image;
    class MultiBody;

    //-----------------------------------------------------------------------------------
    //
    // Mesh:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC HY_Mesh 
        : public RFNodeType<  nl::rf::fluid_wrapper::GridFluidWrapper_RK, 
                              nl::rf_sdk::Node_ExpRsc >
    {

    public:

      static const int EXPORT_MESHES_BIN;
      static const int EXPORT_MESHES_MD;
      static const int EXPORT_MESHES_OBJ;
      static const int EXPORT_MESHES_ABC;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      HY_Mesh( nl::rf::fluid_wrapper::GridFluidWrapper_RK* nativeObjPtr ) 
        : RFNodeType< nl::rf::fluid_wrapper::GridFluidWrapper_RK, 
                      nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {}

    public:
      /// Destructor
      virtual ~HY_Mesh( void ) {}


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// sdkExport:  
      ///
      /// Writes out all the resources that are active in the export central
      void sdkExport( void );

      /// addEmitter:  
      /// 
      /// Add an Emitter to THIS Mesh
      ///
      /// @param [in] emitterName / Emitter 's name to be added to THIS Mesh
      /// @return : True if the emitter was added. False if the emitter could not be added
      ///           becase it is not compatible or already existed.
      bool addEmitter( const std::string& emitterName ); 

      /// removeEmitter:  
      /// 
      /// Remove an Emitter from THIS Mesh
      ///
      /// @param [in] emitterName / Emitter 's name to removed from THIS Mesh
      /// @return : True if the emitter was removed. False if the emitter did not belong
      ///            to the mesh
      bool removeEmitter( const std::string& emitterName ); 

      /// getEmitters:  
      ///
      /// Get Emitters 's names that contribute to create THIS Mesh
      ///
      /// @param [out] emitterNames / Vector of Emitters 's names
      void getEmitters( std::vector< std::string >& emitterNames ); 

      /// build:  
      ///
      /// Builds the Mesh
      void build();

      /// getGeometry:  
      ///
      /// Get a Tuple with the < Faces, Vertexes > of THIS Mesh 
      ///
      /// @param [out] geometry / Tuple of Vectors < Vector of Faces, Vector of Vertexes >
      void getGeometry( std::pair< ArrSdkVertex, ArrSdkFaces >& geometry ); 

      /// fracture:
      ///
      /// Break the mesh into pieces.
      ///
      /// @param [in] numberOfPieces / Number of pieces after the breaking process.
      /// @param [in] seed / Random seed used for the breaking process.
      ///
      /// @return : MultiBody with the resulting pieces.
      MultiBody fracture(  const unsigned int& numberOfPieces,
                           const unsigned int& seed );

      /// getType:
      /// 
      /// Gets the type of this Realflow Node Object
      /// 
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_GRID_MESH; }
      
      /// updateVertices:  
      ///
      /// Update the current Mesh's Vertexes with the new Vertexes ( vertexs ) given as parameter. 
      /// The number of Vertexes given has to be the same than the number of current Object's Vertexes.
      /// This method is useful when you want to deform the object keeping the Object 's face connectivity.
      /// The normals are always recalculated so any value in the vertex normal introduced by the user 
      /// is ignored.
      /// 
      /// @param [in] ref / Coordinates reference in which the new Vertexes are given:
      ///                   - ref values in [ REF_GLOBAL( global coordinates ), 
      ///                                     RF_LOCAL  ( local  coordinates ) ]
      ///                   - ref default value = REF_GLOBAL
      /// 
      /// @param [in] vertexs / Vector of new Vertexes
      void updateVertices( const ArrSdkVertex& vertexs ); 
      
      /// updateFaces:  
      ///
      /// Update the current Mesh's Faces with the new Faces ( faces ) given as parameter. 
      /// The number of Faces given has to be the same than the number of current Mesh's Faces.
      /// The Faces's positions have to be specified in local coordinates.
      /// The normals are always recalculated so any value in the vertex normal introduced by the user 
      /// is ignored.
      ///
      /// @param [in] faces / Vector of new Faces
      void updateFaces( const ArrSdkFaces& Faces ); 
      
      /// setGeometry:  
      ///
      /// Change THIS Mesh's geometry. The new one is given by a list of Vertexes and Faces.
      /// The old geometry is removed so the number of new Vertexes and Faces doesn't have to 
      /// match the previous numbers.
      /// The face normals are always recalculated so any value in the face normal introduced by the user 
      /// is ignored.
      ///
      /// @param [in] vertexs / Vector of new Vertexes
      /// @param [in] faces / Vector of new Faces
      void  setGeometry( const ArrSdkVertex& vertexs, const ArrSdkFaces& faces ); 

      /// tessellate:  
      ///
      /// Tessellate THIS Mesh's geometry. Given a maximum edge length, mesh is tessellated
      /// until every edge is smaller than the passed parameter.
      /// Velocity values are interpolated for the new mesh. 
      ///
      /// @param [in] maxEdgeLength
      void  tessellate( const NL_DOUBLE& maxEdgeLength ); 
      
      /// displaceVerticesWithTexture:  
      ///
      /// Apply displacement to THIS Mesh's vertices based on texture with 
      /// XYZ values encoded as RGB. 
      ///
      /// @param [in] texture / Texture with displacement values (8,16,32 bit RGB)
      /// @param [in] tileU / Tile factor for texture coordinates in U direction
      /// @param [in] tileV / Tile factor for texture coordinates in V direction
      /// @param [in] displacementScale / Scale factor for every component of displacement
      /// @param [in] computeLocalBase / True to compute a local base and displace
      ///                                vertices along their normals. 
      ///                                Normal direction is G component of displacement.
      ///                                False to use world coordinates in RealFlow default
      ///                                coordinates system.
      /// @param [in] interpolatePixels / True to apply a bilinear filter to texture.
      void  displaceVerticesWithTexture( const Image& texture,
                                         const float& tileU,
                                         const float& tileV,
                                         const Vector& displacementScale,
                                         const bool& computeLocalBase = NL_true,
                                         const bool& interpolatePixels = NL_true ); 
      
      /// clipWithBox:  
      ///
      /// Removes THIS mesh's vertices inside (or outside) the box aligned to axes
      /// defined by its minimum and maximum corner.
      ///
      /// @param [in] minCorner / Minimum corner of the clipping box.
      /// @param [in] maxCorner / Maximum corner of the clipping box.
      /// @param [in] removeGeometryInside / True to remove vertices inside the clipping box.
      ///                                False to remove vertices outside the clipping box.
      void  clipWithBox( const Vector& minCorner,
                         const Vector& maxCorner,
                         const bool& removeGeometryInside ); 
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::GRID_MESH_TYPE; }

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

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_HY_GRIDMESH_H...





