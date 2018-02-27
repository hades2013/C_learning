#include <iostream> 

using namespace std; 

class Box
{
public:
	Box(double l=2.0, double b=2.0, double h=2.0)
	{
		cout<<"Constructor called."<<endl; 
		length = l; 
		breadth = b;
		height = h;  

	}
	double Volume()
	{
		return length * breadth * height;
	}
	int compare(Box box)
	{
		return this->Volume() > box.Volume();	
	}
private:
	double length;
	double breadth;
	double height; 
};
int main(int argc, char const *argv[])
{
	Box box1(3.3, 1.2, 1.5); 
	Box box2(8.5, 5.0, 2.0); 

	if(box1.compare(box2))
	{
		cout<<"box2 is smaller than box1"<<endl; 
	}
	else 
	{
		cout<<"box2 is qual to or larger than box1"<<endl; 
	}
	return 0;
}