#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。*/

/*思路：
在一个二维数组中，寻找路径。
1、先定位起点位置
2、在看四周的格子是否包含目标字母，并且没有被走过
3、重复1,2过程
注：函数传递二维数组，可以使用vector<vector>
*/

struct startNode {
    int x;
    int y;
};

bool search(int x, int y, vector<vector<int> >&map, vector<vector<int> >&flag, char *str, int i, int rows, int cols)
{
    if (str[i] == '\0')
    {
        cout << "find end!" << endl;
        return true;
    }
    /*查看当前格子的四周有无目标点*/
    if (x-1>=0 && map[x-1][y]==str[i] && flag[x-1][y]==0)   //向左
    {
        flag[x-1][y] = 1;
        cout << "turn left" << endl;
        i++;
        return search(x-1, y, map, flag, str, i, rows, cols);
    }
    else if (x+1<=cols-1 && map[x+1][y]==str[i] && flag[x+1][y]==0)     //向右
    {
        flag[x+1][y] = 1;
        cout << "turn right" << endl;
        i++;
        return search(x+1, y, map, flag, str, i, rows, cols);
    }
    else if (y-1>=0 && map[x][y-1]==str[i] && flag[x][y-1]==0)     //向上
    {
        flag[x][y-1] = 1;
        cout << "turn up" << endl;
        i++;
        return search(x, y-1, map, flag, str, i, rows, cols);
    }
    else if (y+1<=rows-1 && map[x][y+1]==str[i] && flag[x][y+1]==0)     //向下
    {
        flag[x][y+1] = 1;
        cout << "turn down" << endl;
        i++;
        return search(x, y+1, map, flag, str, i, rows, cols);
    }
    else
    {
        cout << "Not find!" << endl;
        return false;
    }
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    bool result = false;
    printf("Test hasPath!!!\n");
    /*分配地图和标志位*/
    vector<vector<int> > flag;
    vector<vector<int> > map;
    vector<int> tmpFlag;
    vector<int> tmpMap;
    for (int i = 0; i < cols; i++)
    {
        tmpFlag.clear();
        tmpMap.clear();
        for (int j = 0; j < rows; j++)
        {
            tmpFlag.push_back(0);
            tmpMap.push_back('\0');
        }
        flag.push_back(tmpFlag);
        map.push_back(tmpMap);
    }
    /*初始化地图并寻找起点*/
    int n = 0;
    vector<startNode> startAll;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map[i][j] = matrix[n];
	        printf("%c", matrix[n]);
            if (matrix[n] == str[0])        //找到起点，记录下坐标位置
            {
                startNode tmp;
                tmp.x = i;
                tmp.y = j;
                startAll.push_back(tmp);
            }
            n++;
        }
	printf("\n");
    }
    /*若未找到起点*/
    if (startAll.empty())
    {
        cout << "Not find start node!" << endl;
        return result;
    }

    /*以起点开始，寻找*/
    for (int i = 0; i < startAll.size(); i++)
    {
        /*将标志位清零*/
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                flag[i][j] = 0;
        }
        flag[startAll[i].x][startAll[i].y] = 1;
        result = search(startAll[i].x, startAll[i].y, map, flag, str, 1, rows, cols);
        if (result == true)
            break;
    }
    return result;
}

int main()
{
	char *matrix = "abcesfcsadee";
	char *str_1 = "bcced";
	char *str_2 = "abcd";
	int rows = 3;
	int cols = 4;

	bool result = hasPath(matrix, rows, cols, str_2);
	if (result)
		cout << "YES" << endl;
	return 0;    
}
