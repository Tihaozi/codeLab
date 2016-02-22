
#ifndef _NL_SDK_LAYER_H
#define _NL_SDK_LAYER_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include <vector>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include <rf_sdk/util/ptrwrprchkr.h>
#include "rf_sdk/sdk/rfsdklibdefs.h"

// FORWARD DECLARATIONS
namespace nextlimit
{
namespace layer
{
class SceneLayer;
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
    // Layer:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Layer
    {

      typedef nl::layer::SceneLayer NativeObjType ;
      
      // Property Ids
      static const int LAYER_PPTY_SIM_STATUS;
      static const int LAYER_PPTY_EXPORT_DATA;
      static const int LAYER_PPTY_VISIBILITY;
      static const int LAYER_PPTY_DISPLAY_MODE;
      static const int LAYER_PPTY_MAXWELL_VISIBILITY;

      // Property values
      static const int LAYER_PPTY_VISIBILITY_YES;
      static const int LAYER_PPTY_VISIBILITY_NO;

      static const int LAYER_PPTY_EXPORT_DATA_YES;
      static const int LAYER_PPTY_EXPORT_DATA_NO;

      static const int LAYER_PPTY_SIM_STATUS_INACTIVE;
      static const int LAYER_PPTY_SIM_STATUS_ACTIVE;
      static const int LAYER_PPTY_SIM_STATUS_CACHE;

      static const int LAYER_PPTY_DISPLAY_MODE_BBOX;
      static const int LAYER_PPTY_DISPLAY_MODE_WIREFRAME;
      static const int LAYER_PPTY_DISPLAY_MODE_FLAT_SHADED;
      static const int LAYER_PPTY_DISPLAY_MODE_SMOOTH_SHADED;

      static const int LAYER_PPTY_MAXWELL_VISIBILITY_YES;
      static const int LAYER_PPTY_MAXWELL_VISIBILITY_NO;
      static const int LAYER_PPTY_MAXWELL_VISIBILITY_SAME;
      
      

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Layer( NativeObjType* nativeObj ):nativeObj_( nativeObj ) {};

    public:
      /// Destructor
      virtual ~Layer( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getName:
      /// Get the layer's name
      /// @return THIS layer's name string
      std::string getName();

      /// setName:
      /// Set THIS layer's name string
      /// @param [in] exp / layer's name string
      void setName( const std::string& name );

      /// getMembers:
      /// Get THIS layer's members. 
      /// 
      /// @param [in] expandGroups / True to expand groups recursively.
      /// @param [out] members / layer members.
      void getMembers( bool expandGroups, ArrSdkNodeAccesors& members );

      /// addMember:
      /// Add a new member to THIS layer.
      /// @param [in] name / Name of the new member for the layer.
      void addMember( const std::string& name );

      /// clearMembers:
      /// Remove all the members of THIS layer. 
      void clearMembers( void );
      
      /// getProperties:
      /// Get all THIS layer's properties. 
      ///
      /// @param [out] properties / Vector of Tuples < Property id, Property value id >
      void getProperties( std::vector< std::pair< int, int > >& properties );
      
      /// getProperties:
      /// Get all THIS layer's properties. 
      ///
      /// @param [out] properties / Vector of Tuples < Property id, Property value as string >
      void getProperties( std::vector< std::pair< int, std::string > >& properties );
      
      /// getPropertyAsString:
      /// Get THIS layer's property value as a string for the passed property id. 
      ///
      /// @param [in] property / property id. 
      ///                        Valid values are LAYER_PPTY_SIM_STATUS,
      ///                                         LAYER_PPTY_EXPORT_DATA,
      ///                                         LAYER_PPTY_VISIBILITY,
      ///                                         LAYER_PPTY_DISPLAY_MODE,
      ///                                         LAYER_PPTY_MAXWELL_VISIBILITY,
      ///
      /// @return property string value as shown in RealFlow Layer panel
      std::string getPropertyAsString( const int property );
      
      /// getProperty:
      /// Get THIS layer's property value as a value id for the passed property id. 
      ///
      /// @param [in] property / property id. 
      ///                        Valid values are LAYER_PPTY_SIM_STATUS,
      ///                                         LAYER_PPTY_EXPORT_DATA,
      ///                                         LAYER_PPTY_VISIBILITY,
      ///                                         LAYER_PPTY_DISPLAY_MODE,
      ///                                         LAYER_PPTY_MAXWELL_VISIBILITY,
      ///
      /// @return property value id
      int getProperty( const int property );
      
      /// getVisible:
      /// Get THIS layer's visible property value as a value id. 
      /// It is a convenience method for getProperty( LAYER_PPTY_VISIBILITY ). 
      ///
      /// @return Visible value id
      int getVisible( void );
      
      /// getDisplayMode:
      /// Get THIS layer's display mode property value as a value id. 
      /// It is a convenience method for getProperty( LAYER_PPTY_DISPLAY_MODE ). 
      ///
      /// @return Display mode value id
      int getDisplayMode( void );
      
      /// getMaxwellRenderable:
      /// Get THIS layer's Maxwell Renderable property value as a value id. 
      /// It is a convenience method for getProperty( LAYER_PPTY_MAXWELL_VISIBILITY ). 
      ///
      /// @return Renderable value id
      int getMaxwellRenderable( void );
      
      /// getSimulationStatus:
      /// Get THIS layer's simulation status property value as a value id. 
      /// It is a convenience method for getProperty( LAYER_PPTY_SIM_STATUS ). 
      ///
      /// @return Simulation status value id
      int getSimulationStatus( void );
      
      /// getExportData:
      /// Get THIS layer's export data property value as a value id. 
      /// It is a convenience method for getProperty( LAYER_PPTY_EXPORT_DATA ). 
      ///
      /// @return Export data value id
      int getExportData( void );
      
      /// setProperty:
      /// Set THIS layer's property value for the passed property id. 
      ///
      /// @param [in] property / property id. 
      ///                        Valid values are LAYER_PPTY_SIM_STATUS,
      ///                                         LAYER_PPTY_EXPORT_DATA,
      ///                                         LAYER_PPTY_VISIBILITY,
      ///                                         LAYER_PPTY_DISPLAY_MODE,
      ///                                         LAYER_PPTY_MAXWELL_VISIBILITY,
      ///
      /// @param [in] value / property value id. 
      void setProperty( const int property, const int value );
      
      /// setVisible:
      /// Set THIS layer's visible value. 
      /// It is a convenience method for setProperty( LAYER_PPTY_VISIBILITY, value ). 
      ///
      /// @param [in] value / property value id. 
      void setVisible( const int value );
      
      /// setDisplayMode:
      /// Set THIS layer's display mode value. 
      /// It is a convenience method for setProperty( LAYER_PPTY_DISPLAY_MODE, value ). 
      ///
      /// @param [in] value / property value id. 
      void setDisplayMode( const int value );
      
      /// setMaxwellRenderable:
      /// Set THIS layer's Maxwell Renderable value. 
      /// It is a convenience method for setProperty( LAYER_PPTY_MAXWELL_VISIBILITY, value ). 
      ///
      /// @param [in] value / property value id. 
      void setMaxwellRenderable( const int value );
      
      /// setSimulationStatus:
      /// Set THIS layer's simulation status value. 
      /// It is a convenience method for setProperty( LAYER_PPTY_SIM_STATUS, value ). 
      ///
      /// @param [in] value / property value id. 
      void setSimulationStatus( const int value );
      
      /// setExportData:
      /// Set THIS layer's export data value. 
      /// It is a convenience method for setProperty( LAYER_PPTY_EXPORT_DATA, value ). 
      ///
      /// @param [in] value / property value id. 
      void setExportData( const int value );
      
      /// isSimulationLayer:
      /// Checks if THIS layer is a simulation layer. 
      ///
      /// @return True if layer belongs to simulation layers. False otherwise. 
      bool isSimulationLayer( void );      
      
      /// isVisibilityLayer:
      /// Checks if THIS layer is a visibility layer. 
      ///
      /// @return True if layer belongs to visibility layers. False otherwise. 
      bool isVisibilityLayer( void );      
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:
      
      PtrWrprChkr<NativeObjType>& getNativeObj()
      {
        return nativeObj_;
      }

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

      PtrWrprChkr<NativeObjType> nativeObj_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class RFSdkBasicLib;
      friend class Scene;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_CURVE_H...





