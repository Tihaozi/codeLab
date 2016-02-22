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

class CmdCreateGeometry : public CmdPlgSdk
{
  enum StyleMsg
  {
    STYLE_MSG_NBD         ,
    STYLE_MSG_QTD         ,
    STYLE_MSG_NBD_AND_QTD
  };

  public:

    /// Constructor.
    CmdCreateGeometry() {};

    /// Destructor.
    virtual ~CmdCreateGeometry( void ) {};

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
      return ( "CmdCreateGeometry" ); 
    };

    // getCopyRight()
    virtual std::string getCopyRight() const
    {
      return std::string( "Copyright (C) 2014 Next Limit Technologies. All rights reserved." );
    }

    // getCopyRight()
    virtual std::string getLongDescription() const
    {
      return std::string( "" );
    }

    // getCopyRight()
    virtual std::string getShortDescription() const
    {
      return std::string( "" );
    }

    /// Initialize plugin, add properties, etc.
    virtual void initialize( PlgDescriptor* plgDesc )
    {
      Ppty cubes = Ppty::createPpty( "Cubes", 10 );  
      plgDesc->addPpty( cubes );

      Ppty offset = Ppty::createPpty( "Offset", Vector( 1.0f, 1.0f, 1.0f ) );  
      plgDesc->addPpty( offset );

    }

    // createCube
    void createCube( const Vector& position )
    {
      Scene& scene =  AppManager::instance()->getCurrentScene();
      
      std::vector< Vertex > vertices;
      vertices.push_back( Vertex( Vector( -0.5f, -0.5f, -0.5f ) ) );
      vertices.push_back( Vertex( Vector( 0.5f, -0.5f, -0.5f ) ) );
      vertices.push_back( Vertex( Vector( 0.5f, -0.5f, 0.5f ) ) );
      vertices.push_back( Vertex( Vector( -0.5f, -0.5f, 0.5f ) ) );
      vertices.push_back( Vertex( Vector( -0.5f, 0.5f, -0.5f ) ) );
      vertices.push_back( Vertex( Vector( 0.5f, 0.5f, -0.5f ) ) );
      vertices.push_back( Vertex( Vector( 0.5f, 0.5f, 0.5f ) ) );
      vertices.push_back( Vertex( Vector( -0.5f, 0.5f, 0.5f ) ) );

      std::vector< Face > faces;
      faces.push_back( Face( 1, 2, 0 ) );
      faces.push_back( Face( 2, 3, 0 ) );
      faces.push_back( Face( 6, 5, 4 ) );
      faces.push_back( Face( 7, 6, 4 ) );
      faces.push_back( Face( 5, 1, 0 ) );
      faces.push_back( Face( 4, 5, 0 ) );
      faces.push_back( Face( 6, 2, 1 ) );
      faces.push_back( Face( 5, 6, 1 ) );
      faces.push_back( Face( 7, 3, 2 ) );
      faces.push_back( Face( 6, 7, 2 ) );
      faces.push_back( Face( 4, 0, 3 ) );
      faces.push_back( Face( 7, 4, 3 ) );

      std::vector< Vector > txt( 3 );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 0.0f, 0.0f );
      faces[ 0 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 0.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 1.0f, 0.0f );
      faces[ 1 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 0.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 1.0f, 0.0f );
      faces[ 2 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 0.0f, 1.0f, 0.0f );
      faces[ 3 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 0.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 1.0f, 0.0f );
      faces[ 4 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 0.0f, 1.0f, 0.0f );
      faces[ 5 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 0.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 1.0f, 0.0f );
      faces[ 6 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 0.0f, 1.0f, 0.0f );
      faces[ 7 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 0.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 1.0f, 0.0f );
      faces[ 8 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 0.0f, 1.0f, 0.0f );
      faces[ 9 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 0.0f, 0.0f );
      txt[ 0 ].set( 1.0f, 1.0f, 0.0f );
      faces[ 10 ].setTextureCoordinates( txt );

      txt[ 2 ].set( 0.0f, 0.0f, 0.0f );
      txt[ 1 ].set( 1.0f, 1.0f, 0.0f );
      txt[ 0 ].set( 0.0f, 1.0f, 0.0f );
      faces[ 11 ].setTextureCoordinates( txt );

      Object object = scene.addObject( "Cube", vertices, faces );
      object.setParameter( "Position", position );
    }

    // run
    virtual void run ( Cmd* rfEvntCmd )
    {
      const int cubes     = rfEvntCmd->getParameter< int >( "Cubes" );
      const Vector offset = rfEvntCmd->getParameter< Vector >( "Offset" );

      Vector position( 0.0f, 0.0f, 0.0f );
      for( int i = 0; i < cubes; ++i )
      {
        createCube( position );
        position += offset;
      }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_CMD_PLUGIN( CmdCreateGeometry );

/////////////////////////////////////////////////////////////////////////////////////////
