
#ifndef _NL_SDK_RF_HY_WET_AND_FOAM_H
#define _NL_SDK_RF_HY_WET_AND_FOAM_H

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
  namespace realflow
  {
    class FS_GridFluidWetAndFoam3;
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
    // HY_WetAndFoam:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC HY_WetAndFoam 
      : public RFNodeType< nl::rf::FS_GridFluidWetAndFoam3, nl::rf_sdk::Node_ExpRsc >
    {

    public:

      static const int EXPORT_PARTICLES_RPC;
      static const int EXPORT_PARTICLES_BIN;
      static const int EXPORT_PARTICLES_ASC;
      static const int EXPORT_PARTICLES_PDC;
      static const int EXPORT_PARTICLES_PD;
      static const int EXPORT_PARTICLES_PRT;
      static const int EXPORT_PARTICLES_ABC;
      static const int EXPORT_PARTICLES_PROXY;
    
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      HY_WetAndFoam( nl::rf::FS_GridFluidWetAndFoam3* nativeObjPtr ) 
        : RFNodeType< nl::rf::FS_GridFluidWetAndFoam3, 
                      nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~HY_WetAndFoam( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE


      /// getParticles:  
      ///
      /// Get the list of particles.
      ///
      /// @param [out] Particles / List of particles
      void getParticles( std::vector< HY_Particle >& particles ) const;

      /// getParticle:  
      ///
      /// Get the particle with specific ID.
      ///
      /// @param [in] id / Particle's ID
      /// @param [out] particle / Particle
      /// @return : true if particle was found, false otherwise.
      bool getParticle( const unsigned int& id, HY_Particle& sdkParticle ) const;

      /// sdkExport:  
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_HY_WET_AND_FOAM; };

      /// GetNumberOfParticles
      /// 
      /// Get the number of particles of this emitter (including all domains)
      ///
      /// @return the number of particles
      unsigned int getNumberOfParticles () const;

      /// getChannelId:
      ///
      /// Get the channel identification. 
      /// @param [std::string] channelName / Channel's name.
      ///
      /// @ return: the channel's id
      int getChannelId( const std::string& channelName );
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::HY_WET_AND_FOAM_TYPE; };

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
#endif // _NL_SDK_RF_HY_WET_AND_FOAM_H...





