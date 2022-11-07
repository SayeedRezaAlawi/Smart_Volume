/**
* \file Smart_Volume.c
* \author Sayeed Reza Alawi
* \date 
*
* \brief Sound driver
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "Smart_Volume.h"
#include "project.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static uint8_t m_volume=0;


/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/**
 * increasing the volume based on different events.
 * /return volume value.
 */
uint8_t MP3__increaseSmartVolume(EventMaskType nextEvent)
{
    static VOLUME__IncreamentState_t increament_volume_state= VOLUME__NormalIncreament;
    if((nextEvent & ev_3000ms))
    {
        SetRelAlarm(alrm_3000ms,3000,3000);
        if(increament_volume_state == VOLUME__NormalIncreament)
        {
            SetRelAlarm(alrm_500ms,500,500);
            increament_volume_state= VOLUME__FastIncreament; 
        }
        
        else if(increament_volume_state == VOLUME__FastIncreament)
        {
            SetRelAlarm(alrm_100ms,100,100);
            increament_volume_state= VOLUME__VeryFastIncreament; 
        }
        if (m_volume < MP3__MAXVOLUME) 
        {
        m_volume++;
        }
        else if (m_volume == MP3__MAXVOLUME)
        {
            increament_volume_state = VOLUME__NormalIncreament;  
        }        
    }
    else if((increament_volume_state == VOLUME__FastIncreament) && (nextEvent &  ev_500ms))
    {
        if (m_volume < MP3__MAXVOLUME)
        {
        m_volume++;
        }
        else if (m_volume == MP3__MAXVOLUME)
        {
            increament_volume_state = VOLUME__NormalIncreament;  
        }
    }
    else if((increament_volume_state == VOLUME__VeryFastIncreament) &&  (nextEvent & ev_100ms))
    {
        if (m_volume < MP3__MAXVOLUME)
        {
        m_volume++;
        }
        else if (m_volume == MP3__MAXVOLUME)
        {
            increament_volume_state = VOLUME__NormalIncreament;  
        }
    }
     else if(nextEvent &  ev_1000ms)
    {
        SetRelAlarm(alrm_1000ms,1000,1000);
        SetRelAlarm(alrm_3000ms,3000,0);
        if (m_volume < MP3__MAXVOLUME)
        {
        m_volume++;
        }
        else if (m_volume == MP3__MAXVOLUME)
        {
            increament_volume_state = VOLUME__NormalIncreament;  
        }
    }
    else if(nextEvent &  ev_Button1)
    {
        increament_volume_state = VOLUME__NormalIncreament;
        if (m_volume < MP3__MAXVOLUME)
        {
        m_volume++;
        CancelAlarm(alrm_1000ms);
        SetRelAlarm(alrm_1000ms,1000,0);
        }
        else if (m_volume == MP3__MAXVOLUME)
        {
            increament_volume_state = VOLUME__NormalIncreament;  
        }
    }
    return m_volume;
}

/**
 * decreasing the volume based on different events.
 * /return volume value
 */
uint8_t MP3__decreaseSmartVolume(EventMaskType nextEvent)
{
    static VOLUME__DecreamentState_t decreament_volume_state= VOLUME__NormalDecreament;
    if((nextEvent & ev_3000ms))
    {
        SetRelAlarm(alrm_3000ms,3000,3000);
        if(decreament_volume_state == VOLUME__NormalDecreament)
        {
            SetRelAlarm(alrm_500ms,500,500);
            decreament_volume_state= VOLUME__FastDecreament; 
        }
        
        else if(decreament_volume_state == VOLUME__FastDecreament)
        {
            SetRelAlarm(alrm_100ms,100,100);
            decreament_volume_state= VOLUME__VeryFastDecreament; 
        }
        if (m_volume > 0) 
        {
        m_volume--;
        }
        else if (m_volume == 0)
        {
            decreament_volume_state = VOLUME__NormalDecreament;  
        }        
    }
    else if((decreament_volume_state == VOLUME__FastDecreament) && (nextEvent &  ev_500ms))
    {
        if (m_volume > 0)
        {
        m_volume--;
        }
        else if (m_volume == 0)
        {
            decreament_volume_state = VOLUME__NormalDecreament; 
        }
    }
    else if((decreament_volume_state == VOLUME__VeryFastDecreament) &&  (nextEvent & ev_100ms))
    {
        if (m_volume > 0)
        {
        m_volume--;
        }
        else if (m_volume == 0)
        {
            decreament_volume_state = VOLUME__NormalDecreament; 
        }
    }
     else if(nextEvent &  ev_1000ms)
    {
        SetRelAlarm(alrm_1000ms,1000,1000);
        SetRelAlarm(alrm_3000ms,3000,0);
        if (m_volume > 0)
        {
        m_volume--;
        }
        else if (m_volume == 0)
        {
            decreament_volume_state = VOLUME__NormalDecreament; 
        }
    }
    else if(nextEvent &  ev_Button2)
    {
        decreament_volume_state = VOLUME__NormalDecreament;
        if (m_volume > 0)
        {
        m_volume--;
        CancelAlarm(alrm_1000ms);
        SetRelAlarm(alrm_1000ms,1000,0);
        }
        else if (m_volume == 0)
        {
            decreament_volume_state = VOLUME__NormalDecreament; 
        }
    }
    return m_volume;
}