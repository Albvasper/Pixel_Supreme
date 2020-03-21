#include "../include/GameObject.h"

GameObject::GameObject() {
}

GameObject::GameObject(int _id) {
	id = _id;
}

void GameObject::Update() {
	//std::cout << id << ": Update GameObject" << std::endl;
}

void GameObject::Render() {
}

int GameObject::GetID() {
	return id;
}

void GameObject::SetID(unsigned int _id) {
	id = _id;
}

void GameObject::SetPos(float x, float y) {
	position.first = x;
	position.second = y;
}

std::pair<float, float> GameObject::Translate(float x, float y) {
	return std::pair<float, float>(position.first + x, position.second + y);
}

std::pair<float, float> GameObject::GetPos() {
	return position;
}

GameObject::~GameObject() {
}
