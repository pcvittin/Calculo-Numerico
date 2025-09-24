#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fposicao(double, double, double, double, int);
double bissecao(double, double, double, double, int);
double absoluto(double);
double f(double);

int main()
{
    double a = 0.75; //ponto inical do intervalo
    double b = 1.3; //ponto final do intervalo
    double p; //ponto medio do intervalo;
    double tol = 0.0000000001; //tolerancia do erro;
    int ex = 10000;//numero maximo de interações;

    bissecao(a, b, p, tol, ex);
    fposicao(a, b, p, tol, ex);
    return 0;
}

double absoluto(double x){
    
    return (x < 0) ? -x:x;
    
}

double f(double x){
    return pow(x,2)+(3*x)-4;
    //return (pow(2, -x)-2*sin(x));
    //return sin(x) + log(x);

}
double bissecao(double a, double b, double p, double tol, int ex){

    int i = 1;
    double FA = f(a);
    double FP;
    double FB = f(b);
    double c;
    printf("   A     |    B     |   F(A)     |    F(B)    |    P     |    F(P)    |    C     \n");
    while(i <= ex){
        p = (b+a)/2;//calcula o ponto medio
        FP = f(p);
        c = b-a/2;
        printf("%f | %f | %f   | %f  | %f | %f | %f \n", a, b, FA, FB, p, FP, c);

        if(FP == 0 || (b - a) < tol ){
            
            printf("Procedimento concluido com sucesso!\n");
            printf("%d interacoes para aproximacoo de %f\n", i, p);
            break;

        }
        i = i + 1;
        //fverifica se o sinal de a e p são iguais
        if(FA*FP > 0){
            a = p;
            FA = FP;
        }
        else
        {
            b = p;
        }
        
    }
    printf("O procedimento falhou apos %d interações\n", i);
    return 0.0;
}

double fposicao(double a, double b, double p, double tol, int ex){

    int i = 1;
    double FA, FB, p_anterior = 0, c, FP;
    p = ((a*FB) -(b*FA))/FB-FA; 
    printf("   A     |    B     |   F(A)     |    F(B)    |    P     |    F(P)    |    C     \n");
    while (i <= ex)
    {
        FA = f(a);
        FB = f(b);
        p = ((a*FB) - (b*FA))/(FB-FA);
        FP = f(p);
        c = p_anterior - p;
        printf("%f | %f | %f   | %f  | %f | %f | %f \n", a, b, FA, FB, p, FP, c);
        if(absoluto(c) < tol){

            printf("Procedimento concluido com sucesso!\n");
            printf("%d interacoes para aproximacao de %f\n", i, p);
            break;
        }
        i = i + 1;
        p_anterior = p;
        if(FA*FP > 0)
        {
            a = p;
        }
        else
        {
            b = p;
        };

    }
    printf("O procedimento falhou apos %d interações", i);
    return 0.0;
}
