#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sPetWithBreed.h"
#include "funciones.h"

/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                                            ORDENAR ID

_____________________________________________________________________________________________________________________________________________________________________________________________*/


/*   ========================           ORDEN ABAJO A ARRIBA                     ======================== */

/** \brief   Ordena el array de la estructura por peso de ABAJO A ARRIBA
 *
 * \param  array pasado por parametro ,para luego trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
 int  sort_DescendingId(sPet* array,int size)
{
    int result = -1;
    int i;
    int flagSwap;
    sPet auxiliary;

    if(array != NULL && size>0)
    {
        do{
                flagSwap = 0;
                for(i=0;i<size-1;i++)
                {
                        if(array[i].idPet>array[i+1].idPet)
                        {
                            flagSwap = 1;
                            auxiliary = array[i];
                            array[i] = array[i+1];
                            array[i+1]= auxiliary;
                        }
                 }
                 size--;
        }while(flagSwap);
        result = 0;
    }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                MUESTRA MASCOTAS CON SU RAZA

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief   Muestra mascotas con su raza
 *
 * \param  array mascota pasado por parametro ,para luego trabajar con el.
 * \param  array  raza pasado por parametro ,para luego trabajar con el.
 * \param  array  pais pasado por parametro ,para luego trabajar con el.
 * \param  size  mascota tamaño del array
  * \param  size raza  tamaño del array
 * \param  size  pais   tamaño del array

 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int toShowPetsWithBreeds(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry)
{
    int result = -1;
    int i;
    int j;
    int f;

    if(arrayPets != NULL && arrayBreeds != NULL && sizePet >0 && sizeBreed>0 && sizeCountry>0)
    {
            printf("\n\n              LISTA DE MASCOTAS CON SU RAZA                                             ");
            printf("\n  ================================================================");
            printf("\n | NOMBRE      |   TIPO     |       RAZA          |     PAIS      |");
        for (i=0;i<sizePet; i++)
        {
            for (j=0;j<sizeBreed; j++)
            {
                for(f=0;f<sizeCountry;f++)
                {
                     if (arrayPets[i].idBreed == arrayBreeds[j].idBreed &&
                         arrayPets[i].isEmpty == FALSE  &&
                         arrayBreeds[j].idCountry == arrayCountrys[f].idCountry)
                    {
                    printf("\n | %-10s  |   %-8s |  %-15s    |   %-11s |", arrayPets[i].name,arrayPets[i].type,arrayBreeds[j].description,arrayCountrys[f].nameCountry);
                    }
                }
            }
        }
            printf("\n  ================================================================");
        result = 0;
    }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                         CONTADOR  DE PAISES CON MAS MASCOTAS

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  Primero cuenta los paises , luego los compara para ver quien tiene mas cantidad de mascotas.
 *
 * \param  array mascota pasado por parametro ,para luego trabajar con el.
 * \param  array  raza pasado por parametro ,para luego trabajar con el.
 * \param  size  mascota tamaño del array
  * \param  size raza  tamaño del array

 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int countryWithMostPet(sPet arrayPets[],sBreed arrayBreeds[],int sizePet,int sizeBreed)
{
    int result = -1;
    int counterArg= 0;
    int counterAle= 0;
    int counterBel= 0;
    int counterTail= 0;
    int counterPers= 0;
    int counterRare= 0;
    int mostCountry;
    char countryWinner[20];
    int i;

    if(arrayPets != NULL && sizePet >0)
    {
        for (i=0;i<sizePet;i++)
        {
                if (arrayPets[i].idBreed == 5 && arrayPets[i].isEmpty == FALSE)
                {
                    counterArg++;
                }
                else if ((arrayPets[i].idBreed == 3 || arrayPets[i].idBreed== 6)  && arrayPets[i].isEmpty == FALSE)
                {
                    counterAle++;
                }
                else if (arrayPets[i].idBreed == 4 && arrayPets[i].isEmpty == FALSE)
                {
                    counterBel++;
                }
                else if (arrayPets[i].idBreed==1  && arrayPets[i].isEmpty == FALSE)
                {
                        counterTail++;
                }
                else if (arrayPets[i].idBreed == 2  && arrayPets[i].isEmpty == FALSE)
                {
                        counterPers++;
                }else if( arrayPets[i].idBreed == 7 && arrayPets[i].isEmpty == FALSE){
                            counterRare++;
                }
        }
        if (counterArg>counterAle && counterArg>counterBel && counterArg>counterTail && counterArg>counterPers && counterArg>counterRare)
        {
                mostCountry = counterArg;
                strncpy(countryWinner,"Argentina",20);
        }
        else if  (counterAle>counterBel && counterAle>counterTail && counterAle>counterPers  && counterAle>counterRare)
        {
                mostCountry = counterAle;
                strncpy(countryWinner,"Alemania",20);
        }
        else if (counterBel>counterTail && counterBel>counterPers  && counterBel>counterRare)
        {
                mostCountry = counterBel;
                strncpy(countryWinner,"Belgica",20);
        }
         else if (counterTail>counterPers  && counterTail >counterRare)
        {
                mostCountry = counterTail;
                strncpy(countryWinner,"Tailandia",20);
        }
        else if (counterPers>counterRare)
        {
                mostCountry = counterPers;
                strncpy(countryWinner,"Persia",20);
        }else {
                mostCountry = counterRare;
                strncpy(countryWinner,"Rarolandia",20);
        }
            printf("\n\n          PAIS CON MAS MASCOTA            ");
            printf("\n       =============================");
            printf("\n      | NOMBRE      |   CANTIDAD    |");

            printf("\n      | %-10s  |       %-4d    | ",countryWinner, mostCountry);
            printf("\n       =============================");
            result = 0;
     }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                MOSTRAR RAZA CON LOS DATOS DE SU PAIS

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief Muestra  raza con los datos recpectivos a su pais
 *
* \param  array mascota pasado por parametro ,para luego trabajar con el.
 * \param  array  raza pasado por parametro ,para luego trabajar con el.
 * \param  array  pais pasado por parametro ,para luego trabajar con el.
 * \param  size  mascota tamaño del array
  * \param  size raza  tamaño del array
 * \param  size  pais   tamaño del array

 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int toShowBreedWithCountry(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry)
{
    int result = -1;
    int i;
    int j;
    int f;

    if( arrayPets != NULL &&  arrayBreeds != NULL && arrayBreeds != NULL && sizeBreed>0 && sizeCountry>0 && sizePet>0 )
    {
            printf("\n\n              LISTA DE RAZA CON SU PAIS                                             ");
            printf("\n  ===============================================================================");
            printf("\n |  NOMBRE      |       RAZA        |     PAIS       |   CONTINENTE  | CODIGO TEL|");

        for (i=0;i<sizePet; i++)
        {
            for (j=0;j<sizeBreed; j++)
            {
                for(f=0;f<sizeCountry;f++)
                {
                     if (arrayPets[i].idBreed == arrayBreeds[j].idBreed &&
                         arrayBreeds[j].idCountry == arrayCountrys[f].idCountry &&   arrayPets[i].isEmpty == FALSE  &&
                         arrayBreeds[j].isEmpty == FALSE  )
                    {
                    printf("\n |  %-10s  | %-16s  |   %-12s |    %-10s |    %-6d |",arrayPets[i].name, arrayBreeds[j].description ,arrayCountrys[f].nameCountry,arrayCountrys[f].continent,arrayCountrys[f].codeTelephone);
                    }
                }
            }
        }
            printf("\n  ===============================================================================");
        result = 0;
    }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                        ORDENAR POR NUMER TELEFONICO

_____________________________________________________________________________________________________________________________________________________________________________________________*/


