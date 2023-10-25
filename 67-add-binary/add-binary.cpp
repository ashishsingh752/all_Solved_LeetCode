class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size(), n2=b.size();
    
         
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string str="";
        int c=0;
        if(n1>n2){
        for(int i=0;i<n1;i++){
            if(i<n2){
               int p=a[i]-'0';
               int q=b[i]-'0'; 
               int digit = (p+q+c)%2;
               c=(p+q+c)/2;
               str.push_back(digit+'0');
            }
            else{
                int val = (a[i]-'0'+c);
                int di = val%2;
                c=val/2;
                str.push_back(di+'0');
            }
        }
        if(c){
            str.push_back(c+'0');
        }
        }
        else{
                for(int i=0;i<n2;i++){
                    if(i<n1){
                    int p=a[i]-'0';
                    int q=b[i]-'0'; 
                    int digit = (p+q+c)%2;
                    c=(p+q+c)/2;
                    str.push_back(digit+'0');
                    }
                    else{
                        int val = (b[i]-'0'+c);
                        int di = val%2;
                        c=val/2;
                        str.push_back(di+'0');
                    }
                }
                if(c){
                    str.push_back(c+'0');
                }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};