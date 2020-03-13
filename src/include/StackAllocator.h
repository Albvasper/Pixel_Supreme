//--------------------------------------------------------------------
// This code is property of "fmandujano"
// Code borrowed from: https://github.com/fmandujano/stackAllocator
//--------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include "Logging.h"

class StackAllocator {

	public:
		typedef size_t Marker;
		StackAllocator(size_t size);
		void* alloc(size_t size);
		Marker getMarker();
		void freeToMarker(Marker marker);
		void clear();

	private:
		int maxSize;
		void * start;
		Marker marker;
		Marker prev;
		Logging* log;
};