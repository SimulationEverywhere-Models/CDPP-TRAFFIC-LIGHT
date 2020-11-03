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
#include "sensor.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Sensor::Sensor( const string &name )
: Atomic( name )
, car_in_Q( addInputPort( "car_in_Q" ) )
, light_red( addInputPort( "light_red" ) )
, sensor_set( addOutputPort( "sensor_set" ) )


{
	inf = Time(99999,0,0,0);
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Sensor::initFunction()
{
	holdIn(passive, inf);
	sensor = false;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Sensor::externalFunction( const ExternalMessage &msg )
{
	if (state() == passive){
		if (msg.port() == car_in_Q){
			sensor = true;
			holdIn(active, Time::Time(0,0,10,0));
		}
		else {
			timeLeft = msg.time() - lastChange();
		}
	}

	else if (state() == active2) {
		if (msg.port() == light_red) {
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
Model &Sensor::internalFunction( const InternalMessage & )
{
	if (state() == active){
		holdIn(active2, inf);
		sensor = false;
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
Model &Sensor::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), sensor_set, sensor ) ;
	return *this ;
}
