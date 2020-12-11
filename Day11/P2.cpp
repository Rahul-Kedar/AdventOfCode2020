#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


int AdjSeatsOccu(vector<vector<char> >& seats, int si, int sj){
    int count = 0;
    int i = si;
    int j = sj;
    int rowSize = seats.size() - 1;
    int colSize = seats[0].size() - 1;

    while(i > 0){
        i--;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#') {
            count++;
            break;
        }
    }

    i = si;
    while (i < rowSize){
        i++;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#') {
            count++;
            break;
        }
    }

    i = si;
    while (j > 0){
        j--;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#') {
            count++;
            break;
        }
    }

    j = sj;
    while (j < colSize) {
        j++;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#'){
            count++;
            break;
        }
    }

    j = sj;
    while(i > 0 && j > 0) {
        i--;
        j--;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#'){
            count++;
            break;
        }
    }

    i = si;
    j = sj;
    while(i < rowSize && j > 0) {
        i++;
        j--;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#'){
            count++;
            break;
        }
    }

    i = si;
    j = sj;
    while(i > 0 && j < colSize) {
        i--;
        j++;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#'){
            count++;
            break;
        }
    }

    i = si;
    j = sj;
    while(i < rowSize && j < colSize) {
        i++;
        j++;
        if(seats[i][j] == 'L') break;
        if(seats[i][j] == '#'){
            count++;
            break;
        }
    }

    return count;
}

void fillSeats(vector<vector<char> >& seats, vector<vector<char> >& newSeats){
    int rows = seats.size();
    int columns = seats[0].size();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(seats[i][j] == 'L' && (AdjSeatsOccu(seats, i, j) == 0)) newSeats[i][j] = '#';
            if(seats[i][j] == '#' && (AdjSeatsOccu(seats, i, j) >= 5)) newSeats[i][j] = 'L';
        }
    }
}


void copyVec(vector<vector<char> >& Old, vector<vector<char> >& New){
    int rows = Old.size();
    int columns = Old[0].size();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            New[i][j] = Old[i][j];
        }
    }
}

int OccupiedSeats(vector<vector<char> >& seats){   
    vector<vector<char> > newSeats;
    int count = 0;
    int rows = seats.size();
    int columns = seats[0].size();
    for(int i = 0; i < rows; i++){
        vector<char> temp;
        for(int j = 0; j < columns; j++){
            temp.push_back('.');
        }
        newSeats.push_back(temp);
    }
    for(int i = 0; i < 100; i++){
        fillSeats(seats, newSeats);
        copyVec(newSeats, seats);
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(seats[i][j] == '#') count++;
        }
    }
    return count;
}

void readInput(vector<vector<char> >& seats, string& line){
    vector<char> seatsRow;
    for(auto& ch: line) seatsRow.push_back(ch);
    seats.push_back(seatsRow);
}

int main(){
    ifstream input;
    string line;
    vector<vector<char> > seats;
    input.open("input.txt");
    while(getline(input, line)){
        readInput(seats, line);
    }
    cout << OccupiedSeats(seats) << "\n";
    input.close();
    return 0;
}