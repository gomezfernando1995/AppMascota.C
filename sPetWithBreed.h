#ifndef SPETWITHBREED_H_INCLUDED
#define SPETWITHBREED_H_INCLUDED
#include "sPet.h"
#include "sBreed.h"
#include "sCountry.h"
#include  "toShowMenu.h"

#include "funciones.h"

int toShowPetsWithBreeds(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry);
int countryWithMostPet(sPet arrayPets[],sBreed arrayBreeds[],int sizePet,int sizeBreed);
int toShowBreedWithCountry(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry);
 int  sort_DescendingId(sPet* array,int size);
 int  sort_DescendingTelephone(sBreed arrayBreeds[], sCountry arrayCountrys[],int sizeBreed,int sizeCountry);

int  breed_deleteArray(sBreed arrayBreeds[],sPet arrayPets[], int sizePet,int sizeBreed);
int  data_idSearchBreed(sBreed* array,int size);

int typeAndWeight(sPet arrayPets[],int sizePet);
int accumulatorTypePets(sPet arrayPets[],int arrayCounterPets[],float arrayAccumulatorPets[],int sizePet);
int average(int arrayCounterPets[],float arrayAccumulatorPets[],float arrayAveragePets[]);
int toShowAverage(int arrayCounterPets[],float arrayAccumulatorPets[],float arrayAveragePets[]);

int accumulatorSize(sBreed arrayBreeds[],sPet arrayPets[], float* accumulator,int sizePet,int sizeBreed, int strSize);
int TotalWeightPets(sPet arrayPets[],int sizePet,int sizeBreeds,sBreed arrayBreeds[],float* accumulator,int option);
int searchBySize(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry);
int toShowSizeAndWeight(sPet arrayPets[],sBreed arrayBreeds[],sCountry arrayCountrys[],int sizePet,int sizeBreed,int sizeCountry,float accumulator,int option,char* strSize);



#endif // SPETWITHBREED_H_INCLUDED
