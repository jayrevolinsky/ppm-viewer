#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class FlipVerticalEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int x = 0;
		int y = 0;
		int counter = 0;
		vector<vector<Pixel>> replace{};
		replace.resize(doc.getHeight());
		//Ensure that the photo retains the same shape and pixels, simply changing the position of said pixels
		//So, flip the pixels within the shot along a central x-axis
		for (int i = 0; i < doc.getHeight(); i++)
		{
			replace[i].resize(doc.getWidth());
		}
		// Thought diagram: 
		//  x | x | x | x				y | y | y | y
		//	x | x | x | x  ----\		y | y | y | y
		//	y | y | y | y  ----/        x | x | x | x
		//	y | y | y | y				x | x | x | x
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int k = 0; k < doc.getWidth(); k++)
			{
				replace[i][k] = doc[i][k];
			}
		}
		//Gradually the position of the pixels so that they are in the new place
		//
		for (int i = doc.getHeight() - 1; i >= 0; i--)
		{
			for (int k = 0; k < doc[i].size(); k++)
			{
				doc[counter][k] = replace[i][k];
				x++;
			}
			counter++;
			y++;
			x = 0;
		} 
	}
};