#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream input;
    string str;
    input.open("input.txt");
    int currentPosition = 3, tree = 0;
    input >> str;
    int length = str.size();
    while(input >> str) {
        if(str[currentPosition] == '#') {
            tree++;
        }
        currentPosition += 3;
        currentPosition %= length;
    }
    cout << tree << "\n";
    input.close();
    return 0;
}
