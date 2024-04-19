#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Oasis {
    int water;
    int distanceToNext;
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, consumptionRate;
    // fin >> n >> consumptionRate;

    while (!isdigit(fin.peek())) {
        fin.ignore(1);
    }
    fin >> n;
    while (!isdigit(fin.peek())) {
        fin.ignore(1);
    }
    fin >> consumptionRate;

    queue<Oasis> queueInit;
    queue<Oasis> queueAux;

    for (int i = 0; i < n; i++) {
        Oasis o;
        // fin >> o.water >> o.distanceToNext;
        while (!isdigit(fin.peek())) {
            fin.ignore(1);
        }
        fin >> o.water;
        while (!isdigit(fin.peek())) {
            fin.ignore(1);
        }
        fin >> o.distanceToNext;

        queueInit.push(o);
        queueAux.push(o);
    }

    int index = 1;
	while (!queueInit.empty()) {
		int w = queueInit.front().water;
		int d = queueInit.front().distanceToNext;

		if (100 * w / consumptionRate < d) {
			fout << index << " is the oasis from where we can start our journey";
			return 0;
		}

		queueInit.pop();

		index++;

		queueInit.push(queueAux.front());
		queueAux.pop();
	}

    fin.close();
    fout.close();

    return 0;
}
