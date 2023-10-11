#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
struct object
{
    int num;
    int *foo;
    object()
    {
        num = 1;
    }
};

int main(int argc, char *argv[])
{
    fstream f;
    int k, n;
    if (argc != 3)
        return 0;

    k = stoi(argv[1]);
    n = stoi(argv[2]);
    string kk(argv[1]), nn(argv[2]);
    vector<object> arr(n);

    f.open("array\\" + kk + "_" + nn + "_initial", std::ios_base::app);

    clock_t begin = clock();

    for (int i = 0; i < n; i++)
    {
        arr[i].num = rand() % 10000;
        arr[i].foo = new int[k];
    }
    f << (double(clock()) - double(begin)) / CLOCKS_PER_SEC << endl;
    f.close();




    f.open("array\\" + kk + "_" + nn + "_sum", std::ios_base::app);
    begin = clock();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i].num;
    }
    cout << sum << "\n";
    f << (double(clock()) - double(begin)) / CLOCKS_PER_SEC << endl;
    f.close();
}
/*
創建一個vector，其中每個元素都包含一個整數 num 和一個指向整數數組的pointer foo。

將 num 成員初始化為一個隨機整數值，同時為 foo 成員分配一個包含 k 個整數的array。

記錄初始化整個vector的時間。

計算vector中所有 num 的總和，並將該總和輸出。

記錄計算總和的時間。
*/