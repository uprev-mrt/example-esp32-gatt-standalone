/**
 * @file bat_svc.h
 * @brief The Battery Service exposes the state of a battery within a device.
 * @date 12/13/21
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../interface/mrt_gatt_interface.h"


/* Exported Macros -----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

    typedef uint8_t                              bat_level_t;

typedef struct{
    mrt_gatt_svc_t mSvc;
    mrt_gatt_char_t mLevel;                      /* The current charge level of a battery. 100% represents fully charged while 0% represents fully discharged. */
    /*user-block-struct-start*/
    /*user-block-struct-end*/
} bat_svc_t;

/* Exported constants --------------------------------------------------------*/
extern bat_svc_t bat_svc;

/* Initializer----------------------------------------------------------------*/
bat_svc_t* bat_svc_init(mrt_gatt_pro_t* pro);

void bat_svc_register();





/* Getters and Setters--------------------------------------------------------*/

/* */
#define bat_set_level(val)                   mrt_gatt_update_char_val(&bat_svc.mLevel, (uint8_t*)(&(bat_level_t){val}), 1)

/**
 * @brief get cached data for characteristics
 */
uint8_t bat_get_level();

/**
 * @brief check if cache is valid
 */
#define bat_level_cache_valid()                                  (bat_svc.mLevel.data.len != 0)

/* Handlers ------------------------------------------------------------------*/
void bat_svc_post_init_handler();

mrt_status_t bat_level_handler(mrt_gatt_evt_t* event);

#ifdef __cplusplus
}
#endif