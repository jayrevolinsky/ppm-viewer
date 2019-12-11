#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class FlipHorizontalEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		//Heres the link for help on how to flip an image: https://stackoverflow.com/questions/2647376/correct-flip-mirror-of-pixels-of-an-image
		//take the pixels that are located in columns
		//Thought Diagram:
		// x | x | y | y			y | y | x | x
		// x | x | y | y -----\		y | y | x | x
		// x | x | y | y -----/		y | y | x | x
		// x | x | y | y			y | y | x | x
		for (int i = 0; i < doc.getHeight(); i++)
		{
			//push those columns in reverse order
			//loading from the back of the photo first
				reverse(doc[i].begin(), doc[i].end());
		}
	}
};