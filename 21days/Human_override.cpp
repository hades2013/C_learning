/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/
#include <iostream>
#include <string>
using namespace std; 

class Human
{
private: 
	string Name;
	int Age; 

public:
	Human(){
		Age = 0;
		cout<<"defaut constructor create an instance of Human"<<endl; 
	}
	// overloaded constructor thats make name
	Human(string HumanName){
		Name = HumanName;
		Age = 0; 
		cout<<"overloaded constructor creates "<<Name<<endl; 
	}
	Human(string HumanName, int HumanAge){
		Name = HumanName;
		Age = HumanAge; 
		cout<<"overloaded constructor creates ";
		cout<<Name<<" of "<<Age<<" years "<<endl;
	}
	void SetName(string HumanName){
		Name = HumanName;
	}
	void SetAge(int HumanAge){
		Age =HumanAge; 
	}
	void IntroduceSelf(){
		cout<<"i am "+ Name<<" and am "; 
		cout<<Age<<" years old;"<<endl; 
	}
};

int main(int argc, char const *argv[])
{
	//constructing an object
	Human FirstMan; 
	FirstMan.SetName("hades");
	FirstMan.SetAge(18);

	Human FirstWoman; 
	FirstWoman.SetName("yue");
	FirstWoman.SetAge(17);

	Human FirstChild("Girl", 9); 

	FirstMan.IntroduceSelf();
	FirstWoman.IntroduceSelf();
	FirstChild.IntroduceSelf();
	return 0;
}