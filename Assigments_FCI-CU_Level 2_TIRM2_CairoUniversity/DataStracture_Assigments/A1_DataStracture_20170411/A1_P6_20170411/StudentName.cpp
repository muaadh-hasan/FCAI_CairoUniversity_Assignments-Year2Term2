

#include "StudentName.h"

#include <iostream>
#include <vector>


using namespace std;


StudentName::StudentName(string iFullName) : fullName(iFullName) {
    vector<string> words = getWords();
    for (vector<string>::size_type i = words.size(); i < 3; i++) {
        fullName += ' ' + words[words.size() - 1];
    }
}

vector<string> StudentName::getWords() {
    vector<string> words;
    string::size_type i = 0, l_s_pos = 0;
    while (i < fullName.size()) {
        if (fullName[i] == ' ') {
            words.push_back(fullName.substr(l_s_pos, i - l_s_pos));
            l_s_pos = i + 1 ;
        }
        i++;
    }
    words.push_back(fullName.substr(l_s_pos, i - l_s_pos));
    return words;
}

void StudentName::print() {
    vector<string> words = getWords();
    for (vector<string>::size_type i = 0; i < words.size() ; i++) {
        cout << words[i] << '\n';
    }
}
bool StudentName::replace(int a, int b) {
    (a--, b--);

    if (a > b) {
        swap(a, b);
    }

    if (a < 0) {
        return false;
    }

    vector<string> words = getWords();

    if (b > words.size() -1) {
        return false;
    }

    if (a == b) {
        return true;
    }

    swap(words[a], words[b]);

    fullName = words[0];
    for (vector<string>::size_type i = 1; i < words.size(); i++) {
        fullName += ' ' + words[i];
    }

    return true;
}

