/**
 * @file app_ota_svc.c
 * @brief Application layer for FOTA service
 * @date 10/24/21
 * 
 */

/*user-block-includes-start -------------------------------------------------*/
#include "svc/ota_svc.h"

/*user-block-includes-end*/



/* Post Init -----------------------------------------------------------------*/

/**
 * @brief Called after GATT Server is intialized
 */
void ota_svc_post_init_handler(void)
{
    //TODO initialize characteristic values 
}

/* Characteristic Event Handlers----------------------------------------------*/

/**
 * @brief Handles GATT event on version Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t ota_version_handler(mrt_gatt_evt_t* event)
{

    //ota_version_t val = *((ota_version_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle version Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on newVerion Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t ota_newverion_handler(mrt_gatt_evt_t* event)
{

    //ota_newverion_t val = *((ota_newverion_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle newVerion Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on data Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t ota_data_handler(mrt_gatt_evt_t* event)
{

    //ota_data_t* vals = (ota_data_t*) event->data.value;  /* Cast to correct data type*/
    //uint32_t len = event.data.len/sizof(ota_data_t);   /* Get length of array*/


    //TODO Handle data Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on seq Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t ota_seq_handler(mrt_gatt_evt_t* event)
{

    //ota_seq_t val = *((ota_seq_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle seq Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on crc Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t ota_crc_handler(mrt_gatt_evt_t* event)
{

    //ota_crc_t val = *((ota_crc_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle crc Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on status Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t ota_status_handler(mrt_gatt_evt_t* event)
{

    //ota_status_t val = *((ota_status_t*) event->data.value); /* Cast to correct data type*/


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
