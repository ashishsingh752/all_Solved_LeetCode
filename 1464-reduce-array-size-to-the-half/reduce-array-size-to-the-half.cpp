class Solution {
public:
    int size;
map<int,int>mp;
pair<int,int>p;
int minSetSize(vector<int>& arr) 
{
    size=arr.size();
    int currsize=size;
    int count=0;
    
    for(int i=0;i<arr.size();i++)
    {
    	mp[arr[i]]++;
	}
	priority_queue<pair<int,int>>pq;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
    	pq.push({make_pair(it->second,it->first)});   //frequency , element
	}
	while(!pq.empty())
	{
		p=pq.top();
		pq.pop();
		
		int ele = p.second;
		int freq = p.first;
		
	    count=count+1;
			
        currsize = currsize - freq;
     
        if(currsize <= (size/2))
	    {
		   return count;    	
	    }	
	}
	return count;
}
};