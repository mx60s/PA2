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
int num_cmps = 0;

std::vector<Flight> selection_sort(std::vector<Flight> flights,

				   SortOption sortOpt)

{
	if (sortOpt == ByDepartureTime) {
		for (int k = 0; k < flights.size() - 1; k++) {
			int index = k;
			Flight tracker = flights.at(k);
			for (int i = k + 1; i < flights.size(); i++) {
				if (compareToDepartureTime(flights.at(i), flights.at(index))) {
					index = i;
				}
			}
			if (compareToDepartureTime(tracker, flights.at(k))) {
				flights.at(k) = flights.at(index);
				flights.at(index) = tracker;
			}
		}
	}
	else if (sortOpt == ByDestination) {
		for (int k = 0; k < flights.size() - 1; k++) {
			int index = k;
			Flight tracker = flights.at(k);
			for (int i = k + 1; i < flights.size(); i++) {
				if (compareToDestination(flights.at(i), flights.at(index))) {
					index = i;
				}
			}
			if (compareToDestination(tracker, flights.at(k))) {
				flights.at(k) = flights.at(index);
				flights.at(index) = tracker;
			}
		}
	}
	return flights;
}

std::vector<Flight> insertion_sort(std::vector<Flight> flights, SortOption sortOpt) {

  num_cmps = 0;
  if (sortOpt == ByDestination) {
    for (int i = 0; i < flights.size(); i++) {
        num_cmps++;
        Flight tracker = flights.at(i);
        int j = i-1;
        while (j>= 0 && compareToDestination(flights.at(j), tracker)) {
            num_cmps++;
            flights.at(j+1) = flights.at(j);
            j = j - 1;
        }
        flights.at(j+1) = tracker;
    }
  }
  else if (sortOpt == ByDepartureTime) {
    for (int i = 0; i < flights.size(); i++) {
        num_cmps++;
        Flight tracker = flights.at(i);
        int j = i-1;
        while (j>= 0 && compareToDepartureTime(flights.at(j), tracker)) {
            num_cmps++;
            flights.at(j+1) = flights.at(j);
            j = j - 1;
        }
        flights.at(j+1) = tracker;
    }
  }
  flights.erase (flights.begin()+0);
  std::cout << "Number of comparisons used: " << num_cmps << std::endl;
  return flights;
}

std::vector<Flight> bubble_sort(std::vector<Flight> flights,
				SortOption sortOpt)
{
  num_cmps = 0;
  bool swaps = true;
  Flight temp;
    if(sortOpt == ByDestination){
      while(swaps){
        num_cmps++;
        swaps = false;
        for(int j = 1; j < flights.size();j++){ //inner loop, don't do i+1 to go out of bounds
          num_cmps++;
          if(compareToDestination(flights.at(j-1),flights.at(j))){
            num_cmps++;
            swaps = true;
            temp = flights.at(j-1);
            flights.at(j-1) = flights.at(j);
            flights.at(j) = temp;
          }
        } //end inner loop
      } //end outer loop
    }

    else if(sortOpt == ByDepartureTime){
      while(swaps){
        num_cmps++;
        swaps = false;
        for(int j = 1; j < flights.size();j++){ //inner loop, don't do i+1 to go out of bounds
          num_cmps++;
          std::cout << j << std::endl;
          if(compareToDepartureTime(flights.at(j-1),flights.at(j))){
            std::cout << "swapped" << std::endl;
            num_cmps++;
            swaps = true;
            temp = flights.at(j-1);
            flights.at(j-1) = flights.at(j);
            flights.at(j) = temp;
          }
        } //end inner loop
      } //end outer loop
    }
    flights.erase (flights.begin()+0);
    std::cout << "Number of comparisons used: " << num_cmps << std::endl;
    return flights;
}
/*

Maggie von Ebers, Jack Friedberg, Reuben Tadpatri

CSCE 221-505

Programming Assignment 2

sort.cpp

*/



#include "sort.h"





//use this to keep track of comparisons

int num_cmps;



std::vector<Flight> selection_sort(std::vector<Flight> flights,

				   SortOption sortOpt)

{

	if (sortOpt == ByDepartureTime) {
		for (int k = 0; k < flights.size() - 1; k++) {
			int index = k;
			Flight tracker = flights.at(k);
			for (int i = k + 1; i < flights.size(); i++) {
				if (compareToDepartureTime(flights.at(i), flights.at(index))) {
					index = i;
				}
			}
			if (compareToDepartureTime(tracker, flights.at(k))) {
				flights.at(k) = flights.at(index);
				flights.at(index) = tracker;
			}
		}
	}



	else if (sortOpt == ByDestination) {
		for (int k = 0; k < flights.size() - 1; k++) {
			int index = k;
			Flight tracker = flights.at(k);
			for (int i = k + 1; i < flights.size(); i++) {
				if (compareToDestination(flights.at(i), flights.at(index))) {
					index = i;
				}
			}
			if (compareToDestination(tracker, flights.at(k))) {
				flights.at(k) = flights.at(index);
				flights.at(index) = tracker;
			}
		}
	}

	return flights;

}



std::vector<Flight> insertion_sort(std::vector<Flight> flights, SortOption sortOpt) {



  if (sortOpt == ByDestination) {

    for (int i = 0; i < flights.size(); i++) {

        Flight tracker = flights.at(i);

        int j = i-1;

        while (j>= 0 && compareToDestination(flights.at(j), tracker)) {

            flights.at(j+1) = flights.at(j);

            j = j - 1;

        }

        flights.at(j+1) = tracker;

    }

  }

  else if (sortOpt = ByDepartureTime) {

    for (int i = 0; i < flights.size(); i++) {

        Flight tracker = flights.at(i);

        int j = i-1;

        while (j>= 0 && compareToDepartureTime(flights.at(j), tracker)) {

            flights.at(j+1) = flights.at(j);

            j = j - 1;

        }

        flights.at(j+1) = tracker;

    }

  }

  return flights;

}



std::vector<Flight> bubble_sort(std::vector<Flight> flights,

				SortOption sortOpt)

{

  int swaps = 1;

  Flight temp;

    if(sortOpt == ByDestination){

      while(swaps != 0){

        for(int j = 0; j < flights.size();j++){ //inner loop, don't do i+1 to go out of bounds

          swaps = 0;

          if(compareToDestination(flights.at(j),flights.at(j+1))){ //swap

            swaps++;

            temp = flights.at(j);

            flights.at(j) = flights.at(j+1);

            flights.at(j+1) = temp;

          }

        } //end inner loop

      } //end outer loop

    }



    if(sortOpt == ByDepartureTime){

      while(swaps != 0){

        for(int j = 0; j < flights.size();j++){ //inner loop, don't do i+1 to go out of bounds

          swaps = 0;

          if(compareToDepartureTime(flights.at(j),flights.at(j+1))){ //swap

            swaps++;

            temp = flights.at(j);

            flights.at(j) = flights.at(j+1);

            flights.at(j+1) = temp;

          }

        } //end inner loop

      } //end outer loop

    }

    return flights;

}

