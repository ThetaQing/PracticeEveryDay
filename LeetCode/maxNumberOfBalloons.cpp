/*
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.size() == 0 || text.size()>10000)
            return 0;
        int balloon[5]={0,0,0,0,0};
        for(auto item:text)
        {
            switch (item)
            {
                case 'b': balloon[0] += 1; break;
                case 'a': balloon[1] += 1; break;
                case 'n': balloon[2] += 1; break;
                case 'l': balloon[3] += 1; break;
                case 'o': balloon[4] += 1; break;
                default:break;
            }
        }
        cout << balloon[0] << balloon[1]<< balloon[2]<< balloon[3]<< balloon[4];
        for(int j=0; j<5;++j)
        {
            if(!balloon[j])
                return 0;
        }
        int temp1 = balloon[0],temp2;
        int i=1;
        for(; i < 3; ++i)
        {
            if(balloon[i] < temp1)
                temp1 = balloon[i];  // 找到bal中最小的数
        }
        if(balloon[3] > balloon[4])
            temp2 = balloon[4];
        else
            temp2 = balloon[3];  // 找到on中最小的数
        if(temp1 > temp2/2)
            return temp2/2;
        else
            return temp1;
            
        
        
        
        
    }
};
