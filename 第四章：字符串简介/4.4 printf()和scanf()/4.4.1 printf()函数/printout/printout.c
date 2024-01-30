/*printout.c --使用转换说明*/

#include <stdio.h>
#define PI 3.141593

int main(void)
{
	int number = 7;
	float pies = 12.75;
	int cost = 7800;

	printf("有%d位参赛者吃了%f个草莓蛋糕。\n",numbber,cake);
	printf("圆周率的值是%f。\n",PI);
	printf("你对我来说太贵咯。\n");
	printf("%c%d\n",'$',2 * cost); /*这里$是一个字符char，会被c打印出来*/

	getchar();
	return 0;
}

