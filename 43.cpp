/*思路：遇到循环移位的都要想到取模做法*/
string LeftRotateString(string str, int n) 
{
        if (str == "")
            return str;
        int len = str.size();
        int realN = n%len;
        if (realN == 0) 
            return str;
        string tmp1 = str.substr(0, realN);
        string tmp2 = str.substr(realN);
        
        return tmp2+tmp1;
}