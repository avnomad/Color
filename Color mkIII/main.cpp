#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <cstdlib>
using std::system;

#include <gl/glew.h>
#include <gl/glut.h>

#include "Color.h"
using namespace Utility;
using namespace RGBA;

#define test(A,B) cout  << setprecision(20); \
					cout << #A " -> " #B "  "; \
					if(ConvertColor<B>(color_limits<A>::min()) == color_limits<B>::min() || std::numeric_limits<A>::is_integer && std::numeric_limits<B>::is_integer && std::numeric_limits<A>::is_signed && !std::numeric_limits<B>::is_signed && ConvertColor<B>(color_limits<A>::min()) == 0) \
						cout << "\n"; \
					else \
						cout << (long double)color_limits<A>::min() << " -> " << (long double)ConvertColor<B>(color_limits<A>::min()) << endl; \
					cout << #A " -> " #B "  "; \
					if(ConvertColor<B>(color_limits<A>::max()) == color_limits<B>::max()) \
						cout << "\n"; \
					else \
						cout << (long double)color_limits<A>::max() << " -> " << (long double)ConvertColor<B>(color_limits<A>::max()) << endl; \
					cout << #A " -> " #B "  " << (long double)((color_limits<A>::min()+color_limits<A>::max())/2) << " -> " << (long double)ConvertColor<B>((A)((color_limits<A>::min()+color_limits<A>::max())/2)) << endl; \

/// \author Anogeianakis Vaptistis

/// The program starts here!
/** This is a test program for the class \b Color so
	there is not much structure in the code...
*/