/*   ========================           ORDEN ABAJO A ARRIBA                     ======================== */

/** \brief   Ordena el array de la estructura por peso de ABAJO A ARRIBA
 *
 * \param  array pasado por parametro ,para luego trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
 int  sort_DescendingTelephone(sBreed arrayBreeds[], sCountry arrayCountrys[],int sizeBreed,int sizeCountry)
{
    int result = -1;
    int i;
    int j;
    sCountry auxiliaryCountry;

    if(arrayCountrys != NULL && sizeBreed>0)
    {
            for(i=0;i<sizeBreed-1;i++)
            {
                for(j=0+1;j<sizeCountry;i++)

                        if(arrayCountrys[j].codeTelephone>arrayCountrys[j+1].codeTelephone)
                        {
                            auxiliaryCountry = arrayCountrys[i];
                            arrayCountrys[i] = arrayCountrys[i+1];
                            arrayCountrys[i+1]= auxiliaryCountry;
                        }
             }
            sizeCountry--;
        result = 0;
    }
    return result;
}
/*
 _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                          BAJA LOGICA  DE  UNA RAZA

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                         FUNCION PRINCIPAL DE BORRADO
___________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  Borrado logico de una raza y a consecuencia borrado ademas de las mascotas pertenecientes a esa raza
 *
* \param  array mascota pasado por parametro ,para luego trabajar con el.
 * \param  array  raza pasado por parametro ,para luego trabajar con el.
 * \param  size  mascota tamaño del array
  * \param  size raza  tamaño del array

 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int  breed_deleteArray(sBreed arrayBreeds[],sPet arrayPets[],int sizePet,int sizeBreed)
{
    int result = -1;
    int index;
    int i;
    int  warning;
    if(arrayBreeds != NULL && arrayPets != NULL && sizePet>0 &&  sizeBreed>0)
    {
          if(toShowBreeds(arrayBreeds,sizeBreed)==-1)
          {
            printf("\n  HUBO UN ERROR AL MOSTRAR LAS MASCOTAS \n\n");
           }
           else
           {
                index = data_idSearchBreed(arrayBreeds,sizeBreed);
                if(index ==-1)
                {
                    result= -1;
                 }else{

                    if (utn_getNumeroInt(&warning,"\n      !!!ESTA POR BORRAR DATOS MUY IMPORTANTES !!!   \n    SI BORRA UNA RAZA , LAS MASCOTAS CON ESA RAZA SERAN BORRADAS .\n\n ESTA SEGURO DE BORRARLA? \n   1 para Si   |  2 para No : ",
                    "\nERROR,  LO QUE INGRESO NO ES UN NUMERO\n",1,2,2)==-1)
                    {
                            result = -1;
                    }
                    else
                    {
                            if(warning == 1)
                            {
                                for(i = 0;i<sizePet; i++)
                                {
                                        if (arrayPets[i].idBreed == arrayBreeds[index].idBreed )
                                        {
                                            arrayPets[i].isEmpty = TRUE;
                                            printf("\n ID: %-4d    NOMBRE : %-10s   ",arrayPets[index].idPet,arrayPets[index].name);
                                        }
                                }
                                arrayBreeds[index].isEmpty= TRUE;
                                result = 0;
                                system("cls");
                                printf("\n - LA RAZA SE HA BORRADO CORRECTAMENTE !! \n");
                                printf(" \n DATOS BORRADOS\n\n => ID: %d\n => RAZA: %s \n\n",arrayBreeds[index].idBreed,arrayBreeds[index].description);
                            }
                            else
                            {
                                system("cls");
                                printf("\n LA BAJA SE HA CANCELADO CORRECTAMENTE\n");
                                result = 0;
                            }
                        }
                     }
            }
    }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                    BUSCAR ID DE RAZA
_____________________________________________________________________________________________________________________________________________________________________________________________*/

