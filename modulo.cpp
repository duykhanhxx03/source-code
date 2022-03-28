#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ARRAY = 10000;
void ternarySearch (int value, int array[], int size) {
    int location;
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int key1 = (left + right) / 3;
        int key2 = (left + right) * 2 / 3;
        if (value < array[key1]) {
            right = key1 + 1;
        } else if (value > array[key2]) {
            left = key2;
        } else{
            left = key1;
            right = key2 + 1;
        }
    }

    if (value == array[left]) {
        location = left;
    } else {
        location = -1;
    }

    cout << location;
}

int main () {
    int value, n;
    cin >> value >> n;

    int array[100];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort (array, array + n);
    //ternarySearch(value, array, n);

    return 0;
}