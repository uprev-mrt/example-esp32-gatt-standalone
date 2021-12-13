/**
 * @file ota_svc.h
 * @brief sercive for performing over the air updates
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
/* status Values */
    #define OTA_STATUS_IDLE 0x0000   // no ota operation taking place
    #define OTA_STATUS_DOWNLOAD 0x0001   // Currently downloading new firmware
    #define OTA_STATUS_COMPLETE 0x0002   // Firmware download complete. ready to update


/* Exported types ------------------------------------------------------------*/

    typedef uint8_t*                             ota_data_t;
    typedef uint32_t                             ota_seq_t;
    typedef uint32_t                             ota_crc_t;
    typedef uint8_t                              ota_status_t;

typedef struct{
    mrt_gatt_svc_t mSvc;
    mrt_gatt_char_t mVersion;                    /* current Firmware version */
    mrt_gatt_char_t mNewverion;                  /* version of new firmware being loaded */
    mrt_gatt_char_t mData;                       /* current block of data */
    mrt_gatt_char_t mSeq;                        /* sequence number of current block */
    mrt_gatt_char_t mCrc;                        /* crc of new firmware */
    mrt_gatt_char_t mStatus;                     /* status of OTA process */
    /*user-block-struct-start*/
    /*user-block-struct-end*/
} ota_svc_t;

/* Exported constants --------------------------------------------------------*/
extern ota_svc_t ota_svc;

/* Initializer----------------------------------------------------------------*/
ota_svc_t* ota_svc_init(mrt_gatt_pro_t* pro);

void ota_svc_register();





/* Getters and Setters--------------------------------------------------------*/

/* */
#define ota_set_version(val)                 mrt_gatt_update_char_val(&ota_svc.mVersion, (uint8_t*)(val), strlen(val))
#define ota_set_newverion(val)               mrt_gatt_update_char_val(&ota_svc.mNewverion, (uint8_t*)(val), strlen(val))
#define ota_set_data(val,len)                mrt_gatt_update_char_val(&ota_svc.mData, (uint8_t*)(val), (len))
#define ota_set_seq(val)                     mrt_gatt_update_char_val(&ota_svc.mSeq, (uint8_t*)(&(ota_seq_t){val}), 4)
#define ota_set_crc(val)                     mrt_gatt_update_char_val(&ota_svc.mCrc, (uint8_t*)(&(ota_crc_t){val}), 4)
#define ota_set_status(val)                  mrt_gatt_update_char_val(&ota_svc.mStatus, (uint8_t*)(&(ota_status_t){val}), 1)

/**
 * @brief get cached data for characteristics
 */
char* ota_get_version();
char* ota_get_newverion();
uint8_t* ota_get_data();
uint32_t ota_get_seq();
uint32_t ota_get_crc();
uint8_t ota_get_status();

/**
 * @brief check if cache is valid
 */
#define ota_version_cache_valid()                                (ota_svc.mVersion.data.len != 0)
#define ota_newverion_cache_valid()                              (ota_svc.mNewverion.data.len != 0)
#define ota_data_cache_valid()                                   (ota_svc.mData.data.len != 0)
#define ota_seq_cache_valid()                                    (ota_svc.mSeq.data.len != 0)
#define ota_crc_cache_valid()                                    (ota_svc.mCrc.data.len != 0)
#define ota_status_cache_valid()                                 (ota_svc.mStatus.data.len != 0)

/* Handlers ------------------------------------------------------------------*/
void ota_svc_post_init_handler();

mrt_status_t ota_version_handler(mrt_gatt_evt_t* event);
mrt_status_t ota_newverion_handler(mrt_gatt_evt_t* event);
mrt_status_t ota_data_handler(mrt_gatt_evt_t* event);
mrt_status_t ota_seq_handler(mrt_gatt_evt_t* event);
mrt_status_t ota_crc_handler(mrt_gatt_evt_t* event);
mrt_status_t ota_status_handler(mrt_gatt_evt_t* event);

#ifdef __cplusplus
}
#endif