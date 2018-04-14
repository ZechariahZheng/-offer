#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*思路：依次将每个字母推入栈，遇到空字符则将栈里的字母出栈*/
string ReverseSentence(string str)
{
    if (str.empty())
        return str;
    
    int len = str.size();
    char *result = new char [len+1];
    stack<int> tmp;
    int cnt = 0;
    
    for (int i = len-1; i >= 0; i--)
    {
        if (str[i] != ' ')
            tmp.push(str[i]);
        if (str[i] == ' ' || i == 0)
        {
            while (!tmp.empty())
            {
                result[cnt] = tmp.top();
                cnt++;
                tmp.pop();
            }
            if (str[i] == ' ')
            {
                result[cnt] = ' ';
                cnt++;
            }
        }
    }
    string Result = result;
    delete result;
    
    return Result;
}

int main()
{
    string test = "student. a am I";
    string result = ReverseSentence(test);
    cout << result << endl;
    system("pause");
    return 0;
}