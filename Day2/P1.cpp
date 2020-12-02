#include<iostream>
#include<fstream>
using namespace std;

void getIntInput(ifstream& fin, int& val){
    val = 0;
    char c;
    fin.get(c);
    while((c < 48 || c > 57) && (!fin.eof())) fin.get(c);
    while((c >= 48 && c <= 57) && (!fin.eof())) {
        val = (val*10) + c -'0';
        fin.get(c);
    }   
}

void getStringInput(ifstream& fin, string& str){
    str = "";
    char ch;
    fin.get(ch);
    while((ch < 97 || ch > 122) && (!fin.eof())) fin.get(ch);
    while((ch >= 97 && ch <= 122) && (!fin.eof())) {
        str += ch;
        fin.get(ch);
    }
}

bool isPasswordValid(int min, int max, char ch, string& password){
    int length = password.size();
    int freq = 0;
    for(int i = 0; i < length; i++){
        if(password[i] == ch)
            freq++;
        if(freq > max)
            return false;
    }
    if(freq < min) 
        return false;
    return true;
}

int main(){
    ifstream input;
    string ch, password;
    int min, max, validPasswd = 0;
    input.open("input.txt");
    for(int i = 0; i < 1000; i++){
        getIntInput(input, min);
        getIntInput(input, max);
        getStringInput(input, ch);
        getStringInput(input, password);
        if(isPasswordValid(min, max, ch[0], password))
            validPasswd++;
    }
    cout << validPasswd << "\n";
    input.close();
    return 0;
}