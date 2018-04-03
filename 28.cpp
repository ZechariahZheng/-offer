/*思路：使用两个vector，一个保存数组中不同的数字，另一个保存不同数字出现的次数*/

int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        vector<int> DifNum;
        vector<int> ShowNum;
        int ExistFlag = 0;
        int tmp = 0;
        DifNum.push_back(numbers[0]);
        ShowNum.push_back(1);
        for (int i = 0; i < numbers.size(); i++)
        {
            tmp = numbers[i];
            for (int j = 1; j < DifNum.size(); j++)
            {
                if (tmp == DifNum[j])
                {
                    ExistFlag = 1;
                    ShowNum[j]++;
                    break;
                }
            }
            if (ExistFlag == 0)
            {
                DifNum.push_back(tmp);
                ShowNum.push_back(1);
            }
        }
        int result = 0;
        int Half = numbers.size()/2;
        for (int i = 0; i < ShowNum.size(); i++)
        {
            if (ShowNum[i] > Half)
            {
                result = DifNum[i];
                break;
            }    
        }
        return result;
    }