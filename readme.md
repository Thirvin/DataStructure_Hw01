# 資料結構hw01

## 目標：

探討了快取對於Linked List和Dynamic Array這兩種資料結構的影響。分別介紹這兩種資料結構，然後討論在實際應用中，快取對其性能和效能的影響。將通過分析快取的工作原理和其與資料結構操作的交互作用，來深入瞭解這個問題。最後，我們將總結我們的結論，並探討可能的優化方法。

## 資料結構介紹：

Dynamic array:

本次實驗用的Dynamic Array是C++的vector，vector 是 C++ 標準庫中的一個容器，提供動態大小調整。它支持在尾部添加或刪除元素，允許隨機存取元素。

linked list:

本次實驗用的linked list是 C++的list。C++的list是一個標準庫容器，實現了Linked list的功能。它提供了方便的方法來操作和管理Linked list，如插入、刪除和查找節點等。

## 實驗：

Object定義：

dynamic array與linked list會儲存個object，每個object包含一個int num與一個int foo[k]，其中k=1, 23-1, 26-1, 29-1。

Object產生方式：

num由0~9999的整數中隨機選擇，foo的內容不需特別指定。

比較方法：

1. 對於每個k值設定，測量上述資料結構新增$2^h$需要的時間,其中h= 10, 11, 12, …, 30。若無法測試到，請預測執行時間並解釋你的預測。
2. 在新增n個object後，計算這n個object中的num總和，並測量所需時間。
（測量的時間不包含新增object所需時間）
3. 為了降低誤差，重複上述實驗10次後取平均。

## 實驗程式碼：

Dynamic array:

```cpp
//array_test_k_n.cpp
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
```

Linked list:

```cpp
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
```

```cpp
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
```

## 實驗結果：

因為記憶體只有8G的關係，最多只能跑到n = 23，所以n = 23以後的資料都是用擬和出來的，使用的是一次函數來擬和，原因是根據複雜度理論，初始化的複雜度是$O(2^N\times K)$，當K固定時，所需要的時間會隨著$2^N$增加，所以用一次函數來擬和，sum的複雜度是$O(2^N)$，所以一樣用一次函數來擬和。

### 結果解讀

初始化：

- 根據複雜度理論vector和list的初始化的複雜度都是$O(2^N\times K)$，所以當k固定時間會隨著$2^N$增加，可以觀察出數據有這個趨勢，所以K相同時List和vector的兩條線應該要幾乎重和，然後觀察圖1可以發現，兩者也幾乎重和，所以在初始化的時候大致上符合複雜度理論，至於$2^N\times K$相同時，vector初始化時間不同，可以視為vector建構的常數和int陣列建構的常數不同的原因，同理於List。
- 除了建構的常數不同之外，另一個影響整體速度的是記憶體速度，從圖1可以看到k=511的時間增長速度最快，其原因有可能是記憶體被填滿，所以用到了虛擬記憶體，導致整體的常數又再增加。

sum :

- 同樣根據複雜度理論，vector和list把sum總和的複雜度都是$O(2^N)$，觀察表三和表四的k=1,7,63可以發現時間幾乎在同一個數量集，可是當K=515時間增加很多，推測是記憶體塞滿了，所以使用到了虛擬記憶體，所以讀取資料的常數增加了。
- 觀察圖2可以發現，當N很大的時候，List的速度遠低於Vector，最大差距時，時間約差了4倍，在k=1,7,63時N=30的速度甚至有差到10倍，已經不在同一個數量級，推測有可能是快取導致這些結果。

表格一 vector 初始化時間

