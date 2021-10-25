/**
 * @file app_bat_svc.c
 * @brief Application layer for Battery service
 * @date 10/24/21
 * 
 */

/*user-block-includes-start -------------------------------------------------*/
#include "svc/bat_svc.h"

/*user-block-includes-end*/


/* Post Init -----------------------------------------------------------------*/

/**
 * @brief Called after GATT Server is intialized
 */
void bat_svc_post_init_handler(void)
{
    //TODO initialize characteristic values 
}

/* Characteristic Event Handlers----------------------------------------------*/

/**
 * @brief Handles GATT event on Level Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t bat_level_handler(mrt_gatt_evt_t* event)
{

    //bat_level_t val = *((bat_level_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Level Characteristic events
    return MRT_STATUS_OK;
}
