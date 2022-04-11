
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

static int getInt(int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);

static int getText(char pResultado[]);
static int myGetsChar(char cadena[], int longitud);
static int esSoloLetras(char cadena[]);

static int esFloat(char* cadena);
static int getFloat(float* pResultado);




///////////////////////////****     FUNCION DE NUMERO ENTEROS ****////////////////////////////////////////

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje !=NULL	 && mensajeError !=NULL && minimo<= maximo && reintentos >0)
	{
		do{
			printf("%s",mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo )
			{
		            *pResultado = bufferInt;
			     retorno = 0;
			     break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos >=0);
		if(reintentos == 0)
        {
                retorno = -1;
        }

	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado)
{
int retorno=-1;
char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
return retorno;
}


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets(char* cadena, int longitud)
{
    int retorno = -1;

    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
            fflush(stdin);
            if(cadena[strlen(cadena)-1] == '\n')
            {
                cadena[strlen(cadena)-1] = '\0';
            }
        retorno=0;
    }
return retorno;
}


/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
static int esNumerica(char* cadena)
{
int retorno = 1;
int i=0;

	if(cadena[0]== '-')
	{
		i= 1;
	}
	for( ; cadena[i] != '\0';i++)
	{
		if(cadena[i] > '9' || cadena[i]<'0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
///////////////////////////////////////**********************************************//////////////////////////////////////////////////////////////////////
//////////////////////____________________________________________FUNCION  ALFABETICA_____________________________________________________/////////////////////////////////

/**
 * \brief Solicita una cadena de caracteres al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado es un array que le indica donde debe alojar el resultado.
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getTexto(char pResultado[], char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[128];

	if(pResultado != NULL && mensaje !=NULL	&& mensajeError !=NULL && reintentos >0)
	{
		do{
			printf("%s",mensaje);
			if(getText(bufferChar) == 0 )
			{
			     for (int i=0; bufferChar[i]!= '\0'; i++)
                 {
                    bufferChar[i] = tolower(bufferChar[i]);
                 }
                bufferChar[0] = toupper(bufferChar[0]);


			     strcpy(pResultado,bufferChar);
			     retorno = 0;
		     break;
			}
			reintentos--;
            printf("%s",mensajeError);
		}while(reintentos >=0);
		if(reintentos == 0)
		{
                retorno = -1;
		}
 	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada sea de caracteres
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getText(char pResultado[])
{
int retorno=-1;
char buffer[128];
    if(pResultado != NULL)
    {
        if(myGetsChar(buffer,sizeof(buffer))==0 && esSoloLetras(buffer)==0)
        {
            strcpy(pResultado,buffer);
            retorno = 0;
        }
    }
return retorno;
}


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGetsChar(char cadena[], int longitud)
{
    int retorno = -1;

    fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
            if(cadena[strlen(cadena)-1] == '\n')
            {
                cadena[strlen(cadena)-1] = '\0';
            }
        retorno=0;
    }
return retorno;
}

/**
* \brief Verifica si la cadena ingresada es de caracteres
* \param *cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
static int esSoloLetras(char cadena[])
{
	//si 0 para verdadero y -1 para falso

	int i=0;
    int	retorno = 0;
	while(cadena[i] != '\0')
	{
		if((cadena[i] != ' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]< 'A' || cadena[i]> 'Z'))
		{
			retorno = -1;
		}
	   i++;
	}
	return retorno;
}

/////////////////////________________________________________________________________________________________________________________________//////////////////////////////////

//---------------------------------------------- FUNCION DECIMALES ----------------------------------------------------
/**
 * \brief Solicita un numero decimal al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje !=NULL	 && mensajeError !=NULL && minimo<= maximo && reintentos >0)
	{
		do{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
		            *pResultado = bufferFloat;
			     retorno = 0;
			     break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos >=0);
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getFloat(float* pResultado)
{
int retorno=-1;
char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esFloat(buffer)==1)
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
return retorno;
}

/**
* \brief Verifica si la cadena ingresada es numerica con decimales
* \param *cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
static int esFloat(char* cadena)
{
int retorno = 1;
int i=0;
int contadorPuntos=0;

	for( ; cadena[i] != '\0';i++){

	    if(cadena[i] > '9' || cadena[i]<'0')
	    {
            if(cadena[i]=='.')
            {
                contadorPuntos++;
                if(contadorPuntos>1)
				{
					retorno = 0;
					break;
				}
            }
            else
            {
                if(i==0)
                {
                    if(cadena[i]!='+' && cadena[i]!='-')
                    {
                        retorno = 0;
                    }
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
	    }
	}
	return retorno;
}


