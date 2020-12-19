#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct Direction {
        int x;
        int y;
    };

vector<Direction> directions {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {0, -1}
};

char findSeat(vector<vector<char> >& seats, int row, int col, Direction direction){
    char result = '.';
    int i = row + direction.x;
    int j = col + direction.y;
    int rowSize = seats.size();
    int colSize = seats[0].size();
    while(i >= 0 && j >= 0 && i < rowSize && j < colSize && result == '.'){
        result = seats[i][j];
        i += direction.x;
        j += direction.y;
    }
    return result;
}

int AdjSeatsOccu(vector<vector<char> >& seats, int i, int j){
    int count = 0;
    for(auto& direction: directions){
        if(findSeat(seats, i, j, direction) == '#') count++;
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
    for(int i = 0; i < 90; i++){
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