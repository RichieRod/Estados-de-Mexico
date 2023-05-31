#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/*
Aguascalientes: Zacatecas, San Luis Potosí, Jalisco.
Baja California: California, Arizona.
Baja California Sur: Sinaloa.
Campeche: Yucatán, Quintana Roo, Tabasco.
Chiapas: Tabasco, Veracruz, Oaxaca.
Chihuahua: Sonora, Sinaloa, Durango, Coahuila, Nuevo León.
Ciudad de México: Estado de México, Morelos.
Coahuila: Chihuahua, Nuevo León, Durango, Zacatecas, San Luis Potosí.
Colima: Jalisco.
Durango: Sinaloa, Chihuahua, Coahuila, Zacatecas, Nayarit.
Estado de México: Hidalgo, Querétaro, Michoacán, Guerrero, Morelos, Ciudad de México, Tlaxcala, Puebla.
Guanajuato: Jalisco, San Luis Potosí, Querétaro, Michoacán.
Guerrero: Estado de México, Morelos, Puebla, Oaxaca.
Hidalgo: San Luis Potosí, Veracruz, Puebla, Estado de México, Querétaro.
Jalisco: Nayarit, Zacatecas, Aguascalientes, Guanajuato, Michoacán, Colima.
Michoacán: Guanajuato, Jalisco, Estado de México, Guerrero.
Morelos: Estado de México, Ciudad de México, Guerrero, Puebla.
Nayarit: Sinaloa, Durango, Jalisco.
Nuevo León: Coahuila, Tamaulipas.
Oaxaca: Guerrero, Puebla, Veracruz, Chiapas.
Puebla: Tlaxcala, Estado de México, Morelos, Guerrero, Oaxaca, Veracruz.
Querétaro: Hidalgo, San Luis Potosí, Guanajuato, Estado de México.
Quintana Roo: Campeche, Yucatán.
San Luis Potosí: Zacatecas, Aguascalientes, Guanajuato, Querétaro, Hidalgo, Veracruz, Tamaulipas, Nuevo León.
Sinaloa: Sonora, Chihuahua, Durango, Nayarit, Baja California Sur.
Sonora: Arizona, Chihuahua, Sinaloa.
Tabasco: Veracruz, Chiapas, Campeche.
Tamaulipas: Nuevo León, San Luis Potosí, Veracruz.
Tlaxcala: Puebla, Estado de México.
Veracruz: Tamaulipas, San Luis Potosí, Hidalgo, Puebla, Oaxaca, Tabasco, Chiapas.
Yucatán: Quintana Roo, Campeche.

*/
//Estructura arista
typedef struct arista {
    char * ubi;
    struct arista *sig;

}Arista;

//Estructura nodo
typedef struct Nodo { 
    char * estado;
    Arista *aris;
    struct Nodo *sig;
}Nodo;

//Crear nodo y su espacio de memoria 
Nodo * addNode(Nodo * grafo, char * estado) {
    Nodo * nuevoNodo;
    Nodo *aux = grafo;
    if (grafo == NULL) {    
        nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
        nuevoNodo -> estado = estado;
        nuevoNodo -> aris = NULL;
        nuevoNodo -> sig = NULL;
        return nuevoNodo;
    }
    while(aux->sig != NULL) {
        aux = aux->sig;
    }
    nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->estado = estado;
    nuevoNodo->aris=NULL;
    nuevoNodo->sig=NULL;
    aux->sig=nuevoNodo;
    return grafo;
}

//Agregar nueva arista
Nodo * addEdge(Nodo * grafo, char* info1, char* info2) {
    Nodo *aux = grafo;
    Arista *nuevoNodo, *aux2;

    while(aux->estado != info1) {
        aux=aux->sig;
    }
    aux2=aux->aris;

    nuevoNodo = (Arista*)malloc(sizeof(Arista));
    nuevoNodo->ubi=info2;
    if (aux2==NULL) {
        nuevoNodo->sig=NULL;
        aux->aris=nuevoNodo;
    }else {
        while(aux2->sig!=NULL) {
            aux2=aux2->sig;
        }
        aux2->sig=nuevoNodo;
        nuevoNodo->sig=NULL;
    }
    aux=grafo;
    aux2=nuevoNodo=NULL;

    while(aux->estado != info2) {
        aux=aux->sig;
    }
    aux2=aux->aris;

    nuevoNodo = (Arista*)malloc(sizeof(Arista));
    nuevoNodo->ubi=info1;
    if (aux2==NULL) {
        nuevoNodo->sig = NULL;
        aux->aris=nuevoNodo;
    }else {
        while(aux2->sig!=NULL) {
            aux2=aux2->sig;
        }
        aux2->sig=nuevoNodo;
        nuevoNodo->sig=NULL;
    }
    return grafo;
}



