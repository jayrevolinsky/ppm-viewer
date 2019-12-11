#pragma once
#include "RemoveRedEffect.hpp"
#include "RemoveGreenEffect.hpp"
#include "RemoveBlueEffect.hpp"
#include "NegateRedEffect.hpp"
#include "NegateGreenEffect.hpp"
#include "NegateBlueEffect.hpp"
#include "GrayscaleEffect.hpp"
#include "NoiseEffect.hpp"
#include "HighContrastEffect.hpp"
#include "FlipHorizontalEffect.hpp"
#include "FlipVerticalEffect.hpp"
#include "Blur.hpp"
#include "PixelateEffect.hpp"
#include "90Degree.hpp"

enum class ImageEffectType
{
	RemoveRed = 1,
	RemoveGreen,
	RemoveBlue,
	NegateRed,
	NegateGreen,
	NegateBlue,
	Grayscale,
	Noise,
	HighContrast,
	FlipHorizontal,
	FlipVertical,
	Blur,
	Pixelate,
	Rotate
	//TODO: add rest below
};

class EffectFactory
{
public:
	static ImageEffect* createEffect(ImageEffectType effect_type)
	{
		switch (effect_type)
		{
		case ImageEffectType::RemoveRed:
			return new RemoveRedEffect{};
			break;

		case ImageEffectType::RemoveGreen:
			return new RemoveGreenEffect{};
			break;

		case ImageEffectType::RemoveBlue:
			return new RemoveBlueEffect{};
			break;

		case ImageEffectType::NegateRed:
			return new NegateRedEffect{};
			break;

		case ImageEffectType::NegateGreen:
			return new NegateGreenEffect{};
			break;

		case ImageEffectType::NegateBlue:
			return new NegateBlueEffect{};
			break;

		case ImageEffectType::Grayscale:
			return new GrayscaleEffect{};
			break;

		case ImageEffectType::Noise:
			return new NoiseEffect{};
			break;

		case ImageEffectType::HighContrast:
			return new HighContrastEffect{};
			break;

		case ImageEffectType::FlipHorizontal:
			return new FlipHorizontalEffect{};
			break;

		case ImageEffectType::FlipVertical:
			return new FlipVerticalEffect{};
			break;

		case ImageEffectType::Blur:
			return new BlurEffect{};
			break;

		case ImageEffectType::Pixelate:
			return new PixelateEffect{};
			break;

		case ImageEffectType::Rotate:
			return new RotateEffect{};
			break;

		default: 
			break;
		}
	}
};