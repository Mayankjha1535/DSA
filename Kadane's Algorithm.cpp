#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

int Maximum_Sum_Subarray(int arr[],int n)	//Overall Time Complexity O(n)
{
	int ans = arr[0],sum = 0;
	for(int i = 1;i < n; ++i)	//Check if all are negative
		ans = max(ans,arr[i]);	
	if(ans<0)					//if ans < 0 return Max
		return ans;
	ans = 0;
	for(int i = 0 ;i < n; ++i)
	{
		if(sum + arr[i] > 0)
			sum+=arr[i];
		else
			sum  = 0;
		ans = max(ans,sum);	
	}
	return ans;
}

int main()
{
	int arr[] = {-2,-3,4,-1,-2,1,5,-3};
	cout<< "Maximum sum of contiguous subarray " << Maximum_Sum_Subarray(arr,8)<< endl;
	return 0;
}
