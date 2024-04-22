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


