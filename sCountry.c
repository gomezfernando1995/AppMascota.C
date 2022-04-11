#include "sCountry.h"
#include <stdio.h>
#include <stdlib.h>

/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                HARCODEO DE  PAISES

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  Declaramos datos en el array para luego comprobar de que funcione correctamente .
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return   retorna -1 en caso de error o 0 de los contrario.
 *
 */
int initializerCountry(sCountry arrayCountrys[], int size)
{
    int result = -1;

    if (arrayCountrys != NULL && size >0){

    int i;
    int  idCountry[SIZE_COUNTRY]={1,2,3,4,5,6};
    char nameCountry[SIZE_COUNTRY][20]={"Argentina","Alemania","Belgica","Tailandia","Persia","Rarolandia"};
    char continent[SIZE_COUNTRY][20]={"America","Europa","Europa","Asia","Asia","Marte"};
    int  codeTelephone[SIZE_COUNTRY]={54,49,32,66,98,666};

        for (i=0;i<size;i++)
        {
            arrayCountrys[i].idCountry = idCountry[i];
            strcpy(arrayCountrys[i].nameCountry, nameCountry[i]);
            strcpy(arrayCountrys[i].continent, continent[i]);
            arrayCountrys[i].codeTelephone = codeTelephone[i];
        }
    result = 0;
    }

    return result;
}
