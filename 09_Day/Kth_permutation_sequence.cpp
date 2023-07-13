string kthPermutation(int n, int k) {
    string s="";
    int fact=1;
    for(int i=1;i<n;i++){
        fact*=i;
        s+=((char)i+'0');
    }
    s+=((char)n+'0');
    string res="";
    k--;
    while(true){
        res+=s[k/fact];
        s.erase(s.begin()+k/fact);
        if(s.size()==0){
            break;
        }
        k%=fact;
        fact/=s.size();
    }
    return res;
}