#include<iostream>
#include "grafos.h"
using namespace std;



int lista[]={1,2,5};//midificar aca y en lenLista
int lenLista=3;//tambien modificar aca
int j=0;

	
	
bool hayCaminoSiguiendoLaLista2(pVertice p)	;
	
	
	
	

grafo gf,gf2;
int main(){
	
	pVertice p;
	int opc=1,auxVert,auxAris,auxArisEli;
	int u,v;
	
	gf.insertarVertice(1);
	gf.insertarVertice(2);//así 2 no apunte a ninguna arista igual es un vertice
	gf.insertarVertice(3);
	gf.insertarVertice(4);
	gf.insertarVertice(5);
	
	gf.insertarArista(1,2);
	gf.insertarArista(1,3);
	gf.insertarArista(2,4);
	gf.insertarArista(2,5);
	
	cout<<"Vertice\t\t|Arista\n";
	cout<<"-------------------------------------------------\n";
	gf.imprimirGrafo();
	
	cout<<endl<<"Imprimeindo mi lista"<<endl;
	for (int i=0;i<lenLista;i++){
		cout<<lista[i]<<" ";
	}
	cout<<"\nHay camino siguiendo la lista\n";
	cout<<hayCaminoSiguiendoLaLista2(gf.getRaiz());
	
	
	
	cout<<"\n\nFIN";
	return 0;
	
	
}

bool hayCaminoSiguiendoLaLista2(pVertice p){
	if (p==NULL) return false;
	bool esta=0;
	while(j<lenLista-1){
		esta=gf.estaEnElVertice(lista[j],lista[j+1]);
		if(!(esta)){
			return false;
		}
		j++;
	}
	return true;
}
