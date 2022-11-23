
#include "Country.hpp"

Country::Country(const string &name,Language language) {
	this->name = name;
	this->language = language;
}

//returns language spoken in country as an enum
Country::Language Country::getLanguage() const {
    return language;
}

//returns name of country as a string
std::string Country::getName() const {
    return name;
}
