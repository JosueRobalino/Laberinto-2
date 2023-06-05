#include <stdio.h>
#include <stdlib.h>
#include "laberinto.h"
#include "movimientos.h"
#include "juego.h"

int main() {
    int opcion;
    int movimientos = 0;
    int ganador = 0;
    Laberinto laberinto;

    cargarLaberinto(&laberinto); // Cargar el laberinto desde un archivo o de manera manual

    do {
        printf("=== MENU ===\n");
        printf("1. Jugar\n");
        printf("2. Créditos\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                juegoNuevo(&laberinto, &movimientos, &ganador);
                break;
            case 2:
                mostrarCreditos();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 3);
define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 1, 0}
};

int solveMaze(int row, int col)
{
    // Si estamos fuera de los límites del laberinto o estamos en una pared
    // retornamos falso, indicando que no podemos avanzar aquí.
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == 1)
        return 0;

    // Si hemos llegado a la esquina inferior derecha, retornamos verdadero,
    // indicando que hemos encontrado una solución.
    if (row == ROWS - 1 && col == COLS - 1)
        return 1;

    // Marcamos la casilla actual como visitada (puedes usar un número diferente, como 2, para marcarlo).
    maze[row][col] = 2;

    // Intentamos avanzar en las cuatro direcciones posibles:
    // hacia arriba, abajo, izquierda y derecha.
    if (solveMaze(row - 1, col)) // Arriba
        return 1;
    if (solveMaze(row + 1, col)) // Abajo
        return 1;
    if (solveMaze(row, col - 1)) // Izquierda
        return 1;
    if (solveMaze(row, col + 1)) // Derecha
        return 1;

    // Si no se puede avanzar en ninguna dirección, marcamos la casilla actual como no visitada y retrocedemos.
    maze[row][col] = 0;
    return 0;
}

int main()
{
    if (solveMaze(0, 0))
    {
        printf("Felicidades eres un pro.\n");
    }
    else
    {
        printf("Ohh lo siento eres un Noob.\n");
    }

    return 0;
}
