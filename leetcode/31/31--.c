// 别人家的代码。。血槽满了的时候拿来研究一下=v=
void BubbleSort(int* arr, int n)
{
     int i = 0, j =0;     
     for(i = 0; i < n; i++)
       for(j = 0; j < n - 1 - i; j++)
       {
             if(arr[j] > arr[j + 1])
             {
                       arr[j] = arr[j] ^ arr[j+1];
                       arr[j+1] = arr[j] ^ arr[j+1];
                       arr[j] = arr[j] ^ arr[j+1];
             }             
       }     
}

void nextPermutation(int* nums, int numsSize) {
	//if(numsSize == 1) return;
    
    for (int x = numsSize - 1; x > 0; --x)
    {
    	if(nums[x] > nums[x-1]){ //if right is bigger than left
    		int head = nums[x-1];
    		//printf("%d\n", nums[x]);
    		BubbleSort(&nums[x],numsSize - x);
    		for (int i = x; i < numsSize; ++i)
    		{
    			if(nums[i]>head){
    				// printf("%d\n", x-1);
    				// printf("%d\n", nums[x-1]);
    				// printf("%d\n", i);
    				// printf("%d\n", nums[i]);
    				// printf("%d\n", head);
    				nums[x-1] = nums[i];
    				nums[i] = head;
    				printf("%d\n", nums[0]);
    				printf("%d\n", nums[1]);
    				return;
    			}
    		}
    	}
    	//printf("%d\n", nums[x]);
    }
    BubbleSort(nums,numsSize);
}
