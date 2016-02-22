
#ifndef _NL_SDK_RF_MULTISERVO_POS_ANGULAR_H
#define _NL_SDK_RF_MULTISERVO_POS_ANGULAR_H

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
//#include "rf_sdk/rf_sdkdefs.h"
  //  REST"
#include "rf_sdk/sdk/rfsdklibdefs.h"
#include "rf_sdk/sdk/rfnodetype.h"
//#include "rf_sdk/sdk/pb_particle.h"
#include "rf_sdk/sdk/vertex.h"
#include "rf_sdk/sdk/face.h"

//
// FORWARD DECLARATIONS
//
namespace nextlimit
{
  namespace realflow
  {
    class MultiServo_PosAngular;
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
    // MultiServo_PosAngular:
    //
    //-----------------------------------------------------------------------------------
    class RF_SDK_EXPORTS_DLL_STATIC MultiServo_PosAngular 
      : public RFNodeType< nl::rf::MultiServo_PosAngular, nl::rf_sdk::Node_ExpRsc >
    {

    public:
    
      ///////////////////////////////////////////////////////////////////////////////////
      //  @
      //! @name Life Cycle:
      //  @{ 
    private:

      /// Constructor
      MultiServo_PosAngular( nl::rf::MultiServo_PosAngular* nativeObjPtr ) 
        : RFNodeType< nl::rf::MultiServo_PosAngular, nl::rf_sdk::Node_ExpRsc >( nativeObjPtr ) {};

    public:
      /// Destructor
      virtual ~MultiServo_PosAngular( void ) {};


      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Operations:
      //  @{ 
    public:

      /// INTERFACE

      /// sdkExport:  
      /// Write out all the resources that are active in the export central menus.
      void sdkExport( void );

      /// getType:  
      /// Gets the type of this Realflow Node Object
      /// @return the type of this RealFlow Object
      virtual const NL_UINT64 getType( void ) { return node_type::TYPE_MULTISERVO_POS_ANGULAR; };


	  void create ( void );
      
      ///////////////////////////////////////////////////////////////////////////////////
      //  @}
      //! @name Helper methods
      //  @{ 
    protected:

      // getSdkType
      virtual sdk_type::SdkType getSdkType( void ) { return sdk_type::MULTISERVO_POS_ANGULAR_TYPE; };

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
#endif // _NL_SDK_RF_MULTISERVO_POS_ANGULAR_H...





