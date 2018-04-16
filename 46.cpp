#include <iostream>
#include <list>

using namespace std;

/*思路：如果当n>=m时，即第m-1个离开
        如果当n<m时，即第m%n-1个离开
当有一个元素出队列之后，又要重新移动，考虑是否采用循环队列
如果采用循环队列：采用普通队列模拟循环队列*/
        

int LastRemaining_Solution(int n, int m)
{
    /*参数判断*/
    if (n == 1)
        return 0;
    if (n == 0)
        return -1;
    list<int> numbers;
    for (int i = 0; i < n; i++)
        numbers.push_back(i);
    
    /*开始循环*/
    list<int>::iterator it;
    list<int>::iterator tmp;
    int cnt;
    list<int>::iterator current = numbers.begin();
    while (numbers.size() > 1)
    {
        cnt = 0;
        it = current;                   //指向头指针
        if (numbers.size() >= m)        /*删除现存队列中第m-1个元素*/
        {
            while (cnt < m-1)
            {
                it++;
                if (it == numbers.end())        //如果指向队列尾部+1的位置，则重新指向头部
                    it = numbers.begin();
                cnt++;
            }
            numbers.erase(it++);
            tmp = it;
            n--;
            /*删除元素后，队列的头指针要重新指定*/
            if (tmp == numbers.end())
                current = numbers.begin();
            else
                current = tmp;
        }
        else    //删除现存队列中第m%n-1个元素
        {
            if (m%n >= 1)
            {
                while (cnt < m%n-1)
                {
                    it++;
                    if (it == numbers.end())        //如果指向队列尾部+1的位置，则重新指向头部
                        it = numbers.begin();
                    cnt++;
                }
            }
            else
            {
                /*刚好除尽，则删除新队列的最后一个元素*/
                while (cnt < n-1)
                {
                    it++;
                    if (it == numbers.end())
                        it = numbers.begin();
                    cnt++;
                }
            }
            it = numbers.erase(it++);
            n--;
            /*删除元素后，队列的头指针要重新指定*/
            tmp = it;
            if (tmp == numbers.end())
                current = numbers.begin();
            else
                current = tmp;
        }
    }
    return numbers.front();
}

int main()
{
    int result = LastRemaining_Solution(6, 6);
    cout << result << endl;
    system("pause");
    return 0;
}