#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Defind_Array(int **c,int **b,int len1,int len2);//������Ϊ���������ʼ��;
int LCSLength(int m,int n,char*x,char*y,int **c,int **b); //�������������г��ȼ�¼��������;
void printfLCS( int i, int j,char *str, int **b);//���������졢��������У�
int main()
{
    int Xm,Yn;
    printf("��ֱ��������еĳ��ȣ�");
    scanf("%d%d",&Xm,&Yn);
    char x[Xm],y[Yn];
    getchar();
    printf("��һ�����е�ֵ��");
    gets(x);
    printf("��һ�����е�ֵ��");
    gets(y);
    int len1 = strlen(x),len2 = strlen(y);
    if(Xm<len1 || Yn<len2)//���Ƴ��� 
    {
        printf("��������ַ����ȳ�����Լ����Χ,�����˳���");
        return 0;
    }//�����ά����
    int **c = (int **)malloc(sizeof(int*)*(len1 + 1));
    int **b = (int **)malloc(sizeof(int*)*(len1 + 1));
    Defind_Array(c,b,len1,len2);
    int sum = LCSLength(strlen(x),strlen(y),x, y, c, b);//���㳤��
    printf("\n    ����Ϊ: %d\n    ����������Ϊ:",sum);
    printfLCS(len1,len2,x,b);//����������;
    int i;
	//�ڴ��ͷ�
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
     //��̬�����ڴ�ռ� 
    for( i = 0; i<= len1; i++ ) 
    {
        c[i] = (int *)malloc(sizeof(int)*(len2 + 1));
        b[i] = (int *)malloc(sizeof(int)*(len2 + 1));
    }
    for ( i = 0; i<= len1; i++)
	//��c[len1][len2]��b[len1][len2]��ʼ��Ϊ0
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
void printfLCS( int i, int j,char *str, int **b)//���������������
{
    if( i == 0 || j == 0) return;    //�ݹ����߽��ʾ��� 
    if( b[i][j] == 1)
    {                     //������ȵ�Ԫ�أ���·��Ϊ���Ϸ��Խ��ƶ�
        printfLCS( i - 1, j - 1,str, b);
        printf("%c ", str[i-1]);  //��ȵĻ���ԭ�ַ�������ǰ�ݹ�һλ����ӡ���ַ�
    }
    else if ( b[i][j] == 2 )  //�����ʱ�жϷ�����������������λ��
        printfLCS(i - 1, j,str, b);
    else
        printfLCS(i , j - 1,str, b); //���������±�����λ��һλ
}
