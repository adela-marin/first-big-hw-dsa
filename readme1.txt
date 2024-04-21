Flight Booking System

I. Introduction
The Flight Booking System is designed to efficiently manage the booking and cancellation of seats across multiple flights for a small airline. 
It utilizes a custom data structure implemented using linked lists.

- Data Structure: FlightBookingSystem
The FlightBookingSystem manages a series of flights, where each flight has a limited number of seats (up to a maximum of 5 seats per flight). 
Each flight is represented as an array within a node of a linked list, where each element of the array corresponds to a seat booking status (booked/unbooked).

II. Methods

	1. FlightBookingSystem()
		- Initializes the booking system.

	2. void bookSeat(string passengerName)
		- Books a seat for a passenger by adding their name to the last available seat of the last flight in the system. 
		- If the last flight is fully booked, a new flight (node) is created, and the passenger is booked on this new flight.

	3. void cancelBooking(int seatIndex)
		- Cancels the booking for the seat at the global index (across all flights) seatIndex. 
		- This operation ensures that there are no empty slots in the arrays (flights) and shifts subsequent bookings accordingly, possibly across different flights.

	4. void displaySystem()
		- Displays the current booking status of all flights, with each flight's bookings shown on a new line.

	5. string getPassenger(int seatIndex)
		- Returns the name of the passenger booked at the global seat index seatIndex.

III. Example Operations
	1. Booking a Seat:
		If there are available seats on the current flight, the system adds the passenger's name to the next available seat.
		If the current flight is fully booked, the system creates a new flight and adds the passenger's name to the first seat of this new flight.
	2. Cancelling a Booking:
		When a booking is cancelled for a specific seat index, the system removes the passenger's name from that seat and adjusts subsequent bookings if necessary, across different flights.
	3. Displaying the Booking System:
		The system displays the current booking status of all flights, showing each flight's bookings on a separate line.
	4. Retrieving Passenger Information:
		Given a seat index, the system returns the name of the passenger booked at that seat across all flights.

IV. Input 
	The input for this flight booking system consists of user-selected options from a menu displayed in the console:
		1. Book a seat: Prompt the user to enter the passenger's name to book a seat.
		2. Cancel booking: Prompt the user to enter the seat index to cancel the booking for that seat.
		3. Display system: Display the current booking status across all flights.
		4. Exit: Terminate the program.
	The user interacts with the system by selecting one of these options repeatedly until choosing to exit.

V. Example
	1. Bookings are initially empty.
	2. bookSeat("Sergiu") adds Sergiu to the first flight.
	3. bookSeat("Ana") adds Ana to the same flight as Sergiu.
	4. displaySystem() shows the booking status across all flights.
	5. getPassenger(0) returns "Sergiu".
	6. cancelBooking(0) removes Sergiu from the first flight, shifts Ana to the first seat, and moves subsequent bookings accordingly.
	7. displaySystem() reflects the updated booking status.
	