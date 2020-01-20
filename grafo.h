#include<iostream>
#include <list> 
#include<string>
#include <bits/stdc++.h> 
#include"lista_simplemente_enlazada.h"

using namespace std;

struct arista{//cada arista va a tener su dato y un apuntador ahace siguiente arista
	int datoDestino;
	arista * sgteArista;//
	int peso;
};

struct vertice{//estructura para el vertice. Tendra un dato, un puntero hacia otro verice y otro puntero hacia la cabeza de mi lista de aristas
	int datoOrigen;
	arista *adyArista;
	vertice * sgteVertice;
};

typedef arista * pArista;//pArista es un puntero hacia arista: se lee de atraz para adelante
typedef vertice * pVertice;

class grafo{//peirmo se ingresan los vertices y despues las aristas
	private:
		pVertice pGrafo;
		
	public:
		grafo();
//		~grafo();
		void insertarVertice(int x);//cuando se cree un grafo lo 1ro que se inserta son los vertices o nodos y despues las aristas
		void insertarArista(int x, int y);//x=origen    ,     y= destino    Recordar que una arista vienen de un número y se va a otro numero, es un enlace
		void insertarAristaConPeso(int x, int y,int w);//w: peso
		void imprimirGrafo();
		void imprimirGrafoConPeso();
		pVertice getDirVert(int x);//falta implementar
		pArista getDirAris(int vertDato,int aristDato);
		pVertice getRaiz();
		int cantidadDeArista(int verticeDato);
		void eliminarUnaArista(int verticeDato,int aristaDato);
		void eliminarTodasAristas(int verticeDato);
		void eliminarUnVertice(int verticeDato);//Para hacer esto antes tienen que ya haberse eliminado todas sus aristas
		bool estaEnElVertice(int verticeDato,int aristaDato);
		bool hayCamino(int u,int v);
		int cantidadDeVertices();
//		bool imprimeSiHayCamino(int u, int v);//
		string secuenciaDeCamino(int s, int d);
//		int valorDeAristaEnPosicionDada(int verticeDato,);
		bool camino(int u, int v);
		
};

grafo::grafo(){
	pGrafo=NULL;//ver si funciona con 0 o se tiene que porner NULL. Sí funciona.
}

void grafo::insertarVertice(int x){//siempre se esta insertando por encima de mi vertice ya existente.
	pVertice p=new vertice();//lo declaro y separo memoria
	p->datoOrigen=x;
	p->adyArista=0;//cuando declaro un vertice, este todavía no apunta a ningún arista.
	p->sgteVertice=pGrafo;//al incio pGrafo es NULL;
	pGrafo=p;	
}//correr esto en la cabeza par aal menos el ingreso de 2 vértices.

void grafo::insertarArista(int x, int y){//debo tener al menos un vértice par apoder ingresar aristas.
	pVertice p;
	p=pGrafo;//para el caso en que pGrafo=NULL no realizo nada, ya que no puedo almacenar mis aristas.
	if (p!=NULL){//para el caso en que pGrafo!=0 tengo que buscar donde pondré mi arista, es decir tengo que buscar la dirección del valor x.
		while(p->datoOrigen!=x){
			p=p->sgteVertice;
		}
		if(p!=NULL){//o sea lo ha encontrado. Ahora tengo que preguntarme si ya tengo aristas o no.
			pArista a;
			a=new arista;//como voy a ingresar una nueva arista, sí pido memoria.
			a->datoDestino=y;//tener en cuenta que al incio no s ehan puesto aarista, es decir ady arista al inicio es NULL.
			a->sgteArista=p->adyArista;//se ingresan las aristas por el inicio. Tener en cuenta que ya puedne haber aristas para un vértice dado
			p->adyArista=a;
		}//imaginar que al menos ingresan dos aristas, correrlo en la cabeza.
	}
}

