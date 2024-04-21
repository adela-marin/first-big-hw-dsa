#include <iostream>
#include <sstream>
#include "lablist.h"

using namespace std;

#define MAX_SEATS 5

class FlightBookingSystem {
public:
    LinkedList<string> *flights;
    int maxSeats = MAX_SEATS;
    int currentSeats = 0;
    int currentFlight = 0;
    int currentSeat = 0;

    void bookSeat(string passengerName) {
        if (currentSeats == maxSeats) {
            cout << "All seats are booked for this flight." << endl;
            return;
        }

        if (currentSeats == 0) {
            flights->addLast(passengerName);
            currentSeats = 1;
            currentFlight++;
        } else {
            flights->addLast(passengerName);
            currentSeats++;
        }
    }

    void cancelBooking(int seatIndex) {
        if (currentFlight == 0 || seatIndex >= currentSeats * currentFlight) {
            cout << "Invalid seat index." << endl << endl;
            return;
        }

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
                Node<string> *q = flights->pfirst;
                int remainingBookings = 0;
                while (q != NULL) {
                    q = q->next;
                    remainingBookings++;
                }
                currentFlight = (remainingBookings + maxSeats - 1) / maxSeats;
                if (remainingBookings == 0) {
                    currentFlight = 0;
                }
                return;
            }
            prev = p;
            p = p->next;
            i++;
        }
    }

    void displaySystem() {
        if (currentFlight == 0) {
            cout << "No bookings.\n" << endl << endl;
            return;
        }

        Node<string> *p = flights->pfirst;
        while (p != NULL) {
            cout << p->info << endl;
            p = p->next;
        }
        cout << endl;
    }

    string getPassenger(int seatIndex) {
        if (currentFlight == 0 || seatIndex >= currentSeats * currentFlight) {
            return "Invalid seat index.\n";
        }

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

int main() {
    FlightBookingSystem *zboara = new FlightBookingSystem();

    string optionStr;
    string passengerName;
    int seatIndex;

    while (true) {
        cout << "1. Book a seat\n";
        cout << "2. Cancel booking\n";
        cout << "3. Display system\n";
        cout << "4. Exit\n";
        cout << "Option: ";

        getline(cin, optionStr);

        stringstream ss(optionStr);
        int actualOption;
        if (ss >> actualOption) {
            switch (actualOption) {
            case 1:
                cout << "Passenger name: ";
                getline(cin, passengerName);
                zboara->bookSeat(passengerName);
                break;
            case 2:
                cout << "Seat index: ";
                cin >> seatIndex;
                // cin.ignore();
                if (cin.fail()) {
                    cout << "Invalid input\n\n";
                    cin.clear();
                    cin.ignore();
                    break;
                }
                cin.ignore();
                cin.clear();
                zboara->cancelBooking(seatIndex);
                break;
            case 3:
                zboara->displaySystem();
                break;
            case 4:
                delete zboara;
                return 0;
            default:
                cout << "Invalid option\n\n";
                return 0;
            }
        } else {
            cout << "Invalid input\n\n";
            cin.ignore();
        }
    }

    return 0;
}
