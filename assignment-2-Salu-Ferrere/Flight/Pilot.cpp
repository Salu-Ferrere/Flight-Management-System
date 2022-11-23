#include "Pilot.hpp"

Pilot::Pilot(const std::string &name, int ID) : Employee(name, ID) {
	level = CO_PILOT;
}
//returns the rank of the pilot in the form of an enum
Pilot::Level Pilot::getLevel() const {
    return level;
}
//if the pilot is a co-captain this method promotes them to captain
bool Pilot::promote() {
	if (level == CO_PILOT){
		level = CAPTAIN;
		return true;
	}
    return false;
}
//if the pilot is a captain, this method demotes them to co-captain
bool Pilot::demote() {
	if (level == CAPTAIN){
			level = CO_PILOT;
			return true;
	}
    return false;
}

