//--------------------------------------------------------------------
// This code is property of "fmandujano"
// Code borrowed from: https://github.com/fmandujano/stackAllocator
//--------------------------------------------------------------------
#include "../include/StackAllocator.h"
#include "../include/Logging.h"

StackAllocator::StackAllocator(size_t size) {
	//printf("%i,%i \n", sizeof(void*), sizeof(size_t));
	static_assert(sizeof(size_t) >= sizeof(void*), "the size of uint must be greater than or equal to the size of a pointer");
	maxSize = size;
	start = malloc(size);
	if (start == NULL) {
		Logging::Get()->Error("Failed to assign memory.","StackAllocator");
	}

	marker = (size_t)start;
	prev = marker;
	//printf("dir: %p\n", start);
	//printf("marker %#x\n", marker);
}

void* StackAllocator::alloc(size_t size) {
	//comprobar si la memoria pedida es igual o menor al tamano que queda en el stack
	if (prev + size <= maxSize)
	{
		prev = marker;
		marker = marker + size;
		//printf("prev %#x\n", prev);
		//printf("marker %#x\n", marker);
		//printf("return %p\n", (void*)prev);
		//regresar el valor de uint a apuntador
		return (void*)prev;
	}
	else return NULL;
}

StackAllocator::Marker StackAllocator::getMarker() {
	return marker;
}

void StackAllocator::clear() {
	//mover el marcador al inicio del stack
	marker = (size_t)start;
}