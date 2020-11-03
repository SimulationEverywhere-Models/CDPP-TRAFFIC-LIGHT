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

/** include files **/
#include "Walk_But_Sen.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Walk_But_Sen::Walk_But_Sen( const string &name )
: Atomic( name )
, button_on( addInputPort( "button_on" ) )
, sensor_on( addInputPort( "sensor_on" ) )
, light_green( addInputPort( "light_green" ) )
, walk_stop( addOutputPort( "walk_stop" ) )
, walk( addOutputPort( "walk" ) )

{
	inf = Time(9999,0,0,0);
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Walk_But_Sen::initFunction()
{
	this->holdIn( active2, inf ) ;
	walk_ok = true;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Walk_But_Sen::externalFunction( const ExternalMessage &msg )
{
	if (state() == active2){
		if ((msg.port() == button_on) || (msg.port() == sensor_on)) {
			walk_ok = false;
			holdIn(active3, Time(0,0,10,0));
		}

		else {
			timeLeft = msg.time() - lastChange();
		}
	}

	else if (state() == passive) {
		if (msg.port() == light_green){
			walk_ok = true;
			holdIn(active, Time::Time(0,0,0,10));
		}
		else {
			timeLeft = msg.time() - lastChange();
		}
	}

	else {
		timeLeft = msg.time() - lastChange();
	}


	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Walk_But_Sen::internalFunction( const InternalMessage & )
{
	if (state() == active){
		holdIn(active2, inf);
	}

	else if (state() == active3) {
		holdIn(passive, inf);
	}

	else {
		//should never happen
	}		

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Walk_But_Sen::outputFunction( const InternalMessage &msg )
{
	if (state() == active3) {
		sendOutput( msg.time(), walk_stop, !walk_ok ) ;
	}
	else if (state() == active3) {
		sendOutput( msg.time(), walk, walk_ok ) ;
	}
	return *this ;
}
