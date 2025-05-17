#include <iostream>
// 按照要求完成给定的功能，并自动判断程序的运行结果是否正确。
// 从逻辑电路与门、或门、非门等等角度，实现CPU的常见功能。所谓自动判断，即用简单的方式实现指定功能，并判断两个函数的输出是否相同。

// 返回 x 的绝对值,仅使用 !、 ~、 & 、^ 、 | 、 + 、 << 、 >> ， 运算次数不超过 10次
int absVal(int x)
{
    return ((x >> 31) ^ x) + ((x >> 31) & 1);
}
// 判断函数
int absVal_standard(int x) { return (x < 0) ? -x : x; }

// 不使用负号，实现 - x
int negate(int x)
{
    return ~x + 1;
}
// 判断函数
int netgate_standard(int x) { return -x; }

// 仅使用 ~和 | ，实现 &
int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}
// 判断函数
int bitAnd_standard(int x, int y) { return x & y; }

// 仅使用 ~和 & ，实现 |
int bitOr(int x, int y)
{
    return ~(~x & ~y);
}
// 判断函数
int bitOr_standard(int x, int y) { return x | y; }

// 仅使用 ~和 & ，实现 ^
int bitXor(int x, int y)
{
    return ~(~x & ~y) & ~(x & y);
}
// 判断函数
int bitXor_standard(int x, int y) { return x ^ y; }

// 判断x是否为最大的正整数（7FFFFFFF），只能使用 !、 ~、 & 、^ 、 | 、 +
int isTmax(int x)
{
    return !(x ^ (0x7fffffff));
}
// 判断函数
int isTmax_standard(int x) { return x == 0x7fffffff; }

// 统计x的二进制表示中 1 的个数,只能使用，!~&^| +<< >> ，运算次数不超过 40次
int bitCount(int x)
{
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
    return x;
}
// 判断函数
int bitCount_standard(int x)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (x & 1)
        {
            count++;
        }
        x >>= 1;
    }
    return count;
}

// 产生从lowbit 到 highbit 全为1，其他位为0的数。例如bitMask(5, 3) = 0x38 ；要求只使用 !~&^| +<< >> ；运算次数不超过 16次
int bitMask(int highbit, int lowbit)
{
    return (~(~0 << (highbit + 1))) >> lowbit << lowbit;
}
// 判断函数
int bitMask_standard(int highbit, int lowbit)
{
    int result = 0;
    for (int i = 0; i <= highbit - lowbit; i++)
    {
        result = result | 1;
        result = result << 1;
    }
    result = result << lowbit - 1;
    return result;
}

// 当x + y 会产生溢出时返回1，否则返回 0,仅使用 !、 ~、 & 、 ^ 、 | 、 + 、 << 、 >> ， 运算次数不超过 20次
int addOK(int x, int y)
{
    return  (~((x >> 31) ^ (y >> 31)) & ((x >> 31) ^ ((x + y) >> 31))) & 1;
}
// 判断函数
int addOK_standard(int x, int y)
{
    int result = 0;
    int z = x + y;
    if (x >= 0 && y >= 0 && z < 0)
        result = 1;
    if (x < 0 && y < 0 && z >= 0)
        result = 1;
    return result;
}

// 将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间。仅使用 !、 ~、 & 、 ^ 、 | 、 + 、 << 、 >> ， 运算次数不超过 25次
int byteSwap(int x, int n, int m)
{
    int nbyte = (x >> (n << 3)) & 0xff;
    int mbyte = (x >> (m << 3)) & 0xff;
    x = x & ~(0xff << (n << 3)) & ~(0xff << (m << 3));
    x = x | (nbyte << (m << 3)) | (mbyte << (n << 3));
    return x;
}
// 判断函数
int byteSwap_standard(int x, int n, int m)
{
    char* p = (char*)&x;
    char temp = p[n];
    p[n] = p[m];
    p[m] = temp;
    return x;
}

// 当 x = 0 时，返回 1; 其他情况返回 0。实现逻辑非(!),仅使用 ~、 & 、^ 、 | 、 + 、 << 、 >> ，运算次数不超过 12次
int bang(int x)
{
    return (((~x + 1) >> 31 | (x >> 31)) ^ 0) + 1;
}
// 判断函数
int bang_standard(int x) { return !x; }

// 当 x有奇数个二进制位0，返回1；否则返回0,仅使用 !、~、 & 、^ 、 | 、 + 、 << 、 >> ，运算次数不超过 20次。
int bitParity(int x)
{
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    x = x << 31 >> 31;
    return x & 1;
}
// 判断函数
int bitParity_standard(int x)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (x & 1)
        {
            count++;
        }
        x >>= 1;
    }
    return count % 2;
}

int main()
{
    int x = 0x80000000;
    int y = 0x7fffffff;
    int n = 2;
    int m = 3;
    std::cout << "absVal: " << absVal(x) << " " << absVal_standard(x) << std::endl;
    std::cout << "negate: " << negate(x) << " " << netgate_standard(x) << std::endl;
    std::cout << "bitAnd: " << bitAnd(x, y) << " " << bitAnd_standard(x, y) << std::endl;
    std::cout << "bitOr: " << bitOr(x, y) << " " << bitOr_standard(x, y) << std::endl;
    std::cout << "bitXor: " << bitXor(x, y) << " " << bitXor_standard(x, y) << std::endl;
    std::cout << "isTmax0: " << isTmax(x) << " " << isTmax_standard(x) << std::endl;
    std::cout << "isTmax1: " << isTmax(y) << " " << isTmax_standard(y) << std::endl;
    std::cout << "bitCount0: " << bitCount(x) << " " << bitCount_standard(x) << std::endl;
    std::cout << "bitCount1: " << bitCount(y) << " " << bitCount_standard(y) << std::endl;
    std::cout << "bitMask: " << bitMask(m, n) << " " << bitMask_standard(m, n) << std::endl;
    std::cout << "addOK0: " << addOK(x, y) << " " << addOK_standard(x, y) << std::endl;
    std::cout << "addOK1: " << addOK(y, y) << " " << addOK_standard(y, y) << std::endl;
    std::cout << "byteSwap: " << byteSwap(x, n, m) << " " << byteSwap_standard(x, n, m) << std::endl;
    std::cout << "bang0: " << bang(x) << " " << bang_standard(x) << std::endl;
    std::cout << "bang1: " << bang(0) << " " << bang_standard(0) << std::endl;
    std::cout << "bitParity0: " << bitParity(3) << " " << bitParity_standard(3) << std::endl;
    std::cout << "bitParity1: " << bitParity(x) << " " << bitParity_standard(x) << std::endl;
    return 0;
}