void grafo::insertarAristaConPeso(int x, int y,int w){
	pVertice p;
	p=pGrafo;//para el caso en que pGrafo=NULL no realizo nada, ya que no puedo almacenar mis aristas.
	if (p!=NULL){//para el caso en que pGrafo!=0 tengo que buscar donde pondré mi arista, es decir tengo que buscar la dirección del valor x.
		while(p->datoOrigen!=x){
			p=p->sgteVertice;
		}
		if(p!=NULL){//o sea lo ha encontrado. Ahora tengo que preguntarme si ya tengo aristas o no.
			pArista a;
			a=new arista;//como voy a ingresar una nueva arista, sí pido memoria.
			a->datoDestino=y;//tener en cuenta que al incio no s ehan puesto aarista, es decir ady arista al inicio es NULL.
			a->peso=w;
			a->sgteArista=p->adyArista;//se ingresan las aristas por el inicio. Tener en cuenta que ya puedne haber aristas para un vértice dado
			p->adyArista=a;
		}//imaginar que al menos ingresan dos aristas, correrlo en la cabeza.
	}
}

void grafo::imprimirGrafo(){//Para imprimir, tengo que imprimir 1ro los vertices y para c/ vértice imprimir su recorrido de aristas. 
	pVertice p;
	p=pGrafo;
	pArista ra;//recorrido de arista
	if (p==NULL) cout<<"Grafo vacio"<<endl;
	else{
		while(p!=NULL){//pueden haber vértices que no tengas aristas. ver las fotos
			cout<<p->datoOrigen<<"\t\t";
			ra=p->adyArista;
			while(ra!=NULL){
				cout<<ra->datoDestino<<"   ";
				ra=ra->sgteArista;
			}
			cout<<endl;
			p=p->sgteVertice;
		}//esto sería como imprimir una matriz
	}
}

void grafo::imprimirGrafoConPeso(){
	pVertice p;
	p=pGrafo;
	pArista ra;//recorrido de arista
	if (p==NULL) cout<<"Grafo vacio"<<endl;
	else{
		while(p!=NULL){//pueden haber vértices que no tengas aristas. ver las fotos
			cout<<p->datoOrigen<<"\t\t";
			ra=p->adyArista;
			while(ra!=NULL){
				cout<<ra->datoDestino<<"_"<<ra->peso<<"   ";
				ra=ra->sgteArista;
			}
			cout<<endl;
			p=p->sgteVertice;
		}//esto sería como imprimir una matriz
	}
}

pVertice grafo::getRaiz(){
	return pGrafo;
}

pVertice grafo::getDirVert(int x){
	pVertice p=pGrafo;
	while(p!=NULL) {
		if((p->datoOrigen)==x) return p;
		p=p->sgteVertice;
	}
	return NULL;
}

pArista grafo::getDirAris(int vertDato,int aristDato){//Para buscar la direccion d euna arista, se tienen que decir de que vertice se esta bucando, o se de donde sale
	pVertice p=getDirVert(vertDato);
	if(p==NULL) return NULL;
	else{
		pArista a=p->adyArista;
		while(a!=NULL){
			if ((a->datoDestino)==aristDato) return a;
			a=a->sgteArista;
		}
		return NULL;
	}
}

int grafo::cantidadDeArista(int verticeDato){//me devuelve la cantidad de aristas para un vertice dado
	pVertice p=getDirVert(verticeDato);
	int cantArist=0;
	if(p==NULL) return 0;
	else{
		pArista a=p->adyArista;
		if (a==NULL) return 0;
		else{
			while(a!=NULL){
				a=a->sgteArista;
				cantArist++;
			}
			return cantArist;	
		}
		
	}
}

void grafo::eliminarUnaArista(int verticeDato,int aristaDato){
	pVertice p=getDirVert(verticeDato);
	if(p==NULL) cout<<"\nEl vertice ingresano NO esta.\n";
	else{
		pArista a=p->adyArista,b=0;
		pArista primeraArista=a;
		pArista ultimaArista=0,anteriorALaUltimaArista=0;
		
		while(a!=NULL){
			ultimaArista=a;
			a=a->sgteArista;
		}
		a=p->adyArista;//tengo que regresar el a
		while(a!=ultimaArista){
			anteriorALaUltimaArista=a;
			a=a->sgteArista;
		}
		a=p->adyArista;
		while(a!=NULL){
			if ((a->datoDestino)==aristaDato) break;
			a=a->sgteArista;
		}
		if (a==NULL) cout<<"\nSe encontro el vertice, pero NO se encontro a la arista\n";
		else{//para el caso que a sea distinto de null. Voy a tener 3 casos: cuando quiero elimnarl al incio, al final o al intermedio
			if(a==primeraArista){
				p->adyArista=a->sgteArista;
				delete a;
			}
			else if(a==ultimaArista){
				anteriorALaUltimaArista->sgteArista=NULL;
				delete ultimaArista;
			}
			else{//para el caso en que a no sea ni la 1ra ni la ultima arista
				pArista anteriorAAristaQueEstaEnElIntermedio=0;
				b=p->adyArista;
				while((b!=a) && b!=NULL){
					anteriorAAristaQueEstaEnElIntermedio=b;
					b=b->sgteArista;
				}
				anteriorAAristaQueEstaEnElIntermedio->sgteArista=a->sgteArista;
				delete a;
			}
		}	
	}
}

