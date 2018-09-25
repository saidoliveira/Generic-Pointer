#include <iostream>
#include <iterator>
#include <string.h>
#include "fun.h"

using std::begin;
using std::end;
using std::cout;
using std::endl;

using Predicate = bool(*)(void *);
bool menor(void *x)
{
	byte *xx = static_cast < byte *>(x);
	return *xx < 0;	
}


int main(void)
{
	int i;
	int A[] = {5, 6, 2, 1, 3, 7, 4};
	int cop[] = {0, 0, 0, 0, 0, 0, 0};

	cout << "--- MINIMUM ---" << endl;
	print_int(begin(A), end(A));
	auto result1 = (const int*)min(begin(A), end(A), sizeof(int), compare_ints);
	cout << "O menor valor eh: " << *result1 << endl;

	cout << "--- REVERSE ---" << endl;
	print_int(begin(A), end(A));
	reverse(begin(A), end(A), sizeof(int));
	print_int(begin(A), end(A));
		
	cout << "--- COPY ---" << endl;
	print_int(begin(cop),end(cop));
	auto resultcopy = (int*)copy(begin(A),end(A),begin(cop),sizeof(int));
	for(i = 0; i < 7; i++)
	{
		cout << resultcopy[i] << " ";
	}
	cout << endl;
	
	cout << "--- CLONE ---" << endl;
	int clonev[] = {20, 40, 60, 80, 100, -20};
	print_int(begin(clonev),end(clonev));
	auto resultclone = (int*)clone(begin(clonev),end(clonev),sizeof(int));
	for(i = 0; i < 6; i++)
	{
		cout << resultclone[i] << " ";
	}
	cout << endl;

	cout << "--- FIND_IF ---" << endl;
	int find_ifv[] = {15, 30, 45, 15, 30, 45};
	print_int(begin(find_ifv),end(find_ifv));
	auto resultfind_if = (int*)find_if(begin(find_ifv),end(find_ifv),sizeof(int), menor);
	cout << *resultfind_if << endl; 

	return 0;

}