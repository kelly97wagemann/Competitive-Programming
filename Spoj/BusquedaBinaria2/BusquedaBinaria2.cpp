#include <iostream>
using namespace std;

int main(){
	int qnumeros, consultas;
	cin>>qnumeros;
	int vector[qnumeros];
	cin>>consultas;
	int buscados[consultas];
	for(int i=0; i<qnumeros; i++){
		int num;
		cin>> num;
		vector[i]=num;
	}
	for(int j=0; j<consultas; j++){
		int buscar;
		cin>>buscar;
		buscados[j]=buscar;
	}
	for(int i=0; i<consultas; i++){
		int buscar=buscados[i];
		int pivote1=0;
		int pivote2=qnumeros-1;
		int mitad;
		bool hallado=true;
		mitad=(pivote2-pivote1)/2;
		while(buscar!=vector[mitad] && pivote2>=pivote1){
			if(vector[mitad]>buscar){
				pivote2=mitad-1;
			}
			else if(vector[mitad]<buscar){
				pivote1=mitad+1;
			}
			mitad=pivote1+(pivote2-pivote1)/2;
		}
		if(pivote2<pivote1){
			hallado=false;
		}
		int indice=mitad;
		if(hallado==false){
			indice=-1;
		}
		else{
			while(vector[mitad+1]==vector[mitad]){
				indice=indice+1;
				mitad=mitad+1;
			}
		}
		cout<<indice<<endl;
	}

}
