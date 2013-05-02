#pragma once
#define MAX_STR_LENGTH 256

class myString
{
private:
	char* _string;

public:
	myString(void);
	myString(const myString&);
	~myString(void);

	myString& operator=(const myString& other);
	void operator=(const char* other);
	const myString& operator+(const myString& other) const;

	const char* cStr() const;

	const unsigned int Length() const;
private:
	void setString(const char* text);
};
