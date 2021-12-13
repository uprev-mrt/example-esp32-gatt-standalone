/**
 * @file spr_svc.c
 * @brief Custom service for a sprinkler system
 * @date 12/13/21
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "spr_svc.h"


/* Service Constant-----------------------------------------------------------*/
MRT_GATT_DATA_ATTR spr_svc_t spr_svc;

/* UUIDS----------------------------------------------------------------------*/
const uint8_t SPRINKLER_SVC_UUID[] = {0x5b, 0x9a, 0x20, 0x9e, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x49, 0x1b, 0xa8, 0x71};
const uint8_t THRESH_CHR_UUID[] = {0x5b, 0x9a, 0x20, 0x9e, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4A, 0x1B, 0xa8, 0x71};
const uint8_t TEMPERATURE_CHR_UUID[] = {0x5b, 0x9a, 0x20, 0x9e, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4B, 0x1B, 0xa8, 0x71};
const uint8_t MOISTURE_CHR_UUID[] = {0x5b, 0x9a, 0x20, 0x9e, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4C, 0x1B, 0xa8, 0x71};
const uint8_t RELAYS_CHR_UUID[] = {0x5b, 0x9a, 0x20, 0x9e, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4D, 0x1B, 0xa8, 0x71};
const uint8_t SOILTYPE_CHR_UUID[] = {0x5b, 0x9a, 0x20, 0x9e, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4E, 0x1B, 0xa8, 0x71};


/* Initializer-----------------------------------------------------------------*/
spr_svc_t* spr_svc_init(mrt_gatt_pro_t* pro)
{   
    mrt_gatt_init_svc(&spr_svc.mSvc, MRT_UUID_LEN_128, SPRINKLER_SVC_UUID, 5, NULL, "Sprinkler");
    mrt_gatt_init_char(&spr_svc.mSvc , &spr_svc.mThresh,MRT_UUID_LEN_128,  (uint8_t*)&THRESH_CHR_UUID, 2, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, spr_thresh_handler, "Thresh");
    mrt_gatt_init_char(&spr_svc.mSvc , &spr_svc.mTemperature,MRT_UUID_LEN_128,  (uint8_t*)&TEMPERATURE_CHR_UUID, 2, MRT_GATT_PROP_READ | MRT_GATT_PROP_NOTIFY, spr_temperature_handler, "Temperature");
    mrt_gatt_init_char(&spr_svc.mSvc , &spr_svc.mMoisture,MRT_UUID_LEN_128,  (uint8_t*)&MOISTURE_CHR_UUID, 12, MRT_GATT_PROP_READ, spr_moisture_handler, "Moisture");
    mrt_gatt_init_char(&spr_svc.mSvc , &spr_svc.mRelays,MRT_UUID_LEN_128,  (uint8_t*)&RELAYS_CHR_UUID, 1, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE | MRT_GATT_PROP_NOTIFY, spr_relays_handler, "Relays");
    mrt_gatt_init_char(&spr_svc.mSvc , &spr_svc.mSoiltype,MRT_UUID_LEN_128,  (uint8_t*)&SOILTYPE_CHR_UUID, 1, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, spr_soiltype_handler, "SoilType");

    if(pro != NULL)
    {   
        mrt_gatt_add_svc(pro,&spr_svc.mSvc);
    }

    return &spr_svc;
    
}


/* Getters and Setters--------------------------------------------------------*/

uint16_t spr_get_thresh()
{
   if(!spr_thresh_cache_valid())
   {
       return 0;
   }

   return  *((uint16_t*) spr_svc.mThresh.data.value);
}

uint16_t spr_get_temperature()
{
   if(!spr_temperature_cache_valid())
   {
       return 0;
   }

   return  *((uint16_t*) spr_svc.mTemperature.data.value);
}

uint16_t* spr_get_moisture()
{
   if(!spr_moisture_cache_valid())
   {
       return NULL;
   }

   return  ((uint16_t*) spr_svc.mMoisture.data.value);
}

uint8_t spr_get_relays()
{
   if(!spr_relays_cache_valid())
   {
       return 0;
   }

   return  *((uint8_t*) spr_svc.mRelays.data.value);
}

uint8_t spr_get_soiltype()
{
   if(!spr_soiltype_cache_valid())
   {
       return 0;
   }

   return  *((uint8_t*) spr_svc.mSoiltype.data.value);
}



/* Weak Characteristic Event Handlers-----------------------------------------*/
__attribute__((weak)) mrt_status_t spr_thresh_handler(mrt_gatt_evt_t* event)
{

    //spr_thresh_t val = *((spr_thresh_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Thresh Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t spr_temperature_handler(mrt_gatt_evt_t* event)
{

    //spr_temperature_t val = *((spr_temperature_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Temperature Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t spr_moisture_handler(mrt_gatt_evt_t* event)
{

    //spr_moisture_t* vals = (spr_moisture_t*) event.data.value;  /* Cast to correct data type*/
    //uint32_t len = event.data.len/sizof(spr_moisture_t);   /* Get length of array*/


    //TODO Handle Moisture Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t spr_relays_handler(mrt_gatt_evt_t* event)
{

    //spr_relays_t val = *((spr_relays_t*) event.data.value); /* Cast to correct data type*/


    //if(val & SPR_RELAYS_PUMP)                               /* pump control */
    //{
    //  //TODO Handle pump 
    //}
    //if(val & SPR_RELAYS_VALVE01)                            /* valve 1 control */
    //{
    //  //TODO Handle valve01 
    //}
    //if(val & SPR_RELAYS_VALVE02)                            /* valve 2 control */
    //{
    //  //TODO Handle valve02 
    //}
    //if(val & SPR_RELAYS_VALVE03)                            /* valve 3 control */
    //{
    //  //TODO Handle valve03 
    //}
    //if(val & SPR_RELAYS_VALVE04)                            /* valve 4 control */
    //{
    //  //TODO Handle valve04 
    //}
    //if(val & SPR_RELAYS_VALVE05)                            /* valve 5 control */
    //{
    //  //TODO Handle valve05 
    //}
    //if(val & SPR_RELAYS_VALVE06)                            /* valve 6 control */
    //{
    //  //TODO Handle valve06 
    //}

    //TODO Handle Relays Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t spr_soiltype_handler(mrt_gatt_evt_t* event)
{

    //spr_soiltype_t val = *((spr_soiltype_t*) event.data.value); /* Cast to correct data type*/


    //switch(val)
    //{
    //    case SPR_SOILTYPE_PEAT:                             /* Peat soil */
    //        //TODO Handle Peat
    //        break;
    //    case SPR_SOILTYPE_SAND:                             /* Peat soil */
    //        //TODO Handle Sand
    //        break;
    //    case SPR_SOILTYPE_CLAY:                             /* Peat soil */
    //        //TODO Handle Clay
    //        break;
    //    case SPR_SOILTYPE_TOPSOIL:                          /* TopSoil */
    //        //TODO Handle TopSoil
    //        break;
    //    default: 
    //        break;
    //}

    //TODO Handle SoilType Characteristic events
    return MRT_STATUS_OK;
}
