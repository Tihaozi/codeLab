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
#include <rf_sdk/sdk/vector.h>
#include <rf_sdk/sdk/daemon.h>
#include <rf_sdk/sdk/pb_particle.h>
#include <rf_sdk/sdk/pb_emitter.h>
#include <rf_sdk/sdk/gui_message_dialog.h>
#include <rf_sdk/sdk/ppty.h>
#include <rf_sdk/sdk/plgdescriptor.h>
#include <rf_sdk/daemons/daemonplgsdk.h>
#include <rf_sdk/sdk/rfsdklibdefs.h>

/////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace nextlimit::rf_sdk;

/////////////////////////////////////////////////////////////////////////////////////////


class MoveTo_gd_splashDaemonSDK : public DaemonPlgSdk
{
public:

	/// Constructor.
	MoveTo_gd_splashDaemonSDK() {}

	/// Destructor.
	virtual ~MoveTo_gd_splashDaemonSDK() {};

	/// Class id.
	virtual NL_INT32 getClassId() const
	{
		return (1671508588);
	};

	/// If is multithreaded.
	virtual bool isMT(void) const { return NL_false; };

	/// Get plugin name.
	virtual std::string getNameId() const
	{
		return ("Move to grid domain splash");
	};

	// getCopyRight()
	virtual std::string getCopyRight() const
	{
		return std::string("Copyright (C) 2010 Next Limit Technologies. All rights reserved.");
	}

	// getCopyRight()
	virtual std::string getLongDescription() const
	{
		return std::string("Move the particles from a particle-based emitter to a" \
			"grid domain splash");
	}

	// getCopyRight()
	virtual std::string getShortDescription() const
	{
		return std::string("Move the particles from a particle-based emitter to a" \
			"grid domain splash");
	}

	/// Initialize plugin, add properties, etc.
	virtual void initialize(PlgDescriptor* plgDesc)
	{
		Ppty radiusPpty = Ppty::createPpty("Radius", 0.1f);
		plgDesc->addPpty(radiusPpty);

		Ppty splashPpty = Ppty::createPpty("Splash", "");
		plgDesc->addPpty(splashPpty);
	}

	virtual void onSimulationBegin(Daemon* thisPlg)
	{
		const std::string splashName = thisPlg->getParameter<std::string>("Splash");
		Scene& scene = AppManager::instance()->getCurrentScene();
		PB_Emitter splash = scene.get_PB_Emitter(splashName);
		if (splash.isNull())
		{
			GuiMessageDialog messageDlg;
			messageDlg.show(GuiMessageDialog::ALERT_TYPE_CRITICAL, "Splash node not found");
			return;
		}

		if (!splash.queryParticlesAttribute(2))
		{
			GuiMessageDialog messageDlg;
			messageDlg.show(GuiMessageDialog::ALERT_TYPE_CRITICAL, "Node is not a splash");
			return;
		}
	}

	virtual void applyForceToEmitter(Daemon* thisPlg,
		PB_Emitter* emitter,
		PB_Emitter::iterator iter)
	{
		Scene& scene = AppManager::instance()->getCurrentScene();
		const float radius = thisPlg->getParameter<float>("Radius");
		const std::string splashName = thisPlg->getParameter<std::string>("Splash");

		PB_Emitter splash = scene.get_PB_Emitter(splashName);
		if (splash.isNull())
		{
			scene.message("Splash node not found");
			return;
		}

		if (!splash.queryParticlesAttribute(2))
		{
			scene.message("Node is not a splash");
			return;
		}

		while (iter.hasNext())
		{
			PB_Particle particle = iter.next();
			const Vector& position = particle.getPosition();
			const Vector& velocity = particle.getVelocity();
			PB_Particle splashParticle = splash.addParticle(position, velocity);
			splashParticle.setAttribute(2, radius);
		}
		emitter->removeAllParticles();
	}

	virtual void applyForceToEmitter(Daemon* thisPlg,
		PB_Emitter* emitter,
		int nThread,
		PB_Emitter::iterator iter)
	{
	}

	virtual void applyForceToBody(Daemon* thisPlg, Object* obj)
	{
	}

	virtual void removeParticles(Daemon* plgThis, PB_Emitter* obj)
	{
	}

	virtual int canAffect(Daemon* thisPlg) const
	{
		return daemon_affect::AFFECT_EMITTER;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////

RF_SDK_DECLARE_DAEMON_PLUGIN(MoveTo_gd_splashDaemonSDK);

/////////////////////////////////////////////////////////////////////////////////////////


