/**
* Función iterativa del algoritmo divide y vencerás para calcular x^n
*/  
#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;





long double DyVIterativo (double base, int exponente) {

    long long resultado = 1;    
    while (exponente > 0) {
      if ((exponente%2) != 0) // odd
        resultado *= base;
      base *= base;           // x = x * x
      exponente >>= 1;          // n = n/2
    }    
    return resultado;    
}


int main(int argc, char *argv[]){

    //Entrada de datos
        
    if (argc != 3){
        cerr << "Número de argumentos erróneo. El formato para introducir los datos es: ejecutable base exponente" << endl;
        return -1;
    }
    
    
    //Convertimos el primer argumento en una base como número real:
    double base = atof(argv[1]); 
    //Convertimos el segundo argumento en el exponente como número entero:
    int exponente = atoi(argv[2]);
    
    
    
    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;
    tantes=high_resolution_clock::now();
  
  
    long double result = DyVIterativo(base,exponente);


    tdespues=high_resolution_clock::now();  
    transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    
    
    //Exponente y el tiempo transcurrido
    cout << exponente << " " << transcurrido.count() << endl;


    return 0;
}






/*

PSEUDOCÓDIGO DE LA FUNCIÓN ITERATIVA CON DyV
funcion DyVIterativo (base: número real, exponente: entero) Devuelve: número real
variable: resultado: número real

principio
    resultado := 1
    mientras exponente > 0
        si exponente es impar ->
            resultado := base*resultado
        base := base*base
        exponente := exponente/2
    devuelve resultado    
fin        
    
*/
