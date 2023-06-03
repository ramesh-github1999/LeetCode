class Solution {
public:
    string simplifyPath(string path) {
        string ans="/";
        int n=path.length();
        stack<string>st;
        string temp="";
        if(path[n-1]!='/') path+="/";
        n++;
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                if(temp=="" || temp=="/" || temp==".") {
                }
                 else if(temp==".." ){
                     if(st.size()>0) st.pop();
                 }
                else st.push(temp);
                temp="";
            }
            else temp+=path[i];
        }
        string res="";
        while(st.size()>0){
            string temp=st.top();
            reverse(temp.begin(),temp.end());
            res+=temp;
            res+="/";
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(res.length()==0) return "/";
        return res;
        
    }
};


class Solution2 {
public:
    string simplifyPath(string path) {
        string ans="/";
        int n=path.length();
        stack<string>st;
        string temp="";
        if(path[n-1]!='/') path+="/";
        n++;
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                if(temp=="" || temp=="/" || temp==".") {
                }
                 else if(temp==".." ){
                     if(st.size()>0) st.pop();
                 }
                else st.push(temp);
                temp="";
            }
            else temp+=path[i];
        }
        string res="";
        while(st.size()>0){
            res="/"+st.top()+res;
            st.pop();
        }
        if(res.length()==0) return "/";
        return res;
        
    }
};

