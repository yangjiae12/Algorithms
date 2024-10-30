#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data() {
    for (int i = 0; i < SIZE; i++)
        cout << " " << L[i] << " ";
    cout << endl;
}

void merge(int L_index, int R_index, int m) {
    int i, j, k;
    int B[SIZE];

    for (i = m + 1; i > L_index; i--) {
        B[i - 1] = L[i - 1];
    }
    for (j = m; j < R_index; j++) {
        B[R_index + m - j] = L[j + 1];
    }

    for (k = L_index; k <= R_index; k++) {
        L[k] = (B[i] < B[j]) ? B[i++] : B[j--];
    }
}

void merge_sort(int L_index, int R_index) {
    if (L_index < R_index) {
        int m = (L_index + R_index) / 2;

        // 왼쪽과 오른쪽 부분 정렬
        merge_sort(L_index, m);
        merge_sort(m + 1, R_index);

        // 정렬된 두 부분을 병합
        merge(L_index, R_index, m);
    }
}

int main() {
    cout << "Input Data : ";
    print_data();

    merge_sort(0, SIZE - 1);

    cout << "\n\nSorted Data : ";
    print_data();

    return 0;
}
