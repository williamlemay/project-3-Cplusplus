//William Lemay Project 3 4/20/2022. File Purpose: implementation of all files, considered "main.cpp".
#include "linkList.h"
int main()
{
    int choice,temp,month,day,year,hour,minute;
    string name,serviceRequired;
    linkList constructor;

    while(true)
    {   cout<<endl;
        cout<<"Enter 1-5:\n";
        cout<<"1) New customer arrival \n2) Serve Customer\n3) Customer left - remove from waiting list\n4) List all customers waiting for service\n5) Quit"<<endl;
        cin>>choice;

        switch(choice)
        {
            //Allows user to enter a new customer's arrival into the list
            case 1:
                cout<<"Enter name:\n";
                cin>>name;
                cout<<"Enter date as day,month,year (XX XX XXXX spaces between each): \n";
                cin>>day>>month>>year;
                cout<<"Enter time as hour and minute (XX XX space between): \n";
                cin>>hour>>minute;
                cout<<"Reason for visit (ONE word): \n";
                cin>>serviceRequired;
                constructor.insertNode(name,serviceRequired,day,month,year,hour,minute);
                break;
            //Uses serveCustomer to remove customer from list and points to the next customer.
            case 2:
                constructor.serveCustomer();
                break;
            //Deletes a customer from the list. If the customers name does not exist, displays "Not in line".
            case 3:
                cout<<"Enter the name of customer:\n";
                cin>>name;
                temp=constructor.deleteNode(name);
                (temp==1)?cout<<"Not in line."<< endl:cout<<"Deleted."<<endl;
                break;
            //Lists ALL customers currently in line.
            case 4:
                cout<<"SEQUENCE     NAME        ARRIVAL DATE/TIME       PURPOSE OF VISIT"<<endl;
                constructor.listAll(constructor.head);
                break;
            //Ends program.
            case 5:
                return 0;
        }
    }
}