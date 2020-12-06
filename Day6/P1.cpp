#include<iostream>
#include<fstream>
#include<string>
#include<unordered_set>
using namespace std;

int main(){
    ifstream input;
    string line;
    int sum = 0;
    input.open("input.txt");
    while(!input.eof()){
        unordered_set<char> questions;
        while(getline(input, line)){
            if(line.length() < 1) break;
            for(auto& ch: line){
                questions.insert(ch);
            }
        }
        sum += questions.size();
    }
    cout << sum << "\n"; 
    input.close();
    return 0;
}