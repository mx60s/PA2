/*
	Maggie von Ebers, Jack Friedberg, Reuben Tadpatri
	CSCE 221-505
	Programming Assignment 2
	PA2.cpp
*/


#include <sstream>
#include <iostream>
#include <fstream>

#include "sort.h"

std::vector<Flight> readFlights(std::string fileName);
void printFlights(std::vector<Flight> flights);

int main()
{
  /*
    first read flights in files using readFlights()
    descen10.csv	ascen10.csv     rand10.csv
    descen100.csv	ascen100.csv	rand100.csv
    descen1000.csv	ascen1000.csv	rand1000.csv
    descen10000.csv ascen10000.csv	rand10000.csv
  */

  std::ifstream in("descen10.csv");
  std::string file;
  std::string temp;
  //while(in.get(temp)){
    //file += temp;
    //std::cout << file;
  //}

  //std::cout << file << std::endl;

  //std::vector<Flight> flights = readFlights(file);
  //std::cout << flights.at(0).destination << std::endl;
  //printFlights(flights);

  /*
    then use each of the sorting functions on each of the generated vectors
  */

  /*
    then output each of the resultant sorted vectors
    format them so that they look like the table of the front of the 
    instructions

    Flight Number	Destination Departure   Time	        Gate Number
    AA223			LAS VEGAS	21:15			A3
    BA023			DALLAS		21:00			A3
    AA220			LONDON		20:30			B4
    VI303			MEXICO		19:00			A7
    BA087			LONDON		17:45			A7
    AA342			PARIS		16:00			A7
    VI309			PRAGUE		13:20			F2
    QU607			TORONTO		08:30			F2
    AA224			SYDNEY		08:20			A7
    AF342			WASHINGTON	07:45			A3
  */

  /*
    then fill out the rest of the questions on the instructions 
    - the number of comparisons

    - to test your functions experimentally use difftime explained here 
    http://www.cplusplus.com/reference/ctime/time/
  */

  return 0;
}

//read in the flights from the input file at fileName and store them in a vector
std::vector<Flight> readFlights(std::string fileName){
  std::vector<Flight> flights;
  fileName.erase(0,fileName.find('\n'));
  while(!fileName.empty()){
    Flight temp;
    temp.flightNum = fileName.substr(0,fileName.find(',')-1);
    fileName.erase(0,fileName.find(','));
    temp.destination = fileName.substr(0,fileName.find(',')-1);
    fileName.erase(0,fileName.find(','));
    temp.departureTime = fileName.substr(0,fileName.find(',')-1);
    fileName.erase(0,fileName.find(','));
    temp.gateNum = fileName.substr(0,1);
    fileName.erase(0,1);
    flights.push_back(temp);
  }
  return flights;
}

void printFlights(std::vector<Flight> flights){
  for(int i = 0; i < flights.size(); i++){
    printf("%s%5s%5s%5s\n", flights.at(i).flightNum.c_str(), 
                            flights.at(i).destination.c_str(), 
                            flights.at(i).departureTime.c_str(),
                            flights.at(i).gateNum.c_str());
  }
};