#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sPetWithBreed.h"

#define SIZE_BREEDS 7
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                       LUGARES VACIOS DE RAZA

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief Se declara todas las posiciones del array de razas como vacias .
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 de los contrario.
 *
 */
int breedIsEmpty(sBreed arrayBreeds[],int size)
{
    int i;
    int result =-1;

    if(arrayBreeds != NULL && size>0)
    {
            for(i=0;i<size; i++)
            {
                arrayBreeds[i].isEmpty=TRUE;
            }
            result = 0;
    }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                HARCODEO DE  RAZAS

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  Declaramos datos en el array como prueba de que funcione correctamente .
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return   retorna -1 en caso de error o 0 de los contrario.
 *
 */

int initializerBreed(sBreed arrayBreeds[], int size)
{
    int result = -1;

    if (arrayBreeds != NULL && size >0)
    {
        int i;
        int  idBreed[SIZE_BREEDS]={1,2,3,4,5,6,7};
        char description[SIZE_BREEDS][20]={"Siames","Persa","Doberman","Pastor Belga","Dogo Argentino","Pastor Aleman","Indefinido"};
        char sizes[SIZE_BREEDS][20]={"Chico","Mediano","Mediano","Grande","Grande","Grande","Indefinido"};
        int  idSizes[SIZE_BREEDS]={1,2,3,3,3,3,4};
        int  idCountry[SIZE_BREEDS]={4,5,2,3,1,2,6};

            for (i=0;i<SIZE_BREEDS;i++)
            {
                if(arrayBreeds[i].isEmpty == TRUE )
                {
                arrayBreeds[i].idBreed = idBreed[i];
                strcpy(arrayBreeds[i].description, description[i]);
                strcpy(arrayBreeds[i].sizes, sizes[i]);
                arrayBreeds[i].idCountry = idCountry[i];
                arrayBreeds[i].idSizes = idSizes[i];
                arrayBreeds[i].isEmpty = FALSE;

                }
            }
        result = 0;
    }

    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                  MOSTRAR RAZAS

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  Muestra los datos almacenados en el array de razas
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return   retorna -1 en caso de error o 0 de los contrario.
 *
 */
int toShowBreeds(sBreed arrayBreeds[],int  size)
{
    int i;
    int result= -1;

    if(arrayBreeds != NULL && size >0 )
    {
                    printf("\n                   LISTADO DE RAZAS                       ");
                    printf("\n       ===========================================");
                    printf("\n      | ID RAZA   | DESCRIPCION     |    TAMANIO  |");
        for(i=0;i<size;i++)
        {
            if(arrayBreeds[i].isEmpty == FALSE)
            {
                   printf("\n      |    %-2d     |  %-15s| %-10s  |",arrayBreeds[i].idBreed,arrayBreeds[i].description,arrayBreeds[i].sizes);
            }
        }
                    printf("\n       ===========================================");
        result = 0;
    }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                        //ALTA DE UNA RAZA

_____________________________________________________________________________________________________________________________________________________________________________________________*/


/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                BUSCAR UN LUGAR LIBRE PARA DAR UN ALTA DE RAZA
____________________________________________________________________________________________________________________________________________________________________________________________*/


/** \brief  Se le pide el numero para buscar en el array , en caso de existir se le retorna la posicion .
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o la posicion buscada
 *
 */
int  breed_IsEmpty(sBreed* array,int size)
{
    int result = -1;
    int i;
    if(size>0)
    {
            for(i=0;i<size;i++)
            {
                    if (array[i].isEmpty == TRUE)
                    {
                        result = i;
                        break;
                    }
            }
    }
    return result;
}



 /* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                        FUNCION PRINCIPAL DE ALTA DE RAZA
_____________________________________________________________________________________________________________________________________________________________________________________________*/

 /** \brief   Da de alta un ente.
 *
 * \param  array - Este es pasado por parametro , para  trabajar con el.
 * \param  size  Tamaño del array
 * \param  id  - Id de la entidad traido generado afuera y luego incrementandolo en la funcion
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int  breed_High(sBreed* array,int size,int* id)
{

    int result = -1;
    int index;
    int tam;
    sBreed auxiliary;
    if(array != NULL && size>0  && id!= NULL)
    {
            index = breed_IsEmpty(array,size);
            result = 0;
        if(index == -1)
        {
                printf(" \n   __________ATTENTION!______________\n");
                printf("  |                                  |\n");
                printf("  | ERROR, THERE IS NO MORE PLACE !! |\n");
                printf("   __________________________________\n");
        }
        else
        {
           if(
                utn_getTexto(auxiliary.description,"\n INGRESE RAZA: ","\n ERROR,REINGRESE RAZA\n",2) == 0 &&
                utn_getNumeroInt(&tam ,"\n INGRESE TAMANIO\n\n 1-CHICO\n 2-MEDIANO\n 3-GRANDE\n\n ELIJA UNA OPCION: ","\n ERROR,REINGRESE TAMANIO.\n",1,3,2)== 0 &&
                utn_getNumeroInt(&auxiliary.idCountry ,"\n PAIS DE ORIGEN \n  1-ARGENTINA \n  2-ALEMANIA \n  3-BELGICA \n  4-TAILANDIA\n  5-PERSIA\n\n -INGRESE OPCION:  "
                    ,"\n ERROR,REINGRESE TIPO.\n",1,5,2)== 0)
            {
                switch(tam)
                {
                    case 1:
                        strncpy(auxiliary.sizes,"Chico",6);
                    break;
                    case 2:
                        strncpy(auxiliary.sizes,"Mediano",10);
                    break;
                    case 3:
                         strncpy(auxiliary.sizes,"Grande",10);
                    break;
                }
                    result = 0;
                    auxiliary.idBreed = *id;
                    auxiliary.isEmpty = FALSE;
                    (*id )++;
                    array[index] = auxiliary;
                    system("cls");
                    printf(" \n\n LOS DATOS SE HAN  CARGADOS CORRECTAMENTE !!\n");
                   printf(" \n  DATOS INGRESADOS\n\n => ID: %d \n => RAZA: %s \n => TAMANIO DE LA RAZA: %s\n => PAIS ORIGEN: %d \n\n",array[index].idBreed,array[index].description,array[index].sizes,array[index].idCountry);
            }
        }
    }
    return result;
}

