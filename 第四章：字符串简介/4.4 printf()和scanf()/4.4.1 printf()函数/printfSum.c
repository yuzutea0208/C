/*���ļ�Ϊ�����²������ݵ�һ����ӡ�ܽᣬһ���Դ�ӡ�ø�ˬ��C99���������������*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "printfSum.h"
/*
 * ��飺
 *      ĿǰΪֹ������ѧϰ�˵�����������
 *      char �ַ��� , short ������ , int ���� , long ������ , long long �������� unsigned�޷������� signed�з�������
 *
 *      ������������
 *      float �����ȸ�����, doubule ˫���ȸ�����, long double ��˫���ȸ�����
 *
 *      �Լ�c99�����bool����(����������,�������ٽ���)
 *
 *
 */

#ifdef KNOW_INT
/* int �� */

/*
 * int���ͳ�����ʾ����.��Ҫע����ǰ˽�����16���Ƶĳ�����ʾ����
 *
 * (1)0x��0Xǰ׺��ʾʮ������ֵ��0ǰ׺��ʾ�˽��ơ�
 *
 * (2)Ϊ�˷���չʾ���������˺궨��ķ�ʽչʾ,��������׸��
 */

#define NINGNING 0721        /*10����*/
#define NINGNINGFOR16 0x02D1 /*16����*/
#define NINGNINGFOR8 01321   /*8����*/

#endif
/* short �� */

/*
 * short���ͳ�����ʾ����.������Ҫע����Ǳ���ı�ʾ����������ǰ˽�����16���Ƶĳ�����ʾ������
 *
 * (1)0x��0Xǰ׺��ʾʮ������ֵ��0ǰ׺��ʾ�˽��ơ�
 *
 * (2)short��ʵ�Ǽ�д�����������ķ�����short int��
 *
 * (3)short int���ͣ����߼�дΪshort�� ռ�õĴ洢�ռ���ܱ�int�����٣� �����ڽ�С��ֵ�ĳ����Խ�
 *    ʡ�ռ䡣 ��int���ƣ� short���з������͡�
 *
 * (4)             16λƽ̨              32λƽ̨                  64λƽ̨
 *              char 1���ֽ�8λ        char 1���ֽ�8λ          char 1���ֽ�8λ
                short 2���ֽ�16λ      short 2���ֽ�16λ        short 2���ֽ�16λ
                int 2���ֽ�16λ        int 4���ֽ�32λ          int 4���ֽ�32λ
                long 4���ֽ�32λ       long 4���ֽ�32λ         long 8���ֽ�64λ
                ָ�� 2���ֽ�           long long 8���ֽ�64λ    long long 8���ֽ�64λ
                                      ָ�� 4���ֽ�             ָ�� 4���ֽ�(����)
 *
 * (5) unsigned/signed �� short ���Ժ���
 *     ��:
 *        unsigned short / signed short / unsigned short int / signed short int
 *        ��Ϊ�Ϸ��ı������͡�
 *
 * (6)short����û������ĳ���д��,����long long�ĳ���д��������10000LL,����short����û��.
 *
 * ������Ҫ����ĵ���short�Ĵ�ӡ
 *
 * (7)����short���ͣ� ����ʹ��hǰ׺�� %hd��ʾ��ʮ������ʾshort���͵������� %ho��ʾ�԰˽���
 *    ��ʾshort���͵�������%hx��ʾ�԰˽�����ʾshort���͵����� h��lǰ׺�����Ժ�uһ��ʹ�ã� ��
 *      �ڱ�ʾ�޷������͡� ���磬 %lu��ʾ��ӡunsigned long���͵�ֵ���м�C����ʹ�ô�д��
*       Сд�ĳ�����׺�� ������ת��˵����ֻ����Сд��
 *    ����
 *       short ImShort = 0721;
 *       printf("��10���Ʊ�ʾshort����%hd",ImShort);
 *       printf("��8���Ʊ�ʾshort����%ho",ImShort);
 *       printf("��16���Ʊ�ʾshort����%hx",ImShort);
 *
 * (6)����short���͵ı����� ��printf()������ָ����short����(%hd) ����int����(%d)��ӡ����ӡ��
 *    ����ֵ����ͬ�������ڲ�����short��Χ��ֵ���� ������Ϊ�ڸ��������ݲ���ʱ�� C��������short��
 *    �͵�ֵ�Զ�ת����int���͵�ֵ��
 *    
 *
 *    ԭ������:
 *              int���ͱ���Ϊ�Ǽ����������������ʱ���Ч�����͡�
 *
 *    ��Ϊʲô������ʱ����(%hd)��ӡ�أ�
 *
 *    ԭ������:
 *              ʹ��h���η�������ʾ�ϴ��������ضϳ� short ����ֵ�������
 *    ���磺
 *              �� 65537 �Զ����Ƹ�ʽд��һ�� 32 λ����00000000000000010000000000000001��
 *              ʹ��%hd�� printf()ֻ��鿴�� 16λ�� ������ʾ��ֵ�� 1��
 */

/*
 * �˲�����Ҫ��������Ľ���ֱ����д����,������ʹ��IDE��ʾ.
 */
void ShortStudy()
{
    int ImInt = 65537;//���int�������ֳ�������Χ��Ľ�ȡ���
    short ImShort = 0x0721;
    unsigned short ImUnsginedShort = 0721;
    signed short ImSginedShort = -1;
    unsigned short int ImUnsginedShortInt = 721;
    signed short int ImUnsginedShortInt = -721;

    printf("ImShort��ֵ��10����hd��ӡ������%hd", ImShort);
    printf("ImShort��ֵ��8����ho��ӡ������%ho", ImShort);
    printf("ImShort��ֵ��16����hx��ӡ������%hx", ImShort);
    
    printf("ImShort��ֵ��10����d��ӡ������%hd", ImShort);
    printf("ImShort��ֵ��8����hd��ӡ������%ho", ImShort);
    printf("ImShort��ֵ��16����hd��ӡ������%hx", ImShort);
  
     
    printf("ѧϰ����,������뺯��ShortStudy()\n");
}

/**************************************************/
/*
 * ���������������͵ı����������ʼ��һ��
 */

char ImChar;
short ImShort;
int ImInt;
long ImLong;
long long ImLongLong;
float ImFloat;
double ImDobule;

/*
 *��ӡ���������ҽ���ӡ��ͬ
 */
int Printf8(void)
{
    /*�����ﺯ��������Ҫ��ӡ8λ10λ16λ�ĳ�������*/

    printf();
}

int main(void)
{
    ShortStudy();
    return 0;
}