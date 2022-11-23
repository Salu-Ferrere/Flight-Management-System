
#ifndef FLIGHTATTENDANT_HPP
#define FLIGHTATTENDANT_HPP

#include "Employee.hpp"
#include "Country.hpp"
#include <vector>
#include <iostream>
using namespace std;

class FlightAttendant : public Employee {
private:
	FlightAttendant& operator=(const FlightAttendant& other);
	FlightAttendant(const FlightAttendant& other);
	vector<Country::Language> languages;
public:
    FlightAttendant(const std::string &name, int ID);
    void addLanguage(Country::Language language);
    bool canSpeak(Country::Language language) const;


};
#endif
