 void quicksort(int arr[],int l, int r)
 {
 	if(l>=r)
 	return;
 	int left = l, right = r;
 	int k = arr[left]
 	while(left<right){
 		while(left<right&&arr[right]>=k)
 		{
 			right--;
		 }
		 if(left<right)
		 {
		 	arr[left] = arr[right]
		 }
		 while(left<right&&arr[left]<=k)
		 {
		 	left++;
		 }
		 if(left<right)
		 {
		 	arr[right] = arr[left];
		 }
		 if(left>=right)
		 {
		 	arr[left] = k;
		 }
	 }
	 quicksort(arr,l,right-1);
	 quicksort(arr,right+1,r);
 }
