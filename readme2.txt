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


