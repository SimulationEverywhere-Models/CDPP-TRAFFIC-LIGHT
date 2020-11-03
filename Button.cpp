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
#include "button.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Button::Button( const string &name )
: Atomic( name )
, ped_in_Q( addInputPort( "ped_in_Q" ) )
, walk_stop( addInputPort( "walk_stop" ) )
, button_on( addOutputPort( "button_on" ) )

{
	inf = Time(9999,0,0,0);
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Button::initFunction()
{
	holdIn(passive, inf);
	button = false;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Button::externalFunction( const ExternalMessage &msg )
{
	if (state() == passive){
		if (msg.port() == ped_in_Q){
			button = true;
			holdIn(active, Time::Time(0,0,10,0));
		}
		else {
			timeLeft = msg.time() - lastChange();
		}
	}

	else if (state() == active2) {
		if (msg.port() == walk_stop) {
			holdIn(passive, inf);
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
Model &Button::internalFunction( const InternalMessage & )
{
	if (state() == active){
		holdIn(active2, inf);
		button = false;
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
Model &Button::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), button_on, button ) ;
	return *this ;
}
