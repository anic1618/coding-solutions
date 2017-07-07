#use assert to avoid sigseg
#vector<vector<int>> v  & vector<vector<int>> v(1,vector<int>) has  size =0  
#use stringstream for parsing e.g.
  //Convert _ to spaces
	for(int i=0; i<str.size(); i++)	if(str[i]=='_')	str[i]=' ';
	stringstream ss;
	ss<<str;
	while(ss>>word)	fun(wor);
  
#use const reference when not changing variable

