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

#ifndef __WALK_NO_BUT_SEN_H
#define __WALK_NO_BUT_SEN_H

#include <list>
#include "atomic.h"     // class Atomic

class Walk_No_But_Sen : public Atomic
{
public:
	Walk_No_But_Sen( const string &name = "Walk_No_But_Sen" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
  
	const Port &light_green;
	Port &walk_stop, &walk;

   Time timeLeft;
   Time inf;
	bool walk_ok;

};	// class Sensor

// ** inline ** // 
inline
string Walk_No_But_Sen::className() const
{
	return "Walk_No_But_Sen" ;
}

#endif   //__Walk_No_But_Sen
