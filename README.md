# first-big-hw-dsa

This homework consists in three exercises as it follows.

#ex1
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

	Example
		1. Bookings are initially empty.
		2. bookSeat("Matei") adds Matei to the first flight.
		3. bookSeat("Alex") adds Alex to the same flight as Alex.
		4. displaySystem() shows the booking status across all flights.
		5. getPassenger(0) returns "Matei".
		6. cancelBooking(0) removes Matei from the first flight, shifts Alex to the first seat, and moves subsequent bookings accordingly.
		7. displaySystem() reflects the updated booking status.

V. Edge cases

	- if the user wants to cancel a seat which was not booked
	- if the user wants to book more seats then the number of available seats

Note

	There are 2 solutions provided, in one of them being used a singly linked list, and in the other a doubly linked list.


#ex2
Oasis Journey through Desert

I. Introduction

	The Oasis Journey through Desert program aims to help travelers identify the optimal starting oasis for a journey across a vast desert. 
	With limited water reserves in their vehicle, travelers must strategically choose the starting point to ensure they can complete the journey without running out of water before reaching subsequent oases.

II. Methods

	Input:
		Reads input data from an external file ("input.txt").
		Parses the number of oases and the consumption rate for water during the journey.
		Validates input parameters, ensuring they meet specified criteria.
	Processing:
		Constructs a circular queue (queueInit) to store oasis information, initializing it with oasis data sorted in ascending order based on water availability.
		Utilizes a copy queue (queueAux) to test different starting points without altering the original queue.
		Implements the main algorithm to find the optimal starting oasis:
			Iteratively tests each oasis to determine if the journey can be completed without running out of water before reaching subsequent oases.
			Calculates the distance the vehicle can travel with the available water (D) considering the consumption rate.
			Halts the process if the distance to the next oasis is greater than D.
			Identifies the correct starting point if all oases are successfully traversed.
	Output:
		Writes the result indicating the optimal starting oasis to an external file ("output.txt").
	Error Handling:
		Handles corner cases, such as zero or negative values for the number of oases or the consumption rate.
		Outputs an error message if the journey is not possible due to invalid input parameters.

III. Example Operations

	Journey Initialization:
		The program initializes the journey by reading the input data, including the number of oases and the consumption rate of water during the journey.
	Finding Optimal Starting Oasis:
		Utilizing the main algorithm, the program iteratively tests each oasis to determine the optimal starting point for the journey.
		Calculates the distance the vehicle can travel with the available water (D) considering the consumption rate.
		Halts the process if the distance to the next oasis is greater than D.
		Identifies the correct starting oasis if all oases are successfully traversed.
	Displaying the Result:
		The program writes the result indicating the optimal starting oasis to an external file ("output.txt").
	Handling Errors:
		If the journey is not possible due to invalid input parameters (such as zero or negative values for the number of oases or the consumption rate), the program outputs an error message.

IV. Input

	The input for this program consists of:
		The number of oases in the desert.
		The consumption rate of water during the journey.
		Information about each oasis, including water availability and distance to the next oasis.
	The information are provided using a file named "input.txt"

V. Example

	Input:
		The number of oases: 3
		The consumption rate: 5
		Oasis water and distance to next:
		1 25
		10 15
		3 20

	Output:
		1 is the oasis from where we can start our journey


#ex3
Calculator

I. Introduction

	The Calculator program emulates a calculator using a stack. It reads input from a file ("input.txt") and prints the output to another file ("output.txt").

	The program consists of the following components:
		Pair: A struct containing pairs of variable (char) and value (int).
		Calculator: The main class responsible for initializing the calculator and executing operations.

II. Classes and Methods

	Pair
		Attributes: variable (char) and value (int).
	Calculator
		Attributes:
			expressionStack: Stack to store expression characters.
			v: Vector to store variable names and values.
		Methods:
			readInput(): Reads input from the file, handles variable declarations, and checks for errors.
			execute(): Executes the expression and returns the result.
			evaluate(): Evaluates mathematical expressions and handles errors.
			writeOutput(): Writes the result to the output file.

III. Input

	The input file ("input.txt") contains variable declarations followed by a single left-handed expression that uses the variables within parentheses. 
	Possible operators include addition (+), subtraction (-), multiplication (*), division (/), and modulo (%). 
	Variable names range from A to Z, followed by '=' and an integer value.
	The expression has to be written in parentheses.
	Example:
		A=9
		B=100
		(A+B-A)

IV. Error Handling

	The program handles various error scenarios, including:
		- invalid operators
		- invalid numerical values and/or variable names
		- using undefined variables in expressions
		- division by zero

VI. Edge Cases

	The most important edge cases for this program are presented below.
	For the following cases, the output consists in a corresponding message
	1. for defining the variables
		- if an operand is not a letter from A to Z
		- if the operator is not '='
		- if the assigned value is not an integer

	2. for expression
		- if the operands are not letters from A to Z, or the operators are not valid
		- if a letter (variable) was not defined
		- if there is any division by 0
		- if the parentheses are not correctly used (not well balanced)
		- if there are any parentheses, correctly opened and closed, but they do not contain any expression (empty parentheses)
		- if the expression starts with any operator which is not the substraction one (if it is of the type (-(A+B)), then it is correct, but if it is like (/(A+B)), it is not)
		- if the expression ends with any operator
		- if the expression contains succesive operatos (for example, (A+-B))

