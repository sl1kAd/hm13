#include <iostream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");

    const int n = 12;

    int* arr = new int[n] { 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };

    for (int i = 0; i < n; i++) 
    {
        for (int j = n - 1; j > i; j--) 
        {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "Вывод:\n";

    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}