#include<iostream>
#include "grafos.h"
//#include"lista_simplemente_enlazada.h"
using namespace std;

lista L;

int main(){
	grafo gf,gf2;
	pVertice p;
	int opc=1,auxVert,auxAris,auxArisEli;
	int u,v;
	
//	gf.insertarVertice(1);
//	gf.insertarVertice(2);//así 2 no apunte a ninguna arista igual es un vertice
//	gf.insertarVertice(3);
//	gf.insertarVertice(4);
//	gf.insertarVertice(5);
//	gf.insertarVertice(6);
//	
//	
//	
//	
//	gf.insertarArista(1,2);
//	gf.insertarArista(1,1);
//	gf.insertarArista(1,6);
//	gf.insertarArista(3,2);
//	gf.insertarArista(3,4);
//	gf.insertarArista(3,1);
//	gf.insertarArista(3,5);
//	gf.insertarArista(4,2);
//	gf.insertarArista(5,4);
//	gf.insertarArista(4,1);
//	gf.insertarArista(2,4);
//	gf.insertarArista(6,6);
//	gf.insertarArista(6,2);
//
//	gf.insertarVertice(6);
//	gf.insertarVertice(5);
//	gf.insertarVertice(4);
//	gf.insertarVertice(3);
//	gf.insertarVertice(2);
//	gf.insertarVertice(1);
	
	gf.insertarVertice(1);
	gf.insertarVertice(2);
	gf.insertarVertice(3);
	gf.insertarVertice(4);
	gf.insertarVertice(5);
	gf.insertarVertice(6);
	
	gf.insertarArista(1,6);
	gf.insertarArista(1,2);
	gf.insertarArista(1,5);
	gf.insertarArista(1,4);
	gf.insertarArista(2,3);
	gf.insertarArista(3,5);
	gf.insertarArista(5,6);
//	gf.insertarArista(3,1);
//	gf.insertarArista(4,6);
//	gf.insertarArista(4,5);
	


	
	
	
	cout<<"Vertice\t\t|Arista\n";
	cout<<"-------------------------------------------------\n";
	gf.imprimirGrafo();
	
	
	auxVert=7;//falta implementar apra el caso en que no este en el grafo. Ya está correigo. recordar que no s epuede pedir atributis como dato de un null.
	cout<<"\nObteniendo la direccion del vertice "<<auxVert<<" es: "<<gf.getDirVert(auxVert);
	cout<<endl;
	
	auxVert=2;
	auxAris=4;
	cout<<"\nObteniendo la dierrecion del origen (vertice): "<<auxVert<<" y destino (arista): "<<auxAris<<" el cual es: "<<gf.getDirAris(auxVert,auxAris);
	cout<<"\nCantidad de aristas para el origen (vertice): "<<auxVert<<" es: "<<gf.cantidadDeArista(auxVert);
	
	//Esta bien
	auxVert=4;
	cout<<"\nEl valor de la arista al que le sigue el vertice: "<<auxVert<<" es: ";
	if((gf.getDirVert(auxVert))==NULL) cout<<"El vertice que ha ingresado no esta en el grafo";
	else{
		if((gf.getDirVert(auxVert)->adyArista)==NULL) cout<<" NO hay aristas que le sigan a ese vertice";
		else{
			cout<<gf.getDirVert(auxVert)->adyArista->datoDestino;
		}
	}
	
	auxVert=2;
	auxAris=1;
	cout<<"\nLa arista: "<<auxAris<<" esta en el vertice: "<<auxVert<<" ?\n";
	cout<<gf.estaEnElVertice(auxVert,auxAris)+10;//sí se pueden sumar boleanos con int
	
	
	cout<<"\nLa cantidad de vertices es: "<<gf.cantidadDeVertices()<<endl;
	
	u=1;
	v=4;
//	cout<<"\nHay camino de "<<u<<" a "<<v<<"?\n"<<gf.hayCamino(u,v);
	cout<<"\nLa ruta del camino, si es que lo hay de "<<u<<" a "<<v<<"\n";
	if(gf.hayCamino(u,v)){
//		gf.imprimeSiHayCamino(u,v);//antes llamar si hayCamino
		list<int>::iterator it2;
		for(it2=camino2.begin();it2!=camino2.end();it2++){//es un iterador, no e sun numero, por enen no se puede poner el < o >
		cout<<*it2<<" ";
		}
	}
	else cout<<"\nNo hay camino\n";
	
	
	
	
	
//	cout<<"\nViendo si la direccion de un 6 que esta en vertice es el mismo que la direccion de un6 que esta en una arista\n";
//	cout<<gf.getDirVert(6)<<endl;
//	cout<<gf.getDirAris(1,6)<<endl;//Resulta que no viven en la misma direcion de memoria. Esos sí tienenen los mismos valores
	
	
	
	
	
//	//COMPLEMENTO
//	p=gf.getRaiz();
//	while(p!=NULL){//mi grafo 2 tienen los mismo vertices
//		gf2.insertarVertice(p->datoOrigen);
//		p=p->sgteVertice;
//	}
//	p=gf.getRaiz();
//	pArista a=0;
//	while(p!=NULL){
//		a=p->adyArista;
//		while(a!=NULL){
//			gf2.insertarArista(a->datoDestino,p->datoOrigen);//ver como se ha invertido los elementos que se le ingresan
//			a=a->sgteArista;
//		}
//		p=p->sgteVertice;
//	}
//	cout<<"\nEl complemento es: \n";
//	cout<<"Vertice\t\t|Arista\n";
//	cout<<"-------------------------------------------------\n";
//	gf2.imprimirGrafo();

//	u=1;
//	v=3;
//	cout<<"\nHay camino de "<<u<<" a "<<v<<endl;
//	cout<<gf.imprimeSiHayCamino(u,v);
//	
//	cout<<"\nImprimiendo camino\n";
//	LCamino.imprimir();

	u=1;
	v=3;
	cout<<"\nHay camino de "<<u<<" a "<<v<<endl;
	bool hayCamino_=gf.camino(u,v);
	cout<<hayCamino_;
	cout<<"\nImprimiendo camino\n";
	if(hayCamino_) LCamino.imprimir();
	else cout<<"\nNo hay camino\n";
	
	
	
	
	
	
	
	
	
//	auxVert=5;
//	cout<<"\nElimina todas las aristas y el vertice par aun vertice dado\n";
//	gf.eliminarUnVertice(auxVert);
//	cout<<"\nVertice\t\t|Arista\n";
//	cout<<"-------------------------------------------------\n";
//	gf.imprimirGrafo();
//	cout<<endl;
	
	
	
	
	
//	auxVert=5;
//	cout<<"\nCantidad de aristas: "<<gf.cantidadDeArista(auxVert)<<endl;
//	cout<<"\nEliminando todas las arista para el vertice: "<<auxVert;
//	gf.eliminarTodasAristas(auxVert);
//	cout<<"\nVertice\t\t|Arista\n";
//	cout<<"-------------------------------------------------\n";
//	gf.imprimirGrafo();
//	cout<<endl;
	
	
	
	
	
	
//	cout<<"\nDatoOrigen: "<<gf.getRaiz()->datoOrigen;//5
	
	
	
	
//	auxVert=20;
//	auxArisEli=10;
//	cout<<"\nEliminando del vertice: "<<auxVert<<" la arista: "<<auxArisEli<<endl;
//	gf.eliminarUnaArista(auxVert,auxArisEli);
//	cout<<"\nVertice\t\t|Arista\n";
//	cout<<"-------------------------------------------------\n";
//	gf.imprimirGrafo();
	
	
	
	
	
	
	
	
	
	
	cout<<"\n\nFIN";
	return 0;
}


