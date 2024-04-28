#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "queue2.h"

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct Oasis {
    int water;
    int distanceToNext;
};

bool cond(Oasis a, Oasis b)
{
    return a.water < b.water;
}

int main()
{
    int n, consumptionRate, result;
    bool found = false;
    vector<Oasis> v(100);
    
    // citire date conform enuntului
    while (!isdigit(in.peek())) {
        in.ignore(1);
    }
    in >> n;
    while (!isdigit(in.peek())) {
        in.ignore(1);
    }
    in >> consumptionRate;

    // verificare input 
    if (n == 0 || n == 1 || consumptionRate == 0 || consumptionRate == 1 || consumptionRate > 100 || n > 100 || n < 0 || consumptionRate < 0) {
        out << "Not possible";
        return 0;
    }

    // initializare cozi
    QueueCirc<Oasis> queueInit(n);
    QueueCirc<Oasis> queueAux(n);

    // citire date conform enuntului
    for (int i = 0; i < n; i++) {
        while(!isdigit(in.peek())) {
            in.ignore(1);
        }
        in >> v[i].water;
        while(!isdigit(in.peek())) {
            in.ignore(1);
        }
        in >> v[i].distanceToNext;
    }
    // sortare vector
    v.resize(n);
    sort(v.begin(), v.end(), cond);
    // adaugare elemente in cozi
    for (auto i : v) {
        queueInit.enqueue({i.water, i.distanceToNext});
        queueAux.enqueue({i.water, i.distanceToNext});
    }
    // verificare oaza cu formula data
    for (int i = 0; i < n && !found; i++) {
        int w = queueInit.peek().water, nrnext = queueInit.peek().distanceToNext;
        for (int j = 0; j < n && !found; j++) {
            // int D = 100 * w / consumptionRate;
            int D = 100 * queueAux.peek().water / consumptionRate;
            queueAux.dequeue();
            if (queueAux.isEmpty()) {
                found = true;
            }
            else if (D < queueAux.peek().distanceToNext) {
                break;
            }
        }
        if (found) {
            result = w;
        }
        queueInit.dequeue();
        queueInit.enqueue({w, nrnext});
        // golire coada auxiliara
        while (!queueAux.isEmpty()) {
            queueAux.dequeue();
        }
        // refacere coada auxiliara
        for (int j = 0; j < n; j++) {
            int auxwater = queueInit.peek().water, auxdistance = queueInit.peek().distanceToNext;
            queueAux.enqueue({auxwater, auxdistance});
            queueInit.dequeue();
            queueInit.enqueue({auxwater, auxdistance});
        }
    }
    if(!found) {
        out << "Not possible";
    }
    else {
        out << result << " is the oasis from where we can start our journey";
    }

    in.close();
    out.close();

    return 0;
}