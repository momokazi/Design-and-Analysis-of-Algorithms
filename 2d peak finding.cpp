#include <iostream>
using namespace std;

int* findPeakGrid(int arr[][2], int row, int column)
{
    static int result[2];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            // checking with top element
            if (i > 0)
                if (arr[i][j] < arr[i - 1][j])
                    continue;
            // checking with right element
            if (j < column - 1)
                if (arr[i][j] < arr[i][j + 1])
                    continue;
            // checking with bottom element
            if (i < row - 1)
                if (arr[i][j] < arr[i + 1][j])
                    continue;
            // checking with left element
            if (j > 0)
                if (arr[i][j] < arr[i][j - 1])
                    continue;

            result[0] = i;
            result[1] = j;
            return result;
        }
    }

    return result; // If no peak is found
}

int main()
{
    int arr[][2] = { { 9, 8 }, { 25, 67 } };
    int row = sizeof(arr) / sizeof(arr[0]);
    int column = sizeof(arr[0]) / sizeof(arr[0][0]);

    int* result = findPeakGrid(arr, row, column);

    cout << "Peak element found at index: " << result[0]
        << ", " << result[1] << endl;

    return 0;
}
