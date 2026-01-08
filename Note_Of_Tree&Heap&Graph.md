# 樹 (Trees)
## 1. 基礎概念

樹 (Tree) 是一種非線性的分層結構，由節點 (Node) 與邊 (Edge) 組成 。它具有唯一的根節點 (Root)，且沒有任何循環 (Cycle) 。

## 2. 專業術語 

```
葉節點 (Leaf)：沒有子節點的節點。

高度 (Height)：從該節點到最遠葉節點的最長路徑。

深度 (Depth)：從根節點到該節點的路徑長度。

分支度 (Degree/Fan-out)：一個節點擁有的子節點數量。
```

## 3. 二元搜尋樹 (Binary Search Tree, BST) 

對於每個節點，左子樹所有節點值均小於父節點，右子樹所有節點值均大於父節點 。

```
遍歷 (Traversal) ：

前序 (Pre-order)：根 -> 左 -> 右。

中序 (In-order)：左 -> 根 -> 右（會得到排序好的數列）。

後序 (Post-order)：左 -> 右 -> 根。

層序 (Level-order)：使用佇列按層訪問 。
```

## 4. 平衡樹與 AVL 樹

如果樹變得過於歪斜 (Skewed)，搜尋效能會從 $O(\log n)$ 退化到 $O(n)$a。
AVL 樹要求任何節點的左右子樹高度差不超過 1，透過旋轉操作維持平衡。

範例程式碼 (C++)
```
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}
```

# 堆積 (Heaps)

## 1. 定義與性質

堆積 (Heap) 是一種完全二元樹 (Complete Binary Tree)，滿足特定的堆積性質 ：
最大堆積 (Max Heap)：父節點的值 $\ge$ 子節點的值，根節點為最大值 。
最小堆積 (Min Heap)：父節點的值 $\le$ 子節點的值，根節點為最小值 。

## 2. 儲存方式 

由於是完全二元樹，最有效率的儲存方式是使用 陣列 (Array) 。對於索引 i 的節點：

左小孩索引 = 2*i + 1

右小孩索引 = 2*i + 2

父節點索引 = (i-1) / 2

## 3. 操作邏輯與時間複雜度

```
插入 (Insert)：加入到最後一個葉節點，然後進行 Sift-up (向上篩選)。複雜度：$O(\log n)$。
移除最大值 (Extract-Max)：將最後一個葉節點換到根，然後進行 Sift-down (向下篩選)。複雜度：$O(\log n)$。
建立堆積 (Build-Heap)：從最後一個非葉子節點開始 Heapify。複雜度：$O(n)$。
```

範例程式碼 (C++)
```
#include <algorithm>
#include <vector>

class MaxHeap {
    std::vector<int> heap;
    void siftUp(int i) {
        while (i > 0 && heap[(i-1)/2] < heap[i]) {
            std::swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }
public:
    void push(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }
};
```

# 圖 (Graphs)
## 1. 圖的組成
  圖 $G=(V, E)$ 由頂點集 (Vertices) 與邊集 (Edges) 組成。
  有向圖 (Directed) vs 無向圖 (Undirected)。
  加權圖 (Weighted)：每條邊有對應的權重（如距離)。

## 2. 表示方法

鄰接矩陣 (Adjacency Matrix)：使用二維陣列 $V \times V$。適合稠密圖，搜尋邊的時間為 $O(1)$，但空間為 $O(V^2)$。
鄰接串列 (Adjacency List)：每個節點維護一個鄰居清單。適合稀疏圖，節省空間 $O(V+E)$。

## 3. 搜尋演算法 

廣度優先搜尋 (BFS) ：使用 佇列 (Queue) 。由近到遠層層搜尋，適合找尋無加權圖的最短路徑。

深度優先搜尋 (DFS) ：使用 堆疊 (Stack) 或遞迴。盡可能深入探索路徑，適合拓撲排序或找尋連通分量 。

關鍵： 圖搜尋必須使用 visited[] 陣列來防止循環路徑導致死循環 。

範例程式碼 (C++ - BFS)

```
#include <vector>
#include <queue>

void BFS(int startNode, std::vector<std::vector<int>>& adj) {
    int V = adj.size();
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```
































