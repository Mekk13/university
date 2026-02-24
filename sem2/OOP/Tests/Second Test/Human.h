#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

class Human {
private:
	int USbirthday;
public:
	Human(int bd) : USbirthday(bd) {};
	virtual ~Human();
	int years();
	virtual bool receiveCitizenship() = 0;
	virtual bool mustBeDeported() = 0;
	virtual std::string toString();
};

class Family : public Human {
private:
	int membersNo, Americans;
public:
	Family(int bd, int nr, int a) :Human(bd), membersNo(nr), Americans(a) {};
	~Family();
	bool receiveCitizenship();
	bool mustBeDeported();
	std::string toString();
};

class Person :public Human {
private:
	bool American;
public:
	Person(int bd, bool b) :Human(bd), American(b) {};
	~Person();
	bool receiveCitizenship();
	bool mustBeDeported();
	std::string toString();
};