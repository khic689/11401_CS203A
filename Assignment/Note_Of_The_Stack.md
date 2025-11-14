## 堆疊 (Stack)資料結構類別： 線性資料結構 (Linear Data Structure)核心原則： 

LIFO (Last-In-First-Out, 後進先出)堆疊（Stack）是一種基礎且重要的抽象資料類型（ADT），其嚴格的存取規則使其在系統級別和應用程式級別都有廣泛的應用。

### 1. 定義與核心原則堆疊的結構限制了元素的插入和移除只能在同一位置進行。核心特性操作位置： 元素的添加和移除只發生在堆疊的最高位置，稱為 頂部（Top）。

LIFO 行為：最後一個進入堆疊的元素，將會是第一個被取出。比喻： 一疊盤子，最後放上去的盤子必須最先被拿走。實際應用場景堆疊在電腦科學中扮演著關鍵角色：函式呼叫機制（Call Stack）： 追蹤程式執行中函式的呼叫和返回順序。
遞迴（Recursion）： 系統使用隱含的堆疊來管理遞迴呼叫的狀態。撤銷/重做（Undo/Redo）： 在編輯器中實現操作歷史的記錄和回復。表達式求值與轉換： 如將中序表達式轉換為後序表達式（Postfix）。
回溯（Backtracking）： 如深度優先搜尋（DFS）和迷宮求解。

### 2. 堆疊 ADT 核心操作堆疊 ADT 是一個有限的有序列表。所有核心操作的時間複雜度都極為高效，為 $O(1)$。操作 (Operation)描述 (Description)時間複雜度 (Complexity)前置條件 (Precondition)Push(item)將元素插入堆疊的頂部。

$O(1)$需檢查是否 IsFull() (僅限陣列實作)。Pop()移除並返回堆疊頂部的元素。$O(1)$需檢查是否 IsEmpty()。Peek() / Top()檢視頂部元素，但不移除。$O(1)$需檢查是否 IsEmpty()。IsFull()檢查堆疊是否已滿。$O(1)$(固定大小的實作)IsEmpty()檢查堆疊是否為空。$O(1)$範例：Push 與 Pop 序列假設初始堆疊為空：操作堆疊內容 (從底到頂)Top 指向Push(A)AAPush(B)A, BBPush(C)A, B, CCPop()A, BBPop()AAPush(D)A, DD3.3 
實作方式與考量堆疊主要有兩種高效的實作方法：

### 3.1 基於陣列 (Array-based Implementation)關鍵變數： 一個固定大小的陣列 stack[MAX_SIZE] 和一個整數變數 top 作為索引。優點： 簡單，且具有快取優勢（Cache Locality）。Push/Pop 機制： 通過增減 top 索引來進行。C// 陣列實作偽代碼

```
void push(int item) {
    if (top == MAX_SIZE - 1) {
        // 處理 Stack Overflow
        return;
    }
    top = top + 1;
    stack[top] = item;
}

int pop() {
    if (top == -1) {
        // 處理 Stack Underflow
        return ERROR_VALUE;
    }
    int item = stack[top];
    top = top - 1;
    return item;
}
```

### 3.2 基於鏈結串列 (Linked List-based Implementation)關鍵變數： 一個指標 Node* top，永遠指向串列的頭部。優點： 動態大小，沒有固定的容量限制（避免溢位問題）。Push/Pop 機制： 將新的節點插在頭部（Push），或移除頭部節點（Pop）。C// 鏈結串列實作偽代碼 (假設 Node 結構已定義)

```
void push(int item) {
    Node* newNode = createNode(item);
    newNode->next = top; // 新節點指向舊的 Top
    top = newNode;       // 更新 Top 為新節點
}

int pop() {
    if (top == NULL) {
        // 處理 Stack Underflow
        return ERROR_VALUE;
    }
    Node* temp = top;
    int item = temp->data;
    top = top->next;     // Top 移至下一個節點
    free(temp);          // 釋放原 Top 節點記憶體
    return item;
}
```

實作選擇對比特性陣列實作鏈結串列實作容量限制固定動態（理論上無限）溢位 (Overflow)需檢查，可能發生不需檢查，除非記憶體耗盡空間效率較高（無指標開銷）較低（每個節點多一個指標）記憶體管理靜態分配或一次性分配動態分配（malloc/free）
