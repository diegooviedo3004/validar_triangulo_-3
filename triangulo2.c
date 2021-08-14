#include <stdio.h>
#include <cs50.h>

//Prototipo funcion validar y pedir los numeros que entraran al arreglo
int validar_triangulo(int lista[]);
int pedir_numeros();

int main()
{
    //Declaramos una lista y un iterador para los for

    int lista[3],i;

    //A través de un for introducimos los valores a la lista ya
    //que la funcion pedir_numeros retorna un valor

    for(i=0;i<3;i++)
    {
        lista[i] = pedir_numeros();
    }

    //Se llama a la funcion validar triangulo que devuelve True si el triangulo es posible
    //False si no es posible
    //Le pasamos nuestra lista como argumento

    if(validar_triangulo(lista))
    {
        printf("Si es un triangulo posible\n");
    }else{
        printf("No es un triangulo posible\n");
    }
    return 0;

}
//Definicion de funcion pedir_numeris
int pedir_numeros()
{

    int variable;

    //Se realiza un ciclo do while que solo retornara valor
    //Si este es positivo (debido a que son medidas de lados de triangulos)

    do{
        variable = get_int("Introduzca un lado del triangulo: ");
    }while(variable < 0);

    //Retornamos el numero que será posteriormente incluido en el array
    return variable;
}
int validar_triangulo(int lista[])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        //Si en una iteracion la suma de dos lados es menor a el lado restante,
        //el programa devuelve Falso
        //utilizando %3, los indices cambian, comprobando entonces todas las posibilidades
        if (!(lista[i % 3] + lista[(i + 1) % 3] > lista[(i + 2) % 3]))
        {
            return 0;
        }
    }
    //Si el programa llega hasta este punto entonces el triangulo si es posible
    return 1;
}
