/*
 * 【leetcode】1598题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minOperations(char ** logs, int logsSize){
    int re = 0;

    for (int i = 0; i < logsSize; i++)
    {
        if (strcmp(logs[i],"../") == 0 && re != 0)
            re -= 1;
        else if (strcmp(logs[i],"../") == 0 && re == 0)
            continue;
        else if (strcmp(logs[i],"./") == 0)
            continue;
        else 
            re++;
    }
    
    return re;
}

int main()
{
    int logsSize;
    char **logs;

    puts("请输入操作的次数：");
    scanf("%d",&logsSize);
    getchar();

    logs = (char**) malloc(logsSize * sizeof(char*));
    for (int i = 0; i < logsSize; i++)
    {
        logs[i] = (char*) malloc(10 * sizeof(char));
        gets(logs[i]);
    }

    //检查输入
    puts("输入数据为：");
    for (int i = 0; i < logsSize; i++)
    {
        puts(logs[i]);
    }
    
    printf("结果为：%d\n",minOperations(logs,logsSize));
    return 0;
}