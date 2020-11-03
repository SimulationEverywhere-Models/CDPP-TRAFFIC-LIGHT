/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "Queue.h"      // class Queue
#include "Generator.h"    // class Generator
#include "Walk_No_But_Sen.h"        // class CPU
#include "Walk_But_Sen.h"   // class Transducer
#include "Sensor.h"    // class Trafico
#include "Button.h"    // class Trafico
#include "Light.h"    // class Trafico

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Walk_No_But_Sen>() , "Walk_No_But_Sen" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Walk_But_Sen>() , "Walk_But_Sen" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Sensor>() , "Sensor" ) ;
  	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Button>() , "Button" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Light>() , "Light" ) ;
}
