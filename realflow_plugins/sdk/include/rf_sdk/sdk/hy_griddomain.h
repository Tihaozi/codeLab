
#ifndef _NL_SDK_RF_HY_GRID_DOMAIN_H
#define _NL_SDK_RF_HY_GRID_DOMAIN_H

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
    class FS_GridFluidDomain3;
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
    class HY_Particle;

    //-----------------------------------------------------------------------------------
    //
    // HY_GridDomain:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC HY_GridDomain 
      : public RFNodeType< nl::rf::FS_GridFluidDomain3, nl::rf_sdk::Node_ExpRsc >
    {

    public:

      static const int EXPORT_GRID_DOMAIN_GFC;
      static const int EXPORT_GRID_DOMAIN_RPC;
      static const int EXPORT_GRID_DOMAIN_F3D;
      static const int EXPORT_GRID_DOMAIN_VDB;
      static const int EXPORT_GRID_DOMAIN_PROXY;
      static const int EXPORT_GRID_DOMAIN_BIN;
      static const int EXPORT_GRID_DOMAIN_PRT;
      static const int EXPORT_GRID_DOMAIN_ABC;
      static const int EXPORT_GRID_DOMAIN_DISPLACEMENT;
      static const int EXPORT_GRID_DOMAIN_VELOCITY_IMAGE;
      static const int EXPORT_GRID_DOMAIN_VORTICITY_IMAGE;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      HY_GridDomain( nl::rf::FS_GridFluidDomain3* nativeObjPtr ) 
        : RFNodeType< nl::rf::FS_GridFluidDomain3, 
                      nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~HY_GridDomain( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// sdkExport:  
      ///
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// getParticles:
      ///
      /// Get the grid domain's list of particles.
      ///
      /// @param [out] outParticles / Particles.
      void getParticles( std::vector< nl::rf_sdk::HY_Particle >& particles ) const;

      /// getDetailParticles:
      ///
      /// Get the grid domain's list of detail particles. Detail particles indicate 
      /// areas of the fluid where more resolution is needed. Normally those areas 
      /// are detected by checking the properties of the fluid like curvature, speed 
      /// and vorticity. 
      ///
      /// @param [in] curvatureThreshold /  only those particles that are in curvature 
      ///                                   areas that are above the value of this 
      ///                                   parameter are considered. 
      /// @param [in] speedThreshold /  only those particles where the speed is 
      ///                               above this parameter are considered
      /// @param [in] vorticityThreshold /  only those particles where the 
      ///                                   vorticity is above this parameter are considered
      void getDetailParticles(  const float& curvatureThreshold,
                                const float& speedThreshold,
                                const float& vorticityThreshold,
                                      std::vector< HY_Particle >& particles );

      /// getSurfaceParticles:
      ///
      /// Get the grid domain's list of particles that are located at the fluid surface 
      /// within a bandwidth. 
      ///
      /// @param [in] bandwidth /  Surface bandwidth in meters.
      ///
      void getSurfaceParticles( const float& bandwidth,
                                      std::vector< HY_Particle >& particles );

      /// getCoreParticles:
      ///
      /// Get the grid domain's list of particles that are located at the fluid core. 
      /// Particles at the surface within a bandwidth are discarded, the rest are 
      /// considered to be in the core of the fluid.
      ///
      /// @param [in] bandwidth /Surface bandwidth in meters.
      ///
      void getCoreParticles(  const float& bandwidth,
                                    std::vector< HY_Particle >& particles );

      /// getObjectParticles:
      ///
      /// Get the grid domain's list of particles that are in contact with objects. 
      /// Please notice that the grid domain boundary is considered an object so particles in contact with the grid domain boundary are considered as well. 
      ///
      void getObjectParticles( std::vector< HY_Particle >& particles );

      /// getParticle:
      ///
      /// Get the particle with specific ID.
      ///
      /// @param [in] id / Particle's ID.
      /// @param [out] particle / Particle.
      /// @return true if particle was found, false otherwise.
      bool getParticle( const unsigned int& id, nl::rf_sdk::HY_Particle& particle ) const;

      /// getType:  
      ///
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_GRID_DOMAIN; };
      
      /// addForce:
      ///
      /// Add an external force to the whole domain.
      /// @param [Vector] force / Force.
      void addToUserForceFieldConstant( const Vector& force );

      /// addForce:
      ///
      /// Add an external force at specific position.
      /// @param [Vector] force / Force.
      /// @param [Vector] position / Global position where the force is applied.
      void addToUserForceField( const Vector& force, const Vector& position );

      /// getCellLength:
      ///
      /// Get the length of the grid cell.
      ///
      /// @return : Length of the grid cell.
      float getCellLength( void ) const;

      /// getGridPoints:
      /// Gets the list of the grid points positions in world space.
      //void getGridPoints( ArrSdkVectors& points ) const;

      /// getNumberOfParticles:
      ///
      /// Get the number of particles in this domain
      ///
      /// @ return: number of particles
      unsigned int getNumberOfParticles( void ) const;

      /// initialize:
      ///
      /// Initialize the fluid with a list of positions, velocities and uvs.
      /// @param [ArrSdkVector] positions / List of positions.
      /// @param [ArrSdkVector] velocities / List of velocities.
      /// @param [ArrSdkVector] uvs / List of uvs.
      void initialize(  const ArrSdkVectors& positions,
                        const ArrSdkVectors& velocities,
                        const ArrSdkVectors& uvs );

      /// removeAllParticles:
      ///
      /// Initialize the fluid removing all the particles
      void removeAllParticles( void );

      /// getChannelId:
      ///
      /// Get the channel identification. 
      /// @param [std::string] channelName / Channel's name.
      ///
      /// @ return: the channel's id
      int getChannelId( const std::string& channelName );
      
      /// addParticle:
      ///
      /// Add a new particle.
      ///
      /// @param [in] position / New particle position.
      /// @param [in] velocity / New particle velocity.
      /// @param [out] particle / New particle.
      ///
      void addParticle( const Vector& position,
                        const Vector& velocity,
                        nl::rf_sdk::HY_Particle& particle );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) 
      { 
        return sdk_type::GRID_DOMAIN_TYPE; 
      };

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
#endif // _NL_SDK_RF_HY_GRID_DOMAIN_H...





