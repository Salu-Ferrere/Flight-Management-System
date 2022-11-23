#include "FlightManagementSystem.hpp"

#include <vector>
#include <string>

using namespace std;

FlightManagementSystem::FlightManagementSystem(){

}
//return upi number
string FlightManagementSystem::author() {
    return "srdo190";
}
//return a pointer to a customer that has a matching passport number as the one entered into the method
//by looping through a vector of added customers and comparing their passport numbers to the entered one
Customer * FlightManagementSystem::getCustomerFromPPN(const string &passportNumber) {
	for (unsigned int i = 0; i < customers.size(); i++) {
			if(passportNumber == customers[i]->getPassportNumber()){
				return customers[i];
			}
	}
	return NULL;
}
//returns true if there is flight with a matching route and time with enough available seats
bool FlightManagementSystem::bookTicket(Route* route, Date *time, const string &passportNumber, int quantity) {

	Country* destinationCountry = route->getDestination();
	Country* sourceCountry = route->getSource();
	//returns false if customer tries to book more tickets than seats available on the plane
	if(getCapacity(route, time) < quantity){
		return false;
	}
    //returns false if customers passport number is not on record
	if(this->getCustomerFromPPN(passportNumber) == NULL){
		return false;
	}

	Customer * customer = getCustomerFromPPN(passportNumber);

	for (unsigned int i = 0; i < flights.size(); i++) {
		//gets all route and time variables from vector of corresponding dates and flights
		Route * flightRoute = flights[i]->getRoute();
		Country * destination = flightRoute->getDestination();
		Country * source = flightRoute->getSource();
		int day = times[i]->getDay();
		int hour = times[i]->getHour();
		int seats = flights[i]->getAvailableSeats();
        //loops through vectors of corresponding dates and flights to see if one matches the flight trying to be booked, if successful
		// the number of available seats will be decreased respectfully and loyalty points added to the customer booking
		if(destination == destinationCountry && source == sourceCountry &&
				day == time->getDay() && hour == time->getHour() && seats >= quantity){
			seatsTaken[i] = seatsTaken[i] + quantity;

			int points = (route->getHours() * quantity);
			customer->addLoyaltyPoints(points);

			return true;

		}

	}

    return false;
}

//returns the available seats of the flight that matches the correct route and time, returning -1 if no such flight exists
int FlightManagementSystem::getCapacity(const Route* route, const Date *time) const {
	Country* des = route->getDestination();
	Country* src = route->getSource();
	//gets all route and time variables from vector of corresponding dates and flights
	for (unsigned int i = 0; i < flights.size(); i++) {
			Country * destination = flights[i]->getRoute()->getDestination();
			Country * source = flights[i]->getRoute()->getSource();
			int day = times[i]->getDay();
			int hour = times[i]->getHour();
			int seats = flights[i]->getAvailableSeats();
			//loops through vectors of corresponding dates and flights to see if one matches the flight trying to be booked, if successful
			// the number of available seats is returned taking into account those filled by customer bookings
			if(destination == des && source == src &&
					day == time->getDay() && hour == time->getHour()){
				return seats - seatsTaken[i];

			}
	}


    return -1;
}
//returns the loyalty points of a customer using their passport number to look them up returning -1 if no such number exists
int FlightManagementSystem::getCustomerPoints(const string &passportNumber) const {
	for (unsigned int i = 0; i < customers.size(); i++) {
				if(passportNumber == customers[i]->getPassportNumber()){
					return customers[i]->getLoyaltyPoints();
				}
		}

	return -1;
}

//adds a pointer to a customer to a vector holding all added customer pointers, only if customer with same passport number has not been added
bool FlightManagementSystem::addCustomer(Customer *customer) {
	for (unsigned int i = 0; i < customers.size(); i++) {
		if(customer->getPassportNumber() == customers[i]->getPassportNumber()){
			return false;
		}
	}
	 customers.push_back(customer);
	return true;
}

//adds a pointer to a flight to a vector holding all added flight pointers
void FlightManagementSystem::addFlight(Flight* flight, Date* time) {
	flights.push_back(flight);
	times.push_back(time);

}
//returns vector of flight pointers of all added flights
vector<Flight *> FlightManagementSystem::getFlights() const {

    return flights;
}
//returns vector of customer pointers of all added customers
vector<Customer *> FlightManagementSystem::getCustomers() const {

	return customers;
}

FlightManagementSystem::~FlightManagementSystem() {
}

