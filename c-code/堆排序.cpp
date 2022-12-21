void heapfy(int arr(),int root, int length)
{
	if(root > length)
	return;
	int left = root*2+1,right = root*2+2£»
	int max = arr[root];
	if(right<=length&&max<arr[right])
	{
		max = arr[right];
	 }
	 if(left <= length&&max<arr[left])
	 {
	 	max = arr[left];
	 }
	 if(max!=arr[root])
	 {
	 	if(right<=length&&max==arr[right]){
	 		arr[right] = arr[root];
	 		heapfy(arry,right,length);
		 }
		 arr[root] = max;
	 }
}
vold heapsort(int arr[],int length)
{
	for(int i = (length - 1)/2;i>0;i--)
	{
		heapfy(arr,i,length);
	}
}
