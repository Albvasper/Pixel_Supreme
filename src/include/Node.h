#pragma once

template <class T> class Node {

	public:
		T data;				//Data that will be stored in the node
		Node<T>* next;		//A node pointer that stores the next node
		Node<T>* prev;		//A node pointer that stores the previous node
		int index;			//Index that assigns a position
		Node();				//Default constructor
		Node(T dat);		//Constructor that takes a T value called dat
		~Node();			//Destructor
};

template <class T> Node<T>::Node() {
	next = nullptr;			//Pointer called next is null
	prev = nullptr;			//Pointer called prev is null
	index = -1;
}

template <class T> Node<T>::Node(T dat) {
	next = nullptr;			//Pointer called next is null
	prev = nullptr;			//Pointer called prev is null
	data = dat;				//"data" variable equals to "dat" parameter which is the value that will be stored 
	index = -1;
}

template <class T> Node<T>::~Node() {
}