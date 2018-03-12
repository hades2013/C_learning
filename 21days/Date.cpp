/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/
#include <iostream>
using namespace std; 

class Date
{
private: 
	int Day;
	int Month;
	int Year; 
public:
	Date(int InputDay, int InputMonth, int InputYear)
		:Day(InputDay), Month(InputMonth), Year(InputYear){};
	Date& operator++(){
		++Day; 
		return *this; 
	}
	Date& operator--(){
		--Day; 
		return *this; 
	}

	void DisplayDate(){
		cout<<Day<<"/"<<Month<<"/"<<Year<<endl; 
	}
	
};

int main(int argc, char const *argv[])
{
	Date Holiday(12, 3, 2018);
	Holiday.DisplayDate();
	++Holiday; 
	cout<<"Date after prefix increment is ";
	Holiday.DisplayDate();

	--Holiday;
	--Holiday;
	cout<<"Date after two prefix decremnet is ";
	Holiday.DisplayDate();
	return 0;
}