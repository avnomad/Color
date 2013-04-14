//	Copyright (C) 2010-2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of Color Mk. II.
 *
 *	Color Mk. II is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Color Mk. II is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Color Mk. II.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COLOR
#define COLOR

//class T4{};

//// assumes ComponentType is small enough to be passed efficiently by value.
//template<typename ComponentType,bool clamp = true>
//class Color : public T4
//{
//	template<int offset>
//	struct ComponentProperty
//	{
//		//inline operator ComponentType() const
//		//{
//		//	cout << '(';
//		//	//return ((Color*)this)->components[offset];
//		//	return 0;
//		//} // end function operator ComponentType
//
//		//inline ComponentProperty<offset> &operator=(ComponentType component)
//		//{
//		//	cout << '=';
//		//		// add clamp logic here
//		//	//((Color*)this)->components[offset] = component;
//		//	return *this;
//		//} // end function operator =
//
//	}; // end struct template ComponentProperty
//
//
//public:
//	T4 t1;
//	T4 t2;
//	T4 t3;
//	ComponentProperty<0> red;
//	ComponentProperty<1> green;
//	ComponentProperty<2> blue;
//	ComponentProperty<3> alpha;
//private:
//	ComponentType components[4];
//
//public:
//	static int testSize()
//	{
//		return sizeof(ComponentProperty<0>);
//	}
//	inline Color(){}	// default constructor
//}; // end class Color










// assumes ComponentType is small enough to be passed efficiently by value.
template<typename ComponentType,bool clamp = true>
class Color
{
private:
	class Fields
	{
		ComponentType components[4];
		friend class Color;
		template<int offset>
		friend struct ComponentProperty;
	}; // end class Fields

	template<int offset>
	struct ComponentProperty /*: public Fields*/
	{
		Fields f;
		inline operator ComponentType() const
		{
			//cout << '(';
			return f.components[offset];
		} // end function operator ComponentType

		inline ComponentProperty<offset> &operator=(ComponentType component)
		{
			//cout << '=';
				// add clamp logic here
			f.components[offset] = component;
			return *this;
		} // end function operator =

	}; // end struct template ComponentProperty

public:
	union
	{
		Fields all;
		ComponentProperty<0> red;
		ComponentProperty<1> green;
		ComponentProperty<2> blue;
		ComponentProperty<3> alpha;
	}; // end unnamed union

	inline Color(){}	// default constructor
}; // end class Color

#endif // COLOR_H