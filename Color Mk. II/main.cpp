#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::clog;
using std::left;

#include <cstdlib>
using std::system;
using std::exit;

#include "Color.h"

//template<int i,int j>
//class Test
//{};
//
//Test<1,2> x1;
//Test<2,3> x2;
//
//template<int i,int j>
//void f(Test<i,j> &o)
//{
//	cout << i << ',' << j << endl;
//}
//
//class T1
//{};
//
//class T2 : public T1
//{};
//
//class T3 : public T2
//{};

struct Y
{
	//Y &operator=(const Y &right)
	//{
	//	return *this;
	//}
	int i[2];
};

struct X /*: public Y*/
{
	Y m;
};

struct Z
{
	union
	{
		X m1;
		X m2;
	};
};

int main()
{
	Color<unsigned char> fillColor;
	Color<unsigned char> borderColor;

	Y y1;
	y1.i[0] = 1;
	y1.i[1] = 2;
	Y y2;
	y2.i[0] = 10;
	y2.i[1] = 20;

	y2 = y1;

	cout << y2.i[0] << endl;
	cout << y2.i[1] << endl;

	X x1;
	x1.m.i[0] = 1;
	x1.m.i[1] = 2;
	X x2;
	x2.m.i[0] = 10;
	x2.m.i[1] = 20;

	x2 = x1;

	cout << x2.m.i[0] << endl;
	cout << x2.m.i[1] << endl;

	Z z1;
	z1.m1.m.i[0] = 1;
	z1.m1.m.i[1] = 2;
	Z z2;
	z2.m1.m.i[0] = 10;
	z2.m1.m.i[1] = 20;

	z2.m1 = z1.m1;

	cout << z2.m1.m.i[0] << endl;
	cout << z2.m1.m.i[1] << endl;

	//f(x1);
	//f(x2);
	//cout << "size = " << sizeof(T1) << endl;
	//cout << "size = " << sizeof(T2) << endl;
	//cout << "size = " << sizeof(T3) << endl;

	cout << "size = " << sizeof(fillColor) << endl;
	cout << "size = " << sizeof(Color<float>) << endl;
	//cout << "size = " << sizeof(Color<float>::ComponentProperty<0>) << endl;
	//cout << "size = " << Color<float>::testSize() << endl;

	fillColor.red = 32;
	fillColor.green = 64;
	fillColor.blue = 128;
	fillColor.alpha = 255;

	borderColor.red = 0;
	borderColor.green = 0;
	borderColor.blue = 0;
	borderColor.alpha = 0;

	//fillColor.red.components[0] = 5;
	//fillColor.all.components[0] = 5;

	//(fillColor.red = fillColor.green) = 72;
	//fillColor.alpha = fillColor.blue = 255;

	//fillColor.red = borderColor.blue;
	fillColor.red = borderColor.red;
	//fillColor.alpha = fillColor.alpha;
	//borderColor.alpha = (unsigned char)fillColor.alpha;

	//borderColor.alpha = 1.0;
	//borderColor.blue = fillColor;

	cout << (int)fillColor.red << endl;
	cout << (int)fillColor.green << endl;
	cout << (int)fillColor.blue << endl;
	cout << (int)fillColor.alpha << endl;
	//cout << fillColor.all << endl;

	cout << (int)borderColor.red << endl;
	cout << (int)borderColor.green << endl;
	cout << (int)borderColor.blue << endl;
	cout << (int)borderColor.alpha << endl;

	system("pause");
	return 0;
} // end function main
