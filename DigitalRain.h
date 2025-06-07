/*
 `....
`..   `..   `..      `..
`..         `..      `..
`..     `...`.....`...`.....
`..         `..      `..
`..   `..   `..      `..
 `....

Dan Koskiranta
Class Declaration (header file)
Defines the DigitalRain class. 
Declares the constructors, member variables, and functions without implementing them
Allows the DigitalRain class to be reused in multiple source files while keeping the implementation separate
*/

#ifndef DIGITALRAIN_H
#define DIGITALRAIN_H

#include <windows.h>	//SetConsoleCursorPosition
#include <vector>		//Collection of things of the same type
#include <iostream>	    //cout

#define VERBOSE 1

class DigitalRain {
public:
	DigitalRain();									//Default constructor
	DigitalRain(int color);							//Constructor with parameters
	DigitalRain(const DigitalRain&);				//Copy constructor
	~DigitalRain();									//Destructor


	void GotoXY(int x, int y);
	void DrawCharacters();


	// Declare the stream insertion (<<) operator as a friend function
	// This allows printing the DigitalRain object to an output stream (e.g., std::cout)
	// in a custom format, such as displaying the color or other relevant properties.
	friend std::ostream& operator<<(std::ostream& output, const DigitalRain& rain);

private:
	int color_;				//Store the color attribute. Windows console APIs expect integer-based color attributes (0x0020)

};

#endif
