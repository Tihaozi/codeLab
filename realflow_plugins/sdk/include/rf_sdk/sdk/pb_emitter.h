
#ifndef _NL_SDK_RF_PB_EMITTER_H
#define _NL_SDK_RF_PB_EMITTER_H

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
#include "rf_sdk/sdk/pb_particle.h"
#include "rf_sdk/sdk/vertex.h"
#include "rf_sdk/sdk/face.h"

//
// FORWARD DECLARATIONS
//

namespace nextlimit
{
  class MutexRW;

  namespace realflow
  {
    class Particle;
  }
}

class ParticleFluidEmitter3;

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
    // PB_Emitter:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC PB_Emitter 
      : public RFNodeType< ::ParticleFluidEmitter3, nl::rf_sdk::Node_ExpRsc >
    {

    public:

      enum ParticleAttributeType
      {
        PARTICLE_ATTR_TYPE_DOUBLE,
        PARTICLE_ATTR_TYPE_FLOAT,
        PARTICLE_ATTR_TYPE_INT,
        PARTICLE_ATTR_TYPE_CHAR,
        PARTICLE_ATTR_TYPE_BOOL,
        PARTICLE_ATTR_TYPE_VECTOR
      };

    public:

      static const int EXPORT_PARTICLES_BIN;
      static const int EXPORT_PARTICLES_PROXY;
      static const int EXPORT_PARTICLES_ASC;
      static const int EXPORT_PARTICLES_PRT;
      static const int EXPORT_PARTICLES_PDC;
      static const int EXPORT_PARTICLES_PD;
      static const int EXPORT_GRID_FOAM_FTC;
      static const int EXPORT_GRID_FOAM_TEXTURE;

    public:  

        class RF_SDK_EXPORTS_DLL iterator 
        {
          public:
            rf::Particle* currPtr_;
            rf::Particle* lastPtr_;

            iterator();
            iterator( rf::Particle* firstPtr, rf::Particle* lastPtr = NULL );

            // hasNext
            bool hasNext( void );

            // next
            PB_Particle next( void );
        };

    DECLARE_STD_VECTOR_TYPES( PB_Emitter::iterator, SdkPB_EmitterIters );
    

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      PB_Emitter( ParticleFluidEmitter3* nativeObjPtr ) 
        : RFNodeType< ::ParticleFluidEmitter3, nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~PB_Emitter( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE


      /// getParticles:  
      /// Get PB_Emitter 's list of particles.
      /// You might want to iterate the PB_Emitter 's particles using the "getFirstParticle" 
      /// and the particle's function "getNextParticle" instead of using this function 
      /// if the number of particles is really big. In that case if you use this function 
      /// you will obtain a copy of all the particles which means more memory resources needed. 
      /// See the "getFirstParticle" function to learn more about how to get and iterate particles. 
      /// @param [out] Particles / Vector of Particles
      void             getParticles        ( std::vector<PB_Particle>& particles );

      /// getFirstParticle:  
      /// Gets the emitter's first particle. If THIS PB_Emitter has no particles then a Null
      /// Particle is returned
      /// This member function is very useful when we want to iterate the particles in the emitter. 
      /// Just get the first particle and then iterate the particles by using the "getNextParticle()" 
      /// member function in the "Particle" class.
      /// This approach is preferred to that one where the whole list of particles is got 
      /// at once and then we iterate them. In that case a whole copy of the list of particles
      /// must be obtained.
      /// @return :
      ///           PB_Emitter 's first Particle if found
      ///           Null Particle if THIS PB_Emitter has no particles
      PB_Particle getFirstParticle    ( void );

      /// getParticle:  
      /// Get Particle by Id from THIS PB_Emitter
      /// @param [in] particleId / Particle 's Id
      /// @return :
      ///           Particle if found
      ///           Null Particle if there is no Particle with such Id
      PB_Particle getParticle( int particleId );

      /// removeParticle:  
      /// Delete a Particle from THIS PB_Emitter
      /// @param [in] particleId / Particle 's Id
      void removeParticle( long particleId );

      /// addParticle:  
      /// Add a Particle to the PB_Emitter
      /// @param [in] globalPos / New Particle 's global position
      /// @param [in] velocity /  New Particle 's velocity
      PB_Particle addParticle( const Vector& globalPos, 
                                       const Vector& velocity );

      /// getParticlesColliding:  
      /// Get the PB_Emitter 's list of Particles that are colliding at the moment this function is called.
      /// In the simulation pipeline there is a moment where the collision is detected, 
      /// at that moment the flag of collision for every particle colliding is set and 
      /// is cleared at the beginning of the next simulation cycle. 
      /// Because of that reason we can guarantee that there is always a valid list of particles
      /// at the "Simulation Step End" event.
      /// @param [out] Particles / Vector of Particles colliding
      void getParticlesColliding( std::vector<PB_Particle>& outParticles );

      /// sdkExport:  
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// createVoxelization:  
      /// Create the internal data structures that RealFlow uses for speed up the searching of 
      /// the nearest neighbors. Please note that these data structures are only created automatically
      /// by RealFlow for "Liquid" type particles and particle solver plug-ins during the simulation process.
      /// If your particle type doesn't match those and you want to find neighbors you must
      /// call this function explicitly. The same is applicable if your fluid is of "Liquid" type
      /// but you are running the script off the simulation loop.
      /// 
      /// NOTE: if you remove particles from an PB_Emitter where you have created the internal 
      /// data structures you have to re-create the data structures again because they become invalid. 
      void createVoxelization( const bool forceCreationDataStrt,
                               const float voxelLength = 0.0f );

      /// destroyVoxelization:  
      /// Destroys the current voxelization freeing all the related resources. See 
      /// "createVoxelization" to learn mode about RealFlow voxelization.
      void destroyVoxelization( void );

      /// testPositionForParticleInsertion:  
      /// Add a Particle to the PB_Emitter
      /// @param [in] globalPos   / Position to test in global coordinates
      /// @param [in] relaxFactor / Relaxation factor to alleviate the testing condition :
      ///                             - relaxFactor < 0 ; relaxFactor is ignored
      ///                             - relaxFactor == 0.0 means no relaxation at all
      ///                             - relaxFactor > 0 will relax the condition gradually
      /// @return bool / True if it is safe to insert the particle, False otherwise. 
      bool testPositionForParticleInsertion(  const Vector& globalPos, 
                                                    float relaxFactor );

      /// removeAllParticles: 
      /// Remove all PB_Emitter 's Particles
      void removeAllParticles( void );

      /// computeVorticity: 
      /// Compute the vorticity attribute for all the particles in THIS PB_Emitter
      void computeVorticity( void );

      /// getSelectedVertices:  
      /// Gets the PB_Emitter 's selected Vertexes.
      ///
      /// IMPORTANT: This method only works for "Object Emitters"
      /// 
      /// @param [in] typeRef   / Coordinates reference used; #Default value = RF_LOCAL
      ///                         typeRef 's values in [ REF_GLOBAL, RF_LOCAL ] 
      /// @param [out] sdkVertexs / Vector of Vertexes
      void  getSelectedVertices ( std::vector<Vertex>& sdkVertexs, 
                                  int                  typeRef = REF_GLOBAL );

      /// getSelectedFaces:  
      /// Gets the PB_Emitter 's selected Faces.
      ///
      /// IMPORTANT: This method only works for "Object Emitters"
      /// 
      /// @param [out] sdkFaces / Vector of Faces
      void getSelectedFaces( std::vector<Face>& sdkFaces );

      /// setSelectedFaces:  
      /// Selects Faces of THIS PB_Emitter by index
      ///
      /// IMPORTANT: This method only works for "Object Emitters"
      /// 
      /// @param [in] idxs   / Vector of Face 's indexes to be selected 
      void setSelectedFaces( const std::vector<int>& idxs );

      /// setSelectedVertices:  
      /// Selects Vertexes of THIS PB_Emitter by index
      ///
      /// IMPORTANT: This method only works for "Object Emitters"
      /// 
      /// @param [in] idxs   / Vector of Vertexes 's indexes to be selected 
      void setSelectedVertices( const std::vector<int>& idxs );

      /// getFirstParticle:  
      /// Gets an Iterator over all the PB_Emitter 's Particles. In the same order that you would
      /// get using the method firstParticle and traversing the list of particles calling repeatedly
      /// getNextParticle. 
      /// This approach is preferred to that one where the whole list of particles is got 
      /// at once and then we iterate them. In that case a whole copy of the list of particles
      /// must be obtained.
      /// @return : PB_Emitter 's Particles Iterator
      PB_Emitter::iterator getIterator( void ) 
      { 
        PB_Particle firstParticle = getFirstParticle();

        if ( firstParticle.isNull() )
        {
          return iterator();
        }
        else
        {
          return iterator( firstParticle.getNativeObj().getSafe() );
        }
      };

      /// getPartition:  
      /// Obtains a partition of all the particles of THIS PB_Emitter used to make parallel calculations.
      /// Each partition is represented by an PB_Emitter 's Particles Iterator, by which you can access
      /// sequentially to all the particles that belong to the same partition.
      /// 
      /// @param [out] partition / Vector of PB_Emitter::iterator each Iterator representing a partition
      void getPartition( ArrSdkPB_EmitterIters& partitionOut );

      /// getPartition:  
      /// Obtains a partition of all the particles of THIS PB_Emitter used to make parallel calculations.
      /// Each partition is represented by Vector of Particles.
      /// 
      /// @param [out] partition / Vector of Vector of Particles, each Vector of Particles representing
      ///                          a partition.
      void getPartitionSet( std::vector< ArrSdkPB_Particles >& outPartition );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_PB_EMITTER; };

      /// getId:  
      /// Gets the id of this emitter
      /// @return the id of this emitter
      const int getId( void ) const;

      /// createParticlesAttribute:  
      ///
      /// Creates an attribute for all the particles in this emitter. 
      /// Existent and new particles will have the new attribute.
      ///
      /// @param [in] id / Unique identification for the attribute.
      /// @param [in] type / Type of the attribute, valid values are :
      /// PARTICLE_ATTR_TYPE_BOOL 
      /// PARTICLE_ATTR_TYPE_CHAR
      /// PARTICLE_ATTR_TYPE_INT 
      /// PARTICLE_ATTR_TYPE_FLOAT 
      /// PARTICLE_ATTR_TYPE_DOUBLE 
      /// PARTICLE_ATTR_TYPE_VECTOR
      ///
      /// @return : True if the attribute was created, False otherwise.
      bool createParticlesAttribute( const int& id, const ParticleAttributeType& type );

      /// createParticlesAttribute:  
      ///
      /// Creates an attribute for all the particles in this emitter. 
      /// Existent and new particles will have the new attribute.
      /// The size of the data is specified instead of the type so this function
      /// allows you to create chunks of data per particle.
      ///
      /// @param [in] id / Unique identification for the attribute.
      /// @param [in] size / Size of data in bytes
      ///
      /// @return : True if the attribute was created, False otherwise.
      bool createParticlesAttribute( const int& id, const unsigned int& dataSize );

      /// destroyParticlesAttribute:  
      ///
      /// Destroys an attribute for all the particles in this emitter.
      ///
      /// @param [in] id / Identification for the attribute.
      ///
      /// @return : True if the attribute was destroyed, False otherwise
      bool destroyParticlesAttribute( const int& id );
      
      /// queryParticlesAttribute:  
      ///
      /// Returns True if the attribute exists in the emitter False otherwise.
      ///
      /// @param [in] id / Identification for the attribute.
      ///
      /// @return : True if the attribute exists, False otherwise. 
      bool queryParticlesAttribute( const int& id );
      
      /// getSelectedParticles:  
      /// Get PB_Emitter 's list of user selected particles for the specified group.
      ///
      /// @param [in] group / Name of the selection group
      /// @param [out] particles / Vector of Particles
      void getSelectedParticles( const std::string& group, std::vector<PB_Particle>& particles );
      
      /// getParticleSelectionGroups:  
      /// Get PB_Emitter 's list of particle selection group names.
      ///
      /// @param [out] groups / Vector of names
      void getParticleSelectionGroups( std::vector<std::string>& groups );

      /// getNumberOfParticles:
      ///
      /// returns the number of particles of this emitter
      ///
      /// @return: the number of particles of the emitter
      unsigned int getNumberOfParticles() const;

      /// addParticles
      ///
      /// Add particles to the emitter using a list of positions and velocities. 
      /// By default is done in a safe manner so particles won't be added when 
      /// the position is not valid, i.e. adding a particle at that position will 
      /// make the fluid instable. 
      /// @param [ArrSdkVector] positions / List of positions.
      /// @param [ArrSdkVector] velocities / List of velocities.
      /// @param [ArrSdkVector] safe / true to add particles in a safe manner, false otherwise. 
      void addParticles(  const ArrSdkVectors& positions,
                          const ArrSdkVectors& velocities,
                          const NL_BOOL safe = true );
      
      /// getEmitterType:  
      /// 
      /// Returns the name of the type of the emitter. For example: "Circle"..
      ///
      /// @return :The type of the emitter as a string
      //
      std::string getEmitterType( void ) const;
           
	    /// setEditionMode:  
      /// 
      /// Changes the state of the Spline emitter edition mode. 
      /// It is the same effect as when clicking on the "Edit" button. 
      ///
      /// @param [in] enableEdition / True to activate edition mode.
      ///
      /// @return :True if the emitter is a Spline emitter. False otherwise.
      //
      bool setEditionMode( const bool enableEdition );
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations (control points)
      //  @{ 
    public:

     
	    /// insertControlPoint:  
      /// 
      /// Inserts a new control point for the Spline emitter.
      ///
      /// @param [in] position / The position of the control point.
      /// @param [in] handleInPosition / The position of the in handle of the control point.
      /// @param [in] handleOutPosition / The position of the out handle of the control point.
      ///
      /// @return : False if the type of the emitter is not the ESpline.
      ///
      bool insertControlPoint(  const Vector& position,
                                const Vector& handleInPosition,
                                const Vector& handleOutPosition );
      
	    /// removeControlPoint:  
      /// 
      /// Removes the current control point for the Spline emitter.
      ///
      /// @param [in] index / The index of the control point.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the emitter is not the ESpline.
      ///
      bool removeControlPoint( const unsigned int index );
      
	    /// removeControlPoints:  
      /// 
      /// Deprecated, use removeAllControlPoints instead.
      ///
      /// @return : False if the type of the emitter is not the ESpline.
      ///
      bool removeControlPoints( void );

	    /// removeAllControlPoints:  
      /// 
      /// Removes all the DSpline emitter control points.
      ///
      /// @return : False if the type of the emitter is not the ESpline.
      ///
      bool removeAllControlPoints( void );

	    /// getNumberOfControlPoints:  
      /// 
      /// Returns the number of control points of the DSpline emitter.
      ///
      /// @return :The number of control points. 0 if emitter is not of DSpline type.
      //
      int getNumberOfControlPoints( void );

      /// setControlPointPosition:  
      /// 
      /// Set the position of a control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] position / The new position of the control point.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the emitter is not the ESpline.
      ///
      bool setControlPointPosition( const unsigned int index, 
                                    const Vector& position );

	    /// setControlPointHandleInPosition:  
      /// 
      /// Set the position of the in handle of the control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] position / The new position of the in handle.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the emitter is not the ESpline.
      ///
      bool setControlPointHandleInPosition( const unsigned int index, 
                                            const Vector& position );

	    /// setControlPointHandleOutPosition:  
      /// 
      /// Set the position of the out handle of the control point.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] position / The new position of the out handle.
      ///
      /// @return : False if the index of the control point is not valid or if the type
      ///           of the emitter is not the ESpline.
      ///
      bool setControlPointHandleOutPosition(  const unsigned int index, 
                                              const Vector& position );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const std::string& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const int& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const int64_t& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const float& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const double& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const nl::rf_sdk::Vector& value );

	    /// setControlPointParameter:  
      /// 
      /// Set value for the parameter of a control point. The parameter name is the one 
      /// that can be seen in the user interface. It is not case sensitive. The value 
      /// can be any type that is accepted for the parameters in the user interface. 
      /// Care must be taken when using this function about the type of the values and 
      /// the parameter names, a hard type and name check is done reporting the 
      /// corresponding errors to the user in any case
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [in] value / The control point parameter value.
      ///
      /// @return : False if the parameter can't be changed, reasons could be:
      ///           - The index of the control point is not valid.
      ///           - The type of the emitter is not the ESpline.
      ///           - The parameter does not exist.
      ///           - The parameter type is not the right one.
      ///
      bool setControlPointParameter(  const unsigned int index, 
                                      const std::string& name, 
                                      const nl::rf_sdk::Color& value );     
      
      /// getControlPointParameter:  
      ///
      /// Get the control point value for the parameter. Please read 
      /// "setControlPointParameter" description to know more about this function.
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [out] ok / False if the parameter can't be changed, reasons could be:
      ///                     - The index of the control point is not valid.
      ///                     - The type of the emitter is not the ESpline.
      ///                     - The parameter does not exist.
      ///                     - The parameter type is not the right one.
      ///
      /// @return : The control point parameter's value. 
      ///
      template< class T >
      const T getControlPointParameter( const unsigned int index, 
                                        const std::string& name,
                                              bool& ok ) const;

      /// getControlPointParameterType:  
      ///
      /// Get the control point parameter's type. 
      ///
      /// @param [in] name  / Control point parameter's name. 
      /// @param [out] ok / False if the parameter can't be changed, reasons could be:
      ///                     - The type of the emitter is not the ESpline.
      ///                     - The parameter does not exist.
      ///
      /// @return : The parameter type, values in Param_Type [ TYPE_FLOAT  
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
      //
      sdk_type::SdkParamType getControlPointParameterType(  const std::string& name,
                                                                  bool& ok ) const;

      /// getControlPointParameterCurve:  
      ///
      /// @param [in] index / The index of the control point.
      /// @param [in] name / The control point parameter name.
      /// @param [out] ok / False if the parameter can't be changed, reasons could be:
      ///                     - The index of the control point is not valid.
      ///                     - The type of the emitter is not the ESpline.
      ///                     - The parameter does not exist.
      ///
      /// @return : The control point parameter's curve
      ///
      Curve getControlPointParameterCurve(  const unsigned int index,
                                            const std::string& name,
                                                  bool& ok ) const;

      /// getControlPointAllParameterNames:  
      ///
      /// Gets a list of Tuples < Parameter name, Parameter type >  
      ///     - Parameter names and types existing for the control point
      ///
      /// @param [out] parameterNames / Vector of Tuples < Parameter name, Parameter type > 
      ///
      /// @return : False if the type of the emitter is not the ESpline.
      /// 
      bool getControlPointAllParameterNames( std::vector< std::pair< std::string, int > >& parameterNames ) const;

      /// getControlPointCurveName:  
      /// 
      /// Deprecated, now is possible to access the curve of a control point using the 
      /// control point index.
      //
      std::string getControlPointCurveName( const int pointIndex, 
                                            const std::string parameterName ) const;

      /// evaluateSpline:
      ///
      /// If the emitter is of Spline type, returns the point of the spline given by the
      /// span and the parameter t.
      /// @param [in] span / The section of the spline to be evaluated. Must be less than
      ///                    the number of control points of the spline.
      /// @param [in] t / Parameter between 0 and 1 to determine where the spline is
      ///                 evaluated.
      /// @param [out] result / The position of the spline for the given parameters.
      ///
      /// @return : False if the span is out of range or this is not a spline emitter.
      ///
      bool evaluateSpline( const unsigned int span,
                          const float t,
                          Vector& result ) const;
      

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::PB_EMITTER_TYPE; };

      //
      void getPartitionSetInt( std::vector< std::vector<nl::rf_sdk::PB_Particle> >& outParticles );

      //
      void getPartitionInt( ArrSdkPB_EmitterIters& partitionOut ); 

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

    typedef PB_Emitter::iterator RFEmitter_It;

  }; // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_RF_PB_EMITTER_H...





