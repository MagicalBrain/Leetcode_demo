# 【leetcode】71.简化路径（中等）

## 题目描述

给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。


示例 1：

输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。 

示例 2：

输入：path = "/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。

示例 3：

输入：path = "/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。

示例 4：

输入：path = "/a/./b/../../c/"
输出："/c"
 

提示：

1 <= path.length <= 3000
path 由英文字母，数字，'.'，'/' 或 '_' 组成。
path 是一个有效的 Unix 风格绝对路径。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path

## 基本思路

## 代码

```c++
char * simplifyPath(char * path){
    char *stack[100];
    int size = 0;
    for (char *s = strtok(path, "/"); s; s = strtok(NULL, "/")) {
        if (strcmp(s, ".") == 0) {
            //do nothing
        } else if (strcmp(s, "..") == 0) {
            //back 
            size = fmax(0, size-1);
        } else {
            stack[size++] = s;
        }
    }
    if (size == 0) return "/";
    char *res = calloc(1000, sizeof(char));
    for (int i=0; i<size; ++i) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    return res;
}
```

作者：dong-feng-32
链接：https://leetcode-cn.com/problems/simplify-path/solution/cjian-dan-yi-dong-by-dong-feng-32/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

其实没啥的，就是利用了strtok这个函数

## 总结

## 测试程序

```c++
/*
 * 【leetcode】71题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * simplifyPath(char * path){
    char *s = (char*) malloc(3000 * sizeof(char));
    int top = 0;    //栈的栈顶下标
    int cnt = 0;    //字符串遍历计数
    int length = 0, length_t = 0;     //当前目录的长度
    int flag = 0;

    if (NULL == path)
    {
        path = "/";
        return path;
    }   
    else
    {
        while (path[cnt] != '\0')
        {
            s[top++] = path[cnt++];
            if (path[cnt] == '.')
                length_t++;
            else if (path[cnt] == '/')
            {
                if (length == 0 && length_t == 1)    //处理‘.’
                        flag = 1;
                if (length == 0 && length_t == 2)  //处理‘..’
                        flag = 2; 
                if (s[top - 1] == '/')  //处理'//'
                    flag = 3;
                
                switch (flag)
                {
                case 1:
                    top -= 2;
                    break;
                case 2:
                    top -= 3;
                    if (top != 0)
                    {
                        while (s[top - 1] != '/')
                            top--;
                        top -= 1;
                    }
                    break;
                case 3:
                    top--;
                    break;
                default:
                    break;
                }
                flag = 0;
                length_t = 0;
                length = 0;
            }
            else
            {
                length++;
            }
            
        }
        if (s[top - 1] == '/' && top - 1 != 0)
            s[top - 1] = '\0';
        else 
            s[top] = '\0';
    }

    return s;
}

int main()
{
    char str[3000];
    char *s = str;
    char *re;
    puts("请输入测试路径：");
    gets(s);

    re = simplifyPath(s);

    puts("处理结果为：");
    puts(re);

    return 0;
}
```