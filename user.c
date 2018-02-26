/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "user.h"       /* Funciones/Parametros User, como InitApp */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
//char datoUser; //Ejemplo

/*==================[declaraciones de funciones internas]====================*/
//static void funcUser(void); //Ejemplo

/*==================[definiciones de funciones internas]=====================*/
//static void funcUser(void){ //Ejemplo

//}; 
/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Inicializa Ports, Periféricos e Interrupciones
 * @param	nada
 * @return	nada
 * @note
 */
void initApp(void) {
    /* TODO: Inicializa Ports/Periféricos/Interrupciones */

    /* Configura funciones analógicas y dirección de los Ports */
    ANSEL = 0;
    ANSELH = 0;
    TRIS_BOT1 = 1;
    TRIS_BOT2 = 1;
    TRIS_LED_V = 0;
    TRIS_LED_R = 0;
    uartConfig();
    __delay_ms(100); //Espera que se estabilice la fuente
    
    /* TODO: Habilita Interrupciones si es necesario*/
    //TMR2IE = 1;
    //PEIE = 1;
    //GIE = 1;  
}

/**
 * @brief	Configura e Inicializa la UART
 * @param	nada
 * @return	nada
 * @note
 */
void uartConfig(void) {
#if((SYS_FREQ - BAUDRATE*16L)/(BAUDRATE*16L)) > 255 //Si necesita High Baud Rate
#if	(SYS_FREQ - BAUDRATE*64L)/(BAUDRATE*64L) > 255
#error Baud Rate demasiado Bajo
#endif
    SPBRG = (SYS_FREQ - BAUDRATE * 64L) / (BAUDRATE * 64L); //SPBRG para Low Baud Rate
    BRGH = 0;   //Selecciona Low Baud Rate
#else
    SPBRG = (SYS_FREQ - BAUDRATE * 16L) / (BAUDRATE * 16L); //SPBRG para High Baud Rate
    BRGH = 1;   //Selecciona High Baud Rate
#endif
    SYNC = 0;   //Selecciona Modo Asincronico
    SPEN = 1;   //Habilita Serial Port
    TRISC7 = 1;
    TRISC6 = 1;
    CREN = 1;   //Habilita Continuous Reception
    TXEN = 1;   //Habilita Transmision
}

/**
 * @brief	Envia un byte en la salida stdout
 * @param	Byte o dato a transmitir
 * @return	nada
 * @note    Define la salida estandar para la librería stdio
 */
void putch(char data) {
    while (!TXIF)
        continue;
    TXREG = data;
}

/**
 * @brief	Toma un byte de la entrada stdin
 * @param	nada
 * @return	El byte recibido
 * @note    Define la entrada estandar para la librería stdio
 */
char getch(void) {
    while (!RCIF)
        continue;
    return RCREG;
}

/**
 * @brief	Toma un byte de la entrada stdin con eco
 * @param	nada
 * @return  El byte recibido
 * @note
 */
char getche(void) {
    char data;
    while (!RCIF)
        continue;
    data = RCREG;
    while (!TXIF)
        continue;
    TXREG = data;
    return data;
}

/*==================[fin del archivo]========================================*/
