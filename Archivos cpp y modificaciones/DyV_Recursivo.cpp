#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;

using namespace std;

long double pot(int a, int n){
    long double res = 0;

    if (n == 0){
        return 1;
    }

    if (n == 1){
        return a;
    }

    if (n % 2 == 0)
    {
        res = pot(a, n/2);
        res*=res;
    }

    if (n % 2 == 1){
        res = pot(a, n -1);
        res *= a;
    }
    return res;
}

int main(int argc, char * argv[]){
    if (argc != 3){
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

    int exp;
    double num;
    long double salida = 0;
    num = atof(argv[1]);
    exp = atoi(argv[2]);

    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;
    tantes=high_resolution_clock::now();
  
    salida = pot(num, exp);

    tdespues=high_resolution_clock::now();  
    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

    cout << exp<<"  "<<transcurrido.count()<<"\n";

}