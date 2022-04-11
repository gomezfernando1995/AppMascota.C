/*
 ============================================================================
 Name        : Mascotas.c
 Author      :  Fernando gomez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sPetWithBreed.h"
#include "funciones.h"

int main()
{
	sPet arrayPets[SIZE_PET];
	sBreed arrayBreeds[SIZE_BREED];
	sCountry arrayCountrys[SIZE_COUNTRY];

    int option;
    int idPet = 8;
    int idBreed = 8;

   if ( IsEmptyPet(arrayPets,SIZE_PET)== -1 ||
        initializePet(arrayPets,SIZE_PET)== -1 ||
        breedIsEmpty(arrayBreeds,SIZE_BREED)==-1 ||
        initializerBreed(arrayBreeds,SIZE_BREED)==-1 ||
        initializerCountry(arrayCountrys,SIZE_COUNTRY)==-1 )
	{
		printf("Error,File Not Found");
	}

	do{
              printf("\n     ====MENU PRINCIPAL=====\n    |");
              printf("                       |\n    |     1-DAR DE ALTA     |\n    |     2-MODIFICAR       |\n    |     3-BORRAR DATOS    |\n    |     4-MOSTRAR DATOS   |\n    |     5-SALIR           |\n");
              printf("     =======================\n");

               if( utn_getNumeroInt(&option,"\n INGRESE OPCION ==>  ","\n -ERROR,REINGRESE OPCION\n",1,5,2)==-1)
                {
                        printf("\n ERROR, HUBO MUCHOS REINTENTOS\n");
                        break;
                }

            switch(option)
            {
                    case 1:
                        system("cls");
                        if (menu_highData(arrayPets,arrayBreeds,arrayCountrys,SIZE_PET,SIZE_BREED,SIZE_COUNTRY,&idPet,&idBreed)==-1)
                         {
                            printf("\n!! ERROR AL MODIFICAR MASCOTA !!\n");
                         }
                    break;
                    case 2:
                        system("cls");
                        if(data_ModificacionArray(arrayPets,SIZE_PET)==-1)
                        {
                            printf("\n!! ERROR AL MODIFICAR MASCOTA !!\n");
                        }
                    break;
                    case 3:
                            system("cls");
                            if (menu_DeleteData(arrayPets,arrayBreeds, arrayCountrys,SIZE_PET,SIZE_BREED,SIZE_COUNTRY)==-1)
                            {
                                printf("\n!! ERROR AL INTENTAR DAR DE BAJA A UNA  MASCOTA !!\n");
                            }
                    break;
                    case 4:
                                system("cls");
                                if ( menu_ToshowDataTable(arrayPets,arrayBreeds,arrayCountrys,SIZE_PET, SIZE_BREED,SIZE_COUNTRY) == -1)
                                {
                                    printf("Error File Not Found");
                                }
                    break;
            }
    }while(option !=5);

        printf("\nGRACIAS POR USAR NUESTRO SISTEMA\n");

	return 0;
}
