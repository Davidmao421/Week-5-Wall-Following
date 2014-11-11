#ifndef TURNCWSLIGHTLY_H
#define TURNCWSLIGHTLY_H

#include "../CommandBase.h"

/**
 *
 *
 * @author David Mao
 */
class TurnCWSlightly: public CommandBase {
public:
	TurnCWSlightly();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
