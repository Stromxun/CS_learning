### 线性表综合应用题

##### 01
```cpp
  int delete_min_value(int nums[], int& length){
    if(length == 0) return -1;
    int minm = nums[0], k = 0;
    for(int i = 1; i < length; i++){
        if(minm > nums[i]){
            minm = nums[i];
            k = i;
        }
    }
    nums[k] = nums[length - 1], nums[length - 1] = 0, length--;
    return minm;
}
```

##### 02
```cpp
void reverse_List(int nums[], int& length){
    if(length == 0) return;
    int temp;
    for(int i = 0; i < length / 2; i++){
        temp = nums[i];
        nums[i] = nums[length - i - 1];
        nums[length - i - 1] = temp;
    }
}

```
