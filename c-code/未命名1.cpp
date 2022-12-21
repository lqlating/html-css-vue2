#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Defind_Array(int **c,int **b,int len1,int len2);//声明：为数组变量初始化;
int LCSLength(int m,int n,char*x,char*y,int **c,int **b); //声明：将子序列长度记录在数组中;
void printfLCS( int i, int j,char *str, int **b);//声明：构造、输出子序列；
int main()
{
    int Xm,Yn;
    printf("请分别两个序列的长度：");
    scanf("%d%d",&Xm,&Yn);
    char x[Xm],y[Yn];
    getchar();
    printf("第一个序列的值：");
    gets(x);
    printf("第一个序列的值：");
    gets(y);
    int len1 = strlen(x),len2 = strlen(y);
    if(Xm<len1 || Yn<len2)//限制长度 
    {
        printf("你输入的字符长度超过了约束范围,程序退出！");
        return 0;
    }//申请二维数组
    int **c = (int **)malloc(sizeof(int*)*(len1 + 1));
    int **b = (int **)malloc(sizeof(int*)*(len1 + 1));
    Defind_Array(c,b,len1,len2);
    int sum = LCSLength(strlen(x),strlen(y),x, y, c, b);//计算长度
    printf("\n    长度为: %d\n    公共子序列为:",sum);
    printfLCS(len1,len2,x,b);//输出最长子序列;
    int i;
	//内存释放
    for ( i = 0; i <= len1; i++)
    {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);
    return 0;
}
void Defind_Array(int **c,int **b,int len1,int len2)
{
    int i,j;
     //动态申请内存空间 
    for( i = 0; i<= len1; i++ ) 
    {
        c[i] = (int *)malloc(sizeof(int)*(len2 + 1));
        b[i] = (int *)malloc(sizeof(int)*(len2 + 1));
    }
    for ( i = 0; i<= len1; i++)
	//将c[len1][len2]和b[len1][len2]初始化为0
    {
        for( j = 0; j <= len2; j++)
        { 
            c[i][j] = 0;
            b[i][j] = 0;
        }
    }
}
int LCSLength(int m,int n,char *x,char *y,int **c,int **b)
{
    int i,j;
    for (i = 1; i <= m; i++) c[i][0] = 0;
    for (i = 1; i <= n; i++) c[0][i] = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    return c[m][n];  
}
void printfLCS( int i, int j,char *str, int **b)//构造最长公共子序列
{
    if( i == 0 || j == 0) return;    //递归至边界表示完毕 
    if( b[i][j] == 1)
    {                     //对于相等的元素，其路径为左上方对角移动
        printfLCS( i - 1, j - 1,str, b);
        printf("%c ", str[i-1]);  //相等的话，原字符序列向前递归一位并打印出字符
    }
    else if ( b[i][j] == 2 )  //不相等时判断方向：向上则数组向上位移
        printfLCS(i - 1, j,str, b);
    else
        printfLCS(i , j - 1,str, b); //否则数组下标向左位移一位
}
