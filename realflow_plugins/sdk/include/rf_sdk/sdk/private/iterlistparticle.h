
#ifndef _RF_ITER_LIST_PARTICLE_H
#define _RF_ITER_LIST_PARTICLE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/pb_particle.h"

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

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{
  namespace rf_sdk
  {
    //-----------------------------------------------------------------------------------
    //
    // IterListParticle:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL IterListParticle
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      // Iterator for all the particles in the list up to the lastParticle
      // if lastParticle.isNull() then the iterator is for all particles.
      IterListParticle( rf_sdk::PB_Particle* firstParticle, rf_sdk::PB_Particle* lastParticle );

      // Iterator for all particles on the Emitter
      IterListParticle( rf_sdk::PB_Particle* firstParticle );

      /// Destructor
      virtual ~IterListParticle( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // hasNext
      bool hasNext( void );

      // next
      rf_sdk::PB_Particle next( void );


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:
      rf::Particle* currNatPartPtr_;

    };

  } // NameSpace rf_sdk...
} // NameSpace Nextlimit...
#endif // _RF_ITER_LIST_PARTICLE_H...





