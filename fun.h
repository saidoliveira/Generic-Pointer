#ifndef LISTA_2
#define	LISTA_2

#include <cstdlib>

typedef unsigned char byte;
typedef bool (*MinCompare)(const void *, const void *);
typedef bool (*Predicate)(void *);
typedef bool (*Equal)(void *, void *);

const void *min(const void *first, const void *last, std::size_t size, MinCompare cmp);
typedef unsigned char byte;

void print_int( int *first, int *last);
bool compare_ints(const void *a, const void *b);
void reverse( void *first, void *last, std::size_t size);
void *copy( void *first,  void *last, void *d_first, std::size_t size);
void *clone( void *first, void *last, std::size_t size);
void *find_if(void *first, void *last, std::size_t size, Predicate p);
void *find(void *first, void *last, std::size_t size, void *value, Equal eq);
bool all_of(void *first, void *last, std::size_t size, Predicate p);
bool any_of(void *first, void *last, std::size_t size, Predicate p);
bool none_of(void *first, void *last, std::size_t size, Predicate p);
bool equal1(void *first1, void *last1, void *first2, std::size_t size, Equal eq);
bool equal2(void *first1, void *last1, void *first2, void *last2, std::size_t size, Equal eq);

#endif