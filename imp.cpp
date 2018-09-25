#include <iostream>
#include <iterator>
#include <string.h>
#include "fun.h"

void print_int( int *first, int *last)
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
	byte *itf = static_cast< byte *>(first);
	byte *itl = static_cast< byte *>(last);
	byte aux;
	itl-= size;
	
	while( itf != itl)
	{
		aux = *itf;
		*itf = *itl;
		*itl = aux;
		itf++;
		itl--;
	}
}

void *copy(void *first, void *last, void *d_first, std::size_t size){
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(d_first);
	
	while( i != last)
	{
		memcpy(j, i, size);
		i+=size;
		j+=size;
	}
	return d_first;
}

void *clone(void *first, void *last, std::size_t size)
{
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(last);
	byte tam = std::distance(i,j)/size;
	byte *vetor;
	vetor = new byte[tam];
	byte *p = static_cast< byte *>(vetor);

	while(i != last)
	{
		memcpy(p, i, size);
		i+=size;
		p+=size;
	}

	return vetor;
}


void *find_if(void *first, void *last, std::size_t size, Predicate p)
{
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(last);

	while(i != last)
	{
		if(p(i))
		{
			return i;
		}

		i+=size;
	}	
	return j;
}
