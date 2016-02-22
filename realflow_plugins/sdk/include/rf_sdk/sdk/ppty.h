
#ifndef _NL_SDK_PPTY_H
#define _NL_SDK_PPTY_H

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
#include "rf_sdk/sdk/vector.h"
#include "rf_sdk/sdk/color.h"
#include "rf_sdk/sdk/rfnode.h"

// FORWARD DECLARATIONS

namespace nextlimit
{
  namespace rf_sdk
  {

    template<class RF_NODE_TYPE, class SDK_NODE_BASE_TYPE > class RFNodeType;
  }

  class Ppty;
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
    // Ppty:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC Ppty
    {
    public:
        // Selection types for SDK user. 
        static const NL_UINT SELECTION_UNIQUE    = 1;
        static const NL_UINT SELECTION_MULTIPLE  = 2;

        // String/Folder/File selection type
        static const NL_UINT SELECTION_STRING = 0;
        static const NL_UINT SELECTION_FILE = 1;
        static const NL_UINT SELECTION_DIRECTORY = 2;

    public:

      static const Vector VectorMin;
      static const Vector VectorMax; 

    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Ppty( nl::Ppty* ppty );

    public:
      /// Destructor
      virtual ~Ppty( void );

      /// Cloner
      virtual nl::rf_sdk::Ppty* clone( void );

      /// Copy Constructor 
      Ppty( const nl::rf_sdk::Ppty& ppty );

    protected:
      /// Assignment operator disabled
      nl::rf_sdk::Ppty& operator = ( const nl::rf_sdk::Ppty& other );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      // Create Ppty (String, File or Directory)
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&  namePpty , 
          const std::string&  valuePpty ,
          const NL_UINT& selectionType = SELECTION_STRING
        );

      // Create Ppty
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&  namePpty     , 
          const char*  valuePpty                             
        );

      //
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&  namePpty                                , 
          const NL_INT&       valuePpty                               ,
          const NL_INT&       minValuePpty  = NL_minimum< NL_INT >()  ,      
          const NL_INT&       maxValuePpty  = NL_maximum< NL_INT >()
        );

      //
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&  namePpty                                  , 
          const NL_DOUBLE&    valuePpty                                 ,
          const NL_DOUBLE&    minValuePpty  = NL_minimum< NL_FLOAT >() ,      
          const NL_DOUBLE&    maxValuePpty  = NL_maximum< NL_FLOAT >()
        );

      //
      static nl::rf_sdk::Ppty createPpty
        ( 
        const std::string&  namePpty                                  , 
        const NL_FLOAT&    valuePpty                                  ,
        const NL_FLOAT&    minValuePpty  = NL_minimum< NL_FLOAT >()   ,      
        const NL_FLOAT&    maxValuePpty  = NL_maximum< NL_FLOAT >()
        );


      //
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&  namePpty                  , 
          const Vector&     valuePpty                 ,
          const Vector&     minValuePpty = VectorMin  ,
          const Vector&     maxValuePpty = VectorMax
        );

      //
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&    namePpty  , 
          const nl::rf_sdk::Color&  valuePpty            
        );

      //
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&  namePpty              , 
          const bool&     valuePpty
        );

      // array string
      static nl::rf_sdk::Ppty createPpty
        ( 
          const std::string&              namePpty , 
          const std::vector<std::string>& lstNames ,
          const std::vector<int>&         lstVals  
        );

      // objects selector
      static nl::rf_sdk::Ppty createPpty
        (
          const std::string& namePpty,
          const std::vector< std::string >& lstNodes,
          const NL_UINT& nodeTypes = node_type::TYPE_ALL,
          const NL_UINT& selectionType = SELECTION_UNIQUE
        );

      //
      const nl::Ppty& getNativePpty() const
      { 
        return *ppyt_;
      }

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

      nl::Ppty* ppyt_;
    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_PPTY_H...