void grafo::eliminarTodasAristas(int verticeDato){
	pVertice p=getDirVert(verticeDato);
	if(p==NULL) cout<<"\nEl vertice ingresano NO esta en el grafo.\n";
	else{
		pArista a=p->adyArista;
		if (a==NULL) cout<<"\nSe encontro al vertice, pero NO TIENEN NINGUNA ARISTA\n";
		else{//a!=NULL
			do{
				eliminarUnaArista(verticeDato,p->adyArista->datoDestino);
			}while(p->adyArista!=NULL);
		}
	}
}

void grafo::eliminarUnVertice(int verticeDato){
	pVertice p=getDirVert(verticeDato),verticeAnteriorAP=0,rp=0,ultimoVertice=0,primerVertice=pGrafo,penultimoVertice=0;//recorrido de p
	if(p==NULL) cout<<"\nEl vertice ingresano NO esta en el grafo.\n";
	else{
		eliminarTodasAristas(verticeDato);//Elimino todas las aristas para ese vertice
		rp=pGrafo;
		while(rp!=NULL){
			ultimoVertice=rp;
			rp=rp->sgteVertice;
		}
		rp=pGrafo;
		while(rp!=ultimoVertice){
			penultimoVertice=rp;
			rp=rp->sgteVertice;
		}
		rp=pGrafo;
		while(rp!=p){
			verticeAnteriorAP=rp;
			rp=rp->sgteVertice;
		}
		
		if(p==primerVertice){
			pGrafo=primerVertice->sgteVertice;
			delete primerVertice;
		}
		else if(p==ultimoVertice){
			penultimoVertice->sgteVertice=NULL;
			delete ultimoVertice;
		}
		else{
			verticeAnteriorAP->sgteVertice=p->sgteVertice;
			delete p;
			
		}
	}
}

bool grafo::estaEnElVertice(int verticeDato,int aristaDato){
	pVertice p=getDirVert(verticeDato);
	if(p==NULL) cout<<"\nEl vertice ingresano NO esta en el grafo.\n";
	else{
		pArista a=p->adyArista;
		if (a==NULL) return false;//quier decir que ese vertice no tienene aristas
		else{
			while(a!=NULL){
				if((a->datoDestino)==aristaDato) return true;
				a=a->sgteArista;
			}
			return false;//a ya es NULL y no lo ha encontrado
		}
	}
}

int grafo::cantidadDeVertices(){
	pVertice p=pGrafo;
	int contVert=0;
	if(p==NULL) return 0;
	else{
		while (p!=NULL){
			p=p->sgteVertice;
			contVert++;
		}
		return contVert;
	}
}
list<int> camino2;
bool grafo::hayCamino(int s, int d){
	pVertice p=getDirVert(s);
	if(p==NULL){
		return false;
	} 
	pArista a,ra;//al incio a punta a "a"
	camino2.push_back(s);
	if (s==d){
		camino2.push_back(s);//para el caso en que se quiera ir a donde se está ya ha solucion
		return true;//para el caso en que se quiera ir a donde se está ya ha solucion
	} 
	bool *visited = new bool[cantidadDeVertices()]; //al unicio no he visitado ninguna arista
	list<int> queue;//creo una lista la cual va a contener a los valores que faltan analizar para ver si es que entres sus aristas esta la arista que se busca "d"
	visited[s] = true;//de donde parto sí lo he visitado, por ende es true
	queue.push_back(s);//al incio voy a analizar a "s".
	list<int>::iterator i; //creo un iterator para ir moviendome entre los elementos de queue
	while (!queue.empty()){//al incio queue contienen a s por enede es distinto de vacío
		s = queue.front();//se pregunta cual es el 1er elemento de mi lita queue
		queue.pop_front(); //Exptraigo ese numero de mi lista queue para no analizarla de nuevo
		p=getDirVert(s);
		a=p->adyArista;
		ra=a;
		while(ra!=NULL){
			if ((ra->datoDestino)==d){
				camino2.push_back(d);
				return true;//si para ese vertice una de sus aristas es la arista de llegada buscada "d"
			}
			if (!visited[ra->datoDestino]){//si a ese numero aúno no lo he visitado como un vertice, entonces pongo que ya lo visité
				visited[ra->datoDestino] = true;//y lo agrego al final de mi lista queue para que aspi tenga un elemento mas y asi se 
				queue.push_back(ra->datoDestino);//pueda seguir corriendo el while(!queue.empty())	
				camino2.push_back(s);
			}
			
			ra=ra->sgteArista;
		}
	}
	return false;//para el caso en que se salga del while(!queue.empty())  sin encontra algun camino, se retorna false
}

