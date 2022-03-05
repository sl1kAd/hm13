// ConsoleApplication36.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> used, paths;

vector<vector<int>> graph;
void graphs(int v) {
    used[v] = true;
    paths.push_back(v);
    for (int to : graph[v]) {
        if (!used[to]) {
            graphs(to);
            paths.push_back(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    graph = vector<vector<int>>(n + 1);
    used = vector<int>(n + 1, false);

    for (int i = 0; i < m; i++) {
        int f = 0, t = 0;
        cin >> f >> t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }


    graphs(v);

    cout << paths.size() << '\n';
    for (int v : paths) {
        cout << v << ' ';
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
