/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/

#include <iostream>
#include <cstring>
using namespace std; 

class MyString
{
private: char *Buffer; 
public:
	//constructor
	MyString(const char *InitiaInput){
		if(InitiaInput != NULL){
			Buffer = new char[strlen(InitiaInput)+1]; 
			strcpy(Buffer, InitiaInput);
		}
		else 
			Buffer = NULL;
	}
	//destructor: clears the Buffer
	~MyString(){
		cout<<"Invoking destructor, clear up"<<endl; 
		if(Buffer != NULL)
			delete [] Buffer; 
	}

	int GetLength(){
		return strlen(Buffer);
	}
	const char *GetString(){
		return Buffer; 
	}
};

int main(int argc, char const *argv[])
{
	MyString SayHello("Hello");
	cout<<"string Buffer in MyString is : "<< SayHello.GetLength()<<endl; 
	cout<<"characters long"<<endl; 

	cout<<"Buffer contains :";
	cout<<"Buffer contains "<<SayHello.GetString()<<endl; 
	return 0;
}