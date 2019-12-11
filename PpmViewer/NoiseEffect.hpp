#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class NoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				//'noise' in a photo is random, like static on a TV set.
				int random = (rand() % 16); 
				//Limit the value of the random number to prevent vector erros
				int randnumber = random - 8; 
				//Go through each pixel
				//Taking advantage of class functions
				if ((p.red + randnumber) >= 255)
				{
					p.red = 255;
				}
				else if ((p.red - randnumber) <= 0)
				{
					p.red = 0;
				}
				else
				{
					p.red = p.red + randnumber;
				}
				
				if ((p.green + randnumber) >= 255)
				{
					p.green = 255;
				}
				else if ((p.green - randnumber) <= 0)
				{
					p.green = 0;
				}
				else
				{
					p.green = p.green + randnumber;
				}
				
				if ((p.blue + randnumber) >= 255)
				{
					p.blue = 255;
				}
				else if ((p.blue - randnumber) <= 0)
				{
					p.blue = 0;
				}
				else
				{
					p.blue = p.blue + randnumber;
				}
				doc[i][j] = p;
			}
		}
	}
};