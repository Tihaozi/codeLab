
#ifndef _NL_SDK_OBJECT_H
#define _NL_SDK_OBJECT_H  

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
#include "rf_sdk/sdk/face.h"
#include "rf_sdk/sdk/vertex.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"

// FORWARD DECLARATIONS
class RegularBody;

namespace nextlimit
{
  class MutexRW;

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

  // FORWARD DECLARATIONS
  template < class T >
  class Array_R;

  namespace rf_sdk
  {

    namespace proxy_type
    {
      RF_SDK_EXPORTS_DLL_STATIC extern const int  PROXY_CONVEX_HULL;
    };

    // FORWARD DECLARATIONS
    class Scene;
    class PB_Particle;
    class RFSdkBasicLib;
    class NodeAccesor;
    class MultiBody;

    //-----------------------------------------------------------------------------------
    //
    // Object:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Object  
      : public RFNodeType< ::RegularBody, nl::rf_sdk::Node_ExpRsc >
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      Object( RegularBody* nativeObjPtr );

    public:
      /// Destructor
      virtual ~Object( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getAngularVelocity:  
      ///
      /// Gets the Object 's angular velocity
      ///
      /// @return : Object 's angular velocity
      Vector getAngularVelocity(); 

      /// getVelocity:  
      ///
      /// Gets the Object 's linear velocity
      ///
      /// @return : Object 's linear velocity
      Vector getVelocity(); 

      /// getCollidingObjects:  
      ///
      /// Gets the Objects that are colliding with THIS Object
      ///
      /// @param [out] objs / Vector of colliding Objects
      void getCollidingObjects( ArrSdkObjects& objs ); 

      /// getCollisionPoints:  
      ///
      /// Gets the collision points between THIS Object and the Object ( otherObj )
      ///
      /// @param [in] otherObj / Object with which collision points are found 
      /// 
      /// @param [out] objs / Vector of collision Objects
      void getCollisionPoints( ArrSdkVectors& pnts, const Object& otherObj ) const; 

      /// getFaces:  
      ///
      /// Gets the Object 's Faces
      ///
      /// @param [out] faces / Vector of Faces
      void getFaces( ArrSdkFaces& faces ); 

      /// getVertices:  
      ///
      /// Gets the Object 's Vertices. By default ref = REF_GLOBAL
      /// 
      /// @param [in] ref / Coordinates reference in which the vertexes are returned:
      ///                   - ref values in [ REF_GLOBAL( global coordinates ), 
      ///                                     RF_LOCAL  ( local  coordinates ) ]
      ///                   - ref default value = REF_GLOBAL
      /// 
      /// @param [out]  vertexs / Vector of Vertexes
      void getVertices( ArrSdkVertex& vertexs, int ref = REF_GLOBAL ); 

      /// getNumVertices:
      ///
      /// Return number of vertices
      ///
      /// @param [out] number of vertices
      int getNumVertices();

      /// getNumFaces:
      ///
      /// Return number of faces 
      ///
      /// @param [out] number of faces 
      int getNumFaces();

      /// getGeometry:  
      ///
      /// Get a Tuple with the < Faces, Vertexes > of THIS Object
      /// 
      /// @param [in] ref / Coordinates reference in which the Faces & Vertexes are returned:
      ///                   - ref values in [ REF_GLOBAL( global coordinates ), 
      ///                                     RF_LOCAL  ( local  coordinates ) ]
      ///                   - ref default value = REF_GLOBAL
      ///
      /// @param [out] geometry / Tuple of Vectors < Vector of Faces, Vector of Vertexes >
      void getGeometry( Geometry& geometry , 
                        int ref = REF_GLOBAL   ); 

      /// updateVertices:  
      ///
      /// Update the current Object 's Vertexes with the new Vertexes ( vertexs ) given as parameter. 
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
      void updateVertices( const ArrSdkVertex& vertexs, int ref = REF_GLOBAL ); 

      /// updateFaces:  
      ///
      /// Update the current Object 's Faces with the new Faces ( faces ) given as parameter. 
      /// The number of Faces given has to be the same than the number of current Object's Faces.
      /// The Faces 's positions have to be specified in local coordinates.
      /// The normals are always recalculated so any value in the vertex normal introduced by the user 
      /// is ignored.
      ///
      /// @param [in] faces / Vector of new Faces
      void updateFaces( const ArrSdkFaces& faces ); 

      /// setGeometry:  
      ///
      /// Change THIS Object 's geometry. The new one is given by a list of Vertexes and Faces.
      /// The old geometry is removed so the number of new Vertexes and Faces doesn't have to 
      /// match the previous numbers.
      /// The normals are always recalculated so any value in the vertex normal introduced by the user 
      /// is ignored.
      ///
      /// @param [in] vertexs / Vector of new Vertexes
      /// @param [in] faces / Vector of new Faces
      void  setGeometry( const ArrSdkVertex& vertexs, const ArrSdkFaces& faces ); 

      /// setForce:  
      ///
      /// Apply an external Force to THIS Object on a specific point
      ///
      /// @param [in] force / Force vector
      /// @param [in] globalPos / Position in global coordinates where the force is applied
      void  setForce( const Vector& force, const Vector& globalPos ); 

      /// setForce:  
      ///
      /// Apply an external Force to THIS Object
      ///
      /// @param [in] force / Force vector
      void  setForce( const Vector& force ); 

      /// getCenterOfMass:  
      ///
      /// Gets the Object 's center of mass in global coordinates
      ///
      /// @return : Object 's center of mass
      Vector getCenterOfMass(); 

      /// createProxy:  
      ///
      /// Create a proxy Object for this Object of the given proxy type ( proxyType ). 
      /// Valid values are :  PROXY_CONVEX_HULL, PROXY_CUBE and PROXY_SPHERE
      ///
      /// @param [in] proxyType / Proxy type of the proxy Object to be created
      ///
      /// @return : Proxy Object of the given proxyType
      Object createProxy( int proxyType ); 

      /// getAdjoiningFacesToVertex:  
      ///
      /// Get the Faces sharing the Vertex( vertex ) given.
      ///
      /// @param [in] vertex / Vertex
      ///
      /// @param [out]  faces / Vector of Faces sharing the Vertex( vertex )
      void getAdjoiningFacesToVertex( ArrSdkFaces& faces         , 
                                      const Vertex& vertex   ); 

      /// getAdjoiningFacesToFace:  
      ///
      /// Get the Faces connected to the Face( face ) given. Two faces are connected if
      /// they share at least one edge.
      ///
      /// @param [in] face / Face
      ///
      /// @param [out]  faces / Vector of Faces connected to Face( face )
      void getAdjoiningFacesToFace( ArrSdkFaces& outSdkFaces     , 
                                    const Face& face   ); 

      /// getFace:  
      ///
      /// Gets the Face at index( idx )
      ///
      /// @param [in] idx / Face 's index
      ///
      /// @return : Face
      Face getFace( int idx ); 

      /// sdkExport:  
      ///
      /// Writes out all the resources that are active in the export central
      void sdkExport();

      /// resetTransformations:  
      ///
      /// Set the transformation Matrix to the identity Matrix. It is the same than 
      /// setting the position, rotation and scale parameters to their default values
      void resetTransformations();

      /// freezeTransformations:  
      ///
      /// Set the transformation Matrix to the identity Matrix but keeping the vertexes in
      /// the position they have at the time of calling this method
      void freezeTransformations();

      /// getFacesBelowRealWave:  
      ///
      /// Get the Faces that are completely below the RealWave surface. Faces have indexes
      /// to vertices that must be retrieved using the function getVerticesBelowRealWave
      ///
      /// @param [out]  faces / Vector of Faces completely below the RealWave surface
      void getFacesBelowRealWave( ArrSdkFaces& faces );

      /// getFacesCrossingRealWave:  
      ///
      /// Get the faces that are partially below the RealWave surface. Faces have indexes 
      /// to vertices that must be retrieved using the function getVerticesCrossingRealWave
      ///
      /// @param [out]  faces / Vector of Faces partially below the RealWave surface
      void getFacesCrossingRealWave( ArrSdkFaces& faces );

      /// getVerticesBelowRealWave:  
      ///
      /// Get the vertices that are below the RealWave surface
      ///
      /// @param [out]  vertexs / Vector of Vertices below the RealWave surface
      void getVerticesBelowRealWave( ArrSdkVertex& vertexs );

      /// getVerticesCrossingRealWave:  
      ///
      /// Get the vertices of those faces that are partially below the RealWave surface
      ///
      /// @param [out]  vertexs / Vector of Vertices whose Faces are partially below the RealWave surface
      void getVerticesCrossingRealWave( ArrSdkVertex& vertexs );

      /// getGeometryBelowRealWave:  
      ///
      /// Get a Tuple with the < Faces, Vertexes > of THIS Object which are completely below 
      /// the RealWave surface.
      ///
      /// @param [out] geometry / Tuple of Vectors < Vector of Faces, Vector of Vertexes >
      void getGeometryBelowRealWave( Geometry& outGeometry );

      /// getGeometryBelowRealWave:  
      ///
      /// Get a Tuple with the < Faces, Vertexes > of THIS Object which are partially 
      /// below the RealWave surface.
      ///
      /// @param [out] geometry / Tuple of Vectors < Vector of Faces, Vector of Vertexes >
      void getGeometryCrossingRealWave( Geometry& outGeometry );

      /// getGeometryFilePath:  
      ///
      /// Get the file path from where the object geometry was loaded. If it is a built-in RealFlow 
      /// object then this function return an empty file path
      ///
      /// @param [out] Geometry 's file path
      std::string getGeometryFilePath();

      /// setTextureForParameter:  
      ///
      /// Set a texture for a parameter. Only some specific parameters can be controlled 
      /// through textures (in the user interface these parame  ters are marked with a check board icon). 
      /// If you want to "unload" the texture for the specific parameter just pass an empty string ""
      /// in the image's file path. 
      ///
      /// @param [in] paramName / Object 's Parameter name
      /// @param [in] textureFilePath / Texture image file path. Empty string( "" ) to unload the texture
      /// @param [in] channel / Values in [ CHANNEL_RED, CHANNEL_GREEN, CHANNEL_BLUE ];
      ///                       default value = CHANNEL_RED
      /// @param [in] textureMin / Minimum value for the parameter ( the channel value from 
      ///                          the texture image is mapped to the min/max value )
      /// @param [in] textureMax / Maximum  value for the parameter ( the channel value from 
      ///                          the texture image is mapped to the min/max value )
      void setTextureForParameter(  const std::string&  paramName                       , 
                                    const std::string&  textureFilePath                 , 
                                    Channel             channel    = CHANNEL_RED        , 
                                    float               textureMin = 0.0f               , 
                                    float               textureMax = 1.0f                 );

      /// tessellate:
      ///
      /// Performs a tessellation of the object.
      ///
      /// @param [in] maxEdgeLength / Maximum length of the edge that will be tessellated.
      void tessellate( const float& maxEdgeLength );

      /// fracture:
      ///
      /// Break the object into pieces.
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
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_OBJECT; };

      
      /// getBoundingBox:
      /// 
      /// Get the Bounding Box of the object
      /// 
      /// @return a std::pair containing
      std::pair<Vector, Vector> getBoundingBox() const;

