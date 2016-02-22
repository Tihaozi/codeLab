
#ifndef _NL_SDK_GUI_FORM_DIALOG_H
#define _NL_SDK_GUI_FORM_DIALOG_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/gui_dialog.h"
#include "rf_sdk/sdk/vector.h"

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  // FORWARD REFERENCES
  class PptysSet;

  namespace rf_sdk
  {

    //FORWARD REFERENCES


    //-----------------------------------------------------------------------------------
    //
    // GuiFilePickerDialog:
    //
    //-----------------------------------------------------------------------------------  
    class RF_SDK_EXPORTS_DLL GuiFormDialog : public GuiDialog
    {

    public:
      enum OpResult
      {
        GUI_DIALOG_REJECTED,
        GUI_DIALOG_ACCEPTED
      };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor from void
      GuiFormDialog( void );

      /// Destructor
      ~GuiFormDialog( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Operations:
      //  @{ 
    public:

      /// getFieldValue:  
      /// 
      /// Get the value for the field given.
      /// 
      /// @param [in] nameField / Field 's name.
      /// 
      /// @return : Field 's value
      //
      template< class T_FIELD >
      T_FIELD getFieldValue( const std::string& nameFld );

      /// addIntField:  
      /// 
      /// Add a integer type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addIntField( const std::string& nameField, const int& value );

      /// addIntField:  
      /// 
      /// Add a float type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addFloatField( const std::string& nameField, const float& value );

      /// addStringField:  
      /// 
      /// Add a string type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addStringField( const std::string& nameField, const std::string& value );

      /// addFileField:  
      /// 
      /// Add a File type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addFileField( const std::string& nameField, const std::string& value );

      /// addDirectoryField:  
      /// 
      /// Add a Directory type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addDirectoryField( const std::string& nameField, const std::string& value );

      /// addObjectField:  
      /// 
      /// Add a object type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] selection_types / 
      /// @param [in] selection_quantity / 
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addObjectField( const std::string& nameField, int seletion_types, int selection_quantity );

      /// addBoolField:  
      /// 
      /// Add a boolean type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addBoolField( const std::string& nameField, const bool& value );

      /// addListField:  
      /// 
      /// Add a list type field to the form
      /// 
      /// @param [in] nameField   / Field 's name. It must be unique within a form.
      /// @param [in] lstNames    / Vector of strings with the options names
      /// @param [in] initialPos  / Index for the default selected option starting at 0 
      ///                           for the first option.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addListField( const std::string& nameField             , 
                         const std::vector<std::string>& lstNames ,
                         const NL_INT& initialPos                   );

      /// addListField:  
      /// 
      /// Add a list type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] lstNames  / Vector of strings with the options names
      /// @param [in] lstVals   / Vector integer values associated to the options defined 
      ///                         in lstNames. 
      ///                     
      /// @param [in] initialPos / Index for the default selected option starting at 0 
      ///                          for the first option.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addListField( const std::string& nameField             , 
                         const std::vector<std::string>& lstNames ,
                         const std::vector<int>& lstVals          ,
                         const NL_INT& initialPos                   );

      /// addBoolField:  
      /// 
      /// Add a vector type field to the form
      /// 
      /// @param [in] nameField / Field 's name. It must be unique within a form.
      /// @param [in] value     / Initial value.
      /// 
      /// @return : True if the field was successfully added, False otherwise.
      //
      bool addVectorField( const std::string& nameField, const Vector& value );


      /// hasField:  
      ///
      /// Tests whether this form has this field or not.
      ///
      /// @param [in] nameField / Field 's name
      ///
      /// @return : true if the field is defined, false otherwise
      //  
      bool hasField( const std::string& nameField );

      /// show: 
      ///     
      /// Show the dialog and wait until the OK or Cancel buttons are pressed 
      /// or until the dialog is dismissed using the ESC key.
      /// 
      /// @return : GUI_DIALOG_ACCEPTED if the user pressed the OK button,
      ///           GUI_DIALOG_REJECTED if the user pressed the Cancel button or the ESC key was hit.       
      //
      OpResult show(); 

      /// setTitle:
      /// 
      /// Set the title of the dialog
      ///
      void setTitle( const std::string& title);

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:

      PptysSet* pptysSet_;

      // dialog title
      std::string title_;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

    };


  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_GUI_FORM_DIALOG_H...





