#ifndef LIFTARM_H
#define LIFTARM_H

#include "../CommandBase.h"

/**
 *
 *
 * @author David Mao
 */
class LiftArm: public CommandBase {
public:
	LiftArm();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
