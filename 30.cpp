/*˼·��һ������Ϊ��ǰ�ͣ�����ǰ�ʹ�����ʱ������ֵ�����С�����򽫵�ǰֵ����Ԫ��ֵ*/
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