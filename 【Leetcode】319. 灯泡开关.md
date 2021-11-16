# 【Leetcode】319. 灯泡开关

## 题目描述

初始时有 n 个灯泡处于关闭状态。第一轮，你将会打开所有灯泡。接下来的第二轮，你将会每两个灯泡关闭一个。

第三轮，你每三个灯泡就切换一个灯泡的开关（即，打开变关闭，关闭变打开）。第 i 轮，你每 i 个灯泡就切换一个灯泡的开关。直到第 n 轮，你只需要切换最后一个灯泡的开关。

找出并返回 n 轮后有多少个亮着的灯泡。

## 基本思路

## 代码

```cpp
int bulbSwitch(int n){
    if (n <= 0)
        return 0;
    int *nums = (int*) malloc (n * sizeof(int));
    memset(nums, 0, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ( (i + 1) % j == 0)
                nums[i]++;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 != 0)
            sum++;
    }
    return sum;
}
```

超时

```cpp
int bulbSwitch(int n){
    if (n <= 0)
        return 0;
    int sum = 0;
    for (int i = 1; i * i < n;i++)
        sum = i;
    sum -= 1;
    return sum;
}
```

## 总结

