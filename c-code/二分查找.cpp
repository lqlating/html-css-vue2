#include<stdio.h>
 
#define N 10     //����Ԫ�ظ�����
int a[N]={1,2,3,4,5,6,7,8,9,10};    //����������飻
 
 
int half(int low,int high,int key)  //low��ʾ���  high��ʾ�յ㣻
{
	if(low<high)
	{	
		int mid=(low+high)/2;     //�����м�ֵ�����м�ֵ��key�Ƚϣ�
		if(a[mid]==key)       //���ڵĻ���˵���ҵ������Ԫ�أ�
			return mid;
		else if(a[mid]>key)     //Ҫ�ҵ�ֵ��mid����ߣ�
			return half(low,mid-1,key);   //���¶������䳤�ȣ�����half������
		else                            //Ҫ�ҵ�ֵ��mid���ұߣ�
			return half(mid+1,high,key);   //���¶������䳤�ȣ�����half������
	}
	return -1;  
}
int main(void)
{
	int key;
	printf("����Ҫ���ҵĹؼ���: ");
	scanf("%d",&key);
	int pos=half(0,N-1,key);
	printf("ԭ���ݱ�:  ");
	for(int i=0;i<N;i++)
		printf("%d ",a[i]);
	printf("\n\n");
	if(pos>=0)
		printf("���ҳɹ�,�ùؼ���λ������ĵ�%d��Ԫ��!\n",pos+1);
	else
		printf("����ʧ��!!!\n");
	return 0;
}
