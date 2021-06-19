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

    cout << gang << endl << "(" << gang.numOfElements() << " elements)" << endl;

    gang[3] = "Mana sou";
    cout << gang << endl << "(" << gang.numOfElements() << " elements)" << endl;

    gang.add(1, "Dimitris");
    cout << gang << endl << "(" << gang.numOfElements() << " elements)" << endl;


    cout << endl;


    list<int> integers;

    int N, k;
    cout << "How many integers: ";
    cin >> N;

    cout << "Input Values: ";
    for (int i = 0; i < N; ++i) {
        cin >> k;
        integers.pushBack(k);
    }

    cout << endl << integers << endl << "(" << integers.numOfElements() << " elements)\n" << endl;

    bool keep_adding = false;
    do {
        cout << "Select position to add integer: ";
        cin >> N;
        cout << "Value: ";
        cin >> k;

        integers.add(N, k);

        cout << endl << integers << endl << "(" << integers.numOfElements() << " elements)\n" << endl;
        cout << "Add more? (1: Yes, 0: No): ";
        cin >> keep_adding;
    } while (keep_adding);


    return 0;
}
