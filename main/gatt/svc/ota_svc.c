/**
 * @file ota_svc.c
 * @brief sercive for performing over the air updates
 * @date 12/13/21
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "ota_svc.h"


/* Service Constant-----------------------------------------------------------*/
MRT_GATT_DATA_ATTR ota_svc_t ota_svc;

/* UUIDS----------------------------------------------------------------------*/
const uint8_t FOTA_SVC_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x49, 0x1b, 0xa8, 0x71};
const uint8_t VERSION_CHR_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4A, 0x1B, 0xa8, 0x71};
const uint8_t NEWVERION_CHR_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4B, 0x1B, 0xa8, 0x71};
const uint8_t DATA_CHR_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4C, 0x1B, 0xa8, 0x71};
const uint8_t SEQ_CHR_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4D, 0x1B, 0xa8, 0x71};
const uint8_t CRC_CHR_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4E, 0x1B, 0xa8, 0x71};
const uint8_t STATUS_CHR_UUID[] = {0x5b, 0x9a, 0x10, 0x9A, 0xed, 0xc8, 0x62, 0x6b, 0x88, 0x00, 0x39, 0xce, 0x4F, 0x1B, 0xa8, 0x71};


/* Initializer-----------------------------------------------------------------*/
ota_svc_t* ota_svc_init(mrt_gatt_pro_t* pro)
{   
    mrt_gatt_init_svc(&ota_svc.mSvc, MRT_UUID_LEN_128, FOTA_SVC_UUID, 6, NULL, "FOTA");
    mrt_gatt_init_char(&ota_svc.mSvc , &ota_svc.mVersion,MRT_UUID_LEN_128,  (uint8_t*)&VERSION_CHR_UUID, 16, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, ota_version_handler, "version");
    mrt_gatt_init_char(&ota_svc.mSvc , &ota_svc.mNewverion,MRT_UUID_LEN_128,  (uint8_t*)&NEWVERION_CHR_UUID, 16, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, ota_newverion_handler, "newVerion");
    mrt_gatt_init_char(&ota_svc.mSvc , &ota_svc.mData,MRT_UUID_LEN_128,  (uint8_t*)&DATA_CHR_UUID, 64, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, ota_data_handler, "data");
    mrt_gatt_init_char(&ota_svc.mSvc , &ota_svc.mSeq,MRT_UUID_LEN_128,  (uint8_t*)&SEQ_CHR_UUID, 4, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, ota_seq_handler, "seq");
    mrt_gatt_init_char(&ota_svc.mSvc , &ota_svc.mCrc,MRT_UUID_LEN_128,  (uint8_t*)&CRC_CHR_UUID, 4, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, ota_crc_handler, "crc");
    mrt_gatt_init_char(&ota_svc.mSvc , &ota_svc.mStatus,MRT_UUID_LEN_128,  (uint8_t*)&STATUS_CHR_UUID, 1, MRT_GATT_PROP_READ | MRT_GATT_PROP_WRITE, ota_status_handler, "status");

    if(pro != NULL)
    {   
        mrt_gatt_add_svc(pro,&ota_svc.mSvc);
    }

    return &ota_svc;
    
}


/* Getters and Setters--------------------------------------------------------*/

char* ota_get_version()
{
   if(!ota_version_cache_valid())
   {
       return NULL;
   }

   return  ((char*) ota_svc.mVersion.data.value);
}

char* ota_get_newverion()
{
   if(!ota_newverion_cache_valid())
   {
       return NULL;
   }

   return  ((char*) ota_svc.mNewverion.data.value);
}

uint8_t* ota_get_data()
{
   if(!ota_data_cache_valid())
   {
       return NULL;
   }

   return  ((uint8_t*) ota_svc.mData.data.value);
}

uint32_t ota_get_seq()
{
   if(!ota_seq_cache_valid())
   {
       return 0;
   }

   return  *((uint32_t*) ota_svc.mSeq.data.value);
}

uint32_t ota_get_crc()
{
   if(!ota_crc_cache_valid())
   {
       return 0;
   }

   return  *((uint32_t*) ota_svc.mCrc.data.value);
}

uint8_t ota_get_status()
{
   if(!ota_status_cache_valid())
   {
       return 0;
   }

   return  *((uint8_t*) ota_svc.mStatus.data.value);
}



/* Weak Characteristic Event Handlers-----------------------------------------*/
__attribute__((weak)) mrt_status_t ota_version_handler(mrt_gatt_evt_t* event)
{

    //ota_version_t val = *((ota_version_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle version Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t ota_newverion_handler(mrt_gatt_evt_t* event)
{

    //ota_newverion_t val = *((ota_newverion_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle newVerion Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t ota_data_handler(mrt_gatt_evt_t* event)
{

    //ota_data_t* vals = (ota_data_t*) event.data.value;  /* Cast to correct data type*/
    //uint32_t len = event.data.len/sizof(ota_data_t);   /* Get length of array*/


    //TODO Handle data Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t ota_seq_handler(mrt_gatt_evt_t* event)
{

    //ota_seq_t val = *((ota_seq_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle seq Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t ota_crc_handler(mrt_gatt_evt_t* event)
{

    //ota_crc_t val = *((ota_crc_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle crc Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t ota_status_handler(mrt_gatt_evt_t* event)
{

    //ota_status_t val = *((ota_status_t*) event.data.value); /* Cast to correct data type*/


    //switch(val)
    //{
    //    case OTA_STATUS_IDLE:                               /* no ota operation taking place */
    //        //TODO Handle IDLE
    //        break;
    //    case OTA_STATUS_DOWNLOAD:                           /* Currently downloading new firmware */
    //        //TODO Handle DOWNLOAD
    //        break;
    //    case OTA_STATUS_COMPLETE:                           /* Firmware download complete. ready to update */
    //        //TODO Handle COMPLETE
    //        break;
    //    default: 
    //        break;
    //}

    //TODO Handle status Characteristic events
    return MRT_STATUS_OK;
}
