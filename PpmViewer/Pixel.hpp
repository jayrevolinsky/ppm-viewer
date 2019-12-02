#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <istream>
#include <exception>
using namespace std;

class Pixel
{
public:
	
	int red = -1;
	int green = -1;
	int blue = -1;
};

istream& operator>>(istream& stream, Pixel& pixel)
{
	stream >> pixel.red >> pixel.green >> pixel.blue;
	return stream;
}

ostream& operator<<(ostream& stream, const Pixel& pixel)
{
	stream << pixel.red << " " << pixel.green << " " << pixel.blue;
	return stream;
}

#endif // !PIXEL_H
