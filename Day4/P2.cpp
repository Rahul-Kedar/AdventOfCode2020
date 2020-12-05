#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<regex>
#include<fstream>
#include<string>
using namespace std;

unordered_set<string> ecl_set {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"}; 
regex hcl_regex("^#[0-9a-f]*?$");

int parseInt(string& str){
    int x = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] < '0' || str[i] > '9') return -1;
        x = (x*10) + str[i] - '0';
    }
    return x;
}
bool isHeightValid(string& hgt){
    string unit = hgt.substr(hgt.length() - 2, 2);
    string ihgt = hgt.substr(0, hgt.length() - 2);
    int height = parseInt(ihgt);

    if(unit == "cm" && height >= 150 && height <= 193) return true;
    if(unit == "in" && height >= 59 && height <= 76) return true;
    
    return false;
}


bool isValidPassport(unordered_map<string, string>& passport){
    string byr, iyr, eyr, hgt, hcl, ecl, pid;
    int ibyr, iiyr, ieyr, ipid;
    int passportFields = passport.size();
    if(passportFields < 7 || (passportFields == 7 && passport.find("cid") != passport.end())) return false;
    byr = passport["byr"];
    iyr = passport["iyr"];
    eyr = passport["eyr"];
    hgt = passport["hgt"];
    hcl = passport["hcl"];
    ecl = passport["ecl"];
    pid = passport["pid"];

    ibyr = parseInt(byr);
    iiyr = parseInt(iyr);
    ieyr = parseInt(eyr);
    ipid = parseInt(pid);
    if(byr.length() != 4 || ibyr < 1920  || ibyr > 2002) return false;
    if(iyr.length() != 4 || iiyr < 2010  || iiyr > 2020) return false;
    if(eyr.length() != 4 || ieyr < 2020  || ieyr > 2030) return false;
    if(pid.length() != 9 || ipid == -1) return false;
    if(ecl_set.find(ecl) == ecl_set.end()) return false;
    if(hcl.length() != 7 || !regex_match(hcl.begin(), hcl.end(), hcl_regex)) return false;
    return isHeightValid(hgt);    
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
        for (int i = 0; getline(input, line); i++) {
            if(line.length() <= 1) break;  //MinGW g++ & cl.exe returns 0, but WSL g++ returns 1.
            parseLine(line, fields);
        } 
        passports.push_back(fields);   
    }
    for(auto& passport: passports){
        if(isValidPassport(passport)) validPassports++;
    }
    cout << validPassports << "\n";
    input.close();
    return 0;
}