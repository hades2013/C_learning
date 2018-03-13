/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-13
*/
#include <iostream>
using namespace std; 

class Date
{
private: 
	int Day;
	int Month;
	int Year; 

	string DateInString; 
public:
	Date(int InputDay, int InputMonth, int InputYear)
		:Day(InputDay), Month(InputMonth), Year(InputYear){};
	void operator+=(int DaysToAdd){
		Day += DaysToAdd;
	}
	void operator-=(int DaysToSub){
		Day -= DaysToSub; 
	}

	void DisplayDate(){
		cout<<Day<<"/"<<Month<<"/"<<Year<<endl; 
	}
	
};

int main(int argc, char const *argv[])
{
 	Date Holiday(25, 3, 2018);
 	cout<<"Holiday on: ";
 	Holiday.DisplayDate();

 	cout<<"Holiday -= 19 gives:  ";
 	Holiday -= 19;
 	Holiday.DisplayDate();

 	cout<<"Holiday += 25 gives: ";
 	Holiday +=25;
 	Holiday.DisplayDate();

	return 0;
}