#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * nombre;
    char * apellido;
    int edad;
} paciente;

typedef struct {
    paciente * pacientes;
    int ** cama;
} hospital;

int main(int argc, const char * argv[])
{

    paciente * pacientes;
    paciente * aux;
    paciente * final;
    int numpacientes = 0;
    int numcamas = 0;
    char ** camas = malloc(numcamas);
    


    crearPacientes(numpacientes, numcamas, pacientes, aux, camas, final);
    //printf("Hola?");
    
    
   
    printf("\n\n-------Hospital--------\n");
    printf("La cantidad de pacientes es: %d\n", numpacientes);
    for(aux = pacientes; aux < final; ++aux)
    {
        printf("Nombre: %30s \t Apellido: %30s \t Edad: %3d \n", aux->nombre, aux->apellido, aux->edad);
    }

    for (aux = pacientes; aux < final; ++aux) {
        free(aux->nombre);
        free(aux->apellido);
    }
    
    free(pacientes);

    return 0;
    
}

void crearPacientes(int numpacientes, int numcamas, paciente * pacientes, paciente * aux, char ** camas, paciente * final)
{   
    printf("Numero de pacientes: ");
    scanf("%d", &numpacientes);
    pacientes = (paciente *) malloc(sizeof(paciente) * numpacientes);
    final = pacientes + numpacientes;
     for (aux = pacientes; aux < final; ++aux)
    {
        aux->nombre = (char *) malloc(sizeof(char) * 30);
        printf("Ingrese el nombre: ");
        scanf("%s", aux-> nombre);

        aux->apellido = (char *) malloc(sizeof(char) * 30);
        printf("Ingrese el apellido: ");
        scanf("%s", aux->apellido);

        printf("Ingrese la edad: ");
        scanf("%d", &aux->edad);
    }

    do{
        numcamas += 5;
        char ** temp = realloc(camas,numcamas);
        camas = temp;

        for (aux = pacientes; aux < final; ++ aux)
        {
            for (size_t i = 0; i < numcamas; i++)
            {
                camas[i] = (aux->nombre);
                
                printf("Cama n°: %s \n", camas[i]);
            }
            
        }

    } while (numcamas < numpacientes);
    printf("Paciientes: %d, Camas: %d", numpacientes, numcamas);
    return numcamas, numpacientes, pacientes, aux, camas;
}