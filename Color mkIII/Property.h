
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
