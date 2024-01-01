#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Puntuacion {
private:
    int puntos;

public:
    Puntuacion() : puntos(0) {}

    int getPuntos() const {
        return puntos;
    }

    void agregarPuntos(int cantidad) {
        puntos += cantidad;
    }

    void mostrarPuntuacion() const {
        cout << "Puntos totales: " << puntos << endl;
    }
};

class Jugador {
private:
    int distanciaRecorrida;
    int vidas;
    Puntuacion puntuacion;

public:
    Jugador() : distanciaRecorrida(0), vidas(7) {}

    void reiniciar() {
        distanciaRecorrida = 0;
        vidas = 7;
        puntuacion = Puntuacion();
    }

    int getDistanciaRecorrida() const {
        return distanciaRecorrida;
    }

    int getVidas() const {
        return vidas;
    }

    void realizarSaltoArriesgado() {
        int resultadoDado = rand() % 20 + 1;
        if (resultadoDado > 13) {
            cout << "Has realizado un salto arriesgado exitoso! +25 metros." << endl;
            distanciaRecorrida += 25;
            puntuacion.agregarPuntos(10);
        } else {
            cout << "Oops! Fallaste el salto arriesgado, pierdes 1 vida." << endl;
            vidas -= 1;
        }
    }

    void realizarSaltoSeguro() {
        int resultadoSaltoSeguro = rand() % 20 + 1;
        cout << "Has realizado un salto seguro! +5 metros." << endl;
        distanciaRecorrida += 5;
    }

    void mostrarEstado() const {
        cout << "Distancia recorrida: " << distanciaRecorrida << " metros" << endl;
        cout << "Vidas: " << vidas << endl;
        puntuacion.mostrarPuntuacion();
    }

    void encontrarAtajoSecreto() {
        cout << "Encuentras un atajo secreto y ganas 15 metros." << endl;
        distanciaRecorrida += 15;
    }

    void encontrarCorazon() {
        cout << "Encuentras un corazon en el camino." << endl;
        vidas += 1;
    }
};

int main() {
    srand(time(0));

    Jugador jugador;

    int decisionRascacielo;

    cout << "Bienvenido a la emocionante aventura de Urban Jump!" << endl;
    cout << "Tu objetivo es recorrer la ciudad realizando increibles acrobacias de parkour." << endl;
    cout << "Cada decision que tomes afectara tu progreso, pero cuidado, tienes 7 vidas." << endl;

    while (true) {
        cout << "Nueva partida iniciada." << endl;

        while (jugador.getDistanciaRecorrida() < 300 && jugador.getVidas() > 0) {
            int eventoAleatorio = rand() % 75;
            int decision;
            cout << "_________________________" << endl;
            cout << "Elige tu proxima accion:\n";
            cout << "1. Realizar un salto arriesgado (+25 metros o -1 vida).\n";
            cout << "2. Realizar un salto seguro (+5 metros).\n";
            cout << "Ingresa el numero de la accion: ";
            cin >> decision;

            switch (decision) {
                case 1:
                    jugador.realizarSaltoArriesgado();
                    break;
                case 2:
                    jugador.realizarSaltoSeguro();
                    break;
                default:
                    cout << "Decision no valida. Intentalo de nuevo." << endl;
            }

            jugador.mostrarEstado();

            if (eventoAleatorio < 10) {
                jugador.encontrarAtajoSecreto();
            } else if (eventoAleatorio < 20) {
                jugador.encontrarCorazon();
            }

            cout << "_________________________" << endl;

            if (jugador.getDistanciaRecorrida() == 200) {
                cout << "Te encuentras con un rascacielos. Intentas escalarlo para ganar un bono de distancia?" << endl;
                cout << "1. Si, intentar escalar (+40 metros o -2 vidas)\n";
                cout << "2. No, seguir el camino seguro." << endl;
                cin >> decisionRascacielo;

                if (decisionRascacielo == 1) {
                    if (rand() % 20 > 10) {
                        cout << "Lograste escalar el rascacielos! +40 metros." << endl;
                        jugador.realizarSaltoSeguro();  // Se utiliza la función de salto seguro para añadir los metros.
                    } else {
                        cout << "Oops, resbalaste y perdiste 2 vidas." << endl;
                        jugador.realizarSaltoArriesgado();  // Se utiliza la función de salto arriesgado para restar las vidas.
                    }
                }
            }
        }

        if (jugador.getDistanciaRecorrida() >= 300) {
            cout << "Felicidades! Has completado la aventura de parkour y recorrido 300 metros de la ciudad." << endl;
            cout << "   ####     ##     ##   ##    ##      #####   ######   #######" << endl;
            cout << "  ##  ##   ####    ###  ##   ####    ##   ##  # ## #    ##   #" << endl;
            cout << " ##       ##  ##   #### ##  ##  ##   #          ##      ## #" << endl;
            cout << " ##       ##  ##   ## ####  ##  ##    #####     ##      ####" << endl;
            cout << " ##  ###  ######   ##  ###  ######        ##    ##      ## #" << endl;
            cout << "  ##  ##  ##  ##   ##   ##  ##  ##   ##   ##    ##      ##   #" << endl;
            cout << "   #####  ##  ##   ##   ##  ##  ##    #####    ####    #######" << endl;
        }

        if (jugador.getVidas() <= 0) {
            cout << "Tus vidas se han agotado! Tu aventura ha llegado a su fin." << endl;
            cout << " ######   #######  ######   #####     ####     #####   ######   #######" << endl;
            cout << "  ##  ##   ##   #   ##  ##   ## ##     ##     ##   ##  # ## #    ##   #" << endl;
            cout << "  ##  ##   ## #     ##  ##   ##  ##    ##     #          ##      ## #" << endl;
            cout << "  #####    ####     #####    ##  ##    ##      #####     ##      ####" << endl;
            cout << "  ##       ## #     ## ##    ##  ##    ##          ##    ##      ## #" << endl;
            cout << "  ##       ##   #   ##  ##   ## ##     ##     ##   ##    ##      ##   #" << endl;
            cout << " ####     #######  #### ##  #####     ####     #####    ####    #######" << endl;
        }

        int opcion;
        cout << "Deseas jugar de nuevo?\n";
        cout << "1. Si\n";
        cout << "2. No\n";
        cout << "Ingresa el numero de la opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            jugador.reiniciar();
        } else if (opcion == 2) {
            break;
        }
    }

    return 0;
}