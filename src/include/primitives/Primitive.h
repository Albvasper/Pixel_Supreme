#pragma once
#include <utility>
#include "../GameObject.h"
#include "SDL.h"

class Primitive : public GameObject {
	
	public:
		std::pair<float, float> position;
		Primitive();
		virtual void Render();
		~Primitive();
};

