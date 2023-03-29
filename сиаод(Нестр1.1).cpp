#include <iostream>
using namespace std;


int main() {
    int n, m;
    cout << "Введите n и m";
    cin >> n >> m;
    int **arr = new int*[n];
    for ( int i =0;i < n;i++){
        arr[i] = new int[m];
        for(int j =0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int max_sum = -1;
    int max_index = -1;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            if (j-i >= m) {
                break;
            }
            sum += arr[j][j-i];
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_index = i;
        }
    }

    cout << "The ascending diagonal with the maximum sum is: ";
    for (int i = max_index; i < n; i++) {
        if (i-max_index >= m) {
            break;
        }
        cout << arr[i][i-max_index] << " ";
    }
    cout << endl;
    cout << max_sum;
    return 0;
}