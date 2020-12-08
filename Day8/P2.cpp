#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

bool AccuVal(int& acc, vector<pair<string, int> >& code, unordered_set<int>& exeLines){
    exeLines.clear();
    acc = 0;
    int line = 0;
    while(line < code.size()){
        if(exeLines.find(line) != exeLines.end()) return false;
        exeLines.insert(line);
        if (code[line].first == "acc") acc += code[line].second;
        else if (code[line].first == "jmp") line += code[line].second - 1;
        line++;   
    }
    return true;
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
    bool flag = false;
    int acc = 0;
    vector<pair<string, int> > code;
    unordered_set<int> exeLines, temp;
    input.open("input.txt");
    while(getline(input, line)){
        parseLine(line, code);
    }
    AccuVal(acc, code, exeLines);
    for(auto& i: exeLines){
        if(code[i].first == "nop"){
            code[i].first = "jmp";
            if(AccuVal(acc, code, temp)) break;
            code[i].first = "nop";
        } else if(code[i].first == "jmp"){
            code[i].first = "nop";
            if(AccuVal(acc, code, temp)) break;
            code[i].first = "jmp";
        }
    }

    cout << acc << "\n";
    input.close();
    return 0;
}
