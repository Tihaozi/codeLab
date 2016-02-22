
#ifndef _RF_PB_PARTICLE_H
#define _RF_PB_PARTICLE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <vector>
#include <rf_common/core/rf_basicdefs.h>

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/vector.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/rfbaseobj.h"
//#include "rf_sdk/sdk/nodeaccesor.h"

//
// FORWARD DECLARATIONS
//

namespace nextlimit
{
  namespace realflow
  {
    class Particle;
  }
}

#if defined( _CPP_UNIT )
namespace nextlimit
{
  namespace test
  {
    class Test_Sdk_PB_Emitter;
  }
}
#endif


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    enum FindingNearestObjectMode
    {
      USE_LINKED_OBJECTS,
      USE_SCENE_OBJECTS
    };

    
    // FORWARD REFERENCES
    class NodeAccesor;
    class ParticleMeshLegacy;
    class PB_Emitter;

    //-----------------------------------------------------------------------------------
    //
    // rf_sdk::PB_Particle:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL PB_Particle : public RFNativeBaseObj<rf::Particle>
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      PB_Particle( rf::Particle* nativeObjPtr ) 
        : RFNativeBaseObj<rf::Particle>( nativeObjPtr ) {};

    public:

      /// Destructor
      virtual ~PB_Particle( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // INTERFACE

      /// getId:  
      ///
      /// Gets the particle's id
      ///
      /// @return : particle's id
      long getId() const;

      /// getEmitterId:  
      ///
      /// Gets the id of the particle emitter
      ///
      /// @return : particle's id
      long getEmitterId() const;

      /// setPosition:  
      ///
      /// Gets the particle's position
      ///
      /// @return : particle's position
      Vector getPosition( void ) const;

      /// setPosition:  
      ///
      /// Sets the particle's position
      ///
      /// @param [in] pos / Vector position
      void setPosition( const Vector& pos );

      /// getVelocity:  
      ///
      /// Gets the particle's velocity
      ///
      /// @return : particle's velocity
      Vector getVelocity( void ) const;

      /// getVorticity:  
      ///
      /// Gets the particle's vorticity
      ///
      /// @return : particle's vorticity
      Vector  getVorticity( void ) const;

      /// setExternalForce:  
      ///
      /// Set the particle's external force. This force is added to any previous external 
      /// force so this function can be used several times to create the force contribution 
      /// from external force fields. It's safe to use this function during the "OnApplyExternalForces" event,
      /// outside the scope of that event the RF internal engine will reset the external forces 
      /// at some specific point in the pipeline.
      ///
      /// @param [in] force / External Force
      void setExternalForce( const Vector& force );

      /// getExternalForce:  
      ///
      /// Gets the particle's external Force
      ///
      /// @return : particle's external Force
      Vector getExternalForce( void ) const ;

      /// setInternalForce:  
      ///
      /// Sets the particle's internal force
      ///
      /// @param [in] force / new Internal Force
      void setInternalForce( const Vector& force );

      /// getInternalForce:  
      ///
      /// Gets the particle's internal Force
      ///
      /// @return : particle's internal Force
      Vector getInternalForce( void ) const ;

      /// setVelocity:  
      ///
      /// Sets the particle's velocity
      ///
      /// @param [in] velocity / new particle's velocity
      void setVelocity( const Vector& velocity );

      /// setVelocity:  
      ///
      /// Set the particle's change in velocity. During the simulation the particle's
      /// velocity is computed by the solver integrating the force, if you want to 
      /// change the particle´s velocity directly during the simulation and don't let 
      /// the solver to overwrite your value you must use this function. The velocity 
      /// you set is added to the velocity calculated by the solver.
      ///
      /// @param [in] velocity / new particle's change in velocity
      void setChangeInVelocity( const Vector& velocity );

      /// getAge:  
      ///
      /// Gets the particle's age
      ///
      /// @return : particle's age
      float getAge( void ) const ;

      /// setAge:  
      ///
      /// Sets the particle's age
      ///
      /// @param [in] age / new particle's age
      void setAge( float age );

      /// getDensity:  
      ///
      /// Gets the particle's density
      ///
      /// @return : particle's density
      float getDensity( void ) const ;

      /// setDensity:  
      ///
      /// Sets the particle's density
      ///
      /// @param [in] density / new particle's density
      void setDensity( float density );

      /// getPressure:  
      ///
      /// Gets the particle's pressure
      ///
      /// @return : particle's pressure
      float getPressure() const; 

      /// setPressure:  
      ///
      /// Sets the particle's pressure
      ///
      /// @param [in] pressure / new particle's pressure
      void setPressure( float pressure ); 

      /// getRadius:  
      ///
      /// Gets the particle's radius
      ///
      /// @return : particle's radius
      float getRadius() const; 

      /// setRadius:  
      ///
      /// Sets the particle's radius
      ///
      /// @param [in] radius / new particle's radius
      void setRadius( float radius ); 

      /// getTemperature:  
      ///
      /// Gets the particle's temperature
      ///
      /// @return : particle's temperature
      float getTemperature() const; 

      /// getMass:  
      ///
      /// Sets the particle's mass
      ///
      /// @param [in] radius / new particle's mass
      float getMass( void );

      /// setMass:  
      ///
      /// Sets the particle's mass
      ///
      /// @param [in] mass / new particle's mass
      void setMass( float mass ); 

      /// getUV:  
      ///
      /// Get the particle's uv texture coordinates. The third element in the vector is not used. 
      ///
      /// @return : particle's uv texture coordinates
      Vector getUV() const; 

      /// setUV:  
      ///
      /// Sets the particle's texture coordinate
      ///
      /// @param [in] uv / new particle's texture coordinate
      void setUV( const Vector& uv );

      /// getNormal:  
      ///
      /// Gets the particle's normal vector. For Particles that are at the fluid boundaries 
      /// this vector is pointing to the fluid surface. For Particles inside the fluid the normal's norm 
      /// is almost zero
      ///
      /// @return : particle's normal vector
      Vector getNormal() const;

      /// getIsolationTime:  
      ///
      /// Gets the particle's time alone
      ///
      /// @return : particle's time alone
      float getIsolationTime() const; 

      /// isColliding:  
      ///
      /// Says whether the particle is colliding or not. The collision detection is 
      /// done for objects and the RealWave surface. 
      ///
      /// @return : True if the PB_Particle is colliding, false otherwise
      bool isColliding() const; 

      /// getNeighbors:  
      ///
      /// Get the list of particles that are inside the sphere which center is placed 
      /// in the current particle position and has a radius given as the argument. 
      /// Putting it plain, get the list of particles where the distance with the 
      /// current particle is less than the argument. Whenever is possible this 
      /// function uses the internal RealFlow data structures to speed up the search, 
      /// if not a brute force algorithm is used. You can force the generation of the 
      /// RealFlow data structures by using the function "createVoxelization" in the 
      /// "PB_Emitter" class.
      ///
      /// If you are using this function in the simulation events and your particle 
      /// is of type Liquid then the data structures are created for sure. If you are 
      /// running this from a batch script then you must create the data structures 
      /// if you want to speed up the search.
      ///
      /// Whenever the data structures are used the particles from other emitters are 
      /// considered as neighbors if the emitter is linked to the emitter this particle 
      /// belongs to. If the data structures are not used only particles from the same 
      /// emitter are used.      
      ///
      /// @param [in] radius / Maximum distance to this PB_Particle
      /// 
      /// @param [out]  faces / Vector of Particles at <= radius distance of THIS PB_Particle
      void getNeighbors( ArrSdkPB_Particles& particles, const float& radius ) const;

      /// getCollidingObject:  
      ///
      /// Gets the Object that is colliding with THIS PB_Particle, it works also for the realwave Object.
      ///
      /// @return : Object that this PB_Particle is colliding with. It is returned wrapped in a
      ///           NodeAccesor. See NodeAccesor for details about recovering the embedded Object.
      ///           If there is no Object colliding a null Object is returned embedded in the NodeAccesor
      NodeAccesor getCollidingObject() const;

      /// getCollidingFace:  
      ///
      /// Get the Face 's index of the Object that is colliding with THIS PB_Particle, it works 
      /// also for the realwave object. To get the object that is colliding with the particle 
      /// use getCollidingObject. And to get the object's face corresponding to the index use Object::getFace(). 
      ///
      /// @return : Object's face's index of colliding Object
      //
      int getCollidingFace() const;

      /// freeze:  
      ///
      /// Keep THIS PB_Particle motionless during the simulation
      void freeze();

      /// freeze:  
      ///
      /// Bring back a frozen particle into the simulation
      void unfreeze();

      /// isBelowRealWave:  
      ///
      /// Returns whether THIS PB_Particle is below the RealWave surface or not
      ///
      /// @return : True if THIS PB_Particle is below the RealWave surface, false otherwise
      bool isBelowRealWave(); 

      /// setTemperature:  
      ///
      /// Sets the particle's temperature
      ///
      /// @param [in] temperature / new particle's temperature
      void setTemperature( float temperature ); 

      /// setVorticity:  
      ///
      /// Sets the particle's vorticity
      ///
      /// @param [in] vorticity / new particle's vorticity
      void setVorticity( Vector vorticity );

      /// getNextParticle:  
      ///
      /// Gets THIS particle's next particle in the whole particles list. 
      /// For every Emitter a list of Particles is kept, internally is a simple linked list, 
      /// and this function give us the functionality of iterate through the Emitter 's particles. 
      /// To learn more about how to iterate particles have a look at the Emitter class.
      ///
      /// @return : particle's next particle
      PB_Particle getNextParticle( void );

      /// getNearestObject:  
      ///
      /// Find the nearest Object to THIS PB_Particle in a specific direction. If direction is set to
      /// ( 0, 0, 0 ) then all the Objects around are searched. 
      ///
      /// @param [in] dir / Direction which is normalized internally
      /// @param [in] findingMode / findingMode = 
      ///                             - USE_LINKED_OBJECTS -> to consider only Objects linked to the Emitter this paticle belongs to.
      ///                             - USE_SCENE_OBJECTS -> to consider all the objects in the scene.
      /// 
      /// @param [out]  intersection / Nearest Object 's intersection point
      /// @param [out]  normal / Normal at the intersection point
      /// @param [out]  index / Index of the face
      /// @param [out]  distance / Nearest Object 's distance to THIS PB_Particle
      Object getNearestObject( const Vector& dir,   
                               const int& findingMode,
                               Vector& intersection,
                               Vector& normal,
                               unsigned int& index,
                               float& distance );

      /// getNearestObject:  
      ///
      /// Find the nearest point in the object to the particle in a specific direction. 
      /// If direction is set to ( 0, 0, 0 ) then just the nearest point is found.
      ///
      /// @param [in] Object's name
      /// @param [in] dir / Direction which is normalized internally
      /// 
      /// @param [out]  intersection / Nearest point
      /// @param [out]  normal / Normal at the nearest point
      /// @param [out]  index / Index of the face
      /// @param [out]  distance / Distance to nearest point
      ///
      /// /// @return : True if nearest point was found False otherwise.
      NL_BOOL getNearestPointToObject(  const std::string& objectName,
                                        const Vector& dir,   
                                              Vector& intersection,
                                              Vector& normal,
                                              unsigned int& index,
                                              float& distance );

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / value of the attribute
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, double& value ) const; 

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / value of the attribute
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, float& value ) const; 

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / value of the attribute
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, bool& value ) const; 

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / value of the attribute
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, int& value ) const; 

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / value of the attribute
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, char& value ) const; 

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / value of the attribute
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, Vector& value ) const; 

      /// getAttribute:  
      ///
      /// Gets a value of an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class.
      /// To be used only with attributes created using the data size instead of type.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [out] value / Pointer to value
      ///
      /// @return : True if the attribute was found, False otherwise
      bool getAttribute( const int id, void* value ) const; 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Value, must be the type of the attribute.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, const double& value ); 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Value, must be the type of the attribute.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, const float& value ); 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Value, must be the type of the attribute.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, const bool& value ); 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Value, must be the type of the attribute.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, const int& value ); 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Value, must be the type of the attribute.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, const char& value ); 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Value, must be the type of the attribute.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, const Vector& value ); 

      /// setAttribute:  
      ///
      /// Sets a value for an attribute. Attribute has to be created previously 
      /// using the "createParticlesAttribute" function in the "Emitter" class. 
      /// To be used only with attributes created using the data size instead of type.
      ///
      /// @param [in] id / Identification for the attribute.
      /// @param [in] value / Pointer to value.
      ///
      /// @return : True if the attribute was changed, False otherwise. 
      bool setAttribute( const int id, void* const value ); 

      /// queryAttribute:  
      ///
      /// Returns True if the attribute exists, False otherwise. 
      ///
      /// @param [in] id / Identification for the attribute.
      ///
      /// @return : True if the attribute exists False otherwise. 
      bool queryAttribute( const int id ) const; 

