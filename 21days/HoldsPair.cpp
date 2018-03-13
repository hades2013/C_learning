/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-13
*/
template <typename T1=int, typename T2=double>
class HoldsPair
{
private:
	T1 Value1;
	T2 Value2; 
public:
	HoldsPair(const T1& value1, const T2& value2){
		Value1 = value1; 
		Value2 = value2; 
	};
	const T1& GetFisrtValue() const{
		return Value1; 
	};
	const T2& GetSecondValue() const{
		return Value2;
	}
	//~HoldsPair();
	
};

#include <iostream>
using namespace std; 

int main(int argc, char const *argv[])
{
	HoldsPair <> mIntFloatPair(200, 100.9);
	HoldsPair<short, char*> mShortStringPair(30, "learn templates, loves C++");

	cout<<"the fist object contains :"<<endl; 
	cout<<"Value1: "<<mIntFloatPair.GetFisrtValue()<<endl; 
	cout<<"value2: "<<mIntFloatPair.GetSecondValue()<<endl; 

	cout<<"the second object contains: "<<endl; 
	cout<<"Value1: "<<mShortStringPair.GetFisrtValue()<<endl; 
	cout<<"Value2: "<<mShortStringPair.GetSecondValue()<<endl;

	return 0;
}