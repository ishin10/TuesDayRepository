#include<iostream>
using namespace std;
void swap(int &a, int &b);

int main(void)
{
	int x = 10;
	int y = 20;
	cout << "Before swap: x=" << x << ",y=" << y << std::endl;
	swap(x, y);
	cout << "After swap: x=" << x << ",y=" << y << std::endl;

	return 0;
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}