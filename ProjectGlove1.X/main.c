/******************************************************************************/
/** File Name:            ProjectGlove1
 *                                  Main File
*
* Description:          This file contains all the for loops in which the program inspects the current state of the 
 *                           flex sensors in comparison to their previous state i.e. checking to see if the finger has 
 *                           moved.
 *                           It configures the PIC to use the corresponding analog channel and completes an analog-
 *                           to-digital conversion.
 *                           A character is then outputted depending on the intensity of the bend of the flex sensor.
 *                           
* Programmer:       Emma Murphy
*
* Date:                 24/02/2021
*
* Version:              1.0*/
/******************************************************************************/                                                     

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdio.h>

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
#define finger1_current RB0
#define finger2_current RB1
#define finger3_current RB2
#define finger4_current RB3
#define finger5_current RB4

#define _XTAL_FREQ 8000000 
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

unsigned char finger1_prev;
unsigned char finger2_prev;
unsigned char finger3_prev;
unsigned char finger4_prev;
unsigned char finger5_prev;

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
    
    finger1_prev = 1;
    finger2_prev = 1;
    finger3_prev = 1;
    finger4_prev = 1;
    finger5_prev = 1; 
                
   while(1)
   {         
       /*Checking to see if the state of the flex sensor on the thumb has changed.
        * If it has, the PIC is configured to change to analog channel 12.
        * An Analog-to-digitial conversion takes place.
        * A certain character is sent to the HC06 bluetooth module on the Arduino depending on the range of 
        * values after the ADC. */
        if (finger1_current != finger1_prev){
                CHS3 = 1;
                CHS2 = 1;
                CHS1 = 0;
                CHS0 = 0;
                GO = 1;                         //Start an A/D conversion cycle 
                while(GO == 1){             //Wait until the A/D conversion is completed
                }
                if ((ADRESH <= 30) && (ADRESH >=0)){     //closed fist -> completely bent
                    while(TXIF == 0){
                        }
                    TXREG = 'a';
                }
                else if ((ADRESH <= 60) && (ADRESH >=31)){     //slightly open  -> big bend
                     while(TXIF == 0){
                     }
                     TXREG = 'b';
                 }
                else if ((ADRESH <= 90) && (ADRESH >=61)){     //almost fully open  -> slight bend
                     while(TXIF == 0){
                     }
                     TXREG = 'c';
                 }
                else if ((ADRESH <= 120) && (ADRESH >=91)){     //completely open  -> no bend
                     while(TXIF == 0){
                     }
                     TXREG = 'd';
                 }
                 
                __delay_ms(400);
        }
        /*Checking to see if the state of the flex sensor on the index finger has changed.
        * If it has, the PIC is configured to change to analog channel 10.
        * An Analog-to-digital conversion takes place.
        * A certain character is sent to the HC06 Bluetooth module on the Arduino depending on the range of 
        * values after the ADC. */
        if(finger2_current != finger2_prev){
                CHS3 = 1;
                CHS2 = 0;
                CHS1 = 1;
                CHS0 = 0;
                GO = 1;                         //Start an A/D conversion cycle 
                while(GO == 1){             //Wait until the A/D conversion is completed
                }
                if ((ADRESH <= 30) && (ADRESH >=0)){     //closed fist -> completely bent
                    while(TXIF == 0){
                        }
                    TXREG = 'e';
                }
                else if ((ADRESH <= 60) && (ADRESH >=31)){     //slightly open  -> big bend
                     while(TXIF == 0){
                     }
                     TXREG = 'f';
                 }
                else if ((ADRESH <= 90) && (ADRESH >=61)){     //almost fully open  -> slight bend
                     while(TXIF == 0){
                     }
                     TXREG = 'g';
                 }
                else if ((ADRESH <= 120) && (ADRESH >=91)){     //completely open  -> no bend
                     while(TXIF == 0){
                     }
                     TXREG = 'h';
                 }
                 
                __delay_ms(400);
        }
       /*Checking to see if the state of the flex sensor on the middle finger has changed.
        * If it has, the PIC is configured to change to analog channel 8.
        * An Analog-to-digital conversion takes place.
        * A certain character is sent to the HC06 bluetooth module on the Arduino depending on the range of 
        * values after the ADC. */
        
        if(finger3_current != finger3_prev){
                CHS3 = 1;
                CHS2 = 0;
                CHS1 = 0;
                CHS0 = 0;
                GO = 1;                         //Start an A/D conversion cycle 
                while(GO == 1){             //Wait until the A/D conversion is completed
                }
                if ((ADRESH <= 30) && (ADRESH >=0)){     //closed fist -> completely bent
                    while(TXIF == 0){
                        }
                    TXREG = 'i';
                }
                else if ((ADRESH <= 60) && (ADRESH >=31)){     //slightly open  -> big bend
                     while(TXIF == 0){
                     }
                     TXREG = 'j';
                 }
                else if ((ADRESH <= 90) && (ADRESH >=61)){     //almost fully open  -> slight bend
                     while(TXIF == 0){
                     }
                     TXREG = 'k';
                 }
                else if ((ADRESH <= 120) && (ADRESH >=91)){     //completely open  -> no bend
                     while(TXIF == 0){
                     }
                     TXREG = 'l';
                 }
                 
                __delay_ms(400);
        }

       /*Checking to see if the state of the flex sensor on the ring finger has changed.
        * If it has, the PIC is configured to change to analog channel 9.
        * An Analog-to-digital conversion takes place.
        * A certain character is sent to the HC06 bluetooth module on the Arduino depending on the range of 
        * values after the ADC. */
        
        if(finger4_current != finger4_prev){
                CHS3 = 1;
                CHS2 = 0;
                CHS1 = 0;
                CHS0 = 1;
                GO = 1;                         //Start an A/D conversion cycle 
                while(GO == 1){             //Wait until the A/D conversion is completed
                }                
                if ((ADRESH <= 30) && (ADRESH >=0)){     //closed fist -> completely bent
                    while(TXIF == 0){
                        }
                    TXREG = 'm';
                }
                else if ((ADRESH <= 60) && (ADRESH >= 31)){     //slightly open  -> big bend
                     while(TXIF == 0){
                     }
                     TXREG = 'n';
                 }
                else if ((ADRESH <= 90) && (ADRESH >=61)){     //almost fully open  -> slight bend
                     while(TXIF == 0){
                     }
                     TXREG = 'o';
                 }
                else if ((ADRESH <= 120) && (ADRESH >=91)){     //completely open  -> no bend
                     while(TXIF == 0){
                     }
                     TXREG = 'p';
                 }
                 
                __delay_ms(400);
        }
           
       /*Checking to see if the state of the flex sensor on the pinky finger has changed.
        * If it has, the PIC is configured to change to analog channel 11.
        * An Analog-to-digital conversion takes place.
        * A certain character is sent to the HC06 bluetooth module on the Arduino depending on the range of 
        * values after the ADC. */
        
        if(finger5_current != finger5_prev){
                CHS3 = 1;
                CHS2 = 0;
                CHS1 = 1;
                CHS0 = 1;
                GO = 1;                         //Start an A/D conversion cycle 
                while(GO == 1){             //Wait until the A/D conversion is completed
                }                
                if ((ADRESH <= 30) && (ADRESH >=0)){     //closed fist -> completely bent
                    while(TXIF == 0){
                        }
                    TXREG = 'q';
                }
                else if ((ADRESH <= 60) && (ADRESH >=31)){     //slightly open  -> big bend
                     while(TXIF == 0){
                     }
                     TXREG = 'r';
                 }
                else if ((ADRESH <= 90) && (ADRESH >=61)){     //almost fully open  -> slight bend
                     while(TXIF == 0){
                     }
                     TXREG = 's';
                 }
                else if ((ADRESH <= 120) && (ADRESH >=91)){     //completely open  -> no bend
                     while(TXIF == 0){
                     }
                     TXREG = 't';
                 }
                __delay_ms(400);
        }
        }
}