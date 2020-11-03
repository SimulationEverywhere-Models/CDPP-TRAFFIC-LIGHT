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

#ifndef __BUTTON_H
#define __BUTTON_H

#include <list>
#include "atomic.h"     // class Atomic

class Button : public Atomic
{
public:
	Button( const string &name = "Button" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &ped_in_Q;
	const Port &walk_stop;
	Port &button_on;
	Time preparationTime;
	Time inf;
	
	bool button;
	Time timeLeft;


};	// class Sensor

// ** inline ** // 
inline
string Button::className() const
{
	return "Button" ;
}

#endif   //__Button_H
