#include<iostream>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<string>
using namespace std;

bool validatePassport(unordered_map<string, string>& passport){
    int passportFields = passport.size();
    if(passportFields < 7 || (passportFields == 7 && passport.find("cid") != passport.end())) return false;
    return true;
}

void parseLine(string& line, unordered_map<string, string>& fields){
    string field = "";
    for(auto& x : line){
        if(x == ' ') {
            fields[field.substr(0,3)] = field.substr(4, field.length());
            field = "";
        }
        else field += x;        
    }
    fields[field.substr(0,3)] = field.substr(4, field.length());    
}

int main(){
    ifstream input;
    string line;
    vector<unordered_map<string, string> > passports;
    input.open("input.txt");
    int validPassports = 0;
    while (!input.eof()) {   
        unordered_map<string, string> fields;     
        while (getline(input, line)) {
            if(line.length() <= 1) break;  //MinGW g++ & cl.exe returns 0, but WSL g++ returns 1.
            parseLine(line, fields);
        } 
        passports.push_back(fields);  
    }
    for(auto& passport: passports){
        if(validatePassport(passport)) validPassports++; 
    }
    cout << validPassports << "\n";
    input.close();
    return 0;
}