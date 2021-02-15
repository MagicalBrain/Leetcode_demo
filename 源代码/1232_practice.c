/*
* # 【每日一题】1232.缀点成线
*/

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

bool checkStraightLine(int coordinates[][2], int coordinatesSize){
    int hx = coordinates[1][0], hy = coordinates[1][1],
    hdx = 0,hdy= 0, flag_x = 0,flag_y = 0,
    dx = hx - coordinates[0][0],
    dy = hy - coordinates[0][1];

    for (int i = 2; i < coordinatesSize; i++)
    {
        int x = coordinates[i][0], y = coordinates[i][1];
        if ( (y - hy) * dx != dy * (x - hx))
            return false;
    }    
    return true;
}

int main()
{
    //int coordinates[][2] = {{1,2},{3,4},{5,6},{7,8},{9,10}};  //true
    //int coordinates[][2] = {{0,2},{0,4},{0,6},{0,8},{0,10}};    //true
    //int coordinates[][2] = {{1,2},{3,2},{5,2},{7,2},{9,2}};     //true
    int coordinates[][2] = {{1,2},{3,0},{5,6},{7,8},{9,10}};       //false
    int coordinatesSize = 5;

    if (checkStraightLine(coordinates,coordinatesSize))
        puts("在同一直线上！");
    else
    {
        puts("不在同一直线上！");
    }
    

    return 0;
}