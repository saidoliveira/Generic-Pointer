#ifndef LISTA_2
#define	LISTA_2

#include <cstdlib>

typedef bool (*MinCompare)(const void *, const void *);
const void *min(const void *first, const void *last, std::size_t size, MinCompare cmp);
typedef unsigned char byte;

void print_int( int *first, int *last);
bool compare_ints(const void *a, const void *b);
void reverse( void *first, void *last, std::size_t size);
void *copy( void *first,  void *last, void *d_first, std::size_t size);
void *clone( void *first, void *last, std::size_t size);

typedef bool (*Predicate)( void *);
void *find_if(void *first, void *last, std::size_t size, Predicate p);

#endif