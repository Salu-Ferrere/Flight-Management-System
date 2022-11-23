#include "Date.hpp"

Date::Date(int day, int hour) {
	this-> day = day;
	this->hour = hour;
}

//returns hour
int Date::getHour() const {
	if (hour < 0 || hour > 23){
		return 0;
	}
    return hour;
}

//returns day
int Date::getDay() const {
	if (day < 1){
		return 1;
	}
    return day;
}

//changes value of day and hour to those entered in method
void Date::changeDateTo(int day, int hour) {
	this->day = day;
	this->hour = hour;
}

//adds time in the form of hours, method makes sure to convert an amount of 24 hours into a day
void Date::addTime(int count) {
	day = day + (count / 24);
	hour = hour + (count % 24);
	if(hour > 23){
		hour = hour - 24;
		day = day + 1;
	}
}

//returns true if date is less than the "other" entered date
bool Date::isLessThan(const Date &other) const {
	if (getDay() < other.getDay()){
		return true;
	}
	if (getDay() == other.getDay() && getHour() < other.getHour()){
			return true;
		}
    return false;
}
