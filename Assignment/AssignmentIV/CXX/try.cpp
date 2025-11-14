#include <iostream>
using namespace std;
int main(){
    int a[10] = {21,22,23,24,25,26,27,28,29,30};
    int b[10] = {51,52,53,54,55,56,57,58,59,60};
    int crash10 = 0;
    int crash11 = 0;
    int crash37 = 0;
    for(int i = 0; i < 10; i++){
        int temp[10]{};
        temp[i] = a[i] % 10;
        for(int j = 0; j < 10; j++){
            b[j] % 10 == temp[i] ? crash10++ : crash10 == crash10;
        }
    }
    for(int i = 0; i < 10; i++){
        int temp[10]{};
        temp[i] = a[i] % 11;
        for(int j = 0; j < 10; j++){
            b[j] % 11 == temp[i] ? crash11++ : crash11 == crash11;
        }
    }
    for(int i = 0; i < 10; i++){
        int temp[10]{};
        temp[i] = a[i] % 37;
        for(int j = 0; j < 10; j++){
            b[j] % 37 == temp[i] ? crash37++ : crash37 == crash37;
        }
    }
    cout << "Crash10: " << crash10 << endl;
    cout << "Crash11: " << crash11 << endl;
    cout << "Crash37: " << crash37 << endl;
}