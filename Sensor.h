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

#ifndef __SENSOR_H
#define __SENSOR_H

#include <list>
#include "atomic.h"     // class Atomic

class Sensor : public Atomic
{
public:
	Sensor( const string &name = "Sensor" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &car_in_Q;
	const Port &light_red;
	Port &sensor_set;
	Time preparationTime;
   Time inf;
	
	bool sensor;
	Time timeLeft;

};	// class Sensor

// ** inline ** // 
inline
string Sensor::className() const
{
	return "Sensor" ;
}

#endif   //__SENSOR_H