int  data_idSearchBreed(sBreed array[],int size)
{
    int result = -1;
    int valueFind;
    int i;
    if(array != NULL && size>0)
    {
        if(utn_getNumeroInt(&valueFind,"\n\nINGRESE EL ID  : ","\nERROR, LO QUE INGRESO NO ES UN NUMERO\n",0,size,2)==-1)
        {
            printf("\n ERROR AL BUSCAR LA ID");
            result= -1;
         }
         else
        {
            for(i=0;i<size;i++)
            {
                if (array[i].idBreed == valueFind && array[i].isEmpty == FALSE)
                {
                    result = i;
                    break;
                }
            }
         }
    }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                LISTAR TIPO Y PESO

_______________________________________________________________________________________________________________________________________________________________________________________*/

/*     ////////////////                                 FUNCION PRINCIPAL      /////////////////////////////  */

int typeAndWeight(sPet arrayPets[],int sizePet)
{
    int result = -1;
    int arrayCounterPets[3] = {0,0,0};
    float arrayAccumulatorPets[3]={0,0,0};
    float arrayAveragePets[3]={0,0,0};

    if(arrayPets != NULL && sizePet >0)
    {
       if (
              accumulatorTypePets(arrayPets,arrayCounterPets,arrayAccumulatorPets,sizePet) == -1 ||
              average(arrayCounterPets,arrayAccumulatorPets,arrayAveragePets) == -1 )
        {
                printf("\n  ERROR AL SACAR EL PROMEDIO\n ");
        }
        else
        {
           if(toShowAverage(arrayCounterPets,arrayAccumulatorPets,arrayAveragePets)==-1)
           {
               printf("\n ERROR AL MOSTRAR LOS PROMEDIOS\n");
           }
            result = 0;
        }
     }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                    MOSTRAR LOS PROMEDIOS
_____________________________________________________________________________________________________________________________________________________________________________________________*/

int toShowAverage(int arrayCounterPets[],float arrayAccumulatorPets[],float arrayAveragePets[])
{
   int i;
   int result = -1;
   char arrayTipo[3][6]={"GATO","PERRO","RARO"};

   if (arrayAccumulatorPets != NULL && arrayAveragePets != NULL && arrayCounterPets != NULL )
   {
        system("cls");
        printf("\n\n          PROMEDIOS DE LOS TIPOS           ");
        printf("\n    =====================================================");
        printf("\n   | TIPO     |TOTAL TIPO | TOTAL PESO    | PROMEDIO PESO | ");
        for(i=0;i<3;i++)
        {
            printf("\n   | %-6s   |    %-4d   |     %-5.2f     |   %-5.2f       |",arrayTipo[i],arrayCounterPets[i], arrayAccumulatorPets[i],arrayAveragePets[i]);
        }
        printf("\n   =======================================================");
    result = 0;
   }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                    COMPARACION ,CONTADOR Y ACUMULADOR
_____________________________________________________________________________________________________________________________________________________________________________________________*/

int accumulatorTypePets(sPet arrayPets[],int arrayCounterPets[],float arrayAccumulatorPets[],int sizePet)
{
   int result =-1;
   int i;
   if (arrayPets != NULL && arrayAccumulatorPets != NULL && arrayCounterPets != NULL)
   {
           for(i= 0; i<sizePet;i++)
           {
                if( strncmp(arrayPets[i].type, "Perro",6) && arrayPets[i].isEmpty == FALSE)
                    {
                            arrayCounterPets[0]++;
                            arrayAccumulatorPets[0]= arrayAccumulatorPets[0]+arrayPets[i].weight;
                    }
                    else  if( strncmp(arrayPets[i].type, "Gato",6) && arrayPets[i].isEmpty == FALSE)
                    {
                            arrayCounterPets[1]++;
                            arrayAccumulatorPets[1]= arrayAccumulatorPets[1]+arrayPets[i].weight;
                    }
                    else  if( strncmp(arrayPets[i].type, "Raro",6) && arrayPets[i].isEmpty == FALSE)
                    {
                            arrayCounterPets[2]++;
                            arrayAccumulatorPets[2]= arrayAccumulatorPets[2]+arrayPets[i].weight;
                    }
           }
    result = 0;
    }
return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                    CALCULAR PROMEDIO
_____________________________________________________________________________________________________________________________________________________________________________________________*/

int average(int arrayCounterPets[],float arrayAccumulatorPets[],float arrayAveragePets[])
{
    int result = -1;
    int i;

    if (arrayAccumulatorPets != NULL && arrayAveragePets != NULL && arrayCounterPets != NULL )
    {
            for(i=0;i<3;i++)
            {
                    if(arrayAccumulatorPets[i] == 0 ||  arrayCounterPets[i] == 0 )
                    {
                        arrayAveragePets[i] = 0;
                        result = 0;
                    }
                    else
                    {
                    arrayAveragePets[i] = arrayAccumulatorPets[i] / arrayCounterPets[i];
                    result = 0;
                    }
            }
        }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________


                                                                                BUSCAR TIPO Y PESO

_________________________________________________________________________________________________________________________________________________________________________________________*/

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                    ACUMULADOR DE  PESO
_____________________________________________________________________________________________________________________________________________________________________________________________*/


int accumulatorSize(sBreed arrayBreeds[],sPet arrayPets[], float* accumulator,int sizePet,int sizeBreed, int strSize)
{
  int result = -1;
  int i;
  int j;

    if(arrayPets != NULL && accumulator != NULL && sizePet >0 && strSize>0)
    {
         for (i=0;i<sizePet;i++)
         {
            for (j=0;j<sizeBreed;j++)
         {
            if (arrayPets[i].idSizes == strSize &&  arrayPets[i].isEmpty == FALSE && arrayBreeds[j].idBreed == arrayPets[i].idBreed)
            {
                *accumulator= *accumulator+arrayPets[i].weight;
                result= 0;
            }
         }
        }
    }
  return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                CALCULAR TOTAL DE PESOS  DEPENDIENDO LA OPCION ELEGIDA
_____________________________________________________________________________________________________________________________________________________________________________________________*/


int TotalWeightPets(sPet arrayPets[],int sizePet,int sizeBreeds,sBreed arrayBreeds[],float* accumulator,int option)
{
    int result = -1;
    float auxAccumulator = 0;
    if(arrayBreeds != NULL && arrayPets != NULL && sizePet >0 && accumulator != NULL && option>0)
        {
                if (option==1)
                {
                    accumulatorSize(arrayBreeds, arrayPets,&auxAccumulator,sizePet,sizeBreeds,1);
                    *accumulator= auxAccumulator;
                }
                else if (option ==2)
                {
                    accumulatorSize(arrayBreeds, arrayPets,&auxAccumulator,sizePet,sizeBreeds,2);
                    *accumulator= auxAccumulator;
                }
                 else if (option ==3)
                {
                    accumulatorSize(arrayBreeds, arrayPets,&auxAccumulator,sizePet,sizeBreeds,3);
                    *accumulator= auxAccumulator;
                }
                else
                {
                    accumulatorSize(arrayBreeds, arrayPets,&auxAccumulator,sizePet,sizeBreeds,4);
                    *accumulator= auxAccumulator;
                }
        }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                    FUNCION PRINCPAL , ELECCION DEL USUARIO
_____________________________________________________________________________________________________________________________________________________________________________________________*/


int searchBySize(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry)
{
    int option;
    int result = -1;
    float accumulator = 0;
            system("cls");

    if (arrayPets != NULL && arrayBreeds != NULL )
    {
          result = 0;
    do{
            printf("\n 1-CHICO \n 2-MEDIANO\n 3-GRANDE\n 4-VOLVER \n");
           if( utn_getNumeroInt(&option,"\n -INGRESE OPCION:  ","\n ERROR, INGRESE UNA OPCION VALIDA\n",1,4,2)==-1)
           {
                    break;
           }
                TotalWeightPets(arrayPets,sizePet,sizeBreed,arrayBreeds,&accumulator,option);

                switch(option)
                {
                            case 1:
                              if (toShowSizeAndWeight(arrayPets, arrayBreeds, arrayCountrys, sizePet, sizeBreed, sizeCountry, accumulator,option,"Pequenia")==-1)
                              {
                                  printf("\n ERROR AL BUSCAR MASCOTAS CHICAS");
                              }
                            break;
                            case 2:
                              if (toShowSizeAndWeight(arrayPets, arrayBreeds, arrayCountrys, sizePet, sizeBreed, sizeCountry, accumulator,option,"Mediana")==-1)
                              {
                                  printf("\n ERROR AL BUSCAR MASCOTAS MEDIANAS");
                              }
                               break;
                            case 3:
                            if (toShowSizeAndWeight(arrayPets, arrayBreeds, arrayCountrys, sizePet, sizeBreed, sizeCountry, accumulator,option,"Grande")==-1)
                              {
                                  printf("\n ERROR AL BUSCAR MASCOTAS GRANDES");
                              }
                            break;

                    }
            }while(option!=4);
            system("cls");
    }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                           MOSTRAR   TAMAÑO Y PESO A ELECCION
 _____________________________________________________________________________________________________________________________________________________________________________________________*/

int toShowSizeAndWeight(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry,float accumulator,int option,char* strSize)
{
    int result = -1;
    int i;
    int j;
    int k;

    if (arrayPets != NULL && arrayPets != NULL && arrayPets != NULL && sizePet>0 && sizeCountry>0 && sizeBreed>0  )
    {
        system("cls");

         if (accumulator <= 0 )
         {
             printf("\n   NO HAY INFORMACION PARA MOSTRAR \n");
             result = 0;
         }
         else
         {
                printf("\n      Mascotas de Tamanio %s           ",strSize);
                printf("\n    ================================\n");
                printf("  |  NOMBRE    |   PAIS    |  PESO  |");
                for(i=0;i<sizePet;i++)
                {
                    for( j=0;j<sizeBreed;j++)
                    {
                        for( k=0;k<sizeCountry;k++)
                        {
                                if(arrayPets[i].idSizes == option && arrayPets[i].isEmpty == FALSE
                                    &&  arrayBreeds[j].idBreed == arrayPets[i].idBreed
                                    && arrayBreeds[j].idCountry == arrayCountrys[k].idCountry)
                                {
                                    printf("\n  |  %-10s| %-10s|  %-6.2f|  ",arrayPets[i].name,arrayCountrys[k].nameCountry,arrayPets[i].weight);
                                }
                         }
                     }
                  }
                  printf("\n   =================================\n");
                  printf("\n     -----------------------\n");
                  printf("   |  PESO TOTAL : %-8.2f |",accumulator);
                  printf("\n    ------------------------\n");
                  result = 0;
         }


    }
return result;
}





