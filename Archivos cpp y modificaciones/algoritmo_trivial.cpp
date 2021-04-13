//Funcion basica para calcular x^n

#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

long double AlgoritmoTrivial(double base, int exponente){

	int x=1;
	long double resultado=0;
	
	while (x < exponente){
		if (resultado < base){
			resultado=base*base;
		}else{
			resultado=resultado*base;
		}
		
		x++;
	}
	
	return resultado;
}

int main(int argc, char *argv[]){

    //Entrada de datos
    
    if (argc != 3){
        cerr << "Numero de argumentos erroneo. El formato para introducir los datos es: ejecutable base exponente" << endl;
        return -1;
    }
    
	//Convertimos el primer argumento en una base como numero real
    double base = atof(argv[1]);
    //Convertimos el siguiente argumento en un exponente como numero entero
    int exponente = atoi(argv[2]);
	
	high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;
    tantes=high_resolution_clock::now();
	
	long double resultado = AlgoritmoTrivial(base, exponente);
	
	tdespues=high_resolution_clock::now();  
    transcurrido = duration_cast<duration<double>>(tdespues - tantes);
	
	// cerr<<resultado<<endl;
	cout << exponente << "  " << transcurrido.count() << endl;

	return 0;

}