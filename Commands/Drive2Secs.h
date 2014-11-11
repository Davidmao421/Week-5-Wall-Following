#ifndef DRIVE2SECS_H
#define DRIVE2SECS_H

#include "../CommandBase.h"

/**
 *
 *
 * @author prath_000
 */
class Drive2Secs: public CommandBase {
public:
	Drive2Secs();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
