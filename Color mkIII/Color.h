#ifndef COLOR_H
#define COLOR_H

#include "supporting components.h"

namespace RGBA
{
#include "Property.h"

template<typename ComponentType = unsigned char,bool clamp = false,bool treatIntegralAsUChar = true>
class Color
{
	// Nested Classes

	// Fields
	ComponentType components[4];

	// Methods
public:
	/**
		if clamp == false it leaves the object uninitialized.
	*/
	Color() throw()
	{
		if(clamp)
		{
			red() = green() = blue() = 0.0;
			alpha() = 1.0;
		} // end if
	} // end default Color constructor

	template<typename ArgType>
	Color(ArgType intensity) throw()
	{
		red() = green() = blue() = intensity;
		alpha() = 1.0;
	} // end Color constructor

	template<typename ArgType>
	Color(ArgType intensity, ArgType alpha) throw()
	{
		red() = green() = blue() = intensity;
		this->alpha() = alpha;
	} // end Color constructor

	template<typename ArgType>
	Color(ArgType red, ArgType green, ArgType blue) throw()
	{
		this->red() = red;
		this->green() = green;
		this->blue() = blue;
		this->alpha() = 1.0;
	} // end Color constructor

	template<typename ArgType>
	Color(ArgType red, ArgType green, ArgType blue, ArgType alpha) throw()
	{
		this->red() = red;
		this->green() = green;
		this->blue() = blue;
		this->alpha() = alpha;
	} // end Color constructor

	~Color() throw()
	{
		// empty
	} // end ~Color destructor


	// property functions
#define property_function(Name,Index,Const,Constant) \
	Property<ComponentType,clamp,treatIntegralAsUChar,Constant> Name() Const  throw() \
	{ \
		return Property<ComponentType,clamp,treatIntegralAsUChar,Constant>(&components[Index]); \
	}

	property_function(red,0, ,false)
	property_function(red,0,const,true)
	property_function(green,1, ,false)
	property_function(green,1,const,true)
	property_function(blue,2, ,false)
	property_function(blue,2,const,true)
	property_function(alpha,3, ,false)
	property_function(alpha,3,const,true)
#undef property_function

	// does a template declaration of a copy constructor suppress generation of the default?
	// anyway default copy constructor will work just fine.

	template<typename T,bool C,bool AsUC>
	Color(const Color<T,C,AsUC> &original) throw()
	{
		this->red() = original.red();
		this->green() = original.green();
		this->blue() = original.blue();
		this->alpha() = original.alpha();
	} // end Color copy constructor

	template<typename T,bool C,bool AsUC>
	Color &operator=(const Color<T,C,AsUC> &original) throw()
	{
		this->red() = original.red();
		this->green() = original.green();
		this->blue() = original.blue();
		this->alpha() = original.alpha();
		return *this;
	} // end function operator=

	operator const ComponentType *() const throw()
	{
		return components;
	} // end function operator const ComponentType *
}; // end class Color

} // end namespace RGBA

#endif