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
#include <rf_sdk/sdk/object.h>
#include <rf_sdk/sdk/ppty.h>
#include <rf_sdk/sdk/plgdescriptor.h>
#include <rf_sdk/waves/waveplgsdk.h>
#include <rf_sdk/sdk/rfsdklibdefs.h>
#include <rf_sdk/sdk/sdkversion.h>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace nextlimit::rf_sdk;

/////////////////////////////////////////////////////////////////////////////////////////

namespace nextlimit
{
  namespace rf_sdk
  {

    class MathUtilFncs
    {

    public:

      //
      static float NL_toRadian( const float& degree )
      {
        return( degree * (float)( PI() / 180.0 ) );
      } 

      //
      static float GRAVITY_FORCE()
      {
        return( 9.81f );
      }

      //
      static float PI() 
      {
        return( 3.14f );
      }  

      //
      static float _2PI()
      {
        return( PI() * 2.0f  );
      }  
    };


    class GerstnerWaveSDK : public WavePlgSdk
    {
    public:

      /// Constructor.
      GerstnerWaveSDK() {};

      /// Destructor.
      virtual ~GerstnerWaveSDK( void ) {};

      /// Class id.
      virtual NL_INT32 getClassId() const 
      { 
        return ( 485213000 );
      };

      // getSdkVersion
      virtual NL_INDEX32 getSdkVersion() const
      {
        return ( SdkVersion::SDK_VERSION );
      }

      /// Get plugin name.
      virtual std::string getNameId() const 
      { 
        return ( "GerstnerWave" ); 
      };

      // getCopyRight()
      virtual std::string getCopyRight() const
      {
        return std::string( "Copyright (C) 2008 Next Limit Technologies. All rights reserved." );
      }

      // getCopyRight()
      virtual std::string getLongDescription() const
      {
        return std::string( "Simulates a Gerstner Wave." );
      }

      // getCopyRight()
      virtual std::string getShortDescription() const
      {
        return std::string( "Simulates a Gerstner Wave." );
      }

      /// Initialize plugin, add properties, etc.
      virtual void initialize( PlgDescriptor* plgDesc )
      {
        Ppty dirWave    = Ppty::createPpty( "DirWave", 20.0f ); 
        Ppty ampWave    = Ppty::createPpty( "AmpWave", 0.1f );
        Ppty lengthWave = Ppty::createPpty( "LengthWave", 2.0f ); 

        plgDesc->addPpty( dirWave );
        plgDesc->addPpty( ampWave );
        plgDesc->addPpty( lengthWave );
      }

      //#--------------------------------------------------
      //# Function: updateWave 
      //# This function is called by the simulation engine 
      //# when it is time to update the wave. 
      //# The parameter is the list of vertices that you have 
      //# to update. Only values in the Y axis are used. 
      //#--------------------------------------------------

      virtual void updateWave( Wave* plgThis                           , 
                               std::vector<Vertex>& vertices           , 
                               const std::vector<Vector>& initPosVrtxs   )
      {
        
        Scene& scene     =  AppManager::instance()->getCurrentScene();
        double totalTime = scene.getCurrentTime();

        float  dirWave    = plgThis->getParameter<float> ( "DirWave" ); //Just x,z ; y is ignored in dirWave
        float  ampWave    = plgThis->getParameter<float> ( "AmpWave" );
        float  lengthWave = plgThis->getParameter<float> ( "LengthWave" );
   
        float dirRadWave = MathUtilFncs::NL_toRadian( dirWave );

        //Just x,z ; y is ignored in dirWave
        Vector dirVecWaveN = Vector( cos( dirRadWave ), 0.0f, sin( dirRadWave ) ); 
        dirVecWaveN.normalize();

        float k_number = MathUtilFncs::_2PI() / lengthWave;
        Vector k_waveVector( dirVecWaveN * k_number );

        double w_angularVel = sqrt( MathUtilFncs::GRAVITY_FORCE() * k_number );

        Vector dispH;
        Vector dispV( 0.0f, 0.0f, 0.0f );
        Vector local_Eqb_Pos;

        for( int i = 0, length = int( vertices.size() ); i < length; i++ )
        { 
          //local_Eqb_Pos = graficmsh.pgeo[i].oldpos;
          local_Eqb_Pos = initPosVrtxs[ i ];

          double angle = Vector::dot( k_waveVector, local_Eqb_Pos) -  ( w_angularVel * totalTime ); 

          dispH = ( -( dirVecWaveN * ( ampWave *( sin( angle ) ) ) ) );
          dispV.setY( ampWave * ( cos( angle ) ) );

          vertices[ i ].setPosition( local_Eqb_Pos + dispH + dispV );
        }
      }
    };
  }
}


/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_WAVE_PLUGIN( GerstnerWaveSDK );

/////////////////////////////////////////////////////////////////////////////////////////
