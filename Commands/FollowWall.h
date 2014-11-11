#ifndef FOLLOWWALL_H
#define FOLLOWWALL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author David Mao
 */
class FollowWall: public CommandBase {
public:
	FollowWall();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
