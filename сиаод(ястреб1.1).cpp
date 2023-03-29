#include <iostream>
using namespace std;


int main() {
    int N,M;
    cin >> N >> M;
    int **arr = new int*[N];
    for ( int i =0;i < N;i++){
        arr[i] = new int[M];
        for(int j =0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    int max_len = -1;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        int len = 1;
        int max_row_len = -1;
        for (int j = 0; j < M-1; j++) {
            if (arr[i][j] == arr[i][j+1]) {
                len++;
            } else {
                if (len > max_row_len) {
                    max_row_len = len;
                }
                len = 1;
            }
        }
        if (len > max_row_len) {
            max_row_len = len;
        }
        if (max_row_len > max_len) {
            max_len = max_row_len;
            max_index = i;
        }
    }

    cout << "The row number with the longest series of identical elements is: " << max_index << endl;

    return 0;
}