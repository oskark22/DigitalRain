/*
 `....
`..   `..   `..      `..
`..         `..      `..
`..     `...`.....`...`.....
`..         `..      `..
`..   `..   `..      `..
 `....

Dan Koskiranta
*/

#include "DigitalTest.h"		//Test functions
#include "DigitalRain.h"		//include DigitalRain class
#include <stdexcept>			// out_of_range
#include <iostream>				//cerr, endl


int main() {

	DigitalRain rain(FOREGROUND_GREEN);				//Instance of DigitalRain class with parameterized constructor (sets the color to green)

	
	rain.DrawCharacters();							// Call the function to print digital rain


	//Add an exception
	/*try {
		//Run the unit tests
		RunTests();					
	}
	catch (std::out_of_range& e) {
		std::cerr << std::endl << e.what() << std::endl;
		return -1;
	}*/
	//RunTests();										//Run the unit tests

	return 0;
}