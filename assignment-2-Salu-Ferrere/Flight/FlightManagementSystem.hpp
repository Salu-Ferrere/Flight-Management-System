#ifndef FLIGHTMANAGEMENTSYSTEM_HPP
#define FLIGHTMANAGEMENTSYSTEM_HPP

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "Flight.hpp"
#include "Customer.hpp"

class FlightManagementSystem {
private:
	std::vector<Customer *> customers;
	std::vector<Flight *> flights;
	std::vector<Date *> times;
	std::vector<int> seatsTaken = std::vector<int>(100, 0);

	Customer * getCustomerFromPPN(const string &passportNumber) ;
public:
    FlightManagementSystem();
    static string author();
    bool bookTicket(Route* route, Date *time, const string &passportNumber, int quantity);
    bool addCustomer(Customer *customer);

    int getCapacity(const Route* route, const Date* time) const;
    void addFlight(Flight* flight, Date* time);
    int getCustomerPoints(const string &passportNumber) const;

    std::vector<Flight *> getFlights() const;
    std::vector<Customer *> getCustomers() const;

    ~FlightManagementSystem();
};

#endif
