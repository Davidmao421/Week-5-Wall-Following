#ifndef LOWERARM_H
#define LOWERARM_H

#include "../CommandBase.h"

/**
 *
 *
 * @author David Mao
 */
class LowerArm: public CommandBase {
public:
	LowerArm();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
