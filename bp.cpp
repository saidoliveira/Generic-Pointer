#include <iostream>
#include <iterator>
#include <string.h>
#include "fun.h"

using std::begin;
using std::end;
using std::cout;
using std::endl;

int main(void)
{
	int A[] = {5, 6, 2, 1, 3, 7, 4};
	int cop[] = {0, 0, 0, 0, 0, 0, 0};

	print_int(begin(A), end(A));
	auto result1 = (const int *)min(begin(A), end(A), sizeof(int), compare_ints);
	cout << ">>> The smallest element in A is \"" << *result1 << "\"" << endl << endl;

	cout << "--- REVERSE ---" << endl;
	print_int(begin(A), end(A));
	reverse(begin(A), end(A), sizeof(int));
	print_int(begin(A), end(A));
	cout << endl;
		
	cout << "--- COPY ---" << endl;
	print_int(begin(cop), end(cop));
	(const int *)copy(begin(A), end(A), begin(cop), sizeof(int));
	print_int(begin(cop), end(cop));
	

	return 0;

}