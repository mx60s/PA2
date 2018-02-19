/*
	Maggie von Ebers, Jack Friedberg, Reuben Tadpatri
	CSCE 221-505
	Programming Assignment 2
	PA2.cpp
*/


#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>

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

  // APPLYING SORTS
    // Insertion sort (working)
    std::string fileName = "rand10.csv";
    std::vector<Flight> flights  = readFlights(fileName);
    printFlights(flights);
    flights = insertion_sort(flights, ByDestination);
    std::cout << std::endl << "BY DESTINATION:" << std::endl << std::endl;
    printFlights(flights);
    flights = insertion_sort(flights, ByDepartureTime);
    std::cout << std::endl << "BY TIME:" << std::endl << std::endl;
    printFlights(flights);


  /*
    then fill out the rest of the questions on the instructions 
    - the number of comparisons

    - to test your functions experimentally use difftime explained here 
    http://www.cplusplus.com/reference/ctime/time/
  */
  return 0;
}

//read in flights from input file at fileName and store in a vector
std::vector<Flight> readFlights(std::string fileName){
  std::vector<Flight> flights;
  std::ifstream inFile(fileName.c_str());
  std::string dummy;  
  getline(inFile, dummy);
  while(!inFile.eof()) {
    Flight temp;
    std::string str;
    getline(inFile, str, ',');
    temp.flightNum = str;
    getline(inFile, str, ',');
    temp.destination = str;
    getline(inFile, str, ',');
    temp.departureTime = str;
    getline(inFile, str, '\n');
    temp.gateNum = str;
    flights.push_back(temp);
  }
  return flights;
}

void printFlights(std::vector<Flight> flights){
  //ONLY PRINT TO TERMINAL FOR 10 OR LESS FLIGHTS
  if (flights.size() < 12) {
    printf("%-15s %-20s %-15s %-s\n", 
      "Flight Number", 
      "Destination", 
      "Departure Time",
      "Gate Number");
    for(int i = 0; i < flights.size(); i++){
      printf("%-15s %-20s %-15s %-s\n", 
        flights.at(i).flightNum.c_str(), 
        flights.at(i).destination.c_str(), 
        flights.at(i).departureTime.c_str(),
        flights.at(i).gateNum.c_str());
    }
  }
  //Printing to file
  FILE * outFile;
  outFile = fopen("Sorted.txt", "w");
  fprintf(outFile, "%-15s %-20s %-15s %-s\n", 
    "Flight Number", 
    "Destination", 
    "Departure Time",
    "Gate Number");
  for(int i = 0; i < flights.size(); i++){
    fprintf(outFile, "%-15s %-20s %-15s %-s\n", 
      flights.at(i).flightNum.c_str(), 
      flights.at(i).destination.c_str(), 
      flights.at(i).departureTime.c_str(),
      flights.at(i).gateNum.c_str());
  }
  fclose(outFile);
  return;
};