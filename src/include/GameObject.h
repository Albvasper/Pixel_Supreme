#pragma once
#include <iostream>

class GameObject {

	private:
		int id = 0;
		int subArrID = 0;

	public:
		GameObject();
		GameObject(int _id);
		virtual void Update();
		int GetID();
		int GetSubID();
		~GameObject();
};

