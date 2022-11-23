#include "Flight.hpp"
#include <iostream>
#include <cmath>
using namespace std;


#define MAXHOURS 8

Flight::Flight(Route *route, Airplane* airplane) {
	this->route = route;
	this->airplane = airplane;
	this->successfull = false;
	this->successfullFA = false;
}

//returns amount of available seats taking into account the number of seats required by pilots and
//flight attendants, which is determined by whether the flight is a long haul or short haul flight
int Flight::getAvailableSeats() const {
	int seats = airplane->getCapacity();
	if(route->getHours() < MAXHOURS){
		seats = seats - 3;
	} else {
		seats = seats - 8;
	}
    return seats;
}

//checks to see if there are enough seats on the plane to book the desired amount of tickets
bool Flight::bookTicket(int quantity) {
	if(quantity > getAvailableSeats()){
		return false;
	}

    return true;
}

//checks to see if the vector of pilots added to the flight meets the requirement for the flight
bool Flight::setPilots(vector<Pilot*> pilots) {
	if (successfull == true){
		return false;
	}


	int Copilots = 0;
	int Captains = 0;
	//loops thought pilot vector counting the number of captains and co-captains assigned to the flight
	for (unsigned int i = 0; i < pilots.size(); i++) {
			if(pilots[i]->getLevel() == Pilot::CO_PILOT){
				Copilots++;
			} else {
				Captains++;
			}
		}
	//for a short haul flight, checks that there are 2 pilots and that there is 1 Captain and 1 Co-Captain
	if((route->getHours() < MAXHOURS) && pilots.size() == 2 && Captains == 1){
		successfull = true;
		Pilots = pilots;
		return true;
	}
	//for a long haul flight, checks that there are 4 pilots and that there are 2 Captains and 2 Co-Captains
	if((route->getHours() >= MAXHOURS) && pilots.size() == 4 && Captains == 2){
		successfull = true;
		Pilots = pilots;
		return true;
	}
	return false;
}

//checks to see if the vector of flight attendants added to the flight meets the requirement for the flight
bool Flight::setFlightAttendants(vector<FlightAttendant*> flightAttendants) {
	if(successfullFA == true){
		return false;
	}
//gets destination language
	Country* destination = route->getDestination();
	Country::Language destinationLanguage = destination->getLanguage();
//gets source language
	Country* source = route->getSource();
	Country::Language sourceLanguage = source->getLanguage();
//sets arrays for numbers of languages spoken by each flight attendant and of index numbers
//of flight attendant that can only speak one language for cases of short haul and long haul flights
	Country::Language spoken[3][6];
	int numSpoken[6] = {0};
	vector<int> oneLanguage3;
	vector<int> oneLanguage6;

// sets number of flight attendants that can speak each language to 0
	int englishSpeakers = 0;
	int sourceLanguageSpeakers = 0;
	int destinationLanguageSpeakers = 0;

//loops through vector of flight attendants updating number of languages spoken array and speakers of a a language values
//while also adding the languages spoken to a 2d array, where the columns represent the different flight attendants and the rows
//the different languages.
	for(unsigned int i = 0; i < flightAttendants.size(); i++){
		if(flightAttendants[i]->canSpeak(Country::ENGLISH) == true){
			spoken[0][i] = Country::ENGLISH;
			numSpoken[i]++;
			englishSpeakers++;
		}

		if(flightAttendants[i]->canSpeak(destinationLanguage) == true){
			if(destinationLanguage != Country::ENGLISH){
				spoken[1][i] = destinationLanguage;
				numSpoken[i]++;
			}
			destinationLanguageSpeakers++;
		}
		if(flightAttendants[i]->canSpeak(sourceLanguage) == true){
			if(sourceLanguage != Country::ENGLISH && sourceLanguage != destinationLanguage){
				spoken[2][i] = sourceLanguage;
				numSpoken[i]++;
			}
			sourceLanguageSpeakers++;
		}
	}

//checks for condition of short haul flight, making sure there are only 3 flight attendants and that each language is spoken at least once
	if(route->getHours() < MAXHOURS && flightAttendants.size() == 3 && englishSpeakers > 0 && sourceLanguageSpeakers > 0 && destinationLanguageSpeakers > 0){
       //finds the index number of the flight attendants that can only speak one language returning false if a flight attendant can not speak any language
		int count = 0;
		for(unsigned int i = 0; i < 3; i++){
			if(numSpoken[i] == 0){
				return false;
			}
			if(numSpoken[i] == 1){
				oneLanguage3.push_back(i);
				count++;
			}
		}
		//returns true if there is only one flight attendant that speaks only one language
		if(count == 1){
			successfullFA = true;
			FlightAttendants = flightAttendants;
			return true;
		}
            // for the case where more than one flight attendant can only speak one language, makes sure these languages are different before returning true
		    //while also making sure flight attendants have'nt already successfully been added to the flight
		for(unsigned int j = 0; j < 3; j++){
			if(spoken[j][oneLanguage3[0]] == spoken[j][oneLanguage3[1]]){
				return false;
			}
		}
		successfullFA = true;
		FlightAttendants = flightAttendants;
		return true;
	}


	//checks for condition of long haul flight, making sure there are only 6 flight attendants and that each language is spoken at least twice
	if(route->getHours() >= MAXHOURS && flightAttendants.size() == 6 && englishSpeakers > 1 && sourceLanguageSpeakers > 1 && destinationLanguageSpeakers > 1){
		int count2 = 0;
		//finds the index number of the flight attendants that can only speak one language returning false if a flight attendant can not speak any language
		//and returning true if there are either 1 or 2 flight attendants that can only speak one language
		for(unsigned int i = 0; i < 6; i++){
			if(numSpoken[i] == 0){
				return false;
			}
			if(numSpoken[i] == 1){
				oneLanguage6.push_back(i);
				count2++;
			}
		}
		if(count2 <= 2){
			successfullFA = true;
			FlightAttendants = flightAttendants;
			return true;
		}

		int onlyEnglishSpeakers =0;
		int onlySourceLanguageSpeakers =0;
		int onlyDestinationLanguageSpeakers =0;
		//loops through the 2D array finding the languages that the flight attendants who only speak one language can speak
		for(unsigned int i = 0; i < oneLanguage6.size(); i++){
			if (spoken[0][oneLanguage6[i]] == Country::ENGLISH){
		    onlyEnglishSpeakers++;
			}
			if (spoken[1][oneLanguage6[i]] == destinationLanguage){
			onlyDestinationLanguageSpeakers++;
			}
			if (spoken[2][oneLanguage6[i]] == sourceLanguage){
		    onlySourceLanguageSpeakers++;
			}
		}
				 // for the case where more than one flight attendant can only speak one language, makes sure these languages are spoken no more than twice
				//by single language speaking flight attendants before returning true while also making sure flight attendants have'nt
				//already successfully been added to the flight
		if(onlyEnglishSpeakers <= 2 && onlyDestinationLanguageSpeakers <= 2 && onlySourceLanguageSpeakers <= 2 ){
			successfullFA = true;
			FlightAttendants = flightAttendants;
			return true;
			}
	}
	return false;
}
//returns pointer to the flight route
Route* Flight::getRoute() const {
    return route;
}
//returns pointer to the airplane used in the flight
Airplane* Flight::getAirplane() const {
   return airplane;
}
//returns a vector of pointers of the assigned pilots to the flight
vector<Pilot*> Flight::getPilots() const {

    return Pilots;
}
//returns a vector of pointers of the assigned flight attendants to the flight
vector<FlightAttendant *> Flight::getFlightAttendants() const {

	return FlightAttendants;
}

Flight::~Flight() {
}
