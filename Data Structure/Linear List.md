### 线性表的实现

##### 顺序表

* 顺序存储
``` cpp
template<typename T>
class SqList{
    public:
    
    void InitList(){ // 初始化表
        memset(data, 0, sizeof(data));
        length = 0;
    }

    int Length(){ // 返回表的长度 
        return this->Length;
    }

    T LocateElem(T e){  // 按值查找操作
        for(int i = 0; i < length; i++){
            if(e == data[i]) return i;
        }
        return -1; // 查无此值
    }

    T GetElem(int i){ // 根据下标查找
        if(i < 0 || i >= length) return -1;
        return data[i];
    }

    bool ListInsert(int i, T e){ // 插入操作
        if(i < 1 || i > length + 1) return false;
        if(length >= N) return false;
        for(int j = length; j >= i; j--){
            data[j] = data[j - 1];
        }
        data[i - 1] = e;
        length ++;
        return true;
    }

    bool ListDelete(int i){ // 删除操作
        if(i < 1 || i > length) return false;
        e = data[i - 1];
        for(int j = i; j < length; j++){
            data[j - 1] = data[j];
        }
        length --;
        return true;
    }

    void PrintList(){ //打印顺序表
        for(int i = 0; i < length; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void Empty(){ // 判空
        return length == 0;
    }

    void DestroyList(){ // 销毁操作
        InitList()
    }

    private:
    const int N = 50;
    T data[N];
    size_t length;

};
```
