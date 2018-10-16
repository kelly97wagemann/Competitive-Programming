#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > hallado(int posF, int posC, vector< vector<char> > M, char buscado, int fila, int columna){
	vector< vector<int> > valido;
	if((posF<fila-1) && M[posF+1][posC]==buscado){
		valido.push_back({posF+1, posC});
	}
	if((posF>0) && M[posF-1][posC]==buscado){
		valido.push_back({posF-1, posC});
	}
	if((posC<columna-1) && M[posF][posC+1]==buscado){
		valido.push_back({posF, posC+1});
	}
	if((posC>0) && M[posF][posC-1]==buscado){
		valido.push_back({posF, posC-1});
	}
	if((posF<fila-1) && (posC<columna-1) && M[posF+1][posC+1]==buscado){
		valido.push_back({posF+1, posC+1});
	}
	if((posF<fila-1) && (posC>0) && M[posF+1][posC-1]==buscado){
		valido.push_back({posF+1, posC-1});
	}
	if((posF>0) && (posC>0) && M[posF-1][posC-1]==buscado){
		valido.push_back({posF-1, posC-1});
	}
	if((posF>0) && (posC<columna-1) && M[posF-1][posC+1]==buscado){
		valido.push_back({posF-1, posC+1});
	}

	return valido;
} 

bool Backtracking(vector< vector<char> > M, int posF, int posC, vector<char> P, int pos, int fila, int columna){
	//pos comienza con 1
	char buscar=P[pos];
	vector< vector<int> > V;
	V=hallado(posF, posC, M, buscar, fila, columna);
	if(pos==9 && !V.empty()){ 
		cout<<"YES"<<endl;
		//return true
	}
	else if(V.empty()){ 
		cout<<"NO"<<endl;
		return false;
	}
	else{
		for(int j=0; j<V.size(); j++){
			posF=V[j][0];
			posC=V[j][1];
			bool r=Backtracking(M, posF, posC, P, pos+1, fila, columna);
			if(r){break;}		
		}
	}
	return true;
}

int main(){
	int casos, fila, columna;
	char letra;
	vector<int> posF, posC;
	vector<char> P={'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
	cin>>casos;
	for(int i=0; i<casos; i++){ 
		cin>>fila;
		cin>>columna;
		vector< vector<char> > M(fila, vector<char> (columna));
		posF.clear(); posC.clear();
		for(int j=0; j<fila; j++){ 
			for(int k=0; k<columna; k++){
				cin>>letra;
				if(letra=='A'){
					posF.push_back(j);
					posC.push_back(k);		
				}
				M[j][k]=letra;
			}
		}
		if((fila*columna)<10){ 
			cout<<"NO"<<endl;
			continue;
		}
		if(!posF.empty()){ 
			for(int j=0; j<posF.size(); j++){
				bool r=Backtracking(M, posF[j], posC[j], P, 1, fila, columna);	
				if(r){
					break;
				}			
			}
			
	
		}
		else{
			cout<<"NO"<<endl;
			continue; 
		}
	}
	return 0;
}


