#include "Route.hpp"

Route::Route(Country* source, Country* destination, int hours) {
	this->source = source;
    this->destination = destination;
	this->hours = hours;
}
//returns a pointer to the country of origin of the route
Country* Route::getSource() const{
    return source;
}
//returns a pointer to the destination country of the route
Country* Route::getDestination() const{
    return destination;
}
//returns the time in hours it would take to fly this route
int Route::getHours() const{
    return hours;
}

Route::~Route(){
}
