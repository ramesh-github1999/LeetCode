// Time:o(n), space:O(n)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int a=st.top();st.pop();
                int b=st.top(); st.pop();
                if(tokens[i]=="+") st.push(b+a);
                else if(tokens[i]=="-") st.push(b-a);
                else if(tokens[i]=="*") st.push(b*a);
                else if(tokens[i]=="/") st.push(b/a);
                
            }
            else st.push(stoi(tokens[i]));
        }    
        return st.top();

    }
};
