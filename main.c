/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* For uint8_t definition */
#include "system.h"     /* Funciones/Parametros System, como osc/peripheral config */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include <stdio.h>      /* Archivo de Encabezados StdIO */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main(void) {
    /* TODO: Agregue el Cod1iogo de la Aplicaci�n aqu� */
    uint8_t comando;
    initApp();          /* Inicializa I/O y Perif�ricos de la aplicaci�n */

    PIN_LED_V = 1; //Prende led
    PIN_LED_R = 1; //Prende led
    __delay_ms(200);
    PIN_LED_V = 0; //Apaga led
    PIN_LED_R = 0; //apaga led    
    while (1) {
        comando = getch();
        switch (comando) {
            case 'v':
                PIN_LED_V = 1; //Prende led
                break;
            case 'b':
                PIN_LED_V = 0; //apaga led
                break;
            case 'r':
                PIN_LED_R = 1; //Prende led
                break;
            case 't':
                PIN_LED_R = 0; //apaga led
                break;
        }
    }
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
