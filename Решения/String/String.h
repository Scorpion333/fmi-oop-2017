#ifndef STRING_H    // Instead of #pragma once
#define STRING_H    // Because of #ifndef

#include<fstream>

class String {
private:
	char* arr;
	
	// Nice method which can be called in every constuctor
	void copy(const char* _arr);

public:
	String();
	String(const char* _arr);
	String(const String& other);
	
	String& operator = (const String& other);
	String& operator = (const char* _arr);
	
	~String();

	unsigned length() const;
	bool operator == (const String& other) const;

	// The "getter"
	const char* c_str() const;

	friend std::istream& operator >> (std::istream& in, String& str);
	friend std::ostream& operator << (std::ostream& out, const String& str);
};

#endif      // Because of #ifndef