/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-13
*/

#include <iostream>
using namespace std; 

template <typename T>
class TestStatic
{
public:
	static int StaticValue; 
};

template<typename T> int TestStatic<T>::StaticValue; 

int main(int argc, char const *argv[])
{
	TestStatic<int> Int_Year;
	cout<<"setting StaticValue Int_Year to 2018"<<endl; 
	Int_Year.StaticValue = 2018;
	TestStatic<int> Int_2;

	TestStatic<double> Double_1; 
	TestStatic<double> Double_2;
	cout<<"setting StaticValue Double_2 to 1011"<<endl; 
	Double_2.StaticValue = 1011; 

	cout<<"Int_2.StaticValue = "<<Int_2.StaticValue<<endl; 
	cout<<"Double_1.StaticValue = "<<Double_2.StaticValue<<endl;  
	return 0;
}