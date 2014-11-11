#ifndef TURNCCWSLIGHTLY_H
#define TURNCCWSLIGHTLY_H

#include "../CommandBase.h"

/**
 *
 *
 * @author David Mao
 */
class TurnCCWSlightly: public CommandBase {
public:
	TurnCCWSlightly();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
