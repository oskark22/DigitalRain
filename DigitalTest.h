/*
 `....
`..   `..   `..      `..
`..         `..      `..
`..     `...`.....`...`.....
`..         `..      `..
`..   `..   `..      `..
 `....

Dan Koskiranta
Declare unit test functions for testing the DigitalRain class
The tests are implemented in DigitalTest.cpp
*/


//Header Guards. Prevent multiple inclusions of the same header file in a compilation unit
#ifndef DIGITALTEST_H
#define DIGITALTEST_H

#include "DigitalRain.h"

void RunTests();
void TestDefaultConstructor();
void TestGotoXYInput();
void TestOneArgConstructor();
void TestCopyCstr();



//End of Header Guard
#endif