string grafo::secuenciaDeCamino(int s, int d){
	pVertice p=getDirVert(s);
	int sumaCamino=0;
	if(p==NULL){
		return "\nNo hay camino\n";
	} 
	pArista a,ra;//al incio a punta a "a"
	camino2.push_back(s);
	if (s==d){
		camino2.push_back(s);//para el caso en que se quiera ir a donde se está ya ha solucion
		return "\nYa estas en la psoicoona  donde quieres llegarm si hay camino\n";//para el caso en que se quiera ir a donde se está ya ha solucion
	} 
	bool *visited = new bool[cantidadDeVertices()]; //al unicio no he visitado ninguna arista
	list<int> queue;//creo una lista la cual va a contener a los valores que faltan analizar para ver si es que entres sus aristas esta la arista que se busca "d"
	visited[s] = true;//de donde parto sí lo he visitado, por ende es true
	queue.push_back(s);//al incio voy a analizar a "s".
	list<int>::iterator i; //creo un iterator para ir moviendome entre los elementos de queue
	while (!queue.empty()){//al incio queue contienen a s por enede es distinto de vacío
		s = queue.front();//se pregunta cual es el 1er elemento de mi lita queue
		queue.pop_front(); //Exptraigo ese numero de mi lista queue para no analizarla de nuevo
		p=getDirVert(s);
		a=p->adyArista;
		ra=a;
		while(ra!=NULL){
			if ((ra->datoDestino)==d){
				camino2.push_back(d);
				sumaCamino+=ra->peso;
				stringstream ss;
				ss << sumaCamino;
				string str = ss.str();
				return str;//si para ese vertice una de sus aristas es la arista de llegada buscada "d"
			}
			if (!visited[ra->datoDestino]){//si a ese numero aúno no lo he visitado como un vertice, entonces pongo que ya lo visité
				visited[ra->datoDestino] = true;//y lo agrego al final de mi lista queue para que aspi tenga un elemento mas y asi se 
				queue.push_back(ra->datoDestino);//pueda seguir corriendo el while(!queue.empty())	
				camino2.push_back(s);
				sumaCamino+=ra->peso;
			}
			
			ra=ra->sgteArista;
		}
	}
	return "\nNO SE ha encontrado aulgun camino\n";
}




