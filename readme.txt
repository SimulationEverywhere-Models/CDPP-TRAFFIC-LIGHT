After successful compilation (hopefully... it worked at school but i couldn't get it to work here at home), the tests can be run by running any of the seven bat files.

1gen.bat - just one generator generating cars at a specific rate.  No ev file because there is no input to the generator, it should generate events itself.

alight.bat - one light that has an ev file corresponding to it, alight.ev.  Generates the appropriate inputs to the light and outputs will be shown in the output.

aqueue.bat - a test for one queue.  Inputs include cars coming in, and two other input to indicate that status of the light, whether to enqueue the cars (the light is red) or dequeue the cars (the light is green).  There is an ev file and ma file with the same name.

awalksignal - testing the walk signal that has the sensor and button hooked up.  The ev file sends inputs indicating that a person has pressed the button or a car is waiting in line.  Also need an input from the light giving its state.

demo.bat - the whole system connected.  There is no ev file because the generator is to produce the events on its own.  

onebutton.bat - running this after compilation will simulate just one button and a pedestrian pressing it and showing the outputs that it sends.

onesensor.bat - lastly, one sensor, that reacts similarily to the button.  