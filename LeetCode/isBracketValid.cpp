bool isBracketValid(string s) {
        std::stack<char> st;  // 定义栈
        if(!s.size() )
            return 1;  // 如果输入为空，返回1
        // 遍历输入字符串，左括号push到栈中，右括号，如果匹配，把对应的左括号pop掉
        // 否则返回0，因为匹配要符合顺序，所以一旦不符合
        // 这里需要注意一点的是，在top操作之前要先确定存储括号的栈是非空的。

        
        for(auto i:s)
        {
            switch(i)
            {
                case '(': st.push(i); break;
                case '[': st.push(i); break;
                case '{': st.push(i); break;
                case ')': 
                    if(st.empty())
                         return 0;
                    if(st.top() == '(') 
                        st.pop(); 
                    else 
                        return 0; 
                    break;
                case ']': 
                    if(st.empty())
                         return 0;
                    if(st.top() == '[')
                        st.pop(); 
                    else 
                        return 0; 
                    break;
                case '}':
                    if(st.empty())
                         return 0;
                    if(st.top() == '{') 
                        st.pop(); 
                    else 
                        return 0; 
                    break;
                default: break;
            }
        }
        if(st.empty())
            return 1;
        else
            return 0;
        
    }
