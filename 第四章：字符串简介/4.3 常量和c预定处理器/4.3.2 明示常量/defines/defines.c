// defines.c -- 使用 limits.h 和 float.h 头文件中定义的明示常量
#include <stdio.h>
#include <limits.h> // 整型限制
#include <float.h>  // 浮点型限制

int main(void)
{
    printf("此系统的一些数字限制:\n");
    printf("最大的整数: %d\n", INT_MAX);
    printf("最小的长长整数: %lld\n", LLONG_MIN);
    printf("在此系统上，一个字节 = %d 位。\n", CHAR_BIT);
    printf("最大的双精度浮点数: %e\n", DBL_MAX);
    printf("最小的正常单精度浮点数: %e\n", FLT_MIN);
    printf("单精度浮点数的精度 = %d 位\n", FLT_DIG);//这里DIG表示是10进制
    printf("单精度浮点数的 epsilon = %e\n", FLT_EPSILON);//这里的意思是，FLT_EPSILON 是浮点数 1 和比它大的下一个可表示的浮点数之间的差值。
    return 0;
}

