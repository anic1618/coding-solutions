Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]


const int MAX_NO_NODE = 40001;
int nextN[MAX_NO_NODE][26];
int endN[MAX_NO_NODE];
int sz=0;
void insertW(string&str,int sti,int endi){//[sti,endi)]
    if(sti == endi) return;
    //cout<<str.substr(sti,endi)<<"--\n";
    int n =0,e;
    for(int i = sti;i<endi;i++){
        e = str[i]-'a';
        if(!nextN[n][e]) nextN[n][e] = ++sz;
        n = nextN[n][e];
    }
    endN[n]++;
}

bool searchW(const string& str,int sti,int endi){
    if(sti == endi) return false;
   // cout<<str.substr(sti,endi)<<"-**-\n";
    int n =0,e;
    for(int i = sti;i<endi;i++){
        e = str[i]-'a';
        if(!nextN[n][e]) return false;
        n = nextN[n][e];
    }
    return endN[n];
   
}


vector<int> strTokenize(const string& str){
    vector<int> tokens;
    tokens.push_back(-1);
    int prev =0,i;
    for(i = 0;i<str.size();i++){
        if(str[i]=='_') { 
            //insertW(A,prev,i);
            tokens.push_back(i);
            //prev = i+1;
        }
    }
    if(tokens.back() < i){
        //insertW(A,prev,i);
        tokens.push_back(i);
    }
    
    return tokens;
}

bool myComp(const pair<int,int> &lf,const pair<int,int> &rt ){
    if(lf.second > rt.second) return true;
    else if(lf.second < rt.second) return false;
    else{
         return (lf.first < rt.first);
    }
}
vector<int> Solution::solve(string A, vector<string> &B) {
    memset(nextN,0,4*MAX_NO_NODE*26);
    memset(endN,0,4*MAX_NO_NODE);
    int prev =0,i;
    vector<int> tmp,ans;
    vector< pair<int,int> > pre;
    
    if(!A.size()) return ans; 
    if(B.size() == 0) {
        for(int i=0;i<A.size();i++) {
            ans.push_back(i);
        }
        return ans;
    }
    
    tmp = strTokenize(A);
    //for(int i:tmp) cout<<i<<"--";
    for(int i = 1;i<tmp.size();i++){
        insertW(A,tmp[i-1]+1,tmp[i]);
    }
    
    int cnt=0;
    for(int i = 0;i<B.size();i++){
        string s = B[i];
        tmp = strTokenize(s);
        //for(int i:tmp) cout<<i<<"===";
        cnt=0;
        for(int j = 1;j<tmp.size();j++){
            if(searchW(s,tmp[j-1]+1,tmp[j])){
                cnt++;
            }
        }   
        pre.push_back(make_pair(i,cnt));
    }
    
   /* for(pair< int,int > p:pre){
        cout<<p.second<<" ";
    }
    cout<<"\n";*/
    
    
    sort(pre.begin(),pre.end(),myComp);
    
    for(pair< int,int > p:pre){
        ans.push_back(p.first);
    }
        
    return ans;
}
