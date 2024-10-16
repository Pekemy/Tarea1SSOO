#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <cstdlib>

std::mutex mtx;
int posicion = 1;

class Auto {
    std::string nombre;
    int distancia_total;
    int distancia_recorrida;

    public:
        Auto(std::string n, int distancia) : nombre(n), distancia_total(distancia), distancia_recorrida(0) {}

        void carrera(){
            while (distancia_recorrida < distancia_total)
            {
                int avanzar = rand() % 10 + 1;
                distancia_recorrida += avanzar;

                if (distancia_recorrida > distancia_total)
                {
                    distancia_recorrida = distancia_total;
                }

                {
                    std::lock_guard<std::mutex> lock(mtx);
                    std::cout << nombre << "recorre" << "metros (total recorrido: " << distancia_recorrida << "metros)" << std::endl;
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500 + 100));

                {
                    std::lock_guard<std::mutex> lock(mtx);
                    std::cout << nombre << "termino en " << posicion++ << "posicion!!" << std::endl; 
                }
            }
        
        }
};

int main(int argc, char* argv[]){
    if (argc != 3)
    {
        std::cerr << "Se deben ingresar 2 argumentos <distancia_total> <numero_ de_autos> " << std::endl;
    }
    
    int M = std::stoi(argv[1]);
    int N = std::stoi(argv[2]);

    std::vector<std::thread> autos;
    for (int i = 0; i < N; i++)
    {
        autos.push_back(std::thread(&Auto::carrera, Auto("Auto" + std::to_string(i), M)));
    }
    for (auto& car : autos)
    {
        car.join();
    }
    return 0;
}
