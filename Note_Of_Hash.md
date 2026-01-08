# 1. 定義與目標
  雜湊 (Hashing) 是透過雜湊函數 (Hash Function) 將鍵值 (Key) 轉換為陣列索引，以達成平均常數時間 $O(1)$ 的存取。
  其主要目的是在不掃描整個資料集的情況下快速定位資料。

# 2. 雜湊函數 (Hash Functions) 

  除法取餘數 (Division Method)：h(k) = k mod m。建議 m 為質數 。

  折疊法 (Folding Method)：將 Key 切段相加（如 123456 -> 12+34+56）。

  乘法運算 (Multiplication Method)：利用小數部分乘以 m
  # 3. 衝突解決策略 (Collision Handling) 

  當兩個不同的 Key 雜湊到相同索引時會發生「衝突」 。

  ```
  鏈結法 (Chaining)：在每個桶子 (Bucket) 維護一個鏈結串列 。
  
  開放定址法 (Open Addressing)：

  線性探測 (Linear Probing)：順序尋找下一個空位。缺點是容易產生「主要叢集」 (Primary Clustering) 。

  二次探測 (Quadratic Probing)：以平方間距尋找空位，減少叢集 。

  雙重雜湊 (Double Hashing)：使用第二個雜湊函數決定間距 。
  ```

# 4. 複雜度分析
  平均情況：插入、刪除、搜尋均為 $O(1)$。
  最壞情況：當所有元素發生衝突時，退化為 $O(n)$。
  裝載因子 (Load Factor)：$\alpha = n/m$（元素個數 / 雜湊表大小），通常建議保持 $\alpha < 0.75$。

```
#include <iostream>
#include <list>
#include <vector>

class HashTable {
    int BUCKET; 
    std::vector<std::list<int>> table;
public:
    HashTable(int b) : BUCKET(b), table(b) {}
    int hashFunction(int x) { return x % BUCKET; }
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            std::cout << i;
            for (auto x : table[i]) std::cout << " --> " << x;
            std::cout << std::endl;
        }
    }
};
```
