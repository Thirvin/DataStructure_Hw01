//linked_list_test_k_n.cpp
#include<iostream>
#include<vector>
#include<ctime>
#include<list>
#include<random>
#include<algorithm>
#include<fstream>
using namespace std;
struct node
{
    int num;
    int *f;
};

int main(int argc, char *argv[])
{
    fstream f;
    int k, n;
    if(argc != 3 )
        return 0;

    k = stoi(argv[1]);
    n = stoi(argv[2]);
    string kk(argv[1]), nn(argv[2]);

    f.open("linked_list\\"+kk + "_" + nn+"_initial",std::ios_base::app);
    clock_t begin = clock();
    list<node> lis;

    for (int i = 0; i < n;i ++)
    {
        lis.push_back(node{rand()%10000,new int[k]});
    }
    f << (double(clock())-double(begin)) / CLOCKS_PER_SEC<<endl;
    f.close();



    f.open("linked_list\\"+kk + "_" + nn+"_sum",std::ios_base::app);
    begin = clock();
	long long sum = 0;
	for(auto it : lis)
		sum += it.num;
	cout<<sum<<"\n";
    f << (double(clock())-double(begin)) / CLOCKS_PER_SEC<<endl;
    f.close();
}
/*
創建一個list，其中每個元素都包含一個整數 num 和一個指向int array的pointer foo。

將 num 成員初始化為一個隨機整數值，同時為 foo 成員分配一個包含 k 個整數的array。

記錄初始化整個list的時間。

計算list中所有 num 的總和，並將該總和輸出。

記錄計算總和的時間。
*/