//optimize_linked_list_k_n.cpp
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
    node *next = nullptr;
    int num;
    int *f;
		node()
		{
				num = 1;
		}
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
    f.open("optmized_linked_list\\"+kk + "_" + nn+"_sum",std::ios_base::app);

    list<node> lis;
    vector<node> store(n);
    node *head = &store[0];
    head->num = rand() % 10000;
    head->f = new int[k];

    for (int i = 1; i < n;i ++)
    {

        head->next = &store[i];
        head = head->next;
        head->num = rand() % 10000;
        head->f = new int[k];
    }
    clock_t begin = clock();
	long long sum = 0;
    for (auto it = head; it != nullptr;it = it->next){
        sum += it->num;
    }

	cout<<sum<<"\n";
    f << (double(clock())-double(begin)) / CLOCKS_PER_SEC<<endl;

}