#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeOuterParentheses(char * S){
    int top = 0, i = 0, j = 0, len = strlen(S), st = 0, ed = 0;
    char *stack = malloc(len * sizeof(char));
    char *re = malloc(len * sizeof(char));
    
    while (S[i] != '\0')
    {
        printf("i:%d %c\n",i,S[i]);
        if (S[i] == '(')
            stack[top++] = S[i];
        if (S[i] == ')')
        {
            top--;
        }
        
        if (top == 0)
        {
            st += 1;
            ed = i;
            printf("i:%d j:%d st:%d ed:%d %c\n",i,j,st,ed,S[i]);
            while (st < ed)
            {
                re[j] = S[st];
                st++;
                j++;
            }
            
            st = ed + 1;
        }
        i++;
    }
    
    re[j] = '\0';
    return re;
}

int main()
{
    char in[100];
    char *out, *data = in;
    puts("请输入有效的括号字符串：");
    gets(in);

    out = removeOuterParentheses(data);

    puts(out);
    return 0;
}