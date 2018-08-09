/**
 * @File     security_viid_service.cpp
 * @brief    
 * @DateTime 2018/8/4 11:36:40
 * @Author   Anyz
 */
#include "security_viid_service.h"
#include "simple_xml.h"
#include "http_message.h"
#include "security_rest.h"


int security_viid_service::sys_register(const char* ip, int port, const char* deviceId) {
    
    return 0;
}
/**
 * @Method   sys_unregister
 * @Brief
 * @DateTime 2018-08-04T12:42:02+0800
 * @Modify   2018-08-04T12:42:02+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_viid_service::sys_unregister(const char* ip, int port, const char* deviceId) {
    
    return 0;
}
/**
 * @Method   sys_keepalive
 * @Brief
 * @DateTime 2018-08-04T12:54:41+0800
 * @Modify   2018-08-04T12:54:41+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_viid_service::sys_keepalive(const char* ip, int port, const char* deviceId) {
    
    return 0;
}
/**
 * @Method   sys_synctime
 * @Brief
 * @DateTime 2018-08-04T12:55:00+0800
 * @Modify   2018-08-04T12:55:00+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
int security_viid_service::sys_synctime(const char* ip, int port) {
    
    return 0;
}
/**
 * @Method   query_apes
 * @Brief
 * @DateTime 2018-08-04T14:15:03+0800
 * @Modify   2018-08-04T14:15:03+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid_service::query_apes(const char* ip, int port, const char* key, const char* value) {
    
    return 0;
}
/**
 * @Method   update_apes
 * @Brief
 * @DateTime 2018-08-04T14:21:52+0800
 * @Modify   2018-08-04T14:21:52+0800
 * @Author   Anyz
 * @return   [description]
 */
int security_viid_service::update_apes(const char* ) {
    
    return 0;
}

int security_viid_service::query_apss() {

}

int security_viid_service::query_tollgates() {

}

int security_viid_service::query_lanes() {

}

int security_viid_service::query_video_slices() {

}

int security_viid_service::add_video_slices() {

}

int security_viid_service::query_video_slice() {

}

int security_viid_service::update_video_slice() {

}

int security_viid_service::delete_video_slice() {

}

int security_viid_service::query_videoinfo() {

}

int security_viid_service::add_videoinfo() {

}

int security_viid_service::delete_videoinfo() {

}
/**
 * @Method   addressPrefix
 * @Brief
 * @DateTime 2018-08-04T14:15:16+0800
 * @Modify   2018-08-04T14:15:16+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
std::string security_viid_service::addressPrefix(const char* ip, int port) {
    if (!ip || strlen(ip) < 5) {
        printf("IP address invalid.\n");
        return SECURITY_STRING_EMPTY;
    }
    if (port < 1024 || port > 65536) {
        printf("port invalid.\n");
        return SECURITY_STRING_EMPTY;
    }
    std::string suri("http://");
    suri.append(ip);
    suri.append(":");
    suri.append(port2String(port));
    return suri;
}








