#include<iostream>

using namespace std;

int CalculateArea(int width, int height)
{
	return width * height;
}

int CalculateArea(int width, int height, bool)
{
	return width * height / 2;
}



void main()
{

	cout << "»ç°¢Çü ³ÐÀÌ:";

	cout << CalculateArea(3, 4) << endl;

	cout << "»ï°¢Çü ³ÐÀÌ:";

	cout << CalculateArea(3, 4, true) << endl;

}



