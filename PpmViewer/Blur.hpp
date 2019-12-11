#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class BlurEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int gray = 0;
		for (int i = 0; i < doc.getHeight(); i++)
		{

			for (int k = 0; k < doc.getWidth(); k++)
			{
				//The logic of the edge checking usually follows a set system, the check makes sure that the computer does not commit an
				//action that will cause it to manipulate data outside of the ppm document (causing an error). 
				//then it tells the computer to parse through the document in a way that works for the set conditions, pixel by pixel.
				//It then "blurs" the image by taking the 'legal' area of the pixels and averaging the values together.
				//The key distinction between the blurring of the pixelling and not darkening the image is that the division operation 
				//never operates on more than the amount of variables present. IF you do divide by more than the variables present, each
				//cumulative press of the button will darken the image or the specificed position.

				if (k == 0 && i == 0) //Edge check, is it at the start point of the ppm document? If yes, then move along
				{
					//Each individual division is like an extra filter
					int avg_r = (doc[i][k].red + doc[i][(k + 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k + 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k + 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i + 1)][k].red) / 2;
					int simple_g = (avg_g + doc[(i + 1)][k].green) / 2;
					int simple_b = (avg_b + doc[(i + 1)][k].blue) / 2;

					int blur_r = (simple_r + doc[(i + 1)][k + 1].red) / 2;
					int blur_g = (simple_g + doc[(i + 1)][k + 1].green) / 2;
					int blur_b = (simple_b + doc[(i + 1)][k + 1].blue) / 2;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if (i == 0 && (k + 1) == doc[i].size()) //Edge check, is it near the top (but not the start) of the ppm document?
				{
					int avg_r = (doc[i][k].red + doc[i][(k - 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k - 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k - 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i + 1)][k].red) / 2;
					int simple_g = (avg_g + doc[(i + 1)][k].green) / 2;
					int simple_b = (avg_b + doc[(i + 1)][k].blue) / 2;

					int blur_r = (simple_r + doc[(i + 1)][k - 1].red) / 2;
					int blur_g = (simple_g + doc[(i + 1)][k - 1].green) / 2;
					int blur_b = (simple_b + doc[(i + 1)][k - 1].blue) / 2;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if (i == 0) //Just chug along the top of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k + 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k + 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k + 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i + 1)][k].red) / 2;
					int simple_g = (avg_g + doc[(i + 1)][k].green) / 2;
					int simple_b = (avg_b + doc[(i + 1)][k].blue) / 2;

					int blur_r = (simple_r + doc[(i + 1)][k + 1].red) / 2;
					int blur_g = (simple_g + doc[(i + 1)][k + 1].green) / 2;
					int blur_b = (simple_b + doc[(i + 1)][k + 1].blue) / 2;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if ((i + 1) == doc.getHeight() && k == 0) //Move along the rows of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k + 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k + 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k + 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i - 1)][k].red) / 2;
					int simple_g = (avg_g + doc[(i - 1)][k].green) / 2;
					int simple_b = (avg_b + doc[(i - 1)][k].blue) / 2;

					int blur_r = (simple_r + doc[(i - 1)][k + 1].red) / 2;
					int blur_g = (simple_g + doc[(i - 1)][k + 1].green) / 2;
					int blur_b = (simple_b + doc[(i - 1)][k + 1].blue) / 2;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if ((i + 1) == doc.getHeight() && (k + 1) == doc[i].size()) //Move along the rows and columns of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k - 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k - 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k - 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i - 1)][k].red) / 2;
					int simple_g = (avg_g + doc[(i - 1)][k].green) / 2;
					int simple_b = (avg_b + doc[(i - 1)][k].blue) / 2;

					int blur_r = (simple_r + doc[(i - 1)][k - 1].red) / 2;
					int blur_g = (simple_g + doc[(i - 1)][k - 1].green) / 2;
					int blur_b = (simple_b + doc[(i - 1)][k - 1].blue) / 2;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if ((i + 1) == doc.getHeight()) //move along the row of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k + 1)].red + doc[i][(k - 1)].red) / 3;
					int avg_g = (doc[i][k].green + doc[i][(k + 1)].green + doc[i][(k - 1)].green) / 3;
					int avg_b = (doc[i][k].blue + doc[i][(k + 1)].blue + doc[i][(k - 1)].blue) / 3;

					int simple_r = (avg_r + doc[(i - 1)][k].red) / 2;
					int simple_g = (avg_g + doc[(i - 1)][k].green) / 2;
					int simple_b = (avg_b + doc[(i - 1)][k].blue) / 2;

					int blur_r = (simple_r + doc[(i - 1)][k + 1].red) / 2;
					int blur_g = (simple_g + doc[(i - 1)][k + 1].green) / 2;
					int blur_b = (simple_b + doc[(i - 1)][k + 1].blue) / 2;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if (i == 0 && (k + 1) == doc[i].size()) //Edge check, is it near the top (but not the start) of the ppm document?
				{
				int avg_r = (doc[i][k].red + doc[i][(k - 1)].red) / 2;
				int avg_g = (doc[i][k].green + doc[i][(k - 1)].green) / 2;
				int avg_b = (doc[i][k].blue + doc[i][(k - 1)].blue) / 2;

				int simple_r = (avg_r + doc[(i + 1)][k].red) / 2;
				int simple_g = (avg_g + doc[(i + 1)][k].green) / 2;
				int simple_b = (avg_b + doc[(i + 1)][k].blue) / 2;

				int blur_r = (simple_r + doc[(i + 1)][k - 1].red) / 2;
				int blur_g = (simple_g + doc[(i + 1)][k - 1].green) / 2;
				int blur_b = (simple_b + doc[(i + 1)][k - 1].blue) / 2;

				doc[i][k].red = blur_r;
				doc[i][k].green = blur_g;
				doc[i][k].blue = blur_b;
				}
				else if (k == 0) //When you reach the edge of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k + 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k + 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k + 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i + 1)][k].red + doc[(i - 1)][k].red) / 3;
					int simple_g = (avg_g + doc[(i + 1)][k].green + doc[(i - 1)][k].green) / 3;
					int simple_b = (avg_b + doc[(i + 1)][k].blue + doc[(i - 1)][k].blue) / 3;

					int blur_r = (simple_r + doc[(i - 1)][k].red + doc[(i + 1)][k].red) / 3;
					int blur_g = (simple_g + doc[(i - 1)][k].green + doc[(i + 1)][k].green) / 3;
					int blur_b = (simple_b + doc[(i - 1)][k].blue + doc[(i + 1)][k].blue) / 3;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else if ((k + 1) == doc.getWidth()) //If you are not along the edge of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k - 1)].red) / 2;
					int avg_g = (doc[i][k].green + doc[i][(k - 1)].green) / 2;
					int avg_b = (doc[i][k].blue + doc[i][(k - 1)].blue) / 2;

					int simple_r = (avg_r + doc[(i + 1)][k].red + doc[(i - 1)][k].red) / 3;
					int simple_g = (avg_g + doc[(i + 1)][k].green + doc[(i - 1)][k].green) / 3;
					int simple_b = (avg_b + doc[(i + 1)][k].blue + doc[(i - 1)][k].blue) / 3;

					int blur_r = (simple_r + doc[(i - 1)][k].red + doc[(i + 1)][k].red) / 3;
					int blur_g = (simple_g + doc[(i - 1)][k].green + doc[(i + 1)][k].green) / 3;
					int blur_b = (simple_b + doc[(i - 1)][k].blue + doc[(i + 1)][k].blue) / 3;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
				else //Somewhere in the middle of the ppm document
				{
					int avg_r = (doc[i][k].red + doc[i][(k + 1)].red + doc[i][(k - 1)].red) / 3;
					int avg_g = (doc[i][k].green + doc[i][(k - 1)].green + doc[i][(k + 1)].green) / 3;
					int avg_b = (doc[i][k].blue + doc[i][(k + 1)].blue + doc[i][(k - 1)].blue) / 3;

					int simple_r = (avg_r + doc[(i + 1)][k].red + doc[(i - 1)][k].red) / 3;
					int simple_g = (avg_g + doc[(i + 1)][k].green + doc[(i - 1)][k].green) / 3;
					int simple_b = (avg_b + doc[(i + 1)][k].blue + doc[(i - 1)][k].blue) / 3;

					int blur_r = (simple_r + doc[(i - 1)][k].red + doc[(i + 1)][k].red) / 3;
					int blur_g = (simple_g + doc[(i - 1)][k].green + doc[(i + 1)][k].green) / 3;
					int blur_b = (simple_b + doc[(i - 1)][k].blue + doc[(i + 1)][k].blue) / 3;

					doc[i][k].red = blur_r;
					doc[i][k].green = blur_g;
					doc[i][k].blue = blur_b;
				}
			}
		}
	}
};