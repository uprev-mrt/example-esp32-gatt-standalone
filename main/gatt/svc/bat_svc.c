/**
 * @file bat_svc.c
 * @brief The Battery Service exposes the state of a battery within a device.
 * @date 12/13/21
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "bat_svc.h"


/* Service Constant-----------------------------------------------------------*/
MRT_GATT_DATA_ATTR bat_svc_t bat_svc;

/* UUIDS----------------------------------------------------------------------*/
const uint8_t BATTERY_SVC_UUID[] = {0x0F, 0x18};
const uint8_t LEVEL_CHR_UUID[] = {0x19, 0x2A};


/* Initializer-----------------------------------------------------------------*/
bat_svc_t* bat_svc_init(mrt_gatt_pro_t* pro)
{   
    mrt_gatt_init_svc(&bat_svc.mSvc, MRT_UUID_LEN_16, BATTERY_SVC_UUID, 1, NULL, "Battery");
    mrt_gatt_init_char(&bat_svc.mSvc , &bat_svc.mLevel,MRT_UUID_LEN_16,  (uint8_t*)&LEVEL_CHR_UUID, 1, MRT_GATT_PROP_READ | MRT_GATT_PROP_NOTIFY | MRT_GATT_PROP_INDICATE, bat_level_handler, "Level");

    if(pro != NULL)
    {   
        mrt_gatt_add_svc(pro,&bat_svc.mSvc);
    }

    return &bat_svc;
    
}


/* Getters and Setters--------------------------------------------------------*/

uint8_t bat_get_level()
{
   if(!bat_level_cache_valid())
   {
       return 0;
   }

   return  *((uint8_t*) bat_svc.mLevel.data.value);
}



/* Weak Characteristic Event Handlers-----------------------------------------*/
__attribute__((weak)) mrt_status_t bat_level_handler(mrt_gatt_evt_t* event)
{

    //bat_level_t val = *((bat_level_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Level Characteristic events
    return MRT_STATUS_OK;
}
