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
private: 
	char *Buffer;
public:
	MyString(const char *InitialInput){
		if(InitialInput != NULL){
			Buffer = new char [strlen(InitialInput)+ 1];
			strcpy(Buffer, InitialInput);
		}
		else 
			Buffer = NULL; 
	}
	MyString(const MyString& CopySource){
		if(CopySource.Buffer != NULL){
			Buffer = new char [strlen(CopySource.Buffer) + 1];
			strcpy(Buffer, CopySource.Buffer);
		}
		else 
			Buffer = NULL;
	}
	~MyString(){
		if(Buffer != NULL){
			delete [] Buffer;
		}
	}
	int GetLength(){
		return strlen(Buffer);
	}
	const char *GetString(){
		return Buffer;
	}
	
};

class Human
{
private: 
	int Age;
	bool Gender;
	MyString Name; 
public:
	Human(const MyString& InputName, int InputAge, bool InputGender)
		:Name(InputName), Age(InputAge), Gender(InputGender){};

	int GetAge(){
		return Age; 
	}
};

int main(int argc, char const *argv[])
{
	MyString FirstMan("hades");
	MyString FirstWoman("yue");
	cout<<"sizeof(MyString) = "<< sizeof(MyString)<<endl; 
	cout<<"sizeof(FirstMan) = "<< sizeof(FirstMan)<<endl; 
	cout<<"sizeof(FirstWoman) = "<< sizeof(FirstWoman)<<endl;

	Human FirstMaleHuman(FirstMan, 25, true); 
	Human FirstFemalHuman(FirstWoman, 18, false);

	cout<<"sizeof(Human) = "<<sizeof(Human)<<endl; 
	cout<<"sizeof(FirstMaleHuman) = "<<sizeof(FirstMaleHuman)<<endl; 
	cout<<"sizeof(FirstFemalHuman) = "<<sizeof(FirstFemalHuman)<<endl; 
	return 0;
}