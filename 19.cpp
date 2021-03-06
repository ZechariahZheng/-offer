#include <iostream>
#include <vector>

using namespace std;

/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵：
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.*/

/*思路：顺时针打印
顺时针打印就是按圈数循环打印，一圈包含两行或者两列，在打印的时候会出现某一圈中只包含一行，要判断从左向右打印和从右向左打印的时候是否会出现重复打印，
同样只包含一列时，要判断从上向下打印和从下向上打印的时候是否会出现重复打印的情况*/

vector<int> printMatrix(vector<vector<int> > matrix)
{
    vector<int>res;
    res.clear();
    int row=matrix.size();//行数
    int collor=matrix[0].size();//列数
    //计算打印的圈数
    int circle=((row<collor?row:collor)-1)/2+1;//圈数
    for(int i=0;i<circle;i++)
    {
        //从左向右打印
        for(int j=i;j<collor-i;j++)
            res.push_back(matrix[i][j]);         
        //从上往下的每一列数据
        for(int k=i+1;k<row-i;k++)
            res.push_back(matrix[k][collor-1-i]);
        //判断是否会重复打印(从右向左的每行数据)
        for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--)
            res.push_back(matrix[row-i-1][m]);
        //判断是否会重复打印(从下往上的每一列数据)
        for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--)
            res.push_back(matrix[n][i]);}
    return res;
}

int main()
{
    int tmp_1[] = {1,2,3,4};
    int tmp_2[] = {5,6,7,8};
    int tmp_3[] = {9,10,11,12};
    int tmp_4[] = {13,14,15,16};
    vector<int> input_1(begin(tmp_1), end(tmp_1));
    vector<int> input_2(begin(tmp_2), end(tmp_2));
    vector<int> input_3(begin(tmp_3), end(tmp_3));
    vector<int> input_4(begin(tmp_4), end(tmp_4));
    vector<vector<int> > input;
    input.push_back(input_1);
    input.push_back(input_2);
    input.push_back(input_3);
    input.push_back(input_4);
    
    vector<int> result = printMatrix(input);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}