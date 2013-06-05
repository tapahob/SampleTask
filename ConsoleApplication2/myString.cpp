#include "myString.h"
#include <windows.h>

myString::myString(void)
{
	_string = new char[1];
	strcpy(_string, "\n");
}

myString::myString( const myString& other)
{
	(*this) = const_cast<myString&>(other);
}

myString::~myString(void)
{
	delete[] _string;
	_string = NULL;
}

myString& myString::operator=(const myString& other)
{
	auto len = other.Length();
	_string = new char[len+1];
	strcpy(_string, other.cStr());
	return *this;
}

void myString::operator=( const char* other )
{
	strcpy(_string, other);
}

const char* myString::cStr() const
{
	return _string;
}

const unsigned int myString::Length() const
{
	return strlen(_string);
}

const myString& myString::operator+( const myString& other ) const
{
	myString* result = new myString(*this);

	auto length = other.Length() + Length();
	auto str1 = new char[length + 1];
	strcpy(str1,_string);
	strcat(str1, other.cStr());

	*result = str1;
	delete[] str1;
	return *result;
}