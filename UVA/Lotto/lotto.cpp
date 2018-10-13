#include <iostream>
#include <vector>
using namespace std;

void Backtracking(int k, int numero, int loto[], int posicion, vector<int> lista){
	lista.push_back(numero);
	int max_posicion=k-6+lista.size();
	int dif=(k-1-posicion);
	if(lista.size()==6 ){ 
		for(int i=0; i<6; i++){
			if(i!=0){cout<<" ";}
			cout<<lista[i];
		}
		cout<<endl;
		lista.clear();
	}
	else if(dif+lista.size()+1==6){
		for(int i=0; i<lista.size(); i++){
			if(i!=0){cout<<" ";}
			cout<<lista[i];
		}		
		for(int i=0; i<5; i++){
			if(lista.size()!=0){cout<<" ";}
			else if(i!=0){cout<<" ";}
			cout<<loto[posicion+i];
		}
		cout<<endl;
		lista.clear();	
	}
	else if(max_posicion<posicion){
		lista.clear();
		return;
	}
	else{
		int candidatos=max_posicion-posicion; 
		int j=0;
		while(j<candidatos){
			j++;
			Backtracking(k, loto[posicion+j], loto, posicion+j, lista);	
		}		
	}
	return;
}


int main(){
	int k;
	int contador=0;
	vector<int> cadena;
	while(true){ 
		cin>>k;
		if(k==0){
			break;
		}
		if(contador>0){
			cout<<endl;
		}
		int loto[k];
		for(int i=0; i<k; i++){
			int num;
			cin>>num;
			loto[i]=num;
		}
		int candidatos=k-6;
		int j=0;
		while(j<=candidatos){
			Backtracking(k, loto[j], loto, j, cadena);
			j++;
		}
		contador++;		 
	}
	return 0;
}