lista ListVerticesYaVisitados, ListVerticesPendientes,LCamino;;
bool grafo::camino(int u, int v){//hecho por MÍ
	int entroBucle;
	if (u==v){
		if(getDirVert(u)==NULL) return false;
		else{
			LCamino.insertar_final_2(u);
			return true;
		} 
		
	} 
	else{
		pVertice p=getDirVert(u);
		int num__;
		pArista ra;//este es el que hace mi recorrido en todas las aristas par aun vertice dado
		if (p==NULL) return false;//cuando mi u no esiste en mi grafo
		else{
			if(p->adyArista==NULL) return false;//quiere decir que el nodo vertice del que se parte no tienen aristas
			else{//entonces existe al menos una arista en mi vertice u
				ListVerticesPendientes.insertar_final_2(u);//le vamos insertando al final y se le va quitando por el inicio.
				
				//ra=p->adyArista;//al inico este ra es distinto de null, si es que ha ingresado aca
				while(ListVerticesPendientes.long_lista()!=0){//caundo ya no tenga nada en mi ListVerticesPendientes se detienen este bucle
					ra=getDirVert(ListVerticesPendientes.retornaPrimerElemento())->adyArista;
					LCamino.insertar_final_2(ListVerticesPendientes.retornaPrimerElemento());
					entroBucle=0; 
					while(ra!=NULL){
	//					num__=ListVerticesPendientes.retornaPrimerElemento();
						num__=ra->datoDestino;
						if(num__==v){
							LCamino.insertar_final_2(num__);
							return true;//juto ese 1era arista es igual al valor buscado
						} 
						else{//quiere decir que el dato de ese ra no es igual al numero destino que se busca, pero aun ese numero se 
							//debe de analizar como si fuese un vertice, entonces lo acoplamos a lista de vertices pendientes
							if(!(ListVerticesPendientes.estaEnLaLista(num__))&& !ListVerticesYaVisitados.estaEnLaLista(num__)){
								ListVerticesPendientes.insertar_final_2(num__);
							} 
						}
						ra=ra->sgteArista;
						entroBucle=1;
					}
					if(entroBucle==0){
						LCamino.eliminar_nodo(ListVerticesPendientes.retornaPrimerElemento());
					}
					ListVerticesYaVisitados.insertar_final_2(ListVerticesPendientes.retornaPrimerElemento());
					ListVerticesPendientes.eliminarElElementoMasALaIzquierda();	//como ya he visitado ese numero lo eliminao de mi lista d ependientes	
				}
				return false;	
			}
		}
		
	}
	
}


//
//bool grafo::imprimeSiHayCamino(int u, int v){
//	if (u==v){
//		if(getDirVert(u)==NULL) return false;
//		else{
//			LCamino.insertar_final_2(u);
//			return true;
//		} 	
//	} 
//	else{
//		pVertice p=getDirVert(u);
//		int num__;
////		int auxNumerico;
//		pArista ra;//este es el que hace mi recorrido en todas las aristas par aun vertice dado
//		if (p==NULL) return false;//cuando mi u no esiste en mi grafo
//		else{
//			if(p->adyArista==NULL) return false;//quiere decir que el nodo vertice del que se parte no tienen aristas
//			else{//entonces existe al menos una arista en mi vertice u
//				ListVerticesPendientes.insertar_final_2(u);//le vamos insertando al final y se le va quitando por el inicio.
//				
//				//ra=p->adyArista;//al inico este ra es distinto de null, si es que ha ingresado aca
//				while(ListVerticesPendientes.long_lista()!=0){//caundo ya no tenga nada en mi ListVerticesPendientes se detienen este bucle
//					ra=getDirVert(ListVerticesPendientes.retornaPrimerElemento())->adyArista;
//					LCamino.insertar_final_2(ListVerticesPendientes.retornaPrimerElemento());
////					auxNumerico=1;
//					while(ra!=NULL){
//	//					num__=ListVerticesPendientes.retornaPrimerElemento();
//						num__=ra->datoDestino;
//						if(num__==v){
//							LCamino.insertar_final_2(num__);
//							return true;//juto ese 1era arista es igual al valor buscado
//						} 
//						else{//quiere decir que el dato de ese ra no es igual al numero destino que se busca, pero aun ese numero se 
//							//debe de analizar como si fuese un vertice, entonces lo acoplamos a lista de vertices pendientes
//							if(!(ListVerticesPendientes.estaEnLaLista(num__))&& !ListVerticesYaVisitados.estaEnLaLista(num__)){
//								ListVerticesPendientes.insertar_final_2(num__);
//							} 
//						}
//						ra=ra->sgteArista;
////						auxNumerico=0;
//					}
////					if(auxNumerico==1){//quiere decir que no se ha ingresado al while(ra!=NULL)
////						LCamino.eliminar_nodo(ListVerticesPendientes.retornaPrimerElemento());
////					}
//					ListVerticesYaVisitados.insertar_final_2(ListVerticesPendientes.retornaPrimerElemento());
//					ListVerticesPendientes.elimina_elemento_mas_a_la_derecha();	//como ya he visitado ese numero lo eliminao de mi lista d ependientes	
//				}
//				return false;	
//			}
//		}
//		
//	}
//}


