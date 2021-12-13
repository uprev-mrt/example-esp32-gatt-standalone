/**
 * @file app_dvc_svc.c
 * @brief Application layer for Device service
 * @date 10/24/21
 * 
 */

/*user-block-includes-start -------------------------------------------------*/
#include "svc/dvc_svc.h"

/* Private Variables ---------------------------------------------------------*/   
    char* dvc_manufacturer_name_default = "Up-Rev";


/*user-block-includes-end*/



/* Post Init -----------------------------------------------------------------*/

/**
 * @brief Called after GATT Server is intialized
 */
void dvc_svc_post_init_handler(void)
{
    dvc_set_manufacturer_name(dvc_manufacturer_name_default);
    //TODO initialize characteristic values 
}

/* Characteristic Event Handlers----------------------------------------------*/

/**
 * @brief Handles GATT event on Manufacturer_Name Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t dvc_manufacturer_name_handler(mrt_gatt_evt_t* event)
{

    //dvc_manufacturer_name_t val = *((dvc_manufacturer_name_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Manufacturer_Name Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on Serial_Number Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t dvc_serial_number_handler(mrt_gatt_evt_t* event)
{

    //dvc_serial_number_t val = *((dvc_serial_number_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Serial_Number Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on Hardware_Revision Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t dvc_hardware_revision_handler(mrt_gatt_evt_t* event)
{

    //dvc_hardware_revision_t val = *((dvc_hardware_revision_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Hardware_Revision Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on Firmware_Revision Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t dvc_firmware_revision_handler(mrt_gatt_evt_t* event)
{

    //dvc_firmware_revision_t val = *((dvc_firmware_revision_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Firmware_Revision Characteristic events
    return MRT_STATUS_OK;
}
