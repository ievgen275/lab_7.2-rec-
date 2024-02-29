#include <iostream>
#include <iomanip>
#include <climits>
#include <time.h>

using namespace std;

const int ROWS = 3;

void Create(int** a, const int n, const int k, const int Low, const int High, int i, int j);
void Print(int** a, const int n, const int k, int i, int j);
int findMaxInRow(int* row, int k, int col, int currentMax);
int findMinOfMax(int** a, const int n, const int k, int row, int currentMinOfMax);
void SearchMinEven(int** a, const int n, const int k, int& minEven, int i, int j);

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int n, k; // n - row k - col

    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[k];

    Create(a, n, k, Low, High, 0, 0);
    Print(a, n, k, 0, 0);

    int minEven = INT_MAX;
    SearchMinEven(a, n, k, minEven, 0, 0);

    cout << "min value among max values in rows: " << minEven << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int k, const int Low, const int High, int i, int j)
{
    if (i < n) {
        if (j < k) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, n, k, Low, High, i, j + 1);
        }
        else {
            Create(a, n, k, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int n, const int k, int i, int j)
{
    if (i < n) {
        if (j < k) {
            cout << setw(4) << a[i][j];
            Print(a, n, k, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, n, k, i + 1, 0);
        }
    }
}

int findMaxInRow(int* row, int k, int col, int currentMax) {
    if (col == k) {
        return currentMax;
    }

    if (row[col] > currentMax) {
        currentMax = row[col];
    }

    return findMaxInRow(row, k, col + 1, currentMax);
}

int findMinOfMax(int** a, const int n, const int k, int row, int currentMinOfMax) {
    if (row == n) {
        return currentMinOfMax;
    }

    int maxInRow = findMaxInRow(a[row], k, 0, INT_MIN);

    if (maxInRow < currentMinOfMax || currentMinOfMax == INT_MIN) {
        currentMinOfMax = maxInRow;
    }

    return findMinOfMax(a, n, k, row + 1, currentMinOfMax);
}

void SearchMinEven(int** a, const int n, const int k, int& minEven, int i, int j)
{
    if (i < n) {

        int maxInRow = findMaxInRow(a[i], k, 0, INT_MIN);

        if (maxInRow < minEven) {
            minEven = maxInRow;
        }

        SearchMinEven(a, n, k, minEven, i + 1, j);
    }
}
