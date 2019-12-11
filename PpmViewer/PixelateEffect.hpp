#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class PixelateEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		//The link below was helpful for learning how to pixelate an image:
		//https://www.howtobuildsoftware.com/index.php/how-do/b9bP/c-arrays-image-image-processing-how-can-i-pixelate-a-1d-array
		for (int i = 0; i < doc.getHeight(); i += 3)
		{
			for (int j = 0; j < doc.getWidth(); j +=3 )
			{
				Pixel& p = doc[i][j];
				//Parse through certain values of the pixel and then affect the area around that said pixel
				//Right one pixel and up one pixel
				if (i + 1 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
				}
				//Right two pixels and up two pixels
				else if (i + 2 == doc.getHeight() && j + 2 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p; //up one pixel
					doc[i + 1][j] = p; //right one pixel
					doc[i + 1][j + 1] = p; // up one, right one
				}
				//Right two pixels and up one pixel
				else if (i + 2 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i + 1][j] = p;
				}
				//Right one pixel and up two pixels
				else if (i + 1 == doc.getHeight() && j + 2 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
				}
				//Right one pixel
				else if (i + 1 == doc.getHeight())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i][j + 2] = p;
				}
				//Right two pixels
				else if (i + 2 == doc.getHeight())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i][j + 2] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
					doc[i + 1][j + 2] = p;
				}
				//Up one pixel
				else if (j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i + 1][j] = p;
					doc[i + 2][j] = p;
				}
				//Up two pixels
				else if (j + 2 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
					doc[i + 2][j] = p;
					doc[i + 2][j + 1] = p;
				} //Change the area three pixels around
				else 
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i][j + 2] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
					doc[i + 1][j + 2] = p;
					doc[i + 2][j] = p;
					doc[i][j + 2] = p;
					doc[i + 2][j + 2] = p;

				}
			}
		}
	}
};