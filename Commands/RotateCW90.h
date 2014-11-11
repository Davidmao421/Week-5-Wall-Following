#ifndef ROTATECW90_H
#define ROTATECW90_H

#include "../CommandBase.h"

/**
 *
 *
 * @author prath_000
 */
class RotateCW90: public CommandBase {
public:
	RotateCW90();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
