#include "Human.hpp"

Human::Human(const std::string &name) {
	this->name = name;
}
//returns name of human
std::string Human::getName() const {
    return name;
}

Human::~Human() {
}
