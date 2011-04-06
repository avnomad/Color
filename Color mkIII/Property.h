
/**	\note It is assumed that ComponentType is small enough to be more efficiently passed by value.	
*/

template<typename ComponentType,bool clamp,bool treatIntegralAsUChar,bool constant> class Property;

template<typename ComponentType,bool clamp,bool treatIntegralAsUChar>
class Property<ComponentType,clamp,treatIntegralAsUChar,false>
{
	// Fields
	ComponentType *referredComponent;

	// Methods
public:
	inline Property(ComponentType *componentAddress)
		:referredComponent(componentAddress)
	{
		// empty body
	} // end Property constructor

	// default copy constructor and destructor should do.

	inline operator ComponentType() const
	{
		return *referredComponent;
	} // end function operator ComponentType

	inline Property &operator=(const Property &right)
	{
		// TODO add clamp support
		*this->referredComponent = *right.referredComponent;
		return *this;
	} // end function operator=

	template<typename RightType,bool C,bool AsUC,bool constant>
	inline Property &operator=(const Property<RightType,C,AsUC,constant> &right)
	{
		// TODO add clamp support
		*this->referredComponent = ConvertColor<ComponentType>((RightType)right);
		return *this;
	} // end function operator=

	template<typename RightType>
	inline Property &operator=(RightType right)
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
	const ComponentType *referredComponent;

	inline Property &operator=(const Property &original)	// should not be called!! class represents const object.
	{
		return *this;
	} // end function operator=

	// Methods
public:
	inline Property(const ComponentType *componentAddress)
		:referredComponent(componentAddress)
	{
		// empty body
	} // end Property constructor

	// default copy constructor and destructor should do.

	inline operator ComponentType() const
	{
		return *referredComponent;
	} // end function operator ComponentType
}; // end class Property
