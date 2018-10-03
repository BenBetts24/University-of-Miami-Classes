#include "library.h"
int dayOrNight;

void drawDashes()
{
	int x;
	for (x = 0; x < 1110; x += 40)
	fill_rectangle(10 + x, 564, 30, 2);
}
void createScreenWithBackground()
{
	make_window(1100, 650);
	if (dayOrNight > 5) //day
	{
		set_pen_color_int(144, 228, 245);
		fill_rectangle(0, 0, 1110, 660);
		set_pen_color(color::yellow);
		set_pen_width(100);
		move_to(850, 200);
		draw_point();
		set_pen_color_int(43, 199, 19);
		fill_rectangle(0, 475, 1110, 185);
		set_pen_color(color::black);
		fill_rectangle(0, 505, 1110, 120);
		set_pen_color(color::yellow);
		fill_rectangle(0, 510, 1110, 2);
		fill_rectangle(0, 618, 1110, 2);
		drawDashes();
	}
	else if (dayOrNight <= 5) // night
	{
		set_pen_color_int(69, 18, 235);
		fill_rectangle(0, 0, 1110, 660);
		set_pen_color(color::white);
		set_pen_width(100);
		move_to(250, 150);
		draw_point();
		set_pen_color_int(19, 97, 7);
		fill_rectangle(0, 475, 1110, 185);
		set_pen_color(color::black);
		fill_rectangle(0, 505, 1110, 120);
		set_pen_color_int(188, 173, 45);
		fill_rectangle(0, 510, 1110, 2);
		fill_rectangle(0, 618, 1110, 2);
		drawDashes();
	}
}
void drawWindow(const int x, const int y, const int width, const int height, const int color)
{
	int dark;
	if (dayOrNight > 5)
		dark = 0;
	else
		dark = 20;

	if (color == 1 || color == 2) //night off
	{
		set_pen_color(color::black);
		fill_rectangle(x, y, width, height);
	}
	else if (color == 3) //night on
	{
		set_pen_color_int(239, 246, 137);
		fill_rectangle(x, y, width, height);
	}
	else if (color == 4) //day blue
	{
		set_pen_color_int(34, 15, 97);
		fill_rectangle(x, y, width, height);
	}
	else if (color == 5) //day silver
	{
		set_pen_color_int(98, 120, 139);
		fill_rectangle(x, y, width, height);
	}
	else if (color > 5) //house window
	{
		set_pen_color_int(173 - dark, 231 - dark, 243 - dark);
		fill_rectangle(x, y, width, height);
	}
}
void drawFloor(const int house, const int number, int x, const int y, const int width, const int height)
{
	int houseAdd;

	if (dayOrNight > 5) //day
	{
		if (house == 1)
			houseAdd = 2;
		else
			houseAdd = 0;

		for (int count = 0; count < number; count++)
		{
			drawWindow(x, y, width, height, random_in_range(4 + houseAdd, 5 + houseAdd));
			x = x + width + 20;
		}
	}
	else //night
	{
		if (house == 1)
			houseAdd = 5;
		else
			houseAdd = 0;

		for (int count = 0; count < number; count++)
		{
			drawWindow(x, y, width, height, random_in_range(1 + houseAdd,3 + houseAdd));
			x = x + width + 20;
		}
	}
}
void drawBlock(const int floornum, const int windownum, const int x, int y, const int width, const int height)
{
	if (floornum > 0)
	{
		drawFloor(0,windownum, x, y, width, height);
		drawBlock(floornum - 1, windownum, x, y - height - 30, width, height);
	}
}
void drawBuilding(const int x, const int y, int width)
{
	int color = random_in_range(1, 18);
	int floornum = random_in_range(4, 6);
	int winwidth = random_in_range(30, 50);
	int winheight = random_in_range(30, 50);
	int windnum = width / (winwidth + 20);
	width = width - (width % (winwidth + 20)) - 7;

	int dark;
	if (dayOrNight > 5)
		dark = 0;
	else
		dark = 20;

	if (color == 1 || color == 2 || color == 3) {
		set_pen_color_int(147 - dark, 155 - dark, 193 - dark);
		fill_rectangle(x, y, width, -floornum * (winheight + 30));
		drawBlock(floornum, windnum, x + 7, y - 7 - winheight, winwidth, winheight);
	}
	else if (color == 4 || color == 5 || color == 6) {
		set_pen_color_int(135 - dark, 155 - dark, 193 - dark);
		fill_rectangle(x, y, width, -floornum * (winheight + 30));
		drawBlock(floornum, windnum, x + 7, y - 7 - winheight, winwidth, winheight);
	}
	else if (color == 7 || color == 8 || color == 9) {
		set_pen_color_int(152 - dark, 103 - dark, 128 - dark);
		fill_rectangle(x, y, width, -floornum * (winheight + 30));
		drawBlock(floornum, windnum, x + 7, y - 7 - winheight, winwidth, winheight);
	}
	else if (color == 10 || color == 11 || color == 12) {
		set_pen_color_int(121 - dark, 154 - dark, 144 - dark);
		fill_rectangle(x, y, width, -floornum * (winheight + 30));
		drawBlock(floornum, windnum, x + 7, y - 7 - winheight, winwidth, winheight);
	}
	else if (color == 13 || color == 14 || color == 15) {
		set_pen_color_int(155 - dark, 121 - dark, 99 - dark);
		fill_rectangle(x, y, width, -floornum * (winheight + 30));
		drawBlock(floornum, windnum, x + 7, y - 7 - winheight, winwidth, winheight);
	}
	else if (color == 16 || color == 17 || color == 18) {
		set_pen_color_int(185 - dark, 186 - dark, 143 - dark);
		fill_rectangle(x, y, width, -floornum * (winheight + 30));
		drawBlock(floornum, windnum, x + 7, y - 7 - winheight, winwidth, winheight);
	}
}
void drawHouseWindows(const int floornum, int x, const int y)
{
	int doorPosition = 14; //random_in_range(1, 12);

	if (floornum == 2)
		drawFloor(1, 3, x + 8, y - 110, 45, 30);
	if (doorPosition < 6)
	{
		set_pen_color(color::dark_red);
		fill_rectangle(x + 17, y - 60, 30, 60);
		drawFloor(1, 2, x + 73, y - 60, 45, 30);
	}
	else if (doorPosition >= 6 && doorPosition < 12)
	{
		set_pen_color(color::dark_green);
		fill_rectangle(x + 146, y - 60, 30, 60);
		drawFloor(1, 2, x + 8, y - 60, 45, 30);
	}
	else
	{
		drawWindow(x + 8, y - 60, 45, 30, 6);
		set_pen_color(color::dark_red);
		fill_rectangle(x + 81, y - 60, 30, 60);
		drawWindow(x + 139, y - 60, 45, 30, 6);
	}
}
void drawHouse(const int x, const int y)
{
	int floorrand = random_in_range(1, 10);
	int winwidth = 45;
	int winheight = 30;
	int floornum;

	if (floorrand > 5)
		floornum = 2;
	else
		floornum = 1;

	int dark;
	if (dayOrNight > 5)
		dark = 0;
	else
		dark = 35;

	//building
	set_pen_color_int(220 - dark, 235 - dark, 173 - dark);
	fill_rectangle(x, y, 190, -floornum * (winheight + 36));
	drawHouseWindows(floornum, x, y);
	
	//roof
	if (floornum == 2)
	{
		start_shape();
		move_to(x - 16, y - (floornum * (winheight + 36)));
		note_position();
		move_to(x + 95, y - 50 - (floornum * (winheight + 36)));
		note_position();
		move_to(x + 206, y - (floornum * (winheight + 36)));
		note_position();
		set_pen_color(color::brown);
		set_pen_width(1);
		fill_shape();
	}
	else
	{
		start_shape();
		move_to(x - 16, y - (floornum * (winheight + 36)));
		note_position();
		move_to(x + 63, y - 30 - (floornum * (winheight + 36)));
		note_position();
		move_to(x + 127, y - 30 - (floornum * (winheight + 36)));
		note_position();
		move_to(x + 206, y - (floornum * (winheight + 36)));
		note_position();
		set_pen_color(color::brown);
		set_pen_width(1);
		fill_shape();
	}
}
void drawCityBlock(const int x, const int y)
{
	int xTotal = x;

	while (xTotal < 850)
	{
		int houseOrTower = random_in_range(1, 10);
		int xAdd = random_in_range(35, 60);
		int width = random_in_range(200, 275);

		if (houseOrTower >= 5)
		{
			drawBuilding(xTotal + xAdd, y, width);
			xTotal += xAdd + width;
		}
		else
		{
			drawHouse(xTotal, y);
			xTotal += xAdd + 215;
		}
	}
}
void drawBush(const int x, const int y, const int width, const int height)
{
	set_pen_width(5);
	double grow = 0.0;
	for (int count = 0; count < 800; count++)
	{
		set_pen_color_int(random_in_range(69, 117) + 30, random_in_range(102, 160) + 30, random_in_range(20, 60) + 30);
		move_to(x + random_in_range(-width + 15 - grow, width - 15 + grow), y - random_in_range(-height + 15 - grow, height - 15 + grow));
		draw_point();
		grow += 0.02;
	}
	for (int count = 0; count < random_in_range(3, 8); count++)
	{
		set_pen_color(color::red);
		move_to(x + random_in_range(-width + 10, width - 10), y - random_in_range(-height + 10, height - 10));
		draw_point();
		
	}
}
void drawTree(const int x, const int y)
{
	int treeHeight = -random_in_range(40, 60);
	set_pen_color(color::brown);
	fill_rectangle(x, y, 15, treeHeight);
	drawBush(x + 7, y + treeHeight - 15, random_in_range(20, 30), random_in_range(35, 50));
}
void drawGreens(const int x, const int y)
{
	{
	int xTotal = x;

	while (xTotal < 950)
	{
		int treeOrBush = random_in_range(1, 10);
		int xAdd = random_in_range(80, 110);

		if (treeOrBush >= 5)
		{
			drawTree(xTotal + xAdd, y);
			xTotal += xAdd + 60;
		}
		else
		{
			int bushWidth = random_in_range(35, 50);
			drawBush(xTotal + xAdd, y - (bushWidth/2), bushWidth, random_in_range(20, 35));
			xTotal += xAdd + bushWidth;
		}
	}
}
}
int drawCar(const int x, const int y, const int direction) // -1 = left, 1 = right
{
	int carType = random_in_range(1, 18); // divided by 3. car, pickup, cargo truck.
	int color = random_in_range(1, 30);

	int dark;
	if (dayOrNight > 5)
		dark = 0;
	else
		dark = 20;

	if (color <=6)
		set_pen_color_int(15, 6, 47); //black so no dark subraction
	else if (color > 6 && color <= 12)
		set_pen_color_int(239 - dark, 239 - dark, 239 - dark);
	else if (color > 12 && color <= 18)
		set_pen_color_int(80 - dark, 34 - dark, 229 - dark);
	else if (color > 18 && color <= 24)
		set_pen_color_int(219 - dark, 40 - dark, 82 - dark);
	else if (color > 24)
		set_pen_color_int(40 - dark, 156 - dark, 32 - dark);

	if (carType <= 6)
	{
		//body
		start_shape();
		move_to(x, y);
		note_position();
		move_to(x, y - 20);
		note_position();
		move_to(x + (30 * direction), y - 45);
		note_position();
		move_to(x + (90 * direction), y - 45);
		note_position();
		move_to(x + (120 * direction), y - 20);
		note_position();
		move_to(x + (120 * direction), y);
		note_position();
		set_pen_width(1);
		fill_shape();
		//window 1
		start_shape();
		move_to(x + (90 * direction), y - 40);
		note_position();
		move_to(x + (115 * direction), y - 20);
		note_position();
		move_to(x + (90 * direction), y - 20);
		note_position();
		set_pen_color_int(117 - dark, 230 - dark, 238 - dark);
		fill_shape();
		//window 2
		start_shape();
		move_to(x + (30 * direction), y - 40);
		note_position();
		move_to(x + (5 * direction), y - 20);
		note_position();
		move_to(x + (30 * direction), y - 20);
		note_position();
		fill_shape();
		//windows 3 and 4
		fill_rectangle(x + (35 * direction), y - 40, 22 * direction, 21);
		fill_rectangle(x + (63 * direction), y - 40, 22 * direction, 21);
		//wheels
		set_pen_width(25);
		set_pen_color_int(84, 83, 83);
		move_to(x + (25 * direction), y);
		draw_point();
		move_to(x + (95 * direction), y);
		draw_point();
		return 120;
	}
	else if (carType > 6 && carType <= 12)
	{
		//pickup truck
		start_shape();
		move_to(x, y);
		note_position();
		move_to(x, y - 23);
		note_position();
		move_to(x + (65 * direction), y - 23);
		note_position();
		move_to(x + (65 * direction), y - 45);
		note_position();
		move_to(x + (90 * direction), y - 45);
		note_position();
		move_to(x + (120 * direction), y - 23);
		note_position();
		move_to(x + (120 * direction), y);
		note_position();
		set_pen_width(1);
		fill_shape();
		//window 1
		start_shape();
		move_to(x + (90 * direction), y - 40);
		note_position();
		move_to(x + (115 * direction), y - 21);
		note_position();
		move_to(x + (90 * direction), y - 21);
		note_position();
		set_pen_color_int(117 - dark, 230 - dark, 238 - dark);
		fill_shape();
		//window 2
		fill_rectangle(x + (68 * direction), y - 40, 18 * direction, 20);
		//wheels
		set_pen_width(25);
		set_pen_color_int(84, 83, 83);
		move_to(x + (25 * direction), y);
		draw_point();
		move_to(x + (95 * direction), y);
		draw_point();
		return 120;
	}
	else if (carType > 12)
	{
		//body
		fill_rectangle(x, y, 120 * direction, -50);
		fill_rectangle(x + (120 * direction), y, 25 * direction, -5);
		fill_rectangle(x + (125 * direction), y, 25 * direction, -30);
		//wheels
		set_pen_width(25);
		set_pen_color_int(84, 83, 83);
		move_to(x + (25 * direction), y);
		draw_point();
		move_to(x + (95 * direction), y);
		draw_point();
		set_pen_width(15);
		move_to(x + (135 * direction), y + 3);
		draw_point();
		//window
		set_pen_color_int(117 - dark, 230 - dark, 238 - dark);
		fill_rectangle(x + (128 * direction), y - 12, 19 * direction, -16);
		return 135;
	}
}
void drawTraffic()
{
	int xTotal = 0;

	while (xTotal < 860) //top cars going left
	{
		int xAdd = random_in_range(40, 150);
		int carWidth = drawCar(1100 - xTotal - xAdd, 533, -1);
		xTotal += xAdd + carWidth;
	}

	xTotal = 0;

	while (xTotal < 860) //bottom cars going right
	{
		int xAdd = random_in_range(40, 150);
		int carWidth = drawCar(xTotal + xAdd, 595, 1);
		xTotal += xAdd + carWidth;
	}
}

void main()
{
	dayOrNight = random_in_range(1,10);
	cout << dayOrNight;
	createScreenWithBackground();
	drawCityBlock(20, 485);
	drawGreens(20, 485);
	drawTraffic();
}