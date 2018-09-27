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


const void *min(const void *first, const void *last, std::size_t size, Compare cmp)
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

void *copy(const void *first, const void *last, const void *d_first, std::size_t size){
	
	void *firsta = const_cast< void *>(first);
	void *lasta = const_cast< void *>(last);
	void *firstb = const_cast< void *>(d_first);
	byte *i = static_cast< byte *>(firsta);
	byte *j = static_cast< byte *>(firstb);
	byte *p = static_cast< byte *>(lasta);
	byte k = std::distance(i,p)/size;
	
	while( i != last)
	{
		memcpy(j, i, size);
		i+=size;
		j+=size;
	}
	return firstb+static_cast< byte >(k);
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

	return j-size;
}

void *find(void *first, void *last, std::size_t size, void *value, Equal eq)
{
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(last);

	while(i != last)
	{
		if(eq(i,value))
		{
			return i;
		}
		i+=size;
	}
	return j-size;
}

bool all_of(void *first, void *last, std::size_t size, Predicate p)
{
	byte *i = static_cast< byte *>(first);

	while(i != last)
	{
		if(!p(i))
		{
			return false;
		}
		i+=size;
	}
	return true; 
}

bool any_of(void *first, void *last, std::size_t size, Predicate p)
{
	byte *i = static_cast< byte *>(first);

	while(i != last)
	{
		if(p(i))
		{
			return true;
		}
		i+=size;
	}
	return false;
}

bool none_of(void *first, void *last, std::size_t size, Predicate p)
{
	byte *i = static_cast< byte *>(first);

	while(i != last)
	{
		if(p(i))
		{
			return false;
		}
		i+=size;
	}
	return true;
}

bool equal1(void *first1, void *last1, void *first2, std::size_t size, Equal eq)
{
	byte *i = static_cast< byte *>(first1);
	byte *j = static_cast< byte *>(first2);

	while(i != last1)
	{
		if(!eq(i,j))
			return false;
		i+=size;
		j+=size;
	}
	return true;
}

bool equal2(void *first1, void *last1, void *first2, void *last2, std::size_t size, Equal eq)
{
	byte *i = static_cast< byte *>(first1);
	byte *j = static_cast< byte *>(first2);

	while(i != last1 || j != last2)
	{
		if(!eq(i,j))
			return false;
		i+=size;
		j+=size;
	}
	return true;
}

void *unique(void *first, void *last, std::size_t size, Equal eq)
{
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(last);
	byte *result = static_cast< byte *>(first);

	

	while((i+=size) != j)
	{
		if(!eq(result, i) && (result+=size) != i)
		{
			memmove(result, i, size);
		}
	}
	return result+=size;
}

void *partition(void *first, void *last, std::size_t size, Predicate p)
{

}

void sort( void* first , void *last , size_t size, Compare cmp)
{
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(first);
	byte *p = static_cast< byte *>(last);

	int aux;

	for(; i < p-size; i+=size)
	{
		for(j = i+size; j < last; j+=size)
		{
			if(cmp(j,i))
			{
				aux = *j;
				*j = *i;
				*i = aux;
			}
		}
	}
}