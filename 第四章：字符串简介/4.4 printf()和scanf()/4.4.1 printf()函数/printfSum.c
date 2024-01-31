/*此文件为第三章部分内容的一个打印总结，一次性打印用个爽，C99引入的虚数不考虑*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "printfSum.h"
/*
 * 简介：
 *      目前为止，我们学习了的整数类型有
 *      char 字符型 , short 短整型 , int 整型 , long 长整型 , long long 长长整数 unsigned无符号整数 signed有符号整数
 *
 *      浮点数类型有
 *      float 单精度浮点型, doubule 双精度浮点型, long double 长双精度浮点数
 *
 *      以及c99引入的bool类型(虚数不讨论,后续不再解释)
 *
 *
 */

#ifdef KNOW_INT
/* int 型 */

/*
 * int类型常量表示方法.需要注意的是八进制与16进制的常量表示方法
 *
 * (1)0x或0X前缀表示十六进制值，0前缀表示八进制。
 *
 * (2)为了方便展示，这里用了宏定义的方式展示,后续不再赘述
 */

#define NINGNING 0721        /*10进制*/
#define NINGNINGFOR16 0x02D1 /*16进制*/
#define NINGNINGFOR8 01321   /*8进制*/

#endif
/* short 型 */

/*
 * short类型常量表示方法.首先需要注意的是本身的表示方法，其次是八进制与16进制的常量表示方法。
 *
 * (1)0x或0X前缀表示十六进制值，0前缀表示八进制。
 *
 * (2)short其实是简写方法，真正的方法是short int。
 *
 * (3)short int类型（或者简写为short） 占用的存储空间可能比int类型少， 常用于较小数值的场合以节
 *    省空间。 与int类似， short是有符号类型。
 *
 * (4)             16位平台              32位平台                  64位平台
 *              char 1个字节8位        char 1个字节8位          char 1个字节8位
                short 2个字节16位      short 2个字节16位        short 2个字节16位
                int 2个字节16位        int 4个字节32位          int 4个字节32位
                long 4个字节32位       long 4个字节32位         long 8个字节64位
                指针 2个字节           long long 8个字节64位    long long 8个字节64位
                                      指针 4个字节             指针 4个字节(区别)
 *
 * (5) unsigned/signed 与 short 可以合用
 *     例:
 *        unsigned short / signed short / unsigned short int / signed short int
 *        均为合法的变量类型。
 *
 * (6)short类型没有特殊的常量写法,比如long long的常量写法可以有10000LL,但是short类型没有.
 *
 * 接下来要讲解的点是short的打印
 *
 * (7)对于short类型， 可以使用h前缀。 %hd表示以十进制显示short类型的整数， %ho表示以八进制
 *    显示short类型的整数。%hx表示以八进制显示short类型的整数 h和l前缀都可以和u一起使用， 用
 *      于表示无符号类型。 例如， %lu表示打印unsigned long类型的值。切记C允许使用大写或
*       小写的常量后缀， 但是在转换说明中只能用小写。
 *    例：
 *       short ImShort = 0721;
 *       printf("用10进制表示short类型%hd",ImShort);
 *       printf("用8进制表示short类型%ho",ImShort);
 *       printf("用16进制表示short类型%hx",ImShort);
 *
 * (6)对于short类型的变量， 在printf()中无论指定以short类型(%hd) 还是int类型(%d)打印，打印出
 *    来的值都相同（仅限于不超过short范围的值）。 这是因为在给函数传递参数时， C编译器把short类
 *    型的值自动转换成int类型的值。
 *    
 *
 *    原因在于:
 *              int类型被认为是计算机处理整数类型时最高效的类型。
 *
 *    那为什么还是有时候用(%hd)打印呢？
 *
 *    原因在于:
 *              使用h修饰符可以显示较大整数被截断成 short 类型值的情况。
 *    例如：
 *              把 65537 以二进制格式写成一个 32 位数是00000000000000010000000000000001。
 *              使用%hd， printf()只会查看后 16位， 所以显示的值是 1。
 */

/*
 * 此部分需要不看上面的讲解直接手写出来,不允许使用IDE提示.
 */
void ShortStudy()
{
    int ImInt = 65537;//这个int用来表现出超出范围后的截取情况
    short ImShort = 0x0721;
    unsigned short ImUnsginedShort = 0721;
    signed short ImSginedShort = -1;
    unsigned short int ImUnsginedShortInt = 721;
    signed short int ImUnsginedShortInt = -721;

    printf("ImShort的值用10进制hd打印出来是%hd", ImShort);
    printf("ImShort的值用8进制ho打印出来是%ho", ImShort);
    printf("ImShort的值用16进制hx打印出来是%hx", ImShort);
    
    printf("ImShort的值用10进制d打印出来是%hd", ImShort);
    printf("ImShort的值用8进制hd打印出来是%ho", ImShort);
    printf("ImShort的值用16进制hd打印出来是%hx", ImShort);
  
     
    printf("学习结束,详见代码函数ShortStudy()\n");
}

/**************************************************/
/*
 * 变量区，各种类型的变量都定义初始化一遍
 */

char ImChar;
short ImShort;
int ImInt;
long ImLong;
long long ImLongLong;
float ImFloat;
double ImDobule;

/*
 *打印区，这里我将打印不同
 */
int Printf8(void)
{
    /*在这里函数里我们要打印8位10位16位的常量数据*/

    printf();
}

int main(void)
{
    ShortStudy();
    return 0;
}