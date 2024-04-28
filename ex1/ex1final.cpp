#include <iostream>
#include <sstream>
#include <vector>
#include "lablist.h"

using namespace std;

#define MAX_FLIGHTS 5
#define MAX_SEATS 5

class FlightBookingSystem {
private:
    vector<LinkedList<string>*> flights;
    vector<int> passengersPerFlight;

public:
    FlightBookingSystem(int NrOfFlights) {
        if (NrOfFlights > MAX_FLIGHTS) {
            cout << "Maximum number of flights exceeded." << endl;
            return;
        }

        // initializare vectori
        flights.resize(NrOfFlights);
        passengersPerFlight.resize(NrOfFlights, 0);

        // initializare listele de pasageri pentru fiecare zbor
        for (int i = 0; i < NrOfFlights; i++) {
            LinkedList<string>* newList = new LinkedList<string>();
            for (int j = 0; j < MAX_SEATS; j++) {
                newList->addLast("");
            }
            flights[i] = newList;
        }
    }

    // rezervare loc
    void bookSeat(string passengerName) {
        int flightIndex = 0;
        while (flightIndex < flights.size()) {
            LinkedList<string>* currentFlight = flights[flightIndex];
            int availableSeats = MAX_SEATS - passengersPerFlight[flightIndex];
            if (availableSeats > 0) {
                // rezervare primul loc disponibil
                Node<string>* current = currentFlight->pfirst;
                while (current && current->info != "") {
                    current = current->next;
                }
                if (current) {
                    current->info = passengerName;
                    ++passengersPerFlight[flightIndex];
                    cout << "Seat booked in Flight " << (flightIndex + 1) << endl;
                    return;
                }
            }
            ++flightIndex;
        }
        cout << "All flights are fully booked." << endl;
    }

    // anulare rezervare
	void cancelBooking(int seatIndex) {
        if (seatIndex < 0 || seatIndex >= flights.size() * MAX_SEATS) {
            cout << "Invalid seat index." << endl;
            return;
        }

        int flightIndex = seatIndex / MAX_SEATS;
        int seatInFlight = seatIndex % MAX_SEATS;
        LinkedList<string>* currentFlight = flights[flightIndex];
        Node<string>* current = currentFlight->pfirst;
        Node<string>* prev = nullptr;

        // cautare loc
        for (int i = 0; i < seatInFlight; i++) {
            if (!current) {
                cout << "Invalid seat index." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        // anulare rezervare
        if (current && current->info != "") {
            current->info = "";
            // decrementare numar pasageri
            --passengersPerFlight[flightIndex];
            cout << "Booking canceled for seat " << seatIndex << endl;

            Node<string>* temp = current->next;
            while (temp) {
                current->info = temp->info;
                current = temp;
                temp = temp->next;
            }
            current->info = "";

            // mutare pasageri ca sa nu ramana locuri libere intre ei
            for (int i = flightIndex; i < flights.size() - 1; i++) {
                LinkedList<string>* nextFlight = flights[i + 1];

                if (passengersPerFlight[i + 1] > 0) {
                    current = nextFlight->pfirst;
                    while (current->info == "") {
                        current = current->next;
                    }
                    temp = currentFlight->pfirst;
                    while (temp->info != "") {
                        temp = temp->next;
                    }
                    temp->info = current->info;
                    current->info = "";
                    --passengersPerFlight[i + 1];
                    ++passengersPerFlight[i];
                }

                Node<string>* temp = current->next;

                while (temp) {
                    current->info = temp->info;
                    current = temp;
                    temp = temp->next;
                }
                current->info = "";
            }
        } else {
            cout << "No booking found for seat " << seatIndex << endl;
        }
    }

    // afisare status
    void displaySystem() {
        for (int i = 0; i < flights.size(); i++) {
            cout << "Flight " << (i + 1) << ": ";
            Node<string>* current = flights[i]->pfirst;

            while (current) {
                cout << (current->info.empty() ? "-" : current->info) << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    // afisare pasager de la pozitia data
    string getPassenger(int seatIndex) {
        int flightIndex = seatIndex / MAX_SEATS;

        if (flightIndex >= flights.size()) {
            return "Invalid seat index.";
        }

        LinkedList<string>* currentFlight = flights[flightIndex];
        int seatInFlight = seatIndex % MAX_SEATS;
        Node<string>* current = currentFlight->pfirst;

        for (int i = 0; i < seatInFlight; i++) {
            if (!current) {
                return "Invalid seat index.";
            }
            current = current->next;
        }

        return (current && current->info != "") ? current->info : "Not booked";
    }

};

int main() {
    int NrOfFlights;
    string optionStr, passengerName;
    FlightBookingSystem zboara(MAX_FLIGHTS);

    while (true) {
        cout << "1. Book a seat\n";
        cout << "2. Cancel booking\n";
        cout << "3. Display system\n";
        cout << "4. Display passenger\n";
        cout << "5. Exit\n";
        cout << "Option: ";

        getline(cin, optionStr);
        stringstream ss(optionStr);
        int actualOption;

        int seatIndex;
        string passenger = "";

        if (ss >> actualOption) {
            switch (actualOption) {
                case 1:
                    cout << "Passenger name: ";
                    getline(cin, passengerName);
                    zboara.bookSeat(passengerName);
                    break;
                case 2:
                    // int seatIndex;
                    cout << "Seat index: ";
                    cin >> seatIndex;
                    cin.ignore();
                    zboara.cancelBooking(seatIndex);
                    break;
                case 3:
                    zboara.displaySystem();
                    break;
                case 4:
                    // int seatIndex;
                    cout << "Seat index ";
                    cin >> seatIndex;
                    cin.ignore();
                    // string passenger = zboara.getPassenger(seatIndex);
                    passenger = zboara.getPassenger(seatIndex);
                    if (passenger == "Not booked") {
                        cout << "Seat " << seatIndex << " is not booked.\n";
                    } else if (passenger != "Invalid seat index.") {
                        cout << "Passenger on seat " << seatIndex << " is " << passenger << "\n";
                    } else {
                        cout << "Invalid seat index.\n";
                    }
                    // cout << " is " << zboara.getPassenger(seatIndex) << "\n";
                    break;
                case 5:
                   return 0;
                default:
                    cout << "Invalid option\n\n";
                    break;
            }
        } else {
            cout << "Invalid input\n\n";
            cin.ignore();
        }
    }
    return 0;
}
