#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct Pair {
    char variable;
    int value;
};

class Calculator {
	private:
		stack<char> expressionStack;
		vector<Pair> v;

	public:
		void readinput()
		{
			string line;
			while (in >> line) {
				if (line[0] != '(') {
					char letter;
					int nr = 0, i = 2, sgn = 1, length = line.length();
					if (isupper(line[0])) letter = line[0];
					else out << "The letter " << line[0] << " is invalid.", exit(0);
					if(line[1] != '=') out << "The operator " << line[1] << " is invalid.", exit(0);
					if(line[i] == '-') i++, sgn = -1;
					if (!isdigit(line[i])) out << line[i] << " is not an integer.", exit(0);
					for(; i < length; i++) {
						nr = nr * 10 + (line[i] - '0');
					}
					nr *= sgn;
					v.push_back({letter, nr});
				}
				else {
					for(auto i : line) {
						expressionStack.push(i);
					}	
				}	
			}
		}

		int execute()
		{
			char letter='z';
			while(!expressionStack.empty() && expressionStack.top() == ')') {
				stack<char> auxStack;
				string expression;
				while(!expressionStack.empty() && expressionStack.top() != '(') {
					auxStack.push(expressionStack.top());
					expressionStack.pop();
				}
				expressionStack.pop();
				while(!auxStack.empty() && auxStack.top() != ')') {
					expression += auxStack.top();
					auxStack.pop();
				}
				auxStack.pop();
				v.push_back({letter, evaluate(expression)});
				expressionStack.push(letter);
				letter--;
				while(!auxStack.empty()) {
					expressionStack.push(auxStack.top());
					auxStack.pop();
				}
			}
			return v[v.size()-1].value;
		}

		int evaluate(string exp)
		{
			int result = 0;
			char letter = 'a';
			bool found = true;
			vector<Pair> aux;
			while (found) {
				found = false;
				for (int i = 0; i < exp.length(); i++) {
					char sgn;
					if (exp[i] == '*' || exp[i] == '/' || exp[i] == '%') {
						int nr1 = 0, nr2 = 0, s = 0;
						bool found1 = false, found2 = false;
						sgn = exp[i];
						found = true;
						for (int j = 0; j < aux.size(); j++) {
							if (aux[j].variable == exp[i - 1]) nr1 = aux[j].value, found1 = true;
							if (aux[j].variable == exp[i+1]) nr2 = aux[j].value, found2 = true;	
						}
						for (int j = 0; j < v.size(); j++) {
							if(!nr1 && v[j].variable == exp[i - 1]) nr1 = v[j].value, found1 = true;
							if(!nr2 && v[j].variable == exp[i + 1]) nr2 = v[j].value, found2 = true;
						}
						if (!found1) out << "The letter " << exp[i - 1] << " was not defined.", exit(0);
						if (!found2) out << "The letter " << exp[i + 1] << " was not defined.", exit(0);
						if(sgn == '*') s = nr1 * nr2;
						else if(sgn == '/') {
							if(nr2 == 0) out << "Division by zero.", exit(0);
							s = nr1 / nr2;
						}
						else {
							if(nr2 == 0) out << "Module by zero.", exit(0);
							s = nr1 % nr2;
						}
						aux.push_back({letter, s});
						exp[i - 1] = letter;
						letter++;
						for(int j = i; j < exp.length() - 2; j++) {
							exp[j] = exp[j + 2];
						}
						exp.resize(exp.length() - 2);
						i = 0;
					}
				}
			}
			while(exp.length() > 1) {
				for(int i = 0; i < exp.length(); i++) {
					char sgn;
					if(exp[i] == '+' || exp[i] == '-') {
						int nr1 = 0, nr2 = 0, s = 0;
						bool found1 = false, found2 = false;
						sgn = exp[i];
						for(int j = 0; j < aux.size(); j++) {
							if(aux[j].variable == exp[i - 1]) nr1 = aux[j].value, found1 = true;
							if(aux[j].variable == exp[i + 1]) nr2 = aux[j].value, found2 = true;
						}
						for(int j = 0; j < v.size(); j++) {
							if(!nr1 && v[j].variable == exp[i - 1]) nr1 = v[j].value, found1 = true;
							if(!nr2 && v[j].variable == exp[i + 1])
								nr2 = v[j].value, found2 = true;
						}
						if(!found1) out << "The letter " << exp[i - 1] << " was not defined.", exit(0);
						if(!found2) out << "The letter " << exp[i + 1] << " was not defined.", exit(0);
						if(sgn == '+') s = nr1 + nr2;
						else s = nr1 - nr2;
						aux.push_back({letter, s});
						exp[i - 1] = letter;
						letter++;
						for(int j = i; j < exp.length() - 2; j++) {
							exp[j] = exp[j + 2];
						}
						exp.resize(exp.length() - 2);
						i = 0;
					}
				}
			}
			for(int i = 0; i < aux.size(); i++) {
				if(aux[i].variable == exp[0]) return aux[i].value;
			}

			return 0;
		}

		void writeOutput()
		{
			int result = execute();
			out << "Result = " << result;
		}

};

int main()
{
    Calculator calc;
    calc.readinput();
    calc.writeOutput();

	in.close();
	out.close();

    return 0;
}