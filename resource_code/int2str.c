/*
 * 整型数转成字符串 代码存档
 * 
 * 注意：
 * 如果给出的是负数，要对负号进行处理
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* int2str(int num)
{
    char* re = NULL;
    int l = 0;
    int n = num;

    while (n / 10 != 0)
    {
        n /= 10;
        l++;    
    }
    l++;

    if (num > 0)
    {
        printf("长度为：%d\n",l);

        re = (char*) malloc( (l + 1) * sizeof(char));
        re[l] = '\0';

        n = num;
        while (n / 10 != 0)
        {
            int t = n % 10;
            n /= 10;
            re[l - 1] = t + '0';
            l--;    
        }
        re[0] = n + '0';
    }
    else
    {
        l++;
        printf("长度为：%d\n",l);

        re = (char*) malloc( (l + 1) * sizeof(char));
        re[l] = '\0';

        n = num;
        while (n / 10 != 0)
        {
            int t = n % 10;
            n /= 10;
            re[l - 1] = t + '0';
            l--;    
        }
        re[1] = n + '0';
        re[0] = '-';
    }
    
    return re;
}

int main()
{
    int num;
    puts("请输入一个数");
    scanf("%d",&num);
    //printf("%d\n",num % 10);
    //printf("%d\n",num / 10);

    char *re = int2str(num);
    puts(re);

    return 0;
}