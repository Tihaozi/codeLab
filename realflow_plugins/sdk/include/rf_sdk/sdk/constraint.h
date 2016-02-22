
#ifndef _NL_SDK_CONSTRAINT_H
#define _NL_SDK_CONSTRAINT_H

// BASIC INCLUDES
#include <core/nl_basic.h>
#pragma NL_VERBOSE_HEADER_FILE

// EXTERNAL INCLUDES

// LOCAL INCLUDES
#include "rf_sdk/rf_sdkdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"

// FORWARD DECLARATIONS
class Joint;

// NextLimit NameSpace
// NextLimit NameSpace
// NextLimit NameSpace
namespace nextlimit
{

  namespace rf_sdk
  {

    // FORWARD DECLARATIONS
    class Scene;
    class NodeAccesor;

    //-----------------------------------------------------------------------------------
    //
    // Joint:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL Joint : public RFNodeType< ::Joint, nl::rf_sdk::Node >
    {

      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      Joint( ::Joint* nativeObjPtr ) : RFNodeType< ::Joint, nl::rf_sdk::Node >( nativeObjPtr ) {};

    public:

      /// Destructor
      virtual ~Joint( void ) {};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_CONSTRAINT;};

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::CONSTRAINT_TYPE; };

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Data Members:
      //  @{ 
    private:

      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @ friend Classes:
      //  @{ 
    private:

      friend class Scene;
      friend class NodeAccesor;

    };

  } // NameSpace rf_sdk...
} // NameSpace NextLimit...
#endif // _NL_SDK_CONSTRAINT_H...





