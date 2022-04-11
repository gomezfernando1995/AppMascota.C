#ifndef SRACE_H_INCLUDED
#define SRACE_H_INCLUDED
#define FALSE 0
#define TRUE 1
#define SIZE_BREED 10


typedef struct
{
    int   idBreed;
    int   idCountry;
    char  description[20];
    char  sizes[20];
    int    idSizes;
    int     isEmpty;

}sBreed;

int breedIsEmpty(sBreed arrayBreeds[],int size);
int initializerBreed(sBreed arrayBreeds[], int size);
int toShowBreeds(sBreed arrayBreeds[],int  size);

int  breed_IsEmpty(sBreed* array,int size);
int  breed_High(sBreed* array,int size,int* id);


#endif // SRACE_H_INCLUDED
