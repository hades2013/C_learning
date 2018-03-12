/*
* 21 day for cpp
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-12
*/
#include <iostream>
using namespace std; 

class MonsterDB
{
private: 
	~MonsterDB(){};
public:
	static void DestoryInstance(MonsterDB *pInstance){
		delete pInstance;
	}
};

int main(int argc, char const *argv[])
{
	MonsterDB *pMyDatabase = new MonsterDB();
	MonsterDB::DestoryInstance(pMyDatabase);
	return 0;
}