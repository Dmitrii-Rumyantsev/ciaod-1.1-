#include <iostream>

using  namespace std;

int main()
{
    system("chcp 65001");
    int n, key, i = 0;
    cout << "Введите количество элементов массива и значение которое необходимо удалить." << endl;
    cin >> n >> key;
    int * x = new int[n];
    cout << "Введите элементы массива.\n";
    for (int j = 0; j < n;j++) {
        cin >> x[j];
    }
    int count= 0;
    while (i < n) && count++) {
        count++;
        if (x[i] == key){
            count++;
            for(int j = i; j < n - 1 ; j++){
                cout << j << " ";
                x[j] = x[j+1];
                count++;
            }
            count++;
            n--;
        }
        else{
            i++;
        }
        count++;
    }
    count++;
    for(int j = 0; j < n;j++)
    {
        cout << x[j] << " ";
    }
    delete [] x;

    cout << endl << "Подсчет суммарного количества выполненных сравнений: " << count;
    return 0;
}
