//William Lemay Project 3 4/20/2022. File Purpose: implementation of class linkList.
#include "linkList.h"

linkList::linkList()
{
    deleted = NULL;
    counter = NULL;
    head=last=NULL;
}

linkList::~linkList()
{
    customer* start;
    customer* temp;
    start=temp;
    while(start!=NULL)
    {
        temp=start;
        start=start->next;
        free(temp);
    }
}

//Used in deleteNode. Searches for the customers name.
customer* searchNode(string name,customer* start)
{
    if(start==NULL)
        return NULL;
    else
    {
        if(name.compare(start->name)==0)
        {
            return start;
        }
        else
        {
            return    searchNode(name,start->next);
        }
    }
}
//definition of what is happening in insert node. increments counter by 1 no matter what
void linkList::insertNode(string name, string serviceRequired, int day, int month, int year, int hour, int minute){
    class customer *node=NULL;

    node = new customer();
    node->name=name;
    node->serviceRequired=serviceRequired;
    node->day=day;
    node->month=month;
    node->year=year;
    node->hour=hour;
    node->minute=minute;
    node->sequenceNumber=counter;

//if no entries on the list then everything equals the same and current node points to next.
    if(head==NULL && last==NULL)
    {
        head=last=node;
        node->next=NULL;
    }
//if one item exists, current node points to next and current node is given value of head.
    else
    {
        node->next=head;
        head=node;
    }
    counter++;
}
//if entry is on the list (program tells through counter variable), set first entry to NULL and reset head and last to be accurate
customer* linkList::serveCustomer(){
    if (counter >= 1){
        if(counter <= 1){
            head = NULL;
            last = NULL;
            cout<<"Customer served."<<endl;
            counter = counter-1;
        }
        else{
            start=head;
            while(start->next != last)
            {
                start=start->next;
            }
            free(start->next);
            start->next = NULL;
            cout<<"Customer served."<<endl;
            counter = counter-1;
        }
    }
    else{
        cout<<"No customer to be served."<<endl;
        return (0);
    }
    return 0;
}
//removes list entry based on name. if name returns no results, does nothing.
int linkList::deleteNode(string name){
    deleted=searchNode(name,head);

    if(deleted==NULL)
    {
        return 1;
    }
    else
    {
        if(deleted!=head)
        {
            counter = counter-1;
            while(start->next!=deleted)
            {
                start=start->next;
            }

            start->next=deleted->next;
            free(deleted);
        }
        else
        {
            counter = counter-1;
            head=deleted->next;
            free(deleted);
        }
    }
    return 0;
}
//lists all data held within linked list
void linkList::listAll(customer *start)
{
    if(start==NULL)
        return ;
    linkList::listAll(start->next);
    cout<<start->sequenceNumber+1<<"            "<<start->name<<"     "<<start->day<<"/"<<start->month<<"/"<<start->year<<" "<<start->hour<<":"<<start->minute<<"       "<<start->serviceRequired<<endl;
}