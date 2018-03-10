/*
* C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 
* 它的作用是表明该构造函数是显示的, 而非隐式的， 跟它相对应的另一个关键字是implicit, 
* 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式)。
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-10
*/
#include <iostream> 
#include <stdio.h>

using namespace std; 

class CExplict
{
public:
	CExplict();
	explicit CExplict( bool _explicit)
	{
		this->is_explict = _explicit;
	}
	CExplict(const CExplict& other)
	{
		this->is_explict = other.is_explict;
	}
	friend void printExplicit(const CExplict& cx);	

private:
	bool is_explict;
};

void printExplicit(const CExplict& cx)
{
	cout<<"is_explict="<<cx.is_explict<<endl;
}

int main( int argc, char* argv[])
{
	CExplict cx1(true);  
    CExplict cx2(cx1);  
    printExplicit(cx1);  
    printExplicit(cx2);  
    printExplicit(CExplict(false));  
	getchar();
	return 1;
}