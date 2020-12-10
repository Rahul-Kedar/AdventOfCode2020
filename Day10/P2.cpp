#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>

#define ll long long int

using namespace std;

//taken help from https://github.com/alexandru-cohal/AdventOfCode2020/blob/master/AdventOfCode2020/day10/day10puzzle2.cpp
void ans(unordered_map<int, ll>& adaptors, int maxJoult){
    for(int i = 1; i <= maxJoult; i++){
        if(adaptors.find(i) != adaptors.end()){
            if(adaptors.find(i-1) != adaptors.end()) adaptors[i] += adaptors[i-1];
            if(adaptors.find(i-2) != adaptors.end()) adaptors[i] += adaptors[i-2];
            if(adaptors.find(i-3) != adaptors.end()) adaptors[i] += adaptors[i-3];
        }        
    }
}

int parseInt(string& x){
    int num = 0;
    for(auto& ch : x) num = num*10 + ch - '0';
    return num;
}

int main(){
    ifstream input;
    string line;
    unordered_map<int, ll> adaptors;
    int maxJolt = 0;
    input.open("input.txt");
    while(getline(input, line)){
        int joult = parseInt(line);
        adaptors[joult] = 0;
        if(joult > maxJolt) maxJolt = joult;
    }
    adaptors[0] = 1;
    ans(adaptors, maxJolt);
    cout << adaptors[maxJolt] << "\n";
    input.close();
    return 0;
}
