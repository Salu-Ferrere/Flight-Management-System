#include "FlightAttendant.hpp"

FlightAttendant::FlightAttendant(const string &name, int ID) : Employee(name,ID) {
	this->languages.reserve(5);

}
//adds a language that the flight attendant can speak to a vector of enums
void FlightAttendant::addLanguage(Country::Language language) {
	languages.push_back(language);

}
//returns true if the entered enum language can be spoken by and is in the flight attendants languages vector
bool FlightAttendant::canSpeak(Country::Language language) const {
	for (unsigned int i = 0; i < languages.size(); i++) {
			if(languages[i] == language){
				return true;
			}
	}
	return false;

}
