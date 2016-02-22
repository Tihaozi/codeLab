
#ifndef _NL_SDK_PARTICLE_MESH_LEGACY_H
#define _NL_SDK_PARTICLE_MESH_LEGACY_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"

// FORWARD REFERENCES
class ParticleFluidWrapperLegacy;

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
    class MultiBody;

    //-----------------------------------------------------------------------------------
    //
    // ParticleMeshLegacy:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC ParticleMeshLegacy 
          : public RFNodeType< ::ParticleFluidWrapperLegacy, nl::rf_sdk::Node_ExpRsc >
    {

    public:
      static const int EXPORT_MESHES_BIN;
      static const int EXPORT_MESHES_MD;
      static const int EXPORT_MESHES_OBJ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      ParticleMeshLegacy( ParticleFluidWrapperLegacy* nativeObjPtr ) 
        : RFNodeType< ::ParticleFluidWrapperLegacy, nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {}

    public:
      /// Destructor
      virtual ~ParticleMeshLegacy( void ) {}


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getEmitterParameter:  
      ///
      /// Gets the value of the emitter's Parameter given by its name( name ).
      /// As this is a templatized method you would need to indicate the type of the parameter.
      /// Example:
      /// int valueParameter = thisNode.getEmitterParameter<int>( "nameParameter" );
      ///
      /// @param [in] emitterName / emitter's name
      /// @param [in] paramName / emitter's parameter name
      /// 
      /// @return : emitter's parameter value
      //
      template < class X > 
      X getEmitterParameter(  const std::string& emitterName, 
                              const std::string& paramName );

      /// getEmitterParameterType:  
      ///
      /// Gets the emitter's Parameter type given by its name( paramName ).
      ///
      /// @param [in] emitterName / emitter's name
      /// @param [in] paramName / emitter's parameter name
      /// 
      /// @return : emitter's parameter type, values in [ float            ,
      ///                                               double           ,
      ///                                               std::vector[int] ,
      ///                                               int              ,
      ///                                               bool             ,
      ///                                               Vector           ,
      ///                                               Color
      ///                                              ]
      ///
      ///             - If the emitter has not a parameter with name ( paramName ) then it return -1;
      //
      NL_INT getEmitterParameterType( const std::string& emitterName,
                                      const std::string& paramName );

      /// setEmitterParameter:  
      ///
      /// Sets the emitter's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] emitterName / emitter's  name
      /// @param [in] paramName   / emitter's parameter name
      /// @param [in] value       / emitter's parameter new value
      //
      void setEmitterParameter( const std::string& emitterName,
                                const std::string& paramName, 
                                const std::string& value );

      /// setEmitterParameter:  
      ///
      /// Sets the emitter's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] emitterName / emitter's  name
      /// @param [in] paramName   / emitter's parameter name
      /// @param [in] value       / emitter's parameter new value
      //
      void setEmitterParameter( const std::string& emitterName,
                                const std::string& paramName, 
                                const int& value );

      /// setEmitterParameter:  
      ///
      /// Sets the emitter's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] emitterName / emitter's  name
      /// @param [in] paramName   / emitter's parameter name
      /// @param [in] value       / emitter's parameter new value
      //
      void setEmitterParameter( const std::string& emitterName,
                                const std::string& paramName, 
                                const float& value );

      /// setEmitterParameter:  
      ///
      /// Sets the emitter's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] emitterName / emitter's  name
      /// @param [in] paramName   / emitter's parameter name
      /// @param [in] value       / emitter's parameter new value
      //
      void setEmitterParameter( const std::string& emitterName, 
                                const std::string& paramName, 
                                const Vector& value );

      /// setEmitterParameter:  
      ///
      /// Sets the emitter's Parameter value given by its name( name ). The parameter 
      /// name is the one that can be seen in the user interface. It is not case sensitive. 
      /// The value can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and the parameter names, 
      /// a hard type and name check is done reporting the corresponding errors to the user in any case.
      ///
      /// @param [in] emitterName / emitter's  name
      /// @param [in] paramName   / emitter's parameter name
      /// @param [in] value       / emitter's parameter new value
      //
      void setEmitterParameter( const std::string& emitterName,
                                const std::string& paramName, 
                                const Color& value );

      /// sdkExport:  
      ///
      /// Writes out all the resources that are active in the export central
      void sdkExport( void );

      /// addEmitter:  
      /// 
      /// Add an Emitter to THIS ParticleMeshLegacy
      ///
      /// @param [in] emitterName / Emitter 's name to be added to THIS ParticleMeshLegacy
      /// @return : True if the emitter was added. False if the emitter could not be added
      ///           becase it is not compatible or already existed.
      bool addEmitter( const std::string& emitterName ); 

      /// removeEmitter:  
      /// 
      /// Remove an Emitter from THIS ParticleMeshLegacy
      ///
      /// @param [in] emitterName / Emitter 's name to removed from THIS ParticleMeshLegacy
      /// @return : True if the emitter was removed. False if the emitter did not belong
      ///            to the mesh
      bool removeEmitter( const std::string& emitterName ); 

      /// getEmitters:  
      ///
      /// Get Emitters 's names that contribute to create THIS ParticleMeshLegacy
      ///
      /// @param [out] emitterNames / Vector of Emitters 's names
      void getEmitters( std::vector< std::string >& emitterNames ); 

      /// build:  
      ///
      /// Builds the ParticleMeshLegacy
      void build();

      /// getParticlesOutside:  
      ///
      /// Get all particles that belong to the Emitters 's Fluids in THIS ParticleMeshLegacy that are outside
      /// THIS ParticleMeshLegacy
      ///
      /// @param [out] particles / Vector of Particles
      void getParticlesOutside( ArrSdkPB_Particles& particles ); 

      /// getGeometry:  
      ///
      /// Get a Tuple with the < Faces, Vertexes > of THIS ParticleMeshLegacy 
      ///
      /// @param [out] geometry / Tuple of Vectors < Vector of Faces, Vector of Vertexes >
      void getGeometry( std::pair< ArrSdkVertex, ArrSdkFaces >& geometry ); 

      /// getFluidsWeightsPerVertex:  
      ///
      /// Gets a list of Tuples < Emitter 's name, weight contribution >  
      ///     - Weight contribution for the mesh vertex which index is passed as parameter
      ///
      /// @param [in] vertexIdx / Vertex 's index
      ///
      /// @param [out] fluidWeights / Vector of Tuples < Emitter 's name, weight contribution > 
      void getFluidsWeightsPerVertex
        ( std::vector< std::pair< std::string, float > >&  fluidWeights,
          int vertexIdx                                                     ); 

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
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_STANDARD_MESH; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::STANDARD_MESH_TYPE; };

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
#endif // _NL_SDK_PARTICLE_MESH_LEGACY_H...





