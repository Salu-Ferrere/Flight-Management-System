#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "Pilot.hpp"
#include "Route.hpp"
#include "FlightAttendant.hpp"
#include "Airplane.hpp"
#include "Date.hpp"

class Flight{
protected:
	Route *route;
	Airplane *airplane;
    Flight& operator=(const Flight& other);
    Flight(const Flight& other);
    bool successfull;
    bool successfullFA;
    std::vector<Pilot *> Pilots;
    std::vector<FlightAttendant *> FlightAttendants ;
public:
    Flight(Route *route, Airplane* airplane);

    bool setFlightAttendants(vector<FlightAttendant*> flightAttendants);
    bool setPilots(vector<Pilot*> pilots);

    bool bookTicket(int quantity);
    int getAvailableSeats() const;
    Route* getRoute() const;
    Airplane* getAirplane() const;
    std::vector<Pilot *> getPilots() const;
    std::vector<FlightAttendant *> getFlightAttendants() const;

    ~Flight();
};

#endif
