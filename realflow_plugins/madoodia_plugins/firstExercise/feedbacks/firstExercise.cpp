/////////////////////////////////////////////////////////////////////////////////////////
//
// madoodia@gmail.com
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream> 
#include <string>

#include <rf_sdk/sdk/appmanager.h>
#include <rf_sdk/sdk/scene.h>
#include <rf_sdk/sdk/vector.h>
#include <rf_sdk/sdk/daemon.h>
#include <rf_sdk/sdk/pb_particle.h>
#include <rf_sdk/sdk/pb_emitter.h>
#include <rf_sdk/sdk/ppty.h>
#include <rf_sdk/sdk/plgdescriptor.h>
#include <rf_sdk/daemons/daemonplgsdk.h>
#include <rf_sdk/sdk/rfsdklibdefs.h>
#include <rf_sdk/sdk/sdkversion.h>
#include <rf_sdk/sdk/mutex.h>
#include <rf_sdk/sdk/object.h>

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace nextlimit::rf_sdk;

/////////////////////////////////////////////////////////////////////////////////////////


class FirstExerciseDaemonSDK : public DaemonPlgSdk
{

	enum ForceType
	{
		FORCE_CONST,
		FORCE_LINEAR_INC,
		FORCE_QUADRATIC_INC
	};

	Mutex threadLock;

public:

	int timesBeingCalled;
	int localID;

	static int globalLocalID;

	/// Constructor.
	FirstExerciseDaemonSDK()
	{
		// Gives an unique local Id
		localID = FirstExerciseDaemonSDK::globalLocalID++;

		timesBeingCalled = 0;
	}

	/// Destructor.
	virtual ~FirstExerciseDaemonSDK() {};

	/// Class id.
	virtual NL_INT32 getClassId() const
	{
		//return (1672508588);
		return (252254738); // new Class ID from Realflow
	};

	/// Get plugin name.
	virtual string getNameId() const
	{
		return ("FirstExercise");
	};

	// getCopyRight()
	virtual string getCopyRight() const
	{
		return string("Copyright (C) 2016 [madoodia.com]. All rights reserved.");
	}

	// getLongDescription()
	virtual string getLongDescription() const
	{
		return string("Adds a constant force in a certain direction.");
	}

	// getShortDescription()
	virtual string getShortDescription() const
	{
		return string("Adds Constant Force");
	}

	/// Initialize plugin, add properties, etc.
	virtual void initialize(PlgDescriptor* plgDesc)
	{
		// float property
		Ppty fStrength = Ppty::createPpty("FStrength", -9.8f);
		plgDesc->addPpty(fStrength);


		// vector property
		Ppty fDir = Ppty::createPpty("FDir", Vector(1.0, 1.0, 0.0));
		plgDesc->addPpty(fDir);

		// Task A2: (vector property) ------------------
		Ppty vStrength = Ppty::createPpty("VStrength", 2.0f);
		plgDesc->addPpty(vStrength);
		//----------------------------------------------
		// Task A2: (vector property) ------------------
		Ppty extraAttr = Ppty::createPpty("ExtraAttr", 1.0f);
		plgDesc->addPpty(extraAttr);
		//----------------------------------------------


		// list property
		vector<string> lstNames;
		lstNames.push_back("Constant");
		lstNames.push_back("LinearInc");
		lstNames.push_back("QuadraticInc");

		vector<int> lstValues;
		lstValues.push_back(FORCE_CONST);
		lstValues.push_back(FORCE_LINEAR_INC);
		lstValues.push_back(FORCE_QUADRATIC_INC);

		Ppty forceType = Ppty::createPpty("ForceType", lstNames, lstValues);
		plgDesc->addPpty(forceType);
	}

	virtual void applyForceToEmitter(Daemon* thisPlg, PB_Emitter* emitter, PB_Emitter::iterator iter)
	{
		applyForceToEmitter(thisPlg, emitter, 0, iter);
	}


	// Is multithreading (No need to imlement here because while (iter.hasNext())
	// will create threading
	//virtual bool isMT(void) const { return NL_true; };

	//--------------------------------------------------
	//  Function: applyForceToEmitter 
	//  This function is called by the simulation engine 
	//  when external forces should be applied to the    
	//  particles in the emitter.
	//--------------------------------------------------

