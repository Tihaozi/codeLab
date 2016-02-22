
#ifndef _NL_SDK_GUI_MESSAGE_DIALOG_H
#define _NL_SDK_GUI_MESSAGE_DIALOG_H

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
    // GuiMessageDialog:
    //
    //-----------------------------------------------------------------------------------  
    class RF_SDK_EXPORTS_DLL GuiMessageDialog : public GuiDialog
    {

    public:

      enum AlertTypes
      {
        ALERT_TYPE_WARNING    ,
        ALERT_TYPE_INFORMATION,
        ALERT_TYPE_CRITICAL    
      };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor from void
      GuiMessageDialog( void );

      /// Destructor
      ~GuiMessageDialog( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operations:
      //  @{ 
    public:

      /// show: 
      ///     
      /// Show a modal dialog with a message.
      /// 
      /// @param [in] alertType / Message 's type - Valid types are [ ALERT_TYPE_WARNING
      ///                                                             ALERT_TYPE_INFORMATION
      ///                                                             ALERT_TYPE_CRITICAL     ]
      /// 
      /// @param [in] msg / Message to be shown.
      //
      void show(  const AlertTypes& alertType, const std::string& msg ); 

    };


  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_GUI_MESSAGE_DIALOG_H...





