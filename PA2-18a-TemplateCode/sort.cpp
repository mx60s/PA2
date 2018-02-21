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
  num_cmps = 0;

  std::cout << "Number of comparisons used: " << std::endl;
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
