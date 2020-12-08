#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

int AccuVal(vector<pair<string, int> >& code){
    int acc = 0, line = 0;
    unordered_set<int> exeLines;
    while(line < code.size()){
        if(exeLines.find(line) != exeLines.end()) return acc;
        exeLines.insert(line);
        if (code[line].first == "acc") acc += code[line].second;
        else if (code[line].first == "jmp") line += code[line].second - 1;
        line++;   
    }
    return acc;
}

int parseInt(string& x){
    char ch, sign = x[0];
    int num = 0;
    for(int i = 1; i < x.length(); i++){
        ch = x[i];
        num = num*10 + ch - '0';
    }
    if(sign == '-') return num* -1;
    return num;
}

void parseLine(string& line, vector<pair<string, int> >& code){
    string in = "";
    vector<string> temp;
    for(auto& ch: line){
        if(ch == ' '){
            temp.push_back(in);
            in = "";
        }else
        {
            in += ch;
        }        
    }
    temp.push_back(in);
    code.push_back(make_pair(temp[0], parseInt(temp[1])));
}

int main(){
    ifstream input;
    string line;
    vector<pair<string, int> > code;
    input.open("input.txt");
    while(getline(input, line)){
        parseLine(line, code);
    }
    cout << AccuVal(code) << "\n";
    input.close();
    return 0;
}
