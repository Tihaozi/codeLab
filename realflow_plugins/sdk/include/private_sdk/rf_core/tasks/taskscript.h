
#ifndef _TASK_SCRIPT_H
#define _TASK_SCRIPT_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#include <indexes/nl_index.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include NL_END_DISABLE_WARNINGS

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_core/rf_coredefs.h"
  //  REST

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

    //-----------------------------------------------------------------------------------
    //
    // TaskScript:
    //
    //-----------------------------------------------------------------------------------
    class RF_CORE_EXPORTS_DLL TaskScript
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      TaskScript( const std::string& idString ) : idString_( idString ) {};
      
      /// Destructor
      virtual ~TaskScript() {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// Execute task.
      virtual int run( void ) = 0;

      //Gets idString
      std::string getIdString() const { return idString_; };

      // getId
      NL_INDEX getId() const { return id_; }  ;

      // setId
      void setId( NL_INDEX id ) { id_ = id; }  ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      std::string idString_;
      NL_INDEX  id_;

    };

} // NameSpace NextLimit...
#endif // _TASK_SCRIPT_H...





