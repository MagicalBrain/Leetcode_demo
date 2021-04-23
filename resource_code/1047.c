#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeDuplicates(char * S){
    int i = 0, top = 0,len;
    len = strlen(S);
    char *stack = malloc(len * sizeof(char));

    stack[top++] = S[i++];
    while (i < len)
    {
        if (S[i] != stack[top - 1])
            stack[top++] = S[i];
        else
        {
            top--;
        }
        i++;
    }
    stack[top] = '\0';
    return stack;
}


int main()
{
    char in[100];
    char *out, *data = in;
    puts("请输入字符串：");
    gets(in);

    out = removeDuplicates(data);

    puts(out);
    return 0;
}