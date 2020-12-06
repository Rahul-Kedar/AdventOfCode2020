#include<iostream>
#include<fstream>
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
    string seat;
    int highestSeat = 0, seatID, row, col;
    input.open("input.txt");
    while (!input.eof())
    {
        input >> seat;
        row = getSeatRow(seat);
        col = getSeatCol(seat);
        seatID = row * 8 + col;
        if(seatID > highestSeat) highestSeat = seatID;
    } 
    cout << highestSeat << "\n";
    input.close();
    return 0;
}