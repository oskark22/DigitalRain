/*
 `....
`..   `..   `..      `..
`..         `..      `..
`..     `...`.....`...`.....
`..         `..      `..
`..   `..   `..      `..
 `....

Dan Koskiranta
DigitalRain.cpp file defines the DigitalRain class, implementing its constructors and member functions
*/

#include <iostream>			//cout
#include <windows.h>		//SetConsoleCursorPosition
#include "DigitalRain.h"	//include DigitalRain class
#include <vector>			//Collection of things of the same type. vector to stores positions
#include <thread>			//control speed
#include <chrono>			//time delay


DigitalRain::DigitalRain() {}			//Initialize default constructor

DigitalRain::DigitalRain(int color) : color_(color) {										
	HANDLE theConsole = GetStdHandle(STD_OUTPUT_HANDLE);			//Get console output handle. Used for manipulating console's properties like text and cursor position
	SetConsoleTextAttribute(theConsole, color);			            //Set the text color to green once in the constructor instead of setting the color repeatedly in the GotoXY function
}			


//Move the console cursor to (x, y)
void DigitalRain::GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);		//STD_OUTPUT_HANDLE refers to the console screen
}


//Draw the falling characters
void DigitalRain::DrawCharacters() {

	int numberOfChars = 10;										//Number of falling characters

	std::vector<int> xPositions(numberOfChars);					//Store columnposition for each character
	std::vector<int> yPositions(numberOfChars);
	std::vector<char> characters(numberOfChars);				//Vector to store the falling characters
	std::vector<int> speeds(numberOfChars);						//Store different falling speeds
	std::vector<int> timeCounters(numberOfChars, 0);			//Time counters for each character to track when the character should move down
	std::vector<bool> charIsAtBottom(numberOfChars, false);		//Track if each character is at bottom

	//Initialize random starting positions and characters.          Seeds the random number generator to get different random values on every run 
	srand(static_cast<unsigned int>(time(0)));

	//Set the initial positions for characters
	for (int i = 0; i < numberOfChars; ++i) {
		xPositions[i] = 5 + (5 * i);								//Horizontal position for each character (5, 10, 15)
		yPositions[i] = 0;											//Characters will start to fall from the top
		characters[i] = static_cast<char>(33 + rand() % 10);        //(rand() generates a random integer value from ASCII 33 to 42. static_cast<char> is a type cast that converts the integer result into a character
		speeds[i] = 2 + rand() % 5;									//Random falling speed between 2 and 6. speeds[i] controls how fast the character falls
	}

	//Infinite loop to keep chracters falling
	while (true) {

		int allCharsAtBottom = 0;


		//Draw characters
		for (int i = 0; i < numberOfChars; ++i) {
			if (!charIsAtBottom[i]) {
				//Print characters at their positions only if they have not reached the bottom
				GotoXY(xPositions[i], yPositions[i]);
				std::cout << characters[i];
			}
		}

		//Delay the drop
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		//Move characters down according to their speeds
		for (int i = 0; i < numberOfChars; ++i) {
			if (!charIsAtBottom[i]) {
				//if timecounters for a character reaches the speed threshold (speeds[i]), the character is allowed to move down
				//controls how fast each character moves down by ensuring that characters with different speeds fall at different rates
				if (++timeCounters[i] >= speeds[i]) {
					timeCounters[i] = 0;								//Restart the cycle, so the character waits for another speeds[i] frames before moving again
	
					// Move the character down
					++yPositions[i];

					//Check if a character has reached the bottom
					if (yPositions[i] >= 30) {
						yPositions[i] = 30;						//Lock the character at the bottom
						charIsAtBottom[i] = true;
					}
				}
			}
		}

		// Count the number of characters at the bottom
		for (int i = 0; i < numberOfChars; ++i) {
			if (charIsAtBottom[i]) {
				++allCharsAtBottom;
			}
		}

		//If all characters reached the bottom reset to top
		if (allCharsAtBottom == numberOfChars) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			system("cls");															//Clear the screen

			//Reset positions and characters for the next cycle
			for (int i = 0; i < numberOfChars; ++i) {
				yPositions[i] = 0;
				characters[i] = static_cast<char>(33 + rand() % 10);
				speeds[i] = 2 + rand() % 5;											//rand() generates a large random integer, % 5 (modulus operator) ensures the result is between 0 and 4
				charIsAtBottom[i] = false;											//Reset the fallen flag
			}
			allCharsAtBottom = 0;   //Reset counter to start the process again
		}
	}
}

//Copy constructor implementation
DigitalRain::DigitalRain(const DigitalRain& rain) :
	color_{ rain.color_ } 
{
#if VERBOSE
	std::cout << "DigitalRain Copy constructor" << std::endl;
#endif

}

//Call the destructor to clean up any resources that were allocated by the object during its lifetime
DigitalRain::~DigitalRain() {

#if VERBOSE
	std::cout << "Programmer Destructor" << std::endl;
#endif
}


//Define the stream insertion (<<) operator outside the DigitalRain class
//This allows printing the DigitalRain object to the output stream with a custom format(e.g., including the color information)
std::ostream& operator<<(std::ostream& output, const DigitalRain& rain) {
	output << "DigitalRain with color: " <<std::hex << rain.color_ << std::dec << std::endl;
	return output;
}