#pragma once
#include "Node.h"
#include <cstddef>
#include <iostream>

template <class T> class Stack {

	public:
		Node<T>* first;
		Node<T>* last;
		Node<T>* tmp;
		unsigned int size;
		Stack();
		void push(T val);
		void pop();
		bool empty();
		int	getSize();
		void print();
		~Stack();
};

template <class T> Stack<T>::Stack() {
	first = NULL;
	last = NULL;
	tmp = NULL;
	size = 0;
}

template <class T> void Stack<T>::push(T val) {
	if (first == NULL) { // la lista está completamente vacía
		first = new Node<T>(val);
		last = first; // el primero y el último son el mismo
	}
	else {
		if (first == last) { // sólo hay un elemento en la lista
			tmp = first;
			first = new Node<T>(val); // last ahora es diferente
			first->next = last; // el siguiente de first ahora es el nuevo nodo
			first->index = 0;
			last->index = 1;
		}
		else { // hay 2 o más elementos en la lista
			tmp = first;
			first = new Node<T>(val); // last->next era null, ahora es un nodo
			first->next = tmp; // last ahora es el nodo nuevo					
			first->index = -1;
			Node<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...		
				it->index += 1;// se actualiza el iterador por el siguiente nodo en la lista
				it = it->next;
				// si it->next es null, entonces it será null, y se detendrá el While.
			}
		}
	}
	size++;
}

template <class T> void Stack<T>::pop() {
	first = first->next;
	Node<T>* it = first;
}

template <class T> bool Stack<T>::empty() {
	if (first == NULL) return true;
	return false;
}

template <class T> int Stack<T>::getSize() {
	return size;
}

template <class T> void Stack<T>::print() {
	Node<T>* it = first; // se crea un "iterador"
	while (it != NULL) { // si el iterador no es nulo...
		std::cout << it->value << "--->" << it->index << std::endl; // imprime el valor del iterador
		it = it->next; // se actualiza el iterador por el siguiente nodo en la lista
		// si it->next es null, entonces it será null, y se detendrá el While.
	}
}

template <class T> Stack<T>::~Stack() {
}
