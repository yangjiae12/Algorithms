#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data() {
    for (int i = 0; i < SIZE; i++)
        cout << " " << L[i] << " ";
    cout << endl;
}

void quick_sort(int L_index, int R_index) {
    int temp, i, j;

    if (L_index < R_index) {
        temp = L[L_index]; // 피벗으로 첫 번째 요소 선택
        i = L_index;
        j = R_index + 1;

        do {
            do { i++; } while (L[i] < temp && i <= R_index);
            do { j--; } while (L[j] > temp && j >= L_index);

            if (i < j) {
                int temp_swap = L[i];
                L[i] = L[j];
                L[j] = temp_swap;
            }
        } while (i < j);
        L[L_index] = L[j];
        L[j] = temp;

        quick_sort(L_index, j - 1); // 피벗 기준 왼쪽 부분 정렬
        quick_sort(j + 1, R_index); // 피벗 기준 오른쪽 부분 정렬
    }
}

int main() {
    cout << "Input Data : ";
    print_data();

    quick_sort(0, SIZE - 1);

    cout << "\n\nSorted Data : ";
    print_data();

    return 0;
}
