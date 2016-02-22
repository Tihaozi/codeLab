
#ifndef _RF_HY_PARTICLE_H
#define _RF_HY_PARTICLE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <vector>
#include <rf_common/core/rf_basicdefs.h>

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfbaseobj.h"
#include "rf_sdk/sdk/vector.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"
//#include "rf_sdk/util/nodeaccesor.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {
    // FORWARD DECLARATIONS
    class Hy_ParticleImp;
    class HY_GridDomain;
    class HY_Emitter;

    //-----------------------------------------------------------------------------------
    //
    // rf_sdk::HY_Particle:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL HY_Particle
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Typedef:
      //  @{ 
#if defined ( _MSC_VER )
      typedef unsigned __int64 uint64;
#else
      typedef unsigned long long uint64;
#endif

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      HY_Particle();

      /// Copy constructor
      HY_Particle( const HY_Particle& rhs );

      /// Destructor
      ~HY_Particle( void );

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
      uint64 getId() const;

      /// getPosition:  
      ///
      /// Gets the particle's position
      ///
      /// @return : particle's position
      const Vector& getPosition( void ) const;

      /// getVelocity:  
      ///
      /// Gets the particle's velocity
      ///
      /// @return : particle's velocity
      const Vector& getVelocity( void ) const;

      /// setChannelValue:  
      ///
      /// Sets a value for a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [double] value / Channel's new value.
      ///
      /// @return : true if the channel was changed, false otherwise. 
      bool setChannelValue( const int channelId, const double& value );

      /// setChannelValue:  
      ///
      /// Sets a value for a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [float] value / Channel's new value.
      ///
      /// @return : true if the channel was changed, false otherwise. 
      bool setChannelValue( const int channelId, const float& value );

      /// setChannelValue:  
      ///
      /// Sets a value for a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [bool] value / Channel's new value.
      ///
      /// @return : true if the channel was changed, false otherwise. 
      bool setChannelValue( const int channelId, const bool& value );

      /// setChannelValue:  
      ///
      /// Sets a value for a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [int] value / Channel's new value.
      ///
      /// @return : true if the channel was changed, false otherwise. 
      bool setChannelValue( const int channelId, const int& value );

      /// setChannelValue:  
      ///
      /// Sets a value for a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [Vector] value / Channel's new value.
      ///
      /// @return : true if the channel was changed, false otherwise. 
      bool setChannelValue( const int channelId, const Vector& value );

      /// getChannelValue:  
      ///
      /// Gets a value of a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [double] value / Channel's value.
      ///
      /// @return : true if the channel was found, false otherwise. 
      bool getChannelValue( const int channelId, double& value ) const;

      /// getChannelValue:  
      ///
      /// Gets a value of a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [float] value / Channel's value.
      ///
      /// @return : true if the channel was found, false otherwise. 
      bool getChannelValue( const int channelId, float& value ) const;

      /// getChannelValue:  
      ///
      /// Gets a value of a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [bool] value / Channel's value.
      ///
      /// @return : true if the channel was found, false otherwise. 
      bool getChannelValue( const int channelId, bool& value ) const;

      /// getChannelValue:  
      ///
      /// Gets a value of a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [ unsigned short] value / Channel's value.
      ///
      /// @return : true if the channel was found, false otherwise. 
      bool getChannelValue( const int channelId, unsigned short& value ) const;

      /// getChannelValue:  
      ///
      /// Gets a value of a channel. 
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [int] value / Channel's value.
      ///
      /// @return : true if the channel was found, false otherwise. 
      bool getChannelValue( const int channelId, int& value ) const;

      /// getChannelValue:  
      ///
      /// Gets a value of a channel.
      /// 
      /// @param [int] channelId / Channel's identification.
      /// @param [Vector] value / Channel's value.
      ///
      /// @return : true if the channel was found, false otherwise. 
      bool getChannelValue( const int channelId, Vector& value ) const;

      /// queryChannel:  
      ///
      /// Returns true if the channel exists, false otherwise. 
      /// 
      /// @param [int] channelId / Channel's identification.
      ///
      /// @return : true if the channel exists, false otherwise.
      bool queryChannel( const int channelId ) const;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:

      /// Implementation
      Hy_ParticleImp* impl_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:
  
      friend class HY_GridDomain;
      friend class HY_Emitter;
      friend class HY_Foam;
      friend class HY_Bubbles;
      friend class HY_BubblesAndFoam;
      friend class HY_SplashAndFoam;
      friend class HY_Splash;
      friend class HY_Waterline;
      friend class HY_WetAndFoam;
      friend class HY_Wet;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_HY_PARTICLE_H...

