//n=1,seq = 1
//n=2,seq = 1个1 也就是11
//n=3 seq = 2个1 即为21

string countAndSay(int n) {  
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	string seq = "1";  
	int it = 1;  
	while(it<n)  
	{  
		stringstream newSeq;  
		char last = seq[0];  
		int count =0;  
		//seq[sql.size()]='\0'
		for(int i =0; i<= seq.size();i++)  
		{  
			if(seq[i] ==last)  
			{  
				count ++;  
				continue;  
			}  
			else  
			{  
				newSeq<<count<<last;  
				last = seq[i];   
				count =1;  
			}  
		}  
		seq = newSeq.str();  
		it++;  
	}  
	return seq;  
}  
