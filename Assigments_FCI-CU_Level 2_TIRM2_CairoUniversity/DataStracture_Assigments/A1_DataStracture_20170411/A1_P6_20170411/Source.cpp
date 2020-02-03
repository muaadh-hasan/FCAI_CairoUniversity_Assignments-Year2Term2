#include <iostream>

#include "StudentName.h"

using namespace std;

void Test(int id, string name, int r, int w) {
    cout << "Test " << id << ":\n";
    cout << "Before replacement:\n";
    StudentName name_t(name);
    name_t.print();
    cout << endl;

    cout << "After replacement:\n";
    if (name_t.replace(r, w)) {
        name_t.print();
        cout << '\n';

    }
    else {
        cout << "Failed to replace.\n\n";
    }

    cout << endl;
}

int main() {
    Test(0, "Gobran Alnuimi", 1, 2);
    Test(1, "Amr", 1, 2);
    Test(2, "Muaath Hussan", 2, 1);
    Test(3, "Ahmed Amr Ali", 1, 3);
    Test(4, "Taqi mayoof", 2, 2);
    Test(5, "Khaled", 7, 7);
    Test(6, "Karim Mokhtar", 0, -1);
system("pause");
}
