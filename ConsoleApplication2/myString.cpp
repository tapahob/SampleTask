#include "myString.h"
#include <windows.h>

myString::myString(void)
{
	_string = new char[MAX_STR_LENGTH];
	strcpy(_string, "");
}

myString::myString( const myString& other)
{
	(*this) = const_cast<myString&>(other);
}

myString::~myString(void)
{
	delete[] _string;
}

myString& myString::operator=(const myString& other)
{
	_string = new char[MAX_STR_LENGTH];
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

	char str1[MAX_STR_LENGTH];
	strcpy(str1,_string);
	strcat_s(str1, other.cStr());

	*result = str1;
	return *result;
}