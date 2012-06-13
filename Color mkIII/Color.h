//	Copyright (C) 2011-2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Color mkIII.
 *
 *	Color mkIII is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Color mkIII is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Color mkIII.  If not, see <http://www.gnu.org/licenses/>.
 */

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