/*思路：先排序，后取前n个数字*/

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
    vector<int> result;  
    int len = input.size();  
    if(len !=0&&!(len<k)) 
    {  
        sort(input.begin(),input.end());  
        for(int i = 0;i<k;++i)
        {     
            result.push_back(input[i]);   
        }  
        return result;
    }
    else 
        return result;
}