//Mostrar estados vecinos 
void VerInformacion(Nodo * grafo, char * s) {
    system("cls");
    Arista *aux;
    if (grafo==NULL) {
        printf("No ha agregado nada aun\n");
        return;
    }
    while(grafo!=NULL) {
        if (!strcmp(grafo->estado, s)) {
        printf("%s", grafo->estado);
        aux=grafo->aris;
        while(aux!=NULL) {
            printf("->%s\n",aux->ubi);
            aux=aux->sig;
        }
        printf("------------------\n\n");
        return;
    }
        grafo=grafo->sig;
    }

    printf("opcion invalida. Vuelva a seleccionar otro estado\n");
}

//imprimir estados
void imprimirEstados(Nodo *grafo) {
    system("cls");
    Arista *aux;
    printf("\n\n------------------\n\n");
    if (grafo==NULL) {
        printf("No ha agregado nada aun\n");
        return;
    } 
    printf(" 32 Estados de la Republica\n\n");
    while(grafo!=NULL) {
        printf("%s \n", grafo->estado);
        aux=grafo->aris;
        grafo=grafo->sig;
    }
    printf("\n\n------------------\n\n");
}

//inicializar grafo
Nodo* Init(Nodo * grafo) {
	grafo=addNode(grafo, "CDMX");
    grafo=addNode(grafo, "Guerrero");
    grafo=addNode(grafo, "Morelos");
    grafo=addNode(grafo, "Tlaxcala");
    grafo=addNode(grafo, "Puebla");
    grafo=addNode(grafo, "Estado_de_Mexico");
    grafo=addNode(grafo, "Veracruz");
    grafo=addNode(grafo, "Oaxaca");
    grafo=addNode(grafo, "Tabasco");
    grafo=addNode(grafo, "Chiapas");
    grafo=addNode(grafo, "Campeche");
    grafo=addNode(grafo, "Yucatan");
    grafo=addNode(grafo, "Quintana_Roo");
    grafo=addNode(grafo, "Chihuahua");
    grafo=addNode(grafo, "Sonora");
    grafo=addNode(grafo, "Durango");
    grafo=addNode(grafo, "Coahuila");
    grafo=addNode(grafo, "Sinaloa");
    grafo=addNode(grafo, "Baja_California");
    grafo=addNode(grafo, "Baja_California_Sur");
    grafo=addNode(grafo, "Zacatecas");
    grafo=addNode(grafo, "Guadalajara");
    grafo=addNode(grafo, "Aguas_Calientes");
    grafo=addNode(grafo, "San_Luis_Potosi");
    grafo=addNode(grafo, "Nayarit");
    grafo=addNode(grafo, "Nuevo_Leon");
    grafo=addNode(grafo, "Tamaulipas");
    grafo=addNode(grafo, "Colima");
    grafo=addNode(grafo, "Michoacan");
    grafo=addNode(grafo, "Guanajuato");
    grafo=addNode(grafo, "Queretaro");
    grafo=addNode(grafo, "Hidalgo");
    

    addEdge(grafo, "Yucatan", "Campeche");
    addEdge(grafo, "Yucatan", "Quintana_Roo");
    addEdge(grafo, "Quintana_Roo", "Campeche");
    addEdge(grafo, "Chiapas", "Oaxaca");
    addEdge(grafo, "Veracruz", "Chiapas");
    addEdge(grafo, "Tabasco", "Campeche");
    addEdge(grafo, "Tabasco", "Chiapas");
    addEdge(grafo, "Veracruz", "Tabasco");
    addEdge(grafo, "Veracruz", "Oaxaca");
    addEdge(grafo, "Veracruz", "Puebla");
    addEdge(grafo, "Veracruz", "Hidalgo");
    addEdge(grafo, "Veracruz", "San_Luis_Potosi");
    addEdge(grafo, "Veracruz", "Tamaulipas");
    addEdge(grafo, "CDMX", "Morelos");
    addEdge(grafo, "CDMX", "Estado_de_Mexico");
    addEdge(grafo, "Puebla", "Morelos");
    addEdge(grafo, "Puebla", "Hidalgo");
    addEdge(grafo, "Puebla", "Tlaxcala");
    addEdge(grafo, "Tlaxcala", "Estado_de_Mexico");
    addEdge(grafo, "Tlaxcala", "Hidalgo");
    addEdge(grafo, "Morelos", "Guerrero");
    addEdge(grafo, "Morelos", "Estado_de_Mexico");
    addEdge(grafo, "Estado_de_Mexico", "Michoacan");
    addEdge(grafo, "Guerrero", "Michoacan");
    addEdge(grafo, "Estado_de_Mexico", "Guerrero");
    addEdge(grafo, "Estado_de_Mexico", "Queretaro");
    addEdge(grafo, "Hidalgo","Estado_de_Mexico");
    addEdge(grafo, "Hidalgo","Queretaro");
    addEdge(grafo, "Hidalgo","San_Luis_Potosi");
    addEdge(grafo, "Queretaro","Michoacan");
    addEdge(grafo, "Queretaro","Guanajuato");
    addEdge(grafo, "Queretaro","San_Luis_Potosi");
    addEdge(grafo, "Chihuahua","Sonora");
    addEdge(grafo, "Colima","Michoacan");
    addEdge(grafo, "Michoacan", "Guanajuato");
    addEdge(grafo, "Guanajuato", "Guadalajara");
    addEdge(grafo, "Guanajuato", "San_Luis_Potosi");
    addEdge(grafo, "Michoacan", "Guadalajara");
    addEdge(grafo, "Coahuila","Nuevo_Leon");
    addEdge(grafo, "Nuevo_Leon", "San_Luis_Potosi");
    addEdge(grafo, "Nuevo_Leon", "Tamaulipas");
    addEdge(grafo, "Tamaulipas", "San_Luis_Potosi");
    addEdge(grafo, "Aguas_Calientes","Guadalajara");
    addEdge(grafo, "Sinaloa","Nayarit");
    addEdge(grafo, "Nayarit","Guadalajara");
    addEdge(grafo, "Durango","Nayarit");
    addEdge(grafo, "Zacatecas","Guadalajara");
    addEdge(grafo, "Zacatecas","Aguas_Calientes");
    addEdge(grafo, "Zacatecas","San_Luis_Potosi");
    addEdge(grafo, "Durango","Zacatecas");
    addEdge(grafo, "Coahuila","Zacatecas");
    addEdge(grafo, "Chihuahua","Durango");
    addEdge(grafo, "Chihuahua","Coahuila");
    addEdge(grafo, "Chihuahua","Sinaloa");
    addEdge(grafo, "Sonora","Sinaloa");
    addEdge(grafo, "Sinaloa","Durango");
    addEdge(grafo, "Durango","Coahuila");
    addEdge(grafo, "Baja_California","Sonora");
    addEdge(grafo, "Baja_California_Sur","Baja_California");

    return grafo;
}
//main
int main() {
	int opc;
    char * s = malloc(sizeof(char)*50);
    Nodo *grafo=NULL;
    grafo=Init(grafo);
    system("cls");
    do{
    printf("\n \t\t\t*****Menu de Opciones******\n\n");
    
    printf("\n 1.-Visualizar los 32 estados de la republica mexicana");
    printf("\n 2.-Ver cuales son los estados adyacentes");
    printf("\n 3.-Salir del programa");
    printf("\n\n Seleccione una opcion: ");
    scanf("%i", &opc);
    
        switch (opc) {
            case 1:
            imprimirEstados(grafo);
            system("pause");
            break;
            case 2:
            printf("Ingrese el estado del que desea obtener informacion (Primera letra en mayuscula)\n");
            scanf("%s",s);
            VerInformacion(grafo, s);
            system("pause");
            break;
            case 3:
            printf("\n Programa ha terminado\n");
            exit (1);
        }
    } while(opc!=3);
    
    return 0;
}
