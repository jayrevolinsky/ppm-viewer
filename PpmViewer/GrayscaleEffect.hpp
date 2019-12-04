#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class GrayscaleEffect : public ImageEffect //to grayscale is to average out the values
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int gray = 0;
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				gray = (p.red + p.green + p.blue) / 3;
				p.blue = gray;
				p.green = gray;
				p.red = gray;

				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};