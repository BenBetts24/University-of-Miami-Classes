#include "library.h"
#include <fstream>
#include <tuple>
#include <algorithm>
#include <map>
#include <cstdlib>

void fileTop(ifstream& data)
{
	data.clear();
	data.seekg(0, ios::beg);
}
tuple <int, int, int, double, double, double, double, double, double> day_data(ifstream& data)
{
	/*
	index 0 = year
	index 1 = month
	index 2 = day
	index 3 = min
	index 4 = avg
	index 5 = max
	index 6 = depth
	index 7 = precipitation
	index 8 = mph
	*/

	int year, month, day;
	double min, avg, max, depth, precipitation, mph;
	data >> year >> month >> day >> min >> avg >> max >> depth >> precipitation >> mph;

	if (data.fail())
		return make_tuple(-1, -1, -1, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0);
	else
		return make_tuple(year, month, day, min, avg, max, depth, precipitation, mph);
}
int monthdays(const int month, const int year)
{
if (month == 4 || month == 6 || month == 9 || month == 11)
	return 30;

else if (month == 2 && (year % 4 == 0))
	{
	if (year % 400 == 0)
		return 29;
	else if (year % 100 == 0)
		return 28;
	else
		return 29;
	}

else if (month == 2)
	return 28;

else
	return 31;
}
int monthtotal(const int month, const int year)
{
if (month > 0)
	return (monthdays(month, year) + monthtotal(month - 1, year));
else
	return 0; 
}
int dayofyear(const int month, const int day, const int year)
{
return (day + monthtotal(month - 1, year));
}
tuple <double, double> minAndMax(const int index, ifstream& data)
{
	//returns a tuple with the min and max values for an index
	double max = -50;
	double min = 1000;

	switch (index)
	{
	case 3:
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<3>(dataTuple) < min && get<3>(dataTuple) != -1.0)
				min = get<3>(dataTuple);
		}
		if (min == 1000)
			min = -1.0;
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<3>(dataTuple) > max)
				max = get<3>(dataTuple);
		}
		break;
	case 4:
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<4>(dataTuple) < min && get<4>(dataTuple) != -1.0)
				min = get<4>(dataTuple);
		}
		if (min == 1000)
			min = -1.0;
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<4>(dataTuple) > max)
				max = get<4>(dataTuple);
		}
		break;
	case 5:
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<5>(dataTuple) < min && get<5>(dataTuple) != -1.0)
				min = get<5>(dataTuple);
		}
		if (min == 1000)
			min = -1.0;
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<5>(dataTuple) > max)
				max = get<5>(dataTuple);
		}
		break;
	case 6:
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<6>(dataTuple) < min && get<6>(dataTuple) != -1.0)
				min = get<6>(dataTuple);
		}
		if (min == 1000)
			min = -1.0;
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<6>(dataTuple) > max)
				max = get<6>(dataTuple);
		}
		break;
	case 7:
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<7>(dataTuple) < min && get<7>(dataTuple) != -1.0)
				min = get<7>(dataTuple);
		}
		if (min == 1000)
			min = -1.0;
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<7>(dataTuple) > max)
				max = get<7>(dataTuple);
		}
		break;
	case 8:
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<8>(dataTuple) < min && get<8>(dataTuple) != -1.0)
				min = get<8>(dataTuple);
		}
		if (min == 1000)
			min = -1.0;
		fileTop(data);
		while(!data.eof())
		{
			auto dataTuple = day_data(data);
			if (get<8>(dataTuple) > max)
				max = get<8>(dataTuple);
		}
		break;
	default:
		return make_tuple(-100.0, -100.0);
		break;
	}

	fileTop(data);
	return make_tuple(min, max);
}
void draw_choices()
{
	set_pen_color(color::black);
	int buttonSize = 120;
	int buttonDistance = 7;
	fill_rectangle(1200 - buttonDistance, 7, -buttonSize, 26);
	fill_rectangle(1200 - (2 * buttonDistance) - (1 * buttonSize), 7, -buttonSize, 26);
	fill_rectangle(1200 - (3 * buttonDistance) - (2 * buttonSize), 7, -buttonSize, 26);
	fill_rectangle(1200 - (4 * buttonDistance) - (3 * buttonSize), 7, -buttonSize, 26);
	fill_rectangle(1200 - (5 * buttonDistance) - (4 * buttonSize), 7, -buttonSize, 26);
	fill_rectangle(1200 - (6 * buttonDistance) - (5 * buttonSize), 7, -buttonSize, 26);
	set_pen_color(color::dark_grey);
	fill_rectangle(1200 - buttonDistance - 1, 7 + 1, -buttonSize + 2, 26 - 2);
	fill_rectangle(1200 - (2 * buttonDistance) - (1 * buttonSize) - 1, 7 + 1, -buttonSize + 2, 26 - 2);
	fill_rectangle(1200 - (3 * buttonDistance) - (2 * buttonSize) - 1, 7 + 1, -buttonSize + 2, 26 - 2);
	fill_rectangle(1200 - (4 * buttonDistance) - (3 * buttonSize) - 1, 7 + 1, -buttonSize + 2, 26 - 2);
	fill_rectangle(1200 - (5 * buttonDistance) - (4 * buttonSize) - 1, 7 + 1, -buttonSize + 2, 26 - 2);
	fill_rectangle(1200 - (6 * buttonDistance) - (5 * buttonSize) - 1, 7 + 1, -buttonSize + 2, 26 - 2);
	set_pen_color(color::black);
	move_to(1200 - buttonDistance - (buttonSize / 2), 20);
	write_string("Wind Speed", direction::center);
	move_to(1200 - (2 * buttonDistance) - (1 * buttonSize) - (buttonSize / 2), 20);
	write_string("Precipitation", direction::center);
	move_to(1200 - (3 * buttonDistance) - (2 * buttonSize) - (buttonSize / 2), 20);
	write_string("Snow Depth", direction::center);
	move_to(1200 - (4 * buttonDistance) - (3 * buttonSize) - (buttonSize / 2), 20);
	write_string("Max Temp", direction::center);
	move_to(1200 - (5 * buttonDistance) - (4 * buttonSize) - (buttonSize / 2), 20);
	write_string("Avg. Temp", direction::center);
	move_to(1200 - (6 * buttonDistance) - (5 * buttonSize) - (buttonSize / 2), 20);
	write_string("Min Temp", direction::center);

}
window* draw_graph()
{
	window * graph = make_window(1200, 690);
	//40 extra y pixels for buttons and stuff, graph space should start at y=40. [690 < y < 40]
	//x width of 1100. 

	//top menu background
	set_pen_color(color::light_grey);
	fill_rectangle(0,0,1200,40);
	set_pen_color(color::black);
	set_pen_width(2);
	move_to(0, 40);
	draw_to(1200, 40);
	set_pen_width(1);
	//buttons for top menu
	fill_rectangle(7, 7, 120, 26);
	set_pen_color(color::dark_grey);
	fill_rectangle(8, 8, 118, 24);
	move_to(13, 20);
	set_pen_color(color::black);
	write_string("Choose File", direction::east);

	//graph
	set_pen_width(1);
	move_to(50, 50);
	draw_to(50, 650);
	draw_to(1150, 650);
	draw_to(1150, 50);
	draw_to(50, 50);

	return graph;
}
void clearGraphAndText()
{
	set_pen_color(color::white);
	fill_rectangle(0, 40, 1200, 650);
	//graph
	set_pen_color(color::black);
	set_pen_width(1);
	move_to(50, 50);
	draw_to(50, 650);
	draw_to(1150, 650);
	draw_to(1150, 50);
	draw_to(50, 50);
	//redraw top under buttons for color
	set_pen_color(color::light_grey);
	fill_rectangle(0,33,1200,7);
	set_pen_color(color::black);
	set_pen_width(2);
	move_to(0, 40);
	draw_to(1200, 40);
	set_pen_width(1);
	//erase possible error message
	set_pen_color(color::light_grey);
	fill_rectangle(129, 0, 300, 39);
	set_pen_color(color::black);
}
void color_menu(const int x, const int y)
{
	//makes a window, fills it with color squares, get choice from UI function, deletes the window, returns the color
	int buttonSize = 120;
	int buttonDistance = 7;

	//draw background of menu
	set_pen_color(color::black);
	fill_rectangle(x, y, buttonSize, buttonSize);
	set_pen_color(color::white);
	fill_rectangle(x + 1, y + 1, buttonSize - 2, buttonSize - 2);

	//draw color options
	double colorSize = (buttonSize - 1) / 3;
	double z = 1.0;
	set_pen_color(color::red);
	fill_rectangle(x + z, y + z, colorSize, colorSize);
	set_pen_color(color::orange);
	fill_rectangle(x + z + colorSize, y + z, colorSize + 1, colorSize);
	set_pen_color(color::yellow);
	fill_rectangle(x + z + 1 + (2 * colorSize), y + z, colorSize, colorSize);
	set_pen_color(color::blue);
	fill_rectangle(x + z, y + z + colorSize, colorSize, colorSize + 1);
	set_pen_color(color::green);
	fill_rectangle(x + z + colorSize, y + z + colorSize, colorSize + 1, colorSize + 1);
	set_pen_color(color::purple);
	fill_rectangle(x + z + 1 + (2 * colorSize), y + z + colorSize, colorSize, colorSize + 1);
	set_pen_color(color::indigo);
	fill_rectangle(x + z, y + z + 1+ (2 * colorSize), colorSize, colorSize);
	set_pen_color(color::grey);
	fill_rectangle(x + z + colorSize, y + z + 1+ (2 * colorSize), colorSize + 1, colorSize);
	set_pen_color(color::black);
	fill_rectangle(x + z + 1 + (2 * colorSize), y + z + 1 + (2 * colorSize), colorSize, colorSize);
}
int userInterface(string windowType, const int xColor, const int yColor)
{
	if (windowType == "graph")
	{
		//do stuff on the main graph screen
		int buttonSize = 120;
		int buttonDistance = 7;
		while (true)
		{
			wait_for_mouse_click();
			int x = get_click_x();
			int y = get_click_y();
			if (y > 7 && y < 33)
			{
				if (x > 7 && x < 127)
					return 1; //choose file button
				else if (x < (1200 - (1 * buttonDistance)) && x > (1200 - ((1 * buttonDistance) + (1 * buttonSize))))
					return 8; //wind mph
				else if (x < (1200 - ((2 * buttonDistance) + (1 * buttonSize))) && x > (1200 - ((2 * buttonDistance) + (2 * buttonSize))))
					return 7; //precipitation
				else if (x < (1200 - ((3 * buttonDistance) + (2 * buttonSize))) && x > (1200 - ((3 * buttonDistance) + (3 * buttonSize))))
					return 6; //snow
				else if (x < (1200 - ((4 * buttonDistance) + (3 * buttonSize))) && x > (1200 - ((4 * buttonDistance) + (4 * buttonSize))))
					return 5; //max temp
				else if (x < (1200 - ((5 * buttonDistance) + (4 * buttonSize))) && x > (1200 - ((5 * buttonDistance) + (5 * buttonSize))))
					return 4; //avg. temp
				else if (x < (1200 - ((6 * buttonDistance) + (5 * buttonSize))) && x > (1200 - ((6 * buttonDistance) + (6 * buttonSize))))
					return 3; //min temp
			}
		}
	}
	else if (windowType == "color")
	{
		int buttonSize = 120;
		double colorSize = (buttonSize - 1) / 3;
		double z = 1.0;

		while (true)
		{
			wait_for_mouse_click();
			int x = get_click_x();
			int y = get_click_y();

			/*
			1 = Red
			2 = Orange
			3 = Yellow
			4 = Blue
			5 = Green
			6 = Purple
			7 = Indigo
			8 = Grey
			9 = Black
			*/

			if (y > (yColor + 1) && y < (yColor + (1 * colorSize) + 1))
			{
				if (x > (xColor + 1) && x < (xColor + (1 * colorSize) + 1))
					return 1;
				else if (x > (xColor + (1 * colorSize) + 1) && x < (xColor + (2 * colorSize) + 1))
					return 2;
				else if (x > (xColor + (2 * colorSize) + 1) && x < (xColor + (3 * colorSize) + 1))
					return 3;
			}
			else if (y > (yColor + colorSize + 1) && y < (yColor + (2 * colorSize) + 1))
			{
				if (x > (xColor + 1) && x < (xColor + (1 * colorSize) + 1))
					return 4;
				else if (x > (xColor + (1 * colorSize) + 1) && x < (xColor + (2 * colorSize) + 1))
					return 5;
				else if (x > (xColor + (2 * colorSize) + 1) && x < (xColor + (3 * colorSize) + 1))
					return 6;
			}
			else if (y > (yColor + (2 * colorSize) + 1) && y < (yColor + (3 * colorSize) + 1))
			{
				if (x > (xColor + 1) && x < (xColor + (1 * colorSize) + 1))
					return 7;
				else if (x > (xColor + (1 * colorSize) + 1) && x < (xColor + (2 * colorSize) + 1))
					return 8;
				else if (x > (xColor + (2 * colorSize) + 1) && x < (xColor + (3 * colorSize) + 1))
					return 9;
			}
		}
	}
}
tuple <double, double, double> draw_axes_and_return_increment(ifstream& data, const int year, double min, double max)
{
	double xIncrement = 1100/dayofyear(12, 31, year);
	double yIncrement;
	double yRange;
	string monthString[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	//labelling months and drawing vertical lines
	for (int month = 1; month <= 12; month++)
	{
		//vertical lines go here
		int dayCount = dayofyear(month, 0, year);
		move_to((dayCount * xIncrement) + 50.0, 650.0);
		draw_to((dayCount * xIncrement) + 50.0, 50.0);
		
		//writing month letters
		double letterPosition = ((dayCount * xIncrement) + ((monthdays(month, year) * xIncrement)/2));
		move_to(letterPosition + 50.0, 650.0);
		write_string(monthString[month - 1], direction::south);
	}

	//figuring out axis scaling
	/*auto minMax = minAndMax(index, data);
	double min = get<0>(minMax);
	double max = get<1>(minMax);*/

	//lets try something...


	set_pen_color(color::black);

	if(min >= 0 && max >= 0) //if all data is above 0
	{
		yRange = max;
		yIncrement = 600.0/max;
		double yGroup = max/10.0;

		for (int count = 0; count <= 10; count++)
		{
			move_to(50.0, (650.0 - (count * (yGroup * yIncrement))));
			draw_to(1150.0, (650.0 - (count * (yGroup * yIncrement))));
			move_to(50.0, (650.0 - (count * (yGroup * yIncrement))));
			write_double((count) * yGroup, direction::west);
		}
	}
	else if (min <= 0 && max <= 0) //if all data is under 0 (Haven't seen this but just in case? Should work)
	{
		yRange = -min;
		yIncrement = -600.0/min;
		double yGroup = min/10.0;

		for (int count = 10; count >= 0; count--)
		{
			move_to(50.0, (650.0 - (count * (yGroup * yIncrement))));
			draw_to(1150.0, (650.0 - (count * (yGroup * yIncrement))));
			move_to(50.0, (650.0 - (count * (yGroup * yIncrement))));
			write_double((count) * yGroup, direction::west);
		}
	}
	else //here comes the hard part
	{
		yRange = (max - min);
		yIncrement = 600.0/yRange;
		double yGroup = yRange/10.0;

		for (int count = 0; count <= 10; count++)
		{
			move_to(50.0, (650.0 - (count * (yGroup * yIncrement))));
			draw_to(1150.0, (650.0 - (count * (yGroup * yIncrement))));
			move_to(50.0, (650.0 - (count * (yGroup * yIncrement))));
			write_double((min + (count * yGroup)), direction::west);
		}

		//adding a 0 line
		set_pen_color(color::dark_blue);
		set_pen_width(2);
		move_to(50.0, (650.0 - (-min * yIncrement)));
		draw_to(1150.0, (650.0 - (-min * yIncrement)));
		write_string(" 0", direction::east);
		set_pen_color(color::black);
	}

	return make_tuple(xIncrement, yIncrement, min);
}
void draw_data(const int index, const double xIncrement, const double yIncrement, const double yMin, ifstream& data, tuple <int, int, int, double, double, double, double, double, double> & dataTuple, int color)
{
	/*
			1 = Red
			2 = Orange
			3 = Yellow
			4 = Blue
			5 = Green
			6 = Purple
			7 = Indigo
			8 = Grey
			9 = Black
	*/

	switch (color)
	{
	case 1:
		set_pen_color(color::red);
		break;
	case 2:
		set_pen_color(color::orange);
		break;
	case 3:
		set_pen_color(color::yellow);
		break;
	case 4:
		set_pen_color(color::blue);
		break;
	case 5:
		set_pen_color(color::green);
		break;
	case 6:
		set_pen_color(color::purple);
		break;
	case 7:
		set_pen_color(color::indigo);
		break;
	case 8:
		set_pen_color(color::grey);
		break;
	case 9:
		set_pen_color(color::black);
		break;
	}
	set_pen_width(2);
	switch(index)
	{
	case 3:
		{
		fileTop(data);
		bool firstPoint = true;
		int lastDay;
		while (!data.eof())
			{
				auto dataTuple = day_data(data);
				double value = get<3>(dataTuple);
				int dayValue = dayofyear(get<1>(dataTuple), get<2>(dataTuple), get<0>(dataTuple));

				if (yMin < 0)
					value += -yMin;

				if (firstPoint && value != -1)
				{
					move_to(50.0, 650.0 - (value * yIncrement));
					lastDay = dayValue;
					firstPoint = false;
				}
				else if (value != -1)
				{
					if (lastDay != (dayValue - 1))
					{
						move_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
						draw_point();
					}
					else
						draw_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
					lastDay = dayValue;
				}
			}
		}
		fileTop(data);
		break;
	case 4:
		{
		fileTop(data);
		bool firstPoint = true;
		int lastDay;
		while (!data.eof())
			{
				auto dataTuple = day_data(data);
				double value = get<4>(dataTuple);
				int dayValue = dayofyear(get<1>(dataTuple), get<2>(dataTuple), get<0>(dataTuple));

				if (yMin < 0)
					value += -yMin;

				if (firstPoint && value != -1)
				{
					move_to(50.0, 650.0 - (value * yIncrement));
					lastDay = dayValue;
					firstPoint = false;
				}
				else if (value != -1)
				{
					if (lastDay != (dayValue - 1))
					{
						move_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
						draw_point();
					}
					else
						draw_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
					lastDay = dayValue;
				}
			}
		}
		fileTop(data);
		break;
	case 5:
		{
		fileTop(data);
		bool firstPoint = true;
		int lastDay;
		while (!data.eof())
			{
				auto dataTuple = day_data(data);
				double value = get<5>(dataTuple);
				int dayValue = dayofyear(get<1>(dataTuple), get<2>(dataTuple), get<0>(dataTuple));

				if (yMin < 0)
					value += -yMin;

				if (firstPoint && value != -1)
				{
					move_to(50.0, 650.0 - (value * yIncrement));
					lastDay = dayValue;
					firstPoint = false;
				}
				else if (value != -1)
				{
					if (lastDay != (dayValue - 1))
					{
						move_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
						draw_point();
					}
					else
						draw_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
					lastDay = dayValue;
				}
			}
		}
		fileTop(data);
		break;
	case 6:
		{
		fileTop(data);
		bool firstPoint = true;
		int lastDay;
		while (!data.eof())
			{
				auto dataTuple = day_data(data);
				double value = get<6>(dataTuple);
				int dayValue = dayofyear(get<1>(dataTuple), get<2>(dataTuple), get<0>(dataTuple));

				if (yMin < 0)
					value += -yMin;

				if (firstPoint && value != -1)
				{
					move_to(50.0, 650.0 - (value * yIncrement));
					lastDay = dayValue;
					firstPoint = false;
				}
				else if (value != -1)
				{
					if (lastDay != (dayValue - 1))
					{
						move_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
						draw_point();
					}
					else
						draw_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
					lastDay = dayValue;
				}
			}
		}
		fileTop(data);
		break;
	case 7:
		{
		fileTop(data);
		bool firstPoint = true;
		int lastDay;
		while (!data.eof())
			{
				auto dataTuple = day_data(data);
				double value = get<7>(dataTuple);
				int dayValue = dayofyear(get<1>(dataTuple), get<2>(dataTuple), get<0>(dataTuple));

				if (yMin < 0 && value != -1)
					value += -yMin;

				if (firstPoint && value != -1)
				{
					move_to(50.0, 650.0 - (value * yIncrement));
					lastDay = dayValue;
					firstPoint = false;
				}
				else if (value != -1)
				{
					if (lastDay != (dayValue - 1))
					{
						move_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
						draw_point();
					}
					else
						draw_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
					lastDay = dayValue;
				}
			}
		}
		fileTop(data);
		break;
	case 8:
		{
		fileTop(data);
		bool firstPoint = true;
		int lastDay;
		while (!data.eof())
			{
				auto dataTuple = day_data(data);
				double value = get<8>(dataTuple);
				int dayValue = dayofyear(get<1>(dataTuple), get<2>(dataTuple), get<0>(dataTuple));

				if (yMin < 0)
					value += -yMin;

				if (firstPoint && value != -1)
				{
					move_to(50.0, 650.0 - (value * yIncrement));
					lastDay = dayValue;
					firstPoint = false;
				}
				else if (value != -1)
				{
					if (lastDay != (dayValue - 1))
					{
						move_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
						draw_point();
					}
					else
						draw_to(50.0 + (dayValue * xIncrement), 650.0 - (value * yIncrement));
					lastDay = dayValue;
				}
			}
		}
		fileTop(data);
		break;
	default:
		break;
	}
	set_pen_color(color::black);
	set_pen_width(1);
}
string run_graph(ifstream& data)
{
	//allow the user to choose the color that they want

	multimap <int, int> indexMap;
	indexMap.clear();
	int year;
	data >> year;
	fileTop(data);

	while (true)
	{

		fileTop(data);
		int index = userInterface("graph", 0, 0);
		int color;
		double range = 0;
		double min = 5000;
		double max = -5000;
		int scaleIndex = 0;

		if (indexMap.find(index) == indexMap.end() && index != 1) //if index not in set, adds it
		{
			color_menu(1200 - ((9 - index) * 127), 33);
			color = userInterface("color", 1200 - ((9 - index) * 127), 33);
			indexMap.insert(pair<int, int>(index, color));
			clearGraphAndText();
		}
		else //if the index is in the vector, it deletes it
			indexMap.erase(index);

		clearGraphAndText();

		if (!indexMap.empty())
		{
			if (index >= 3 && index <= 8) //changes made to the graph
			{
				for (multimap<int, int>::iterator it = indexMap.begin(); it != indexMap.end(); ++it)
				{
					auto minMax = minAndMax(it->first, data);
					double tempMin = get<0>(minMax);
					double tempMax = get<1>(minMax);

					if (tempMax > max && tempMax != -1)
						max = tempMax;
					if (tempMin < min && tempMin != -1)
						min = tempMin;
				}

				auto increments = draw_axes_and_return_increment(data, year, min, max);
				double xIncrement = get<0>(increments);
				double yIncrement = get<1>(increments);
				double yMin = get<2>(increments);
					
				for (multimap<int, int>::iterator it = indexMap.begin(); it != indexMap.end(); ++it)
				{
					auto minMax = minAndMax(it->first, data);
				
					if (get<0>(minMax) == -1 && get<1>(minMax) == -1)//checking if data exists before graphing
					{
						move_to(134, 20);
						set_pen_color(color::red);
						write_string("Error: Missing Data!", direction::east);
						set_pen_color(color::black);
					}
					
					else //if it does exist, graphing
					{
						auto dataTuple = day_data(data);
						draw_data(it->first, xIncrement, yIncrement, yMin, data, dataTuple, it->second);
					}
				}
			}
			else if (index == 1) //closes old file, returns new file path to be opened again
			{
				data.close();

				do
				{
					string file = open_file_pop_up("", "", "Select Data File");
					if (file != "" && file[file.length() - 3] == 't' && file[file.length() - 2] == 'x' && file[file.length() - 1] == 't') //also make sure that its a text file
						return file;
					else
					{
						set_pen_color(color::red);
						move_to(134, 20);
						write_string("Error: Please choose a valid file!", direction::east);
						set_pen_color(color::black);
					}
				}while (true);
			}
		}
		
	}
}

void main()
{
	hide_console();
	int input = 0;
	string file = "";
	ifstream data;

	while (true)
	{
		window * graph = draw_graph();
		set_caption(file);
			
		if (file == "")
		{
			while (input != 1 || !data.is_open() || !(file[file.length() - 3] == 't' && file[file.length() - 2] == 'x' && file[file.length() - 1] == 't'))
			{
				input = userInterface("graph", 0, 0);
				if (input == 1)
				{
					file = open_file_pop_up("", "", "Select Data File");
					if (file[file.length() - 3] == 't' && file[file.length() - 2] == 'x' && file[file.length() - 1] == 't')
						data.open(file);
				}
				set_pen_color(color::red);
				move_to(134, 20);
				write_string("Error: Please choose a valid file!", direction::east);
				set_pen_color(color::black);
			}
		}
		else
			data.open(file);
		
		clearGraphAndText();
		draw_choices();
		file = run_graph(data);
		hide_window();
	}
}
