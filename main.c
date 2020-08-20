#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pacientes; 
    int * cama;
} hospital;

typedef struct{
    char * nombre;
    char * apellido;
    int edad;
} paciente;

int main(int argc, const char * argv[])
{

    paciente * pacientes;
    paciente * aux;
    int numpacientes = 0;

    printf("Numero de pacientes: ");
    scanf("%d", &numpacientes);

    pacientes = (paciente *) malloc(sizeof(paciente) * numpacientes);

    paciente * final = pacientes + numpacientes;

    for (aux = pacientes; aux < final; ++aux)
    {
        aux->nombre = (char *) malloc(sizeof(char) * 30);
        printf("Ingrese el nombre: ");
        scanf("%s", aux-> nombre);

        aux->apellido = (char *) malloc(sizeof(char) * 60);
        printf("Ingrese el apellido: ");
        scanf("%s", aux->apellido);

        printf("Ingrese la edad: ");
        scanf("%d", &aux->edad);
    }

    printf("La cantidad de pacientes es: %d", numpacientes);

    for (aux = pacientes; aux < final; ++aux) {
        free(aux->nombre);
        free(aux->apellido);
    }
    
    free(pacientes);

    return 0;
    
}