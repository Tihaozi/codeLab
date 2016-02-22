/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2008 Next Limit Technologies. All rights reserved.
//
// This file is just part of the C++ SDK examples provided with RealFlow(c).
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <rf_sdk/sdk/appmanager.h>
#include <rf_sdk/sdk/scene.h>
#include <rf_sdk/sdk/vector.h>
#include <rf_sdk/sdk/daemon.h>
#include <rf_sdk/sdk/pb_particle.h>
#include <rf_sdk/sdk/pb_emitter.h>
#include <rf_sdk/sdk/object.h>
#include <rf_sdk/sdk/ppty.h>
#include <rf_sdk/sdk/plgdescriptor.h>
#include <rf_sdk/particles/particlesolverplgsdk.h>
#include <rf_sdk/sdk/rfsdklibdefs.h>
#include <rf_sdk/sdk/sdkversion.h>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace nextlimit::rf_sdk;

/////////////////////////////////////////////////////////////////////////////////////////

class SurfaceTensionSDK : public ParticleSolverPlgSdk
{
  public:

    /// Constructor.
    SurfaceTensionSDK() {};

    /// Destructor.
    virtual ~SurfaceTensionSDK( void ) {};

    /// Class id.
    virtual NL_INT32  getClassId() const  
    { 
      return ( 1580460102 );
    };

    /// Get plugin name.
    virtual std::string getNameId() const 
    { 
      return ( "SurfaceTension 1.0" ); 
    };

    // getCopyRight()
    virtual std::string getCopyRight() const
    {
      return std::string( "Copyright (C) 2008 Next Limit Technologies. All rights reserved." );
    }

    // getCopyRight()
    virtual std::string getLongDescription() const
    {
      return std::string( "Solver with surface tension." );
    }

    // getCopyRight()
    virtual std::string getShortDescription() const
    {
      return std::string( "Solver with surface tension." );
    }


    /// Initialize plugin, add properties, etc.
    virtual void initialize( PlgDescriptor* plgDesc )
    {
      Ppty factor = Ppty::createPpty( "Factor", 1.5f );  
      plgDesc->addPpty( factor );
    }

    /// Integration
    virtual void integrate( ParticleSolver* particleSolver,
                            PB_Emitter* emitter, 
                            int nThread, 
                            PB_Emitter::iterator iter,
                            float dt )
    {
      //particleSolver->integrate( nThread, dt );

      Scene& scene =  AppManager::instance()->getCurrentScene();

      while ( iter.hasNext() ) 
      {
        PB_Particle particle = iter.next();
        const Vector& velocity = particle.getVelocity();
        const Vector& position = particle.getPosition();
        const Vector& force = particle.getInternalForce();

        if ( particle.isColliding() )
        {
          // If particle is colliding the velocity to integrate position is the one
          // imposed by the collision and not the one integrated using the force.
          particle.setPosition( position + velocity * dt );
          const Vector newVelocity = velocity + force * dt;
          particle.setVelocity( newVelocity  );          
        }
        else
        {
          const Vector newVelocity = velocity + force * dt;
          particle.setVelocity( newVelocity  );
          particle.setPosition( position + newVelocity * dt );
        }
      }
    }

    // get integration time
    virtual float getIntegrationTime( ParticleSolver* particleSolver ) const
    {
      return ( 0.02f );
    }

    virtual void preComputeInternalForces( ParticleSolver* particleSolver,
                                           PB_Emitter* emitter )
    {
      emitter->createVoxelization( true, 0.15f );
    }

    /// Compute internal forces.
    virtual void computeInternalForces( ParticleSolver* particleSolver,
                                        PB_Emitter* emitter, 
                                        int nThread, 
                                        PB_Emitter::iterator iter )
    {
      const float factor = particleSolver->getParameter<float>( "Factor" );
      Vector center( 0.0f, 0.0f, 0.0f );
      Vector force( 0.0f, 0.0f, 0.0f );      
      while ( iter.hasNext() )
      {
        PB_Particle particle = iter.next();
        std::vector< PB_Particle > neighbors;
        particle.getNeighbors( neighbors, 0.15f );
        if ( neighbors.size() > 0 )
        {        
          center.set( 0.0f, 0.0f, 0.0f );
          const size_t numberOfNeighbors = neighbors.size();
          for( int i = 0; i < numberOfNeighbors; ++i )
          {
            PB_Particle& neighbor =  neighbors[i];
            center = center + neighbor.getPosition();
          }

          center.setX( center.getX() * ( 1.0f / numberOfNeighbors ) );
		      center.setY( center.getY() * ( 1.0f / numberOfNeighbors ) );
		      center.setZ( center.getZ() * ( 1.0f / numberOfNeighbors ) );
			    Vector position( particle.getPosition() );
          Vector force( ( center.getX() - position.getX() ) * factor,
			                    ( center.getY() - position.getY() ) * factor,
			                    ( center.getZ() - position.getZ() ) * factor );
          particle.setInternalForce( force );
        }            
      }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_PARTICLE_SOLVER_PLUGIN( SurfaceTensionSDK );

/////////////////////////////////////////////////////////////////////////////////////////

