#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#define NOMBRE_DEL_ARCHIVO "numeros.txt"
#include "mpi.h"
using namespace std;

int main()
{
    MPI_Status status;
    int rank;
    MPI::Init();
    rank = MPI::COMM_WORLD.Get_rank();
    double tiempo_inicial_total;
    double tiempo_fin_total;
    double tiempo_inicio_suma;
    double tiempo_fin_suma;
    double tiempo_inicio_desviacion;
    double tiempo_fin_desviacion;
    clock_t t_tiempo;
    double secs;
    t_tiempo = clock();
    secs = (double)t_tiempo / CLOCKS_PER_SEC;
    tiempo_inicial_total=secs;
    FILE *entrada;
    int auxiliar, numero_de_datos;

   if ((entrada = fopen(NOMBRE_DEL_ARCHIVO, "r")) == NULL){
      perror(NOMBRE_DEL_ARCHIVO);
      return EXIT_FAILURE;
   }

   numero_de_datos = 0;
   while ((auxiliar = fgetc(entrada)) != EOF)
      if (auxiliar == '\n')
         numero_de_datos++;

   fclose(entrada);
   numero_de_datos=numero_de_datos+1;
    cout << "la cantidad de datos es: " << numero_de_datos<<endl;

    char texto[30];

      float zenb,arreglo_a[100000];
      int datos_procesados=0;
      int suma=0;
      int contador=0;
      int i;
      int inicio=0;
      int fin=10000;
        int ct=0;
        float varianza=0;
        t_tiempo = clock();
        secs = (double)t_tiempo / CLOCKS_PER_SEC;
        tiempo_inicio_suma=secs;
        tiempo_inicio_desviacion=secs;
 entrada =fopen(NOMBRE_DEL_ARCHIVO,"rb");
            if (entrada==NULL)
            {
                printf("Error abriendo el fichero");
            }

        else
        {
            entrada =fopen(NOMBRE_DEL_ARCHIVO,"rb");
            if (entrada==NULL)
            {
                printf("Error abriendo el fichero");
            }
            while (feof(entrada)==0)
            {
                fgets(texto,30,entrada);
                sscanf(texto,"%f",&zenb);
                if(rank==0)
                {
                    suma=zenb+suma;
                }
                if(rank==1)
                {
                    suma=zenb+suma;
                }
                if(rank==2)
                {
                    suma=zenb+suma;
                }
                if(rank==3)
                {
                    suma=zenb+suma;
                }
                if(rank==4)
                {
                    suma=zenb+suma;
                }

            }
        }

        fclose(entrada);
        t_tiempo = clock();
        secs = (double)t_tiempo / CLOCKS_PER_SEC;
        tiempo_fin_suma=secs;

 while (datos_procesados!=numero_de_datos)
 {
            contador=0;
            i=0;
            entrada = fopen(NOMBRE_DEL_ARCHIVO,"rb");
            if (entrada==NULL)
            {
                printf("Error abriendo el fichero");
            }
        else
        {
            entrada =fopen(NOMBRE_DEL_ARCHIVO,"rb");
            if (entrada==NULL)
            {
                printf("Error abriendo el fichero");
            }
            while ((feof(entrada)==0)&&(datos_procesados!=numero_de_datos))
            {
                fgets(texto,30,entrada);
                sscanf(texto,"%f",&zenb);
                contador=contador+1;
                if((contador>inicio)&&(contador<fin))
                {
                    if(rank==0)
                    {
                        arreglo_a[i]=zenb;
                        i=i+1;
                        datos_procesados=datos_procesados+1;
                        ct=ct+1;
                    }
                    if(rank==1)
                    {
                        arreglo_a[i]=zenb;
                        i=i+1;
                        datos_procesados=datos_procesados+1;
                        ct=ct+1;
                    }
                    if(rank==2)
                    {
                        arreglo_a[i]=zenb;
                        i=i+1;
                        datos_procesados=datos_procesados+1;
                        ct=ct+1;
                    }
                    if(rank==3)
                    {
                        arreglo_a[i]=zenb;
                        i=i+1;
                        datos_procesados=datos_procesados+1;
                        ct=ct+1;
                    }
                    if(rank==4)
                    {
                        arreglo_a[i]=zenb;
                        i=i+1;
                        datos_procesados=datos_procesados+1;
                        ct=ct+1;
                    }

                }
            }
        }
        for(i=0;i<ct;i=i+1)
        {
            arreglo_a[i]=(suma/numero_de_datos)-arreglo_a[i];
            arreglo_a[i]=arreglo_a[i]*arreglo_a[i];
        }
        for(i=0;i<ct;i=i+1)
        {
            varianza=varianza+arreglo_a[i];
        }
        fclose(entrada);
        inicio=fin-1;
        fin=fin+10000;
 }
    t_tiempo = clock();
    secs = (double)t_tiempo / CLOCKS_PER_SEC;
    tiempo_fin_desviacion=secs;
    tiempo_fin_total=secs;
    fclose(entrada);
    varianza=sqrt(varianza);
    cout<<"tiempo ocupado para calcular el promedio: "<<tiempo_fin_suma-tiempo_inicio_suma<<endl;
    cout<<"tiempo ocupado para calcularla desviacion estandar: "<<tiempo_fin_desviacion-tiempo_inicio_desviacion<<endl;
    cout<<"tiempo total de ejecucion: "<<tiempo_fin_total-tiempo_inicial_total<<endl;
    cout<<"la desviacion estandar es: "<<varianza<<endl;
    cout<<"el promedio de los elementos es: "<<suma/numero_de_datos<<endl;
    MPI_Finalize();
    return 0;
}
