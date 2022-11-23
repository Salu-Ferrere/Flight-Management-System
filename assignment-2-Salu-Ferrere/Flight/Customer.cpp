#include "Customer.hpp"

Customer::Customer(const std::string &name, const std::string &passportNumber) : Human(name) {
	this-> name = name;
	this-> passportNum = passportNumber;
	Points = 0;
}

//adds loyalty points
void Customer::addLoyaltyPoints(int points) {
	Points = Points + points;
}

//decreases loyalty  points without going below 0
void Customer::decreaseLoyaltyPoints(int points) {
	Points = Points - points;
	if (Points < 0){
		Points = 0;
	}
}

//returns number of loyalty points
int Customer::getLoyaltyPoints() const {
    return Points;
}

//returns passport number
std::string Customer::getPassportNumber() const {
    return passportNum;
}
