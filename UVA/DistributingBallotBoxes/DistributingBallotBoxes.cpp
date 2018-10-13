#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int ciudades, cajas, hab;
    
    while(true){
        cin>>ciudades;
      	cin>>cajas;
      	int poblacion[ciudades];
        if(ciudades == -1){ 
			break;
        }
        
        int p1=1;
      	int p2=0;
      	int mitad;
        
        for(int i = 0;i<ciudades;++i){
            cin>>hab;
          	poblacion[i]=hab;
            p2=max(p2,poblacion[i]);
        }
        
        while(p1<p2){
            mitad=(p1+p2) >> 1;
            int usadas = 0;
            for(int i = 0;i < ciudades;++i){
                usadas += (poblacion[i] + mitad - 1) / mitad;
            }
            
            if(usadas >cajas){ 
            	p1= mitad + 1;
            }
            else{ 
            	p2 = mitad;
            }
        }
        
        printf("%d\n",p1);
    }
    
    return 0;
}
