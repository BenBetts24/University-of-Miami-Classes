#include "library.h"
#include <string>

void drawButton(const int x, const int y, const int size, const string content)
{
	//built for regular strings
	set_pen_color(color::black);
	fill_rectangle(x, y, size, size);
	set_pen_color(color::grey);
	fill_rectangle(x + 1, y + 1, size - 2, size - 2);
	set_pen_color(color::black);
	if (content.length() > 2)
		set_font_size(size - 30);
	else if (content.length() > 1)
		set_font_size(size - 20);
	else
		set_font_size(size);
	move_to(x + (size/2), y + (size/2));
	write_string(content, direction::center);
}
void drawButton(const int x, const int y, const int size, const int content)
{
	//built for unicode characters
	set_pen_color(color::black);
	fill_rectangle(x, y, size, size);
	set_pen_color(color::grey);
	fill_rectangle(x + 1, y + 1, size - 2, size - 2);
	set_pen_color(color::black);
	set_font_size(size);
	move_to(x + (size/2), y + (size/2));
	write_char(content, direction::center);
}
double factorial(const double number)
{
	if (number == 1)
		return 1;
	else
		return (number * factorial(number - 1));
}
void drawScreen(const int windowWidth, const int windowHeight)
{
	int buttonSize = windowWidth/6;
	int totalX = windowWidth/60;
	int xAdd = windowWidth/30;
	int screenY = windowHeight/60;
	int totalY = windowHeight/30 + windowHeight/6;
	int yAdd = windowHeight/30;

	//drawing screen
	set_pen_color(color::black);
	fill_rectangle(totalX, screenY, ((4 * xAdd) + (5 * buttonSize)), buttonSize);
	set_pen_color(color::dark_grey);
	fill_rectangle(totalX + 1, screenY + 1, ((4 * xAdd) + (5 * buttonSize)) - 2, buttonSize - 2);
	set_pen_color(color::black);
}
void drawCalculator(const int windowWidth, const int windowHeight)
{
	//dimensions and distances
	int buttonSize = windowWidth/6;
	int totalX = windowWidth/60;
	int xAdd = windowWidth/30;
	int screenY = windowHeight/60;
	int totalY = windowHeight/30 + windowHeight/6;
	int yAdd = windowHeight/30;
	string labels[20] = {"7", "8", "9", "+", "^y", "4", "5", "6", "-", "+/-", "1", "2", "3", "X", "mod", "c", "0", "=", "divide", "!"};
	int uniLabel = (L'÷');

	//drawing screen
	drawScreen(windowWidth, windowHeight);

	//actually drawing buttons
	for (int count = 0, copyX = totalX; count < 5; count++, copyX += buttonSize + xAdd)
		drawButton(copyX, totalY, buttonSize, labels[count]);
	totalY += buttonSize + yAdd;
	for (int count = 0, copyX = totalX; count < 5; count++, copyX += buttonSize + xAdd)
		drawButton(copyX, totalY, buttonSize, labels[count + 5]);
	totalY += buttonSize + yAdd;
	for (int count = 0, copyX = totalX; count < 5; count++, copyX += buttonSize + xAdd)
		drawButton(copyX, totalY, buttonSize, labels[count + 10]);
	totalY += buttonSize + yAdd;
	for (int count = 0, copyX = totalX; count < 5; count++, copyX += buttonSize + xAdd)
		if (count == 3)
			drawButton(copyX, totalY, buttonSize, uniLabel);
		else
			drawButton(copyX, totalY, buttonSize, labels[count + 15]);
	totalY += buttonSize + yAdd;
}
void writeNumber(const int windowWidth, const int windowHeight, string number)
{
	int buttonSize = windowWidth/6;
	int yTotal = windowWidth/60;
	int xTotal = windowWidth/60;
	int xAdd = windowWidth/30;
	int yPosition = yTotal + (buttonSize / 2);
	int screenY = windowHeight/60;

	drawScreen(windowWidth, windowHeight);
	set_pen_color(color::yellow);
	move_to(((4 * xAdd) + (5 * buttonSize)), screenY + (buttonSize / 2));
	write_string(number, direction::west);
	set_pen_color(color::black);
}
int userInput(const int windowWidth, const int windowHeight)
{
	int buttonSize = windowWidth/6;
	int xTotal = windowWidth/60;
	int xAdd = windowWidth/30;
	int yTotal = windowHeight/30 + windowHeight/6;
	int yAdd = windowHeight/30;

	wait_for_mouse_click();
	int x = get_click_x(), y = get_click_y();
	
	/*
	return key:
	0-9 is the digit returned
	10 = equals
	11 = plus
	12 = minus
	13 = multiply
	14 = divide
	15 = exponent
	16 = sign change
	17 = mod
	18 = factorial
	19 = clear
	-1 = outside of buttons
	*/

	if ((x > xTotal && x < (xTotal + buttonSize)) && (y > (yTotal) && y < (yTotal + buttonSize)))
		return 7; //seven
	else if ((x > (xTotal + (1 * xAdd) + (1 * buttonSize)) && x < (xTotal + (1 * xAdd) + (2 * buttonSize))) && (y > (yTotal) && y < (yTotal + buttonSize)))
		return 8; //eight
	else if ((x > (xTotal + (2 * xAdd) + (2 * buttonSize)) && x < (xTotal + (2 * xAdd) + (3 * buttonSize))) && (y > (yTotal) && y < (yTotal + buttonSize)))
		return 9; //nine
	else if ((x > (xTotal + (3 * xAdd) + (3 * buttonSize)) && x < (xTotal + (3 * xAdd) + (4 * buttonSize))) && (y > (yTotal) && y < (yTotal + buttonSize)))
		return 11; //plus
	else if ((x > (xTotal + (4 * xAdd) + (4 * buttonSize)) && x < (xTotal + (4 * xAdd) + (5 * buttonSize))) && (y > (yTotal) && y < (yTotal + buttonSize)))
		return 15; //exponent
	else if ((x > xTotal && x < (xTotal + buttonSize)) && (y > (yTotal + (1 * yAdd) + (1 * buttonSize)) && y < (yTotal + (1 * yAdd) + (2 * buttonSize))))
		return 4; //four
	else if ((x > (xTotal + (1 * xAdd) + (1 * buttonSize)) && x < (xTotal + (1 * xAdd) + (2 * buttonSize))) && (y > (yTotal + (1 * yAdd) + (1 * buttonSize)) && y < (yTotal + (1 * yAdd) + (2 * buttonSize))))
		return 5; //five
	else if ((x > (xTotal + (2 * xAdd) + (2 * buttonSize)) && x < (xTotal + (2 * xAdd) + (3 * buttonSize))) && (y > (yTotal + (1 * yAdd) + (1 * buttonSize)) && y < (yTotal + (1 * yAdd) + (2 * buttonSize))))
		return 6; //six
	else if ((x > (xTotal + (3 * xAdd) + (3 * buttonSize)) && x < (xTotal + (3 * xAdd) + (4 * buttonSize))) && (y > (yTotal + (1 * yAdd) + (1 * buttonSize)) && y < (yTotal + (1 * yAdd) + (2 * buttonSize))))
		return 12; //minus
	else if ((x > (xTotal + (4 * xAdd) + (4 * buttonSize)) && x < (xTotal + (4 * xAdd) + (5 * buttonSize))) && (y > (yTotal + (1 * yAdd) + (1 * buttonSize)) && y < (yTotal + (1 * yAdd) + (2 * buttonSize))))
		return 16; //sign change
	else if ((x > xTotal && x < (xTotal + buttonSize)) && (y > (yTotal + (2 * yAdd) + (2 * buttonSize)) && y < (yTotal + (2 * yAdd) + (3 * buttonSize))))
		return 1; //one
	else if ((x > (xTotal + (1 * xAdd) + (1 * buttonSize)) && x < (xTotal + (1 * xAdd) + (2 * buttonSize))) && (y > (yTotal + (2 * yAdd) + (2 * buttonSize)) && y < (yTotal + (2 * yAdd) + (3 * buttonSize))))
		return 2; //two
	else if ((x > (xTotal + (2 * xAdd) + (2 * buttonSize)) && x < (xTotal + (2 * xAdd) + (3 * buttonSize))) && (y > (yTotal + (2 * yAdd) + (2 * buttonSize)) && y < (yTotal + (2 * yAdd) + (3 * buttonSize))))
		return 3; //three
	else if ((x > (xTotal + (3 * xAdd) + (3 * buttonSize)) && x < (xTotal + (3 * xAdd) + (4 * buttonSize))) && (y > (yTotal + (2 * yAdd) + (2 * buttonSize)) && y < (yTotal + (2 * yAdd) + (3 * buttonSize))))
		return 13; //times
	else if ((x > (xTotal + (4 * xAdd) + (4 * buttonSize)) && x < (xTotal + (4 * xAdd) + (5 * buttonSize))) && (y > (yTotal + (2 * yAdd) + (2 * buttonSize)) && y < (yTotal + (2 * yAdd) + (3 * buttonSize))))
		return 17; //mod
	else if ((x > xTotal && x < (xTotal + buttonSize)) && (y > (yTotal + (3 * yAdd) + (3 * buttonSize)) && y < (yTotal + (3 * yAdd) + (4 * buttonSize))))
		return 19; //clear
	else if ((x > (xTotal + (1 * xAdd) + (1 * buttonSize)) && x < (xTotal + (1 * xAdd) + (2 * buttonSize))) && (y > (yTotal + (3 * yAdd) + (3 * buttonSize)) && y < (yTotal + (3 * yAdd) + (4 * buttonSize))))
		return 0; //zero
	else if ((x > (xTotal + (2 * xAdd) + (2 * buttonSize)) && x < (xTotal + (2 * xAdd) + (3 * buttonSize))) && (y > (yTotal + (3 * yAdd) + (3 * buttonSize)) && y < (yTotal + (3 * yAdd) + (4 * buttonSize))))
		return 10; //equals
	else if ((x > (xTotal + (3 * xAdd) + (3 * buttonSize)) && x < (xTotal + (3 * xAdd) + (4 * buttonSize))) && (y > (yTotal + (3 * yAdd) + (3 * buttonSize)) && y < (yTotal + (3 * yAdd) + (4 * buttonSize))))
		return 14; //divide
	else if ((x > (xTotal + (4 * xAdd) + (4 * buttonSize)) && x < (xTotal + (4 * xAdd) + (5 * buttonSize))) && (y > (yTotal + (3 * yAdd) + (3 * buttonSize)) && y < (yTotal + (3 * yAdd) + (4 * buttonSize))))
		return 18; //factorial
	else
		return -1;
}
void runCalculator(const int windowWidth, const int windowHeight)
{
	string inputNumber = "0"; //preferred use of string concatenation because it would allow the use of a decimal button if added
	double storedNumber = 0;
	double storedNumberTwo = 0;
	int operationNumber = 0;

	//put code to have 0 on screen on load
	writeNumber(windowWidth, windowHeight, "0");

	while (true)
	{
		if (inputNumber == "Error")
			inputNumber = "0";

		int input = userInput(windowWidth, windowHeight);
		if (input == 19)
		{
			inputNumber = "0";
			storedNumber = 0;
		}
		else if (input == 0 && inputNumber != "0") //0
			inputNumber += to_string(static_cast<long double>(input));
		else if (input >= 1 && input <= 9)
		{
			if (inputNumber == "0") //other numbers
				inputNumber = to_string(static_cast<long double>(input));
			else
				inputNumber += to_string(static_cast<long double>(input));
		}
		else if (input > 10 && input < 18 && input != 16) //operations
		{
			if (operationNumber == 0)
			{
				storedNumber = atof(inputNumber.c_str());
				inputNumber = "0";
				operationNumber = input;
			}
		}
		else if (input == 16) //sign change
		{
			if (inputNumber != "0")
			{
				if (inputNumber[0] == '-')
					inputNumber = inputNumber.substr(1);
				else
					inputNumber = "-" + inputNumber;
			}
		}
		else if (input == 18) //factorial
		{
			inputNumber = to_string(static_cast<long double>(factorial(atof(inputNumber.c_str()))));
		}
		else if (input == 10) //equals scenario, will have a built in switch
		{
			if (storedNumber != 0)
			{
				storedNumberTwo = atof(inputNumber.c_str());

				switch (operationNumber)
				{
				case 11:
					inputNumber = to_string(static_cast<long double>(storedNumber + storedNumberTwo));
					break;
				case 12:
					inputNumber = to_string(static_cast<long double>(storedNumber - storedNumberTwo));
					break;
				case 13:
					inputNumber = to_string(static_cast<long double>(storedNumber * storedNumberTwo));
					break;
				case 14:
					if (storedNumberTwo != 0)
						inputNumber = to_string(static_cast<long double>(storedNumber / storedNumberTwo));
					else
						inputNumber = "Error";
					break;
				case 15:
					inputNumber = to_string(static_cast<long double>(pow (storedNumber, storedNumberTwo)));
					break;
				case 17:
					inputNumber = to_string(static_cast<long double>(fmod(storedNumber, storedNumberTwo)));
					break;
				case 18:
					inputNumber = to_string(static_cast<long double>(pow (storedNumber, storedNumberTwo)));
					break;
				default:
					break;
				}
				storedNumber = 0;
				storedNumberTwo = 0;
				operationNumber = 0;
			}
		}
		writeNumber(windowWidth, windowHeight, inputNumber);
	}
}

void main()
{
	int windowWidth = 500;
	int windowHeight = windowWidth; //in place in case you want to change height

	make_window(windowWidth, windowHeight);
	set_caption("Calculator");
	drawCalculator(windowWidth, windowHeight);
	runCalculator(windowWidth, windowHeight);
}