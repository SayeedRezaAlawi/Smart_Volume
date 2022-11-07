/*******************************************************************************
* File Name: SOUND_ENABLE.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SOUND_ENABLE_H) /* Pins SOUND_ENABLE_H */
#define CY_PINS_SOUND_ENABLE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SOUND_ENABLE_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SOUND_ENABLE__PORT == 15 && ((SOUND_ENABLE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SOUND_ENABLE_Write(uint8 value);
void    SOUND_ENABLE_SetDriveMode(uint8 mode);
uint8   SOUND_ENABLE_ReadDataReg(void);
uint8   SOUND_ENABLE_Read(void);
void    SOUND_ENABLE_SetInterruptMode(uint16 position, uint16 mode);
uint8   SOUND_ENABLE_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SOUND_ENABLE_SetDriveMode() function.
     *  @{
     */
        #define SOUND_ENABLE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SOUND_ENABLE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SOUND_ENABLE_DM_RES_UP          PIN_DM_RES_UP
        #define SOUND_ENABLE_DM_RES_DWN         PIN_DM_RES_DWN
        #define SOUND_ENABLE_DM_OD_LO           PIN_DM_OD_LO
        #define SOUND_ENABLE_DM_OD_HI           PIN_DM_OD_HI
        #define SOUND_ENABLE_DM_STRONG          PIN_DM_STRONG
        #define SOUND_ENABLE_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SOUND_ENABLE_MASK               SOUND_ENABLE__MASK
#define SOUND_ENABLE_SHIFT              SOUND_ENABLE__SHIFT
#define SOUND_ENABLE_WIDTH              1u

/* Interrupt constants */
#if defined(SOUND_ENABLE__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SOUND_ENABLE_SetInterruptMode() function.
     *  @{
     */
        #define SOUND_ENABLE_INTR_NONE      (uint16)(0x0000u)
        #define SOUND_ENABLE_INTR_RISING    (uint16)(0x0001u)
        #define SOUND_ENABLE_INTR_FALLING   (uint16)(0x0002u)
        #define SOUND_ENABLE_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SOUND_ENABLE_INTR_MASK      (0x01u) 
#endif /* (SOUND_ENABLE__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SOUND_ENABLE_PS                     (* (reg8 *) SOUND_ENABLE__PS)
/* Data Register */
#define SOUND_ENABLE_DR                     (* (reg8 *) SOUND_ENABLE__DR)
/* Port Number */
#define SOUND_ENABLE_PRT_NUM                (* (reg8 *) SOUND_ENABLE__PRT) 
/* Connect to Analog Globals */                                                  
#define SOUND_ENABLE_AG                     (* (reg8 *) SOUND_ENABLE__AG)                       
/* Analog MUX bux enable */
#define SOUND_ENABLE_AMUX                   (* (reg8 *) SOUND_ENABLE__AMUX) 
/* Bidirectional Enable */                                                        
#define SOUND_ENABLE_BIE                    (* (reg8 *) SOUND_ENABLE__BIE)
/* Bit-mask for Aliased Register Access */
#define SOUND_ENABLE_BIT_MASK               (* (reg8 *) SOUND_ENABLE__BIT_MASK)
/* Bypass Enable */
#define SOUND_ENABLE_BYP                    (* (reg8 *) SOUND_ENABLE__BYP)
/* Port wide control signals */                                                   
#define SOUND_ENABLE_CTL                    (* (reg8 *) SOUND_ENABLE__CTL)
/* Drive Modes */
#define SOUND_ENABLE_DM0                    (* (reg8 *) SOUND_ENABLE__DM0) 
#define SOUND_ENABLE_DM1                    (* (reg8 *) SOUND_ENABLE__DM1)
#define SOUND_ENABLE_DM2                    (* (reg8 *) SOUND_ENABLE__DM2) 
/* Input Buffer Disable Override */
#define SOUND_ENABLE_INP_DIS                (* (reg8 *) SOUND_ENABLE__INP_DIS)
/* LCD Common or Segment Drive */
#define SOUND_ENABLE_LCD_COM_SEG            (* (reg8 *) SOUND_ENABLE__LCD_COM_SEG)
/* Enable Segment LCD */
#define SOUND_ENABLE_LCD_EN                 (* (reg8 *) SOUND_ENABLE__LCD_EN)
/* Slew Rate Control */
#define SOUND_ENABLE_SLW                    (* (reg8 *) SOUND_ENABLE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SOUND_ENABLE_PRTDSI__CAPS_SEL       (* (reg8 *) SOUND_ENABLE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SOUND_ENABLE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SOUND_ENABLE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SOUND_ENABLE_PRTDSI__OE_SEL0        (* (reg8 *) SOUND_ENABLE__PRTDSI__OE_SEL0) 
#define SOUND_ENABLE_PRTDSI__OE_SEL1        (* (reg8 *) SOUND_ENABLE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SOUND_ENABLE_PRTDSI__OUT_SEL0       (* (reg8 *) SOUND_ENABLE__PRTDSI__OUT_SEL0) 
#define SOUND_ENABLE_PRTDSI__OUT_SEL1       (* (reg8 *) SOUND_ENABLE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SOUND_ENABLE_PRTDSI__SYNC_OUT       (* (reg8 *) SOUND_ENABLE__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SOUND_ENABLE__SIO_CFG)
    #define SOUND_ENABLE_SIO_HYST_EN        (* (reg8 *) SOUND_ENABLE__SIO_HYST_EN)
    #define SOUND_ENABLE_SIO_REG_HIFREQ     (* (reg8 *) SOUND_ENABLE__SIO_REG_HIFREQ)
    #define SOUND_ENABLE_SIO_CFG            (* (reg8 *) SOUND_ENABLE__SIO_CFG)
    #define SOUND_ENABLE_SIO_DIFF           (* (reg8 *) SOUND_ENABLE__SIO_DIFF)
#endif /* (SOUND_ENABLE__SIO_CFG) */

/* Interrupt Registers */
#if defined(SOUND_ENABLE__INTSTAT)
    #define SOUND_ENABLE_INTSTAT            (* (reg8 *) SOUND_ENABLE__INTSTAT)
    #define SOUND_ENABLE_SNAP               (* (reg8 *) SOUND_ENABLE__SNAP)
    
	#define SOUND_ENABLE_0_INTTYPE_REG 		(* (reg8 *) SOUND_ENABLE__0__INTTYPE)
#endif /* (SOUND_ENABLE__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SOUND_ENABLE_H */


/* [] END OF FILE */
