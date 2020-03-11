#include "../include/GameObject.h"

GameObject::GameObject() {
}

GameObject::GameObject(int _id) {
	id = _id;
}

void GameObject::Update() {
	//std::cout << id << ": Update GameObject" << std::endl;
}

int GameObject::GetID() {
	return id;
}

int GameObject::GetSubID() {
	return subArrID;
}

GameObject::~GameObject() {
}
