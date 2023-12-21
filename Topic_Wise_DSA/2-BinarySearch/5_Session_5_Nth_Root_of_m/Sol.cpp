class Solution{
	public:
	int helper(int mid,int n,int m)
	{
	    long long ans=1;
	    for(int i=1;i<=n;i++){
	           ans=ans*mid;
	           if(ans>m) return 2;
	           
	    }
	    if(ans==m) return 1;
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int st=1;
	    int end=m;
	    while(st<=end){
	        int mid=(st+end)/2;
	        if (helper(mid,n,m)==1) return  mid;
	        if (helper(mid,n,m)==0) st=mid+1;
	        else end=mid-1;
	       
	    }
	    return -1;
	    
	    
	}  
};