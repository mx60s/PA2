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
using namespace std;
vector<Flight> readFlights(string fileName);
void printFlights(vector<Flight> flights);

int main()
{
<<<<<<< HEAD
	/*
	first read flights in files using readFlights()
	descen10.csv	ascen10.csv     rand10.csv
	descen100.csv	ascen100.csv	rand100.csv
	descen1000.csv	ascen1000.csv	rand1000.csv
	descen10000.csv ascen10000.csv	rand10000.csv
	*/

	// APPLYING SORTS
	// Insertion sort (working)
	string fileName = "rand10.csv";
	vector<Flight> flights = readFlights(fileName);
	printFlights(flights);
	flights = selection_sort(flights, ByDestination);
	cout << endl << "BY DESTINATION:" << endl << endl;
	printFlights(flights);
	flights = selection_sort(flights, ByDepartureTime);
	cout << endl << "BY TIME:" << endl << endl;
	printFlights(flights);
=======
  /*
    first read flights in files using readFlights()
    descen10.csv	ascen10.csv     rand10.csv
    descen100.csv	ascen100.csv	rand100.csv
    descen1000.csv	ascen1000.csv	rand1000.csv
    descen10000.csv ascen10000.csv	rand10000.csv
  */

  // APPLYING SORTS
    // Insertion sort (working)
    std::string fileName = "ascen10.csv";
    std::vector<Flight> flights  = readFlights(fileName);
    std::cout << std::endl << "Original:" << std::endl << std::endl;
    printFlights(flights);

    std::cout << std::endl;
    std::cout << "-------------------Insertion Sort---------------------" << std::endl;
    std::cout << std::endl << "BY DESTINATION:" << std::endl;
    flights = insertion_sort(flights, ByDestination);
    std::cout << std::endl;
    printFlights(flights);

    flights  = readFlights(fileName); // reset
        
    std::cout << std::endl << "BY TIME:" << std::endl;
    flights = insertion_sort(flights, ByDepartureTime);
    std::cout << std::endl;
    printFlights(flights);
>>>>>>> 719b598e52672f8051d876b7af735fb62e8efedb

    // Bubble sort (working)
    std::cout << std::endl;
    std::cout << "---------------------Bubble Sort-----------------------" << std::endl;
    std::cout << std::endl << "BY DESTINATION:" << std::endl;
    flights = bubble_sort(flights, ByDestination);
    std::cout << std::endl;
    printFlights(flights);

    flights  = readFlights(fileName); // reset
        
    std::cout << std::endl << "BY TIME:" << std::endl;
    flights = bubble_sort(flights, ByDepartureTime);
    std::cout << std::endl;
    printFlights(flights);

    //Selection sort
    std::cout << std::endl;
    std::cout << "--------------------Selection Sort----------------------" << std::endl;
    std::cout << std::endl << "BY DESTINATION:" << std::endl;
    flights = selection_sort(flights, ByDestination);
    std::cout << std::endl;
    printFlights(flights);

    flights  = readFlights(fileName); //reset
        
    std::cout << std::endl << "BY TIME:" << std::endl;
    flights = selection_sort(flights, ByDepartureTime);
    std::cout << std::endl;
    printFlights(flights);

<<<<<<< HEAD
	/*
	then fill out the rest of the questions on the instructions
	- the number of comparisons

	- to test your functions experimentally use difftime explained here
	http://www.cplusplus.com/reference/ctime/time/
	*/
	return 0;
=======
  /*
    then fill out the rest of the questions on the instructions 
    - the number of comparisons
    - to test your functions experimentally use difftime explained here 
    http://www.cplusplus.com/reference/ctime/time/
  */



  return 0;
>>>>>>> 719b598e52672f8051d876b7af735fb62e8efedb
}

//read in flights from input file at fileName and store in a vector
vector<Flight> readFlights(string fileName) {
	vector<Flight> flights;
	ifstream inFile(fileName);
	if (!inFile.is_open()) {
		cout << "Error opening file." << endl;
	}
	else {
		string dummy;
		getline(inFile, dummy);
		while (!inFile.eof()) {
			Flight temp;
			string str;
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
	}
	return flights;
}

<<<<<<< HEAD
void printFlights(vector<Flight> flights) {
	//ONLY PRINT TO TERMINAL FOR 10 OR LESS FLIGHTS
	if (flights.size() < 12) {
		printf("%-15s %-20s %-15s %-s\n",
			"Flight Number",
			"Destination",
			"Departure Time",
			"Gate Number");
		for (int i = 0; i < flights.size(); i++) {
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
	for (int i = 0; i < flights.size(); i++) {
		fprintf(outFile, "%-15s %-20s %-15s %-s\n",
			flights.at(i).flightNum.c_str(),
			flights.at(i).destination.c_str(),
			flights.at(i).departureTime.c_str(),
			flights.at(i).gateNum.c_str());
	}
	fclose(outFile);
	return;
=======
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
>>>>>>> 719b598e52672f8051d876b7af735fb62e8efedb
};