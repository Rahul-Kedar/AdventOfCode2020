#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int AdjSeatsOccu(vector<vector<char> >& seats, int si, int sj){
    int count = 0;
    int rowSize = seats.size() - 1;
    int colSize = seats[0].size() - 1;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(i == j && i == 0) continue;
            if((si + i < 0) || (sj + j < 0) || (si + i > rowSize) || (sj + j) > colSize) continue;
            if(seats[si + i][sj + j] == '#') count++; 
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
            if(seats[i][j] == '#' && (AdjSeatsOccu(seats, i, j) >= 4)) newSeats[i][j] = 'L';
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