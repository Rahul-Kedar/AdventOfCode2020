#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main() {
    ifstream input;
    ofstream output;
    int num[200], a, b, c;
    bool flag = false;
    input.open("input.txt");
    for (int i = 0; i < 200; i++) {
        input >> num[i];
    }
    sort(num, num + 200);
    for (int k = 0; k < 198; k++) {
        for (int i = k + 1, j = 199; i < j;) {
            int x = 2020 - num[k];
            int sum = num[i] + num[j];
            if (sum == x) {
                a = num[i];
                b = num[j];
                c = num[k];
                break;
            } else if (sum > x)
                j--;
            else
                i++;
        }
    }

    cout << a * b * c << "\n";
    input.close();
    return 0;
}