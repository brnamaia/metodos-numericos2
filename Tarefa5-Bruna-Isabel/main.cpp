#include <bits/stdc++.h>
#include "./gauss-legendre.cpp"

#define EPS 0.0000001

using namespace std;
int main() {
    double a = 0, b = 1;

    int n, it;
    double in, err, iv, delta;

    int option;


    while(true) {
        cout << "MENU" << endl;
        cout << "2. Gauss Legendre com 2 pontos." << endl;
        cout << "3. Gauss Legendre com 3 pontos." << endl;
        cout << "4. Gauss Legendre com 4 pontos." << endl;
        cout << "0. Sair." << endl;
        cout << endl;
        cout << "Escolha uma abordagem [2, 4]: ";
        cin >> option;
        
        n = 1, err = 1000;

        if(option == 0) break;
        else if(option == 2) {
            in = gauss_legendre_2(a, b);
            while(err > EPS) {
                iv = in, 
                n = n * 2, 
                it = 0;
            
                delta = (b - a) / n;

                in = 0;
                for(int i = 0; i < n; ++i) {
                    double xi = a + i * delta;
                    double xf = xi + delta;
                    in += ((xf - xi) / 2.0) * gauss_legendre_2(a, b);
                    ++it;
                }
                
                err = abs((iv - in) / in);
            }
        }
        else if(option == 3) {
            in = gauss_legendre_3(a, b);
            while(err > EPS) {
                iv = in, 
                n = n * 2, 
                it = 0;
            
                delta = (b - a) / n;

                in = 0;
                for(int i = 0; i < n; ++i) {
                    double xi = a + i * delta;
                    double xf = xi + delta;
                    in += ((xf - xi) / 2.0) * gauss_legendre_3(a, b);
                    ++it;
                }
                
                err = abs((iv - in) / in);
            }
        }
        else if(option == 4) {
            in = gauss_legendre_4(a, b);
            while(err > EPS) {
                iv = in, 
                n = n * 2, 
                it = 0;
            
                delta = (b - a) / n;

                in = 0;
                for(int i = 0; i < n; ++i) {
                    double xi = a + i * delta;
                    double xf = xi + delta;
                    in += ((xf - xi) / 2.0) * gauss_legendre_4(a, b);
                    ++it;
                }
                
                err = abs((iv - in) / in);
            }
        }
        else {
            cout << "Opcao Invalida! Bye-Bye!" << endl;
            break;
        }

        cout << endl;
        cout << "Resultado: " << in << endl;
        cout << "Numero de interacoes: " << it << endl;
        cout << endl;
        
    }
    
    return 0;
}