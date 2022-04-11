#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getTexto(char pResultado[], char* mensaje, char* mensajeError, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif // UTN_H_INCLUDED
