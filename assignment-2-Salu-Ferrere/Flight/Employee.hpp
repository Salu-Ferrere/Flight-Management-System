
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Human.hpp"

class Employee : public Human {
protected:
	int ID;

public:
	Employee(const std::string &name, int ID);
    virtual int getID() const;
    ~Employee();
};

#endif
