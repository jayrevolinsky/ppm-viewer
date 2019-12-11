#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class FlipHorizontalEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
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