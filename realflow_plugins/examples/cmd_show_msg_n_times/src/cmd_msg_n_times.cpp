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


#include <iostream>
#include <sstream>
#include <string>

#include <rf_sdk/sdk/appmanager.h>
#include <rf_sdk/sdk/scene.h>
#include <rf_sdk/tasks/cmdplgsdk.h>
#include <rf_sdk/sdk/ppty.h>
#include <rf_sdk/sdk/plgdescriptor.h>
#include <rf_sdk/sdk/rfsdklibdefs.h>
#include <rf_sdk/sdk/sdkversion.h>

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace nextlimit::rf_sdk;

/////////////////////////////////////////////////////////////////////////////////////////

class CmdMssgNTimes : public CmdPlgSdk
{
  enum StyleMsg
  {
    STYLE_MSG_NBD         ,
    STYLE_MSG_QTD         ,
    STYLE_MSG_NBD_AND_QTD
  };

  public:

    /// Constructor.
    CmdMssgNTimes() {};

    /// Destructor.
    virtual ~CmdMssgNTimes( void ) {};

    /// Class id.
    virtual NL_INT32 getClassId() const 
    { 
      return ( 1863453809 );
    };

    // getSdkVersion
    virtual NL_INDEX32 getSdkVersion() const
    {
      return ( SdkVersion::SDK_VERSION );
    }

    /// Get plugin name.
    virtual std::string getNameId() const 
    { 
      return ( "CmdMssgNTimes" ); 
    };

    // getCopyRight()
    virtual std::string getCopyRight() const
    {
      return std::string( "Copyright (C) 2008 Next Limit Technologies. All rights reserved." );
    }

    // getCopyRight()
    virtual std::string getLongDescription() const
    {
      return std::string( "Show a message n times." );
    }

    // getCopyRight()
    virtual std::string getShortDescription() const
    {
      return std::string( "Show a message n times." );
    }

    /// Initialize plugin, add properties, etc.
    virtual void initialize( PlgDescriptor* plgDesc )
    {
      Ppty nTimes = Ppty::createPpty( "nTimes", 2 );  
      plgDesc->addPpty( nTimes );

      Ppty msg = Ppty::createPpty( "Msg", " RealFlow 2012 is Here !!" );  
      plgDesc->addPpty( msg );

      std::vector<std::string> lstNames;
      lstNames.push_back( "Numbered" );
      lstNames.push_back( "Quoted" );
      lstNames.push_back( "Numbered & Quoted" );

      std::vector<int> lstValues;
      lstValues.push_back( STYLE_MSG_NBD         );
      lstValues.push_back( STYLE_MSG_QTD         );
      lstValues.push_back( STYLE_MSG_NBD_AND_QTD );

      Ppty styleMsg = Ppty::createPpty( "MsgStyle", lstNames, lstValues );  
      plgDesc->addPpty( styleMsg );
    }

    // run
    virtual void run ( Cmd* rfEvntCmd )
    {
      int nTimes      = rfEvntCmd->getParameter<int>( "nTimes" );
      std::string msg = rfEvntCmd->getParameter<std::string>( "Msg" );
      int styleMsg    = rfEvntCmd->getParameter<int>( "MsgStyle" );

      Scene& scene =  AppManager::instance()->getCurrentScene();

      std::stringstream mssg;
      for ( int times = 0; times < nTimes; times++ )
      {
        switch ( styleMsg )
        {
          case STYLE_MSG_NBD:
            mssg << msg << times;
        	break;

          case STYLE_MSG_QTD:
            mssg << "\"" << msg << "\"";
          break;

          case STYLE_MSG_NBD_AND_QTD:
            mssg << "\"" << msg << "\"" << times;
          break;

          default:
            mssg << "Plugin Internal Error!!";
          break;
        }

        scene.message( mssg.str() );
        mssg.str("");
      }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_CMD_PLUGIN( CmdMssgNTimes );

/////////////////////////////////////////////////////////////////////////////////////////
