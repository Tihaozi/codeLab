
#ifndef _NL_SDK_GUI_FILE_PICKER_DIALOG_H
#define _NL_SDK_GUI_FILE_PICKER_DIALOG_H

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
    // GuiFilePickerDialog:
    //
    //-----------------------------------------------------------------------------------  
    class RF_SDK_EXPORTS_DLL GuiFilePickerDialog : public GuiDialog
    {

    public:
      enum OpType
      {
        FILE_PICKER_LOAD,
        FILE_PICKER_SAVE 
      };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor from void
      GuiFilePickerDialog( void );

      /// Destructor
      ~GuiFilePickerDialog( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operations:
      //  @{ 
    public:


      /// show: 
      ///     
      /// Show a dialog to browse for a file for either a load or save operation. Returns 
      /// the full path of the chosen file or empty if nothing is selected.
      ///
      /// @param [in] opType / type of the intended use of the file to select.
      ///                      Valid types are [ FILE_PICKER_LOAD
      ///                                        FILE_PICKER_SAVE ]
      /// 
      /// @param [in] fullPath_DefaultDir / Default directory to browse
      /// @param [in] filters / a string that may contains several filters separated by ';'
      ///                       for instance ; "*.bin;*.pd" shows the files that end in bin or pd
      /// @param [in] Title / Title for the dialog
      /// 
      /// @return : The full path of the file selected. Or "" if no file was selected
      //
      std::string show( const OpType&      opType              , 
                        const std::string& fullPath_DefaultDir ,
                        const std::string& filters             ,
                        const std::string  title                 ); 

    };


  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_GUI_FILE_PICKER_DIALOG_H...