| n | k=1 | k=7 | k=63 | k=511 |
| --- | --- | --- | --- | --- |
| 10 | 0.0 | 0.0 | 0.0 | 0.0 |
| 11 | 0.0 | 0.0 | 0.0 | 0.0 |
| 12 | 0.0 | 0.0 | 0.0 | 0.0 |
| 13 | 0.0 | 0.0 | 0.0 | 0.0 |
| 14 | 0.0 | 0.0 | 0.0 | 0.0 |
| 15 | 0.0 | 0.0 | 0.0 | 0.0 |
| 16 | 0.0 | 0.0 | 0.0 | 0.0 |
| 17 | 0.0 | 0.0 | 0.0 | 0.1 |
| 18 | 0.0 | 0.0 | 0.0 | 0.1 |
| 19 | 0.0 | 0.0 | 0.1 | 0.3 |
| 20 | 0.1 | 0.1 | 0.1 | 0.6 |
| 21 | 0.1 | 0.1 | 0.3 | 1.4 |
| 22 | 0.2 | 0.3 | 0.5 | 7.3 |
| 23 | 0.4 | 0.5 | 1.1 | 39.5 |
| 24 | 0.9 | 1.1 | 2.2 | 70.0 |
| 25 | 1.7 | 2.2 | 4.3 | 141.4 |
| 26 | 3.5 | 4.3 | 8.7 | 284.3 |
| 27 | 6.9 | 8.7 | 17.4 | 569.9 |
| 28 | 13.9 | 17.3 | 34.8 | 1141.2 |
| 29 | 27.7 | 34.7 | 69.6 | 2283.8 |
| 30 | 55.5 | 69.4 | 139.2 | 4569.0 |

表格二 List初始化時間

| n | k=1 | k=7 | k=63 | k=511 |
| --- | --- | --- | --- | --- |
| 10 | 0.0 | 0.0 | 0.0 | 0.0 |
| 11 | 0.0 | 0.0 | 0.0 | 0.0 |
| 12 | 0.0 | 0.0 | 0.0 | 0.0 |
| 13 | 0.0 | 0.0 | 0.0 | 0.0 |
| 14 | 0.0 | 0.0 | 0.0 | 0.0 |
| 15 | 0.0 | 0.0 | 0.0 | 0.0 |
| 16 | 0.0 | 0.0 | 0.0 | 0.0 |
| 17 | 0.0 | 0.0 | 0.0 | 0.1 |
| 18 | 0.0 | 0.0 | 0.1 | 0.6 |
| 19 | 0.1 | 0.1 | 0.1 | 1.2 |
| 20 | 0.1 | 0.1 | 0.2 | 2.0 |
| 21 | 0.2 | 0.2 | 0.4 | 1.4 |
| 22 | 0.4 | 0.5 | 0.7 | 7.3 |
| 23 | 0.8 | 0.9 | 1.5 | 33.1 |
| 24 | 1.7 | 1.9 | 3.0 | 58.0 |
| 25 | 3.3 | 3.7 | 6.0 | 117.0 |
| 26 | 6.7 | 7.5 | 12.0 | 235.0 |
| 27 | 13.3 | 14.9 | 24.1 | 470.9 |
| 28 | 26.6 | 29.8 | 48.1 | 942.8 |
| 29 | 53.2 | 59.6 | 96.2 | 1886.6 |
| 30 | 106.5 | 119.3 | 192.5 | 3774.2 |

表格三vector sum時間

| n | k=1 | k=7 | k=63 | k=511 |
| --- | --- | --- | --- | --- |
| 10 | 0.0 | 0.0 | 0.0 | 0.0 |
| 11 | 0.0 | 0.0 | 0.0 | 0.0 |
| 12 | 0.0 | 0.0 | 0.0 | 0.0 |
| 13 | 0.0 | 0.0 | 0.0 | 0.0 |
| 14 | 0.0 | 0.0 | 0.0 | 0.0 |
| 15 | 0.0 | 0.0 | 0.0 | 0.0 |
| 16 | 0.0 | 0.0 | 0.0 | 0.0 |
| 17 | 0.0 | 0.0 | 0.0 | 0.0 |
| 18 | 0.0 | 0.0 | 0.0 | 0.0 |
| 19 | 0.0 | 0.0 | 0.0 | 0.0 |
| 20 | 0.0 | 0.0 | 0.0 | 0.0 |
| 21 | 0.0 | 0.0 | 0.0 | 0.0 |
| 22 | 0.0 | 0.0 | 0.0 | 0.2 |
| 23 | 0.0 | 0.0 | 0.0 | 1.0 |
| 24 | 0.0 | 0.0 | 0.0 | 1.7 |
| 25 | 0.1 | 0.1 | 0.1 | 3.4 |
| 26 | 0.2 | 0.2 | 0.2 | 6.9 |
| 27 | 0.3 | 0.3 | 0.4 | 13.8 |
| 28 | 0.7 | 0.7 | 0.8 | 27.7 |
| 29 | 1.4 | 1.4 | 1.5 | 55.5 |
| 30 | 2.7 | 2.8 | 3.1 | 111.0 |

