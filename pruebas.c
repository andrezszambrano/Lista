#include <stdio.h>
#include "lista.h"
#include "tda_pruebas.h"

#define MAX_ELEMENTOS 100
#define ERROR -1

typedef struct nodo{
	lista_t* lista_apuntada;
	struct nodo* nodo_siguiente;
}nodo_t;

struct lista{
	void* info;
	struct nodo* primer_nodo;
	struct nodo* nodo_final;
	int numero_listas;
};

struct lista_iterador{
	lista_t* lista;
	nodo_t* nodo;
	size_t indice;
};

void negro();


void probar_funcion_crear_lista(tda_pruebas_t* pruebas){
	lista_t* lista= lista_crear();
	tda_pruebas_afirmar(pruebas,"Lista distinto que NULL, creada correctamente.", lista!=NULL);
	lista_destruir(lista);
}

void probar_funcion_lista_insertar_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int elemento=3;
		lista_insertar(lista, &elemento);
		printf("------------------------------------------------\nInsertar un elemento en lista vacía\n");
		tda_pruebas_afirmar(pruebas, "Número de listas es igual a 1.", lista->numero_listas==1);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		tda_pruebas_afirmar(pruebas, "Insertar en lista vacía 100 elementos cambia el número de listas acorde.", lista->numero_listas==100);
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_vacia_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		tda_pruebas_afirmar(pruebas,"Lista creada y no alterada está vacía.", lista_vacia(lista));
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elemento=3;
		lista_insertar(lista, &elemento);
		printf("------------------------------------------------\nLista con un elemento\n");
		tda_pruebas_afirmar(pruebas, "Lista con un elemento no está vacía.", lista_vacia(lista)==false);
		printf("Elimino elemento\n");
		lista_borrar(lista);
		tda_pruebas_afirmar(pruebas, "Lista con cero elementos está vacía",lista_vacia(lista));
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_insertar_en_posicion_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int elemento=3;
		lista_insertar_en_posicion(lista,&elemento,12);
		negro();
		printf("------------------------------------------------\nInsertar en posición mayor a cero en lista vacía\n");
		tda_pruebas_afirmar(pruebas, "Lista solo tiene un elemento.",lista->numero_listas==1);
		printf("Insertar en posición mayor a cero en lista con 1 elemento\n");
		lista_insertar_en_posicion(lista,&elemento,12);
		tda_pruebas_afirmar(pruebas, "Lista tiene dos elementos.",lista->numero_listas==2);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		int elemento=3;
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		printf("------------------------------------------------\nInsertar en posición intermedia en lista llena\n");
		lista_insertar_en_posicion(lista, &elemento, 40);

		tda_pruebas_afirmar(pruebas, "Agrego elemento en lista.", lista->numero_listas==101);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_borrar_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int aux=lista_borrar(lista);
		tda_pruebas_afirmar(pruebas, "No se borran elementos de lista vacia.",aux==ERROR);
		printf("Borrar de lista con 100 elementos\n");
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		lista_borrar(lista);
		tda_pruebas_afirmar(pruebas, "Hay 99 elementos.",lista->numero_listas==99);
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_borrar_en_posicion_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int aux=lista_borrar_de_posicion(lista,4);
		tda_pruebas_afirmar(pruebas, "No se borran elementos de una posición en una lista vacia.",aux==ERROR);
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		lista_borrar_de_posicion(lista, 130);
		printf("------------------------------------------------\nBorrar de lista con 100 elementos, posicion 130 \n");
		tda_pruebas_afirmar(pruebas, "Número de elementos es 99.",lista->numero_listas==99);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_elemento_en_posicion_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		void* elemento=lista_elemento_en_posicion(lista, 0);
		int numero=3;
		tda_pruebas_afirmar(pruebas, "En lista vacía no se regresa ningún elemento.",elemento==NULL);
		lista_insertar(lista, &numero);
		lista_elemento_en_posicion(lista, 0);
		tda_pruebas_afirmar(pruebas, "En lista con un elemento regresa el elemento acorde.",&numero==(int*)lista->info);
		elemento=lista_elemento_en_posicion(lista, 3);
		tda_pruebas_afirmar(pruebas, "Al pedir un elemento de una posicion inválida no pasa nada.",elemento==NULL);
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		printf("------------------------------------------------\nLista con 100 elementos, pido el de la posición 50\n");
		void* elemento=lista_elemento_en_posicion(lista,50);
		tda_pruebas_afirmar(pruebas, "Elemento regresado es el correspondiente.",(int*)elemento==&elementos[50]);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_ultimo_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		void* elemento=lista_ultimo(lista);
		tda_pruebas_afirmar(pruebas, "En lista vacía no se regresa ningún elemento.",elemento==NULL);
		printf("------------------------------------------------\nAgrego un elemento\n");
		int numero=3;
		lista_insertar(lista, &numero);
		elemento=lista_ultimo(lista);
		tda_pruebas_afirmar(pruebas, "Regresa el único elemento.",(int*)elemento==&numero);
		lista_borrar(lista);
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		printf("Agrego elementos para tener una lista con 100\n");
		elemento=lista_ultimo(lista);
		tda_pruebas_afirmar(pruebas, "Regresa el último elemento.", (int*)elemento==&elementos[99]);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_elementos_caja_negra(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		printf("------------------------------------------------\nLista vacía\n");
		size_t numero_elementos=lista_elementos(lista);
		tda_pruebas_afirmar(pruebas, "Lista tiene cero elementos.",numero_elementos==0);
		printf("Agrego 100 elementos\n");
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		numero_elementos=lista_elementos(lista);
		tda_pruebas_afirmar(pruebas, "Lista tiene 100 elementos.",numero_elementos==100);
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funciones_lista_caja_negra(tda_pruebas_t* pruebas){
	probar_funcion_crear_lista(pruebas);
	probar_funcion_lista_insertar_caja_negra(pruebas);
	probar_funcion_lista_insertar_en_posicion_caja_negra(pruebas);
	probar_funcion_lista_borrar_caja_negra(pruebas);
	probar_funcion_lista_borrar_en_posicion_caja_negra(pruebas);
	probar_funcion_lista_vacia_caja_negra(pruebas);
	probar_funcion_lista_elemento_en_posicion_caja_negra(pruebas);
	probar_funcion_lista_ultimo_caja_negra(pruebas);
	probar_funcion_lista_elementos_caja_negra(pruebas);
}

void probar_funcion_lista_insertar_caja_blanca(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int elemento=3;
		lista_insertar(lista, &elemento);
		printf("------------------------------------------------\nInsertar un elemento en lista vacía\n");
		tda_pruebas_afirmar(pruebas, "No se crea un nodo.", (lista->primer_nodo==NULL)&&(lista->nodo_final==NULL));
		printf("Agrego otros dos elementos\n");
		int numero=4; int numero2=2;
		lista_insertar(lista,&numero);
		nodo_t* nodo_auxiliar=lista->primer_nodo;
		lista_insertar(lista, &numero2);
		tda_pruebas_afirmar(pruebas, "Nodo inicial se mantiene igual.",nodo_auxiliar==lista->primer_nodo);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}
void probar_funcion_lista_insertar_en_posicion_caja_blanca(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		nodo_t* nodo_auxiliar1=lista->nodo_final;
		nodo_t* nodo_auxiliar2=lista->primer_nodo;
		lista_borrar_de_posicion(lista, 130);
		printf("------------------------------------------------\nBorrar de lista con 100 elementos, posicion 130 \n");
		tda_pruebas_afirmar(pruebas, "Nodo final cambia.", nodo_auxiliar1!=lista->nodo_final);
		tda_pruebas_afirmar(pruebas, "Nodo inicial no cambia.", nodo_auxiliar2==lista->primer_nodo);
		nodo_auxiliar1=lista->nodo_final;
		nodo_auxiliar2=lista->primer_nodo;
		lista_borrar_de_posicion(lista, 4);		
		tda_pruebas_afirmar(pruebas, "Nodo final no cambia.", nodo_auxiliar1==lista->nodo_final);
		tda_pruebas_afirmar(pruebas, "Nodo inicial no cambia.", nodo_auxiliar2==lista->primer_nodo);
		printf("Borrar de lista con 98 elementos, posicion 0\n");
		lista_borrar_de_posicion(lista,0);
		tda_pruebas_afirmar(pruebas, "Nodo final no cambia.", nodo_auxiliar1==lista->nodo_final);
		printf("Borrar de lista con 97 elementos, posicion 1\n");
		tda_pruebas_afirmar(pruebas, "Nodo final no cambia.", nodo_auxiliar1==lista->nodo_final);
		tda_pruebas_afirmar(pruebas, "Nodo inicial cambia.", nodo_auxiliar2!=lista->primer_nodo);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
		{
		lista_t* lista=lista_crear();
		int elemento=3;
		lista_insertar_en_posicion(lista,&elemento,12);
		negro();
		printf("------------------------------------------------\nInsertar en posición mayor a cero en lista vacía\n");
		tda_pruebas_afirmar(pruebas, "Lista solo tiene un elemento.",lista->numero_listas==1);
		tda_pruebas_afirmar(pruebas, "Lista no tiene nodos.",(lista->primer_nodo==NULL)&&(lista->nodo_final==NULL));
		printf("Insertar en posición mayor a cero en lista con 1 elemento\n");
		lista_insertar_en_posicion(lista,&elemento,12);
		tda_pruebas_afirmar(pruebas, "Lista tiene dos elementos.",lista->numero_listas==2);
		tda_pruebas_afirmar(pruebas, "Lista tiene nodos inicial y final iguales.",(lista->primer_nodo==lista->nodo_final));
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		int elemento=3;
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		printf("------------------------------------------------\nInsertar en posición intermedia en lista llena\n");
		nodo_t* nodo_auxiliar1=lista->nodo_final;
		nodo_t* nodo_auxiliar2=lista->primer_nodo;
		lista_insertar_en_posicion(lista, &elemento, 40);
		tda_pruebas_afirmar(pruebas, "Los nodos no cambiaron", (nodo_auxiliar1==lista->nodo_final)&&(nodo_auxiliar2==lista->primer_nodo));
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar_en_posicion(lista,&elementos[i],0);
		tda_pruebas_afirmar(pruebas, "Elementos están acorde al insertar 100 elementos en posicion cero.",(((int*)lista->nodo_final->lista_apuntada->info==&elementos[0])&&((int*)lista->info==&elementos[99])));
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");	
}
void probar_funcion_lista_borrar_caja_blanca(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");	
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		nodo_t* nodo_auxiliar1=lista->nodo_final;
		nodo_t* nodo_auxiliar2=lista->primer_nodo;
		lista_borrar(lista);
		printf("------------------------------------------------\nBorrar de lista con 100 elementos\n");
		tda_pruebas_afirmar(pruebas, "Nodo final cambia.", nodo_auxiliar1!=lista->nodo_final);
		tda_pruebas_afirmar(pruebas, "Nodo inicial no cambia.", nodo_auxiliar2==lista->primer_nodo);
		printf("------------------------------------------------\n");
		lista_destruir(lista);
	}
	{
		lista_t* lista= lista_crear();
		int elemento=3;
		lista_insertar(lista, &elemento);
		lista_insertar(lista, &elemento);
		lista_borrar(lista);
		tda_pruebas_afirmar(pruebas, "Al eliminar una lista de dos totales, nodos apuntan a null",(lista->primer_nodo==NULL)&&(lista->nodo_final==NULL));
		lista_destruir(lista);
	}
	printf("------------------------------------------------------------------------------------------------\n");		
}


void probar_funciones_lista_caja_blanca(tda_pruebas_t* pruebas){
	probar_funcion_lista_insertar_caja_blanca(pruebas);
	probar_funcion_lista_insertar_en_posicion_caja_blanca(pruebas);
	probar_funcion_lista_borrar_caja_blanca(pruebas);
}

void probar_funcion_lista_iterador_crear(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		lista_iterador_t* iterador=lista_iterador_crear(lista);
		tda_pruebas_afirmar(pruebas, "Iterador vacío solo apunta a lista.",(iterador->nodo==NULL)&&(iterador->indice==0));
		lista_destruir(lista);
		lista_iterador_destruir(iterador);

	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_iterador_tiene_siguiente(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		lista_iterador_t* iterador=lista_iterador_crear(lista);
		tda_pruebas_afirmar(pruebas, "Lista vacía no tiene siguiente.",lista_iterador_tiene_siguiente(iterador)==false);
		lista_destruir(lista);
		lista_iterador_destruir(iterador);
	}
	{	
		lista_t* lista=lista_crear();
		printf("------------------------------------------------\nLista con 2 elementos\n");
		int elemento=3;
		lista_insertar(lista, &elemento);
		lista_insertar(lista, &elemento);
		lista_iterador_t* iterador=lista_iterador_crear(lista);
		tda_pruebas_afirmar(pruebas, "Posición cero, lista tiene siguiente.",lista_iterador_tiene_siguiente(iterador));
		tda_pruebas_afirmar(pruebas, "Posición uno, lista no tiene siguiente", lista_iterador_tiene_siguiente(iterador));
		printf("------------------------------------------------\n");

	}	
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_iterador_siguiente(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* lista=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_insertar(lista, &(elementos[i]));
		printf("------------------------------------------------\nLista con 100 elementos\n");
		lista_iterador_t* iterador=lista_iterador_crear(lista);
		void* elemento=lista_iterador_siguiente(iterador);
		tda_pruebas_afirmar(pruebas,"El elemento siguiente es el de la posición cero.",(int*)elemento==&elementos[0]);
		elemento=lista_iterador_siguiente(iterador);
		tda_pruebas_afirmar(pruebas,"El elemento siguiente es el de la posición uno.",(int*)elemento==&elementos[1]);
		printf("Itero por otros 98 elementos\n");
		while(lista_iterador_tiene_siguiente(iterador))
			elemento=lista_iterador_siguiente(iterador);
		tda_pruebas_afirmar(pruebas, "El elemento final es el de la posición 99",(int*)elemento==&elementos[99]);
		lista_destruir(lista);
		lista_iterador_destruir(iterador);
		printf("------------------------------------------------\n");
	}
	printf("------------------------------------------------------------------------------------------------\n");
}


void probar_funciones_lista_iterador(tda_pruebas_t* pruebas){
	probar_funcion_lista_iterador_crear(pruebas);
	probar_funcion_lista_iterador_tiene_siguiente(pruebas);
	probar_funcion_lista_iterador_siguiente(pruebas);
}

void probar_funciones_lista(tda_pruebas_t* pruebas){
	printf("PRUEBAS DE LISTA CAJA NEGRA:\n");
	probar_funciones_lista_caja_negra(pruebas);
	printf("PRUEBAS DE LISTA CAJA BLANCA:\n");
	probar_funciones_lista_caja_blanca(pruebas);
	printf("PRUEBAS DE LISTA ITERADOR\n");
	probar_funciones_lista_iterador(pruebas);
}

void probar_funcion_lista_apilar(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* pila=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_apilar(pila, &(elementos[i]));
		printf("------------------------------------------------\nPila con 100 elementos\n");	
		tda_pruebas_afirmar(pruebas,"Número de elementos es correcto.",pila->numero_listas==100);
		tda_pruebas_afirmar(pruebas, "Elemento final es el último apilado.",(int*)pila->nodo_final->lista_apuntada->info==&elementos[99]);
		tda_pruebas_afirmar(pruebas, "Elemento primero fue el primero en apilar.",(int*)pila->info==&elementos[0]);
		printf("------------------------------------------------\n");
		lista_destruir(pila);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_desapilar(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* pila=lista_crear();
		int aux=lista_desapilar(pila);
		tda_pruebas_afirmar(pruebas, "No pasa nada cuando desapilo pila vacía.",aux==ERROR);
	}
	{
		lista_t* pila=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_apilar(pila, &(elementos[i]));
		printf("------------------------------------------------\nDesapilo pila con 100 elementos\n");	
		lista_desapilar(pila);
		tda_pruebas_afirmar(pruebas, "Número de elementos correcto al desapilar.",pila->numero_listas==99);
		tda_pruebas_afirmar(pruebas, "El nuevo último elemento es correspondiente.",(int*)pila->nodo_final->lista_apuntada->info==&elementos[98]);
		tda_pruebas_afirmar(pruebas, "El primer elemento de la lista es el mismo.",(int*)pila->info==&elementos[0]);
		lista_destruir(pila);
		printf("------------------------------------------------\n");
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_tope(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* pila=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_apilar(pila, &(elementos[i]));
		void* elemento=lista_tope(pila);
		tda_pruebas_afirmar(pruebas, "El tope de la pila recibido es válido.",elemento==pila->nodo_final->lista_apuntada->info);
		lista_destruir(pila);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funciones_pila(tda_pruebas_t* pruebas){
	probar_funcion_lista_apilar(pruebas);
	probar_funcion_lista_desapilar(pruebas);
	probar_funcion_lista_tope(pruebas);
}

void probar_funcion_lista_encolar(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* cola=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_encolar(cola, &(elementos[i]));
		printf("------------------------------------------------\nCola con 100 elementos\n");
		tda_pruebas_afirmar(pruebas,"Número correcto de listas.",cola->numero_listas==100);
		tda_pruebas_afirmar(pruebas,"Primer elemento encolado es el último de la lista.",(int*)cola->nodo_final->lista_apuntada->info==&elementos[0]);
		tda_pruebas_afirmar(pruebas,"Último elemento encolado es el primero de la lista.",(int*)cola->info==&elementos[99]);
		lista_destruir(cola);
		printf("------------------------------------------------\n");
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_desencolar(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* cola=lista_crear();
		int aux=lista_desencolar(cola);
		tda_pruebas_afirmar(pruebas, "No pasa nada cuando desencolo cola vacía.",aux==ERROR);
	}
	{
		lista_t* cola=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_encolar(cola, &(elementos[i]));
		printf("------------------------------------------------\nDesencolo cola con 100 elementos\n");	
		lista_desencolar(cola);
		tda_pruebas_afirmar(pruebas, "Número de elementos correcto al desacolar.",cola->numero_listas==99);
		tda_pruebas_afirmar(pruebas, "El nuevo último elemento es correspondiente.",(int*)cola->nodo_final->lista_apuntada->info==&elementos[1]);
		tda_pruebas_afirmar(pruebas, "La primera lista encolada es la lista desencolada.",(int*)cola->nodo_final->lista_apuntada->info!=&elementos[0]);
		lista_destruir(cola);
		printf("------------------------------------------------\n");
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funcion_lista_primero(tda_pruebas_t* pruebas){
	printf("------------------------------------------------------------------------------------------------\n");
	{
		lista_t* cola=lista_crear();
		int elementos[MAX_ELEMENTOS];
		for(int i=0;i<MAX_ELEMENTOS;i++)
			lista_encolar(cola, &(elementos[i]));
		void* elemento=lista_primero(cola);
		tda_pruebas_afirmar(pruebas, "El primero de la cola recibido es válido.",elemento==cola->nodo_final->lista_apuntada->info);
		lista_destruir(cola);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void probar_funciones_cola(tda_pruebas_t* pruebas){
	probar_funcion_lista_encolar(pruebas);
	probar_funcion_lista_desencolar(pruebas);
	probar_funcion_lista_primero(pruebas);
}

int main(){

	tda_pruebas_t* tda_pruebas=tda_pruebas_crear();
	printf("PRUEBAS DE LISTA\n");
	probar_funciones_lista(tda_pruebas);
	printf("PRUEBAS DE PILA\n");
	probar_funciones_pila(tda_pruebas);
	printf("PRUEBAS DE COLA\n");
	probar_funciones_cola(tda_pruebas);
	tda_pruebas_mostrar_estadisticas(tda_pruebas);
	tda_pruebas_destruir(tda_pruebas);
	return 0;
}