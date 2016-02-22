
#ifndef _NL_SDK_RF_IDOC_H
#define _NL_SDK_RF_IDOC_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// STANDARD INCLUDES
#include NL_BEGIN_DISABLE_WARNINGS
#include <vector>
#include NL_END_DISABLE_WARNINGS

// EXTERNAL INCLUDES

// LOCAL INCLUDES
  //  BASIC PROJ
#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"

//
// FORWARD DECLARATIONS
//
namespace nextlimit
{
  namespace realflow
  {
    class IDOC;
  }
}

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD REFERENCES
    class Scene;
    class NodeAccesor;

    //-----------------------------------------------------------------------------------
    //
    // Emitter:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC IDOC 
      : public RFNodeType< nl::rf::IDOC, nl::rf_sdk::Node >
    {

    public:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      IDOC( nl::rf::IDOC* nativeObjPtr ) 
        : RFNodeType< nl::rf::IDOC, nl::rf_sdk::Node >( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~IDOC( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE
      
      /// add:  
      ///
      /// Add a Node to THIS IDOC
      ///
      /// @param [in] name / Node 's name to be added
      void add( const std::string& name );
      
      /// remove:  
      ///
      /// Remove a Node from THIS IDOC
      ///
      /// @param [in] name / Node 's name to be removed
      void remove( const std::string& name );
      
      /// clear:  
      ///
      /// Remove all nodes from THIS IDOC
      ///
      void clear( void );
      
      /// update:  
      ///
      /// Update IDOC to add the nodes contained in its bounding box
      ///
      void update( void );
      
      /// sendToJobManager:  
      ///
      /// Send the IDOC to the Job Manager using RealFlow Job Manager preferences
      ///
      void sendToJobManager( void );
      
      /// getNodes:  
      ///
      /// Get the list of Nodes contained in THIS IDOC. 
      /// 
      /// @param [out] nodes / Vector of NodeAccesors 
      ///                     NodeAccesor is a wrapper to a Node object which type could be 
      ///                     any of  Emitter, Daemon, Mesh, Camera, Joint, Object and Group.
      ///                     To obtain the sdk object wrapped inside the NodeAccesor use the
      ///                     methods getType and asRFCamera, asMesh ... See NodeAccesor for more details.
      void getNodes( std::vector<NodeAccesor>& nodes );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_IDOC; };
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::IDOC_TYPE; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;
      friend class NodeAccesor;

    };

  }; // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_RF_IDOC_H...





