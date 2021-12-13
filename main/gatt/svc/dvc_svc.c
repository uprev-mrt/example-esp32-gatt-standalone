/**
 * @file dvc_svc.c
 * @brief The Device Information Service exposes manufacturer and/or vendor information about a device.
 * @date 12/13/21
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "dvc_svc.h"


/* Service Constant-----------------------------------------------------------*/
MRT_GATT_DATA_ATTR dvc_svc_t dvc_svc;

/* UUIDS----------------------------------------------------------------------*/
const uint8_t DEVICE_SVC_UUID[] = {0x0A, 0x18};
const uint8_t MANUFACTURER_NAME_CHR_UUID[] = {0x29, 0x2A};
const uint8_t SERIAL_NUMBER_CHR_UUID[] = {0x25, 0x2A};
const uint8_t HARDWARE_REVISION_CHR_UUID[] = {0x27, 0x2A};
const uint8_t FIRMWARE_REVISION_CHR_UUID[] = {0x26, 0x2A};


/* Initializer-----------------------------------------------------------------*/
dvc_svc_t* dvc_svc_init(mrt_gatt_pro_t* pro)
{   
    mrt_gatt_init_svc(&dvc_svc.mSvc, MRT_UUID_LEN_16, DEVICE_SVC_UUID, 4, NULL, "Device");
    mrt_gatt_init_char(&dvc_svc.mSvc , &dvc_svc.mManufacturerName,MRT_UUID_LEN_16,  (uint8_t*)&MANUFACTURER_NAME_CHR_UUID, 16, MRT_GATT_PROP_READ, dvc_manufacturer_name_handler, "Manufacturer_Name");
    mrt_gatt_init_char(&dvc_svc.mSvc , &dvc_svc.mSerialNumber,MRT_UUID_LEN_16,  (uint8_t*)&SERIAL_NUMBER_CHR_UUID, 16, MRT_GATT_PROP_READ, dvc_serial_number_handler, "Serial_Number");
    mrt_gatt_init_char(&dvc_svc.mSvc , &dvc_svc.mHardwareRevision,MRT_UUID_LEN_16,  (uint8_t*)&HARDWARE_REVISION_CHR_UUID, 16, MRT_GATT_PROP_READ, dvc_hardware_revision_handler, "Hardware_Revision");
    mrt_gatt_init_char(&dvc_svc.mSvc , &dvc_svc.mFirmwareRevision,MRT_UUID_LEN_16,  (uint8_t*)&FIRMWARE_REVISION_CHR_UUID, 16, MRT_GATT_PROP_READ, dvc_firmware_revision_handler, "Firmware_Revision");

    if(pro != NULL)
    {   
        mrt_gatt_add_svc(pro,&dvc_svc.mSvc);
    }

    return &dvc_svc;
    
}


/* Getters and Setters--------------------------------------------------------*/

char* dvc_get_manufacturer_name()
{
   if(!dvc_manufacturer_name_cache_valid())
   {
       return NULL;
   }

   return  ((char*) dvc_svc.mManufacturerName.data.value);
}

char* dvc_get_serial_number()
{
   if(!dvc_serial_number_cache_valid())
   {
       return NULL;
   }

   return  ((char*) dvc_svc.mSerialNumber.data.value);
}

char* dvc_get_hardware_revision()
{
   if(!dvc_hardware_revision_cache_valid())
   {
       return NULL;
   }

   return  ((char*) dvc_svc.mHardwareRevision.data.value);
}

char* dvc_get_firmware_revision()
{
   if(!dvc_firmware_revision_cache_valid())
   {
       return NULL;
   }

   return  ((char*) dvc_svc.mFirmwareRevision.data.value);
}



/* Weak Characteristic Event Handlers-----------------------------------------*/
__attribute__((weak)) mrt_status_t dvc_manufacturer_name_handler(mrt_gatt_evt_t* event)
{

    //dvc_manufacturer_name_t val = *((dvc_manufacturer_name_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Manufacturer_Name Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t dvc_serial_number_handler(mrt_gatt_evt_t* event)
{

    //dvc_serial_number_t val = *((dvc_serial_number_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Serial_Number Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t dvc_hardware_revision_handler(mrt_gatt_evt_t* event)
{

    //dvc_hardware_revision_t val = *((dvc_hardware_revision_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Hardware_Revision Characteristic events
    return MRT_STATUS_OK;
}

__attribute__((weak)) mrt_status_t dvc_firmware_revision_handler(mrt_gatt_evt_t* event)
{

    //dvc_firmware_revision_t val = *((dvc_firmware_revision_t*) event.data.value); /* Cast to correct data type*/


    //TODO Handle Firmware_Revision Characteristic events
    return MRT_STATUS_OK;
}
