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
	bool operator==(const Date& compareTo){
		return ((Day == compareTo.Day) && (Month == compareTo.Month) && (Year == compareTo.Year));
	}

	bool operator!=(const Date& compareTo){
		return !(this->operator== (compareTo));
	}

	void DisplayDate(){
		cout<<Day<<"/"<<Month<<"/"<<Year<<endl; 
	}
	
};

int main(int argc, char const *argv[])
{
 	Date Holiday1(25, 3, 2018);
 	Date Holiday2(31, 3, 2018);
 	cout<<"Holiday 1 on: ";
 	Holiday1.DisplayDate();
 	cout<<"Holiday 2 on: ";
 	Holiday2.DisplayDate();

 	if(Holiday1 == Holiday2)
		cout<<"Equality operator: the two are the same Day "<< endl;
	else
		cout<<"Equality operator: the two are not the same Day"<<endl; 
 	
 	if(Holiday1 != Holiday2)
 		cout<<"Inequality operator: the two are the different Day"<<endl; 
 	else
 		cout<<"Inequality operator: the two are the same Day"<<endl; 

	return 0;
}