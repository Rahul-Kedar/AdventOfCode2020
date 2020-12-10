#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int formChain(vector<int>& in){
    int diff1 = 0, diff3 = 0;
    int prev = 0;
    for(int i = 0; i < in.size(); i++){
        if((in[i] - prev) == 1) diff1++;
        else diff3++;
        prev = in[i];
    }
    diff3++;
    return diff1 * diff3;
}

int parseInt(string& x){
    int num = 0;
    for(auto& ch : x) num = num*10 + ch - '0';
    return num;
}

int main(){
    ifstream input;
    string line;
    vector<int> adaptors;
    input.open("input.txt");
    while(getline(input, line)){
        adaptors.push_back(parseInt(line));
    }
    sort(adaptors.begin(), adaptors.end());    
    cout << formChain(adaptors) << "\n";
    input.close();
    return 0;
}
