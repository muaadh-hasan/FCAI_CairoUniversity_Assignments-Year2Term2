#ifndef STUDENTNAME_H
#define STUDENTNAME_H

#include <string>
#include <vector>

using namespace std;

class StudentName {
private:
    string fullName;

public:
    explicit StudentName(string iFullName);
    vector<string> getWords();
    void print();
    bool replace(int x, int y);

};

#endif // STUDENTNAME_H