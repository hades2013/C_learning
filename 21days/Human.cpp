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
	void SetName(string HumanName){
		Name = HumanName;
	}
	void SetAge(int HumanAge){
		Age =HumanAge; 
	}
	void IntroduceSelf(){
		cout<<"i am "+ Name<<" and am"; 
		cout<<Age<<"years old;"<<endl; 
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

	FirstMan.IntroduceSelf();
	FirstWoman.IntroduceSelf();
	return 0;
}