//William Lemay Project 3 4/20/2022. File Purpose: holds customer class which holds customer information.
#include <string>
#include <iostream>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H
class customer
{
public:
    unsigned int sequenceNumber;
    int month;
    int day;
    int year;
    int hour;
    int minute;
    string name;
    string serviceRequired;
    customer* next;
};
#endif