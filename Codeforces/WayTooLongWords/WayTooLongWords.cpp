#include <iostream>
#include <string>
using namespace std;
int main(){
	int palabras;
	cin>>palabras; 
	string words[palabras];
	for(int i=0; i<palabras; i++){
		string word;
		cin>>word;
		words[i]=word;
	}
	for(int i=0; i<palabras; i++){
		int largo=words[i].length();
		int largo_medio=largo-2;
		string num=to_string(largo_medio);
		if(largo>10){
			cout<< words[i].at(0)+num+words[i].at(largo-1);
		}
		else{
			cout<<words[i];		
		}
		if(i<palabras-1){
			cout<<endl;
		}
	}
	return 0;
}
