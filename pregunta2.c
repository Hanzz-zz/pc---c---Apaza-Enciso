/*#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if(a>0&&b>0&&c>0){
    if(a+b>c&&a+c>b&&b+c>a){
    if(a==b&&b==c){printf("equilatero\n");}
    else {
    if(a==b||b==c||a==c){printf("isosceles\n");}
    else{printf("escaleno\n");}
    }
    }else{printf("no triangulo\n");}
    }else{printf("invalido\n");}






    return 0;
}
*/


#include <stdio.h>
#include <math.h> 


#define INVALIDO 0
#define NO_FORMAN 1
#define EQUILATERO 2
#define ISOSCELES 3
#define ESCALENO 4



int main(void) {
    long long lado_a, lado_b, lado_c;     
    printf("Ingrese los 3 lados: ");
    if (scanf("%lld %lld %lld", &lado_a, &lado_b, &lado_c) != 3) {
        fprintf(stderr, "Error: Se esperaban 3 enteros.\n"); 
                return 1;
    }
        long long orig_a = lado_a, orig_b = lado_b, orig_c = lado_c;
        long long temp;
    if (lado_a > lado_b) { temp = lado_a; lado_a = lado_b; lado_b = temp; }
    if (lado_b > lado_c) { temp = lado_b; lado_b = lado_c; lado_c = temp; }
    if (lado_a > lado_b) { temp = lado_a; lado_a = lado_b; lado_b = temp; }





    int tipo;
    if (lado_a <= 0) {
        tipo = INVALIDO;
    } else if (lado_a + lado_b <= lado_c) {
        tipo = NO_FORMAN;
    } else if (lado_a == lado_c) {
        tipo = EQUILATERO;
    } else if (lado_a == lado_b || lado_b == lado_c) {
        tipo = ISOSCELES;
    } else {
        tipo = ESCALENO;
    }

    printf("\n%-11s: %lld, %lld, %lld\n", "Lados", orig_a, orig_b, orig_c);
    
        switch (tipo) {
        case INVALIDO: 
            printf("%-11s: Invalido\n", "Tipo"); break;
        case NO_FORMAN: 
            printf("%-11s: No forman triangulo\n", "Tipo"); break;
        case EQUILATERO: 
            printf("%-11s: Equilatero\n", "Tipo"); break;
        case ISOSCELES: 
            printf("%-11s: Isosceles\n", "Tipo"); break;
        case ESCALENO: 
            printf("%-11s: Escaleno\n", "Tipo");
            double s = (orig_a + orig_b + orig_c) / 2.0; 
            double area = sqrt(s * (s - orig_a) * (s - orig_b) * (s - orig_c));
            printf("%-11s: %.3f\n", "Area", area);break;
    }




    if (tipo != INVALIDO && tipo != NO_FORMAN) {
        if (lado_c * lado_c == (lado_a * lado_a) + (lado_b * lado_b)) {
            printf("%-11s: Si\n", "Rectangulo");
        } else {
            printf("%-11s: No\n", "Rectangulo");
        }
    }








    return 0;
}





































