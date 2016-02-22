
#ifndef _NL_RFSDK_PLG_SDK_H
#define _NL_RFSDK_PLG_SDK_H

//BASIC INCLUDES
#include <core/nl_basic.h>
#include <indexes/nl_index.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <string>
#include NL_END_DISABLE_WARNINGS

// PROJECT INCLUDES
#include <rf_common/core/rf_basicdefs.h>

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_core/rf_coredefs.h"
  //  REST

// FORWARD REFERENCES
class QAction;
namespace nextlimit { namespace realflow { namespace graph { class RF_GraphScene; }}}
namespace nextlimit { namespace graph { class GraphLayout; }}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

    // FORWARD DECLARATIONS

  namespace rf_sdk
  {

    // FORWARD DECLARATION
    class PlgDescriptor;

    namespace plgsdk
    {
      RF_CORE_EXPORTS_DLL_STATIC extern const NL_INDEX32 UNUSED_PLG_ID;
    };

    //-----------------------------------------------------------------------------------
    //
    // PlgSdk:
    //
    //-----------------------------------------------------------------------------------
    class RF_CORE_EXPORTS_DLL PlgSdk
    {

    public:
      static const NL_INDEX32 SDK_VERSION = NL_INDEX32_NOT_FOUND;

    public:

      enum PlgSdk_Status
      {
        ST_LOADED    ,
        ST_UNLOADED  ,
        ST_READY     ,
        ST_ERROR 
      };

      //RF_CORE_EXPORTS_DLL_STATIC static const std::string DUMMY_PLG_ID;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    public:

      /// Constructor
      PlgSdk( ) : status_( PlgSdk::ST_ERROR )
      {
      }

      /// Destructor
      virtual ~PlgSdk() {}

      // Initialize plugin type:
      // - This is where the Properties of the type are initialized
      // - Global Vars may be initialized here
      virtual void initialize ( nl::rf_sdk::PlgDescriptor* plgDesc ) = 0;

      // Initialize plugin.
      // - If needed local vars are initialized here
      // - Global Vars may be initialized here. If same Global Vars are created for all plugins of
      //   the same type then the right place to be created is the method "initialize".
      //virtual void initPlg ( ) = 0;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // getNameId
      virtual std::string getNameId() const = 0;
      //{ 
      //  NL_PURE_VIRTUAL;
      //  return "";
      //}

      // getClassId
      virtual NL_INT32 getClassId() const = 0;

      // getSdkVersion
      virtual NL_INDEX32 getSdkVersion() const = 0;

      // Get plugin copyright policy
      virtual std::string getCopyRight() const = 0;

      // Get plugin long description
      virtual std::string getLongDescription() const = 0;

      // Get plugin short description
      virtual std::string getShortDescription() const = 0;

      // Set plugin copyright policy
      virtual void setCopyRight( const std::string& copyright ) 
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED( copyright );
      }
      
      // Set plugin long description
      virtual void setLongDescription( const std::string& longDescription ) 
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED( longDescription );
      }
      
      // Set plugin short description
      virtual void setShortDescription( const std::string& shortDescription )
      {
        NL_VARIABLE_MAYBE_NOT_REFERENCED( shortDescription );
      }
      
      // Is multithreading
      virtual bool isMT( void ) const { return NL_true; }

      // isEditable
      virtual NL_BOOL isEditable()
      {
        return ( NL_false );
      }

      // getCode
      virtual std::string getCode()
      {
        NL_ASSERT( isEditable() );
        NL_PURE_VIRTUAL_RETURN( std::string );
      }

      // setCode
      virtual void setCode(  const std::string& code ) 
      {
        NL_ASSERT( isEditable() );
        NL_PURE_VIRTUAL;
        NL_VARIABLE_MAYBE_NOT_REFERENCED( code );
      }

      // getGraphLayout
      virtual const nl::graph::GraphLayout& getGraphLayout( void ) const
      { 
        NL_PURE_VIRTUAL; 
        return ( *reinterpret_cast< nl::graph::GraphLayout* >( NULL ) );
      };

      // getGraph
      virtual const nl::rf::graph::RF_GraphScene& getGraph( void ) const
      {
        NL_PURE_VIRTUAL; 
        return ( *reinterpret_cast< nl::rf::graph::RF_GraphScene* >( NULL ) );
      }

      // refGraphLayout
      virtual nl::graph::GraphLayout& refGraphLayout( void )
      { 
        NL_PURE_VIRTUAL; 
        return ( *reinterpret_cast< nl::graph::GraphLayout* >( NULL ) ); 
      };

      // refGraph
      virtual nl::rf::graph::RF_GraphScene& refGraph( void )
      {
        NL_PURE_VIRTUAL; 
        return ( *reinterpret_cast< nl::rf::graph::RF_GraphScene* >( NULL ) );
      }

      /// getAction
      virtual QAction* getAction( void ) const
      {
        NL_PURE_VIRTUAL;
        return ( NULL );
      }


      // refreshCode
      virtual void refreshCode(  ) 
      {
      }
      
      // purgeMemory
      virtual void purgeMemory()
      {
      }
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @internal Operations:
      //  @{ 
    public:

      //
      PlgSdk::PlgSdk_Status getPlgStatus() const
      {
        return ( status_ );
      }

      //
      void setPlgStatus( const PlgSdk::PlgSdk_Status& status )
      {
        status_ = status;
      }

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @helper Operations:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      //
      PlgSdk::PlgSdk_Status status_;

    };

    //const ByteId PlgSdk::DUMMY_PLG_ID = ByteId();

  };

} // NameSpace NextLimit...
#endif // _NL_RFSDK_PLG_SDK_H...





