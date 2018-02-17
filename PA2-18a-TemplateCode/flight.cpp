/*
  Margaret von Ebers, Jack Friedberg, Reuben Tadpatri
  CSCE 221-505
  Programming Assignment 2
  flight.cpp
*/

#include "flight.h"

Flight::Flight(): 
flightNum("AA000"), destination("College Station"), departureTime("00:00"), gateNum("A0")
{}

Flight::Flight(std::string fn, std::string dest, std::string dt, std::string gn):
flightNum(fn), destination(dest), departureTime(dt), gateNum(gn)
{}

Flight::~Flight()
{}

bool compareToDestination(Flight f1, Flight f2)
{
  return (f1.destination >= f2.destination);
}

bool compareToDepartureTime(Flight f1, Flight f2)
{
  return (f1.departureTime >= f2.departureTime);
}
