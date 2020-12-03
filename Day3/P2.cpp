#include<iostream>
#include<fstream>
using namespace std;

int findTrees(int right, int down){
    ifstream fin;    
    fin.open("input.txt");
    int currentPosition = right, tree = 0;
    string str;
    fin >> str;
    int length = str.size();
    while(!fin.eof()) {
        fin >> str;
        if(down > 1) {
            fin >> str;
        }        
        if(str[currentPosition] == '#') {
            tree++;
        }
        currentPosition += right;
        currentPosition %= length;
    }
    fin.close();
    return tree;
}

int main(){
    int treeCount = 1;
    int slopes[5][2] = {{1,1}, {3,1}, {5,1}, {7,1}, {1,2}};
    for(int i = 0; i < 5; i++){
        treeCount *= findTrees(slopes[i][0], slopes[i][1]);
    }
    cout << treeCount << "\n";
    return 0;
}
