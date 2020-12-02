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
    if(password[min-1] == ch && password[max-1] == ch) return false;
    if(password[min-1] == ch || password[max-1] == ch) return true;
    return false;
}

int main(){
    ifstream input;
    string ch, password;
    int index1, index2, validPasswd = 0;
    input.open("input.txt");
    for(int i = 0; i < 1000; i++){
        getIntInput(input, index1);
        getIntInput(input, index2);
        getStringInput(input, ch);
        getStringInput(input, password);
        if(isPasswordValid(index1, index2, ch[0], password))
            validPasswd++;
    }
    cout << validPasswd << "\n";
    input.close();
    return 0;
}