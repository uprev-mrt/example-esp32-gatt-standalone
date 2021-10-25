idf_component_register(SRCS 
                        "example_gatt_server.c"
                        "interface/mrt_gatt_interface.c"
                        "interface/esp32_gatt_adapter.c"  
                        "svc/dvc_svc.c"
                        "app_dvc_svc.c"
                        "svc/bat_svc.c"
                        "app_bat_svc.c"
                        "svc/spr_svc.c"
                        "app_spr_svc.c"
                        "svc/ota_svc.c"
                        "app_ota_svc.c"
               INCLUDE_DIRS interface svc)