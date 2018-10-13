#include <iostream>
#include <string>
using namespace std;

int main(){
	int fila;
	int columna;
	int Matriz[5][5];
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			int numero;
			cin>>numero;
			Matriz[i][j]=numero; 
			if(numero!=0){
				fila=i;
				columna=j;		
			}
		}
			
	}
	//sabemos donde esta el 1, por fila y columna
	//deseamos que este en fila 2 y columna 2. ver distancias. abs().
	int movidas;
	int fijar_fila=abs(fila-2);
	int fijar_columna=abs(columna-2);
	movidas=fijar_fila+fijar_columna;
	cout<<movidas;
	

	return 0;
}
