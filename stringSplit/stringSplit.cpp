#include <iostream> 
#include <string>
#include <vector>

using namespace std; 

int main(int argc, char const *argv[])
{
	string str1;
	string str2;
	while(cin>> str1){
		cin >> str2; 
		vector<string>temp; 
		temp.push_back(str1);
		temp.push_back(str2);
		for(int i = 0; i < 2; i++){
			string t = temp[i]; 
			int n1 = t.size()/8; 
			int n2 = t.size()%8; 
			for(int k =0; k < 8-n2 && n2>0; k++){
				t+='0';
			}
			if(n2 > 0) 
				n1++; 
			for(int j = 0; j < n1; j++){
				cout<<t.substr(j*8, 8)<<endl; 
			}
		}
	}
	return 0;
}