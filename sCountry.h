#ifndef SCOUNTRY_H_INCLUDED
#define SCOUNTRY_H_INCLUDED
#define SIZE_COUNTRY 6

typedef struct
{
    int idCountry;
    char nameCountry[20];
    char continent[20];
    int codeTelephone;

}sCountry;

int initializerCountry(sCountry arrayCountrys[], int size);


#endif // SCOUNTRY_H_INCLUDED
