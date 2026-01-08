1. 核心定義與限制

堆疊 (Stack)：一種線性的資料結構，遵循「後進先出」(Last-In-First-Out, LIFO) 原則 。想像成一疊盤子，你只能從頂部放入或取出 。




佇列 (Queue)：一種線性的資料結構，遵循「先進先出」(First-In-First-Out, FIFO) 原則 。如同排隊買票，先排的人先得到服務 。




2. 視覺化結構 (Visualization)

堆疊：只有一個開口（Top），所有的插入 (Push) 與刪除 (Pop) 都在此端進行 。


佇列：有兩個端點，後端 (Rear) 負責插入 (Enqueue)，前端 (Front) 負責刪除 (Dequeue) 。



3. 操作與演算法邏輯
堆疊操作 (Stack ADT) 

Push(item)：將元素壓入頂端。

Pop()：移除並回傳頂端元素。

IsEmpty()：檢查堆疊是否為空。

IsFull()：檢查是否超過最大容量 MAX_SIZE。

佇列操作 (Queue ADT) 

AddQ(item)：在 Rear 端加入元素。

DeleteQ()：在 Front 端移除元素。


環狀佇列 (Circular Queue)：利用模數運算 (%) 讓陣列空間循環使用，解決空間浪費問題 。

|特性 |陣列實作 (Array)|鏈結串列實作 (Linked List)|
|-----|---------------|-------------------------|
|記憶體|預先分配可能浪費空間 |動態分配指標有額外開銷 |
|溢位處理|需檢查 MAX_SIZE |除非記憶體耗盡否則不溢位 |
|效能|O(1)但調整大小成本高 |O(1)但每一步需分配記憶體 |

```
#include <iostream>
#include <vector>

using namespace std;

// 陣列實作的 Stack
class Stack {
private:
    int top;
    int maxSize;
    int* stackArray;
public:
    Stack(int size) : maxSize(size), top(-1) {
        stackArray = new int[maxSize];
    }
    bool isFull() { return top == maxSize - 1; }
    bool isEmpty() { return top == -1; }
    void push(int val) {
        if (isFull()) return;
        stackArray[++top] = val; // 先遞增再賦值
    }
    int pop() {
        if (isEmpty()) return -1;
        return stackArray[top--]; // 先回傳再遞減
    }
};

int main() {
    Stack s(5);
    s.push(10); s.push(20);
    cout << "Popped: " << s.pop() << endl; // 20
    return 0;
}
```