#if defined( _CPP_UNIT )
      //
      NL_BOOL operator < ( const PB_Particle& other )
      {
        NL_DEPRECATED;
        return NL_true;
      }
#endif

      ///////////////////////////////////////////////////////////////////////////////////
      //!  @}
      //!  @cond SHOW_PROTECTED
      //!  @name Helper methods
      //!  @{
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::PARTICLE_TYPE; };

      //! @}
      //! @endcond SHOW_PROTECTED


      ///////////////////////////////////////////////////////////////////////////////////
      //
      //! @name Data Members:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //!  @}
      //! @name friend Classes :
      //!  @{
    private:

      friend class PB_Emitter;
      friend class ParticleMeshLegacy;

#if defined( _CPP_UNIT )
      friend class nl::test::Test_Sdk_PB_Emitter;
#endif


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //
      //
      ///////////////////////////////////////////////////////////////////////////////////


    };

    /*! \class PB_Particle
        \brief Class PB_Particle

    <h2><a name="Examples"> <strong><em>Examples</em></strong> </a></h2>
    <p />
    <ul>
      <li> Example 1 <br><br>
      </li>
    </ul>
    <pre>
    @code
    std::stringstream sceneMsgBuf;

    //Iterate the list of particles and write out their ids.
    Particle currentParticle = emitter.getFirstParticle();

    while( !currentParticle.isNull() )
    {
      sceneMsgBuf << currentParticle.getId();
      scene.message( sceneMsgBuf.str() );
      sceneMsgBuf.str("");

      currentParticle = currentParticle.getNextParticle();
    }
    @endcode
    </pre>
    <ul>
      <li> Example 2 <br><br>
      </li>
    </ul>
    <pre>
    @code
    std::stringstream sceneMsgBuf;

    //// Count the number of neighbor particles for a particle.
    // Get the particles that are less than 0.1 distance from the current particle.
    ArrSdkParticles particles;
    circle01.getParticles( particles );

    Particle particle = particles[ 10 ];

    ArrSdkParticles neighbors;
    particle.getNeighbors( neighbors, 0.1 );

    sceneMsgBuf << "No. of Neighbors: " << neighbors.size();
    scene.message( sceneMsgBuf.str() );
    sceneMsgBuf.str("");
    @endcode
    </pre>
    <ul>
      <li> Example 3 <br><br>
      </li>
    </ul>
    <pre>
    @code
    std::stringstream sceneMsgBuf;

    // In the events script this will check particles colliding with objects and faces.
    Emitter::iterator iter = circle01.getIterator();

    while ( iter.hasNext() )
    {
      Particle particle = iter.next();

      NodeAccesor node = particle.getCollidingObject();
      if ( !node.isNull() )
      {
        Object obj = node.asRFObject();
        Face face = obj.getFace( particle.getCollidingFace() );
      }
    }
    @endcode
    </pre>
    <ul>
      <li> Example 4 <br><br>
      </li>
    </ul>
    <pre>
    @code
    std::stringstream sceneMsgBuf;

    // Add a particle and find the nearest object to that particle in a specific direction.
    circle01.removeAllParticles();
    Particle particle = circle01.addParticle( Vector( 1.0f, 1.0f, 1.0f ), Vector( 0.0f, 0.0f, 0.0f ) );
    Vector dir( 1.0f, 0.6f, 4.0f );
    dir.normalize();

    Vector intersection;
    Vector normal;
    float distance;
    Object object = particle.getNearestObject
      ( dir, find_nst_obj_mode::USE_SCENE_OBJECTS, intersection, normal, distance );

    if ( !object.isNull() )
    {
      sceneMsgBuf << "Nearest object: " << object.getName();
      scene.message( sceneMsgBuf.str() );
      sceneMsgBuf.str("");

      sceneMsgBuf << "Nearest object distance: " << distance;
      scene.message( sceneMsgBuf.str() );
      sceneMsgBuf.str("");

      msgBuf << testName << " Done!. ";
      scene.message( msgBuf.str() );
      msgBuf.str( "" );
    }
    @endcode
    </pre>
    <ul>
      <li> Example 5 <br><br>
      </li>
    </ul>
    <pre>
    @code
    std::stringstream sceneMsgBuf;

    //Create several attributes for the particles and set the value for
    // those attributes in a new created particle.
    circle01.createParticlesAttribute( 11, Emitter::PARTICLE_ATTR_TYPE_VECTOR );
    circle01.createParticlesAttribute( 12, Emitter::PARTICLE_ATTR_TYPE_DOUBLE );
    circle01.createParticlesAttribute( 13, Emitter::PARTICLE_ATTR_TYPE_FLOAT   );
    circle01.createParticlesAttribute( 14, Emitter::PARTICLE_ATTR_TYPE_BOOL   );

    Particle particle = circle01.addParticle( Vector( 0.0f, 0.0f, 0.0f ), Vector( 0.0f, 0.0f, 0.0f ) );
    particle.setAttribute( 11, Vector( 1.0f, 2.0f , 3.0f ) );
    particle.setAttribute( 12, 3.14159 );
    particle.setAttribute( 13, 32432.0f );
    particle.setAttribute( 14, true );
    @endcode
    </pre>
    <p />
    */
    //

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_PB_PARTICLE_H...

