
#ifndef _NL_SDK_GUI_NODES_PICKER_DIALOG_H
#define _NL_SDK_GUI_NODES_PICKER_DIALOG_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/gui_dialog.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    //-----------------------------------------------------------------------------------
    //
    // GuiNodesPickerDialog:
    //
    //-----------------------------------------------------------------------------------  
    class RF_SDK_EXPORTS_DLL GuiNodesPickerDialog : public GuiDialog
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor from void
      GuiNodesPickerDialog( void );

      /// Destructor
      ~GuiNodesPickerDialog( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operations:
      //  @{ 
    public:

      /// show: 
      ///     
      /// Show a dialog with the list of nodes in the scene that meet the type requirement.
      /// The user then can select a subset of them. This subset will be returned in the nodes
      /// parameter.
      /// Several types can be specified at the same time using the or bitwise operator (|)
      ///
      /// @param [in] type / Node 's types - Valid types are [ TYPE_CAMERA
      ///                                                      TYPE_DAEMON
      ///                                                      TYPE_OBJECT
      ///                                                      TYPE_EMITTER
      ///                                                      TYPE_MESH
      ///                                                      TYPE_CONSTRAINT
      ///                                                      TYPE_GROUP
      ///                                                      TYPE_REALWAVE
      ///                                                      TYPE_ALL         ]
      /// 
      /// @param [out] nodes / Vector of NodeAccesors that represent the nodes selected by the user
      ///                     NodeAccesor is a wrapper to a Node object which type could be 
      ///                     any of  Emitter, Daemon, Mesh, Camera, Joint, Object and Group.
      ///                     To obtain the sdk object wrapped inside the NodeAccesor use the
      ///                     methods getType and asRFCamera, asMesh ... See NodeAccesor for more details.
      //
      void show( int type, ArrSdkNodeAccesors& nodes ); 

    };


  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_GUI_NODES_PICKER_DIALOG_H...





