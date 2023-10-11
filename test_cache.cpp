#include <iostream>

using namespace std;
int main()
{
    string kk[4] = {"1", "7", "63", "511"};
	string cmd2="perf stat -o ",cmd3=" -e cache-misses -e cache-references ./array_sum_k_n";
    string cmd4="perf stat -o ",cmd5=" -e cache-misses -e cache-references ./optimize_linked_list_k_n ";

    for (int i = 10; i <= 21; i++)
    {
        int n = (1 << (i));
        cout << n << "\n";
        for (int k = 0; k < 4;k ++)
            for (int j = 0; j < 10; j++)
            {
                system((cmd2+" "+kk[k]+"_"+to_string(n)+cmd3+kk[k]+" "+to_string(n)).c_str());
            }
    }
    for (int i = 10; i <= 21; i++)
    {
        int n = (1 << (i));
        cout << n << "\n";
        for (int k = 0; k < 4;k ++)
            for (int j = 0; j < 10; j++)
            {
                system((cmd4+" "+kk[k]+"_"+to_string(n)+cmd5+kk[k]+" "+to_string(n)).c_str());
            }
    }
}
