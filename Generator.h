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

#ifndef __GENERATOR_H
#define __GENERATOR_H

#include <list>
#include "atomic.h"     // class Atomic

class Distribution ;

class Generator : public Atomic
{
public:
	Generator( const string &name = "Generator" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port &out ;
	Distribution *dist ;
	int next, initial ;

	Distribution &distribution()
			{return *dist;}

};	// class Sensor

// ** inline ** // 
inline
string Generator::className() const
{
	return "Generator" ;
}

#endif   //__GENERATOR_H
