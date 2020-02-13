// PRO_CPP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
输入连个字符串
输出第二个字符串在第一个字符串中的连接次序
例如，输入abdbcc和abc，输出125,126,145,146
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
void ConnectSequence(char* p_str, char* s_str);
void PrintfArray(char* p_str, char* s_str, int* print_arr, int p_len, int s_len, int print_arr_num, int p_start_num, int s_start_num);

int main()
{
    char ParString[] = "abdbcca";
    char SonString[] = "abc";

    ConnectSequence(ParString, SonString);

    return 0;
}

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