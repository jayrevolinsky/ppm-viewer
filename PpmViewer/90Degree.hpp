#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class RotateEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		//The classic two dimensional vector
		//That way the image can be transposed
		vector<vector<Pixel>> change{};
		//Store the values of the height into width
		//And the values of width into height
		int replacew = doc.getHeight();
		int replaceh = doc.getWidth();
		//'Change' so that it fits the proper dimensions
		change.resize(replaceh);
		for (int i = 0; i < change.size(); i++)
		{
			change[i].resize(replacew);
		}
		//Let the computer know that they need to sort through the image
		//Using the principle of translation in math
		//Take one point, keeping in mind the original point (store the original point in a new value for safekeeping)
		for (int i = 0; i < doc.getWidth(); i++)
		{
			vector<Pixel> storevalue;
			for (int j = doc.getHeight() - 1; j >= 0; j--)
			{
				storevalue.push_back(doc[j][i]);
			}
			change[i] = storevalue;
		}

		//Push all the dimensions to a new angle
		//Starting from the edges
		doc.setHeight(replaceh);
		doc.setWidth(replacew);
		//Push all the pixels to a new position
		//Separating them by edges
		doc.shiftY(replaceh);
		doc.shiftX(replacew);

		//Finally show the changes that were made 
		//
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				doc[i][j] = change[i][j];
			}
		}
	}
};