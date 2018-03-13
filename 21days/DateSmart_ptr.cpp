/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/
#include <iostream>
using namespace std; 

template <typename T>
class Smart_pointer
{
private: T* m_pRawPointer;
public:
	Smart_pointer(T* pDate): m_pRawPointer(pDate){};
	~Smart_pointer(){delete m_pRawPointer;};
	T& operator*() const{
		return *(m_pRawPointer); 
	}
	T* operator->(){
		return m_pRawPointer; 
	}
	
};
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
	Smart_pointer<int> pDynamicInt(new int(42));
	cout<<"pDynamicInt allocated interge value: = "<<*pDynamicInt<<endl; 

	Smart_pointer<Date> pDate(new Date(13, 3, 2018));
	cout<<"Date is: ="; 
	pDate->DisplayDate();

	return 0;
}