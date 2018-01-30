#include <stdio.h>
#include "calc.h"
#include "show.h"

int main(int argc, char const *argv[])
{
	int s; 
	int i = 1; 
	int j = 2; 
	s = sum(i, j);
	show(i, "i");
	show(j, "j");
	show(s, "sum");
	return 0;
}
