#include <stdio.h>
#include <string.h>

int main() {
    char nombres[5][30];
    float notas[5][3];
    float prom_est[5], prom_mat[3];
    float max_est[5], min_est[5];
    float max_mat[3], min_mat[3];
    int aprobados[3], reprobados[3];
    int i, j, opc, valido, len;

    for (i = 0; i < 5; i++) {
        do {
            valido = 1;
            printf("Ingrese el nombre del estudiante %d: ", i + 1);
            fflush(stdin);
            fgets(nombres[i], 30, stdin);
            len = strlen(nombres[i]);
            if (nombres[i][len - 1] == '\n') {
                nombres[i][len - 1] = '\0';
                len--;
            }

            for (j = 0; j < len; j++) {
                if (!((nombres[i][j] >= 'A' && nombres[i][j] <= 'Z') || (nombres[i][j] >= 'a' && nombres[i][j] <= 'z') || nombres[i][j] == ' ')) {
                    valido = 0;
                }
            }

            if (!valido) {
                printf("Solo se permiten letras.\n");
            }
        } while (!valido);
    }

    for (i = 0; i < 5; i++) {
        printf("\nIngrese las 3 calificaciones de %s:\n", nombres[i]);
        for (j = 0; j < 3; j++) {
            do {
                printf("  Materia %d: ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  Nota invalida. Debe estar entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    for (i = 0; i < 5; i++) {
        prom_est[i] = 0;
        max_est[i] = min_est[i] = notas[i][0];
        for (j = 0; j < 3; j++) {
            float nota = notas[i][j];
            prom_est[i] += nota;
            if (nota > max_est[i]) max_est[i] = nota;
            if (nota < min_est[i]) min_est[i] = nota;
        }
        prom_est[i] /= 3;
    }

    for (j = 0; j < 3; j++) {
        prom_mat[j] = 0;
        max_mat[j] = min_mat[j] = notas[0][j];
        aprobados[j] = 0;
        reprobados[j] = 0;
        for (i = 0; i < 5; i++) {
            float nota = notas[i][j];
            prom_mat[j] += nota;
            if (nota > max_mat[j]) max_mat[j] = nota;
            if (nota < min_mat[j]) min_mat[j] = nota;
            if (nota >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }
        prom_mat[j] /= 5;
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1. Promedio por estudiante\n");
        printf("2. Promedio por materia\n");
        printf("3. Nota mayor y menor por estudiante\n");
        printf("4. Nota mayor y menor por materia\n");
        printf("5. Aprobados y reprobados por materia\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1:
            printf("\n--- Promedio por estudiante ---\n");
            for (i = 0; i < 5; i++) {
                printf("%s: %.2f\n", nombres[i], prom_est[i]);
            }
            break;
        case 2:
            printf("\n--- Promedio por materia ---\n");
            for (j = 0; j < 3; j++) {
                printf("Materia %d: %.2f\n", j + 1, prom_mat[j]);
            }
            break;
        case 3:
            printf("\n--- Nota mayor y menor por estudiante ---\n");
            for (i = 0; i < 5; i++) {
                printf("%s: Mayor = %.2f, Menor = %.2f\n", nombres[i], max_est[i], min_est[i]);
            }
            break;
        case 4:
            printf("\n--- Nota mayor y menor por materia ---\n");
            for (j = 0; j < 3; j++) {
                printf("Materia %d: Mayor = %.2f, Menor = %.2f\n", j + 1, max_mat[j], min_mat[j]);
            }
            break;
        case 5:
            printf("\n--- Aprobados y reprobados por materia ---\n");
            for (j = 0; j < 3; j++) {
                printf("Materia %d: Aprobados = %d, Reprobados = %d\n", j + 1, aprobados[j], reprobados[j]);
            }
            break;
        case 6:
            printf("Saliendo.\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }

    } while (opc != 6);

    return 0;
}
