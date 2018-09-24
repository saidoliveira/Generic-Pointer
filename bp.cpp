#include <iostream>
#include <iterator>
#include <string.h>
#include "fun.h"

int main(void)
{
	int A[] = {5, 6, 2, 1, 3, 7, 4};
	int cop[] = {0, 0, 0, 0, 0, 0, 0};

	print_int(std::begin(A), std::end(A));
	auto result1 = (const int *)min(std::begin(A), std::end(A), sizeof(int), compare_ints);
	std::cout << ">>> The smallest element in A is \"" << *result1 << "\"" << std::endl << std::endl;

	
	print_int(std::begin(A), std::end(A));
	reverse(std::begin(A), std::end(A), sizeof(int));
	print_int(std::begin(A), std::end(A));

	/*
	print_int(std::begin(cop), std::end(cop));
	auto resultcopy = (const int *)copy(std::begin(A), std::end(A), std::begin(cop), sizeof(int));
	for( auto j(std::begin(cop)); *j != resultcopy; ++j){
		std::cout << *j << " ";
	}
	std::cout << std::endl;
	*/
	return 0;

}