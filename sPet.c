#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "sPetWithBreed.h"

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                            INICIALIZACION DE LUGARES VACIOS  DE LAS MASCOTAS
_____________________________________________________________________________________________________________________________________________________________________________________________*/


/** \brief This function declares the positions is empty in true
 *
 * \param arrayPets, Array to declare it isEmpty in true
 * \param size , Total pet size
  * \return If is correct return 0, else  return -1(error).
 *
 */
int IsEmptyPet(sPet arrayPets[],int size)
{
    int i;
    int result = -1;

        if(arrayPets != NULL && size>0)
        {
            for(i=0;i<size;i++)
            {
                arrayPets[i].isEmpty = TRUE;
            }
            result = 0;
        }
        return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                   MASCOTAS HARCODIADAS
____________________________________________________________________________________________________________________________________________________________________________________________*/


/** \brief  This function loads the pets array with data
 *
 * \param arrayPets, Array to fill it with data.
 * \param size,  Total pet size.
 * \return If is correct return 0, else  return -1(error).
 *
 */
 int initializePet(sPet arrayPets[],int size)
{
	int i;
	int result = -1;

	if(arrayPets != NULL && size>0)
	{
        int id[7]={1,2,3,4,5,6,7};
        char name[7][20]={"Pepe","Juan","Julia","Sam","Rita","Roberta","Brian"};
        int age[7]={3,5,10,5,2,5,15};
        char sex[7][2]={"M","M","F","M","F","M","F"};
        char tipo[7][6]={"Gato","Gato","Gato","Perro","Perro","Perro","Perro"};
        float auxWeight[7]={1.5, 4.2, 6.2, 18.0, 24.0, 25.0, 26.00};
		int  auxIdBreed[7]={1,2,2,3,4,5,6};
       int  idSizes[7]={1,2,2,3,3,3,};



		for(i=0;i<7;i++)
		{
		  if(arrayPets[i].isEmpty == TRUE )
		  {
			  arrayPets[i].idPet= id[i];
			  strcpy(arrayPets[i].name,name[i]);
			  arrayPets[i].age= age[i];
              strcpy(arrayPets[i].sex,sex[i]);
			  strcpy(arrayPets[i].type,tipo[i]);
               arrayPets[i].weight = auxWeight[i];
			  arrayPets[i].idBreed = auxIdBreed[i];
			    arrayPets[i].idSizes = idSizes[i];

			  arrayPets[i].isEmpty = FALSE;
		  }
		}
		result = 0;
	}
	return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                MOSTRAR  TODOS LOS DATOS DE LAS MASCOTAS

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  This function shows data loaded in the array the pets
 *
 * \param arrayPets, Array for to shows data.
 * \param size,  Total pet size.
 * \return If is correct return 0, else  return -1(error).
 *
 */
int toShowPets(sPet arrayPets[],int  size)
{
    int i;
    int result= -1;

    if(arrayPets != NULL && size >0 )
    {
                    sort_DescendingId(arrayPets,size);
                    printf("\n             LISTADO DE MASCOTAS EXISTENTE                           ");
                    printf("\n    ===============================================");
                    printf("\n   |  ID    |   NOMBRE     | EDAD | SEXO |  TIPO   |");
        for(i=0;i<size;i++)
        {
            if(arrayPets[i].isEmpty == FALSE)
            {
                   printf("\n   |  %-4d  |   %-10s |  %-3d |  %-2s  |  %-5s  |",arrayPets[i].idPet,arrayPets[i].name,arrayPets[i].age,arrayPets[i].sex,arrayPets[i].type);
            }
        }
                    printf("\n    ===============================================\n");
        result = 0;

    }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________

                                                                                //MOSTRAR MASCOTAS ORDEN POR PESO

_____________________________________________________________________________________________________________________________________________________________________________________________*/


/*  =================================            FUNCION PRINCIPAL         ======================================*/

/** \brief Funcion para mostrar datos de las mascotas con su respectivo peso .
 *
 * \param Array para mostrar las informacion
 * \param  Cantidad de mascotas que tolera el array
 * \return retorna -1 en caseo de error y 0 de lo contrario
 *
 */
int toShowPetsBySortWeight (sPet array[],int  size)
{
    int i;
    int result= -1;
    int opcion;
    sPet arrayPets[size];

    for (i=0;i<size;i++){
        arrayPets[i] = array[i];
    }

    do{
            if(array != NULL && size >0 )
            {
                       system("cls");
                        printf("\n             LISTADO DE MASCOTAS POR PESO                          ");
                        printf("\n    ================================================");
                        printf("\n   |   NOMBRE     | EDAD | SEXO |  TIPO   |   PESO   |");

                for(i=0;i<size;i++)
                {
                    if(arrayPets[i].isEmpty == FALSE)
                    {
                           printf("\n   |   %-10s |  %-3d |  %-2s  |  %-5s  | %-5.2f KG |",arrayPets[i].name,arrayPets[i].age,arrayPets[i].sex,arrayPets[i].type,arrayPets[i].weight);
                    }
                }
                        printf("\n    =================================================\n");
            result = 0;

            printf("\n         =====================================");
            printf("\n        (       1-ORDENAR MENOR A MAYOR       )");
            printf("\n        (       2-ORDENAR MAYOR A MENOR       ) ");
            printf("\n        (       3- VOLVER                     )");
            printf("\n         =====================================");

                if (utn_getNumeroInt(&opcion,"\n\n -INGRESE OPCION:   ","\n   - ERROR, INGRESE UNA OPCION CORRECTA ! \n",1,3,2)== -1)
                {
                    printf("\nERROR, EN OPCION DEL MENU\n");
                }
                else
                {
                        if (opcion == 1)
                        {
                            sort_Descending(arrayPets,size);
                            system("cls");
                        }
                        else if (opcion == 2)
                        {
                            sort_Ascending(arrayPets,size);
                            system("cls");
                        }else{
                                system("cls");
                                break;
                        }
                }
            }

    }while(opcion != 3);

    return result;
}

/*  ========================   ORDEN  ARRIBA A ABAJO =============================== */

/** \brief   Ordena el array de la estructura por peso de arriba a abajo
 *
 * \param  array pasado por parametro ,y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
 int  sort_Ascending(sPet* array,int size)
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
                        if(array[i].isEmpty || array[i+1].isEmpty )
                        {
                            continue;
                        }
                        if(array[i].weight<array[i+1].weight)
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
/*   ========================           ORDEN ABAJO A ARRIBA                     ======================== */

/** \brief   Ordena el array de la estructura por peso de ABAJO A ARRIBA
 *
 * \param  array pasado por parametro ,para luego trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
 int  sort_Descending(sPet* array,int size)
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
                        if(array[i].isEmpty || array[i+1].isEmpty )
                        {
                            continue;
                        }
                        if(array[i].weight>array[i+1].weight)
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

                                                                                        //ALTA DE UNA MASCOTA

_____________________________________________________________________________________________________________________________________________________________________________________________*/
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                        FUNCION PRINCIPAL PARA DAR DE ALTA UNA MASCOTA
_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief   Da de alta un ente.
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \param  id  id de la entidad traido generado afuera y luego incrementandolo en la funcion
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int  pet_HighArray(sPet* array,int size,int* id)
{

    int result = -1;
    int index;
    int type;
    sPet auxiliary;
    if(array != NULL && size>0  && id!= NULL)
    {
            index = pet_IsEmpty(array,size);
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
                utn_getTexto(auxiliary.name,"\n INGRESE NOMBRE: ","\n ERROR,REINGRESE NOMBRE\n",2) == 0 &&
                utn_getNumeroInt(&auxiliary.age ,"\n INGRESE EDAD: ","\n ERROR,REINGRESE EDAD.\n",0,20,2)== 0 &&
                utn_getNumeroFloat(&auxiliary.weight,"\n INGRESE PESO DE LA MASCOTA: ","\n ERROR, REINGRESE PESO. \n",0,45,2) == 0 &&
                utn_getTexto(auxiliary.sex,"\n INGRESE SEXO, 'M' (MASCULINO) O 'F' (FEMENINO): ","\n ERROR,REINGRESE SEXO,SOLO LETRA\n",2) == 0 &&
                utn_getNumeroInt(&type ,"\n TIPO DE MASCOTA \n  1-PERRO \n  2-GATO \n  3-RARO \n\n -INGRESE OPCION:  ","\n ERROR,REINGRESE TIPO.\n",1,3,2)== 0)
            {
                    result = 0;

                    pet_highIdBreed(&auxiliary,type);

                    auxiliary.idPet = *id;
                    auxiliary.isEmpty = FALSE;
                    (*id )++;
                    array[index] = auxiliary;
                    system("cls");
                    printf(" \n\n LOS DATOS SE HAN  CARGADOS CORRECTAMENTE !!\n");
                   printf(" \n  DATOS INGRESADOS\n\n => NOMBRE: %s \n => EDAD: %d\n => PESO: %.2f\n => SEXO: %s\n => TIPO: %s\n => RAZA: %d\n\n",array[index].name,array[index].age,array[index].weight,array[index].sex,array[index].type,array[index].idBreed);
            }
        }
    }
    return result;
}
/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                                ASIGNA EL TIPO DE RAZA
_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief Dependiendo lo que se cargue en tipo 1,2,3 , se le carga  el tipo de raza de la mascota
 *
 * \param  array pasado por parametro  para trabajar con trabajar con el.
 * \param  type  tamaño del array
 * \return   retorna -1 en caso de error o 0 de los contrario.
 *
 */
int pet_highIdBreed(sPet* arrayPets,int type)
{
    int result = -1;
    int breedDog;
    sPet auxiliary;

     if (type>0 && arrayPets != NULL )
     {
           switch (type )
            {
                        case 1 :
                            if(utn_getNumeroInt(&breedDog ,"\n 1-Doberman \n 2-Pastor Belga \n 3-Dogo Argentino \n 4-Pastor Aleman\n\n -INGRESE RAZA DEL PERRO: ","\n ERROR,REINGRESE UNA RAZA CORRECTA.\n",1,4,2)== 0)
                            {
                                switch(breedDog)
                                {
                                    case 1 :
                                        auxiliary.idBreed = 3;
                                        auxiliary.idSizes = 2;
                                        break;
                                    case 2:
                                        auxiliary.idBreed = 4;
                                        auxiliary.idSizes = 3;
                                        break;
                                    case 3:
                                        auxiliary.idBreed = 5;
                                        auxiliary.idSizes = 3;
                                        break;
                                    case 4 :
                                        auxiliary.idBreed = 6;
                                        auxiliary.idSizes = 3;
                                        break;
                                }
                                strncpy(arrayPets->type,"Perro",6);
                                arrayPets->idBreed = auxiliary.idBreed;
                                arrayPets->idSizes = auxiliary.idSizes;
                                result = 0;
                            }
                            else
                            {
                                    result = -1;
                                printf("\nHUBO UN ERROR AL ASIGNAR LA RAZA DEL TIPO PERRO\n");
                            }
                        break;

                        case 2 :
                             if(utn_getNumeroInt( &auxiliary.idBreed ,"\n 1-SIAMES \n 2-PERSA \n\n -INGRESE RAZA DEL GATO: ","\n ERROR,REINGRESE UNA RAZA CORRECTA.\n",1,2,2)== 0)
                            {
                                result = 0;
                                strncpy(arrayPets->type,"Gato",6);
                                if(auxiliary.idBreed == 1)
                                {
                                auxiliary.idSizes = 1;
                                }else{
                                auxiliary.idSizes = 2;
                                }
                                arrayPets->idBreed = auxiliary.idBreed;
                            }
                            else
                            {
                                result = -1;
                                printf("\nHUBO UN ERROR AL ASIGNAR LA RAZA DEL TIPO GATO\n");
                            }
                        break;

                        case 3 :
                            result = 0;
                            auxiliary.idBreed = 7;
                            strncpy(arrayPets->type,"Raro",6);
                            arrayPets->idBreed = auxiliary.idBreed;
                        break;
            }
        }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                               BUSCAR UNA POSICION PARA UN ALTA DE MASCOTA
_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief  Se le pide el numero para buscar en el array , en caso de existir se le retorna la posicion .
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o la posicion buscada
 *
 */
int  pet_IsEmpty(sPet* array,int size)
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

                                                                            //MODIFICACION  DE UNA MASCOTA

_____________________________________________________________________________________________________________________________________________________________________________________________*/

/*  ------------------------------------------------------------         FUNCION PRINCIPAL  --------------------------------------------------------------------------------------  */

/** \brief  Solo modifica datos de una posicion pedida por el usuario
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int  data_ModificacionArray(sPet* array,int size)
{
    int index;
    int result = -1;
    int option;
    int optionCero;
    int type;
    sPet auxiliary;


    if(array != NULL && size>0 )
    {
        do{
                if(toShowPets(array,size)==-1)
                {
                    printf("\n  HUBO UN ERROR AL MOSTRAR LAS MASCOTAS \n\n");
                }
                else
                {
                    printf("\n     1-INGRESAR ID\n     2-VOLVER\n ");
                    if (utn_getNumeroInt(&optionCero,"\n     -INGRESE OPCION: ","\n  ERROR, INGRESE UNA OPCION VALIDA ENTRE 1 Y 2 \n",1,2,2)==-1)
                    {
                                printf("\n\n ERROR, REINTENTOS TERMINADOS");
                                break;
                    }
                    else
                    {
                        if (optionCero == 1)
                        {
                            index = data_idSearch(array,size);
                            if(index == -1)
                            {
                                system("cls");
                                printf("\n !!! NO SE ENCONTRO LA ID INDICADA !!!! \n");
                                result= -1;
                            }
                            else
                            {
                                system("cls");
                                printf("  DATOS DE LA MASCOTA\n\n => ID: %d\n => NOMBRE: %s \n => EDAD: %d\n => PESO: %.2f\n => SEXO: %s\n => TIPO: %s\n => RAZA: %d\n\n",array[index].idPet,array[index].name,array[index].age,array[index].weight,array[index].sex,array[index].type,array[index].idBreed);
                                menu_modification();
                                if( utn_getNumeroInt(&option,"\n -INGRESE OPCION:  ","\n ERROR, INGRESE UNA OPCION VALIDA\n",1,6,2)==-1)
                                {
                                printf("\n\n ERROR ");
                                break;
                                }
                                result = 0;

                                    switch(option)
                                    {
                                        case 1 :
                                                    if (utn_getTexto(auxiliary.name,"\n INGRESE NOMBRE: ","\n ERROR,REINGRESE NOMBRE\n",2) ==-1)
                                                    {
                                                        printf("  \n\n HUBO UN ERROR AL MODIFICAR EL NOMBRE");
                                                    }
                                                    else
                                                    {
                                                       strncpy(array[index].name,auxiliary.name,15);
                                                        system("cls");
                                                        printf("\n EL NOMBRE DE LA ID %-2d A SIDO MODIFICADO CON EXITO !!! \n",array[index].idPet);
                                                    }
                                        break;
                                         case 2 :
                                                  if( utn_getNumeroInt(&auxiliary.age ,"\nINGRESE EDAD: ","\n ERROR,REINGRESE EDAD.\n",0,20,2)==-1)
                                                  {
                                                    printf("  \n\n HUBO UN ERROR AL MODIFICAR EL NOMBRE");
                                                  }
                                                  else
                                                  {
                                                    array[index].age = auxiliary.age;
                                                    system("cls");
                                                     printf("\n LA EDAD  DE LA ID %-2d A SIDO MODIFICADA CON EXITO !!! \n",array[index].idPet);
                                                  }
                                        break;
                                         case 3:
                                                if( utn_getTexto(auxiliary.sex,"\n INGRESE SEXO, 'M' (MASCULINO) O 'F' (FEMENINO): ","\n ERROR,REINGRESE SEXO,SOLO LETRA\n",2) ==-1)
                                                {
                                                       printf("  \n\n HUBO UN ERROR AL MODIFICAR EL SEXO !!! ");
                                                }
                                                else
                                                {
                                                     strncpy(array[index].sex ,auxiliary.sex,15);
                                                     system("cls");
                                                     printf("\n EL SEXO DE LA ID %-2d A SIDO MODIFICADO CON EXITO!!! \n",array[index].idPet);
                                                }
                                                break;
                                         case 4 :
                                                if( utn_getNumeroInt(&type ,"\n TIPO DE MASCOTA \n  1-PERRO \n  2-GATO \n  3-RARO \n\n -INGRESE OPCION:  ","\n ERROR,REINGRESE TIPO.\n",1,3,2)==-1)
                                                {
                                                       printf("  \n\n HUBO UN ERROR AL MODIFICAR EL NOMBRE!!!!");
                                                }
                                                else
                                                {
                                                        pet_highIdBreed(&auxiliary,type);
                                                        strncpy( array[index].type,auxiliary.type,30);
                                                        array[index].idBreed = auxiliary.idBreed;
                                                        system("cls");
                                                          printf("\n\n LA MODIFICACION DE LA ID %-2d  DEl TIPO Y RAZA A SIDO EXITOSA!! \n",array[index].idPet);
                                                }
                                        break;
                                        case 5 :
                                                  if( utn_getNumeroFloat(&auxiliary.weight,"\n INGRESE PESO DE LA MASCOTA: ","\n ERROR, REINGRESE PESO. \n",0,45,2)==-1)
                                                {
                                                       printf("  \n\n HUBO UN ERROR AL MODIFICAR EL PESO!!!");
                                                }
                                                else
                                                {
                                                        array[index].weight = auxiliary.weight;
                                                       system("cls");
                                                       printf("\n\n LA MODIFICACION DEL PESO DE LA ID %-2d A SIDO EXITOSA!!!  \n",array[index].idPet);
                                                }
                                        break;
                                    }//FIN DE SWITCH -- FIN DE MENU DE MODIFICACION
                                }// FIN ---- INDICE ENCONTRADO
                            }   // FIN ---- OPCION 1--> BUSCA EL INDICE Y SI LO ENCUENTRA ENTRA AL MENU DE MODIFICACION
                            else
                            {
                                result = 0;
                                system("cls");
                                break ; // OPCION 2 --> VOLVER AL MENU PRINCIPAL, ENTRA AL ELSE Y ROMPE.
                            }
                        }
                    }
      }while(option != 6);
        system("cls");
    }
    return result;
}

/* _____________________________________________________________________________________________________________________________________________________________________________________________
                                                                     PEDIMOS ID PARA MODIFICAR
_____________________________________________________________________________________________________________________________________________________________________________________________*/

/** \brief Pide el id para buscar, de encontrarlo procede a continuar con la modificacion.
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error , de lo contrario retorna 0 y continua con la modificacion.
 *
 */
int  data_idSearch(sPet* array,int size)
{
    int result = -1;
    int valueFind;
    int i;
    if(array != NULL && size>0)
    {
        if(utn_getNumeroInt(&valueFind,"\nINGRESE EL ID  : ","\nERROR, LO QUE INGRESO NO ES UN NUMERO\n",0,10,2)==-1)
        {
            result= -1;
         }
         else
        {
            for(i=0;i<size;i++)
            {
                if (array[i].idPet == valueFind && array[i].isEmpty == FALSE)
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

                                                                          BAJA LOGICA  DE UNA MASCOTA

_____________________________________________________________________________________________________________________________________________________________________________________________*/


/** \brief  Borrado logico de una posicion del array
 *
 * \param  array pasado por parametro , y trabajar con el.
 * \param  size  tamaño del array
 * \return    retorna -1 en caso de error o 0 si fue exitosa
 *
 */
int  pet_deleteArray(sPet* array,int size)
{
    int result = -1;
    int index;
    int  warning;
    struct auxliary;
    if(array != NULL && size>0)
    {
          if(toShowPets(array,size)==-1)
           {
            printf("\n  HUBO UN ERROR AL MOSTRAR LAS MASCOTAS \n\n");
           }
           else
           {
                index = data_idSearch(array,size);
                if(index ==-1)
                {
                    result= -1;
                 }else{

                        if (utn_getNumeroInt(&warning,
                        "\n      !!!ESTA POR BORRAR DATOS MUY IMPORTANTES !!!   \n RECUERDE ADEMAS QUE TIENE LA POSIBILIDAD DE MODIFICAR DATOS.\n\n ESTA SEGURO DE BORRAR SUS DATOS? \n   1 para Si   |  2 para No : ",
                        "\nError, lo ingresado es invalido\n",1,2,2)==-1)
                        {
                            result = -1;
                        }
                        else
                        {
                            if(warning == 1)
                            {
                                result = 0;
                                array[index].isEmpty= TRUE;
                                system("cls");

                                printf("\n - LOS DATOS SE HAN BORRADO CORRECTAMENTE !! \n");
                                printf(" \n DATOS BORRADOS\n\n => ID: %d\n => NOMBRE: %s \n => EDAD: %d\n => PESO: %.2f\n => SEXO: %s\n => TIPO: %s\n => RAZA: %d\n\n"
                                       ,array[index].idPet,array[index].name,array[index].age,array[index].weight,array[index].sex,array[index].type,array[index].idBreed);

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

