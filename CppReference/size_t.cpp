/*
* cppreference practice 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-10
*/
#include <cstddef>
#include <iostream> 

int main(int argc, char const *argv[])
{
	const std::size_t N = 10; 
	int *a = new int[N]; 

	for(std::size_t n = 0; n < N; ++n)
		a[n] = n; 
	for(std::size_t n = N; n-- > 0;)
		std::cout<<a[n]<<" "; 

	delete[] a; 
	return 0;
}