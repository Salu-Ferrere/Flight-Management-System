#include "Airplane.hpp"

Airplane::Airplane(int capacity) {
	this->capacity = capacity;
}

//Returns Capacity
int Airplane::getCapacity() const{
	if(capacity < 0){
		return 0;
	}
    return capacity;
}
