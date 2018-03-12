/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/
#include <iostream>
#include <memory>  //include this to use std::unique_ptr
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

	void DisplayDate(){
		cout<<Day<<"/"<<Month<<"/"<<Year<<endl; 
	}
	
};

int main(int argc, char const *argv[])
{
	unique_ptr<int> pDynamicAllocInteger(new int);
	*pDynamicAllocInteger = 42;
	cout<<"Integer value is: "<<*pDynamicAllocInteger<<endl; 

	unique_ptr<Date> pHoliday(new Data(12, 3, 2018));

	pHoliday->DisplayDate();

	return 0;
}