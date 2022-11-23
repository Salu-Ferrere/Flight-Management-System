#ifndef ROUTE_HPP
#define ROUTE_HPP
#include <string>

#include "Country.hpp"

class Route{
protected:
	int hours;
	Country *source;
	Country *destination;

public:
    Route(Country *source, Country *destination, int distance);
    Country* getSource() const;
    Country* getDestination() const;
    int getHours() const;
    ~Route();
private:
    Route& operator=(const Route& other);
    Route(const Route& other);

};

#endif
