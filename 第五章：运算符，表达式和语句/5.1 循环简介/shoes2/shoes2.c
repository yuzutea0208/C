/*shoes2.c -- 计算多个不同鞋码的脚长*/

#include <stdio.h>
#define ADJUST 7.31 // 字符常量
int main(void)
{
    const double SCALE = 0.333; // const 变量
    double shoe, foot;

    printf("鞋码(男士)脚长\n");
    shoe = 3.0;
    while (shoe < 18.5)
    {
        foot = SCALE * shoe + ADJUST;
        printf("%10.1f %15.2f 英寸\n", shoe, foot);
        shoe = shoe + 1.0;
    }
    printf("如果鞋合适，就穿上它\n");
    return 0;
}