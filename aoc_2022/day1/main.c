#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Inizializziamo una variabile chiamata "maxCalories" per tenere traccia delle 
calorie massime trovate finora. Inizializziamola a 0.

2. Apriamo il file di input e iniziamo a leggere le righe una alla volta.

3. Se troviamo una riga vuota, significa che stiamo passando a un nuovo elfo. 
In questo caso, reimpostiamo il nostro contatore di calorie a 0.

4.Se troviamo una riga che contiene un numero, convertiamo il numero in un 
intero e aggiungiamolo al nostro contatore di calorie.

5. Dopo aver letto ogni riga, confrontiamo il nostro contatore 
di calorie con la variabile "maxCalories". Se il contatore di calorie 
è maggiore, aggiorniamo "maxCalories" con il nuovo valore.

6. Continuiamo a leggere le righe del file finché non le abbiamo lette tutte.

7. Alla fine, "maxCalories" conterrà il numero di calorie massimo 
trovato, ovvero il numero di calorie portato dall'elfo che ne ha di più. 
Possiamo stampare questo valore come risposta.
*/

int part1() {
    // Apriamo il file di input
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Impossibile aprire il file di input\n");
        return 1;
    }

    // Inizializziamo il nostro contatore di calorie a 0
    int calorieCounter = 0;

    // Inizializziamo la variabile "maxCalories" a 0
    int maxCalories = 0;

    // Leggere ogni riga del file di input
    char line[256];
    while (fgets(line, sizeof(line), inputFile)) {
        // Se troviamo una riga vuota, significa che stiamo passando a un nuovo elfo
        if (line[0] == '\n') {
            // Se il contatore di calorie di questo elfo è maggiore di "maxCalories", aggiorniamo "maxCalories"
            if (calorieCounter > maxCalories) {
                maxCalories = calorieCounter;
            }
            // Reimpostiamo il contatore di calorie a 0 per il prossimo elfo
            calorieCounter = 0;
        } 
        else {
            // Convertiamo la stringa letta in un intero e aggiungiamo il valore al nostro contatore di calorie
            calorieCounter += atoi(line);
        }
    }

    // Dopo aver letto tutte le righe del file, confrontiamo ancora una volta il contatore di calorie con "maxCalories"
    // e aggiorniamo "maxCalories" se necessario
    if (calorieCounter > maxCalories) {
        maxCalories = calorieCounter;
    }

    // Chiudiamo il file di input
    fclose(inputFile);

    return maxCalories;
}

int part2() {


    return 0;
}

int main() {
    printf("%d", part1());
    printf("%d", part2());

    return 0;
}