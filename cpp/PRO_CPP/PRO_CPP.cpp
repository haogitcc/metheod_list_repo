// PRO_CPP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
void ConnectSequence(char* p_str, char* s_str);
void PrintfArray(char* p_str, char* s_str, int* print_arr, int p_len, int s_len, int print_arr_num, int p_start_num, int s_start_num);

int func(int m, int n);

int x(int n);

int main()
{
    /*
    //Q1
    输入连个字符串
    输出第二个字符串在第一个字符串中的连接次序
    例如，输入abdbcc和abc，输出125,126,145,146
    */
    char ParString[] = "abdbcca";
    char SonString[] = "abc";
    //ConnectSequence(ParString, SonString);

    /*
    //Q2
    请给出此题的非递归算法:
    f(m, n) = n, (m=1)
    f(m, n) = m, (n=1)
    f(m, n) = f(m-1, n) + f(m, n-1), (m>1, n>1)
    1, 2, 3, 4, 5
    2, 4, 7, 11,16
    3, 7,14, 25,41
    4, 11,25,50,91
    5, 16,41,91,182
    如上所示，假如想求m为3、n为4的f(m, n)值，就是25。
    */
    //cout << "Q2: " << func(3, 4) << endl;

    /*
    //Q3
    设计递归算法x(x(8))需要调用几次函数x(int n)。
    */
    int i;
    i = x(x(8));
    /*
    x(8) --> 理解为一个二叉树
         8
       /   \
      6     4
     / \   / \
    4   2 2  0
   / \
  2   0
  节点数为9，
  x(8)=9， 所以x(9) -->的二叉树
         9
       /   \
      7     5
     / \   / \
    5   3 3  1
   / \
  3   1
  节点数也为9，
  所以x(x(8))一共调用了x(int n) 18次。
    */

    return 0;
}

//start Q3
int x(int n)
{
    if (n <= 3)
    {
        return 1;
    }
    else
    {
        return x(n - 2) + x(n - 4) + 1;
    }
}
//Q3 end

//start Q2
#define RECUSION 0
#define NO_RECUSION 1

#if RECUSION
int func(int m, int n)
{
    if (m <= 0 || n <= 0)
    {
        return -1;
    }
    if (m == 1)
    {
        return n;
    }
    if (n == 1)
    {
        return m;
    }
    return func(m - 1, n) + func(m, n - 1);
}
#endif

#if NO_RECUSION
int func(int m, int n)
{
    if (m > 0 && n > 0)
    {
        if (m > 100 || n > 100)
        {
            return -2;
        }
        int a[100][100];
        for (int i = 0; i != m; ++i)
        {
            a[i][0] = i + 1;
        }
        for (int i = 0; i != n; ++i)
        {
            a[0][i] = i + 1;
        }

        for (int i = 1; i != m; ++i)
        {
            for (int j = 1; j != n; ++j)
            {
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        return a[m - 1][n - 1];
    }
    else
    {
        return -1;
    }
}
#endif
//Q2 end

// start Q1
void ConnectSequence(char* p_str, char* s_str)
{
    int p_len = strlen(p_str);
    int s_len = strlen(s_str);
    int* print_arr = new int[s_len];
    unsigned int print_arr_num = 0;

    if (NULL == p_str && NULL == s_str)
    {
        cout << "string error" << endl;
        return;
    }

    if (NULL == print_arr)
    {
        cout << "allocate error" << endl;
        return;
    }

    PrintfArray(p_str, s_str, print_arr, p_len, s_len, 0, 0, 0);
}


void PrintfArray(char *p_str, char *s_str, int *print_arr, int p_len, int s_len, int print_arr_num, int p_start_num,  int s_start_num)
{
    int pStartNum = p_start_num;
    int sStartNum = s_start_num;
    int printNum = print_arr_num;

    if (printNum == s_len)
    {
        for (int i = 0; i < s_len; i++)
        {
            cout << *(print_arr+i) << " ";
        }
        cout << endl;
        return;
    }

    for (int i = pStartNum; i < p_len; i++)
    {
        for (int j = sStartNum; j < s_len; j++)
        {
            if (*(p_str + i) == *(s_str + j))
            {
                print_arr[printNum] = i + 1;
                pStartNum = i;
                sStartNum = j;
                PrintfArray(p_str, s_str, print_arr, p_len, s_len, printNum + 1, pStartNum + 1, sStartNum + 1);
            }
        }
    }
}
// Q1 end