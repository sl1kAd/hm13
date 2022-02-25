#include <iostream>
#include <stack> 
#include <string>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    short int n;

    int mas[7][7];

    string input[7];

    do 
    {
        cout << "Количество вершин: ";

        cin >> n;

    } 
    
    while ((n < 2) || (n > 7));

    cout << "Списки смежности вершин\n";

    cout << "Замечания:\n";

    cout << "По концу вводу списка нажимается Enter\n";

    cout << "Список задаётся в порядке возрастания номера смежной вершины\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) 
    {
        cout << "Для " << i + 1 << " вершины:" << endl;

        getline(cin, input[i]);

        for (int j = 0; j < input[i].length(); j++) 
        {
            if (input[i][j] == ' ') 
            {
                input[i].erase(j, 1);

                j--;
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            mas[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < input[i].length(); j++) 
        {
            mas[i][static_cast<int>(input[i][j]) - 48 - 1] = 1;
        }
    }

 
    stack <int> Stack;

    int nodes[7];

    for (int i = 0; i < n; i++) nodes[i] = 0;

    Stack.push(0);

    while (!Stack.empty())
    { 
        int node = Stack.top(); 

        Stack.pop();
        if (nodes[node] == 2) continue;

        nodes[node] = 2;

        for (int j = n - 1; j >= 0; j--)
        { 
            if (mas[node][j] == 1 && nodes[j] != 2)
            { 
                Stack.push(j);

                nodes[j] = 1; 
            }
        }

        cout << node + 1; 
    }
    return 0;
}