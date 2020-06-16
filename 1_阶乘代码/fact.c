#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* 函数功能：求两个数的乘积
* 参数num_arrar: 按位排列好的整数数组，高位在前
* 参数cnt：num_array的长度
* 参数num_nulti: 第二个乘数，一个正整数
* 返回值：无
*/
void multi_array(int *num_array, int cnt, int num_multi)
{
    int i;
    for(i=0; i<cnt; i++)
    {
        num_array[i] *= num_multi;
    }
    for(i=cnt-1; i>0; i--)
    {
        num_array[i-1] += num_array[i]/10;
        num_array[i] %= 10;
    }
}

/*
* 函数功能：求100以内的阶乘
* 参数num：所求的数
* 返回值：阶乘结果数组，长度50,失败返回null
*/
int *factor(int num)
{
    /*输入非法处理*/
    if(num < 0)
    {
        return NULL;
    }

    int *num_array = (int *)malloc(sizeof(int)*50);
    if(num_array == NULL)
    {
        return NULL;
    }
    memset(num_array, 0, sizeof(int)*50);
    *(num_array+(50-1)) = 1;

    if(num == 0)    //处理特殊情况
    {
        return num_array;
    }

    //开始计算
    for(int i=2; i<=num; i++)
    {
        multi_array(num_array, 50, i);
    }

    return num_array;
}

int main()
{
    int num;
    printf("输入一个一百以内的非负整数：");
    scanf("%d", &num);
    int *result = factor(num);
    if(result == NULL)
    {
        printf("输入的数据不符合要求\n");
        return -1;
    }

    //显示结果
    int start = 0;
    for(int i = 0; i < 50; i++)
    {
        if(start)
        {
            printf("%d", result[i]);
        }
        else
        {
            //不显示高位多余的0
            if(result[i+1] != 0)
            {
                start = 1;
            }
        }
    }
    printf("\n");
    return 0;
}