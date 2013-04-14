//	Copyright (C) 2011-2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of Color Mk. III.
 *
 *	Color Mk. III is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Color Mk. III is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Color Mk. III.  If not, see <http://www.gnu.org/licenses/>.
 */

/**	\note It is assumed that ComponentType is small enough to be more efficiently passed by value.	
*/

template<typename ComponentType,bool clamp,bool treatIntegralAsUChar,bool constant> class Property;

template<typename ComponentType,bool clamp,bool treatIntegralAsUChar>
class Property<ComponentType,clamp,treatIntegralAsUChar,false>
{
	// Fields
	ComponentType *const referredComponent;

	// Methods
public:
	inline Property(ComponentType *componentAddress) throw()
		:referredComponent(componentAddress)
	{
		// empty body
	} // end Property constructor

	// default copy constructor and destructor should do.

	inline operator ComponentType() const throw()
	{
		return *referredComponent;
	} // end function operator ComponentType

	inline Property &operator=(const Property &right) throw()	// Property objects small, but compiler gets confused! :)
	{
		// TODO add clamp support
		*this->referredComponent = *right.referredComponent;
		return *this;
	} // end function operator=

	template<typename RightType,bool C,bool AsUC,bool constant>
	inline Property &operator=(const Property<RightType,C,AsUC,constant> &right) throw()
	{
		// TODO add clamp support
		*this->referredComponent = ConvertColor<ComponentType>((RightType)right);
		return *this;
	} // end function operator=

	template<typename RightType>
	inline Property &operator=(RightType right) throw()
	{
		// TODO add clamp support
		if(treatIntegralAsUChar && std::numeric_limits<RightType>::is_integer)
			*this->referredComponent = ConvertColor<ComponentType>((unsigned char)right);
		else
			*this->referredComponent = ConvertColor<ComponentType>(right);
		return *this;
	} // end function operator=
}; // end class Property


template<typename ComponentType,bool clamp,bool treatIntegralAsUChar>
class Property<ComponentType,clamp,treatIntegralAsUChar,true>
{
	// Fields
	const ComponentType *const referredComponent;

	inline Property &operator=(const Property &original) throw()	// should not be called!! class represents const object.
	{
		return *this;
	} // end function operator=

	// Methods
public:
	inline Property(const ComponentType *componentAddress) throw()
		:referredComponent(componentAddress)
	{
		// empty body
	} // end Property constructor

	// default copy constructor and destructor should do.

	inline operator ComponentType() const throw()
	{
		return *referredComponent;
	} // end function operator ComponentType
}; // end class Property
