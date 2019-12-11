#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class HighContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				//Contrast = turn anything that could be a normal value into a much higher value
				//If a pixel is around half the value of a 'full' pixel then raise it to full
				//Other empty the value
				if (p.blue >= 127)
				{
					p.blue = 255;
				}
				else
				{
					p.blue = 0;
				}
				if (p.green >= 127)
				{
					p.green = 255;
				}
				else
				{
					p.green = 0;
				}
				if (p.red >= 127)
				{
					p.red = 255;
				}
				else
				{
					p.red = 0;
				}
				doc[i][j] = p;
			}
		}
	}
};