#ifndef _NL_SDK_VERTEX_H
#define _NL_SDK_VERTEX_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <rf_common/core/rf_basicdefs.h>

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/vector.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"

// FORWARD DECLARATION

namespace nextlimit
{
  template< class T >
  class Vector3;

  namespace realflow
  {
    class Vertex;
  }

  namespace rf_sdk
  {
    class PB_Emitter;
    class Object;
    class RealWave;
  }

  namespace rw
  {
    class VertexRw;
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
    // Vertex:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Vertex
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      Vertex
        (
        const Vector& position,
        const Vector& velocity,
        const Vector& normal,
        const Vector& uvw
        ) : position_ ( position ),
        velocity_ ( velocity ),
        normal_   ( normal   ),
        uvw_      ( uvw      ),
        index_    ( -1       ) {};

      /// Constructor
      Vertex
        (
          const nl::Vector3<NL_FLOAT>& locAxsPosition,
          const nl::Vector3<NL_FLOAT>& locAxsVelocity,
          const nl::Vector3<NL_FLOAT>& locAxsNormal
        );

      /// Constructor
      Vertex
        (
        const Vector& position,
        const Vector& velocity,
        const Vector& uvw
        ) : position_ ( position ),
            velocity_ ( velocity ),
            normal_   ( 0.0f, 0.0f, 0.0f    ),
            uvw_      ( uvw      ),
            index_    ( -1       ) {};

      /// Constructor
      Vertex
        (
        const Vector& position
        ) : position_   ( position         ),
        velocity_   ( 0.0f, 0.0f, 0.0f ),
        normal_     ( 0.0f, 0.0f, 0.0f ),
        uvw_        ( 0.0f, 0.0f, 0.0f ),
        index_      ( -1               )  {};

      /// Constructor
      Vertex ( const nl::rf::Vertex& rf_Vertex, int ref = REF_GLOBAL ); 

      /// Constructor
      Vertex ( const nl::rw::VertexRw& rf_pntGeom, int idx ); 
       

      /// Destructor
      virtual ~Vertex( void ) {};

    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE
      /// get
      Vector getPosition()           const  { return position_; } 
      Vector getVelocity()           const  { return velocity_; } 
      Vector getNormal()             const  { return normal_;   } 

      /// getTextureCoordinates:  
      ///
      /// Get the vertex's texture coordinates. Please notice that these texture 
      /// coordinates ARE NOT the texture coordinates of the RealFlow object, 
      /// they are just the texture coordinates you have assigned using the 
      /// setTextureCoordinates function.     
      ///
      /// @return : Texture coordinates
      Vector getTextureCoordinates() const  { return uvw_;      }  

      /// set
      void setPosition            ( const Vector& vec ) { position_ = vec;  } 
      void setVelocity            ( const Vector& vec ) { velocity_ = vec;  } 
      void setNormal              ( const Vector& vec ) { normal_ =  vec;   }  
      void setTextureCoordinates  ( const Vector& vec ) { uvw_ =  vec;      }  

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @private Methods:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      Vector  position_;
      Vector  velocity_;
      Vector  normal_;
      Vector  uvw_;
      NL_INT  index_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class PB_Emitter;
      friend class Object;
      friend class RealWave;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_VERTEX_H...