      /// copyGeometry
      /// 
      /// Copy geometry from other object
      ///
      /// @param[in] the other object
      /// 
      /// @return 
      //FIXME: const correctness!!
      void copyGeometry(Object&);
      
      /// getObjectType:  
      /// 
      /// Returns the name of the type of the object. For example: "Sphere".
      ///
      /// @return :The type of the object as a string
      //
      std::string getObjectType( void ) const;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::OBJECT_TYPE; };

      // assigns 
      static void NL_set( nl::rf::Face& dest, const Face& orig, Array_R< nl::rf::Vertex >& rf_arrVertex );

      // getFacesRealWave
      void getFacesRealWave( const int& filter, ArrSdkFaces& out_sdk_Faces ); 

      // getVertexesRealWave
      void getVertexesRealWave( const int& filter, ArrSdkVertex& out_sdk_Vertexs ); 

      // getGeometryRealWave
      void getGeometryRealWave( const int&    filter          ,
                                ArrSdkVertex& out_sdk_Vertexs , 
                                ArrSdkFaces&  out_sdk_Faces   
                                                                ); 

      // getVerticesAux
      void getVerticesAux( ArrSdkVertex& r_objs, int ref ); 

      // getFacesAux
      void getFacesAux( ArrSdkFaces& r_objs ); 


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;
      friend class PB_Particle;
      friend class RFSdkBasicLib;
      friend class NodeAccesor;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_OBJECT_H...





