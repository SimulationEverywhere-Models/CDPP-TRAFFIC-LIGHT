/*******************************************************************
*
*  DESCRIPTION: class Atomic
*
*  AUTHOR:    Amir Barylko & Jorge Beyoglonian 
*  VERSION 2: Daniel Rodriguez
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*         mailto://drodrigu@dc.uba.ar
*
*  DATE: 27/6/1998
*  DATE: 25/4/1999 (v2)
*
*******************************************************************/

#ifndef __ATOMIC_H
#define __ATOMIC_H

/** include files **/
#include "model.h"   //class Model

/** foward declarations **/
class MainSimulator ;
class Simulator ;
class ExternalMessage ;
class InternalMessage ;

#define	ATOMIC_NAME		"Atomic"

/** definitions **/
class Atomic : public Model
{
public:
	virtual ~Atomic()	// Destructor
		{}

protected:
	friend class Simulator ;

	enum State
	{
		active,
		passive,
      active2,
      active3
	} ;

	Atomic( const string &name = "Atomic" )	// Constructor
			: Model( name )
			, st( passive )
			{}

	Atomic( const Atomic & ) ;	 	// Copy constructor

	Atomic &operator = ( const Atomic & );	// Assignment operator

	int operator ==( const Atomic & ) const; // Equality operator

	virtual Model &initFunction() = 0 ;

	virtual Model &externalFunction( const ExternalMessage & ) = 0 ;

	virtual Model &internalFunction( const InternalMessage & ) = 0 ;

	virtual Model &outputFunction( const InternalMessage & ) = 0 ;

	Model &holdIn( const State &, const Time & ) ;

	Model &passivate();

	Model &state( const State &s )
		{ st = s; return *this; }

	const State &state() const
		{return st;}
	
	virtual string className() const
		{return ATOMIC_NAME;}

private:
	friend class MainSimulator ;
	State st;
};	// class Atomic

#endif   //__ATOMIC_H