/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2008 Next Limit Technologies. All rights reserved.
//
// This file is just part of the C++ SDK examples provided with RealFlow(c).
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <rf_sdk/sdk/appmanager.h>
#include <rf_sdk/sdk/scene.h>
#include <rf_sdk/sdk/vector.h>
#include <rf_sdk/sdk/daemon.h>
#include <rf_sdk/sdk/ppty.h>
#include <rf_sdk/sdk/plgdescriptor.h>
#include <rf_sdk/objects/objectplgsdk.h>
#include <rf_sdk/sdk/rfsdklibdefs.h>
#include <rf_sdk/sdk/sdkversion.h>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace nextlimit::rf_sdk;

/////////////////////////////////////////////////////////////////////////////////////////

class ObjectPptiesSDK : public ObjectPlgSdk
{
  public:

    /// Constructor.
    ObjectPptiesSDK() {};

    /// Destructor.
    virtual ~ObjectPptiesSDK( void ) {};

    /// Class id.
    virtual NL_INT32 getClassId() const
    { 
      return ( 1593454072 );
    };

    // getSdkVersion
    virtual NL_INDEX32 getSdkVersion() const
    {
      return ( SdkVersion::SDK_VERSION );
    }

    /// Get plugin name.
    virtual std::string getNameId() const
    { 
      return ( "ObjectPpties" ); 
    };

    // getCopyRight()
    virtual std::string getCopyRight() const
    {
      return std::string( "Copyright (C) 2008 Next Limit Technologies. All rights reserved." );
    }

    // getCopyRight()
    virtual std::string getLongDescription() const
    {
      return std::string( "Object with user defined properties." );
    }

    // getCopyRight()
    virtual std::string getShortDescription() const
    {
      return std::string( "Object with properties." );
    }


    /// Initialize plugin, add properties, etc.
    virtual void initialize( PlgDescriptor* plgDesc )
    {
      Ppty factor = Ppty::createPpty( "Factor", 1.5f );  
      plgDesc->addPpty( factor );
    }
};

/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_OBJECT_PLUGIN( ObjectPptiesSDK );

/////////////////////////////////////////////////////////////////////////////////////////