//void grafo::imprimeSiHayCamino(int s, int d){
//	list<int> camino;
//	pVertice p=getDirVert(s);
//	if(p==NULL) cout<<"\No hay camino\n";
//	pArista a,ra;//al incio a punta a "a"
//	if (s==d){
//		camino.push_back(s);//para el caso en que se quiera ir a donde se está ya ha solucion
//		camino.push_back(s);
//	} 
//	bool *visited = new bool[cantidadDeVertices()]; //al unicio no he visitado ninguna arista
//	list<int> queue;//creo una lista la cual va a contener a los valores que faltan analizar para ver si es que entres sus aristas esta la arista que se busca "d"
//	visited[s] = true;//de donde parto sí lo he visitado, por ende es true
//	queue.push_back(s);//al incio voy a analizar a "s".
//	list<int>::iterator i; //creo un iterator para ir moviendome entre los elementos de queue
//	while (!queue.empty()){//al incio queue contienen a s por enede es distinto de vacío
//		s = queue.front();//se pregunta cual es el 1er elemento de mi lita queue
//		queue.pop_front(); //Exptraigo ese numero de mi lista queue para no analizarla de nuevo
//		p=getDirVert(s);
//		a=p->adyArista;
//		ra=a;
//		while(ra!=NULL){
//			if ((ra->datoDestino)==d);// cout<<" "<<d<<" ";//si para ese vertice una de sus aristas es la arista de llegada buscada "d"
//			if (!visited[ra->datoDestino]){//si a ese numero aúno no lo he visitado como un vertice, entonces pongo que ya lo visité
//				visited[ra->datoDestino] = true;//y lo agrego al final de mi lista queue para que aspi tenga un elemento mas y asi se 
//				queue.push_back(ra->datoDestino);//pueda seguir corriendo el while(!queue.empty())	
//				camino.push_back(s);
//			}
//			
//			ra=ra->sgteArista;
//		}
//	}
//	list<int>::iterator it2;
//	for(it2=camino.begin();it2!=camino.end();it2++){//es un iterador, no e sun numero, por enen no se puede poner el < o >
//		cout<<*it2<<" ";
//	}
//}





//void grafo::imprimeSiHayCamino(int s, int d){
//	list<int> camino;
//	pVertice p=getDirVert(s);
//	if(p==NULL) cout<<"\No hay camino\n";
//	pArista a,ra;//al incio a punta a "a"
//	if (s==d) cout<<"\nCamino: "<<s<<" "<<s<<"\n";//para el caso en que se quiera ir a donde se está ya ha solucion
//	bool *visited = new bool[cantidadDeVertices()]; //al unicio no he visitado ninguna arista
//	list<int> queue;//creo una lista la cual va a contener a los valores que faltan analizar para ver si es que entres sus aristas esta la arista que se busca "d"
//	visited[s] = true;//de donde parto sí lo he visitado, por ende es true
//	queue.push_back(s);//al incio voy a analizar a "s".
//	list<int>::iterator i; //creo un iterator para ir moviendome entre los elementos de queue
//	cout<<s<<" ";
//	while (!queue.empty()){//al incio queue contienen a s por enede es distinto de vacío
//		s = queue.front();//se pregunta cual es el 1er elemento de mi lita queue
//		queue.pop_front(); //Exptraigo ese numero de mi lista queue para no analizarla de nuevo
//		p=getDirVert(s);
//		a=p->adyArista;
//		ra=a;
//		while(ra!=NULL){
//			if ((ra->datoDestino)==d);// cout<<" "<<d<<" ";//si para ese vertice una de sus aristas es la arista de llegada buscada "d"
//			if (!visited[ra->datoDestino]){//si a ese numero aúno no lo he visitado como un vertice, entonces pongo que ya lo visité
//				visited[ra->datoDestino] = true;//y lo agrego al final de mi lista queue para que aspi tenga un elemento mas y asi se 
//				queue.push_back(ra->datoDestino);//pueda seguir corriendo el while(!queue.empty())	
//				cout<<" "<<ra->datoDestino<<" ";
//			}
//			
//			ra=ra->sgteArista;
//		}
//	}
//	//cout<<"\nNo se ha encontrado un CAMINO\n";//para el caso en que se salga del while(!queue.empty())  sin encontra algun camino, se retorna false
//}









