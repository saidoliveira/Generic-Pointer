#include <iostream>
#include <iterator>
#include <string.h>
#include "fun.h"

using std::begin;
using std::end;
using std::cout;
using std::endl;

bool negativo(void *x)
{
	return *static_cast< int *>(x) < 0;
}

bool igual(void *x, void *y)
{
	return *static_cast< int *>(x) == *static_cast< int *>(y); 
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
	int find_ifv[] = {15, 30, 45, 15, -30, 20};
	print_int(begin(find_ifv),end(find_ifv));
	auto resultfind_if = (int*)find_if(begin(find_ifv),end(find_ifv),sizeof(int), negativo);
	cout << *resultfind_if << endl; 

	cout << "--- FIND ---" << endl;
	int findv[] = {2, 3, 5, 7, 11};
	int *ptr;
	int x = 7;
	ptr = &x;
	print_int(begin(findv),end(findv));
	auto resultfind = (int*)find(begin(findv),end(findv), sizeof(int), ptr, igual);
	cout << "Elemento a ser buscado no vetor: " << *ptr << endl << "Elemento encontrado: "<<*resultfind << endl;

	cout << "--- ALL/ANY/NONE ---" << endl;
	int all_ofv[] = {-6, -5, -4, -3, -2, -1};
	auto resultall_of = all_of(begin(all_ofv),end(all_ofv), sizeof(int), negativo);
	cout << "Todos os elementos são menos que zero? " << resultall_of << endl;
	int any_ofv[] = {6, 5, 4, 3, 2, -1};
	auto resultany_of = any_of(begin(any_ofv),end(any_ofv),sizeof(int), negativo);
	cout << "Existe pele menos um elemento menor que zero? " << resultany_of << endl;
	int none_ofv[] = {6, 5, 4, -3, 2, 1};
	auto resultnone_of = none_of(begin(none_ofv),end(none_ofv),sizeof(int), negativo);
	cout << "Todos os elementos são maiores que zero? " << resultnone_of << endl;
	return 0;

}