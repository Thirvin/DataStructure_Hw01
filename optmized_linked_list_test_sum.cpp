#include <iostream>

using namespace std;
int main()
{
    string cmd2 = "optimize_linked_list_k_n.exe";
    string kk[4] = {"1", "7", "63", "511"};

    for (int i = 10; i <= 23; i++)
    {
        int n = (1 << (i));
        cout << n << "\n";
        for (int k = 0; k < 4;k ++)
            for (int j = 0; j < 10; j++)
                system((cmd2+" "+kk[k]+" "+to_string(n)).c_str());
    }
}