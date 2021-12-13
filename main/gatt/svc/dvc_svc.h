/**
 * @file dvc_svc.h
 * @brief The Device Information Service exposes manufacturer and/or vendor information about a device.
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


typedef struct{
    mrt_gatt_svc_t mSvc;
    mrt_gatt_char_t mManufacturerName;           /* The value of this characteristic is a UTF-8 string representing the name of the manufacturer of the device. */
    mrt_gatt_char_t mSerialNumber;               /* The value of this characteristic is a variable-length UTF-8 string representing the serial number for a particular instance of the device. */
    mrt_gatt_char_t mHardwareRevision;           /* The value of this characteristic is a UTF-8 string representing the hardware revision for the hardware within the device. */
    mrt_gatt_char_t mFirmwareRevision;           /* Firmware revision */
    /*user-block-struct-start*/
    /*user-block-struct-end*/
} dvc_svc_t;

/* Exported constants --------------------------------------------------------*/
extern dvc_svc_t dvc_svc;

/* Initializer----------------------------------------------------------------*/
dvc_svc_t* dvc_svc_init(mrt_gatt_pro_t* pro);

void dvc_svc_register();





/* Getters and Setters--------------------------------------------------------*/

/* */
#define dvc_set_manufacturer_name(val)       mrt_gatt_update_char_val(&dvc_svc.mManufacturerName, (uint8_t*)(val), strlen(val))
#define dvc_set_serial_number(val)           mrt_gatt_update_char_val(&dvc_svc.mSerialNumber, (uint8_t*)(val), strlen(val))
#define dvc_set_hardware_revision(val)       mrt_gatt_update_char_val(&dvc_svc.mHardwareRevision, (uint8_t*)(val), strlen(val))
#define dvc_set_firmware_revision(val)       mrt_gatt_update_char_val(&dvc_svc.mFirmwareRevision, (uint8_t*)(val), strlen(val))

/**
 * @brief get cached data for characteristics
 */
char* dvc_get_manufacturer_name();
char* dvc_get_serial_number();
char* dvc_get_hardware_revision();
char* dvc_get_firmware_revision();

/**
 * @brief check if cache is valid
 */
#define dvc_manufacturer_name_cache_valid()                      (dvc_svc.mManufacturerName.data.len != 0)
#define dvc_serial_number_cache_valid()                          (dvc_svc.mSerialNumber.data.len != 0)
#define dvc_hardware_revision_cache_valid()                      (dvc_svc.mHardwareRevision.data.len != 0)
#define dvc_firmware_revision_cache_valid()                      (dvc_svc.mFirmwareRevision.data.len != 0)

/* Handlers ------------------------------------------------------------------*/
void dvc_svc_post_init_handler();

mrt_status_t dvc_manufacturer_name_handler(mrt_gatt_evt_t* event);
mrt_status_t dvc_serial_number_handler(mrt_gatt_evt_t* event);
mrt_status_t dvc_hardware_revision_handler(mrt_gatt_evt_t* event);
mrt_status_t dvc_firmware_revision_handler(mrt_gatt_evt_t* event);

#ifdef __cplusplus
}
#endif