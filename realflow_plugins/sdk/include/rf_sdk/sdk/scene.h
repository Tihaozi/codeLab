
#ifndef _RF_SCENE_H
#define _RF_SCENE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
//#include <utils/nl_optional.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES
#include <rf_common/core/nl_reftype.h>

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/appmanager.h"
#include "rf_sdk/sdk/object.h"
#include "rf_sdk/sdk/pb_emitter.h"
#include "rf_sdk/sdk/camera.h"
#include "rf_sdk/sdk/daemon.h"
#include "rf_sdk/sdk/group.h"
#include "rf_sdk/sdk/constraint.h"
#include "rf_sdk/sdk/sphere.h"
#include "rf_sdk/sdk/cube.h"
#include "rf_sdk/sdk/cube_top_open.h"
#include "rf_sdk/sdk/particlemeshlegacy.h"
#include "rf_sdk/sdk/particlemesh.h"
#include "rf_sdk/sdk/particlemesh_vdb.h"
#include "rf_sdk/sdk/gridmesh.h"
#include "rf_sdk/sdk/cross.h"
#include "rf_sdk/sdk/hemisphere.h"
#include "rf_sdk/sdk/plane.h"
#include "rf_sdk/sdk/rocket.h"
#include "rf_sdk/sdk/cylinder.h"
#include "rf_sdk/sdk/vase.h"
#include "rf_sdk/sdk/capsule.h"
#include "rf_sdk/sdk/cone.h"
#include "rf_sdk/sdk/torus.h"
#include "rf_sdk/sdk/realwave.h"
#include "rf_sdk/sdk/mist.h"
#include "rf_sdk/sdk/idoc.h"
#include "rf_sdk/sdk/spline.h"
#include "rf_sdk/sdk/griddomain.h"
#include "rf_sdk/sdk/multibody.h"
#include "rf_sdk/sdk/multijoint.h"
#include "rf_sdk/sdk/multiservo_poslinear.h"
#include "rf_sdk/sdk/multiservo_posangular.h"
#include "rf_sdk/sdk/multiservo_vellinear.h"
#include "rf_sdk/sdk/multiservo_velangular.h"
#include "rf_sdk/sdk/layer.h"
#include "rf_sdk/sdk/rf_null_excpt.h"
#include "rf_sdk/sdk/rf_wrongargs_excpt.h"
#include "rf_sdk/util/sdkexcptmessg.h"
#include "rf_sdk/sdk/hy_emitter.h"
#include "rf_sdk/sdk/hy_griddomain.h"
#include "rf_sdk/sdk/hy_mesh.h"
#include "rf_sdk/sdk/hy_mesh_vdb.h"
#include "rf_sdk/sdk/hy_mist.h"
#include "rf_sdk/sdk/hy_splash.h"
#include "rf_sdk/sdk/hy_splash_and_foam.h"
#include "rf_sdk/sdk/hy_foam.h"
#include "rf_sdk/sdk/hy_bubbles.h"
#include "rf_sdk/sdk/hy_bubbles_and_foam.h"
#include "rf_sdk/sdk/hy_waterline.h"
#include "rf_sdk/sdk/hy_wet_and_foam.h"
#include "rf_sdk/sdk/hy_wet.h"
#include "rf_sdk/sdk/image.h"

// FORWARD DECLARATIONS
namespace nextlimit
{
  class MutexRW;
}


// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // Simulation step returned type.
    enum SimulStatus
    {
      SIM_STATUS_FRAME_IS_UP,
      SIM_STATUS_FINISHED,  
      SIM_STATUS_NORMAL
    };


    //-----------------------------------------------------------------------------------
    //
    // Scene:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Scene
    {

      DECLARE_STD_MAP_TYPES( std::string, nl::NL_RefTypeBase*, GlobalVars )

      // Resource ids.
      static const int EXPORT_SCENE_ANIMATION_SD;
      static const int EXPORT_SCENE_CACHE_BDC;
      static const int EXPORT_PREVIEW;
      static const int EXPORT_VIDEO_PREVIEW;
      static const int EXPORT_VIDEO_PREVIEW_FRAMES;
      static const int EXPORT_CHANNELS;
      static const int EXPORT_LOG;
      static const int EXPORT_JOBFILES;
      static const int EXPORT_MAXWELL_SCENE;
      static const int EXPORT_ARNOLD_SCENE;
      
      // Image formats.
      static const int IMAGE_FORMAT_TGA;
      static const int IMAGE_FORMAT_BMP;
      static const int IMAGE_FORMAT_PNG;
      static const int IMAGE_FORMAT_JPG;
      
      // Interpolation methods.
      static const int INTERPOLATION_METHOD_NONE;
      static const int INTERPOLATION_METHOD_LINEAR;
      static const int INTERPOLATION_METHOD_CUBIC;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Scene( void );
      
      NL_DISABLE_COPY( Scene )

    public:
      /// Destructor
      ~Scene( void );


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// add_PB_Emitter:
      ///
      /// Creates a new particle-based emitter and adds it to the current Scene
      ///
      /// @param [in] type / Emitter 's type
      ///
      /// @return a new emitter
      //
      PB_Emitter add_PB_Emitter( const std::string& type );

      /// add_GB_Emitter:
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "add_HY_Emitter" instead.
      ///
      /// Creates a new grid-based emitter and adds it to the current Scene
      ///
      /// @param [in] type / Emitter 's type
      ///
      /// @return a new emitter
      //
      GB_Emitter add_GB_Emitter( void );

      /// add_HY_Emitter:
      ///
      /// Creates a new grid-based emitter and adds it to the current Scene
      ///
      /// @param [in] type / Emitter 's type
      ///
      /// @return a new emitter
      //
      HY_Emitter add_HY_Emitter( void );

      /// removeEmitter:  
      ///
      /// Deletes an Emitter from the current Scene
      ///
      /// @param [in] name / Emitter 's name
      //
      void removeEmitter( const std::string& name );

      /// addCamera:  
      ///
      /// Creates a new Camera and adds it to the current Scene
      ///
      /// @return a new Camera
      //
      Camera addCamera( void );

      /// removeCamera:  
      ///
      /// Deletes an Camera from the current Scene
      ///
      /// @param [in] name / Camera 's name
      //
      void removeCamera( const std::string& name );

      /// addDaemon:  
      ///
      /// Creates a new Daemon and adds it to the current Scene
      ///
      /// @param [in] type / Daemon 's type
      ///
      /// @return a new Daemon
      //
      Daemon addDaemon( const std::string& subType );

      /// removeDaemon:  
      ///
      /// Deletes a Daemon from the current Scene
      ///
      /// @param [in] name / Daemon 's name
      //
      void removeDaemon( const std::string& name );

      /// removeRealWave:  
      ///
      /// Deletes a RealWave from the current Scene
      ///
      /// @param [in] name / RealWave 's name
      //
      void removeRealWave( const std::string& name );

      /// addConstraint:  
      ///
      /// Creates a new Joint and adds it to the current Scene
      ///
      /// @param [in] type / Joint 's type
      ///
      /// @return a new Joint
      //
      Joint addConstraint( const std::string& subType );

      /// removeConstraint:  
      ///
      /// Deletes a Joint from the current Scene
      ///
      /// @param [in] name / Joint 's name
      //
      void removeConstraint( const std::string& name );

      /// addMesh:  
      ///
      /// Creates a new Mesh and adds it to the current Scene
      ///
      /// @return a new Mesh
      //
      StandardMesh addMesh( void );

      /// removeMesh:  
      ///
      /// Deletes a Mesh from the current Scene
      ///
      /// @param [in] name / Mesh 's name
      //
      void removeMesh( const std::string& name );

      /// addGridMesh:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "add_HY_Mesh" instead.
      ///
      /// Creates a new hybrido mesh and adds it to the current Scene
      ///
      /// @return a new hybrido mesh
      //
      GridMesh addGridMesh( void );

      /// add_HY_Mesh:  
      ///
      /// Creates a new hybrido mesh and adds it to the current Scene
      ///
      /// @return a new hybrido mesh
      //
      HY_Mesh add_HY_Mesh( void );

      /// add_HY_Mesh_VDB:  
      ///
      /// Creates a new hybrido mesh vdb and adds it to the current Scene
      ///
      /// @return a new hybrido mesh vdb
      //
      HY_Mesh_VDB add_HY_Mesh_VDB( void );

      /// remove_HY_Mesh:  
      ///
      /// Deletes a hybrido mesh from the current Scene
      ///
      /// @param [in] name / Hybrido mesh's name
      //
      void remove_HY_Mesh( const std::string& name );

      /// remove_HY_Mesh_VDB:  
      ///
      /// Deletes a hybrido mesh vdb from the current Scene
      ///
      /// @param [in] name / Hybrido mesh's name
      //
      void remove_HY_Mesh_VDB( const std::string& name );

      /// removeGridMesh:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "remove_HY_Mesh" instead.
      ///
      /// Deletes a hybrido mesh from the current Scene
      ///
      /// @param [in] name / Hybrido mesh's name
      //
      void removeGridMesh( const std::string& name );

      /// addRenderkitMesh:  
      ///
      ///  This function has been deprecated and will be removed in future 
      /// versions of RF, use "addParticleMesh" instead.
      ///
      /// Creates a new renderkit mesh and adds it to the current Scene
      ///
      /// @return a new renderkit mesh
      //
      RenderkitMesh addRenderkitMesh( void );

      /// addParticleMesh:  
      ///
      /// Creates a new renderkit mesh and adds it to the current Scene
      ///
      /// @return a new renderkit mesh
      //
      ParticleMesh addParticleMesh( void );

      /// addParticleMesh_VDB:  
      ///
      /// Creates a new VDB mesh and adds it to the current Scene
      ///
      /// @return a new VDB mesh
      //
      ParticleMesh_VDB addParticleMesh_VDB( void );

      /// removeRenderkitMesh:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "removeParticleMesh" instead.
      ///
      /// Deletes a renderkit mesh from the current Scene
      ///
      /// @param [in] name / Renderkit mesh's name
      //
      void removeRenderkitMesh( const std::string& name );

      /// removeParticleMesh:  
      ///
      /// Deletes a renderkit mesh from the current Scene
      ///
      /// @param [in] name / Renderkit mesh's name
      //
      void removeParticleMesh( const std::string& name );

      /// removeParticleMesh_VDB:  
      ///
      /// Deletes a VDB mesh from the current Scene
      ///
      /// @param [in] name / VDB mesh's name
      //
      void removeParticleMesh_VDB( const std::string& name );

      /// addMist:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "add_HY_Mist" instead.
      ///
      /// Creates a new Mist and adds it to the current Scene
      ///
      /// @return a new Mesh
      //
      Mist addMist( void );

      /// add_HY_Mist:  
      ///
      /// Creates a new Mist and adds it to the current Scene
      ///
      /// @return a new Mesh
      //
      HY_Mist add_HY_Mist( void );

      /// removeMist:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "remove_HY_Mist" instead.
      ///
      /// Deletes a mist from the current Scene
      ///
      /// @param [in] name / Mist's name
      //
      void removeMist( const std::string& name );

      /// remove_HY_Mist:  
      ///
      /// Deletes a mist from the current Scene
      ///
      /// @param [in] name / Mist's name
      //
      void remove_HY_Mist( const std::string& name );

      /// addGridDomain:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "add_HY_GridDomain" instead.
      ///
      /// Creates a new grid domain and adds it to the current Scene
      ///
      /// @return a new grid domain
      //
      GridDomain addGridDomain( void );

      /// add_HY_GridDomain:  
      ///
      /// Creates a new grid domain and adds it to the current Scene
      ///
      /// @return a new grid domain
      //
      HY_GridDomain add_HY_GridDomain( void );

      /// removeGridDomain:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "remove_HY_GridDomain" instead.
      ///
      /// Deletes a grid domain from the current Scene
      ///
      /// @param [in] name / Grid domain's name
      //
      void removeGridDomain( const std::string& name );

      /// removeGridDomain:  
      ///
      /// Deletes a grid domain from the current Scene
      ///
      /// @param [in] name / Grid domain's name
      //
      void remove_HY_GridDomain( const std::string& name );

      /// addIDOC:  
      ///
      /// Creates a new IDOC and adds it to the current Scene
      ///
      /// @return a new IDOC
      //
      IDOC addIDOC( void );

      /// addMultiBody:  
      ///
      /// Creates a new MultiBody and adds it to the current Scene
      ///
      /// @return a new MultiBody
      //
      MultiBody addMultiBody( const std::string& filePath );

      /// addMultiJoint:  
      ///
      /// Creates a new MultiJoint and adds it to the current Scene
      ///
      /// @return a new MultiJoint
      //
      MultiJoint addMultiJoint  ( const std::string& filePath );

      /// addSpline:  
      ///
      /// Creates a new spline and adds it to the current Scene
      ///
      /// @return a new Spline
      //
      Spline addSpline ( void );

      /// addMultiServo_PosLinear:  
      ///
      /// Creates a new MultiServo_Position_Linear and adds it to the current Scene
      ///
      /// @return a new MultiServo_Position_Linear
      //
      MultiServo_PosLinear addMultiServo_PosLinear  ( const std::string& filePath );

      /// addMultiServo_PosAngular:  
      ///
      /// Creates a new MultiServo_Position_Angular and adds it to the current Scene
      ///
      /// @return a new MultiServo_Position_Angular
      //
      MultiServo_PosAngular addMultiServo_PosAngular  ( const std::string& filePath );

      /// addMultiServo_VelLinear:  
      ///
      /// Creates a new MultiServo_Velocity_Linear and adds it to the current Scene
      ///
      /// @return a new MultiServo_Velocity_Linear
      //
      MultiServo_VelLinear addMultiServo_VelLinear  ( const std::string& filePath );

      /// addMultiServo_VelAngular:  
      ///
      /// Creates a new MultiServo_Velocity_Angular and adds it to the current Scene
      ///
      /// @return a new MultiServo_Velocity_Angular
      //
      MultiServo_VelAngular addMultiServo_VelAngular  ( const std::string& filePath );

      /// removeIDOC:  
      ///
      /// Deletes a IDOC from the current Scene
      ///
      /// @param [in] name / IDOC's name
      //
      void removeIDOC( const std::string& name );

      /// removeMultiBody:  
      ///
      /// Deletes a MultiBody from the current Scene
      ///
      /// @param [in] name / MultiBody's name
      //
      void removeMultiBody( const std::string& name );

      /// removeMultiJoint:  
      ///
      /// Deletes a MultiJoint from the current Scene
      ///
      /// @param [in] name / MultiJoint's name
      //
      void removeMultiJoint ( const std::string& name );

      /// removeSpline:  
      ///
      /// Deletes a Spline from the current Scene
      ///
      /// @param [in] name / Spline's name
      //
      void removeSpline ( const std::string& name );

      /// removeMultiServo_PosLinear:  
      ///
      /// Deletes a MultiServo_Position_Linear from the current Scene
      ///
      /// @param [in] name / Multiservo's name
      //
      void removeMultiServo_PosLinear ( const std::string& name );

      /// removeMultiServo_PosAngular:  
      ///
      /// Deletes a MultiServo_Position_Angular from the current Scene
      ///
      /// @param [in] name / Multiservo's name
      //
      void removeMultiServo_PosAngular ( const std::string& name );

	    /// removeMultiServo_VelLinear:  
      ///
      /// Deletes a MultiServo_Velocity_Linear from the current Scene
      ///
      /// @param [in] name / Multiservo's name
      //
      void removeMultiServo_VelLinear ( const std::string& name );

	    /// removeMultiServo_VelAngular:  
      ///
      /// Deletes a MultiServo_Velocity_Angular from the current Scene
      ///
      /// @param [in] name / Multiservo's name
      //
      void removeMultiServo_VelAngular ( const std::string& name );

      /// importObjects:  
      ///
      /// Imports Objects from a file and add them to the current Scene
      ///
      /// @param [in] filePath / File 's filePath
      ///
      /// @param [out] sdkObjs / Vector of sdk Objects
      //
      void importObjects(       ArrSdkObjects& sdkObjs, 
                          const std::string& filePath );

      /// removeObject:  
      ///
      /// Deletes an Object from the current Scene
      ///
      /// @param [in] name / Object 's name
      //     
      void removeObject( std::string name );

      /// get_PB_Emitters:  
      ///
      /// Get the list of particle-based emitters. 
      /// 
      /// @param [out] emitters / List of emitters.
      //
      void get_PB_Emitters( std::vector<PB_Emitter>& emitters );

      /// getMultiBodies:  
      ///
      /// Get the list of MultiBodies. 
      /// 
      /// @param [out] MultiBodies / List of MultiBodies.
      //
      void getMultiBodies( std::vector<MultiBody>& bodies );

	    /// getMultiJoints:  
      ///
      /// Get the list of MultiJoint. 
      /// 
      /// @param [out] MultiJoint / List of MultiJoint.
      //
      void getMultiJoints ( std::vector<MultiJoint>& joint);

	    /// getSplines:  
      ///
      /// Get the list of splines. 
      /// 
      /// @param [out] Spline / List of splines.
      //
      void getSplines ( std::vector<Spline>& spline);

	    /// getMultiServos_PosLinear:  
      ///
      /// Get the list of MultiServo_Position_Linear. 
      /// 
      /// @param [out] MultiServo_PosLinear / List of MultiServo_Position_Linear.
      //
      void getMultiServos_PosLinear ( std::vector<MultiServo_PosLinear>& multiservo);

	    /// getMultiServos_PosAngular:  
      ///
      /// Get the list of MultiServo_Position_Angular. 
      /// 
      /// @param [out] MultiServo_PosAngular / List of MultiServo_Position_Angular.
      //
      void getMultiServos_PosAngular ( std::vector<MultiServo_PosAngular>& multiservo);

	    /// getMultiServos_VelLinear:  
      ///
      /// Get the list of MultiServo_Velocity_Linear. 
      /// 
      /// @param [out] MultiServo_VelLinear / List of MultiServo_Velocity_Linear.
      //
      void getMultiServos_VelLinear ( std::vector<MultiServo_VelLinear>& multiservo);

	    /// getMultiServos_VelAngular:  
      ///
      /// Get the list of MultiServo_Velocity_Angular. 
      /// 
      /// @param [out] MultiServo_VelAngular / List of MultiServo_Velocity_Angular.
      //
      void getMultiServos_VelAngular ( std::vector<MultiServo_VelAngular>& multiservo);

      /// get_GB_Emitters:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_Emitters" instead
      ///
      /// Get the list of grid-based emitters. 
      /// 
      /// @param [out] emitters / List of emitters.
      //
      void get_GB_Emitters( std::vector<GB_Emitter>& emitters );

      /// get_HY_Emitters:  
      ///
      /// Get the list of grid-based emitters. 
      /// 
      /// @param [out] emitters / List of emitters.
      //
      void get_HY_Emitters( std::vector<HY_Emitter>& emitters );

      /// getCameras:  
      /// 
      /// Gets all Cameras in the current Scene
      /// 
      /// @param [out] cameras / Vector of Cameras
      //
      void getCameras( std::vector<Camera>& cameras );

      /// getObjects:  
      /// 
      /// Gets all Objects in the current Scene
      /// 
      /// @param [out] objs / Vector of sdk Objects
      //
      void getObjects( std::vector<Object>& objs );

      /// getDaemons:  
      /// 
      /// Gets all Daemons in the current Scene
      /// 
      /// @param [out] daemons / Vector of Daemons
      //
      void getDaemons( std::vector<Daemon>& daemons );

      /// getConstraints:  
      /// 
      /// Gets all Constraints in the current Scene
      /// 
      /// @param [out] constraints / Vector of Constraints
      //
      void getConstraints( std::vector<Joint>& constraints );

      /// getMeshes:  
      ///
      /// Gets all Meshes in the current Scene
      ///
      /// @param [out] meshes / Vector of Meshes
      //
      void getMeshes( ArrSdkNodeAccesors& outSdkNodeAccesors );

      /// getGridMeshes:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_Meshes" instead.
      ///
      /// Gets all hybrido meshes in the current Scene
      ///
      /// @param [out] hybrido meshes / Vector of hybrido meshes
      ///
      void getGridMeshes( std::vector<GridMesh>& meshes );

      /// get_HY_Meshes:  
      ///
      /// Gets all hybrido meshes in the current Scene
      ///
      /// @param [out] hybrido meshes / Vector of hybrido meshes
      ///
      void get_HY_Meshes( std::vector<HY_Mesh>& meshes );

      /// get_HY_Meshes_VDB:  
      ///
      /// Gets all hybrido meshes vdb in the current Scene
      ///
      /// @param [out] hybrido meshes vdb / Vector of hybrido meshes vdb
      ///
      void get_HY_Meshes_VDB( std::vector<HY_Mesh_VDB>& meshes );

      /// getRenderkitMeshes:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "getParticleMeshes" instead.
      ///
      /// Gets all renderkit meshes in the current Scene
      ///
      /// @param [out] renderkit meshes / Vector of renderkit meshes
      //
      void getRenderkitMeshes( std::vector<RenderkitMesh>& meshes );

      /// getParticleMeshes:  
      ///
      /// Gets all renderkit meshes in the current Scene
      ///
      /// @param [out] renderkit meshes / Vector of renderkit meshes
      //
      void getParticleMeshes( std::vector<ParticleMesh>& meshes );

      /// getParticleMeshes_VDB:  
      ///
      /// Gets all VDB meshes in the current Scene
      ///
      /// @param [out] VDB meshes / Vector of VDB meshes
      //
      void getParticleMeshes_VDB( std::vector<ParticleMesh_VDB>& meshes );

      /// getMists:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_Mists" instead.
      ///
      /// Gets all mists in the current Scene
      ///
      /// @param [out] mists / Vector of mists
      //
      void getMists( std::vector<Mist>& mists );

      /// get_HY_Mists:  
      ///
      /// Gets all mists in the current Scene
      ///
      /// @param [out] mists / Vector of mists
      //
      void get_HY_Mists( std::vector<HY_Mist>& mists );

      /// getGridDomains:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_GridDomains" instead.
      ///
      /// Gets all grid domains in the current Scene
      ///
      /// @param [out] grid domains / Vector of grid domains
      //
      void getGridDomains( std::vector<GridDomain>& gridDomains );

      /// get_HY_GridDomains:  
      ///
      /// Gets all grid domains in the current Scene
      ///
      /// @param [out] grid domains / Vector of grid domains
      //
      void get_HY_GridDomains( std::vector<HY_GridDomain>& gridDomains );

      /// getIDOCs:  
      ///
      /// Gets all IDOCs in the current Scene
      ///
      /// @param [out] idocs / Vector of mists
      //
      void getIDOCs( std::vector<IDOC>& idocs );

      /// getGlobalLinks:  
      ///
      /// Gets all global linkss in the current Scene
      ///
      /// @param [out] global links
      //
      void getGlobalLinks( ArrSdkNodeAccesors& outSdkNodeAccesors );

      /// getExclusivelLinks:  
      ///
      /// Gets all exclusive linkss in the current Scene
      ///
      /// @param [out] exclusive links
      //
      void getExclusiveLinks( NodeAccesor& node, ArrSdkNodeAccesors& outSdkNodeAccesors );

      /// getCurrentTime:
      /// 
      /// Gets the Scene 's current time
      /// 
      /// @return Scene 's current time
      //
      float getCurrentTime( void );  

      /// message:
      ///
      /// Writes out a message in the messages window
      //
      void message( const std::string& message );

      /// get_PB_Emitter:  
      /// 
      /// Get the particle-based emitter by name.
      /// 
      /// @param [in] name / Emitter 's name
      ///
      /// @return :
      ///           Emitter if found
      ///           Emitter( Null ) if there is no Emitter with such name
      //
      PB_Emitter get_PB_Emitter( const std::string& name );

      /// get_GB_Emitter:  
      /// 
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_Emitter" instead.
      ///
      /// Get the grid-based emitter by name.
      /// 
      /// @param [in] name / Emitter 's name
      ///
      /// @return :
      ///           Emitter if found
      ///           Emitter( Null ) if there is no Emitter with such name
      //
      GB_Emitter get_GB_Emitter( const std::string& name );

      /// get_HY_Emitter:  
      /// 
      /// Get the grid-based emitter by name.
      /// 
      /// @param [in] name / Emitter 's name
      ///
      /// @return :
      ///           Emitter if found
      ///           Emitter( Null ) if there is no Emitter with such name
      //
      HY_Emitter get_HY_Emitter( const std::string& name );

      /// getMultiBody:  
      /// 
      /// Get the MultiBody by name.
      /// 
      /// @param [in] name / MultiBody's name
      ///
      /// @return :
      ///           MultiBody if found
      ///           MultiBody( Null ) if there is no MultiBody with such name
      //
      MultiBody getMultiBody( const std::string& name );

	    /// getMultiJoint:  
      /// 
      /// Get the MultiJoint by name.
      /// 
      /// @param [in] name / MultiJoint's name
      ///
      /// @return :
      ///           MultiJoint if found
      ///           MultiJoint( Null ) if there is no MultiJoint with such name
      //
      MultiJoint getMultiJoint ( const std::string& name );

	    /// getSpline:  
      /// 
      /// Get the Spline by name.
      /// 
      /// @param [in] name / Spline's name
      ///
      /// @return :
      ///           Spline if found
      ///           Spline( Null ) if there is no Spline with such name
      //
      Spline getSpline( const std::string& name );

	    /// getMultiServo_PosLinear:  
      /// 
      /// Get the MultiServo_Position_Linear by name.
      /// 
      /// @param [in] name / Multiservo's name
      ///
      /// @return :
      ///           MultiServo_Position_Linear if found
      ///           MultiServo_Position_Linear( Null ) if there 
      ///           is no MultiServo_Position_Linear with such name
      //
      MultiServo_PosLinear getMultiServo_PosLinear ( const std::string& name );

	    /// getMultiServo_PosAngular:  
      /// 
      /// Get the MultiServo_Position_Angular by name.
      /// 
      /// @param [in] name / Multiservo's name
      ///
      /// @return :
      ///           MultiServo_Position_Angular if found
      ///           MultiServo_Position_Angular( Null ) if there 
      ///           is no MultiServo_Position_Angular with such name
      //
      MultiServo_PosAngular getMultiServo_PosAngular ( const std::string& name );

	    /// getMultiServo_VelLinear:  
      /// 
      /// Get the MultiServo_Velocity_Linear by name.
      /// 
      /// @param [in] name / Multiservo's name
      ///
      /// @return :
      ///           MultiServo_Velocity_Linear if found
      ///           MultiServo_Velocity_Linear( Null ) if there 
      ///           is no MultiServo_Velocity_Linear with such name
      //
      MultiServo_VelLinear getMultiServo_VelLinear ( const std::string& name );

	    /// getMultiServo_VelAngular:  
      /// 
      /// Get the MultiServo_Velocity_Angular by name.
      /// 
      /// @param [in] name / Multiservo's name
      ///
      /// @return :
      ///           MultiServo_Velocity_Angular if found
      ///           MultiServo_Velocity_Angular( Null ) if there 
      ///           is no MultiServo_Velocity_Angular with such name
      //
      MultiServo_VelAngular getMultiServo_VelAngular ( const std::string& name );

      /// getCamera:  
      ///
      /// Gets Camera by name from the current Scene
      /// 
      /// @param [in] name / Camera 's name
      /// 
      /// @return :
      ///           Camera if found
      ///           Camera( Null ) if there is no Camera with such name
      //
      Camera getCamera( const std::string& name );

      /// getObject:  
      /// 
      /// Gets Sdk Object by name from the current Scene
      /// 
      /// @param [in] name / Sdk Object 's name
      /// 
      /// @return :
      ///           Sdk Object if found
      ///           Sdk Object( Null ) if there is no Sdk Object with such name
      //
      Object getObject( const std::string& name );

      /// simulateStep:  
      ///
      /// Simulates the Scene one cycle (step) forward from the current time line position. 
      /// Returns a symbolic constant that provides information about what the 
      /// simulation status is after the cycle is simulated.
      ///
      /// @return SimulStatus / Simulation status after the cycle: 
      ///   SIM_STATUS_FRAME_IS_UP -> if after the cycle we are in a new frame
      ///   SIM_STATUS_FINISHED    -> if after the cycle we reach the scene last frame
      ///   SIM_STATUS_NORMAL      -> when nothing happened
      //
      SimulStatus simulateStep( void );

      /// simulate: 
      ///     
      /// Simulate the scene from the current frame to the end frame.  
      /// IMPORTANT: This function can't be called from a script that is executed as a response to an event
      ///
      //
      void simulate( void );


      ///     
      /// Stops simulation
      ///
      //
      void stopSimulation ( void );

      /// simulateRange: 
      ///     
      /// Simulates the current Scene from the startFrame to the stopFrame. 
      /// Range checking is done and the proper error is raised in such a case.
      /// IMPORTANT: This function can't be called from a script that is executed as a response to an event
      ///
      /// @param [in] startFrame / Start frame #Default value = 0
      /// @param [in] stopFrame / Stop frame #Default value = maxFrames
      //
      void simulateRange( int startFrame , int stopFrame  );

      /// reset: 
      /// 
      /// Resets the current Scene
      //
      void reset( void );

      /// setCurrentFrame: 
      /// 
      /// Moves the time line cursor to the specified frame in the current Scene. 
      /// Range checking is done and the proper error is raised in such a case 
      /// 
      /// @param [in] frameToMoveIn / Frame to move in
      //
      void setCurrentFrame( int frameToMoveIn );

      /// load: 
      /// 
      /// Loads the current Scene from a file (.flw)
      /// 
      /// @param [in] path / File 's file Path
      //
      bool load ( const std::string& path );

      /// newScene: 
      /// 
      /// Recreates the current Scene as a new one
      //
      void newScene( void );

      /// addGroup:  
      ///
      /// Creates a new Group and adds it to the current Scene
      ///
      /// @return a new Group
      //
      Group addGroup( void );
      
      /// removeGroup:  
      ///
      /// Deletes a Group from the current Scene
      ///
      /// @param [in] name / Group 's name
      //
      void removeGroup( std::string name );

      /// addSphere:  
      ///
      /// Creates a new Sphere Object and adds it to the current scene
      ///
      /// @param [in] resolution / resolution used to build the Sphere ; 
      ///                         - resolution ( Default value ) = 0
      ///
      /// @return a new Sphere Object
      //
      Sphere addSphere( int resolution = 0 );

      /// addCapsule:  
      ///
      /// Creates a new Capsule Object and adds it to the current scene
      ///
      /// @return a new Capsule Object
      //
      Capsule addCapsule( void );

      /// addCube:  
      ///
      /// Creates a new Cube Object and adds it to the current scene
      ///
      /// @return a new Cube Object
      //
      Cube addCube( void );

      /// addCubeTopOpen:  
      ///
      /// Creates a new Cube Top Open Object and adds it to the current scene
      ///
      /// @return a new Cube Top Open Object
      //
      CubeTopOpen addCubeTopOpen( void );

      /// addCross:  
      ///
      /// Creates a new Cross Object and adds it to the current scene
      ///
      /// @return a new Cross Object
      //
      Cross addCross( void );

      /// addHemisphere:  
      ///
      /// Creates a new Hemisphere Object and adds it to the current scene
      ///
      /// @param [in] resolution / resolution used to build the Hemisphere ; 
      ///                         - resolution ( Default value ) = 2
      ///
      /// @return a new Hemisphere Object
      //
      Hemisphere addHemisphere( int resolution = 2 ); 

      /// addPlane:  
      ///
      /// Creates a new Plane and adds it to the current scene
      ///
      /// @return a new Plane
      //
      Plane addPlane( void ); 

      /// addRocket:  
      ///
      /// Creates a new Rocket Object and adds it to the current scene
      ///
      /// @return a new Rocket Object
      //
      Rocket addRocket( void );

      /// addCylinder:  
      ///
      /// Creates a new Cylinder Object and adds it to the current scene
      ///
      /// @param [in] nVertxInBase / Number of vertices in the base
      ///                           - nVertxInBase ( Default value ) = 10
      /// @param [in] nSegments / Number of segments
      ///                           - nSegments ( Default value )    = 1
      ///
      /// @return a new Cylinder Object
      //
      Cylinder addCylinder ( int nVertxInBase = 10, 
                             int nSegments = 1 );

      /// addVase:  
      ///
      /// Creates a new Vase Object and adds it to the current scene
      ///
      /// @param [in] nVertxInBase / Number of vertices in the base
      ///                           - nVertxInBase ( Default value )    = 10
      /// @param [in] nSegments / Number of segments
      ///                           - nSegments ( Default value )       = 1
      /// @param [in] lengthUpperEdge / Size of the upper edge
      ///                           - lengthUpperEdge ( Default value ) = 2.0
      ///
      /// @return a new Vase Object
      //
      Vase addVase( int nVertxInBase      = 10, 
                    int nSegments         = 1, 
                    float lengthUpperEdge = 2.0 );

      /// addCone:  
      ///
      /// Creates a new Cone Object and adds it to the current scene
      ///
      /// @param [in] nVertxInBase / Number of vertices in the base
      ///                           - nVertxInBase ( Default value )    = 10
      ///
      /// @return a new Cone Object
      //
      Cone addCone( int nVertxInBase = 10 ); 

      /// addTorus:  
      ///
      /// Creates a new Torus  Object and adds it to the current scene
      ///
      /// @param [in] nVertxInCrsSect / Number of vertices in cross section 
      ///                               - nVertxInCrsSect ( Default value ) = 10
      /// @param [in] nSegments       / Number of segments
      ///                               - nSegments ( Default value )       = 20
      ///
      /// @return a new Torus  Object
      //
      Torus addTorus( int nVertxInCrsSect = 10, 
                      int nSegments = 20 ); 

      /// addRealWave:  
      ///
      /// Creates a new RealWave and adds it to the current scene
      ///
      /// @return a new RealWave 
      //
      RealWave addRealWave( void );

      /// getCurrentFrame:  
      ///
      /// Gets the Current Scene 's Frame
      ///
      /// @return : Current Scene 's Frame
      //
      int getCurrentFrame( void );  

      /// getNumberOfThreads:  
      ///
      /// Gets the number of threads that will be used for simulation
      ///
      /// @return : Number of threads
      //
      int getNumberOfThreads( void );  

      /// getRealFlowVersion:  
      ///
      /// Gets the RealFlow version
      ///
      /// @return : RealFlow version
      //
      std::string getRealFlowVersion( void );  

      /// getPackageEdition:  
      ///
      /// Gets the RealFlow package edition
      ///
      /// @return : RealFlow package edition 
      //
      std::string getPackageEdition( void );  

      /// save:  
      ///
      /// Saves the Current Scene
      ///
      /// @param [in] path / Scene's file path including file extension ".flw". 
      ///                    Path delimiter "/" should be used instead of "\"
      /// 
      /// @return : True if the Scene was saved successfully, False otherwise
      bool save( const std::string& path );

      /// getDaemon:  
      /// 
      /// Gets Daemon by name from the current Scene
      /// 
      /// @param [in] name / Daemon 's name
      ///
      /// @return :
      ///           Daemon if found
      ///           Daemon( Null ) if there is no Daemon with such name
      //
      Daemon getDaemon( const std::string& name );

      /// getMesh:  
      ///
      /// This function has been deprecated and will be removed in future versions 
      /// of RF, use "getParticleMeshLegacy" instead. 
      /// 
      /// Gets Mesh by name from the current Scene
      /// 
      /// @param [in] name / Mesh's name
      ///
      /// @return :
      ///           Mesh if found
      ///           Mesh( Null ) if there is no Mesh with such name
      //
      StandardMesh getMesh( const std::string& name );

      /// getParticleMeshLegacy:  
      ///
      /// Gets Mesh by name from the current Scene
      /// 
      /// @param [in] name / Mesh's name
      ///
      /// @return :
      ///           Mesh if found
      ///           Mesh( Null ) if there is no Mesh with such name
      //
      ParticleMeshLegacy getParticleMeshLegacy( const std::string& name );

      /// getGridMesh:  
      /// 
      ///  This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_Mesh" instead.
      ///
      /// Gets hybrido mesh by name from the current Scene
      /// 
      /// @param [in] name / Hybrido mesh's name
      ///
      /// @return :
      ///           Hybrido mesh if found
      ///           HY_Mesh( Null ) if there is no hybrido mesh with such name
      //
      GridMesh getGridMesh( const std::string& name );

      /// get_HY_Mesh:  
      /// 
      /// Gets hybrido mesh by name from the current Scene
      /// 
      /// @param [in] name / Hybrido mesh's name
      ///
      /// @return :
      ///           Hybrido mesh if found
      ///           HY_Mesh( Null ) if there is no hybrido mesh with such name
      //
      HY_Mesh get_HY_Mesh( const std::string& name );


      /// get_HY_Mesh_VDB:  
      /// 
      /// Gets hybrido mesh vdb by name from the current Scene
      /// 
      /// @param [in] name / Hybrido mesh's vdb name
      ///
      /// @return :
      ///           Hybrido mesh vdb if found
      ///           HY_Mesh( Null ) if there is no hybrido mesh vdb with such name
      //
      HY_Mesh_VDB get_HY_Mesh_VDB( const std::string& name );

      /// getRenderkitMesh:  
      /// 
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "getParticleMesh" instead.
      ///
      /// Gets renderkit mesh by name from the current Scene
      /// 
      /// @param [in] name / Renderkit mesh's name
      ///
      /// @return :
      ///           Renderkit mesh if found
      ///           RenderkitMesh( Null ) if there is no renderkit mesh with such name
      //
      RenderkitMesh getRenderkitMesh( const std::string& name );

      /// getParticleMesh:  
      /// 
      /// Gets renderkit mesh by name from the current Scene
      /// 
      /// @param [in] name / Renderkit mesh's name
      ///
      /// @return :
      ///           Renderkit mesh if found
      ///           RenderkitMesh( Null ) if there is no renderkit mesh with such name
      //
      ParticleMesh getParticleMesh( const std::string& name );

      /// getParticleMesh_VDB:  
      /// 
      /// Gets VDB mesh by name from the current Scene
      /// 
      /// @param [in] name / VDB mesh's name
      ///
      /// @return :
      ///           VDB mesh if found
      ///           ParticleMesh_VDB( Null ) if there is no VDB mesh with such name
      //
      ParticleMesh_VDB getParticleMesh_VDB( const std::string& name );

      /// getMist:  
      /// 
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_Mist" instead.
      ///
      /// Gets mist by name from the current Scene
      /// 
      /// @param [in] name / Mist's name
      ///
      /// @return :
      ///           Mist if found
      ///           Mist( Null ) if there is no Mist with such name
      //
      Mist getMist( const std::string& name );

      /// get_HY_Mist:  
      /// 
      /// Gets mist by name from the current Scene
      /// 
      /// @param [in] name / Mist's name
      ///
      /// @return :
      ///           Mist if found
      ///           Mist( Null ) if there is no Mist with such name
      //
      HY_Mist get_HY_Mist( const std::string& name );

      /// getGridDomain:  
      /// 
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "get_HY_GridDomain" instead.
      ///
      /// Gets grid domain by name from the current Scene
      /// 
      /// @param [in] name / Grid domain's name
      ///
      /// @return :
      ///           Grid domain if found
      ///           HY_GridDomain( Null ) if there is no grid domain with such name
      //
      GridDomain getGridDomain( const std::string& name );

      /// get_HY_GridDomain:  
      /// 
      /// Gets grid domain by name from the current Scene
      /// 
      /// @param [in] name / Grid domain's name
      ///
      /// @return :
      ///           Grid domain if found
      ///           HY_GridDomain( Null ) if there is no grid domain with such name
      //
      HY_GridDomain get_HY_GridDomain( const std::string& name );

      /// getIDOC:  
      /// 
      /// Gets IDOC by name from the current Scene
      /// 
      /// @param [in] name / IDOC's name
      ///
      /// @return :
      ///           IDOC if found
      ///           IDOC( Null ) if there is no IDOC with such name
      //
      IDOC getIDOC( const std::string& name );

      /// getConstraint:  
      /// 
      /// Gets Joint by name from the current Scene
      /// 
      /// @param [in] name / Joint 's name
      ///
      /// @return :
      ///           Joint if found
      ///           Joint( Null ) if there is no Joint with such name
      //
      Joint getConstraint( const std::string& name ); 

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( PB_Emitter&  sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( Daemon& sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( Object& sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( RealWave& sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( HY_Emitter& sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( Mist& sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( HY_GridDomain& sdkObj );

      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void addGlobalLink( MultiBody& sdkObj );


      /// addGlobalLink:  
      /// 
      /// Adds a global link to the scene for the given Node
      /// 
      /// @param [in] sdkObj / Node to be globally linked
      //
      void                    addGlobalLink     ( MultiJoint& sdkObj         );

      /// getLinkedNodes:  
      /// 
      /// Get the list of nodes linked to the input node.
      /// 
      /// @param [in] node
      /// @param [out] nodes / Vector of NodeAccesors 
      ///                     NodeAccesor is a wrapper to a Node object which type could be any.
      ///                     To obtain the sdk object wrapped inside the NodeAccesor use the
      ///                     methods getType and asRFCamera, asMesh ... See NodeAccesor for more details.
      //
      template < class T >
      void getLinkedNodes( const T& node, ArrSdkNodeAccesors& outSdkNodeAccesors );

      /// addExclusiveLink:  
      /// 
      /// Adds a exclusive link to the current Scene between the specified Nodes.
      /// Source Node ( srcSdkObj )is linked to target Node ( trgtSdkObj )
      /// 
      /// @param [in] trgtSdkObj  / Target Node 
      ///                           trgtSdkObj 's type can be any of [ Realwave | Emitter | Daemon | Object ]
      /// @param [in] srcSdkObj   / Source Node
      ///                           srcSdkObj 's type can be any of [ Realwave | Emitter | Daemon | Object ]
      //
      template <class TRG_T, class SRC_T>
      void addExclusiveLink ( TRG_T& trgtSdkObj, 
                              SRC_T& srcSdkObj  );
      /// removeExclusiveLink:  
      /// 
      /// Removes a exclusive link from the current Scene between the specified Nodes.
      /// The link between the source Node ( srcSdkObj ) and the target Node ( trgtSdkObj )
      //  is removed.
      /// 
      /// @param [in] trgtSdkObj  / Target Node 
      ///                           trgtSdkObj 's type can be any of [ Realwave | Emitter | Daemon | Object ]
      /// @param [in] srcSdkObj   / Source Node
      ///                           srcSdkObj 's type can be any of [ Realwave | Emitter | Daemon | Object ]
      //
      template <class TRG_T, class SRC_T>
      void removeExclusiveLink( TRG_T& trgtSdkObj, 
                                SRC_T& srcSdkObj  );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( PB_Emitter&  sdkObj );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( Daemon& sdkObj);

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( Object& sdkObj );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( RealWave& sdkObj );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( HY_Emitter& sdkObj );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( Mist& sdkObj );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( HY_GridDomain& sdkObj );

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink ( MultiJoint& sdkObj );


      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      void removeGlobalLink( MultiBody& sdkObj );
      
      /// isLinkAllowed:  
      /// 
      /// Checks if it is possible to create a direct link between the given nodes or hubs
      /// 
      /// @param [in] sourceName / Name of Node or hub to be the source of the link
      /// @param [in] targetName / Name of Node or hub to be the target of the link
      /// 
      /// @return : True if a direct link is possible or already exists. 
      ///           False if the link cannot be created.
      //
      bool isLinkAllowed( const std::string& sourceName, const std::string& targetName );
      
      /// addLink:  
      /// 
      /// Creates a direct link between the given nodes or hubs
      /// 
      /// @param [in] sourceName / Name of Node or hub to be the source of the link
      /// @param [in] targetName / Name of Node or hub to be the target of the link
      /// 
      /// @return : True if the link was successfully created. False if the link
      ///           could not be created because inputs are not compatible or the link
      ///           already existed
      //
      bool addLink( const std::string& sourceName, const std::string& targetName );
      
      /// addLinkToHub:  
      /// 
      /// Creates a direct link between a node and a hub
      /// 
      /// @param [in] nodeName / Name of the node to connect to the hub
      /// @param [in] targetName / Name of the hub to connect the node
      /// 
      /// @return : True if the link was successfully created. False if the link
      ///           could not be created because inputs are not compatible or the link
      ///           already existed
      //
      bool addLinkToHub( const std::string& nodeName, const std::string& hubName );
      
      
      /// sceneAddLinkToDefaultHub:  
      /// 
      /// Creates a direct link between a node and the scene default hub
      /// 
      /// @param [in] nodeName / Name of the node to connect to the default hub
      /// 
      /// @return : True if the link was successfully created. False if the link
      ///           could not be created because inputs are not compatible or the link
      ///           already existed
      //
      bool sceneAddLinkToDefaultHub( const std::string& nodeName );

      /// removeLink:  
      /// 
      /// Removes, if exists, the direct link between the given nodes or hubs
      /// 
      /// @param [in] sourceName / Node or hub to be the source of the link
      /// @param [in] targetName / Node or hub to be the target of the link
      /// 
      /// @return : True if the link was successfully remove. False if the link
      ///           did not exist
      //
      bool removeLink( const std::string& sourceName, const std::string& targetName );

      /// addHub:  
      /// 
      /// Adds a new connection hub to the scene
      /// 
      /// @return : The new hub name
      //
      std::string addHub( void );
      
      /// getDefaultHubName:  
      /// 
      /// Returns the name of the default hub of the scene.
      /// 
      /// @param [out] defaultHubName / The name of the default hub of the scene
      /// 
      /// @return : True if the scene has any hub. False otherwise
      //
      bool getDefaultHubName( std::string& defaultHubName );
      
      /// hasHub:  
      /// 
      /// Checks if the scene contains a hub with the given name
      /// 
      /// @param [in] hubName / The name of the hub to check if exists
      /// 
      /// @return : True if a hub with the given name exists. False otherwise
      //
      bool hasHub( const std::string& hubName );
      
      /// removeHub:  
      /// 
      /// Removes from the scene the hub with the given name
      /// 
      /// @param [in] hubName / The name of the hub to remove
      /// 
      /// @return : True if a hub with the given name existed and has been remove. 
      ///           False otherwise
      //
      bool removeHub( const std::string& hubName );
      
      /// renameHub:  
      /// 
      /// Renames a hub from the scene
      /// 
      /// @param [in] hubName / The current name of the hub to rename
      /// @param [in] newHubName / The desired name for the hub to rename
      /// 
      /// @return : True if a the hub was successfully renamed. 
      ///           False otherwise
      //
      bool renameHub( const std::string& hubName, const std::string& newHubName );
      
      /// getHubs:  
      /// 
      /// Returns the name of all the hubs from the scene
      /// 
      /// @param [out] hubNames / The name of the hubs in the scene
      /// 
      //
      void getHubs( std::vector< std::string >& hubNames );
      
      /// getHubLinks:  
      /// 
      /// Returns all the direct links for the given hub
      /// 
      /// @param [out] hubName / The name of the hub to check the links with
      /// @param [out] links / The name of the nodes connected to the hub
      /// 
      /// @return : True if the hub exists. False otherwise
      //
      bool getHubLinks( const std::string& hubName, std::vector< std::string >& links );
      
      /// getLinksWithNode:  
      /// 
      /// Returns the links of a given node or hub
      /// 
      /// @param [in] nodeName / The name of the node or hub to check the links with
      /// @param [in] ifNodeIsSource / True to include links where the node is the source
      /// @param [in] ifNodeIsTarget / True to include links where the node is the target
      /// @param [in] includeImplicit / True to include implicit links with the given node.
      ///                               False to include only direct links
      /// @param [out] links / The name of the nodes/hubs connected to the given node/hub
      /// 
      /// @return : True if the node or hub exists. False otherwise
      //
      bool getLinksWithNode( const std::string& nodeName, 
                             const bool& ifNodeIsSource,
                             const bool& ifNodeIsTarget,
                             const bool& includeImplicit,
                             std::vector< std::string >& links );
      
      /// getUserGraphFolder:  
      /// 
      /// Returns the folder where Simulation Graph components are stored to be used
      /// as compounds for new graphs
      /// 
      /// @return : The path to the folder where files are stored
      //
      std::string getUserGraphFolder( void );
      
      /// setUserGraphFolder:  
      /// 
      /// Changes the folder where Simulation Graph components are stored to be used
      /// as compounds for new graphs
      /// 
      /// @param [in] newPath / The path to the new folder where files are stored
      //
      void setUserGraphFolder( const std::string& newPath );
      
      /// getGroups:  
      ///
      /// Gets the current Scene 's Groups
      ///
      /// @param [out]  groups / Vector of the current Scene 's Groups
      //
      void getGroups( ArrSdkGroups& groups );

      /// getMesh:  
      /// 
      /// Gets Group by name from the current Scene
      /// 
      /// @param [in] name / Group 's name
      ///
      /// @return :
      ///           Group if found
      ///           Group( Null ) if there is no Group with such name
      //
      Group getGroup( const std::string& grpName );
      
      /// getMaxFrames:  
      ///
      /// Gets the Current Scene 's maximum number of Frames
      ///
      /// @return : Current Scene 's maximum number of Frames
      //     
      int getMaxFrames();
      
      /// setMaxFrames:  
      ///
      /// Sets the current Scene 's maximum number of Frames
      ///
      /// @param [in] maxFrames / new current Scene 's maximum number of Frames
      //  
      void setMaxFrames( int maxFrames ); 
      
      /// getMinFrame:  
      ///
      /// Gets the Current Scene 's first simulation frame
      ///
      /// @return : Current Scene 's first simulation frame
      //     
      int getMinFrame();
      
      /// setMinFrame:  
      ///
      /// Sets the current Scene 's first simulation frame
      ///
      /// @param [in] minFrame / new current Scene 's first simulation frame
      //  
      void setMinFrame( int minFrame ); 
      
      /// getEndFrame:
      ///
      /// Gets the Current Scene 's last edition frame
      ///
      /// @return : Current Scene 's last edition frame
      //
      int getEndFrame();
      
      /// setEndFrame:
      ///
      /// Sets the current Scene's last edition frame
      ///
      /// @param [in] endFrame / new current Scene's last edition frame
      //
      void setEndFrame( int endFrame );
      
      /// getFps:  
      ///
      /// Gets the Current Scene 's FPS (Frames Per Second)
      ///
      /// @return : Current Scene 's FPS
      //     
      int getFps(); 
      
      /// setFps:  
      ///
      ///  Sets the Current Scene 's FPS (Frames Per Second)
      ///
      /// @param [in] fps / new current Scene 's FPS
      //  
      void setFps( int fps ); 

      /// addObject:  
      ///
      /// Creates a new Object and adds it to the current scene. The new Object geometry 
      /// is given by the set of Vertices( vrtxs ) and Faces( faces ) given as parameters. Several checks are 
      /// done in order to ensure that the geometry description is good. If the Object 's name
      /// is already assigned it is automatically changed to a new valid one
      ///
      /// @param [in] name  / new Object 's name
      /// @param [in] vrtxs / new Object 's Vertices
      /// @param [in] faces / new Object 's Faces
      ///
      /// @return a new Object described by the geometry of Vertices( vrtxs ) and Faces( faces )
      //
      Object addObject( const std::string& name, 
                        const std::vector<Vertex>& vrtxs, 
                        const std::vector<Face>& faces );

      /// addNull:  
      /// 
      /// Adds an Object( Null )to the current Scene
      /// 
      /// @return : a new Object( Null )
      //
      Object addNull();

      /// getRealWave:  
      /// 
      /// Gets the current Scene 's RealWave
      /// 
      /// @return :
      ///           RealWave if this Object has been added to the current Scene
      ///           RealWave( Null ) if the the current Scene has no RealWave
      //
      RealWave getRealWave();
      
      /// getNode:
      ///
      /// Gets node or group by name from the current Scene
      ///
      /// @param [in] name / Node's name
      ///
      /// @return : NodeAccesor if found
      ///           NodeAccesor( Null ) if there is no node with such name
      ///
      NodeAccesor getNode( const std::string& name );

      /// getNodes:  
      ///
      /// Get the list of Nodes in the current Scene. 
      /// 
      /// @param [out] nodes / Vector of NodeAccesors 
      ///                     NodeAccesor is a wrapper to a Node object which type could be any.
      ///                     To obtain the sdk object wrapped inside the NodeAccesor use the
      ///                     methods getType and asRFCamera, asMesh ... See NodeAccesor for more details.
      //
      void getNodes( ArrSdkNodeAccesors& nodes ); 

      /// getSelectedNodes:  
      ///
      /// Get the list of selected Nodes in the current Scene. 
      /// 
      /// @param [out] nodes / Vector of NodeAccesors 
      ///                     NodeAccesor is a wrapper to a Node object which type could be any.
      ///                     To obtain the sdk object wrapped inside the NodeAccesor use the
      ///                     methods getType and asRFCamera, asMesh ... See NodeAccesor for more details.
      //
      void getSelectedNodes( ArrSdkNodeAccesors& nodes ); 
      

      /// selectNodes
      ///
      /// Set selected Nodes in the current Scene. 
      /// 
      /// @param [in] nodes / Vector of NodeAccesors 
      //
      void selectNodes(const ArrSdkNodeAccesors& nodes, bool add = false );

      
      /// selectNodes
      ///
      /// Set selected Nodes in the current Scene. 
      /// 
      /// @param [in] nodes / Vector of std::string containing node names.
      //
      void selectNodes( const std::vector<std::string>& nodes, bool add = false );

      /// removeAllNodes:  
      ///
      /// Remove all Nodes in the current Scene
      //
      void removeAllNodes(); 
      
      /// setUndoEnable:  
      /// 
      /// Enables/Disables the undo functionality of the WorkSpace
      /// 
      /// @param [in] enable / True to enable the undo functionality
      /// 
      /// @return : State before the change
      //
      bool setUndoEnable( bool enable );
      
      /// setAddToDefaultHub:  
      /// 
      /// Define the policy of default hub links for new created Nodes
      /// 
      /// @param [in] addToDefaultHub / If true then new created Nodes are added to the default hub
      /// 
      /// @return : State before the change
      //
      bool setAddToDefaultHub( bool addToDefaultHub );
      
      
      /// setAddToGlobalLinks:  
      ///
      /// This function has been deprecated and will be removed in future 
      /// versions of RF, use "setAddToDefaultHub" instead.
      ///
      /// Define the policy of global links for new created Nodes
      /// 
      /// @param [in] addToGlobalLnks / If true then new created Nodes are added to the global links
      /// 
      /// @return : State before the change
      //
      bool setAddToGlobalLinks( bool addToGlobalLnks );

      /// getAxisSetup:  
      /// 
      /// Gets the axis setup that is used in the current Scene. 
      /// 
      /// @return : Axis setup : Value in [ AXIS_SETUP_YXZ, AXIS_SETUP_ZXY, AXIS_SETUP_YZX ]
      //
      int getAxisSetup();

      /// getRootPath:  
      /// 
      /// Gets current Scene 's root path 
      /// 
      /// @return : Current Scene 's root path
      //
      std::string getRootPath();

      /// getFileName:  
      /// 
      /// Gets current Scene 's file name (extension included).
      /// 
      /// @return : Current Scene 's file name (extension included).
      //
      std::string getFileName(); 

      /// loadMasterEventsScript:  
      /// 
      /// Load the Master Events Script from an external file.
      ///
      /// @param [in] filePath / Path to the script file to load.
      /// 
      /// @return : True if Master Events Script has been successfully replaced, false in other case.
      //
      bool loadMasterEventsScript( const std::string& filePath ); 
      
      /// activateMasterEventsScript:  
      /// 
      /// Activate/deactivate the Master Events Script from an external file.
      ///
      /// @param [in] activate / True to activate, False to deactivate.
      //
      void activateMasterEventsScript( bool activate ); 

      /// isMasterEventsScriptActive:  
      /// 
      /// Gets the Master Events Script active state.
      ///
      /// @return : True if Master Events Script is active, false otherwise.
      //
      bool isMasterEventsScriptActive(); 
      
      /// paint:  
      /// 
      /// Force to paint all the nodes in the ciurrent Scene, as a result all the views are updated. 
      /// You might need to do this after you modify, for instance, the Particle 's position. 
      /// Updating the views every time you change a particle 's property will lead to poor performance. 
      /// This way you can indicate RealFlow when you want the views to be updated, i.e. when all 
      /// the particles have been changed. 
      //
      void paint(); 
      
      /// getScale:  
      ///
      /// Gets the Current Scene 's Scale
      ///
      /// @return : Current Scene 's Scale
      //     
      float getScale(); 

      /// setScale:  
      ///
      /// Sets the Current Scene 's Scale
      ///
      /// @param [in] scale / new current Scene 's Scale
      //  
      void setScale( float scale ); 

      /// getDescription:  
      ///
      /// Gets the Current Scene 's Description. This information can be edited and visualized in 
      /// the "Summary Info" window
      ///
      /// @return : Current Scene 's Description
      //  
      std::string getDescription();

      /// setDescription:  
      ///
      /// Sets the Current Scene 's Description. This information can be edited and visualized in
      /// the "Summary Info" window
      ///
      /// @param [in] descp / new current Scene 's Description
      //  
      void setDescription( std::string& descp );

      /// enablePaint:
      ///
      /// Enable/disable the painting. Useful to speed up the execution of your script if 
      /// you are doing many things and don't want immediate feedback. For instance, if 
      /// you are creating particles and don't want the view to be updated every single 
      /// time a particle is created. 
      ///
      /// @param [in] enable / Enable/disable. 
      void enablePaint( const bool& enable );

      /// enable_GUI_updates:
      ///
      /// Enable/disable the GUI updates. Useful to speed up the execution of your script 
      /// if you are doing many things and don't want the GUI to be updated at every 
      /// single function. For instance you are creating one hundred emitters, and you 
      /// don't want the GUI to be updated every time an emitter gets created. 
      ///
      /// @param [in] enable / Enable/disable. 
      void enable_GUI_updates( const bool& enable );

      /// goToLastCachedFrame
      /// Move simulation bar to the last cached frame.
      ///
      void goToLastCachedFrame();
      
      /// getLastCachedFrame
      /// Return the last cached frame number.
      ///
      /// @return : The last cached frame number.
      ///
      int getLastCachedFrame();
      
      /// updateTimeLineCacheFrame
      /// Refresh the time line to find the last simulated frame.
      ///
      void updateTimeLineCache();
      
      /// getSceneVariable
      /// Return the value of the input Scene Variable name.
      ///
      /// @param [in] name / The name of the variable
      ///
      /// @return : The value of the input scene variable. An empty string if it
      ///           does not exist
      ///
      std::string getSceneVariable( const std::string& name );
      
      /// setSceneVariable
      /// Changes or sets the value of the input Scene Variable name.
      ///
      /// @param [in] name / The name of the variable
      /// @param [in] value / The new value for the scene variable
      void setSceneVariable( const std::string& name, const std::string& value );
      
      /// resolveSceneVariables
      /// Returns a version of the input string with all the scene variables resolved.
      ///
      /// @param [in] string / String that may contain scene variables.
      ///                    For example: "$(SCENEDIR)/particles".
      ///
      /// @return : The input string with all the scene variables resolved.
      //
      std::string resolveSceneVariables( const std::string& string );
      
      /// resolveSceneVariablesUsingAlternativePaths
      /// Returns a version of the input string with all the scene variables resolved
      /// for every existing alternative path.
      ///
      /// @param [in] string / String that may contain scene variables.
      ///                    For example: "$(SCENEDIR)/particles".
      ///
      /// @param [out] resolvedList / The input string with all the scene variables resolved
      ///                             for every existing alternative path
      //
      void resolveSceneVariablesUsingAlternativePaths( const std::string& string,
                                         std::vector< std::string >& resolvedList );
      
      // createGlobalVariableValue
      template < class T_DEST  >
      T_DEST& createGlobalVariableValue( const std::string& nameVar )
      {
        T_DEST* newVar = new T_DEST();
        nl::NL_RefType<T_DEST>* objType = 
          new nl::NL_RefType<T_DEST>( *newVar );

        void* retVar = createGlobalVariableValueAux( nameVar, objType );

        if ( retVar == NULL )
        {
          NL_safeDelete( objType);
          NL_safeDelete( newVar );
          SdkExcptMessg::throw_GlobalVarAlreadyDefined( nameVar );
        }
        else
        {
          return ( objType->getRef() );
        }
      }

      // setGlobalVariableValue
      template < class T_DEST  >
      void setGlobalVariableValue( const std::string& nameVar, const T_DEST& varValue )
      {
        NL_RefTypeBase* objType = getGlobalVariableValueAux( nameVar );

        if ( objType == NULL )
        {
          SdkExcptMessg::throw_GlobalVarNotDefined( nameVar );
        }
        else
        {
          if ( nl::NL_Is_RefToType<T_DEST>( *objType ) )
          {
            T_DEST& refTovar = ( dynamic_cast< nl::NL_RefType<T_DEST>* >( objType ) )->getRef();
            refTovar = varValue;
          }
          else
          {
            SdkExcptMessg::throw_WrongTypeCast( "Scene", "getGlobalVariableValue" );
          }
        }
      }

      // getGlobalVariableValue
      template < class T_DEST  >
      T_DEST& getGlobalVariableValue( const std::string& nameVar )
      {
        NL_RefTypeBase* objType = getGlobalVariableValueAux( nameVar );

        if ( objType == NULL )
        {
          SdkExcptMessg::throw_GlobalVarNotDefined( nameVar );
        }
        else
        {
          if ( nl::NL_Is_RefToType<T_DEST>( *objType ) )
          {
            return ( ( dynamic_cast< nl::NL_RefType<T_DEST>* >( objType ) )->getRef() );
          }
          else
          {
            SdkExcptMessg::throw_WrongTypeCast( "Scene", "getGlobalVariableValue" );
          }
        }
      }

      /// existsGlobalVariable:  
      ///
      /// Tests whether the global variable ( nameVar ) is defined or not
      ///
      /// @param [in] nameVar / global variable name
      ///
      /// @return : true if the variable is defined, false otherwise
      //  
      bool existsGlobalVariable( const std::string& nameVar );

      // 
      void removeGlobalVariable( const std::string& nameVar )
      {
        removeGlobalVariableAux( nameVar );
      }

      /// removeAllGlobalVariables:  
      ///
      /// Removes all existing global variables.
      void removeAllGlobalVariables( void );
      
      /// getExportResourcePath:  
      ///
      /// Gets the Scene 's path for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Scene 's resource Id. 
      ///                      Valid resources are: EXPORT_SCENE_ANIMATION_SD,
      ///                                           EXPORT_SCENE_CACHE_BDC,
      ///                                           EXPORT_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW_FRAMES,
      ///                                           EXPORT_CHANNELS,
      ///                                           EXPORT_LOG,
      ///                                           EXPORT_JOBFILES
      ///
      /// @return : Scene 's resource's path. Empty string ("") if the resource is not found
      //
      std::string getExportResourcePath( const int rsrcId );
      
      /// setExportResourcePath:  
      ///
      /// Sets the Scene 's path for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources are: EXPORT_SCENE_ANIMATION_SD,
      ///                                           EXPORT_SCENE_CACHE_BDC,
      ///                                           EXPORT_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW_FRAMES,
      ///                                           EXPORT_CHANNELS,
      ///                                           EXPORT_LOG,
      ///                                           EXPORT_JOBFILES
      ///
      /// @param [in] path / new Scene 's path for resource ( rsrcId )  
      //
      void setExportResourcePath( const int rsrcId, const std::string path );
      
      /// getExportResourceName:  
      ///
      /// Gets the name for a specific Scene's resource. 
      /// This is the name used for the root of the file name exported for the resource.   
      ///
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources are: EXPORT_SCENE_ANIMATION_SD,
      ///                                           EXPORT_SCENE_CACHE_BDC,
      ///                                           EXPORT_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW_FRAMES,
      ///                                           EXPORT_CHANNELS,
      ///                                           EXPORT_LOG
      ///
      /// @return : Scene 's resource name
      //
      std::string getExportResourceName( const int rsrcId );
      
      /// setExportResourceName:  
      ///
      /// Sets the name for a specific Scene's resource. 
      /// This is the name used for the root of the file name exported for the resource.   
      ///
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources are: EXPORT_SCENE_ANIMATION_SD,
      ///                                           EXPORT_SCENE_CACHE_BDC,
      ///                                           EXPORT_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW,
      ///                                           EXPORT_VIDEO_PREVIEW_FRAMES,
      ///                                           EXPORT_CHANNELS,
      ///                                           EXPORT_LOG
      ///
      /// @param [in] rsrcName / Scene 's resource name
      //
      void setExportResourceName( const int rsrcId, const std::string& rsrcName );
      
      /// isExportResourceActive:  
      ///
      /// Gets the Scene 's active state for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources are: EXPORT_SCENE_ANIMATION_SD,
      ///                                           EXPORT_SCENE_CACHE_BDC,
      ///                                           EXPORT_PREVIEW,
      ///                                           EXPORT_LOG
      ///
      /// @return : True if the specific resource is active for exporting or False otherwise
      //
      bool isExportResourceActive( int rsrcId );
      
      /// activeExportResource:  
      ///
      /// Sets the Scene 's active state for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources are: EXPORT_SCENE_ANIMATION_SD,
      ///                                           EXPORT_SCENE_CACHE_BDC,
      ///                                           EXPORT_PREVIEW,
      ///                                           EXPORT_LOG
      ///
      /// @param [in] activate / True to activate the resource for exporting, False otherwise
      //
      void activeExportResource( const int rsrcId, const bool activate );
      
      /// getExportResourceImageFormat:  
      ///
      /// Gets the Scene 's image format for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources is: EXPORT_PREVIEW
      ///
      /// @return : Scene 's resource's image format. -1 if resource does not exist.
      //
      int getExportResourceImageFormat( const int rsrcId );
      
      /// setExportResourceImageFormat:  
      ///
      /// Sets the Scene 's image format for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Scene 's resource Id.
      ///                      Valid resources is: EXPORT_PREVIEW
      ///
      /// @param [in] format / new Scene's image format for resource ( rsrcId )  
      ///                      Valid formats are:  IMAGE_FORMAT_TGA,
      ///                                           IMAGE_FORMAT_BMP,
      ///                                           IMAGE_FORMAT_JPG,
      ///                                           IMAGE_FORMAT_PNG
      //
      void setExportResourceImageFormat( const int rsrcId, const int format );
      
      /// getAllSceneExportResources:
      ///
      /// Returns all the available export resources at scene level.
      ///
      /// @param [out] rsrcIds / Scene's export resource Ids.
      ///
      //
      void getAllSceneExportResources( std::vector< int >& rsrcIds );
      
      /// getAllExportResourceOptions:
      ///
      /// Returns all the available options for a scene export resource.
      /// For instance: ["png", "tga", etc] for EXPORT_PREVIEW
      ///
      /// @param [in] rsrcId / Scene 's resource Id.
      ///
      /// @param [out] options / Scene's export resource options.
      //
      void getAllExportResourceOptions( const int& rsrcId, std::vector< std::string >& options );
      
      /// getExportResourceOptionValue:
      ///
      /// Returns the selected option for a scene export resource.
      /// For instance: "png" for EXPORT_PREVIEW
      ///
      /// @param [in] rsrcId / Scene 's resource Id.
      ///
      /// @return : Selected option for scene's export resource.
      //
      std::string getExportResourceOptionValue( const int& rsrcId );
      
      /// setExportResourceOptionValue:
      ///
      /// Changes the selected option for a scene export resource.
      /// For instance: "png" for EXPORT_PREVIEW
      ///
      /// @param [in] rsrcId / Scene 's resource Id.
      ///
      /// @param [in] newValue / The new value for the option.
      ///
      //
      void setExportResourceOptionValue( const int& rsrcId, const std::string& newValue );
      
      /// hasExportResource:
      ///
      /// Checks if the given resource id exists for the scene.
      ///
      /// @return : True if the resource id exists. False otherwise.
      //
      bool hasExportResource( const int& rsrcId );
      
      /// setExportAll:
      ///
      /// Changes the current export settings to export all the nodes in the scene.
      /// It is equivalent to clicking on Export->Export All.
      ///
      //
      void setExportAll( void );
      
      /// setExportNone:
      ///
      /// Changes the current export settings to stop exporting any file.
      /// It is equivalent to clicking on Export->Export None.
      ///
      //
      void setExportNone( void );
      
      /// setExportDefault:
      ///
      /// Changes the current export settings to export the default resources for scene
      /// nodes. Non-default resources that were already enabled remain with the same state.
      /// It is equivalent to clicking on Export->Export Default Files.
      //
      void setExportDefault( void );

      /// exportToXML:  
      ///
      /// Export scene nodes to a RealFlow XML file. 
      /// 
      /// @param [in] xmlPath. Path to the XML file that will be created. 
      /// @param [in] onlySelected. Export only selected nodes. 
      /// @param [in] exportSceneParams. Export scene parameters. 
      /// @param [in] exportNodeParams. Export node parameters. 
      /// @param [in] exportRecursively. Export unselected nodes that are linked to others selected. 
      /// @param [in] exportLinks. Export links. 
      /// @param [in] exportGlobalLinks. Export Global links. 
      /// @param [in] exportExclusiveLinks. Export Exclusive links. 
      /// @param [in] curvesAsFiles. Export curves as separate files. 
      /// @param [in] curvesFolderPath. Path to folder where save curve files. 
      /// @param [in] exportSelection. Export current selection status. 
      /// @param [in] exportSimulationEvents. Export Simulation Events status. 
      /// @param [in] exportLayers. Export scene layers. 
      /// @param [in] exportRetimer. Export scene retimer settings.
      /// @param [in] exportAlternativePaths. Export scene alternative paths.
      /// @param [in] absolutePaths. Export paths as absolute paths.
      //
      void exportToXML( const std::string& xmlPath, 
                        const bool& onlySelected         = false,
                        const bool& exportSceneParams    = false,
                        const bool& exportNodeParams     = true,
                        const bool& exportRecursively    = false,
                        const bool& exportLinks          = true,
                        const bool& exportGlobalLinks    = true,
                        const bool& exportExclusiveLinks = true,
                        const bool& curvesAsFiles        = false,
                        const std::string& curvesFolderPath = "$(XMLPATH)",
                        const bool& exportSelection        = true,
                        const bool& exportSimulationEvents = true,
                        const bool& exportLayers           = true,
                        const bool& exportRetimer          = true,
                        const bool& exportAlternativePaths = true,
                        const bool& absolutePaths          = false );

      
      /// importFromXML:  
      ///
      /// Export scene nodes to a RealFlow XML file. 
      /// 
      /// @param [in] xmlPath. Path to the XML file that will be parsed. 
      /// @param [in] createNodes. Create nodes missing on the scene. 
      /// @param [in] updateNodes. Update nodes with the same name on the scene. 
      /// @param [in] renameOnConflict. Rename nodes with the same name on the scene 
      ///             by adding the suffix "_xml". It only makes effect when creating nodes and 
      ///             not updating the existing ones. 
      /// @param [in] skipUnexpected. Skip unexpected tags when found. If set to false the XML
      ///             import process will stop whenever an unexpected tag is found.
      //
      void importFromXML( const std::string& xmlPath, 
                          const NL_BOOL& createNodes      = true,
                          const NL_BOOL& updateNodes      = true, 
                          const NL_BOOL& renameOnConflict = false,
                          const NL_BOOL& skipUnexpected   = false );
      
      /// importFromXML_string:
      ///
      /// Export scene nodes to a RealFlow XML string.
      ///
      /// @param [in] xmlString. XML code that will be parsed.
      /// @param [in] createNodes. Create nodes missing on the scene.
      /// @param [in] updateNodes. Update nodes with the same name on the scene.
      /// @param [in] renameOnConflict. Rename nodes with the same name on the scene
      ///             by adding the suffix "_xml". It only makes effect when creating nodes and
      ///             not updating the existing ones.
      /// @param [in] skipUnexpected. Skip unexpected tags when found. If set to false the XML
      ///             import process will stop whenever an unexpected tag is found.
      //
      void importFromXML_string( const std::string& xmlPath,
                                 const NL_BOOL& createNodes      = true,
                                 const NL_BOOL& updateNodes      = true,
                                 const NL_BOOL& renameOnConflict = false,
                                 const NL_BOOL& skipUnexpected   = false );
      
      /// getNBinaryLoaderSequences:
      ///
      /// Get the list of a representative frame of the binary sequences
      /// of the specified NBinary Loader Emitter. 
      /// 
      /// @param [in] emitter. NBinary Loader Emitter. 
      /// @param [out] sequences. List of file paths to the first frame
      ///              of every sequence of the NBinary Loader Emitter. 
      //
      void getNBinaryLoaderSequences( PB_Emitter& emitter, 
                                      std::vector< std::string >& sequencesList );
      
      /// addNBinaryLoaderSequence:  
      ///
      /// Adds a new binary sequence to the specified NBinary Loader Emitter.
      /// 
      /// @param [in] emitter. NBinary Loader Emitter. 
      /// @param [in] framePath. File path to a frame of the binary sequence. 
      //
      void addNBinaryLoaderSequence( PB_Emitter& emitter, 
                                     std::string& framePath );
      
      /// clearNBinaryLoaderSequences:
      ///
      /// Clear the specified NBinary Loader Emitter sequences list.
      /// 
      /// @param [in] emitter. NBinary Loader Emitter. 
      //
      void clearNBinaryLoaderSequences( PB_Emitter& emitter );
      
      /// sendToJobManager:  
      ///
      /// Sends the current scene to Job Manager using RealFlow Job Manager preferences
      ///
      /// @return : True if job has been sent properly. False otherwise.
      //
      bool sendToJobManager( void );
      
      /// sendPreviewToJobManager:
      ///
      /// Sends the current scene to Job Manager for a Maxwell Preview
      /// using RealFlow Job Manager preferences
      ///
      /// @return : True if job has been sent properly. False otherwise.
      //
      bool sendPreviewToJobManager( void );
      
      /// isCommandLineMode:  
      /// 
      /// Check if RealFlow is running under command line or GUI mode
      /// 
      /// @return : True if RealFlow is running on command line mode.
      //
      bool isCommandLineMode( void );

      /// enableDisplay:  
      //
      void enableDisplay( void );

      /// disableDisplay:  
      /// 
      //
      void disableDisplay( void );
      
      /// getSimulationLayers:  
      ///
      /// Get the list of Simulation Layers in the current Scene. 
      /// 
      /// @param [out] layers / Vector of Layers 
      //
      void getSimulationLayers( std::vector< Layer >& layers ); 
      
      /// getVisibilityLayers:  
      ///
      /// Get the list of Visibility Layers in the current Scene. 
      /// 
      /// @param [out] layers / Vector of Layers 
      //
      void getVisibilityLayers( std::vector< Layer >& layers ); 
      
      /// getSimulationLayer:  
      ///
      /// Get the Simulation Layer with the provided name. 
      ///
      /// @param [in] name. Simulation Layer name. 
      /// 
      /// @return : Simulation Layer matching the provided name.
      //
      Layer getSimulationLayer( const std::string& name ); 
      
      /// getVisibilityLayer:  
      ///
      /// Get the Visibility Layer with the provided name. 
      ///
      /// @param [in] name. Visibility Layer name. 
      /// 
      /// @return : Visibility Layer matching the provided name.
      //
      Layer getVisibilityLayer( const std::string& name ); 
      
      /// hasSimulationLayer:  
      ///
      /// Checks if a Simulation Layer with the provided name exists. 
      ///
      /// @param [in] name. Simulation Layer name. 
      /// 
      /// @return : True if simulation layer exists. False otherwise.
      //
      bool hasSimulationLayer( const std::string& name ); 
      
      /// hasVisibilityLayer:  
      ///
      /// Checks if a Visibility Layer with the provided name exists. 
      ///
      /// @param [in] name. Visibility Layer name. 
      /// 
      /// @return : True if visibility layer exists. False otherwise.
      //
      bool hasVisibilityLayer( const std::string& name ); 
      
      /// addSimulationLayer:  
      ///
      /// Adds a new Simulation Layer with the provided name. 
      ///
      /// @param [in] name. Simulation Layer name. 
      /// 
      /// @return : New Simulation Layer.
      //
      Layer addSimulationLayer( const std::string& name );       
      
      /// addVisibilityLayer:  
      ///
      /// Adds a new Visibility Layer with the provided name. 
      ///
      /// @param [in] name. Visibility Layer name. 
      /// 
      /// @return : New Visibility Layer.
      //
      Layer addVisibilityLayer( const std::string& name );       

      /// removeSimulationLayer:  
      ///
      /// Removes the Simulation Layer with the provided name. 
      ///
      /// @param [in] name. Simulation Layer name. 
      //
      void removeSimulationLayer( const std::string& name );       
      
      /// removeVisibilityLayer:  
      ///
      /// Removes the Visibility Layer with the provided name. 
      ///
      /// @param [in] name. Visibility Layer name. 
      //
      void removeVisibilityLayer( const std::string& name );      
      
      /// retimeWithCurrentSettings:  
      ///
      /// Launch the retiming process using the current scene settings for retiming.
      /// 
      //
      void retimeWithCurrentSettings( void ); 
      
      /// retimeNodes:  
      ///
      /// Launch the retiming process for the passed nodes and selected range. 
      ///
      /// @param [in] nodes. Nodes to retime. 
      ///
      /// @param [in] firstFrame. First frame of output sequence. 
      ///
      /// @param [in] lastFrame. Last frame of output sequence. 
      //
      void retimeNodes( const ArrSdkNodeAccesors& nodes, 
                        const int& firstFrame, const int& lastFrame );      
      
      /// retimerEnableNode:  
      ///
      /// Modify the retiming settings to enable the node. 
      ///
      /// @param [in] node. Node to enable for retiming. 
      ///
      //
      void retimerEnableNode( const NodeAccesor& node );
      
      /// retimerDisableNode:  
      ///
      /// Modify the retiming settings to disable the node. 
      ///
      /// @param [in] node. Node to disable for retiming. 
      ///
      //
      void retimerDisableNode( const NodeAccesor& node );      
      
      /// retimerReadSceneSD:  
      ///
      /// Modify the retiming settings to enable/disable 
      /// the Scene SD file read. 
      ///
      /// @param [in] enable. True to read from Scene SD. False otherwise. 
      ///
      //
      void retimerReadSceneSD( const bool& enable );      
      
      /// retimerWriteSceneSD:  
      ///
      /// Modify the retiming settings to enable/disable 
      /// the Scene SD file output. 
      ///
      /// @param [in] enable. True to write Scene SD. False otherwise. 
      ///
      //
      void retimerWriteSceneSD( const bool& enable );      
      
      /// retimerReadObjectFromSceneSD:  
      ///
      /// Modify the retiming settings to enable/disable 
      /// the object to be read from the Scene SD file. 
      ///
      /// @param [in] node. Object to enable/disable for Scene SD read. 
      ///
      /// @param [in] enable. True to read from Scene SD. False otherwise. 
      ///
      //
      void retimerReadObjectFromSceneSD( const NodeAccesor& node, const bool& enable );      
      
      /// retimerWriteObjectToSceneSD:  
      ///
      /// Modify the retiming settings to enable/disable 
      /// the object to be written to the Scene SD file. 
      ///
      /// @param [in] node. Object to enable/disable for Scene SD writting. 
      ///
      /// @param [in] enable. True to write to Scene SD. False otherwise. 
      ///
      //
      void retimerWriteObjectToSceneSD( const NodeAccesor& node, const bool& enable );      
      
      /// retimerSetNodeResource:  
      ///
      /// Modify the retiming settings to enable/disable the export of a node resource.
      ///
      /// @param [in] node. Node that owns the export resource.
      ///
      /// @param [in] resource. Export resource id. Depends on node type.
      ///
      /// @param [in] enable. True to enable resource export. False otherwise. 
      ///
      //
      void retimerSetNodeResource( const NodeAccesor& node, 
                                   const int& resource,
                                   const bool& enable );      
      
      /// retimerUseSceneFrameRange:  
      ///
      /// Modify the retiming settings to enable/disable the use of the scene range
      /// as the output range. 
      ///
      /// @param [in] enable. True to use the scene range. False to use a custom range. 
      ///
      //
      void retimerUseSceneFrameRange( const bool& enable );      
      
      /// retimerSetFrameRange:  
      ///
      /// Modify the retiming settings output frame range.
      ///
      /// @param [in] firstFrame. First frame of output sequence. 
      ///
      /// @param [in] lastFrame. Last frame of output sequence. 
      ///
      //
      void retimerSetFrameRange( const int& firstFrame, const int& lastFrame );      
      
      /// retimerSetAlternativePath:  
      ///
      /// Modify the retiming settings output alternative path.
      ///
      /// @param [in] path. Path to the alternative location to save the output files.
      ///                   If empty, the output location is the current folder.
      ///
      //
      void retimerSetAlternativePath( const std::string& path );
      
      /// retimerSetPathSuffix:  
      ///
      /// Modify the retiming settings output suffix path.
      ///
      /// @param [in] suffix. Suffix to add to the output location of the files.
      ///                     For example, it will create a subfolder into the 'particles'
      ///                     folder for the retimed fluids.
      ///
      //
      void retimerSetPathSuffix( const std::string& suffix );
      
      /// retimerSetFilePrefix:  
      ///
      /// Modify the retiming settings output files prefix.
      ///
      /// @param [in] prefix. Prefix to add at the beginning of the output file names.
      ///
      //
      void retimerSetFilePrefix( const std::string& prefix );      
      
      /// retimerSetFileSuffix:  
      ///
      /// Modify the retiming settings output files suffix.
      ///
      /// @param [in] suffix. Suffix to append at the end of the output file names, 
      ///                     before the frame number.
      ///
      //
      void retimerSetFileSuffix( const std::string& suffix );      
      
      /// retimerSetTimeFunction:  
      ///
      /// Modify the retiming settings time function.
      ///
      /// @param [in] curve. Curve to be copied to the retimer time function.
      ///
      //
      void retimerSetTimeFunction( const Curve& curve );      
      
      /// retimerSetExpression:  
      ///
      /// Modify the retiming settings time function expression.
      ///
      /// @param [in] expression. Expression to use for the time function.
      ///
      //
      void retimerSetExpression( const std::string& expression );      
      
      /// retimerSetTimeFactor:  
      ///
      /// Modify the retiming settings time factor.
      ///
      /// @param [in] factor. Time factor to apply at time function evaluation.
      ///
      //
      void retimerSetTimeFactor( const float& factor );      
      
      /// retimerEvaluateFunctionAsFrames:  
      ///
      /// Modify the retiming settings to evaluate the time function result as time or
      /// number of frame.
      ///
      /// @param [in] asFrames. True to evaluate function as frames. 
      ///                       False to evaluate as time.
      ///
      //
      void retimerEvaluateFunctionAsFrames( const bool& asFrames );      
      
      /// retimerSetInterpolationMethod:  
      ///
      /// Modify the retiming settings to evaluate the time function result as time or
      /// number of frame.
      ///
      /// @param [in] method. Valid methods are: INTERPOLATION_METHOD_NONE,
      ///                                        INTERPOLATION_METHOD_LINEAR,
      ///                                        INTERPOLATION_METHOD_CUBIC
      ///
      //
      void retimerSetInterpolationMethod( const int& method );      
      
      /// retimerSetFreezeDyingParticles:  
      ///
      /// Modify the retiming settings to freeze particles that 
      /// are dying at some time between the interpolated frames.
      ///
      /// @param [in] freeze. True to freeze the particle. False to let it keep moving.
      ///
      //
      void retimerSetFreezeDyingParticles( const bool& freeze );      
      
      /// retimerSetDyingParticlesKillTime:  
      ///
      /// Modify the retiming settings to set the amount of time a dying particle will
      /// keep moving using its latest force and velocity values.
      ///
      /// @param [in] time. 0.0 means kill at the beginning of the last frame it appears.
      ///                   1.0 means keep moving during all the interpolated frames.
      ///
      //
      void retimerSetDyingParticlesKillTime( const float& time );      
      
      /// retimerClearEnabledNodes:  
      ///
      /// Modify the retiming settings to clear the list of nodes enabled for retiming.
      ///
      //
      void retimerClearEnabledNodes( void );      
      
      /// retimerClearDisabledNodes:  
      ///
      /// Modify the retiming settings to clear the list of nodes disabled for retiming.
      ///
      //
      void retimerClearDisabledNodes( void );      
      
      /// retimerIsNodeEnabled:  
      ///
      /// Check if node is enabled for retiming in the current retimer settings. 
      ///
      /// @param [in] node. Node to check status. 
      ///
      /// @return : True if node is enabled for retiming. False otherwise.
      ///
      //
      bool retimerIsNodeEnabled( const NodeAccesor& node );
      
      /// retimerIsNodeDisabled:  
      ///
      /// Check if node is disabled for retiming in the current retimer settings. 
      ///
      /// @param [in] node. Node to check status. 
      ///
      /// @return : True if node is disabled for retiming. False otherwise.
      ///
      //
      bool retimerIsNodeDisabled( const NodeAccesor& node );
      
      /// retimerIsSceneSD_read:  
      ///
      /// Check if Scene SD file is enabled for reading in the current retimer settings. 
      ///
      /// @return : True if Scene SD is enabled for read. False otherwise.
      ///
      //
      bool retimerIsSceneSD_read( void );
      
      /// retimerIsSceneSD_written:  
      ///
      /// Check if Scene SD file is enabled for writting in the current retimer settings. 
      ///
      /// @return : True if Scene SD is enabled for writting. False otherwise.
      ///
      //
      bool retimerIsSceneSD_written( void );
      
      /// retimerIsObjectReadFromSceneSD:  
      ///
      /// Check if node cache is being read from the Scene SD file 
      /// in the current retimer settings. 
      ///
      /// @param [in] node. Node to check status. 
      ///
      /// @return : True if node is being read from the Scene SD file. False otherwise.
      ///
      //
      bool retimerIsObjectReadFromSceneSD( const NodeAccesor& node );
      
      /// retimerIsObjectWrittenToSceneSD:  
      ///
      /// Check if node cache is being written to the output Scene SD file 
      /// in the current retimer settings. 
      ///
      /// @param [in] node. Node to check status. 
      ///
      /// @return : True if node is being written to the Scene SD file. False otherwise.
      ///
      //
      bool retimerIsObjectWrittenToSceneSD( const NodeAccesor& node );

      /// retimerIsNodeResourceEnabled:  
      ///
      /// Check if node resource is enabled or disabled for retiming 
      /// in the current retimer settings. 
      ///
      /// @param [in] node. Node that owns the resource to check. 
      ///
      /// @param [in] resource. Id of resource to check. 
      ///
      /// @return : True if resource is enabled for retiming. False otherwise.
      ///
      //
      bool retimerIsNodeResourceEnabled( const NodeAccesor& node, const int& resource );
      
      /// retimerGetEnabledNodes:  
      ///
      /// Get the list of nodes enabled for retiming in the current retimer settings.
      /// 
      /// @param [out] outNodes / Vector of NodeAccesors 
      //
      void retimerGetEnabledNodes( ArrSdkNodeAccesors& outNodes ); 
      
      /// retimerGetDisabledNodes:  
      ///
      /// Get the list of nodes disabled for retiming in the current retimer settings.
      /// 
      /// @param [out] outNodes / Vector of NodeAccesors 
      //
      void retimerGetDisabledNodes( ArrSdkNodeAccesors& outNodes ); 
      
      /// retimerGetObjectsReadFromSceneSD:  
      ///
      /// Get the list of nodes that read their cache for retiming from the Scene SD file.
      /// 
      /// @param [out] outNodes / Vector of NodeAccesors 
      //
      void retimerGetObjectsReadFromSceneSD( ArrSdkNodeAccesors& outNodes ); 
      
      /// retimerGetObjectsWrittenToSceneSD:  
      ///
      /// Get the list of nodes that are written to the output Scene SD file on retiming.
      /// 
      /// @param [out] outNodes / Vector of NodeAccesors 
      //
      void retimerGetObjectsWrittenToSceneSD( ArrSdkNodeAccesors& outNodes ); 
      
      /// retimerGetNodeEnabledResources:  
      ///
      /// Get the list of resources enabled for retiming for an specific node.
      ///
      /// @param [in] node. Node to check resource status.  
      ///
      /// @return : Vector of enabled resource ids.
      //
      std::vector< int > retimerGetNodeEnabledResources( const NodeAccesor& node ); 
      
      /// retimerGetNodeDisabledResources:  
      ///
      /// Get the list of resources disabled for retiming for an specific node.
      ///
      /// @param [in] node. Node to check resource status.  
      ///
      /// @return : Vector of disabled resource ids.
      //
      std::vector< int > retimerGetNodeDisabledResources( const NodeAccesor& node ); 

      /// retimerIsUsingSceneFrameRange:  
      ///
      /// Check if the output frame range for retiming is the same as the scene frame range
      /// in the current retimer settings. 
      ///
      /// @return : True if scene range is being used. False otherwise.
      //
      bool retimerIsUsingSceneFrameRange( void ); 
      
      /// retimerGetFrameRange:  
      ///
      /// Get the current retimer settings output frame range.
      ///
      /// @return : Vector of 2 ints = [firstFrame, lastFrame].
      //
      std::vector< int > retimerGetFrameRange( void ); 
      
      /// retimerGetAlternativePath:  
      ///
      /// Get the retiming settings output alternative path. 
      ///
      /// @return :  Path to the alternative location to save the output files.
      ///            If empty, the output location is the current folder.
      //
      std::string retimerGetAlternativePath( void ); 
      
      /// retimerGetPathSuffix:  
      ///
      /// Get the retiming settings output suffix path. 
      ///
      /// @return :  Suffix to add to the output location of the files.
      ///            For example, it will create a subfolder into the 'particles'
      ///            folder for the retimed fluids.
      //
      std::string retimerGetPathSuffix( void ); 
      
      /// retimerGetFilePrefix:  
      ///
      /// Get the retiming settings output files prefix. 
      ///
      /// @return : Prefix to add at the beginning of the output file names.
      //
      std::string retimerGetFilePrefix( void ); 
      
      /// retimerGetFileSuffix:  
      ///
      /// Get the retiming settings output files suffix. 
      ///
      /// @return : Suffix to append at the end of the output file names, 
      ///           before the frame number.
      //
      std::string retimerGetFileSuffix( void ); 
      
      /// retimerCopyTimeFunctionToCurve:  
      ///
      /// Copy the retimer time function current setup to the passed existing Curve reference. 
      ///
      /// param [in,out] curve. Curve to overwrite with the retimer time function.
      //
      void retimerCopyTimeFunctionToCurve( Curve& curve ); 
      
      /// retimerGetExpression:  
      ///
      /// Get the expression property of the time function in the current retimer settings. 
      ///
      /// @return : Expression of the time function.
      //
      std::string retimerGetExpression( void ); 
      
      /// retimerGetTimeFactor:  
      ///
      /// Get the retiming settings time factor. 
      ///
      /// @return : Time factor value.
      //
      float retimerGetTimeFactor( void ); 
      
      /// retimerIsEvaluatingFunctionAsFrames:  
      ///
      /// Check if retimer time function is evaluated as frames or time.
      ///
      /// @return : True if time function is evaluated as frames. False if evaluated as time.
      //
      bool retimerIsEvaluatingFunctionAsFrames( void ); 
      
      /// retimerGetInterpolationMethod:  
      ///
      /// Get the interpolation method used for retiming.
      ///
      /// @return : Interpolation method identifier.
      //
      int retimerGetInterpolationMethod( void ); 
      
      /// retimerIsFreezingDyingParticles:  
      ///
      /// Check if particles dying between interpolated frames are frozen or keep moving.
      ///
      /// @return : True if dying particles remain frozen. False if keep moving.
      //
      bool retimerIsFreezingDyingParticles( void ); 
      
      /// retimerGetDyingParticlesKillTime:  
      ///
      /// Get the amount of time a dying particle will keep moving using its latest force
      /// and velocity values according to retimer settings.
      ///
      /// @return : 0.0 means kill at the beginning of the last frame it appears.
      ///           1.0 means keep moving during all the interpolated frames.
      //
      float retimerGetDyingParticlesKillTime( void ); 
      
      /// retimerEvaluateTimeFunction:  
      ///
      /// Get the retimer time function value at an specific time value.
      ///
      /// @param [in] time. Parameter to evaluate the function at.
      ///
      /// @param [in] applyTimeFactor. True to apply the time factor to 
      ///                              the time function evaluation.
      ///
      /// @return : The value of time function.
      //
      float retimerEvaluateTimeFunction( const float& time, const bool& applyTimeFactor ); 
      
      /// sceneRetimerNodeCanBeRetimed:  
      ///
      /// Check if node class can be retimed.
      ///
      /// @param [in] node. The node to check if retiming is possible.
      ///
      /// @return : True if retiming is available for the node type.
      //
      bool sceneRetimerNodeCanBeRetimed( const NodeAccesor& node ); 

      
      /// copyParameters:  
      ///
      /// Copy parameters from one node to another
      ///
      /// @param [in] node_from. The node where the parameters will be copied from.
      /// @param [in] node_to. The node where the parameters will be copied to.
      ///
      //
      void copyParameters(const NodeAccesor& node_from, const NodeAccesor& node_to);
      
      /// add_HY_Splash:
      ///
      /// Creates a new splash emitter and adds it to the current Scene
      ///
      /// @return a new splash emitter
      //
      HY_Splash add_HY_Splash( void );

      /// add_HY_Bubbles:
      ///
      /// Creates a new bubbles emitter and adds it to the current Scene
      ///
      /// @return a new bubbles emitter
      //
      HY_Bubbles add_HY_Bubbles( void );

      /// add_HY_BubblesAndFoam:
      ///
      /// Creates a new bubbles and foam emitter and adds it to the current Scene
      ///
      /// @return a new bubbles and foam emitter
      //
      HY_BubblesAndFoam add_HY_BubblesAndFoam( void );

      /// add_HY_SplashAndFoam:
      ///
      /// Creates a new splash and foam emitter and adds it to the current Scene
      ///
      /// @return a new splash and foam emitter
      //
      HY_SplashAndFoam add_HY_SplashAndFoam( void );

      /// add_HY_Foam:
      ///
      /// Creates a new foam emitter and adds it to the current Scene
      ///
      /// @return a new foam emitter
      //
      HY_Foam add_HY_Foam( void );

      /// add_HY_Waterline:
      ///
      /// Creates a new waterline emitter and adds it to the current Scene
      ///
      /// @return a new waterline emitter
      //
      HY_Waterline add_HY_Waterline( void );

      /// add_HY_WetAndFoam:
      ///
      /// Creates a new wet and foam emitter and adds it to the current Scene
      ///
      /// @return a new wet and foam emitter
      //
      HY_WetAndFoam add_HY_WetAndFoam( void );

      /// add_HY_Wet:
      ///
      /// Creates a new wet emitter and adds it to the current Scene
      ///
      /// @return a new wet emitter
      //
      HY_Wet add_HY_Wet( void );

      /// remove_HY_Splash:  
      ///
      /// Deletes a splash from the current Scene
      ///
      /// @param [in] name / Splash's name
      //
      void remove_HY_Splash( const std::string& name );

      /// remove_HY_Bubbles:  
      ///
      /// Deletes a bubbles emitter from the current Scene
      ///
      /// @param [in] name / Bubbles' name
      //
      void remove_HY_Bubbles( const std::string& name );

      /// remove_HY_BubblesAndFoam:  
      ///
      /// Deletes a bubbles and foam emitter from the current Scene
      ///
      /// @param [in] name / Bubbles and foam' name
      //
      void remove_HY_BubblesAndFoam( const std::string& name );

      /// remove_HY_SplashAndFoam:  
      ///
      /// Deletes a splash and foam from the current Scene
      ///
      /// @param [in] name / Splash and foam's name
      //
      void remove_HY_SplashAndFoam( const std::string& name );

      /// remove_HY_Foam:  
      ///
      /// Deletes a foam from the current Scene
      ///
      /// @param [in] name / Foam's name
      //
      void remove_HY_Foam( const std::string& name );

      /// remove_HY_Waterline:  
      ///
      /// Deletes a waterline from the current Scene
      ///
      /// @param [in] name / Waterline's name
      //
      void remove_HY_Waterline( const std::string& name );

      /// remove_HY_WetAndFoam:  
      ///
      /// Deletes a wet and foam from the current Scene
      ///
      /// @param [in] name / Wet and foam's name
      //
      void remove_HY_WetAndFoam( const std::string& name );

      /// remove_HY_Wet:  
      ///
      /// Deletes a wet from the current Scene
      ///
      /// @param [in] name / Wet's name
      //
      void remove_HY_Wet( const std::string& name );

      /// get_HY_Splashes:  
      ///
      /// Get the list of splashes. 
      /// 
      /// @param [out] splashes / List of splashes.
      //
      void get_HY_Splashes( std::vector<HY_Splash>& splashes );

      /// get_HY_SplashAndFoams:  
      ///
      /// Get the list of splash and foams. 
      /// 
      /// @param [out] splashAndFoams / List of splash and foams.
      //
      void get_HY_SplashAndFoams( std::vector<HY_SplashAndFoam>& splashAndFoams );

      /// get_HY_Foams:  
      ///
      /// Get the list of foams. 
      /// 
      /// @param [out] foams / List of foams.
      //
      void get_HY_Foams( std::vector<HY_Foam>& foams );

      /// get_HY_Bubbles:  
      ///
      /// Get the list of bubbles. 
      /// 
      /// @param [out] bubbles / List of bubbles.
      //
      void get_HY_Bubbles( std::vector<HY_Bubbles>& bubbles );

      /// get_HY_BubblesAndFoam:  
      ///
      /// Get the list of bubbles and foams. 
      /// 
      /// @param [out] bubblesAndFoams / List of bubbles and foams.
      //
      void get_HY_BubblesAndFoam( std::vector<HY_BubblesAndFoam>& bubblesAndFoams );

      /// get_HY_Waterlines:  
      ///
      /// Get the list of waterlines. 
      /// 
      /// @param [out] waterlines / List of waterlines.
      //
      void get_HY_Waterlines( std::vector<HY_Waterline>& waterlines );

      /// get_HY_WetAndFoams:  
      ///
      /// Get the list of wet and foams. 
      /// 
      /// @param [out] wetAndFoams / List of wet and foams.
      //
      void get_HY_WetAndFoams( std::vector<HY_WetAndFoam>& wetAndFoams );

      /// get_HY_Wets:  
      ///
      /// Get the list of wets. 
      /// 
      /// @param [out] wets / List of wets.
      //
      void get_HY_Wets( std::vector<HY_Wet>& wets );

      /// get_HY_Splash:  
      /// 
      /// Get the splash by name.
      /// 
      /// @param [in] name / Splash's name
      ///
      /// @return :
      ///           HY_Splash if found
      ///           HY_Splash( Null ) if there is no splash with such name
      //
      HY_Splash get_HY_Splash( const std::string& name );

      /// get_HY_SplashAndFoam:  
      /// 
      /// Get the splash and foam by name.
      /// 
      /// @param [in] name / Splash and foam's name
      ///
      /// @return :
      ///           HY_SplashAndFoam if found
      ///           HY_SplashAndFoam( Null ) if there is no splash and foam with such name
      //
      HY_SplashAndFoam get_HY_SplashAndFoam( const std::string& name );

      /// get_HY_Foam:  
      /// 
      /// Get the foam by name.
      /// 
      /// @param [in] name / Foams's name
      ///
      /// @return :
      ///           HY_Foam if found
      ///           HY_Foam( Null ) if there is no foam with such name
      //
      HY_Foam get_HY_Foam( const std::string& name );

      /// get_HY_Bubbles:  
      /// 
      /// Get the bubbles by name.
      /// 
      /// @param [in] name / Bubbles's name
      ///
      /// @return :
      ///           HY_Bubbles if found
      ///           HY_Bubbles( Null ) if there is no bubbles with such name
      //
      HY_Bubbles get_HY_Bubbles( const std::string& name );

      /// get_HY_BubblesAndFoam:  
      /// 
      /// Get the bubbles and foam by name.
      /// 
      /// @param [in] name / Bubbles and foam's name
      ///
      /// @return :
      ///           HY_BubblesAndFoam if found
      ///           HY_BubblesAndFoam( Null ) if there is no bubbles and foam with such name
      //
      HY_BubblesAndFoam get_HY_BubblesAndFoam( const std::string& name );

      /// get_HY_Waterline:  
      /// 
      /// Get the waterline by name.
      /// 
      /// @param [in] name / Waterline's name
      ///
      /// @return :
      ///           HY_Waterline if found
      ///           HY_Waterline( Null ) if there is no waterline with such name
      //
      HY_Waterline get_HY_Waterline( const std::string& name );

      /// get_HY_WetAndFoam:  
      /// 
      /// Get the wet and foam by name.
      /// 
      /// @param [in] name / Wet and foam's name
      ///
      /// @return :
      ///           HY_WetAndFoam if found
      ///           HY_WetAndFoam( Null ) if there is no wet and foam with such name
      //
      HY_WetAndFoam get_HY_WetAndFoam( const std::string& name );

      /// get_HY_Wet:  
      /// 
      /// Get the wet by name.
      /// 
      /// @param [in] name / Wet's name
      ///
      /// @return :
      ///           HY_Wet if found
      ///           HY_Wet( Null ) if there is no wet with such name
      //
      HY_Wet get_HY_Wet( const std::string& name );
      
      /// getCurrentViewportImage:  
      /// 
      /// Get the current OpenGL viewport image.
      /// 
      /// @param [out] image / The image to store the screenshot
      ///
      //
      void getCurrentViewportImage( nextlimit::rf_sdk::Image& image );
      
      /// exportCurrentFrame:
      ///
      /// Exports ALL the enabled resources on the Export Central
      /// the same way they would do during a simulation.
      /// This means that nodes in Cache state may not overwrite their data.
      ///
      //
      void exportCurrentFrame( void );

      
      /// executeCommand:
      ///
      /// Executes the RealFlow command with the Class ID specified.
      ///
      /// @param [in] classId / Command's Class ID
      ///
      //
      void executeCommand( const unsigned int& classId );
      
      /// hasCommand:
      ///
      /// Checks if RealFlow has a command with the input Class ID.
      ///
      /// @param [in] classId / Command's Class ID
      ///
      /// @return : True if the command is registered in RealFlow. False otherwise
      //
      bool hasCommand( const unsigned int& classId );
      
      
      /// getAlternativePaths:
      ///
      /// Get the list of the scene Alternative Paths.
      ///
      /// @param [out] pathsList. List of Alternative Paths.
      //
      void getAlternativePaths( std::vector< std::string >& pathsList );
      
      
      /// addAlternativePath:
      ///
      /// Adds a new Alternative Path to this scene.
      ///
      /// @param [in] path. The Alternative Path to be added. It cannot be empty.
      //
      void addAlternativePath( const std::string& path );
      

      /// addAlternativePaths:
      ///
      /// Adds new Alternative Paths to this scene.
      ///
      /// @param [in] pathsList. The Alternative Paths to be added.
      //
      void addAlternativePaths( const std::vector< std::string >& pathsList );
      
      
      /// clearAlternativePaths:
      ///
      /// Clear the current scene Alternative Paths list.
      ///
      //
      void clearAlternativePaths( void );
      
      
      /// getGeometryScale:
      ///
      /// Gets the Current Scene 's Scale
      ///
      /// @return : Current Scene 's Scale
      //
      float getGeometryScale();
      
      
      /// setGeometryScale:
      ///
      /// Sets the Current Scene 's Scale
      ///
      /// @param [in] scale / new current Scene 's Scale
      //
      void setGeometryScale( float scale );
      
      
      /// getCellSizeScale:
      ///
      /// Gets the Current Scene 's Cell Size Scale
      ///
      /// @return : Current Scene 's Cell Size Scale
      //
      float getCellSizeScale();
      
      
      /// setCellSizeScale:
      ///
      /// Sets the Current Scene 's Cell Size Scale
      ///
      /// @param [in] scale / new current Scene 's Cell Size Scale
      //
      void setCellSizeScale( float scale );
      
      
      /// getFluidDaemonForceScale:
      ///
      /// Gets the Current Scene 's Fluid Daemon Force Scale
      ///
      /// @return : Current Scene 's Fluid Daemon Force Scale
      //
      float getFluidDaemonForceScale();
      
      
      /// setFluidDaemonForceScale:
      ///
      /// Sets the Current Scene 's Fluid Daemon Force Scale
      ///
      /// @param [in] scale / new current Scene 's Fluid Daemon Force Scale
      //
      void setFluidDaemonForceScale( float scale );
      
      
      /// getObjectDaemonForceScale:
      ///
      /// Gets the Current Scene 's Object Daemon Force Scale
      ///
      /// @return : Current Scene 's Object Daemon Force Scale
      //
      float getObjectDaemonForceScale();
      
      
      /// setFluidDaemonForceScale:
      ///
      /// Sets the Current Scene 's Object Daemon Force Scale
      ///
      /// @param [in] scale / new current Scene 's Object Daemon Force Scale
      //
      void setObjectDaemonForceScale( float scale );
      
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      /// removeGlobalLink:  
      /// 
      /// Removes a global link from the current Scene for the given Node
      /// 
      /// @param [in] sdkObj / Node which global link is going to be removed
      //
      template <class Nat_T >
      void                    removeGlobalLinkRF( RFBaseObj<Nat_T>& sdkObj );

      void* createRFItem              ( sdk_type::SdkType itemType      , 
                                        const std::string& subTypeName  , 
                                        int detail1   = 0               ,
                                        int detail2   = 0               ,
                                        float detail3 = 0               ,
                                        const std::string& filePath = "" );

      void  destroyRFNode             ( const std::string& name );

      void* createRFItem_Mode_Gui     ( sdk_type::SdkType itemType      , 
                                        const std::string& subTypeName  , 
                                        int detail1   = 0               ,
                                        int detail12  = 0               ,
                                        float detail3 = 0               ,
                                        const std::string& filePath = ""  );


      void* createRFItem_Non_Mode_Gui ( sdk_type::SdkType itemType      , 
                                        const std::string& subTypeName  , 
                                        int detail1   = 0               ,
                                        int detail2   = 0               ,
                                        float detail3 = 0               ,
                                        const std::string& filePath = "");


      void initRFNative_Obj      ( RegularBody* nativeObjPtr              , 
                                          const std::string& subTypeName  , 
                                          int detail1   = 0               ,
                                          int detail2   = 0               ,
                                          float detail3 = 0                 );

      NL_INT getNativeObjSubtype ( const std::string& subTypeName );

      
      void sceneChanged( void );

      template <class RFType, class NativeType, sdk_type::SdkType type>
      RFType  addRFItem( const std::string& subType    , 
                         int initDetail1   = -1 , 
                         int initDetail2   = -1 ,
                         float initDetail3 = -1 ,
                         const std::string& filePath = "" );

      //
      nl::NL_RefTypeBase* createGlobalVariableValueAux( const std::string& nameVar  , 
                                                      nl::NL_RefTypeBase*          );

      //
      //void setGlobalVariableValueAux( const std::string& nameVar      , 
      //                                nl::NL_ClassTypeBase&  varValue   );

      //
      nl::NL_RefTypeBase* getGlobalVariableValueAux( const std::string& nameVar );

      //
      void removeGlobalVariableAux( const std::string& nameVar );


      //template <>
      //RFType* addRFItem<rf_sdk::PB_Particle, Particle, PARTICLE_TYPE>( std::string subType, int initDetail = 0 )
      //{

      //  // Create the Native Realflow object.
      //  NativeType* nativeObjPtr = (NativeType*) createRFItem( type, subType );

      //  if ( nativeObjPtr == NULL )
      //  {
      //    rfAppMngrInst->sendMessageId( MSG_ID_SCRIPT_VALUE, subType );
      //    return sceneReturn<RFType*>( NULL );
      //  }

      //  //Creates Wrp Wk Ptr
      //  PtrWrper_WkPtr<NativeType> nativeObjPtrWrp( nativeObjPtr );

      //  // Create the SDK Counterparty Object
      //  RFType* rfObj = new RFType( PtrWrper_WkPtr<NativeType>( nativeObjPtrWrp ) );
      //  rfObj->init( initDetail );

      //  // Update the interface and sets the scene dirty
      //  sceneChanged();

      //  return sceneReturn<RFType*>( rfObj );
      //};

      void removeRFItem( const std::string& name );
      
      // getRFItems
      template <class RFType_T, class NativeType, NL_UINT64 NATIVE_SUBTYPE_ID>
      void getRFItems( std::vector<RFType_T>& listRFItems );

      // getRFItem
      template <class RFType, class NativeType>
      RFType  getRFItem( const std::string& objName );

      // addRFGlobalLink
      template <class Nat_T>
      void addRFGlobalLink( RFBaseObj<Nat_T>& sdkObj );

      // getNodesAux
      void getNodesAux( ArrSdkNodeAccesors& outSdkNodeAccesors );
      
      // toNBinaryLoader
      Nodo* toNBinaryLoader( PB_Emitter& emitter );


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      AppManager* rfAppMngrInst;

      MapGlobalVars mapGlobalVars_;

      //
      nl::MutexRW* accsMutx_;
      

      friend class AppManager;
    };

    /*! \class Scene 
        \brief Class Scene
    
    <h2><a name="Examples"> <strong><em>Examples</em></strong> </a></h2>
    <p />
    <ul>
      <li> Example 1 <br><br>
      </li>
    </ul>
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
    <ul>
      <li> Example 2 <br><br>
      </li>
    </ul>
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
    <ul>
      <li> Example 3 <br><br>
      </li>
    </ul>
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
    <ul>
      <li> Example 4 <br><br>
      </li>
    </ul>
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
    <ul>
      <li> Example 5 <br><br>
      </li>
    </ul>
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
    <p />
    */
    // 

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_SCENE_H...


