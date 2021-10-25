#include <iostream>
using namespace std;

int leastPossibleLength(string str[], int sizeOfArray) {
    int output = str[0].size();
    for (int i=1; i<sizeOfArray; i++) {
        if (str[i].size() < output)
            output = str[i].size();
    }
    return output;
}

string longestCommonPrefix(string str[], int sizeOfArray) {
    string output = "";
    for(int i=0; i<leastPossibleLength(str, sizeOfArray); i++) {
        char characterInFirstString = str[0][i];
        for (int j=1; j<sizeOfArray; j++) {
            if(characterInFirstString != str[j][i]) {
                return output;
            }
        }
        output = output + characterInFirstString;
    }
    return output;
}

int main() {
    string animals[] = {"abc", "ab", "ade"};
    cout << longestCommonPrefix(animals, (sizeof(animals)/sizeof(animals[0]))) << endl;
}