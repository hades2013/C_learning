/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/

#include <iostream>
#include <string>
using namespace std; 

class President
{
private:
	President(){};
	President(const President&);
	const President& operator=(const President&);
	string Name; 
public: 
	static President& GetInstance(){
		static President OnlyInstance; 
		return OnlyInstance; 
	}

	string GetName(){
		return Name; 
	}

	void SetName(string InputName){
		Name = InputName; 
	}
	
};

int main(int argc, char const *argv[])
{
	President& OnlyInstance = President::GetInstance();
	OnlyInstance.SetName("Abraham Lincoln");

	cout<<"the name of the President is: ";
	cout<<President::GetInstance().GetName()<<endl; 
	return 0;
}