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

#ifndef __LIGHT_H
#define __LIGHT_H

#include <list>
#include "atomic.h"     // class Atomic

class Light : public Atomic
{
public:
	Light( const string &name = "Light" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
  
	const Port &opp_light_red;
   const Port &walk_stop;
	Port &light_red;
   Port &light_green;

	bool green;
	bool red;
	Time inf;
  	Time timeLeft;

};	// class Sensor

// ** inline ** // 
inline
string Light::className() const
{
	return "Light" ;
}

#endif   //__GENERATOR_H
