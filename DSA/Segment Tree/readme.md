## Road map

- [x] Đổi / gán giá trị 1 vị trí

- [x] Đổi / gán giá trị 1 đoạn (ban đầu là 0) + lazy		

- [x] Đổi / gán giá trị 1 đoạn (ban đầu là array) + lazy	


## Build:
```cpp
void build(int id, int l, int r)
{
    if (l == r)
    {
        node[id].val = a[l];
        node[id].lazy = a[l];
        return;
    }
    int mid = l + r >> 1;
    down(id);
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    node[id].val = max(node[2 * id].val, node[2 * id + 1].val);
}
```
