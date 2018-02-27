#include <iostream> 

using namespace std; 

class Line 
{
	public: 
		int getLength(void); 
		Line(int len);
		Line(const Line &obj); 
		~Line();
	private:
		int *ptr; 
};

Line::Line(int len)
{
	cout<<"Nomal constructor allocating ptr"<<endl; 
	ptr = new int; 
	*ptr = len; 
}
Line::Line(const Line &obj)
{
	cout<<"copy constructor allocating ptr."<<endl;
	ptr = new int; 
	*ptr = *obj.ptr; 
}

Line::~Line(void)
{
	cout<<"freeing memeory!"<<endl; 
	delete ptr; 
}

int Line::getLength(void)
{
	return *ptr; 
}

void display(Line obj)
{
	cout<<"getLength of Line: "<<obj.getLength()<<endl;
}

int main(int argc, char const *argv[])
{
	Line line1(10); 

	Line line2 = line1; 
	display(line1);
	display(line2);
	return 0;
}