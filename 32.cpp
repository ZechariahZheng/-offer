static bool compare(int a, int b)
{
    string strNum1=to_string(a);
    string strNum2=to_string(b);
    return (strNum1+strNum2)<(strNum2+strNum1);
}
string PrintMinNumber(vector<int> numbers) {
    string result;
    if(numbers.empty())
        return result;
    sort(numbers.begin(),numbers.end(),compare);
    for(unsigned int i=0;i<numbers.size();i++)
        result+=to_string(numbers[i]);
    return result;
}