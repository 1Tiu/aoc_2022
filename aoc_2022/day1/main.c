#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
