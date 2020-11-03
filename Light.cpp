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
#include "Light.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Light::Light( const string &name )
: Atomic( name )
, opp_light_red( addInputPort( "opp_light_red" ) )
, walk_stop( addInputPort( "walk_stop" ) )
, light_red( addOutputPort( "light_red" ) )
, light_green( addOutputPort( "light_green" ) )


{
	inf = Time(9999,0,0,0);
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Light::initFunction()
{
	this->holdIn( active2,inf ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Light::externalFunction( const ExternalMessage &msg )
{
	if (state() == passive){
		if (msg.port() == walk_stop) {
			red = true;
			holdIn(active, Time(0,0,3,0));
		}

		else {
			timeLeft = msg.time() - lastChange();
		}
	}

	else if (state() == active2) {
		if (msg.port() == opp_light_red){
			green = true;
			holdIn(active3, Time(0,0,0,10));
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
Model &Light::internalFunction( const InternalMessage & )
{
	if (state() == active){
		holdIn(active2, inf);
		red = false;
	}

	else if (state() == active3) {
		holdIn(passive, inf);
		green = false;
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
Model &Light::outputFunction( const InternalMessage &msg )
{
	if (state() == active){
		this->sendOutput( msg.time(), this->light_red, this->red );
	}
   else if (state() == active3){
		this->sendOutput( msg.time(), this->light_green, this->green );
   }
	return *this ;
}
