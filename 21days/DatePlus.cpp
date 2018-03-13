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
	Date operator+(int DaysToAdd){
		Date newDate(Day+ DaysToAdd, Month, Year);
		return newDate; 
	}
	Date operator-(int DaysToSub){
		return Date(Day -DaysToSub, Month, Year); 
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
 	Date PreviousHoliday(Holiday- 19);
 	cout<<"Previous Holiday on: ";
 	PreviousHoliday.DisplayDate();

 	Date NextHoliday(Holiday + 5);
 	cout<<"Next Holiday on :"; 
 	NextHoliday.DisplayDate();

	return 0;
}