int main(int argc,char **argv)
{
	//// clamp test
	//cout << clamp(1.2,0.0,1.0) << endl;
	//cout << clamp(0.9,0.0,1.0) << endl;
	//cout << clamp(-0.1,0.0,1.0) << endl;
	//cout << clamp(1.2,-1.0,1.0) << endl;
	//cout << clamp(0.9,-1.0,1.0) << endl;
	//cout << clamp(-0.1,-1.0,1.0) << endl;
	//cout << clamp<double>(-2,-1.0,1.0) << endl;
	//cout << clamp(1,0,1) << endl;
	//cout << clamp(0,0,1) << endl;
	//cout << clamp(1,-10,10) << endl;
	//cout << clamp(-20,-10,10) << endl;
	//cout << clamp(29,-10,10) << endl;
	//cout << clamp(5,-10,10) << endl;
	//cout << clamp(15,-10,10) << endl;

	//// testing color_limits
	//cout << "max char: " << (long long)color_limits<char>::max() << endl;
	//cout << "min char: " << (long long)color_limits<char>::min() << endl;
	//cout << "max unsigned char: " << (long long)color_limits<unsigned char>::max() << endl;
	//cout << "min unsigned char: " << (long long)color_limits<unsigned char>::min() << endl;
	//cout << "max signed char: " << (long long)color_limits<signed char>::max() << endl;
	//cout << "min signed char: " << (long long)color_limits<signed char>::min() << endl;
	//cout << "max unsigned short: " << color_limits<unsigned short>::max() << endl;
	//cout << "min unsigned shbrt: " << color_limits<unsigned short>::min() << endl;
	//cout << "max signed short: " << color_limits<signed short>::max() << endl;
	//cout << "min signed short: " << color_limits<signed short>::min() << endl;
	//cout << "max unsigned int: " << color_limits<unsigned int>::max() << endl;
	//cout << "min unsigned int: " << color_limits<unsigned int>::min() << endl;
	//cout << "max signed int: " << color_limits<signed int>::max() << endl;
	//cout << "min signed int: " << color_limits<signed int>::min() << endl;
	//cout << "max unsigned long: " << color_limits<unsigned long>::max() << endl;
	//cout << "min unsigned long: " << color_limits<unsigned long>::min() << endl;
	//cout << "max signed long: " << color_limits<signed long>::max() << endl;
	//cout << "min signed long: " << color_limits<signed long>::min() << endl;
	//cout << "max unsigned long long: " << color_limits<unsigned long long>::max() << endl;
	//cout << "min unsigned long long: " << color_limits<unsigned long long>::min() << endl;
	//cout << "max signed long long: " << color_limits<signed long long>::max() << endl;
	//cout << "min signed long long: " << color_limits<signed long long>::min() << endl;
	//cout << "max float: " << color_limits<float>::max() << endl;
	//cout << "min float: " << color_limits<float>::min() << endl;
	//cout << "max double: " << color_limits<double>::max() << endl;
	//cout << "min double: " << color_limits<double>::min() << endl;
	//cout << "max long double: " << color_limits<long double>::max() << endl;
	//cout << "min long double: " << color_limits<long double>::min() << endl;

	//cout << "max GLByte: " << (int)color_limits<GLbyte>::max() << endl;
	//cout << "min GLByte: " << (int)color_limits<GLbyte>::min() << endl;
	//cout << "max GLUByte: " << (int)color_limits<GLubyte>::max() << endl;
	//cout << "min GLUByte: " << (int)color_limits<GLubyte>::min() << endl;
	//cout << "max GLshort: " << color_limits<GLshort>::max() << endl;
	//cout << "min GLshort: " << color_limits<GLshort>::min() << endl;
	//cout << "max GLushort: " << color_limits<GLushort>::max() << endl;
	//cout << "min GLushort: " << color_limits<GLushort>::min() << endl;
	//cout << "max GLint: " << color_limits<GLint>::max() << endl;
	//cout << "min GLint: " << color_limits<GLint>::min() << endl;
	//cout << "max GLuint: " << color_limits<GLuint>::max() << endl;
	//cout << "min GLuint: " << color_limits<GLuint>::min() << endl;
	//cout << "max GLfloat: " << color_limits<GLfloat>::max() << endl;
	//cout << "min GLfloat: " << color_limits<GLfloat>::min() << endl;
	//cout << "max GLdouble: " << color_limits<GLdouble>::max() << endl;
	//cout << "min GLdouble: " << color_limits<GLdouble>::min() << endl;

	// test ConvertColor
	test(char,char)
	test(char, unsigned char)
	test(char, signed char)
	test(char, unsigned short)
	test(char, signed short)
	test(char, unsigned int)
	test(char, signed int)
	test(char, unsigned long)
	test(char, signed long)
	test(char, unsigned long long)
	test(char, signed long long)
	test(char, float)
	test(char, double)
	test(char, long double)

	test(unsigned char,char)
	test(unsigned char, unsigned char)
	test(unsigned char, signed char)
	test(unsigned char, unsigned short)
	test(unsigned char, signed short)
	test(unsigned char, unsigned int)
	test(unsigned char, signed int)
	test(unsigned char, unsigned long)
	test(unsigned char, signed long)
	test(unsigned char, unsigned long long)
	test(unsigned char, signed long long)
	test(unsigned char, float)
	test(unsigned char, double)
	test(unsigned char, long double)

	test(signed char,char)
	test(signed char, unsigned char)
	test(signed char, signed char)
	test(signed char, unsigned short)
	test(signed char, signed short)
	test(signed char, unsigned int)
	test(signed char, signed int)
	test(signed char, unsigned long)
	test(signed char, signed long)
	test(signed char, unsigned long long)
	test(signed char, signed long long)
	test(signed char, float)
	test(signed char, double)
	test(signed char, long double)

	test(unsigned short,char)
	test(unsigned short, unsigned char)
	test(unsigned short, signed char)
	test(unsigned short, unsigned short)
	test(unsigned short, signed short)
	test(unsigned short, unsigned int)
	test(unsigned short, signed int)
	test(unsigned short, unsigned long)
	test(unsigned short, signed long)
	test(unsigned short, unsigned long long)
	test(unsigned short, signed long long)
	test(unsigned short, float)
	test(unsigned short, double)
	test(unsigned short, long double)

	test(signed short,char)
	test(signed short, unsigned char)
	test(signed short, signed char)
	test(signed short, unsigned short)
	test(signed short, signed short)
	test(signed short, unsigned int)
	test(signed short, signed int)
	test(signed short, unsigned long)
	test(signed short, signed long)
	test(signed short, unsigned long long)
	test(signed short, signed long long)
	test(signed short, float)
	test(signed short, double)
	test(signed short, long double)

	test(unsigned int,char)
	test(unsigned int, unsigned char)
	test(unsigned int, signed char)
	test(unsigned int, unsigned short)
	test(unsigned int, signed short)
	test(unsigned int, unsigned int)
	test(unsigned int, signed int)
	test(unsigned int, unsigned long)
	test(unsigned int, signed long)
	test(unsigned int, unsigned long long)
	test(unsigned int, signed long long)
	test(unsigned int, float)
	test(unsigned int, double)
	test(unsigned int, long double)

	test(signed int,char)
	test(signed int, unsigned char)
	test(signed int, signed char)
	test(signed int, unsigned short)
	test(signed int, signed short)
	test(signed int, unsigned int)
	test(signed int, signed int)
	test(signed int, unsigned long)
	test(signed int, signed long)
	test(signed int, unsigned long long)
	test(signed int, signed long long)
	test(signed int, float)
	test(signed int, double)
	test(signed int, long double)

	test(unsigned long,char)
	test(unsigned long, unsigned char)
	test(unsigned long, signed char)
	test(unsigned long, unsigned short)
	test(unsigned long, signed short)
	test(unsigned long, unsigned int)
	test(unsigned long, signed int)
	test(unsigned long, unsigned long)
	test(unsigned long, signed long)
	test(unsigned long, unsigned long long)
	test(unsigned long, signed long long)
	test(unsigned long, float)
	test(unsigned long, double)
	test(unsigned long, long double)

	test(signed long,char)
	test(signed long, unsigned char)
	test(signed long, signed char)
	test(signed long, unsigned short)
	test(signed long, signed short)
	test(signed long, unsigned int)
	test(signed long, signed int)
	test(signed long, unsigned long)
	test(signed long, signed long)
	test(signed long, unsigned long long)
	test(signed long, signed long long)
	test(signed long, float)
	test(signed long, double)
	test(signed long, long double)

	test(unsigned long long,char)
	test(unsigned long long, unsigned char)
	test(unsigned long long, signed char)
	test(unsigned long long, unsigned short)
	test(unsigned long long, signed short)
	test(unsigned long long, unsigned int)
	test(unsigned long long, signed int)
	test(unsigned long long, unsigned long)
	test(unsigned long long, signed long)
	test(unsigned long long, unsigned long long)
	test(unsigned long long, signed long long)
	test(unsigned long long, float)
	test(unsigned long long, double)
	test(unsigned long long, long double)

	test(signed long long,char)
	test(signed long long, unsigned char)
	test(signed long long, signed char)
	test(signed long long, unsigned short)
	test(signed long long, signed short)
	test(signed long long, unsigned int)
	test(signed long long, signed int)
	test(signed long long, unsigned long)
	test(signed long long, signed long)
	test(signed long long, unsigned long long)
	test(signed long long, signed long long)
	test(signed long long, float)
	test(signed long long, double)
	test(signed long long, long double)

	test(float,char)
	test(float, unsigned char)
	test(float, signed char)
	test(float, unsigned short)
	test(float, signed short)
	test(float, unsigned int)
	test(float, signed int)
	test(float, unsigned long)
	test(float, signed long)
	test(float, unsigned long long)
	test(float, signed long long)
	test(float, float)
	test(float, double)
	test(float, long double)

	test(double,char)
	test(double, unsigned char)
	test(double, signed char)
	test(double, unsigned short)
	test(double, signed short)
	test(double, unsigned int)
	test(double, signed int)
	test(double, unsigned long)
	test(double, signed long)
	test(double, unsigned long long)
	test(double, signed long long)
	test(double, float)
	test(double, double)
	test(double, long double)

	test(long double,char)
	test(long double, unsigned char)
	test(long double, signed char)
	test(long double, unsigned short)
	test(long double, signed short)
	test(long double, unsigned int)
	test(long double, signed int)
	test(long double, unsigned long)
	test(long double, signed long)
	test(long double, unsigned long long)
	test(long double, signed long long)
	test(long double, float)
	test(long double, double)
	test(long double, long double)

	system("pause");
	return 0;
} // end function main