表格四List sum時間

| n | k=1 | k=7 | k=63 | k=511 |
| --- | --- | --- | --- | --- |
| 10 | 0.0 | 0.0 | 0.0 | 0.0 |
| 11 | 0.0 | 0.0 | 0.0 | 0.0 |
| 12 | 0.0 | 0.0 | 0.0 | 0.0 |
| 13 | 0.0 | 0.0 | 0.0 | 0.0 |
| 14 | 0.0 | 0.0 | 0.0 | 0.0 |
| 15 | 0.0 | 0.0 | 0.0 | 0.0 |
| 16 | 0.0 | 0.0 | 0.0 | 0.0 |
| 17 | 0.0 | 0.0 | 0.0 | 0.0 |
| 18 | 0.0 | 0.0 | 0.0 | 0.0 |
| 19 | 0.0 | 0.0 | 0.0 | 0.0 |
| 20 | 0.0 | 0.0 | 0.0 | 0.0 |
| 21 | 0.1 | 0.1 | 0.0 | 0.1 |
| 22 | 0.1 | 0.1 | 0.1 | 0.8 |
| 23 | 0.2 | 0.3 | 0.2 | 4.3 |
| 24 | 0.3 | 0.6 | 0.4 | 7.5 |
| 25 | 0.7 | 1.1 | 0.7 | 15.1 |
| 26 | 1.4 | 2.2 | 1.4 | 30.3 |
| 27 | 2.7 | 4.5 | 2.8 | 60.8 |
| 28 | 5.4 | 8.9 | 5.7 | 121.8 |
| 29 | 10.9 | 17.8 | 11.4 | 243.8 |
| 30 | 21.8 | 35.6 | 22.7 | 487.8 |

圖表1： 不同k對vector和list對不同大小n初始化所需的時間。

![Untitled](%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8Bhw01%201a52322098ad4219bc50174b6ef14be1/Untitled.png)

圖表2： 不同k對vector和list對不同大小n把num總和所需的時間。

![Untitled](%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8Bhw01%201a52322098ad4219bc50174b6ef14be1/Untitled%201.png)

## 快取實驗：

### 目的

發現圖表2的趨勢差異，於是想知道vector和list兩者在快取上的不同表現，於是又寫了兩支程式測試這兩個資料結構在快取上的表現。

實驗和前面一樣不過這次不是測試時間，是測試cache hits和 cache misses。

當我們在讀取變數的時候，CPU會先檢查快取，如果在快取裡面找到了要的那段記憶體位置，就算做一次cache hits，反之，cache misses，然後CPU會把帶有變數的某段連續記憶體拉進快取裡面，cache hits 和 cache misses相比，cache misses要花的時間會更多，因為要把記憶體拉近快取裡面，所以我打算測試，vector和list的cache misses，來判斷cache是否為兩者速度差異的原因。

### 實驗結果

可以發現當整體資料量到一定程度之後，list的Cache misses就比vector的cache misses來的要多，特別是當K=515時，最大有差到兩個數量級。

當資料量大到一定程度之後，cache misses開始出現差距的原因可能是cache已經被填滿了，然後list的記憶體位置不是連續的，所以導致可能每次都要把連續記憶體拉進cache，所以會更容易cache misses，為了進一步，確認是否為連續記憶體導致的cache misses，進行了下一個實驗。

圖3 vector 和 list的 Cache misses

![Untitled](%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8Bhw01%201a52322098ad4219bc50174b6ef14be1/Untitled%202.png)

