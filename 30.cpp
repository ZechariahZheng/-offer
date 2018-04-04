/*思路：一个数作为当前和，当当前和大于零时，加上值；如果小于零则将当前值等于元素值*/
int FindGreatestSumOfSubArray(vector<int> array) 
{
    if (array.size() == 0)
        return 0;
    int CurSum = 0;
    int MaxSum = INT_MIN;
    for (int i = 0; i < array.size(); i++)
    {
        if (CurSum > 0)
        {
            CurSum += array[i];
        }
        else
        {
            CurSum = array[i];
        }
        if (CurSum > MaxSum)
            MaxSum = CurSum;
    }
    return MaxSum;
}