	virtual void applyForceToEmitter(Daemon* thisPlg, PB_Emitter* emitter, int nThread, PB_Emitter::iterator iter)
	{
		Scene& Scene = AppManager::instance()->getCurrentScene();

		float fStrength = thisPlg->getParameter<float>("FStrength");
		int   forceType = thisPlg->getParameter<int>("ForceType");

		// Current time
		float currTime = scene.getCurrentTime();

		float currFStrength = fStrength;

		switch (forceType)
		{
		case FORCE_CONST:
			currFStrength = fStrength;
			break;

		case FORCE_LINEAR_INC:
			currFStrength = fStrength * currTime;
			break;

		case FORCE_QUADRATIC_INC:
			currFStrength = fStrength * currTime * currTime;
			break;
		}


		Vector fDir = thisPlg->getParameter<Vector>("FDir");

		if (fDir.module() != 0) {
			fDir.normalize(); //NB RF might crash if Fdir is (0,0,0). I usually check the size first.
			fDir.scale(currFStrength);
		}

		// apply the daemon transformation to gravity direction vector
		// unit direction vector
		//Vector forceDirWrld = thisPlg->toWorld( fDir );

		// ----------------------------------------------------
		// Task A1:
		// Task A2:

		PB_Particle curpart = emitter->getFirstParticle();
		ArrSdkPB_Particles neighbors;
		float massParticle = curpart.getMass();

		//threadlocking the call to avoid crashes. (Haven't tested to see if its not needed in RF2015. I use another method, which I'll show you later if needed)
		threadLock.lock();
		// the more resolution, the less redius
		double resolution = 1000.0f * emitter->getParameter<double>("Resolution");
		float radInf = 20.0f / (10.0f * pow(resolution, 1.0 / 3.0));
		threadLock.unlock();

		// get velocity from particle
		Vector parVel;
		Vector fVel;
		float vStrength = thisPlg->getParameter<float>("VStrength");

		fDir.scale(massParticle);
		//while (iter.hasNext())
		//{
		//	curpart.getNeighbors(neighbors, radInf);
		//	parVel = curpart.getVelocity();
		//	fVel = parVel  * vStrength;
		//	
		//	curpart.setExternalForce(fDir * neighbors.size() + fVel);
		//	curpart = iter.next();
		//}
		// ----------------------------------------------------
		// Task A3:
		//Vector direction(0.0f, 0.0f, 0.0f);
		//Vector intersection;
		//Vector normal;
		//float distance;
		//unsigned int index;
		//
		//while (iter.hasNext())
		//{
		//	curpart.getNeighbors(neighbors, radInf);
		//	parVel = curpart.getVelocity();
		//	fVel = parVel  * vStrength;

		//	Object object = curpart.getNearestObject(direction, USE_SCENE_OBJECTS, intersection, normal, index, distance);
		//	if(!object.isNull()){
		//		curpart.setExternalForce(fDir * neighbors.size() / distance + fVel);
		//	} else {
		//		curpart.setExternalForce(fDir * neighbors.size() + fVel);
		//	}

		//	curpart = iter.next();
		//}
		// ----------------------------------------------------
		/*
			Notes for A3 :
			Add a ...Ppty::createPpty... in Initialize to select one or more objects and query only those objects.
			Adjust the force, so that its Max near the object and fades out further away.
			Adjust the object based force to point either toward or away from the object (So add a Fobj, which is the total force contribution from all objects selected)
			Max force should occur when the distance is zero and Max force can be either positive or negative for an object (pull/push) Define pull/push by reading a parameter in the objects parameter list.
			Max Force should be a user input, maybe scale with a paramter from the Object. 
			Be creative

			

		*/




		// Task A4:
		/*
		Notes for A4 : 
		use curpart.setAttribute(,) and curPart.getAttribute(,)
		I normally create the atributes/parameters in onSimFrame or onSimBegin :
		Example : if (emitter.queryParticlesAttribute(xxx)==false) emitter.createParticlesAttribute( xxx, emitter.PARTICLE_ATTR_TYPE_FLOAT ); for the emitters that are linked to the daemon
		xxx is an integer.
		Example : You can then assign a random value to the attribute when the particle is born and read it later modify the force.
		Its like adding a lot of extra information to a particle and store it for later use.
		You can alse vare the attribute over time. You decide.
		Be creative.

		*/

		float eAttr = thisPlg->getParameter<float>("ExtraAttr");

		while (iter.hasNext())
		{
			curpart.getNeighbors(neighbors, radInf);
			parVel = curpart.getVelocity();
			fVel = parVel  * vStrength;

			curpart.setExternalForce(fDir * neighbors.size() + fVel);

			curpart = iter.next();
		}



	}

	//--------------------------------------------------
	// Function: applyForceToBody 
	// This function is called by the simulation engine 
	// when external forces should be applied to the body.                  
	//--------------------------------------------------
	virtual void applyForceToBody(Daemon* thisPlg, Object* obj)
	{
		//Scene& scene = AppManager::instance()->getCurrentScene();
		//stringstream msg;

		//int currFrame = scene.getCurrentFrame();
		//msg << "Current Frame = " << currFrame;
		//scene.message(msg.str());
		//msg.str("");

		//float fstrength = thisPlg->getParameter<float>("FStrength");
		//int   forceType = thisPlg->getParameter<int>("ForceType");

		//// Current time
		//float currTime = scene.getCurrentTime();

		//float currFtrength = fstrength;

		//switch (forceType)
		//{
		//case FORCE_CONST:
		//  currFtrength = fstrength;
		//  break;

		//case FORCE_LINEAR_INC:
		//  currFtrength = fstrength + fstrength * currTime;
		//  break;

		//case FORCE_QUADRATIC_INC:
		//  currFtrength = fstrength + fstrength * currTime * currTime;
		//  break;
		//}

		//Vector fDir = thisPlg->getParameter<Vector>("FDir");

		//fDir.normalize();
		//fDir.scale(currFtrength);

		//// apply the daemon transformation to gravity direction vector
		//// unit direction vector
		////Vector forceDirWrld = thisPlg->toWorld( fDir );

		//// Force proportional to mass
		//float massObj = obj->getParameter<float>("@ mass");
		//fDir.scale(massObj);

		//obj->setForce(fDir);

		//// Example of the use of Local Vars
		//timesBeingCalled++;

		//msg << "ID = " << localID << " -> applyForceToBody - calls: " << timesBeingCalled;
		//scene.message(msg.str());
		//msg.str("");
	}

	//--------------------------------------------------
	// Function: removeParticles 
	// This function is called by the simulation engine 
	// when it is safe to remove particles.                 
	//--------------------------------------------------
	virtual void removeParticles(Daemon* plgThis, PB_Emitter* obj)
	{

	}

};

int FirstExerciseDaemonSDK::globalLocalID = 0;

/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_DAEMON_PLUGIN(FirstExerciseDaemonSDK);

/////////////////////////////////////////////////////////////////////////////////////////

