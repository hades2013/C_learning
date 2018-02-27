#include <iostream>
#include <csignal>
#include <cstdlib> 
#include <unistd.h>

using namespace std; 

void signalHandler(int signum) 
{
	cout<<"Interrupt signal ("<<signum<<") received\n";
	exit(signum); 
}

int main(int argc, char const *argv[])
{
	int i = 0; 
	signal(SIGINT, signalHandler); 
	while(++i){
		cout<<"going to sleep....."<<endl;
		if(i == 3){
			raise(SIGINT);
		}
		sleep(1); 
	}
	return 0;
}