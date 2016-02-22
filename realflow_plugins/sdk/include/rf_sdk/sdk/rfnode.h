
#ifndef _RF_NODE_H
#define _RF_NODE_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include <string>
#include <iostream>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfbaseobj.h"
#include "rf_sdk/sdk/curve.h"
#include "rf_sdk/sdk/vector.h"

// FORWARD DECLARATIONS
class Nodo;

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS

    namespace node_type
    {
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_NONE                     ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_CAMERA                   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_DAEMON                   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_OBJECT                   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_PB_EMITTER               ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_GB_EMITTER               ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_EMITTER               ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_FOAM                  ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_SPLASH_AND_FOAM       ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_SPLASH                ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_WATERLINE             ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_WET_AND_FOAM          ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_WET                   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_BUBBLES               ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_BUBBLES_AND_FOAM      ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_STANDARD_MESH            ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_PARTICLE_MESH_LEGACY     ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_CONSTRAINT               ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_GROUP                    ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_REALWAVE                 ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MIST                     ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_MIST                  ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_IDOC                     ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_GRID_MESH                ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_MESH                  ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_MESH_VDB              ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_RENDERKIT_MESH           ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_PARTICLE_MESH_VDB        ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_PARTICLE_MESH            ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_GRID_DOMAIN              ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_HY_DOMAIN                ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MULTIBODY                ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MULTIJOINT               ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MULTISERVO_POS_LINEAR    ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MULTISERVO_POS_ANGULAR   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MULTISERVO_VEL_LINEAR    ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_MULTISERVO_VEL_ANGULAR   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_SPLINE                   ;
      RF_SDK_EXPORTS_DLL_STATIC extern const NL_UINT64  TYPE_ALL                      ;
    };

    namespace nd_expt
    {

      static const bool EXPORT_RSRC_YES = true;
      static const bool EXPORT_RSRC_NO  = false;

      static const bool EXPORT_RSRC_IMG_YES = true;
      static const bool EXPORT_RSRC_IMG_NO  = false;

    };

    //-----------------------------------------------------------------------------------
    //
    // RFNode<T, false, false>:
    //
    //-----------------------------------------------------------------------------------
 //   template < bool EXPORT_RSRC = false, bool EXPORT_RSRC_IMG = false>
    class RF_SDK_EXPORTS_DLL Node : public RFBaseObj< ::Nodo >
    {

    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      //
      Node( ::Nodo* nativeObjPtr ) : RFBaseObj< ::Nodo>( nativeObjPtr ) {};

    public:
      /// Destructor
      //
      virtual ~Node( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getName:  
      ///
      /// Gets the Node 's name
      ///
      /// @return : Node 's name
      //
      virtual std::string getName() ;
      
      /// setName:  
      ///
      /// Sets the Node 's name
      ///
      /// @param [in] name / Node 's parameter name
      //
      virtual void  setName( const std::string newName );

      /// getParameterCurve:  
      ///
      /// Gets THIS Node 's curve for the parameter given( paramName )
      ///
      /// @return : Node 's curve for the parameter( paramName )
      Curve getParameterCurve( const std::string& paramName );

      /// toWorld:  
      ///
      /// Transforms Vector( vector ) with the "Local to World" transformation Matrix
      ///
      /// @param [in] vector / Vector to transform
      ///
      /// @return : Transformed Vector
      Vector toWorld( const Vector& vector );

      /// toLocal:  
      ///
      /// Transforms Vector( vector ) with the "World to Local" transformation Matrix
      ///
      /// @param [in] vector / Vector to transform
      ///
      /// @return : Transformed Vector
      Vector toLocal( const Vector& vector );

      /// getType:
      /// 
      /// Gets the type of this Realflow Node Object
      /// 
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) 
      { 
        NL_PURE_VIRTUAL; 
        return ( 0 );
      }

      // getParameterListStr
      //std::vector<std::string> getParameterListStr( const std::string& name );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper Operations:
      //  @{ 
    protected:

      // getSubclass
      virtual const int getSubclass( void );

    };

 //   typedef RFNode< nd_expt::EXPORT_RSRC_NO, nd_expt::EXPORT_RSRC_IMG_NO > Node;

    //-----------------------------------------------------------------------------------
    //
    // Node Export Resource
    //
    //-----------------------------------------------------------------------------------
 //  template <>
    class RF_SDK_EXPORTS_DLL Node_ExpRsc 
      : public Node
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

        /// Constructor
      Node_ExpRsc( ::Nodo* nativeObjPtr ) : Node( nativeObjPtr ) {};

    public:
        /// Destructor
        virtual ~Node_ExpRsc( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getExportResourcePath:  
      ///
      /// Gets the Node 's path for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Node 's resource Id
      ///                      Valid values are :
      ///                                         - EXPORT_TEXTURE
      ///                                         - EXPORT_DATA                                     
      ///
      /// @return : Node 's resource's path. Empty string ("") if the resource is not found
      //
      std::string getExportResourcePath( const int rsrcId );

      /// setExportResourcePath:  
      ///
      /// Sets the Node 's path for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Node 's resource Id
      ///                      Valid values are :
      ///                                         - EXPORT_TEXTURE
      ///                                         - EXPORT_DATA    
      /// @param [in] path / new Node 's path for resource ( rsrcId )  
      //
      void setExportResourcePath( const int rsrcId, const std::string path );

      /// getExportResourceName:  
      ///
      /// Gets the Node 's exported resource name. This is the name used for the root of the 
      /// file name exported for all resources in this object                                
      ///
      /// @return : Node 's resource name
      //
      std::string getExportResourceName( void );

      /// setExportResourceName:  
      ///
      /// Sets the Node 's exported resource name. This is the name used for the root of the 
      /// file name exported for all resources in this object 
      /// 
      /// @param [in] rsrcName / Node 's resource name
      //
      void setExportResourceName( const std::string& rsrcName );

      /// isExportResourceActive:  
      ///
      /// Gets the Node 's active state for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Node 's resource Id
      ///                      Valid values are :
      ///                                         - EXPORT_TEXTURE
      ///                                         - EXPORT_DATA                                     
      ///
      /// @return : True if the specific resource is active for exporting or False otherwise
      //
      bool isExportResourceActive( int rsrcId );

      /// activeExportResource:  
      ///
      /// Sets the Node 's active state for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Node 's resource Id
      ///                      Valid values are :
      ///                                         - EXPORT_TEXTURE
      ///                                         - EXPORT_DATA                                     
      /// @param [in] activate / True to activate the resource for exporting, False otherwise
      //
      void activeExportResource( const int rsrcId, const bool activate );

      /// isExportDataActive:  
      ///
      /// Gets the Node 's active state for exporting any kind of data.
      /// 
      /// @return : False if node data export is disabled. True otherwise
      //
      bool isExportDataActive( void );
      
      /// activeExportData:  
      ///
      /// Sets the Node 's active state for exporting data.
      /// 
      /// @param [in] activate / True to activate the node for exporting, False otherwise
      //
      void activeExportData( const bool activate );
      
      /// hasExportResource:
      ///
      /// Checks if the passed export resource Id is available for the node.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @return : True if the node has the input resource Id. False otherwise.
      //
      bool hasExportResource( const int rsrcId );
      
      /// getAllExportResourceIds:
      ///
      /// Returns the list of export resource Ids available for this node.
      ///
      /// @param [out] rsrcIds / Node 's resource Id list.
      //
      void getAllExportResourceIds( std::vector< int >& rsrcIds );
      
      /// getAllExportResourceValues:
      ///
      /// Returns the list of pairs with export resource Ids and their enabled/disabled state.
      ///
      /// @param [out] rsrcIds / Node 's resource Id list as a pair of:
      ///                     ( resource Id, enabled state )
      //
      void getAllExportResourceValues( std::vector< std::pair< int, bool > >& rsrcIds );
      
      /// getAllExportResourceOptions:
      ///
      /// Returns the list of options related to the given node's export resource.
      /// For example: Compression of an Alembic file.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @param [out] options / Node 's resource Id list of options.
      //
      void getAllExportResourceOptions( const int rsrcId,
                                            std::vector< std::string >& options );
      
      /// getAllExportResourceCheckOptions:
      ///
      /// Returns the list of check options related to the given node's export resource.
      /// For example: Channels from an Alembic particle file.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @param [out] checkOptions / Node 's resource Id list of check option tuples:
      ///                             ( check option name, check option state )
      //
      void getAllExportResourceCheckOptions( const int rsrcId,
                std::vector< std::pair< std::string, bool > >& checkOptions );

      /// getExportResourceIdDescription:
      ///
      /// Returns the description of the given node's export resource.
      /// For example: "Particle cache (*.bin)"
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @return : Node's export resource description.
      //
      std::string getExportResourceIdDescription( const int rsrcId );
      
      /// getExportResourceIdExtension:
      ///
      /// Returns the file extension of the given node's export resource.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @return : Node's export resource file extension.
      //
      std::string getExportResourceIdExtension( const int rsrcId );
      
      /// getExportResourceIdFromDescription:
      ///
      /// Returns the node's export resource Id for a given description.
      /// If it does not exist, returns -1
      ///
      /// @param [in] description / Node 's export resource description.
      ///
      /// @return : Node's export resource id of the resource with the matching description.
      //
      int getExportResourceIdFromDescription( const std::string& description );
      
      /// setExportResourceOptionValue:
      ///
      /// Changes the selected option of the given node's export resource.
      /// For instance: "No compression" in an Alembic file.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @param [in] value / The new option.
      ///
      //
      void setExportResourceOptionValue( const int rsrcId, const std::string& value );
      
      /// getExportResourceOptionValue:
      ///
      /// Returns the selected option of the given node's export resource.
      /// For instance: "No compression" in an Alembic file.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @return : The current option for the input export resource.
      ///
      //
      std::string getExportResourceOptionValue( const int rsrcId );
      
      /// setExportResourceCheckOptionValue:
      ///
      /// Changes the selected check option state of the given node's export resource.
      /// For instance: "Vorticity" to True in an Alembic particle file.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @param [in] checkOption / The check option name.
      ///
      /// @param [in] value / The check state of the check option.
      ///
      //
      void setExportResourceCheckOptionValue( const int rsrcId,
                                             const std::string& checkOption,
                                             const bool value );
      
      /// getExportResourceCheckOptionValue:
      ///
      /// Returns the selected check option state of the given node's export resource.
      /// For instance: "Vorticity" in an Alembic particle file.
      ///
      /// @param [in] rsrcId / Node 's resource Id.
      ///
      /// @param [in] checkOption / The check option name.
      ///
      /// @return The check state of the check option.
      ///
      //
      bool getExportResourceCheckOptionValue( const int rsrcId,
                                              const std::string& checkOption );
      
      /// reloadData:
      ///
      /// Reloads the simulation data of this node.
      /// If Export data is not enabled for the node, no files are written.
      ///
      //
      void reloadData( void );
      
    };

    //-----------------------------------------------------------------------------------
    //
    // RFNode<T, EXPORT_RSRC, true>:
    //
    //-----------------------------------------------------------------------------------
  //  template <>
    class RF_SDK_EXPORTS_DLL Node_ExpRsc_ExpRscImg : public Node_ExpRsc
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    protected:

      /// Constructor
      Node_ExpRsc_ExpRscImg( ::Nodo* nativeObjPtr ) : Node_ExpRsc( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~Node_ExpRsc_ExpRscImg( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getExportResourceImageFormat:  
      ///
      /// Gets the Node 's image format for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Node 's resource Id
      ///                      Valid values are : Unique valid value = EXPORT_TEXTURE                              
      ///
      /// @return : Image format used for the resource 
      ///           valid values are :
      ///                               - IMAGE_FORMAT_TGA
      ///                               - IMAGE_FORMAT_BMP
      ///                               - IMAGE_FORMAT_JPG                               
      //
      int getExportResourceImageFormat( const int rsrcId );

      /// setExportResourceImageFormat:  
      ///
      /// Sets the Node 's image format for a specific exported resource.
      /// 
      /// @param [in] rsrcId / Node 's resource Id
      ///                      Valid values are : Unique valid value = EXPORT_TEXTURE                              
      /// @param [in] imgFormat /  Image format used for the resource 
      ///                          valid values are :
      ///                                             - IMAGE_FORMAT_TGA
      ///                                             - IMAGE_FORMAT_BMP
      ///                                             - IMAGE_FORMAT_JPG                               
      //
      void setExportResourceImageFormat( const int rsrcId, const int imgFormat );

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_NODE_H...





