#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main() {
    list<string> gang;

    gang.pushBack("Thanasis");
    gang.pushBack("Varelas");
    gang.pushBack("Stavros");
    gang.pushBack("Andreas");
    gang.pushBack("Giannis");

    cout << gang << endl << "(" << gang.getSize() << " elements)" << endl;

    gang[0] = "Nikos";
    cout << gang << endl << "(" << gang.getSize() << " elements)" << endl;

    gang.remove(gang[3]);
    cout << gang << endl << "(" << gang.getSize() << " elements)" << endl;

    gang.add(1, "Dimitris");
    cout << gang << endl << "(" << gang.getSize() << " elements)" << endl;

    cout << endl;

    list<string> triadi_gang(gang);
    triadi_gang[1] = "Billy";
    triadi_gang.remove(triadi_gang[2]);

    cout << "Killkys gang:\t" << gang << endl
         << "Triadi gang: \t" << triadi_gang << endl;

    cout << endl;

    list<int> integers;

    int k;
    cout << "Input Values (write \"stop\" to continue): ";
    while (cin >> k) {
        integers.pushBack(k);
    }
    cin.clear();
    cin.ignore(1000,'\n');

    if (integers.getSize() == 0) {
        cerr << "ERROR: Input at least one integer!" << endl;
        exit(1);
    }

    cout << endl << integers << endl << "(" << integers.getSize() << " elements)\n" << endl;

    int N;
    int keep_adding;
    do {
        cout << "Select position to add integer: ";
        cin >> N;
        cout << "Value: ";
        cin >> k;

        try {
            integers.add(N, k);
        } catch (...) {
            cerr << "ERROR\nPosition index out of range" << endl;
        }

        cout << endl << integers << endl << "(" << integers.getSize() << " elements)\n" << endl;
        cout << "Add more? (1: Yes, 0: No): ";
        cin >> keep_adding;
    } while (keep_adding);


    return 0;
}
