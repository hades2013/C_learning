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
			cout<<"Buffer points : 0x"<<hex; 
			cout<<(unsigned int *)Buffer<<endl;
		}
		else 
			Buffer = NULL;
	}
	//copy constructor 
	MyString(const MyString& CopySource){
		cout<<"copy constructor: copy form MyString"<<endl; 
		Buffer = new char[strlen(CopySource.Buffer) + 1];
		strcpy(Buffer, CopySource.Buffer);

		cout<<"Buffer points: 0x"<<hex; 
		cout<<(unsigned int*)Buffer<<endl; 
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

void UseMyString(MyString Input)
{
	cout<<"string Buffer in MyString is: "<<Input.GetLength();
	cout<<" characters long "<<endl; 

	cout<<"Buffer contains :" << Input.GetString()<<endl;
	return;
}

int main(int argc, char const *argv[])
{
	MyString SayHello("Hello form MyString class ");
	//cout<<"string Buffer in MyString is : "<< SayHello.GetLength()<<endl; 
	//cout<<"characters long"<<endl; 

	UseMyString(SayHello);
	//cout<<"Buffer contains :";
	//cout<<"Buffer contains "<<SayHello.GetString()<<endl; 
	return 0;
}