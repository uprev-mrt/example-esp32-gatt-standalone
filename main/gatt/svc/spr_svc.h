/**
 * @file spr_svc.h
 * @brief Custom service for a sprinkler system
 * @date 10/24/21
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../interface/mrt_gatt_interface.h"


/* Exported Macros -----------------------------------------------------------*/
/* Relays Values */
    #define SPR_RELAYS_PUMP 0x0001   // pump control
    #define SPR_RELAYS_VALVE01 0x0002   // valve 1 control
    #define SPR_RELAYS_VALVE02 0x0004   // valve 2 control
    #define SPR_RELAYS_VALVE03 0x0008   // valve 3 control
    #define SPR_RELAYS_VALVE04 0x0010   // valve 4 control
    #define SPR_RELAYS_VALVE05 0x0020   // valve 5 control
    #define SPR_RELAYS_VALVE06 0x0040   // valve 6 control

/* SoilType Values */
    #define SPR_SOILTYPE_PEAT 0x0000   // Peat soil
    #define SPR_SOILTYPE_SAND 0x0001   // Peat soil
    #define SPR_SOILTYPE_CLAY 0x0002   // Peat soil
    #define SPR_SOILTYPE_TOPSOIL 0x0003   // TopSoil


/* Exported types ------------------------------------------------------------*/

    typedef uint16_t                             spr_thresh_t;
    typedef uint16_t                             spr_temperature_t;
    typedef uint16_t*                            spr_moisture_t;
    typedef uint8_t                              spr_relays_t;
    typedef uint8_t                              spr_soiltype_t;

typedef struct{
    mrt_gatt_svc_t mSvc;
    mrt_gatt_char_t mThresh;                     /* Moisture Threshold to turn on the sprinklers */
    mrt_gatt_char_t mTemperature;                /* Temperature reading from sensor */
    mrt_gatt_char_t mMoisture;                   /* Moisture readings from all 6 zones */
    mrt_gatt_char_t mRelays;                     /* Controls Relays for pump and valves */
    mrt_gatt_char_t mSoiltype;                   /* Soil type for the yard */
    /*user-block-struct-start*/
    /*user-block-struct-end*/
} spr_svc_t;

/* Exported constants --------------------------------------------------------*/
extern spr_svc_t spr_svc;

/* Initializer----------------------------------------------------------------*/
spr_svc_t* spr_svc_init(mrt_gatt_pro_t* pro);

void spr_svc_register();





/* Getters and Setters--------------------------------------------------------*/

/* */
#define spr_set_thresh(val)                  mrt_gatt_update_char_val(&spr_svc.mThresh, (uint8_t*)(val), 2)
#define spr_set_temperature(val)             mrt_gatt_update_char_val(&spr_svc.mTemperature, (uint8_t*)(val), 2)
#define spr_set_moisture(val)                mrt_gatt_update_char_val(&spr_svc.mMoisture, (uint8_t*)(val), 12)
#define spr_set_relays(val)                  mrt_gatt_update_char_val(&spr_svc.mRelays, (uint8_t*)(val), 1)
#define spr_set_soiltype(val)                mrt_gatt_update_char_val(&spr_svc.mSoiltype, (uint8_t*)(val), 1)

/**
 * @brief get cached data for characteristics
 */
uint16_t spr_get_thresh();
uint16_t spr_get_temperature();
uint16_t* spr_get_moisture();
uint8_t spr_get_relays();
uint8_t spr_get_soiltype();

/**
 * @brief check if cache is valid
 */
#define spr_thresh_cache_valid()                                 (spr_svc.mThresh.data.len != 0)
#define spr_temperature_cache_valid()                            (spr_svc.mTemperature.data.len != 0)
#define spr_moisture_cache_valid()                               (spr_svc.mMoisture.data.len != 0)
#define spr_relays_cache_valid()                                 (spr_svc.mRelays.data.len != 0)
#define spr_soiltype_cache_valid()                               (spr_svc.mSoiltype.data.len != 0)

/* Handlers ------------------------------------------------------------------*/
void spr_svc_post_init_handler();

mrt_status_t spr_thresh_handler(mrt_gatt_evt_t* event);
mrt_status_t spr_temperature_handler(mrt_gatt_evt_t* event);
mrt_status_t spr_moisture_handler(mrt_gatt_evt_t* event);
mrt_status_t spr_relays_handler(mrt_gatt_evt_t* event);
mrt_status_t spr_soiltype_handler(mrt_gatt_evt_t* event);

#ifdef __cplusplus
}
#endif