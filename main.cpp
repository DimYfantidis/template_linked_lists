#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "list.h"

using namespace std;

#define READ_TIME std::chrono::high_resolution_clock::now()
#define MS_DIFF   std::chrono::duration_cast<std::chrono::milliseconds>
#define DBL_SIZE  30000

int main() {
    list<string> gang;

    gang.pushBack("Thanasis");
    gang.pushBack("Varelas");
    gang.pushBack("Stavros");
    gang.pushBack("Andreas");
    gang.pushBack("Giannis");

    cout << gang << "\t(" << gang.getSize() << " elements)" << endl;

    gang[0] = "Nikos";
    cout << gang << "\t(" << gang.getSize() << " elements)" << endl;

    gang.remove(gang[3]);
    cout << gang << "\t\t(" << gang.getSize() << " elements)" << endl;

    gang.insert(1, "Dimitris");
    cout << gang << "\t(" << gang.getSize() << " elements)" << endl;

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

    int pos;
    int keep_adding;
    do {
        cout << "Select position to add integer: ";
        cin >> pos;
        cout << "Value: ";
        cin >> k;

        try {
            integers.insert(pos, k);
        } catch (...) {
            cerr << "ERROR\nPosition index out of range" << endl;
        }

        cout << endl << integers << endl << "(" << integers.getSize() << " elements)\n" << endl;
        cout << "Add more? (1: Yes, 0: No): ";
        cin >> keep_adding;
    } while (keep_adding);


    cout << endl;

    list<double> doubles;

    auto start = READ_TIME;
    for (int i = 0; i < DBL_SIZE; ++i) {
        try {
            doubles.pushBack((double)i + 0.5);
        } catch (...) {
            cerr << "Memory Error! Exiting ..." << endl;
            exit(2);
        }
    }
    auto stop = READ_TIME;
    auto duration = MS_DIFF (stop - start);

    cout << "Doubles list created in " << (double)duration.count()/1000 << " seconds." << endl;

    ofstream outFile;
    outFile.open("list of doubles.txt", ios::out);
    if (outFile.is_open()) {
        start = READ_TIME;
        doubles.print(outFile, VERT);
        stop = READ_TIME;
        duration = MS_DIFF (stop - start);
        outFile.close();
    } else {
        cerr << "File Error!" << endl;
    }

    cout << "Doubles list printed in " << (double)duration.count()/1000 << " seconds." << endl;

    return 0;
}
