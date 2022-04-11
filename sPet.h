#ifndef SPET_H_INCLUDED
#define SPET_H_INCLUDED
#define FALSE 0
#define TRUE 1
#define SIZE_PET 10


typedef struct
{
    int  idPet;
	int  age;
	char name[20];
	char sex[20];
	char type[6];
    float  weight;

    int  idSizes;
	int isEmpty;
	int  idBreed;

}sPet;

int IsEmptyPet(sPet arrayPets[],int size);
int initializePet(sPet arrayPets[],int size);
int toShowPets(sPet arrayPets[],int  size);
int toShowPetsBySortWeight (sPet arrayPets[],int  size);

int  pet_IsEmpty(sPet* array,int size);
int pet_HighArray(sPet* array,int size,int* id);
int pet_highIdBreed(sPet* auxiliary,int type);

int  data_ModificacionArray(sPet* array,int size);
int  data_idSearch(sPet* array,int size);

int  sort_Ascending(sPet* array,int size);
int  sort_Descending(sPet* array,int size);

int  pet_deleteArray(sPet* array,int size);

#endif // SPET_H_INCLUDED
