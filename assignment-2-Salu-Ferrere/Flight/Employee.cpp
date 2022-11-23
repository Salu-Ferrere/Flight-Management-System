#include "Employee.hpp"

Employee::Employee(const std::string &name, int ID): Human(name) {
	this->ID = ID;
}

//returns ID of employee
int Employee::getID() const {
	return ID;
}

Employee::~Employee() {
}
