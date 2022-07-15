//William Lemay Project 3 4/20/2022. File Purpose: definition of class linkList.
#include "customer.h"
#include <string>
#include <iostream>
class linkList{
public:
    int counter;
    customer* head;
    customer* deleted;
    customer* start=head;
    customer* last;

    linkList();

    ~linkList();

    //Inserts new node into list. Node includes Customer name, date arrived, reason for visit, and time arrived
    void insertNode(string name, string serviceRequired,int day,int month,int year,int hour,int minute);
    //Deletes a node based on customer name.
    int deleteNode(string name);
    //"Serves" the customer and removes them from the list and moves to the next customer in the list.
    customer* serveCustomer();
    //Lists all customers who have not been served or deleted.
    void listAll(customer*);
};