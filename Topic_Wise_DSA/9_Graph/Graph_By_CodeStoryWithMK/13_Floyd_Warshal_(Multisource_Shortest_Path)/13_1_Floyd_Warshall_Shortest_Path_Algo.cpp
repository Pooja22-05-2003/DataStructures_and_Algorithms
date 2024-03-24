/*
Probelm Link : https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


1. For Cycle Detection, if grid[i][i]<0, then it contain cycle.
Because shortest node from any path to itself is 0.
*/
// TC=O(N^3)
// SC=O(1)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Here In Question it is given , that if (matrix[i][j]==-1) then there is no edge between i and j.
	    // So, If we update the edge weight with any max value, then we will never choose to going to any node throguh i and j, 
	    
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix.size();j++)
	        {
	            if(matrix[i][j]==-1) matrix[i][j]=100000;
	        }
	    }
	    
	    for(int via=0;via<matrix.size();via++)
	    {
	        for(int i=0;i<matrix.size();i++)
	        {
	             for(int j=0;j<matrix.size();j++)
	               {
	                 matrix[i][j]=min(matrix[i][j],(matrix[i][via]+matrix[via][j]));
	               }
	        } 
	    }
	    
	    // converting again that large value to -1;
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix.size();j++)
	        {
	            if(matrix[i][j]==100000) matrix[i][j]=-1;
	        }
	    }
	    
	  
	}
};