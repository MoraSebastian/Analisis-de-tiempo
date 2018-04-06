template<class T>
struct Nodo{
	T x;
	Nodo<T> *sig;
}
class Lista{
	T *cab;
	T *fin;
	int tam;
	
	public:
		Lista(){
			cab=fin=NULL;
			tam=0;
		}
		bool estaVacia(){
			if(tam ==0)
				return true;
			else
				return false;
		}
		
		void anadirFin(T a){
			Nodo<T> b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				fin->sig = b;
				fin = b;
			}
			tam++;
		}
		
		void anadirCabeza(T a){
			Nodo<T> b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				b->sig = cab;
				cab=b
			}
			tam++;
		}
		
		void anadirPos(T a, int Pos){
			Nodo<T> b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia())
				anadirFin(T a);
			if(Pos>tam)
				anadirCabeza(T a);
			else{
				int contador = 1;
				Nodo<T> aux = new Nodo<T>;
				aux = cab;
				while(contador<Pos-1){
					if(contador == Pos){
						b->sig = aux->sig;
						aux->sig = b;
 					}
					else{
						aux = aux->sig;
						contador++;
					}
				}
			}
		}
		
		
		void modificar(T a,int Pos){
			if(estaVacia())
				anadirFin(T a);
			if(Pos>tam)
				anadirCabeza(T a);
			else{
				int contador = 1;
				Nodo<T> aux = new Nodo<T>;
				aux = cab;
				while(contador<Pos){
					if(contador == Pos){
						aux->x =a;
 					}
					else{
						aux = aux->sig;
						contador++;
					}
				}
			}	
		}
		
		void eliminarFinal(){
			int contador = 1;
			Nodo<T> aux = new Nodo<T>;
			aux = cab;
			while(contador<= tam-1){
				if(contador == tam){
					delete aux->sig;
					aux->sig = NULL;
				}
				else{
					aux = aux->sig;
						contador++;
				}
			}
		}
		
		void eliminarInicio(){
			Nodo<T> aux = new Nodo<T>;
			
			if(!estaVacia()){								
				aux = cab->sig;
				cab = aux;
				tam--;
			}
		}
		
		void eliminarPos(int pos){
			if(!estaVacia()){
				
				int contador = 1;
				Nodo<T> aux = new Nodo<T>;
				aux = cab;
				
				while(contador<Pos){
					if(contador == pos){
						aux = aux->sig;    //tengo mis dudas
						tam--;
 					}
					else{
						aux = aux->sig;
						contador++;
					}
				}	
			}
		}	
		bool estaVacia(Lista list){
			if(list.cab==NULL && list.fin==NULL ){   
				return false;
			}
			return true;
		}
	
};
