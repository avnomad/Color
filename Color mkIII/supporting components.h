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
		cout << "\373 ";
		convertedValue = sourceValue;
	} // end ConvertColor conversion constructor

	template<typename SourceType>
	inline ConvertColor(SourceType sourceValue) throw()
	{
		typedef std::numeric_limits<DestinationType> dLimits;
		typedef std::numeric_limits<SourceType> sLimits;

		if(!sLimits::is_integer && !dLimits::is_integer) // floating to floating (no temps)
		{
			convertedValue = static_cast<DestinationType>(sourceValue);
			return;
		} // end if

		long double temp; // intermediate results in maximum accuracy.

		if(sLimits::is_integer && sLimits::is_signed)
			if(dLimits::is_integer && !dLimits::is_signed)
				temp = ((long double)sourceValue-sLimits::min()) / (sLimits::max()-sLimits::min());	// denominator 2^b-1
			else
				temp = (2.0l*sourceValue+1) / (sLimits::max()-sLimits::min());	// denominator 2^b-1
		if(sLimits::is_integer && !sLimits::is_signed)
			temp = (long double)sourceValue / sLimits::max();	// denominator 2^b-1
		if(!sLimits::is_integer)
			temp = (long double)sourceValue;

		if(dLimits::is_integer && dLimits::is_signed)
			if(sLimits::is_integer && !dLimits::is_signed)
				convertedValue = (DestinationType)((dLimits::max()-dLimits::min())*temp+dLimits::min());
			else
				convertedValue = (DestinationType)(0.5l*((dLimits::max()-dLimits::min())*temp-1));
		if(dLimits::is_integer && !dLimits::is_signed)
			convertedValue = (DestinationType)(dLimits::max()*temp);
		if(!dLimits::is_integer)
			convertedValue = (DestinationType)temp;
	} // end ConvertColor conversion constructor

	inline operator DestinationType() throw()
	{
		return convertedValue;
	} // end function operator DestinationType
}; // end class ConvertColor

} // end namespace RGBA

#endif