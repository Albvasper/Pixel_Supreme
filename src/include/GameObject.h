#pragma once
#include <iostream>
#include <utility>

class GameObject {

	private:
		unsigned int id = 0;
		std::pair<float, float> position;

	public:
		GameObject();
		GameObject(int _id);
		virtual void Update();
		virtual void Render();
		int GetID();
		void SetID(unsigned int _id);
		void SetPos(float x, float y);
		std::pair<float, float> Translate(float x, float y);
		std::pair<float, float> GetPos();
		~GameObject();
};

