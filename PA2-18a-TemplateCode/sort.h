/*
Maggie von Ebers, Jack Friedberg, Reuben Tadpatri
CSCE 221-505
Programming Assignment 2
sort.h
*/

#pragma once
#include <vector>
#include <string>

#include "flight.h"

enum SortOption {
  ByDestination,
  ByDepartureTime
};

//implement each of these functions for their respective sort
std::vector<Flight> selection_sort(std::vector<Flight> flights,
				   SortOption sortOpt);

std::vector<Flight> insertion_sort(std::vector<Flight> flights,
				   SortOption sortOpt);

std::vector<Flight> bubble_sort(std::vector<Flight> flights,
				SortOption sortOpt);
