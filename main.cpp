#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Pista.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto pista (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias pistas en un solo archivo
void escribir(string nombre_archivo, Pista*pista, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*30);
    out.write((char*)pista->autor.c_str(),10);
    out.write((char*)&pista->fecha,4);
    out.write((char*)&pista->duracion,4);
    out.write((char*)&pista->categoria,1);
    out.write((char*)&pista->es_buena,1);
    out.close();
}

//Devuelve una pista previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias pistas de un solo archivo
Pista* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*30);
    char autor[10];
    int fecha;
    int duracion;
    char categoria;
    bool es_buena;
    in.read((char*)autor,10);
    in.read((char*)&fecha,4);
    in.read((char*)&duracion,4);
    in.read((char*)&categoria,1);
    in.read((char*)&es_buena,1);
    Pista *pista = new Pista(autor,fecha,duracion,categoria,es_buena);
    return pista;
}

//Devuelve la cantidad de pistas almacenadas en el archivo con nombre_archivo que su atributo es_buena sea igual a true
int contarBuenas(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0, ios::end);
    int cantidad = in.tellg()/30;
    int pistasbuenas=0;
    for(int i=0; i<=cantidad; i++){
        if(leer(nombre_archivo,i)->es_buena==true){
            pistasbuenas+=1;
        }
    }
    return pistasbuenas;
}

//Devuelve la cantidad de numeros repetidos
//Nota: NO devuelve la cantidad de repeticiones
int contarRepetidos(multiset<int> mi_set)
{
    return -1;
}

//Devuelve true solo si c (dado) existe en a (dado) o en b (dado)
bool existe(queue<char> a, stack<char> b, char c)
{
    return false;
}

//Devuelve la llave asociada a valor (dado) en mi_mapa (dado)
string getKey(map<string,string>mi_mapa, string valor)
{
    return "";
}

//Establece en NULL el hijo izquerdo e hijo derecho del nodo cuyo valor es igual a valor (dado)
void cortarDecendencia(NodoBinario* raiz,int valor)
{

}

//Devuelve la profundidad a donde se encuentra el valor buscado (dado)
int getProfundidad(NodoBinario* raiz,int buscado)
{
    int c=0;
    for(NodoBinario*i=raiz;i!=NULL;i=i->hijo_izquierdo)
    {
        if(i->hijo_izquierdo!=NULL)

        for(NodoBinario*d=i;d!=NULL;d=d->hijo_derecho)
            {
                if(d->hijo_derecho!=NULL)
                c+=1;
            }
    }
}

//Establece en false todos los bits de byte (dado) excepto los ultimos dos
char borrar2Bits(char byte)
{
    return ' ';
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

