/**
 * @file app_spr_svc.c
 * @brief Application layer for Sprinkler service
 * @date 10/24/21
 * 
 */

/*user-block-includes-start -------------------------------------------------*/
#include "svc/spr_svc.h"
#include "driver/gpio.h"

#define GPIO_LED 2

/*user-block-includes-end*/


/* Post Init -----------------------------------------------------------------*/

/**
 * @brief Called after GATT Server is intialized
 */
void spr_svc_post_init_handler(void)
{
    //Configure LED pin
    gpio_reset_pin(GPIO_LED);
    gpio_set_direction(GPIO_LED, GPIO_MODE_OUTPUT);
}

/* Characteristic Event Handlers----------------------------------------------*/

/**
 * @brief Handles GATT event on Thresh Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t spr_thresh_handler(mrt_gatt_evt_t* event)
{

    //spr_thresh_t val = *((spr_thresh_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Thresh Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on Temperature Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t spr_temperature_handler(mrt_gatt_evt_t* event)
{

    //spr_temperature_t val = *((spr_temperature_t*) event->data.value); /* Cast to correct data type*/


    //TODO Handle Temperature Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on Moisture Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t spr_moisture_handler(mrt_gatt_evt_t* event)
{

    //spr_moisture_t* vals = (spr_moisture_t*) event->data.value;  /* Cast to correct data type*/
    //uint32_t len = event.data.len/sizof(spr_moisture_t);   /* Get length of array*/


    //TODO Handle Moisture Characteristic events
    return MRT_STATUS_OK;
}

/**
 * @brief Handles GATT event on Relays Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t spr_relays_handler(mrt_gatt_evt_t* event)
{

    spr_relays_t val = *((spr_relays_t*) event->data.value); /* Cast to correct data type*/

    //Set LED output based on bit for pump relay
    gpio_set_level(GPIO_LED, val & SPR_RELAYS_PUMP);


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

/**
 * @brief Handles GATT event on SoilType Characteristic
 * @param event - ptr to mrt_gatt_evt_t event with data and event type
 */
mrt_status_t spr_soiltype_handler(mrt_gatt_evt_t* event)
{

    //spr_soiltype_t val = *((spr_soiltype_t*) event->data.value); /* Cast to correct data type*/


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
