/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
#ifndef USER_H
#define USER_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aqui */
#define	TRIS_BOT1       TRISBbits.TRISB0
#define	PIN_BOT1        PORTBbits.RB0

#define	TRIS_BOT2       TRISCbits.TRISC0
#define	PIN_BOT2        PORTCbits.RC0

#define	TRIS_LED_V      TRISBbits.TRISB1
#define	PIN_LED_V       PORTBbits.RB1

#define	TRIS_LED_R      TRISBbits.TRISB2
#define	PIN_LED_R       PORTBbits.RB2

#define	TRIS_PICTX      TRISCbits.TRISC6
#define	PIN_PICTX       PORTCbits.RC6

#define	TRIS_PICRX      TRISCbits.TRISC7
#define	PIN_PICRX       PORTCbits.RC7

#define	BAUDRATE        9600

/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aqui */
void initApp(void);     /* Inicialización de I/O y eripheral Initialization */

void uartConfig(void);   /* Inicialización de UART */
void putch(char data);  /* pone un byte e stdout */
char getch(void);       /* toma un byte e stdin  */
char getche(void);      /* toma un byte e stdin con eco */

/*==================[fin del archivo]========================================*/
#endif// USER_H
