
#ifndef _NL_RFSDK_FACE_H
#define _NL_RFSDK_FACE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include <vector>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES
#include <rf_common/core/rf_basicdefs.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/vector.h"

// FORWARD DECLARATIONS
class ANIFloatBase;
class FaceMeshRw;

namespace nextlimit
{
  namespace realflow
  {
    class Face;
  }
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {
    // FORWARD DECLARATIONS
    class PB_Emitter;
    class Object;
    class RealWave;
    class RFSdkBasicLib;
    class ParticleMeshLegacy;
    class ParticleMesh;
    class ParticleMesh_VDB;
    class HY_Mesh;

    //-----------------------------------------------------------------------------------
    //
    // Face:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Face
    {

     // typedef ANIFloatBase NativeObjType ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Face( const std::vector<int>& ijk, Vector& normal );

      /// Constructor
      Face( const nl::rf::Face& face );

      /// Constructor
      Face( const ::FaceMeshRw& rf_FaceMesh );
      
    public:

      ///
      /// Create a new Face. A Face in RealFlow is a polygon with vertices. When the Face is 
      /// created no check is done about whether the indices to the vertices are valid or not.
      /// This check is done when you create the object geometry. The normal of the face is 
      /// computed taking the vector from vertex 1 to vertex 2 and the vector from vertex 1 
      /// to vertex 3 and computing the cross product moving the first vector ( 1->2 ) to 
      /// the second vector ( 1->3 ). The normal is computed when we create the object geometry.
      ///
      /// @param [in] i / Index for the first vertex
      /// @param [in] j / Index for the second vertex
      /// @param [in] k / Index for the third vertex
      Face( int i, int j, int k );

      /// Copy Constructor
      Face( const nl::rf_sdk::Face& face );

      /// Destructor
      virtual ~Face( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// getIndices:  
      ///
      /// Get the Face 's vertex indices.
      ///
      /// @return : Vector of THIS Face 's vertex indices 
      const std::vector<int>& getIndices() const;

      /// setIndices:
      ///
      /// Sets the Face 's vertex indices
      ///
      /// @param [in] i / Index for the first vertex
      /// @param [in] j / Index for the second vertex
      /// @param [in] k / Index for the third vertex
      void setIndices( int i, int j, int k );

      /// getTextureCoordinates:  
      ///
      /// Get the Face 's texture coordinates for every vertex. 
      ///
      /// @return : Vector of THIS Face 's texture coordinates ;
      ///             - The first element holds the texture coordinates for the "i" vertex
      ///             - The second element holds the texture coordinates for the "j" vertex   
      ///             - The third element holds the texture coordinates for the "k" vertex  
      const std::vector<Vector>& getTextureCoordinates( void ) const;

      /// setTextureCoordinates:  
      ///
      /// Sets the Face 's texture coordinates for every vertex. 
      ///
      /// @param [in] txtureCoords / Vector with THIS Face 's texture coordinates per vertex
      ///             - The first element holds the texture coordinates for the "i" vertex
      ///             - The second element holds the texture coordinates for the "j" vertex   
      ///             - The third element holds the texture coordinates for the "k" vertex  
      void setTextureCoordinates( const std::vector<Vector>& txtureCoords );

      /// getNormal:  
      ///
      /// Gets the Face 's normal 
      ///
      /// @return : Face 's normal  
      const Vector& getNormal( void ) const;

      /// setNormal:  
      ///
      /// Sets the Face 's normal
      ///
      /// @param [in] normal / New Face 's normal
      void setNormal( const Vector& normal );

      /// getI:  
      ///
      /// Gets the Face 's first vertex index
      ///
      /// @return : Face 's first vertex index
      int getI() const { return idxs_[ 0 ]; };

      /// getI:  
      ///
      /// Gets the Face 's second vertex index
      ///
      /// @return : Face 's second vertex index
      int getJ() const { return idxs_[ 1 ]; };

      /// getI:  
      ///
      /// Gets the Face 's third vertex index
      ///
      /// @return : Face 's third vertex index
      int getK() const { return idxs_[ 2 ]; };


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @private Methods:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      std::vector<int> idxs_;
      std::vector<Vector> textureUVWs_;
      Vector normal_;
      NL_INT index_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class PB_Emitter;
      friend class RFSdkBasicLib;
      friend class Object;
      friend class RealWave;
      friend class ParticleMeshLegacy;
      friend class HY_Mesh;
      friend class HY_Mesh_VDB;
      friend class ParticleMesh;
      friend class ParticleMesh_VDB;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_RFSDK_FACE_H...





