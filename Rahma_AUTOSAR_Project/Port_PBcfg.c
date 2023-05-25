 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build configuration source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Rahma abdelkader 
 ******************************************************************************/

/* AUTOSAR Port header file */
#include "Port.h"

/*******************************************************************************
 *                                Version Definitions                          *
 *******************************************************************************/
/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Software Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION           (1U)
#define PORT_PBCFG_SW_MINOR_VERSION           (0U)
#define PORT_PBCFG_SW_PATCH_VERSION           (0U)



/* Checking AUTOSAR Release compitability between Port.h and Port_Cfg.h */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
      #error "The AR version of Port.h does not match the expected version"
#endif

/* Checking Software compitability between Port.h and Port_Cfg.h */
#if ((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION)\
 ||  (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION)\
 ||  (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION))
      #error "The AR version of Port.h does not match the expected version"
#endif

/* Post Build  structure used with Port_Init API */
/*config 6 ports 0-5
 * config there 8 pins 0-7
 *
 *
 * Struct contains
 *      1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. pin mode 
        5. initial value
        6. Internal pull-up/down resistor control                
        7. Pin direction changeable
        8. Pin mode changeable
 */
/* PB structure used with Port_Init API */  
const Port_ConfigType Port_Configuration = {
   PORT_A , PIN_0 , PORT_PIN_IN     , PORT_PA0_U0Rx   , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_1 , PORT_PIN_OUTPUT , PORT_PA1_U0Tx   , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_2 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_3 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_4 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_5 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_6 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_A , PIN_7 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   
   PORT_B , PIN_0 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_1 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_2 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_3 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_4 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_5 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_6 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_B , PIN_7 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
  
   PORT_C , PIN_0 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_1 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_2 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_3 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_4 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_5 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_6 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_C , PIN_7 , PORT_PIN_IN     , PORT_PC7_WT1CCP1 , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   
   PORT_D , PIN_0 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_1 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_2 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_3 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_4 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_5 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_6 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_D , PIN_7 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
  
   PORT_E , PIN_0 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_E , PIN_1 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_E , PIN_2 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_E , PIN_3 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_E , PIN_4 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_E , PIN_5 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
 
   PORT_F , PIN_0 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_F , PIN_1 , PORT_PIN_OUTPUT , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_F , PIN_2 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_F , PIN_3 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF ,
   PORT_F , PIN_4 , PORT_PIN_IN     , PORT_DIGITAL_IO , STD_HIGH , OFF , STD_OFF , STD_OFF 
};
   


