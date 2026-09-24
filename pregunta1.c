#include <stdio.h>

int main(void) {
    unsigned int registro = 0;
    unsigned int temp_n;
    unsigned char n;
    char opcion;

    for (;;) {
        printf("\nOpciones:\n1- Encender bit\n2- Apagar bit\n3- Alternar bit\n4- Consultar bit\n5- Imprimir\n6- Contar encendidos\n7- Invertir todos\ne- Salir\nOpcion: ");
        scanf(" %c", &opcion);
        
        if (opcion == 'e' || opcion == 'q') {
            break;
        }
        
        if (opcion >= '1' && opcion <= '4') {
            printf("Ingrese bit n (0-31): ");
            if (scanf("%u", &temp_n) != 1 || temp_n > 31) {
                fprintf(stderr, "Error de rango\n");
                continue;
            }
            n = (unsigned char)temp_n;

            if (opcion == '1') {
                registro |= (1u << n);
            } else if (opcion == '2') {
                registro &= ~(1u << n);
            } else if (opcion == '3') {
                registro ^= (1u << n);
            } else if (opcion == '4') {
                if ((registro & (1u << n)) != 0) {
                    printf("Encendido\n");
                } else {
                    printf("Apagado\n");
                }
            }
        } else if (opcion == '5') {
            printf("Registro: ");
            for (int i = 31; i >= 0; i--) {
                printf("%d", (registro >> i) & 1);
                if (i % 4 == 0 && i != 0) printf(" ");
            }
            printf("\nHex     : 0x%08X\n", registro);
            printf("Decimal : %u\n", registro);
        } else if (opcion == '6') {
            unsigned int t = registro;
            int cont = 0;
            while (t) { 
                t &= (t - 1); 
                cont++; 
            }
            printf("Bits encendidos: %d\n", cont);
        } else if (opcion == '7') {
            
        } else {
            fprintf(stderr, "Error\n");
        }
    }
    
    printf("\n--- ESTADO FINAL ---\n");
    printf("Registro: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (registro >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    printf("\nHex     : 0x%08X\n", registro);
    printf("Decimal : %u\n", registro);
    
    return 0;
}