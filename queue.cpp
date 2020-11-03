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
#include "queue.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Queue::Queue( const string &name )
: Atomic( name )
, enqueue( addInputPort( "enqueue" ) )
, empty_Q( addInputPort( "empty_Q" ) )
, fill_Q( addInputPort( "fill_Q" ) )
, remove( addOutputPort( "remove" ) )
, add( addOutputPort( "add" ) )
, preparationTime( 0, 0, 10, 0 )

{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
	inf = Time(9999,0,0,0);
   }

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Queue::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	holdIn(passive, inf);

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Queue::externalFunction( const ExternalMessage &msg )
{
	if (state() == passive){
		if (msg.port() == enqueue){
			elements.push_back(msg.value());
			holdIn(active, Time::Time(0,0,1,0));
		}
		else if(msg.port() == empty_Q) {
			holdIn(active2, Time::Time(0,0,0,10));
		}
		else {
			timeLeft = msg.time() - lastChange();
		}
	}

	else if (state() == active2) {
		if (msg.port() == fill_Q) {
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
Model &Queue::internalFunction( const InternalMessage & )
{
	if (state() == active){
		holdIn(passive, inf);
	}
	else if(state() == active2){
		holdIn(active2, Time::Time(0,0,0,10));
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
Model &Queue::outputFunction( const InternalMessage &msg )
{
	if (state() == active) {
		sendOutput( msg.time(), add, elements.front() ) ;
	}
	else if (state() == active2) {
		sendOutput( msg.time(), remove, true ) ;
	}
   return *this ;
}
