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
            if (path[cnt] == '.')
                length_t++;
            else if (path[cnt] == '/')
            {
                if (top == 0)
                    s[top++] = path[cnt];
                else 
                {
                    if (length == 0 && length_t == 1)   //处理 '.'
                    {
                        top -= 2;
                        //cnt++;
                    }
                    if (length == 0 && length_t == 2)   //处理 '..'
                    {
                        //cnt++;
                        if (top != 0){
                            top -= 2;
                            while(s[top] != '/')
                                top--;    
                        }
                        
                    } 
                    if (path[cnt + 1] != '/' && path[cnt + 1] != '\0')
                        s[top++] = path[cnt];
                }
                length = 0;
                length_t = 0;
            }
            else {
                s[top++] = path[cnt];
                length++;
            }
            //s[top++] = path[cnt++];
            cnt++;
        }
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