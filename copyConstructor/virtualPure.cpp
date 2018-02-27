#include <iostream>

using namespace std; 

class Shape
{
public:
	//Shape();
	//~Shape();
	virtual int getArea() = 0; 
	void setWidth(int w)
	{
		width = w; 
	} 
	void setHeight(int h)
	{
		height = h; 
	}
protected:
	int width;
	int height; 
};

class Rectangle: public Shape
{
public:
	//Rectangle();
	//~Rectangle();
	int getArea()
	{
		return (width * height); 
	}
};

class Triangle: public Shape
{
public:
	//Triangle();
	//~Triangle();
	int getArea()
	{
		return (width * height)/2;
	}
};
int main(int argc, char const *argv[])
{
	Rectangle Rect; 
	Triangle Tri; 

	Rect.setWidth(5);
	Rect.setHeight(7); 
	cout<<"Total Rectangle area: "<<Rect.getArea()<<endl; 

	Tri.setWidth(6);
	Tri.setHeight(8); 

	cout<<"Total Triangle area :"<<Tri.getArea()<<endl; 
	return 0;
}