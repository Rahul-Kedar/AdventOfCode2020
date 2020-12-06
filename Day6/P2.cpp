#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    ifstream input;
    string line;
    int sum = 0;
    input.open("input.txt");
    while(!input.eof()){
        int count = 0;
        unordered_map<char, int> questions;
        while(getline(input, line)){
            if(line.length() < 1) break;
            for(auto& ch : line) questions[ch]++;
            count++;
        }
        for(auto& it: questions){
            if(it.second == count) sum++;
        }
    }
    cout << sum << "\n"; 
    input.close();
    return 0;
}