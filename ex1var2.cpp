#include <iostream>
#include <sstream>
#include <vector>
#include "lablist.h"

using namespace std;

#define MAX_SEATS 5

class FlightBookingSystem
{
private:

    int maxflights, NrOfPassengers;
    vector <LinkedList <string> *> flights;

public:

    FlightBookingSystem (int NrOfFlights)
    {
        maxflights=NrOfFlights;
        if(maxflights!=0)
        {
            LinkedList <string> *newList=new LinkedList <string>();
            for(int j=0; j<MAX_SEATS; j++)
                newList->addLast("");
            flights.push_back(newList);
        }
        else
            cout << "There are no planes.", exit(0);
    }

    void AddNewFlight()
    {
        LinkedList <string> *newList=new LinkedList <string>();
        for(int j=0; j<MAX_SEATS; j++)
            newList->addLast("");
        flights.push_back(newList);
    }

    void bookSeat (string passengerName)
    {
        Node <string> *current=flights[flights.size()-1]->pfirst;
        int cnt=0;
        while(current && current->info!="")
        {
            cnt++;
            current=current->next;
        }
        if(flights.size()==maxflights && cnt==MAX_SEATS)
            cout << "All flights are fully booked. Cannot book seat for " << passengerName << endl;
        else if(cnt==5)
        {
            AddNewFlight();
            Node <string> *add=flights[flights.size()-1]->pfirst;
            add->info=passengerName;
            NrOfPassengers++;
        }
        else
        {
            current->info=passengerName;
            NrOfPassengers++;
        }
    }

    void cancelBooking(int seatIndex)
    {
        if(seatIndex<0 || seatIndex>NrOfPassengers-1)
        {
            cout << "Invalid seat index.";
            return;
        }
        else
        {
            int flight=seatIndex/MAX_SEATS, seat=seatIndex%MAX_SEATS, cnt=0;
            Node <string> *current=flights[flight]->pfirst;
            while(current && cnt!=seat)
            {
                cnt++;
                current=current->next;
            }
            Node <string> *aux=current;
            if(flight==flights.size()-1)
            {
                while(current && current->next)
                {
                    current=current->next;
                    aux->info=current->info;
                    aux=aux->next;
                }
                current->info="";
            }
            else
            {
                while(flight<flights.size()-1)
                {
                    while(current && current->next)
                    {
                        current=current->next;
                        aux->info=current->info;
                        aux=aux->next;
                    }
                    flight++;
                    current=flights[flight]->pfirst;
                    aux->info=current->info;
                    aux=current;
                }
                while(current && current->next)
                {
                    current=current->next;
                    aux->info=current->info;
                    aux=aux->next;
                }
                current->info="";
            }

            NrOfPassengers--;
        }
    }

    void displaySystem()
    {
        for(int i=0; i<flights.size(); i++, cout << endl)
        {
            Node <string> *current=flights[i]->pfirst;
            while(current)
            {
                cout << current->info <<" ";
                current=current->next;
            }
        }
    }

    string getPassenger(int seatIndex)
    {
        if(seatIndex<0 || seatIndex>NrOfPassengers-1)
            return "Invalid seat index.";
        else
        {
            int flight=seatIndex/MAX_SEATS, seat=seatIndex%MAX_SEATS, cnt=0;
            Node <string> *current=flights[flight]->pfirst;
            while(current && cnt!=seat)
            {
                cnt++;
                current=current->next;
            }
            return current->info;
        }
    }

};

// int main()
// {
//     int NrOfFlights;
//     cin >> NrOfFlights;
//     FlightBookingSystem system(NrOfFlights);
//     system.bookSeat("A");
//     system.bookSeat("B");
//     system.bookSeat("C");
//     system.bookSeat("D");
//     system.bookSeat("E");
//     system.bookSeat("F");
//     system.bookSeat("G");
//     system.bookSeat("H");
//     system.bookSeat("I");
//     system.bookSeat("J");
//     system.bookSeat("K");
//     system.bookSeat("L");
//     system.bookSeat("M");
//     system.bookSeat("N");
//     system.bookSeat("O");
//     system.bookSeat("P");
//     system.bookSeat("Q");
//     system.bookSeat("R");
//     system.bookSeat("S");
//     system.bookSeat("T");


//     system.displaySystem();
//     system.cancelBooking(12);
//     system.displaySystem();
//     system.bookSeat("U");
//     system.displaySystem();


//     /*system.displaySystem();
//     cout << system.getPassenger(5) << endl;
//     system.cancelBooking(13);
//     system.displaySystem();
//     cout << system.getPassenger(11) << endl;
//     system.bookSeat("P");
//     system.bookSeat("Q");
//     cout << system.getPassenger(14) << endl;
//     system.displaySystem();
//     system.cancelBooking(15);
//     cout << system.getPassenger(15) << endl;
//     system.displaySystem();
//     system.bookSeat("ana");
//     system.displaySystem();
//     return 0;*/
// }

int main()
{
    int NrOfFlights, seatIndex;
    string optionStr, passengerName;

    cin >> NrOfFlights;

    FlightBookingSystem zboara(NrOfFlights);

    while (true)
    {
        cout << "1. Book a seat\n";
        cout << "2. Cancel booking\n";
        cout << "3. Display system\n";
        cout << "4. Display passenger\n";
        cout << "5. Exit\n";
        cout << "Option: ";

        getline(cin, optionStr);

        stringstream ss(optionStr);
        int actualOption;
        if (ss >> actualOption)
        {
            switch (actualOption)
            {
            case 1:
                cout << "Passenger name: ";
                getline(cin, passengerName);
                zboara.bookSeat(passengerName);
                break;
            case 2:
                cout << "Seat index: ";
                cin >> seatIndex;
                // cin.ignore();
                if (cin.fail())
                {
                    cout << "Invalid input\n\n";
                    cin.clear();
                    cin.ignore();
                    break;
                }
                cin.ignore();
                cin.clear();
                zboara.cancelBooking(seatIndex);
                break;
            case 3:
                zboara.displaySystem();
                break;
            case 4:
                cout << "Passenger on seat ";
                cin >> seatIndex;
                cout << " is " << zboara.getPassenger(seatIndex) << "\n";
                break;
            case 5:
               return 0;
            default:
                cout << "Invalid option\n\n";
                return 0;
            }
        }
        else
        {
            cout << "Invalid input\n\n";
            cin.ignore();
        }
    }

    return 0;
}