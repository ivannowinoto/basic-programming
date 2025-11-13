#include <iostream>
using namespace std;

void double_hashing (int *arr1, int *arr2, int n) 
{
    int h1 = 0;
    int h2 = 0;
    int temp = 0;
    int k = 1;
    
    for (int i = 0; i < n; i++) {
        h1 = arr1[i] % 13;
        if (arr2[h1] == 0) {
            arr2[h1] = arr1[i];
        } else {
            while (k != 0) {
            h2 = arr1[i] % 9 + 2;
            temp = (h1 + k * h2) % 13;
            if (arr2[temp] == 0) {
                arr2[temp] = arr1[i];
                break;
                } else k++;
            }
        }
    }
}

int main()
{
    int arr1[13] = {37, 30, 65, 24, 48, 18, 27, 53};
    int arr2[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int sizeOfTable = 13;
    
    double_hashing(arr1, arr2, sizeOfTable);
    
    for (int i = 0; i < 13; i++) {
        cout << arr2[i] << " ";
    }
}
