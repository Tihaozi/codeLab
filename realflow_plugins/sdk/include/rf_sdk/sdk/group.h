
#ifndef _NL_RFSDK_GROUP_H
#define _NL_RFSDK_GROUP_H

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
#include "rf_sdk/sdk/rfnodetype.h"
#include "rf_sdk/sdk/nodeaccesor.h"

// FORWARD DECLARATIONS
//

namespace nextlimit
{
  class MutexRW;

  namespace realflow
  {
    class Group;
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
    // Group:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Group : public RFNodeType< nl::rf::Group, nl::rf_sdk::Node >
    {

      typedef RFNodeType< nl::rf::Group, nl::rf_sdk::Node > ParentType;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Group( nl::rf::Group* nativeObjPtr );

    public:
      /// Destructor
      virtual ~Group( void );

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      // INTERFACE

      ///// getName:  
      /////
      ///// Gets the Group 's name
      /////
      ///// @return : Group 's name
      //std::string getName( void )
      //{
      //  return ParentType::getName();
      //}

      ///// setName:  
      /////
      ///// Sets the Group 's name
      /////
      ///// @param [in] name / New Group 's name
      //void setName( const std::string& name )
      //{        
      //  ParentType::setName( name );
      //}

      /// add:  
      ///
      /// Add a Node to THIS Group
      ///
      /// @param [in] name / Node 's name to be added
      void add( const std::string& name );

      /// remove:  
      ///
      /// Remove a Node from THIS Group
      ///
      /// @param [in] name / Node 's name to be removed
      void remove( const std::string& name );

      /// getNodes:  
      ///
      /// Get the list of Nodes grouped under THIS group. 
      /// 
      /// @param [out] nodes / Vector of NodeAccesors 
      ///                     NodeAccesor is a wrapper to a Node object which type could be 
      ///                     any of  Emitter, Daemon, Mesh, Camera, Joint, Object and Group.
      ///                     To obtain the sdk object wrapped inside the NodeAccesor use the
      ///                     methods getType and asRFCamera, asMesh ... See NodeAccesor for more details.
      void getNodes( std::vector<NodeAccesor>& nodes );

      /// getType:
      /// 
      /// Gets the type of this Realflow Node Object
      /// 
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_GROUP; } ;

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    public:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::GROUP_TYPE; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    protected:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @friend Classes :
      //  @{ 
    private:

      friend class Scene;
      friend class NodeAccesor;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _RF_WAVE_H...





