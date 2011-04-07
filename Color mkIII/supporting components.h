#ifndef SUPPORTING_COMPONENTS_H
#define SUPPORTING_COMPONENTS_H

#include <limits>

/// functions and classes supporting the \b Color class.
/** \attention The functions and classes coded here may be relocated to
	another header and/or source file.
*/
namespace Utility
{

/// clamps a value of type T between two values of the same type.
/** the type T must support comparison using the operators < and >.
	\pre \a minValue <= \a maxValue.
*/
template<typename T>
T clamp(T valueToClamp, T minValue, T maxValue)
	throw()
{
	if(valueToClamp > maxValue)
		return maxValue;
	if(valueToClamp < minValue)
		return minValue;
	return valueToClamp;
} // end function clamp


template<typename T>
struct toUnsigned
{
	typedef T type;
}; // end struct toUnsigned

template< >
struct toUnsigned<char>
{
	typedef unsigned char type;
}; // end struct toUnsigned

template< >
struct toUnsigned<signed char>
{
	typedef unsigned char type;
}; // end struct toUnsigned

template< >
struct toUnsigned<signed short>
{
	typedef unsigned short type;
}; // end struct toUnsigned

template< >
struct toUnsigned<signed int>
{
	typedef unsigned int type;
}; // end struct toUnsigned

template< >
struct toUnsigned<signed long>
{
	typedef unsigned long type;
}; // end struct toUnsigned

template< >
struct toUnsigned<signed long long>
{
	typedef unsigned long long type;
}; // end struct toUnsigned

} // end namespace Utility

namespace RGBA
{

template<typename ColorComponentType>
struct color_limits
{
	/// minimum nominal value of an object of type \b ColorComponentType
	/// representing a color component (e.i red, green, blue or alpha).
	static ColorComponentType min() throw()
	{
		if(std::numeric_limits<ColorComponentType>::is_integer) // resolved in compile time.
			return std::numeric_limits<ColorComponentType>::min();
		else
			return static_cast<ColorComponentType>(0.0);
	} // end method min

	/// maximum nominal value of an object of type \b ColorComponentType
	/// representing a color component (e.i red, green, blue or alpha).
	static ColorComponentType max() throw()
	{
		if(std::numeric_limits<ColorComponentType>::is_integer) // resolved in compile time.
			return std::numeric_limits<ColorComponentType>::max();
		else
			return static_cast<ColorComponentType>(1.0);
	} // end method max

}; // end class color_limits

/// used as a function to convert between color components of different types.
/** simulates the syntax of \c static_cast.
	\warning the color conversion uses the same formulas as OpenGL but with
	the actual bit width of the type, not the minimum defined by the standard.
	\todo may need to fix the above.
	\remark The conversion is done in such a way that if you convert an object \a src of type
	S to an object \a dst of type D then calling the appropriate glColor for each of them
	will have the same result. However if S is a signed integral type, src has a nonpositive
	value and D is an unsigned integral type, then there is no possible value for dst that will
	have the same effect as src while clamping is disabled for OpenGL.
*/
template<typename DestinationType>
class ConvertColor
{
	// fields
	DestinationType convertedValue;

	// methods
public:
	inline ConvertColor(DestinationType sourceValue) throw()
	{
		convertedValue = sourceValue;
	} // end ConvertColor conversion constructor                                                                                                                                    

	template<typename SourceType>
	inline ConvertColor(SourceType sourceValue) throw()
	{
		typedef std::numeric_limits<DestinationType> dLimits;
		typedef std::numeric_limits<SourceType> sLimits;
		typedef std::numeric_limits<toUnsigned<DestinationType>::type> udLimits;
		typedef std::numeric_limits<toUnsigned<SourceType>::type> usLimits;

		if(!sLimits::is_integer && !dLimits::is_integer) // floating to floating (no temps)
		{
			convertedValue = static_cast<DestinationType>(sourceValue);
			return;
		} // end if

		long double temp; // intermediate results in maximum accuracy.

		if(sLimits::is_integer && sLimits::is_signed)
			if(dLimits::is_integer && !dLimits::is_signed && sourceValue < 0)	// there is no conversion from s<0 to u 
				temp = 0.0l;		// such that s and u would wield the same effect during rendering without clamping
			else
				temp = (2.0l*sourceValue+1) / usLimits::max();	// denominator 2^b-1
		if(sLimits::is_integer && !sLimits::is_signed)
			temp = (long double)sourceValue / sLimits::max();	// denominator 2^b-1
		if(!sLimits::is_integer)
			temp = (long double)sourceValue;

		if(dLimits::is_integer && dLimits::is_signed)
			convertedValue = (DestinationType)(0.5l*(udLimits::max()*temp-1));
		if(dLimits::is_integer && !dLimits::is_signed)
			convertedValue = (DestinationType)(dLimits::max()*temp);
		if(!dLimits::is_integer)
			convertedValue = (DestinationType)temp;
	} // end ConvertColor conversion constructor

	inline operator DestinationType() const throw()
	{
		return convertedValue;
	} // end function operator DestinationType
}; // end class ConvertColor

} // end namespace RGBA

#endif