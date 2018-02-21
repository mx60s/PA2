/*
Maggie von Ebers, Jack Friedberg, Reuben Tadpatri
CSCE 221-505
Programming Assignment 2
sort.cpp
*/

#include "sort.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>

//use this to keep track of comparisons
int num_cmps;
std::vector<Flight> selection_sort(std::vector<Flight> flights,
	SortOption sortOpt)
{
	if (sortOpt == ByDepartureTime) {
		for (int k = 0; k < flights.size() - 1; k++) {
			int min = k;
			Flight tracker = flights.at(k);
			for (int i = k + 1; i < flights.size(); i++) {
				num_cmps++;
				if (!compareToDepartureTime(flights.at(i), flights.at(min))) {
					num_cmps++;
					min = i;
				}
			}
			if (compareToDepartureTime(flights.at(k), flights.at(min))) {
				num_cmps++;
				flights.at(k) = flights.at(min);
				flights.at(min) = tracker;
			}
		}
	}
	else if (sortOpt == ByDestination) {
		for (int k = 0; k < flights.size() - 1; k++) {
			int min = k;
			Flight tracker = flights.at(k);
			for (int i = k + 1; i < flights.size(); i++) {
				num_cmps++;
				if (!compareToDestination(flights.at(i), flights.at(min))) {
					num_cmps++;
					min = i;
				}
			}
			if (compareToDestination(flights.at(k), flights.at(min))) {
				num_cmps++;
				flights.at(k) = flights.at(min);
				flights.at(min) = tracker;
			}
		}
	}

	std::cout << "Number of comparisons used: " << num_cmps << std::endl;
	return flights;

}

std::vector<Flight> insertion_sort(std::vector<Flight> flights, SortOption sortOpt) {

	if (sortOpt == ByDestination) {
		for (int i = 0; i < flights.size(); i++) {
			Flight tracker = flights.at(i);
			int j = i - 1;
			while (j >= 0 && compareToDestination(flights.at(j), tracker)) {
				num_cmps++;
				flights.at(j + 1) = flights.at(j);
				j = j - 1;
			}
			flights.at(j + 1) = tracker;
		}
	}
	else if (sortOpt = ByDepartureTime) {
		for (int i = 0; i < flights.size(); i++) {
			Flight tracker = flights.at(i);
			int j = i - 1;
			while (j >= 0 && compareToDepartureTime(flights.at(j), tracker)) {
				num_cmps++;
				flights.at(j + 1) = flights.at(j);
				j = j - 1;
			}
			flights.at(j + 1) = tracker;
		}
	}
	std::cout << "Number of comparisons used: " << num_cmps << std::endl;
	return flights;
}

std::vector<Flight> bubble_sort(std::vector<Flight> flights,
	SortOption sortOpt)
{
	num_cmps = 0;
	bool swaps = true;
	Flight temp;
	if (sortOpt == ByDestination) {
		while (swaps) {
			swaps = false;
			for (int j = 1; j < flights.size(); j++) { //inner loop, don't do i+1 to go out of bounds
				num_cmps++;
				if (compareToDestination(flights.at(j - 1), flights.at(j))) {
					//std::cout << j << " Swap " << flights.at(j-1).destination << " and " << flights.at(j).destination << std::endl;
					num_cmps++;
					swaps = true;
					temp = flights.at(j - 1);
					flights.at(j - 1) = flights.at(j);
					flights.at(j) = temp;
				}
				//std::cout << flights.at(j-1).destination << std::endl;
			} //end inner loop
		} //end outer loop
	}

	else if (sortOpt == ByDepartureTime) {
		while (swaps) {
			swaps = false;
			for (int j = 0; j < flights.size() - 1; j++) { //inner loop, don't do i+1 to go out of bounds
				num_cmps++;
				if (compareToDepartureTime(flights.at(j), flights.at(j + 1))) {
					//std::cout << j << " swap " << flights.at(j).departureTime << " and " << flights.at(j+1).departureTime << std::endl;
					num_cmps++;
					swaps = true;
					temp = flights.at(j);
					flights.at(j) = flights.at(j + 1);
					flights.at(j + 1) = temp;
				}
			} //end inner loop
		} //end outer loop
	}
	//flights.erase (flights.begin()+0);
	std::cout << "Number of comparisons used: " << num_cmps << std::endl;
	return flights;
}
