#include <iostream> 
using namespace std; 

class printData
{
public:
	void print(int i){
		cout<<"pirnt int:"<<i<<endl; 
	}
	void print(double f){
		cout<<"print float: "<<f<<endl; 
	}
	void print(char *c){
		cout<<"print character: "<<c<<endl; 
	}
	//printData();
	//~printData();
	
};

int main(int argc, char const *argv[])
{
	printData pd; 
	pd.print(5); 
	pd.print(500.222);
	pd.print("hello C++");
	return 0;
}