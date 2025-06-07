/*
 `....
`..   `..   `..      `..
`..         `..      `..
`..     `...`.....`...`.....
`..         `..      `..
`..   `..   `..      `..
 `....

Dan Koskiranta
DigitalTest.cpp runs unit tests for DigitalRain class
*/


#include <iostream>						//cout
#include "DigitalRain.h"
#include "DigitalTest.h"

void RunTests() {
	//TestDefaultConstructor();
	//TestGotoXYInput();
	//TestOneArgConstructor();
	TestCopyCstr();

}

void TestDefaultConstructor() {
	std::cout << "Test Default Constructor" << std::endl;
	DigitalRain rain1;
	//std::cout << rain1;
}

//unit test for 1-arg constructor
void TestOneArgConstructor() {
	std::cout << "Test One Argument Constructor" << std::endl;
	DigitalRain rain1(0x0002);										
	std::cout << rain1 << std::endl;
}

//Unit test for testing copy constructor. 
//Creates a new object as a copy of an existing object 
//It then prints both objects to check if the copy constructor is properly invoked and behaves as expected
void TestCopyCstr() {
	std::cout << "Test Copy Constructor" << std::endl;

	DigitalRain rain1(0x0002);				//Create an object with green color
	DigitalRain rain2(rain1);				//Create a new object by copying rain1 using the copy constructor
	std::cout << rain1 << rain2;			//Print both objects
}

//Unit test for GotoXY function to check behaviour with valid input coordinates
void TestGotoXYInput() {
	std::cout << "Testing GotoXY function with a valid input..." << std::endl;

	DigitalRain rain;
	rain.GotoXY(10, 5);			//Move cursor to screen width 10 and screen height 5

	std::cout << "GotoXY test passed\n\n" << std::endl;
}

