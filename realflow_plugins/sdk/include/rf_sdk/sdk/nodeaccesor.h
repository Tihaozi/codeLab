
#ifndef _NL_RFSDK_NODE_ACCESOR_H
#define _NL_RFSDK_NODE_ACCESOR_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/pb_emitter.h"
#include "rf_sdk/sdk/daemon.h"
#include "rf_sdk/sdk/standardmesh.h"
#include "rf_sdk/sdk/camera.h"
#include "rf_sdk/sdk/constraint.h"
#include "rf_sdk/sdk/object.h"
#include "rf_sdk/sdk/realwave.h"
#include "rf_sdk/sdk/rfnode.h"
#include "rf_sdk/sdk/group.h"
#include "rf_sdk/sdk/mist.h"
#include "rf_sdk/sdk/idoc.h"
#include "rf_sdk/sdk/gridmesh.h"
#include "rf_sdk/sdk/gb_emitter.h"
#include "rf_sdk/sdk/renderkitmesh.h"
#include "rf_sdk/sdk/griddomain.h"
#include "rf_sdk/sdk/multibody.h"
#include "rf_sdk/sdk/multijoint.h"
#include "rf_sdk/sdk/multiservo_poslinear.h"
#include "rf_sdk/sdk/multiservo_posangular.h"
#include "rf_sdk/sdk/multiservo_vellinear.h"
#include "rf_sdk/sdk/multiservo_velangular.h"
#include "rf_sdk/sdk/hy_splash.h"
#include "rf_sdk/sdk/hy_splash_and_foam.h"
#include "rf_sdk/sdk/hy_foam.h"
#include "rf_sdk/sdk/hy_wet.h"
#include "rf_sdk/sdk/hy_wet_and_foam.h"
#include "rf_sdk/sdk/hy_waterline.h"


// FORWARD DECLARATIONS
class Nodo;

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {


  //-----------------------------------------------------------------------------------
  //
  // NodeAccesor:
  //
  //-----------------------------------------------------------------------------------
  class RF_SDK_EXPORTS_DLL_STATIC NodeAccesor
  {

  public:

    ///////////////////////////////////////////////////////////////////////////////////
    //  @
    //! @name Life Cycle:
    //  @{ 
  public :

    /// Constructor
    NodeAccesor( Nodo* node );
    
    NodeAccesor();

    /// Destructor
    ~NodeAccesor() {};

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Operations:
    //  @{ 
  public:

    /// getType:  
    ///
    /// Gets THIS NodeAccesor 's wrapped element type.
    /// 
    /// @return : NodeAccesor 's wrapped element type, values in [ TYPE_NONE  
    ///                                                            TYPE_CAMERA 
    ///                                                            TYPE_DAEMON  
    ///                                                            TYPE_OBJECT   
    ///                                                            TYPE_GROUP
    ///                                                            TYPE_PB_EMITTER
    ///                                                            TYPE_CONSTRAINT
    ///                                                            TYPE_GB_EMITTER
    ///                                                            TYPE_GROUP
    ///                                                            TYPE_MIST
    ///                                                            TYPE_IDOC
    ///                                                            TYPE_GRID_DOMAIN
    ///                                                            TYPE_MULTIBODY
    ///                                                            TYPE_STANDARD_MESH
    ///                                                            TYPE_RENDERKIT_MESH
    ///                                                            TYPE_GRID_MESH  ... ]
    ///                                             
    ///
    //
    NL_UINT64 getType( void ) const;
     
    // asRFEmitter
    PB_Emitter asRFPB_Emitter( void );

    // asRFDaemon
    Daemon asRFDaemon( void );

    // asRFStandardMesh
    ParticleMeshLegacy asRFStandardMesh( void );
    
    // asRFMesh
    ParticleMeshLegacy asRFMesh( void )
    {
      return asRFStandardMesh();
    }
    
    // Camera
    Camera asRFCamera( void );

    // asRFConstraint
    Joint asRFConstraint( void );

    // asRFRealWave
    RealWave asRFRealWave( void );

    // asRFObject
    Object asRFObject( void );
    
    // asRFGB_Emitter
    HY_Emitter asRFGB_Emitter( void );

    // asRFGroup
    Group asRFGroup( void );
    
    // asRFMist
    HY_Mist asRFMist( void );
    
    // asRFIDOC
    IDOC asRFIDOC( void );
    
    // asRFGridMesh
    HY_Mesh asRFGridMesh( void );
    
    // asRFRenderkitMesh
    ParticleMesh asRFRenderkitMesh( void );
    
    // asRFGridDomain
    HY_GridDomain asRFGridDomain( void );
    
    // asRFHY_Splash
    HY_Splash asRFHY_Splash( void );
    
    // asRFHY_Foam
    HY_Foam asRFHY_Foam( void );
    
    // asRFHY_SplashAndFoam
    HY_SplashAndFoam asRFHY_SplashAndFoam( void );
    
    // asRFHY_Wet
    HY_Wet asRFHY_Wet( void );
    
    // asRFHY_WetAndFoam
    HY_WetAndFoam asRFHY_WetAndFoam( void );
    
    // asRFHY_Waterline
    HY_Waterline asRFHY_Waterline( void );
    
    // asRFMultiBody
    MultiBody asRFMultiBody( void );
    
    // asRFMultiBody
    MultiJoint asRFMultiJoint( void );

    // asRFMultiServo_posLinear
    MultiServo_PosLinear asRFMultiServo_posLinear( void );

    // asRFMultiServo_posAngular
    MultiServo_PosAngular asRFMultiServo_posAngular( void );

    // asRFMultiServo_velLinear
    MultiServo_VelLinear asRFMultiServo_velLinear( void );

    // asRFMultiServo_velAngular
    MultiServo_VelAngular asRFMultiServo_velAngular( void );

    // isEmpty
    bool isNull( void );

    // name of the node
    std::string getName() const;

    // clone node
    NodeAccesor clone();

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    //! @name Helper methods
    //  @{ 
  protected:

    // cast
    template< class SDK_NODE_CLASS, class RF_NODE_CLASS >
    SDK_NODE_CLASS castTo( void );

    //
    Nodo* getInternalNodo() const;

    ///////////////////////////////////////////////////////////////////////////////////
    //  @}
    // !@name Data Members:
    //  @{
  private:

    Nodo* node_;
    NL_UINT64 sdkNodeType_;

    friend class Camera;
    friend class Scene;
    
    friend class RFSdkBasicLib;

  };

  };


} // NameSpace NextLimit...
#endif // _NL_RFSDK_NODE_ACCESOR_H...





