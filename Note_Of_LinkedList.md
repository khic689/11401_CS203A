# 鏈結串列 (Linked List)
## 鏈結串列是一種基礎的線性資料結構，它不依賴連續的記憶體空間，而是依靠節點內的指標來維護元素的邏輯順序。

## 1. 核心原理與特性節點 (Node)：是鏈結串列的基本組成單位。每個節點包含兩部分：資料 (Data)：儲存的實際元素。

## 2. 指標 (Pointer)：指向下一個節點的引用。動態性：大小可以在運行時動態增長或縮小，每個節點是單獨分配的。

## 3. 記憶體：節點在記憶體中是分散的 (Non-contiguous)，這可能導致 CPU 快取效能 (Cache Locality) 不如陣列。

## 4. 存取：只能循序存取。
### 要訪問第 $i$ 個元素，必須從頭節點 $(\text{Head})$ 開始遍歷 $i$ 次，時間複雜度為 $O(n)$。

## 5. 插入/刪除：如果已知目標節點的前驅節點，插入和刪除操作極為高效，僅需修改幾個指標，時間複雜度為 $O(1)$。

### 實作範例：C++ 單向鏈結串列 (Singly Linked List)在 C++ 中，我們將整個串列封裝在一個 LinkedList 類別中，head 作為其私有成員。

```
#include <iostream>

// 節點結構
class Node {
public:
    int data;
    Node* next;

    // 節點建構子
    Node(int value) : data(value), next(nullptr) {}
};

// 鏈結串列類別
class LinkedList {
private:
    Node* head; // 指向串列頭部的指標

public:
    // 建構子: 初始化一個空串列
    LinkedList() : head(nullptr) {}

    // 解構子: 釋放所有節點記憶體
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 插入到頭部 (O(1))
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head; // (Insert->next = Target)
        head = newNode;       // (Head = Insert)
    }

    // 插入到尾部 (O(n) - 需要遍歷)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* last = head;
        while (last->next != nullptr) { //
            last = last->next; //
        }
        last->next = newNode; //
    }

    // 刪除指定值的節點 (O(n))
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        // 案例 1: 目標是頭節點
        if (temp != nullptr && temp->data == value) {
            head = temp->next; // (Head = Target->next)
            delete temp;       // (free(target))
            return;
        }

        // 案例 2: 尋找目標節點 (以及其前驅節點)
        while (temp != nullptr && temp->data != value) { //
            prev = temp; //
            temp = temp->next; //
        }

        // 案例 3: 找不到目標
        if (temp == nullptr) {
            return;
        }

        // 案例 4: 找到目標 (非頭節點)
        prev->next = temp->next; // (Prev->next = Target->next)
        delete temp;             // (free(Target))
    }

    // 遍歷印出串列
    void printList() {
        Node* current = head; //
        while (current != nullptr) { //
            std::cout << current->data << " -> ";
            current = current->next; //
        }
        std::cout << "nullptr" << std::endl;
    }
};
```

## Dummy Head 節點問題：在標準實現中，對「頭節點」的插入和刪除操作總是需要特殊處理（如上 deleteNode 範例中的 "案例 1"）。
### 解決方案：使用一個「虛擬頭節點」(Dummy Head Node) 或「哨兵節點」(Sentinel Node)。
### 作法：這是在串列開頭的一個額外節點，它不儲存實際資料。head 指標永遠指向這個 dummy 節點，而 dummy 節點的 next 才指向真正的第一個元素。優勢：統一所有操作。
### 刪除第一個元素變得和刪除中間元素一樣（都是刪除 prev->next），prev 節點永遠存在（至少是 dummy 節點）。這大大簡化了程式碼邏輯。

## 鏈結串列變體：雙向鏈結串列 (Doubly Linked List)結構：
### 每個節點除了 data 和 next 指標外，還有一個 prev 指標指向前一個節點。
### 優勢：可以雙向遍歷。如果給定了目標節點 target 的指標，可以在 $O(1)$ 內刪除它（因為可以透過 target->prev 找到前驅節點）。
### 缺點：記憶體開銷更大（多一個指標），插入/刪除操作需要維護兩個指標，稍微更複雜。

// 雙向鏈結串列的節點

```
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// 雙向鏈結串列類別 (簡化實作)
class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail; //
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() { /* ... 省略 ... */ }

    // 在尾部插入
    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (tail == nullptr) { //
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; //
        }
    }

    // 在頭部插入
    void insertAtHead(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode; //
        }
    }
    
    // 雙向印出
    void printForward() {
        DNode* current = head;
        while(current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }
};
```

## 鏈結串列變體：環狀鏈結串列 (Circular Linked List)結構：最後一個節點的 next 指標不指向 NULL，而是指向第一個節點 (Head)，形成環。
### 應用：常用於實現「循環緩衝區」或作業系統中需要循環排程的任務佇列（例如 Round-Robin 演算法）。

## 反轉鏈結串列 (Reversing a Linked List)這是面試中非常經典的問題。
### 目標是將 1 -> 2 -> 3 -> nullptr 變成 3 -> 2 -> 1 -> nullptr。演算法：我們需要三個指標在串列上移動：prev (前一個節點)、current (當前節點) 和 next_temp (臨時儲存下一個節點)。
### 初始化 prev = nullptr, current = head。在 current 尚未結束時，進行迴圈：儲存 next_temp = current->next (防止斷鏈)。
### 反轉指標：current->next = prev。指標後移：prev = current, current = next_temp。迴圈結束時，prev 會指向新的頭節點。

// 假設這是 LinkedList 類別中的一個方法

```
void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next_temp = nullptr;

    while (current != nullptr) {
        // 1. 儲存下一個節點
        next_temp = current->next; 
        
        // 2. 反轉當前節點的指標
        current->next = prev;
        
        // 3. 將 prev 和 current 向後移動
        prev = current;
        current = next_temp;
    }
    
    // 4. 最後將 head 指向新的頭節點 (即舊的尾節點)
    head = prev;
}
```

## 快慢指標 (Two Pointer Technique)應用：常用於尋找中間點、偵測循環。尋找中間點：演算法：使用兩個指標 slow 和 fast，都從 head 開始。
### slow 每次移動一步。fast 每次移動兩步。
### 當 fast 到達結尾 (fast == nullptr 或 fast->next == nullptr) 時，slow 剛好會停在中間點。
### 偵測循環 (Floyd's Tortoise and Hare)：演算法：slow 每次一步，fast 每次兩步。
如果串列中有循環，fast 最終會從後面追上 slow（即 slow == fast）。
如果 fast 到達 nullptr，則無循環。
