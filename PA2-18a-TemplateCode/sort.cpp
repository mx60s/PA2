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
