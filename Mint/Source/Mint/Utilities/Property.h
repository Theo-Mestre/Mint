#ifndef CORE_PROTERTY_H
#define CORE_PROTERTY_H
// C# like property implementation in C++
#include <functional>

template <typename T>
class Property
{
public:
	Property() : value(nullptr) {}
	Property(T& _value) = delete;
	virtual ~Property() = default;

	virtual T& operator= (const T& f) { return value = f; }
	virtual const T& operator() () const { return value; }
	virtual explicit operator const T& () const { return value; }
	virtual T* operator->() { return &value.get(); }
	friend std::ostream& operator<<(std::ostream& os, const Property& p)
	{
		os << *p.value;
		return os;
	}

	virtual T* GetValue() { return value; }

	virtual void SetValue(T& _value) { value = &_value; }
	virtual void SetValue(T* const _value) { value = _value; }

	virtual bool IsValid() { return value != nullptr; }
protected:
	T* value;
};

template <typename T>
class PropertyReadOnly
{
public:
	PropertyReadOnly() : value(nullptr) {}
	PropertyReadOnly(T* _value) = delete;
	virtual ~PropertyReadOnly() = default;

	T& operator= (const T& f) = delete;
	T& operator= (const T* f) = delete;

	virtual const T& operator() () const { return *value; }
	virtual explicit operator const T& () const { return *value; }
	friend std::ostream& operator<<(std::ostream& os, const PropertyReadOnly& p)
	{
		os << *p.value;
		return os;
	}

	virtual T* GetValue() { return value; }

	virtual void SetValue(T& _value) { value = &_value; }
	virtual void SetValue(T* const _value) { value = _value; }

	virtual bool IsValid() { return value != nullptr; }
protected:
	T* value;
};
#endif