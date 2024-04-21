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
	Possible operators include addition (+), subtraction (-), multiplication (*), division (/), and modulus (%). 
	Variable names range from A to Z, followed by '=' and an integer value.

IV. Error Handling
	The program handles various error scenarios, including:
		Invalid operators.
		Invalid numerical values and/or variable names.
		Using undefined variables in expressions.
		Division by zero.
