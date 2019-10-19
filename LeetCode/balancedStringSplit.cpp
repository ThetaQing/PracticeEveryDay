/***********问题描述***********************
*  在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。

* 给出一个平衡字符串s，请你将它分割成尽可能多的平衡字符串。

* 返回可以通过分割得到的平衡字符串的最大数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-a-string-in-balanced-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

/***************解题思想***************
* 1、 遍历原串，记录当前 LL 和 RR 的数量差，如果数量差为 0 就表示可以以当前位置作为一个分割点。
* 2、基于栈的实现，当栈中没有元素时，当前元素入栈；当栈中有元素时，若栈顶字符与当前字符一致，则入栈，否则出栈；检查当前栈是否为空，若为空，平衡次数+1。
* 说明：第一次求解这个问题的基本思路就是基于栈实现的，但是遇到问题时，没有理解平衡次数+1的判断条件。
******************/
class Solution {
public:
    int balancedStringSplit_1(string s) {
        int tempL=0, tempR=0;
        int count=0;
        for(int i=0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case 'L': tempL++; break;
                case 'R': tempR++; break;
                default: return 0;
            }
            if(tempL == tempR)
            {
                
                tempL = 0;
                tempR = 0;
                count ++;
            }
        }
        return count;        
    }
    
    int int balancedStringSplit_2(string s) {
        stack <char> temp_stack;
        int count=0;  //计数
        for(int i=0; i< s.size();++i)
        {
          if(temp_stack.empty())
          {            
            temp_stack.push(s[i]);
          }
          else
          {
            if(s[i] == temp_stack.top())
              temp_stack.push(s[i]);
            else
              temp_stack.pop();
          }
          // 如果是空，+1，注意这里要放在pop和push的后面
            if(temp_stack.empty())
                count = count + 1;
        }
        return count;
    
    }
    
};
