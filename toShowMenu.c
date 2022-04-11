#include <stdio.h>
#include <stdlib.h>
#include "sPetWithBreed.h"


int menu_ToshowDataTable(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry)
{
    int option;
    int result = -1;

    if (arrayPets != NULL && arrayBreeds != NULL )
    {
          result = 0;
         do{
            printf("\n     ===============================================\n ");
            printf("   |                                               |\n ");
            printf("   | ==> 1-TABLA DE MASCOTAS                       |\n");
            printf("    | ==> 2-TABLA DE RAZAS                          |\n");
            printf("    | ==> 3-TABLA DE MASCOTAS CON SU RAZA           |\n");
            printf("    | ==> 4-TABLA DE MASCOTAS ORDENADA POR PESO     |\n");
            printf("    | ==> 5-PAIS CON MAS MASCOTAS                   |\n");
            printf("    | ==> 6-TABLA DE RAZA CON SU PAIS               |\n");
            printf("    | ==> 7-PROMEDIO Y PESO                         |\n ");
            printf("   | ==> 8-BUSCAR POR TAMANIO                      |\n ");
            printf("   | ==> 9-VOLVER                                  |\n ");
            printf("   |                                               |\n ");
            printf("    ===============================================\n");
           if( utn_getNumeroInt(&option,"\n -INGRESE OPCION:  ","\n ERROR, INGRESE UNA OPCION VALIDA\n",1,9,2)==-1)
           {
                    break;
           }
                    switch(option)
                    {
                            case 1:
                                        if (toShowPets(arrayPets,sizePet)==-1)
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;
                            case 2:
                                        if(  toShowBreeds(arrayBreeds,sizeBreed)==-1)
                                         {
                                            printf("Error File Not Found");
                                          }
                            break;
                            case 3:
                                        if ( toShowPetsWithBreeds(arrayPets,arrayBreeds,arrayCountrys,sizePet,sizeBreed,sizeCountry)==-1 )
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;
                            case 4:
                                        if ( toShowPetsBySortWeight (arrayPets,sizePet)==-1 )
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;
                            case 5:
                                        if ( countryWithMostPet(arrayPets,arrayBreeds,sizePet,sizeCountry)==-1 )
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;
                             case 6:
                                        if ( toShowBreedWithCountry(arrayPets,arrayBreeds,arrayCountrys,sizePet,sizeBreed,sizeCountry)==-1 )
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;
                             case 7:
                                        if ( typeAndWeight(arrayPets,sizePet)==-1 )
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;
                             case 8:
                                        if (searchBySize(arrayPets,arrayBreeds,arrayCountrys,sizePet,sizeBreed,sizeCountry)==-1 )
                                        {
                                            printf("Error File Not Found");
                                        }
                            break;


                    }
            }while(option!=9);
            system("cls");
    }
    return result;
}

int menu_modification()
{

                printf("\n      ===============================================\n ");
                 printf("    |                                               |\n ");
                printf("    | ==> 1-MODIFICAR NOMBRE                        |\n");
                printf("     | ==> 2-MODIFICAR EDAD                          |\n");
                printf("     | ==> 3-MODIFICAR SEXO                          |\n");
                printf("     | ==> 4-MODIFICAR TIPO Y RAZA                   |\n");
                printf("     | ==> 5-MODIFICAR PESO                          |\n");
                printf("     | ==> 6-VOLVER                                  |\n ");
                printf("    |                                               |\n ");
                printf("     ===============================================\n");
    return 0;
}

int menu_highData(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry,int* idPet,int* idBreed)
{
    int option;
    int result = -1;
    int idUno;
    int idDos;

    idUno = *idPet;
    idDos = *idBreed;

    if (arrayPets != NULL && arrayBreeds != NULL )
    {
          result = 0;
         do{
            printf("\n     ===============================================\n ");
            printf("   |                                               |\n ");
            printf("   | ==> 1-ALTA DE MASCOTA                         |\n");
            printf("    | ==> 2-ALTA DE RAZA                            |\n");
            printf("    | ==> 3-VOLVER                                  |\n ");
            printf("   |                                               |\n ");
            printf("    ===============================================\n");

           if( utn_getNumeroInt(&option,"\n -INGRESE OPCION:  ","\n ERROR, INGRESE UNA OPCION VALIDA\n",1,3,2)==-1)
           {
                    break;
           }
                    switch(option)
                    {
                            case 1:
                                        system("cls");
                                        if(pet_HighArray(arrayPets,sizePet,&idUno)==-1)
                                        {
                                            printf(" \n ERROR AL DAR DE ALTA UNA MASCOTA !! \n");
                                        }
                                        *idPet = idUno;
                            break;
                            case 2:
                                        if(  breed_High(arrayBreeds,sizeBreed,&idDos)==-1)
                                         {
                                            printf("Error File Not Found");
                                          }
                                          *idBreed = idDos;
                            break;

                    }
            }while(option!=3);
            system("cls");
    }
    return result;
}

int menu_DeleteData(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry)
{
    int option;
    int result = -1;


    if (arrayPets != NULL && arrayBreeds != NULL )
    {
          result = 0;
         do{
                toShowPetsWithBreeds(arrayPets,arrayBreeds,arrayCountrys,sizePet,sizeBreed,sizeCountry);
                toShowBreeds(arrayBreeds,sizeBreed);
            printf("\n     ===============================================\n ");
            printf("   |                                               |\n ");
            printf("   | ==> 1-BAJA DE MASCOTA                         |\n");
            printf("    | ==> 2-BAJA DE RAZA                            |\n");
            printf("    | ==> 3-VOLVER                                  |\n ");
            printf("   |                                               |\n ");
            printf("    ===============================================\n");

           if( utn_getNumeroInt(&option,"\n -INGRESE OPCION:  ","\n ERROR, INGRESE UNA OPCION VALIDA\n",1,3,2)==-1)
           {
                    break;
           }
                    switch(option)
                    {
                            case 1:
                                        system("cls");
                                        if (pet_deleteArray(arrayPets,sizePet)==-1)
                                        {
                                            printf("\n!! ERROR AL INTENTAR DAR DE BAJA A UNA  MASCOTA !!\n");
                                        }

                            break;
                            case 2:
                                        system("cls");

                                        if (breed_deleteArray(arrayBreeds,arrayPets,sizePet,sizeBreed)==-1)
                                        {
                                            printf("\n!! ERROR AL INTENTAR DAR DE BAJA A UNA  MASCOTA !!\n");
                                        }
                            break;

                    }
            }while(option!=3);
            system("cls");
    }
    return result;
}

