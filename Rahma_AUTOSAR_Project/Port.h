
   /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H
   
/* Non-AUTOSAR Files */
#include "Common_Macros.h"
#include "Port_registers.h"
/*******************************************************************************
 *                       Version Definitions and IDs                           *
 *******************************************************************************/
#define PORT_VENDOR_ID                  (1000)

#define PORT_MODULE_ID                  (120U)

#define PORT_INSTANCE_ID                (0U)

/*
 * AUTOSAR Version 4.0.2
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Software Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
/* AUTOSAR Standard Types */
#include "Std_Types.h"

/* Checking files compitability between Port.h and Std_Types.h */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
      #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Port pre-compile configuration file */
#include "Port_Cfg.h"
   
/* Checking AUTOSAR Release compitability between Port.h and Port_Cfg.h */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
      #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Checking Software compitability between Port.h and Port_Cfg.h */
#if ((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION)\
 ||  (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION)\
 ||  (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION))
      #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/*******************************************************************************
 *                                  Port Status                                *
 *******************************************************************************/
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)
   
/*******************************************************************************
 *                                DET Error Codes                              *
 *******************************************************************************/
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                (uint8)0x0A
   
/* Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B
   
/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG             (uint8)0x0C
   
/* API Port_SetPinMode service called when mode is invalid*/
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
   
/* API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E
   
/* API service called without module initialization */   
#define PORT_E_UNINIT                   (uint8)0x0F
   
/* APIs called with a Null Pointer */
#define PORT_E_POINTER                  (uint8)0x10
   
/*******************************************************************************
 *                                API Services ID                              *
 *******************************************************************************/
/* Service ID for Port init */
#define PORT_INIT_SID                   (uint8)0x00
   
/* Service ID for Port set pin direction */
#define PORT_SET_PIN_DIRECTION_SID      (uint8)0x01
   
/* Service ID for Port refresh pin direction */
#define PORT_REFRESH_PORT_DIRECTION     (uint8)0x02
   
/* Service ID for Port get version info */
#define PORT_GET_VERSION_INFO_SID       (uint8)0x03
   
/* Service ID for Port set pin mode */
#define PORT_SET_PIN_MODE_SID           (uint8)0x04

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 /*Type definition for port_pinType used by the port APIs*/
typedef uint8 Port_PinType;
 /*Type definition for port_portType used by the port APIs*/
typedef uint8 Port_PortType;
 /*Type definition for port_PinModeType used by the port APIs*/
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN ,PORT_PIN_OUTPUT
}Port_PinDirection;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. pin mode 
        5. initial value
        6. Internal pull-up/down resistor control                
        7. Pin direction changeable
        8. Pin mode changeable
 */
typedef struct 
{
    Port_PortType port_num; 
    Port_PinType pin_num; 
    Port_PinDirection direction;
    Port_PinModeType pin_mode; 
    uint8 initial_value;
    Port_InternalResistor pin_internalResistor;
    boolean pin_directionChangeable;
    boolean pin_modeChangeable;
}Port_ConfigPin;

/*******************************************************************************
* Name: Port_ConfigType
* Type: Structure
* Range: Hardware dependent structure
* Description: Type for data used to initialize the port module  
********************************************************************************/
typedef struct
{
  Port_ConfigPin Pins[PORT_PINS_NUM];
}Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_SetupGpioPin
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
void Port_SetupGpioPin(const Port_ConfigType *ConfigPtr );

/*******************************************************************************
 *                             Function Prototypes                             *
 *******************************************************************************/

/*******************************************************************************
* Service Name: Port_Init
* Service ID: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the Port Driver module
********************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

#if (STD_ON == PORT_SET_DIRECTION_API)
/*******************************************************************************
* Service Name: Port_SetPinDirection
* Service ID: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin       - Port Pin ID number
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
********************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirection Direction);
#endif

/*******************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction
********************************************************************************/
void Port_RefreshPortDirection(void);

/*******************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version info
* Return value: None
* Description: Returns the version information of this module
********************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

#if (STD_ON == PORT_SET_MODE_API)
/*******************************************************************************
* Service Name: Port_SetPinMode
* Service ID: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin  - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode
********************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

 

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