### 

## optmized list實驗

## 目的

確認list和vector的cache misses的不同，是否為連續記憶體這個性質導致的。

### optmized list

一般的linked list的記憶體位置是不連續的，為了解決這個問題，我實做了一個簡易的連續記憶體空間的linked list，我預先開好一個vector，用來分配一段連續記憶體，然後再自己實作linked list，這樣的linked list裡面就是連續的記憶體區段了。

### 程式碼

```cpp
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
    f.open("optmized_linked_list\\"+kk + "_" + nn+"_initial",std::ios_base::app);

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
    for (auto it = head; it != nullptr;it = it->next)
        sum += it->num;
	cout<<sum<<"\n";
    f << (double(clock())-double(begin)) / CLOCKS_PER_SEC<<endl;

}
```

### 實驗結果

- 根據圖4可以驚奇的發現optmized list比vector還快！可能原因有兩個，cache misses下降或是因為optmized list是自己實作的，所以在某些操作上常數會比STL容器還要低一點。
- 再根據圖5可以發現optmized list的cache misses已經比一般的list低一個數量集了，整體和vector差不多
- 可以發現optmized list的cache misses明顯下降，所以可以得知兩個結論
    - 1.不連續的記憶體會導致cache misses增加
    - 2.cache 的增加會導致 traversal的時間增加

圖4 sum time in different k with optmized list

![Untitled](%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8Bhw01%201a52322098ad4219bc50174b6ef14be1/Untitled%203.png)

圖5 cache misses in different k with optmized list

![Untitled](%E8%B3%87%E6%96%99%E7%B5%90%E6%A7%8Bhw01%201a52322098ad4219bc50174b6ef14be1/Untitled%204.png)

## 結論

這次的實驗主要探討了快取對於Linked List和Dynamic Array（這裡使用C++的vector）這兩種資料結構的影響。

首先，觀察到初始化的時間隨著資料量的增加而增長，並在較大的資料集下開始出現差異。這符合複雜度理論，因為初始化的複雜度隨著資料量的增加而增加。另外，記憶體的速度也在某些情況下影響了初始化的時間，當記憶體被填滿時，可能需要使用虛擬記憶體，導致更長的初始化時間。

接下來，我們觀察了計算num總和所需的時間。在這方面，我們注意到Dynamic Array（vector）通常比Linked List（list）快，特別是當資料量較大時。這可能是由於快取（Cache）的表現差異所導致的。讀取來自Cache的資料比來自主記憶體的資料更快。當資料不連續存儲時，Cache hits可能較低，導致Cache misses的情況增加，進而影響了性能。

為了更深入瞭解這一點，進一步測試了Cache hits和Cache misses。結果顯示，當資料量變大時，List的Cache misses明顯比Vector高。這表明List在存取資料時可能較少地使用Cache，導致性能下降。

為了解決Cache misses的問題，實做了一個優化的Linked List，即Optimized List。這個優化List在初始化時使用了連續的記憶體空間，進一步降低了Cache misses。結果顯示，Optimized List的性能明顯優於普通List，甚至在某些情況下超越了Vector，這證實了Cache misses和記憶體存儲的連續性之間的關聯。

## 心得

這次的實驗中，面臨了兩個主要困難。首先，我們遇到了電腦記憶體不足。由於記憶體有限，我們只能處理有限量的資料，這限制了實驗的規模。在處理大規模資料時，我們需要更多的記憶體，在沒辦法提升記憶體的情況下，只能用擬和的方式去預測資料，這使得實驗的變因增加。而且還需要仔細控制資料結構的大小，以確保能夠在有限的記憶體空間內運行，不然電腦會crash。

在來，需要測量Cache misses，一開始沒想到要測量cache misses，是去查了很多資料之後才發現這個指標，然後也找了很多工具來嘗試測量，包括likwid、AmdProf和perf，最後perf是唯一派上用場的。

總的來說，這次作業讓我學到很多東西，如何想實驗、如何測數據以及如何去設計程式用來完成實驗，最重要的是利用網路上的資源來學習如何利用工具。