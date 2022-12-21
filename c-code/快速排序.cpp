#include<stdio.h>
void Print(int array[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
} 
/*��ȡ��׼���꣬���������(��߱Ȼ�׼����С���ұ߱Ȼ�׼�����)*/
int getStandard(int array[],int low,int high) {
    int key = array[low];  //��ʱ�����׼Ԫ�� 
    while(low<high) {  
        //highָ��Ӻ���ǰ���� �� Ԫ�رȻ�׼Ԫ�ش���ָ����ǰ�ƶ� ��Ȼ�׼Ԫ��С��ͻ�׼Ԫ�ؽ��� 
        while(low<high && array[high]>=key){
            high--;
        }
        if(low<high){
            array[low] = array[high];  //��ֵ����һ��Ԫ�أ���Ϊ��һ��Ԫ����Ϊ��׼Ԫ���Ѿ���ʱ�����ˣ�������ֱ�Ӹ�ֵ 
        }
        //lowָ���ǰ������ �� Ԫ�رȻ�׼Ԫ��С��ָ������ƶ� ����Ȼ�׼Ԫ�ش���ͻ�׼Ԫ�ؽ��� 
        while(low<high && array[low]<=key){
            low++;
        }
        if(low<high){
            array[high] = array[low];  //���Ƹ�highָ����ָ��λ�ã���Ϊ��11���Ѿ���ֵ��array[low]�� 
        }
    }
    array[low] = key;
    return low; 
}
void QuickSort(int array[],int low,int high){
    if(low<high){  //�ݹ���� 
        int standard = getStandard(array,low,high);
        QuickSort(array,low,standard-1);  //�Ȼ�׼Ԫ��С�Ĳ��ּ������ÿ������� 
        QuickSort(array,standard+1,high);   //�Ȼ�׼Ԫ�ش�Ĳ��ּ������ÿ������� 
    }
}
 int main(){
     int array[] = {1,42,45,86,23,14,12};
    int size = sizeof(array) / sizeof(int);
    printf("ԭʼ����Ϊ��\n");
    Print(array,size); 
    QuickSort(array,0,size-1);
    printf("���������Ϊ��\n");
    Print(array,size); 
 }
