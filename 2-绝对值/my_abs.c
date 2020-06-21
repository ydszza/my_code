/**
 * 中文使用gbk编码，以正常在window命令行显示
*/


#include <stdio.h>
/**
 * 分支结构求绝对值
*/
int my_abs1(int num_t)
{
	int num = num_t;
	if(num >= 0)
	{
		return num;
	}
	else
	{
		return -num;
	}
}

/**
 * 分支结构求绝对值
*/
int my_abs2(int num_t)
{
	int num = num_t;
	return num>=0 ? num : -num;
}

/**
 * 分支结构求绝对值
*/
int my_abs3(int num_t)
{
	int num = num_t;
	return num>>31 ? num : ~num+1;
}

/**
 * 功能：判断一个数是不是2的n次方
 * 参数：要判断的数
 * 返回值：1是，0不是
*/
int is_npower_2(int num_t)
{
	int num = num_t;
	return ((num&(num-1)) == 0);
	//return ((num|(num-1)) == (num+(num-1)));
}


int main() {
    int x = -100;
    int y = 128;
    printf("分支结构|x| = %d\n",my_abs1(x));
    printf("条件运算符|x| = %d\n",my_abs2(x));
    printf("位运算|x| = %d\n",my_abs3(x));
    if(is_npower_2(y)){
        printf("%d是2的n次方",y);
    }
    return 0;
}