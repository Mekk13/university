#pragma once
#include <stdio.h>
#include <string>
#include <exception>

class MyException : public std::exception {
private:
	std::string message;

public:
	MyException(const char* msg) : message(msg){}
	const char* what() const throw() {
		return message.c_str();
	}
};