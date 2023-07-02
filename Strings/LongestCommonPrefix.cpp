/* TC-> O(n*m), SC->O(1) */
class Solution {
public:
    string getCommon(string s1, string s2){
        int n1=s1.length();
        int n2=s2.length();
        int m=min(n1,n2);
        int i=0;
        string res = "";
        while(i<m){
            if(s1[i]==s2[i]){
                res += s1[i];
            }
            else{
                break;
            }
            ++i;
        }
        return res;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1 and !strs[0].empty()){
            return strs[0];
        }
        string ans=getCommon(strs[0],strs[1]);
        
        for(int i=1; i<n-1; ++i){
            int j=i+1;
            string tmp="";
            tmp += getCommon(strs[i],strs[j]);
            if(ans.length()>tmp.length()){
                int idx = ans.find(tmp);
                if(idx>=0 and idx<=ans.length()-1){
                    ans=tmp;
                }else{
                    return "";
                }
            }
            //tmp>ans
            int idx = tmp.find(ans);
            if(idx>=0 and idx<=tmp.length()-1){
                continue;
            }
            else{
                return "";
            }
        }

        return ans;
    }
};