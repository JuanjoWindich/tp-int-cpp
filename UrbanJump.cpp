#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    int distanciaRecorrida = 0;
    int obstaculosSorteados = 0;
    int vidas = 7;
    int decisionRascacielo;

    cout << "Bienvenido a la emocionante aventura de Urban Jump!" << endl;
    cout << "Tu objetivo es recorrer la ciudad realizando increibles acrobacias de parkour." << endl;
    cout << "Cada decision que tomes afectara tu progreso, pero cuidado, tienes 7 vidas." << endl;

    while (true) {

        cout << "Nueva partida iniciada." << endl;

        while (distanciaRecorrida < 300 && vidas > 0) {
            int resultadoDado = rand() % 20 + 1;
            int eventoAleatorio = rand() % 75;
            int resultadoSaltoSeguro;
            int decision;
            cout << "_________________________"<< endl;
            cout << "Elige tu proxima accion:\n";
            cout << "1. Realizar un salto arriesgado (+25 metros o -1 vida).\n";
            cout << "2. Realizar un salto seguro (+5 metros).\n";
            cout << "Ingresa el numero de la accion: ";
            cin >> decision;

            switch (decision) {
                case 1:
                    if (resultadoDado > 13) {
                        cout << "Has realizado un salto arriesgado exitoso! +25 metros." << endl;
                        distanciaRecorrida += 25;
                    } else {
                        cout << "Oops! Fallaste el salto arriesgado, pierdes 1 vida." << endl;
                        vidas -= 1;
                    }
                    break;
                case 2:
                    resultadoSaltoSeguro = rand() % 20 + 1;
                    cout << "Has realizado un salto seguro! +5 metros." << endl;
                    distanciaRecorrida += 5;
                    break;
                default:
                    cout << "Decision no valida. Intentalo de nuevo." << endl;
            }
            cout << "Distancia recorrida: " << distanciaRecorrida << " metros" << endl;
            cout << "Vidas: " << vidas << endl;

            if (eventoAleatorio < 10) {
                cout << "Encuentras un atajo secreto y ganas 15 metros." << endl;
                distanciaRecorrida += 15;
                } else if (eventoAleatorio < 20) {
                cout << "Encuentras un corazon en el camino." << endl;
                vidas += 1;
                }
            
            cout << "_________________________" << endl;


            if (distanciaRecorrida == 200) {
                cout << "Te encuentras con un rascacielos. ¿Intentas escalarlo para ganar un bono de distancia?" << endl;
                cout << "1. Sí, intentar escalar (+40 metros o -2 vidas)\n";
                cout << "2. No, seguir el camino seguro." << endl;
                cin >> decisionRascacielo;

            if (decisionRascacielo == 1) {
                if (rand() % 20 > 10) {
                cout << "Lograste escalar el rascacielos! +40 metros." << endl;
                distanciaRecorrida += 40;
                } else {
                cout << "Oops, resbalaste y perdiste 2 vidas." << endl;
                vidas -= 2;
                }
            }
            }
    

}


        if (distanciaRecorrida >= 300) {
            cout << "Felicidades! Has completado la aventura de parkour y recorrido 300 metros de la ciudad." << endl;
            cout << "   ####     ##     ##   ##    ##      #####   ######   #######" << endl;
            cout << "  ##  ##   ####    ###  ##   ####    ##   ##  # ## #    ##   #" << endl;
            cout << " ##       ##  ##   #### ##  ##  ##   #          ##      ## #" << endl;
            cout << " ##       ##  ##   ## ####  ##  ##    #####     ##      ####" << endl;
            cout << " ##  ###  ######   ##  ###  ######        ##    ##      ## #" << endl;
            cout << "  ##  ##  ##  ##   ##   ##  ##  ##   ##   ##    ##      ##   #" << endl;
            cout << "   #####  ##  ##   ##   ##  ##  ##    #####    ####    #######" << endl;

        }

        if (vidas <= 0) {
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

        if (opcion == 2) {
            break;
        }

        distanciaRecorrida = 0;
        obstaculosSorteados = 0;
        vidas = 7;
    }

    return 0;
}
