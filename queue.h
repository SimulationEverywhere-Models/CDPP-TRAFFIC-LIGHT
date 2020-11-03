/*******************************************************************
*
*  DESCRIPTION: Atomic Model Queue
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __QUEUE_H
#define __QUEUE_H

#include <list>
#include "atomic.h"     // class Atomic

class Queue : public Atomic
{
public:
	Queue( const string &name = "Queue" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &enqueue;
	const Port &empty_Q;
	const Port &fill_Q;
	Port &remove;
	Port &add;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;
	bool deQ;
	Time timeLeft;
	Time inf;

};	// class Queue

// ** inline ** // 
inline
string Queue::className() const
{
	return "Queue" ;
}

#endif   //__QUEUE_H
