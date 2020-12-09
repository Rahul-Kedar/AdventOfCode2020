#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_set>

#define ll long long int

using namespace std;

ll cumSum(vector<ll>& in, ll num){
    ll sum = 0, smallest = INT_MAX, largest = INT_MIN;
    int start = 0, end = 0;
    for(int i = 0; i < in.size(); i++){
        if(sum == num) break;
        sum += in[i];
        while(sum > num) {
            sum -= in[start];
            start++;
        }
        end = i;
    }
    for(int i = start; i <= end; i++){
        if(in[i] > largest) largest = in[i];
        if(in[i] < smallest) smallest = in[i];
    }
    return smallest + largest;
}

bool isNumberValid(vector<ll>& in, ll num, int start, int end){
    unordered_set<ll> s;
    for(int i = start; i <= end; i++){
        ll temp = num - in[i];
        if(s.find(temp) != s.end()) return true;
        s.insert(in[i]);
    }
    return false;
}

ll invalidNumber(vector<ll>& in, int preamble){
    for(int i = preamble; i < in.size(); i++){
        if(!isNumberValid(in, in[i], i - preamble, i - 1)) return in[i];
    }
    return -1;
}

ll parseLongLong(string& x){
    ll num = 0;
    for(auto& ch : x){
        num = num*10 + ch - '0';
    }
    return num;
}

int main(){
    ifstream input;
    string line;
    vector<ll> numbers;
    input.open("input.txt");
    while(getline(input, line)){
        numbers.push_back(parseLongLong(line));
    }
    // cout << invalidNumber(numbers, 5) << "\n";
    cout << cumSum(numbers, 27911108) << "\n";
    input.close();
    return 0;
}
