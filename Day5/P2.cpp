#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int getSeatRow(string& seat){
    int front = 0, back = 127, diff;
    for(int i = 0; i < 7; i++){
        diff = (back - front);
        if(seat[i] == 'F') back -= diff / 2 + 1;
        if(seat[i] == 'B') front += diff / 2 + 1;
    }
    return front;
}

int getSeatCol(string& seat){
    int left = 0, right = 7, diff;
    for(int i = 0; i < 3; i++){
        diff = (right - left);
        if(seat[7 + i] == 'L') right -= diff / 2 + 1;
        if(seat[7 + i] == 'R') left += diff / 2 + 1;
    }
    return left;
}

int main(){
    ifstream input;
    string bseat;
    int seatID, row, col, mySeat = 0;
    vector<int> seats;
    input.open("input.txt");
    while (!input.eof())
    {
        input >> bseat;
        row = getSeatRow(bseat);
        col = getSeatCol(bseat);
        seatID = row * 8 + col;
        seats.push_back(seatID);
    } 
    sort(seats.begin(), seats.end());
    int size = seats.size();
    for(int i = 1; i < size; i++){
        if(seats[i]-1 != seats[i-1]) {
            mySeat = seats[i] - 1;
            break;
        }
    }
    cout << mySeat << "\n";
    input.close();
    return 0;
}