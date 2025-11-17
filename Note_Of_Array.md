# Arrays — Notes

## 1. 基本概念

Array:
一組元素存放在連續記憶體位置，可透過索引直接存取。

特性：

固定大小

元素型別相同

常數時間存取 (O(1))

## 2. 一維、二維、三維陣列

### 一維 (1D)

```
int array[5]; // 宣告
int array[5] = {10, 20, 30, 40, 50}; // 初始化
printf("%d", array[2]); // 印出 30
```

### 二維 (2D)

```
int array2d[3][4] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12}
};
printf("%d", array2d[1][2]); // 印出 7
```

### 三維 (3D)

```
int array3d[2][3][4] = {
  { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} },
  { {13,14,15,16}, {17,18,19,20}, {21,22,23,24} }
};
printf("%d", array3d[1][2][3]); // 印出 24
```

## 3. ADT: Array

抽象資料型態 (ADT) 定義：

Objects: <index, value> 的集合

Functions:

Create(j, list) 建立 j 維陣列

Retrieve(A, i) 取得元素

Store(A, i, x) 更新元素

## 4. 靜態 vs 動態陣列
靜態陣列

大小固定 (編譯期決定)

通常配置在 stack

動態陣列

大小可在執行時決定或調整 (malloc / realloc)

配置在 heap

使用後需 free 釋放避免 memory leak

動態陣列範例

```
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));

for (int i = 0; i < n; i++) array[i] = i + 1;

n *= 2;
array = (int *) realloc(array, n * sizeof(int));
for (int i = n/2; i < n; i++) array[i] = i + 1;

free(array);
```

## 5. C++ STL

std::array: 靜態陣列，大小固定

std::vector: 動態陣列，可彈性調整大小

Aspect	std::array	std::vector
Size	固定	可變
Memory	Stack	Heap
Access Speed	最快	快，略有額外開銷
Flexibility	低	高

## 6. 排序 (Sorting)

Bubble Sort

```
for i = 1 to n-1:
  for j = 1 to n-i:
    if A[j] > A[j+1]:
      swap(A[j], A[j+1])
```

Selection Sort

```
for i = 1 to n-1:
  minIndex = i
  for j = i+1 to n:
    if A[j] < A[minIndex]:
      minIndex = j
  swap(A[i], A[minIndex])
```

Insertion Sort

```
for i = 2 to n:
  key = A[i]
  j = i-1
  while j > 0 and A[j] > key:
    A[j+1] = A[j]
    j--
  A[j+1] = key
```

## 7. 搜尋 (Searching)

Unsorted Array: Linear search (O(n))

Sorted Array:

Linear search (O(n))

Binary search (O(log n))

## 8. 常見操作 & 複雜度
Operation	Complexity	說明
Access	O(1)	直接透過 index
Update	O(1)	直接更新
Insert	O(n)	需移動元素
Delete	O(n)	需移動元素
Traverse	O(n)	全部走訪
Search	O(n) / O(log n)	無序=線性、有序=二分

## 9. 陣列型別

Integer array → int, short, long, fixed-width (int32_t…)

Character array → char

String array → char array (C-style string), 或字串陣列

## 10. 優缺點

優點

支援隨機存取 (fast access)

簡單、高效

缺點

插入刪除成本高 (需搬移元素)

靜態陣列不可調整大小

## 11. 應用

建立基礎資料結構 (stack, queue)

多維陣列處理 (matrix, 3D data)

字串操作

演算法：排序、搜尋
