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

    cout << gang << endl;

    gang[3] = "Mana sou";
    cout << gang << endl;

    gang.add(1, "Dimitris");
    cout << gang << endl;

    cout << endl;

    return 0;
}
