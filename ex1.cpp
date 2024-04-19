#include <iostream>
#include "lablist.h"

using namespace std;

class FlightBookingSystem {
    public:
        LinkedList<string> *flights;
        int maxSeats = 5;
        int currentSeats = 0;
        int currentFlight = 0;
        int currentSeat = 0;

        void bookSeat(string passengerName) {
            // if (currentSeats == 0) {
            //     flights->addFirst(passengerName);
            //     currentSeats++;
            // } else if (currentSeats == maxSeats) {
            //     flights->addLast(passengerName);
            //     currentSeats = 1;
            //     currentFlight++;
            // } else {
            //     flights->addLast(passengerName);
            //     currentSeats++;
            // }

            // if (currentFlight == 0) {
            //     currentFlight++;
            // }

            if (currentSeats == maxSeats) {
                flights->addLast(passengerName);
                currentSeats = 1;
                currentFlight++;
            } else {
                flights->addLast(passengerName);
                currentSeats++;
            }

        }

        void cancelBooking(int seatIndex) {
            Node<string> *p = flights->pfirst;
            Node<string> *prev = NULL;
            int i = 0;
            while (p != NULL) {
                if (i == seatIndex) {
                    if (prev == NULL) {
                        flights->pfirst = p->next;
                    } else {
                        prev->next = p->next;
                    }
                    delete p;
                    currentSeats--;
                    return;
                }
                prev = p;
                p = p->next;
                i++;
            }
        }


        void displaySystem() {
            Node<string> *p = flights->pfirst;
            while (p != NULL) {
                cout << p->info << endl;
                p = p->next;
            }
        }

        string getPassenger(int seatIndex) {
            Node<string> *p = flights->pfirst;
            int i = 0;
            while (p != NULL) {
                if (i == seatIndex) {
                    return p->info;
                }
                p = p->next;
                i++;
            }
            return "";
        }

        FlightBookingSystem() {
            flights = new LinkedList<string>();
        }

        ~FlightBookingSystem() {
            delete flights;
        }

};

int main() 
{
    FlightBookingSystem *zboara = new FlightBookingSystem();
    // zboara->bookSeat("Sergiu");
    // zboara->bookSeat("Ana");
    // zboara->displaySystem();
    // cout << zboara->getPassenger(0) << endl;
    // zboara->cancelBooking(0);
    // zboara->displaySystem();
    // delete zboara;

    // test the flight booking system with data from the keyboard

    int option;
    string passengerName;
    int seatIndex;

    while (true) {
        cout << "1. Book a seat" << endl;
        cout << "2. Cancel booking" << endl;
        cout << "3. Display system" << endl;
        cout << "4. Exit" << endl;
        cout << "Option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Passenger name: ";
                cin >> passengerName;
                zboara->bookSeat(passengerName);
                break;
            case 2:
                cout << "Seat index: ";
                cin >> seatIndex;
                zboara->cancelBooking(seatIndex);
                break;
            case 3:
                zboara->displaySystem();
                break;
            case 4:
                delete zboara;
                return 0;
            default:
                cout << "Invalid option" << endl;
        }
    }

    
    return 0;
}


