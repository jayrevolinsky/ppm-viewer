#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class NegateRedEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				p.red = 255 - p.red;

				doc[i][j] = p;
			}
		}
	}
};