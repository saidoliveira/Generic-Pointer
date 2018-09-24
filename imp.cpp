#include <iostream>
#include <iterator>
#include <string.h>
#include "fun.h"

void print_int(const int *first, const int *last)
{
	while(first != last)
	{
		std::cout << *first++ << " ";
	}
	std::cout << std::endl;
}

bool compare_ints(const void *a, const void *b)
{
	return *static_cast< const int *>(a) < *static_cast< const int *>(b);
}

const void *min(const void *first, const void *last, std::size_t size, MinCompare cmp)
{
	const byte *it = static_cast< const byte *>( first );

	const byte *smallest = it;

	while( it != last)
	{
		if( cmp( it, smallest ))
			smallest = it;
		it += size;
	}
	return smallest;
}


void reverse(void *first, void *last, std::size_t size)
{
	const byte *itf = static_cast< const byte *>(first);
	const byte *itl = static_cast< const byte *>(last);
	
	itl -= size;

	while( itf != itl)
	{
		memcpy(*itf, *itl, size);
		itf += size;
		itl -= size;
	}
}


/*
void *copy(const void *first, const void *last, const void *d_first, std::size_t size){
	int tam = std::distance(first,last);
	const byte *i = static_cast< const byte *>(first);
	const byte *j = static_cast< const byte *>(d_first);

	while( i != last)
	{
		*j = *i;
		i +=size;
	}

	return j+tam;
}*/

