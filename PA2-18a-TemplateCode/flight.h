/*
  Maggie von Ebers, Jack Friedberg, Reuben Tadpatri
  CSCE 221-505
  Programming Assignment 2
  flight.h
*/

#pragma once
#include <string>

struct Flight 
{
  std::string flightNum;
  std::string destination;
  std::string departureTime;
  std::string gateNum;

  Flight();
  Flight(std::string fn, std::string dest, std::string dt, std::string gn);
  ~Flight();
  //...
};

//compare this Flight object against another Flight object
//returns true if this object is >= other
bool compareToDestination(Flight f1, Flight f2);
bool compareToDepartureTime(Flight f1, Flight f2);
