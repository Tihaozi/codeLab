
#ifndef _NL_SDK_REAL_WAVE_H
#define _NL_SDK_REAL_WAVE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/wave.h"

//FORWARD REFERENCES
class RWEmisor;

namespace nextlimit
{
  class MutexRW;
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
    // RealWave:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL RealWave 
      : public RFNodeType< ::RWEmisor, nl::rf_sdk::Node_ExpRsc >
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      RealWave( RWEmisor* nativeObjPtr );

    public:
      /// Destructor
      virtual ~RealWave( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getFaces:  
      ///
      /// Gets the Faces of the RealWave 's mesh
      ///
      /// @param [out] faces / Vector of Faces
      //
      void getFaces( ArrSdkFaces& faces ); 

      /// getVertices:  
      ///
      /// Gets the Vertices of the RealWave 's mesh
      /// 
      /// @param [out]  vertexs / Vector of Vertices
      //
      void getVertices( ArrSdkVertex& vertexs ); 

      /// getGeometry:  
      ///
      /// Get a Tuple with the < Faces, Vertexes > of THIS RealWave 's mesh
      ///
      /// @param [out] geometry / Tuple of Vectors < Vector of Faces, Vector of Vertexes >
      //
      void getGeometry( Geometry& geometry ); 

      /// getNearestVertex:  
      ///
      /// Get Vertex 's index which is the nearest global position given as parameter( globalPos ) 
      /// This index can be used in the scripted waves to access to the list of Wave 's vertices
      ///
      /// @param [in] globalPos / Global position
      ///
      /// @return : Vertex 's index
      //
      int getNearestVertex( const Vector& globalPos ); 

      /// getWaterLine:  
      ///
      /// Get the water line for an object interacting with the RealWave 's mesh. The water 
      /// line represents the intersection between the object and the RealWave 's mesh. 
      /// The result of this function is a vector of ordered Vertices where every consecutive 
      /// pair of Vertices forms a segment, so the first vertex and the second forms the first segment,
      /// the second and the third forms the second segment, and so on. The last vertex and the 
      /// first vertex forms the last segment that closes the water line. A water line Vertex has a position, 
      /// a velocity and a normal. The velocity of a water line Vertex is the relative velocity between
      /// the velocity of the RealWave 's mesh and the velocity of the object at the intersection point. 
      /// The normal is just the normal of the Face of the object that is intersecting with the RealWave 's mesh.
      ///
      /// @param [in] objName / name of the object for which the water line will be returned
      ///
      /// @param [out]  vertexs / Vector of Vertices that form the water line
      //
      void getWaterLine( ArrSdkVertex& vertexs , const std::string& objName ); 

      /// getAdjoiningFacesToVertex:  
      ///
      /// Get the RealWave 's Faces sharing the Vertex given( vertex ).
      ///
      /// @param [in] vertex / Vertex
      ///
      /// @param [out]  faces / Vector of Faces sharing the Vertex( vertex )
      //
      void getAdjoiningFacesToVertex( ArrSdkFaces& faces , const Vertex& vertex );

      /// getAdjoiningFacesToFace:  
      ///
      /// Get the RealWave 's Faces connected to the Face given( face ). Two faces are connected if
      /// they share at least one edge.
      ///
      /// @param [in] face / Face
      ///
      /// @param [out]  faces / Vector of Faces connected to Face( face )
      //
      void getAdjoiningFacesToFace( ArrSdkFaces& faces, const Face& face );

      /// getVerticesInsideWaterLine:  
      ///
      /// Get the list of Vertices inside the water line created by the Object given( objName ). 
      ///
      /// @param [in] objName / name of the object
      ///
      /// @param [out]  vertexs / Vector of Vertices inside the water line formed by Object( objName )
      //
      void getVerticesInsideWaterLine( ArrSdkVertex& outSdkVertexs, const std::string& objName );

      /// addWave:  
      ///
      /// Add a Wave of the type given( waveType ) to THIS RealWave
      ///
      /// @param [in] waveType / Wave 's type
      /// 
      /// @return a new Wave
      //
      Wave addWave( std::string& waveType );

      /// getWave:  
      /// 
      /// Gets Sdk Wave by name from THIS RealWave
      /// 
      /// @param [in] name / Sdk Wave 's name
      /// 
      /// @return :
      ///           Sdk Wave if found
      ///           Sdk Wave( Null ) if there is no Sdk Wave with such name
      //
      Wave          getWave         ( const std::string& name             );

      /// removeWave:  
      ///
      /// Remove the Wave given by its name( waveName ) from THIS RealWave
      ///
      /// @param [in] waveName / Wave 's name
      //
      void removeWave( std::string& waveName );

      /// getWaveParameter:  
      ///
      /// Gets the value of THIS Node 's Parameter given by its name( name ).
      /// As this is a templatized method you would need to indicate the type of the parameter.
      /// Example:
      /// int valueParameter = thisNode.getParameter<int>( "nameParameter" );
      ///
      /// @param [in] name / Node 's parameter name
      /// 
      /// @return : Node 's parameter value
      //
      template < class X > 
      X getWaveParameter( const std::string& waveName, const std::string& paramName );

      /// getWaveParameterType:  
      ///
      /// Gets THIS Wave 's Parameter type given by its name( paramName ).
      ///
      /// @param [in] waveName  / Wave 's name
      /// @param [in] paramName / Wave 's parameter name
      /// 
      /// @return : Wave 's parameter type, values in Param_Type [ TYPE_FLOAT  
      ///                                                          TYPE_DOUBLE 
      ///                                                          TYPE_LIST  
      ///                                                          TYPE_INT   
      ///                                                          TYPE_BOOL
      ///                                                          TYPE_EDIT
      ///                                                          TYPE_CBUTTON
      ///                                                          TYPE_BUTTON
      ///                                                          TYPE_BROWSE
      ///                                                          TYPE_VECTOR
      ///                                                          TYPE_COLOR ]
      ///                                             
      ///
      ///             - If the Wave has not a parameter with name ( paramName ) then it return -1;
      //
      sdk_type::SdkParamType getWaveParameterType( const std::string& waveName, const std::string& paramName );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setWaveParameter( const std::string& waveName, const std::string& paramName, const std::string& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setWaveParameter( const std::string& waveName, const std::string& paramName, const int& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setWaveParameter( const std::string& waveName, const std::string& paramName, const float& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setWaveParameter( const std::string& waveName, const std::string& paramName, const Vector& value );

      /// setParameter:  
      ///
      /// Sets THIS Node 's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] name / Node 's parameter name
      /// @param [in] value / Node 's parameter new value
      //
      void setWaveParameter( const std::string& waveName, const std::string& paramName, const Color& value );

      /// sdkExport:  
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// getType:
      /// 
      /// Gets the type of this Realflow Node Object
      /// 
      /// @return the type of this RealFlow Object
      //
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_REALWAVE; };


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::REAL_WAVE_TYPE; };

      // getVerticesAux
      void getVerticesAux( ArrSdkVertex& r_objs ); 

      // getFacesAux
      void getFacesAux( ArrSdkFaces& r_objs );

      // getParameterT
      int getWaveParameterT( const std::string& waveName, const std::string& paramName, int* ignore );

      // getParameterT
      bool getWaveParameterT( const std::string& waveName, const std::string& paramName, bool* ignore );

      // getParameterT
      float getWaveParameterT( const std::string& waveName, const std::string& paramName, float* ignore );

      // getParameterT
      std::string getWaveParameterT( const std::string& waveName, const std::string& paramName, std::string* ignore );

      // getParameterT
      Vector getWaveParameterT( const std::string& waveName, const std::string& paramName, Vector* ignore );

      // getParameterT
      Color getWaveParameterT( const std::string& waveName, const std::string& paramName, Color* ignore );

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
       friend class NodeAccesor;
       friend class Wave;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_REAL_WAVE_H...





