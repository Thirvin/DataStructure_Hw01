//test.cpp
#include <iostream>

using namespace std;
int main()
{
    string cmd1 = "cd C:\\Users\\user\\Desktop\\codes\\lecture\\DataStructure\\HW01";
    string cmd2 = "linked_list_sum_k_n.exe";
    string cmd3 = "array_sum_k_n.exe";
    string kk[4] = {"1", "7", "63", "511"};

    system(cmd1.c_str());
    for (int i = 10; i <= 23; i++)
    {
        int n = (1 << (i));
        cout << n << "\n";
        for (int k = 0; k < 4;k ++)
            for (int j = 0; j < 10; j++)
                system((cmd2+" "+kk[k]+" "+to_string(n)).c_str());
    }
		for (int i = 10; i <= 23; i++)
    {
        int n = (1 << (i));
        cout << n << "\n";
        for (int k = 0; k < 4;k ++)
            for (int j = 0; j < 10; j++)
                system((cmd3+" "+kk[k]+" "+to_string(n)).c_str());
    }
}
/*
分別自動執行上面的test
*/