bool isOpeningBracket(char ch) { 
    return ch == '(' or ch == '[' or ch == '{';
}

bool isMatchingBracket(char a,char b){
    if(!isOpeningBracket(a)) return false;
    return (a == '(' and b == ')') or (a == '[' and b == ']') or
           (a == '{' and b == '}');
}
bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(auto &ch:expression){
        if(st.empty()){
            if(isOpeningBracket(ch)){
                st.push(ch);
            }
            else{
                return false;
            }
        }
        else{
            if(isOpeningBracket(ch)){
                st.push(ch);
            }
            else{
                if(isMatchingBracket(st.top(),ch) ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    return st.empty();
}