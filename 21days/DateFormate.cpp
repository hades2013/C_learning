/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/
#include <iostream>
#include <sstream>
#include <string>
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
	operator const char*(){
		ostringstream formattedDate; 
		formattedDate<<Day<<"/"<<Month<<"/"<<Year<<endl; 

		DateInString = formattedDate.str();
		return DateInString.c_str();
	}

	void DisplayDate(){
		cout<<Day<<"/"<<Month<<"/"<<Year<<endl; 
	}
	
};

int main(int argc, char const *argv[])
{
	Date Holiday(12, 3, 2018);
	cout<<"Holiday is on: "<<Holiday<<endl; 
	return 0;
}