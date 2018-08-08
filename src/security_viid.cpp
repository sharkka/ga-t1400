/**
 * @File     security_viid.cpp
 * @brief    
 * @DateTime 2018/8/4 11:36:40
 * @Author   Anyz
 */
#include "security_viid.h"
#include "simple_xml.h"
#include "http_message.h"
#include "security_rest.h"
#include "security_message_factory.h"

/**
 * @Method   sys_register
 * @Brief
 * @DateTime 2018-08-04T12:15:07+0800
 * @Modify   2018-08-04T12:15:07+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_viid::sys_register(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_REGISTER);
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }

    http_message hm;
    std::string sxml = security_message_factory::makeRegisterMessage(deviceId);
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    printf("response: %s\n", respData.c_str());
    if (SECURITY_REST_HTTP_RESPONSE_401 == hm.errorCode()) {
        http_message hm;
        
        printf("server response %d\n", ret);
        hm.appendHeaderItem("username:admin");
        hm.appendHeaderItem("password:13579");
        int ret = hm.post(uri, sxml);
        if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
            printf("Register failed.\n");
            return -1;
        }
    }
    printf("Register success.");
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
int security_viid::sys_unregister(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_UNREGISTER);
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    http_message hm;
    std::string sxml = security_message_factory::makeUnregisterMessage(deviceId);
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    printf("response: %s\n", respData.c_str());
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("Unregister failed.\n");
        return -1;
    }
    printf("Unregister success.");
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
int security_viid::sys_keepalive(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_KEEPALIVE);
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }

    http_message hm;
    std::string sxml = security_message_factory::makeKeepaliveMessage(deviceId);
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    printf("response: %s\n", respData.c_str());
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("Keep alive failed.\n");
        return -1;
    }
    printf("Keep alive success.");
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
int security_viid::sys_synctime(const char* ip, int port) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_TIME);
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("Keep alive failed.\n");
        return -1;
    }

    printf("Keep alive success.\n");
    printf("response: %s\n", respData.c_str());
    // synchorize your system time
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
int security_viid::query_apes(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_APES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get APE list failed.\n");
        return -1;
    }
    printf("get APE list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase APE list
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
int security_viid::update_apes(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_APES);
    std::string sxml = security_message_factory::makeAPEListMessage(deviceId);
    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get APE list failed.\n");
        return -1;
    }
    printf("get APE list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase APE list
    return 0;
}
/**
 * @Method   query_apss
 * @Brief
 * @DateTime 2018-08-06T10:36:45+0800
 * @Modify   2018-08-06T10:36:45+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_apss(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_APSS);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get APS list failed.\n");
        return -1;
    }
    printf("get APS list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase APS list
    return 0;
}
/**
 * @Method   query_tollgates
 * @Brief
 * @DateTime 2018-08-06T10:56:35+0800
 * @Modify   2018-08-06T10:56:35+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_tollgates(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_TOLLGATES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string info = queryCondition(key, value);
    http_message hm;
    int ret = hm.get(suri.c_str(), info);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get Tollgates list failed.\n");
        return -1;
    }
    printf("get Tollgates list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase Tollgates list
    return 0;
}
/**
 * @Method   query_lanes
 * @Brief
 * @DateTime 2018-08-06T10:56:47+0800
 * @Modify   2018-08-06T10:56:47+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_lanes(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_LANES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string info = queryCondition(key, value);
    http_message hm;
    int ret = hm.get(suri.c_str(), info);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get Lanes list failed.\n");
        return -1;
    }
    printf("get Lanes list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase Lanes list
    return 0;
}
/**
 * @Method   query_video_slices
 * @Brief
 * @DateTime 2018-08-06T11:28:58+0800
 * @Modify   2018-08-06T11:28:58+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_video_slices(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string info = queryCondition(key, value);
    http_message hm;
    int ret = hm.get(suri.c_str(), info);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get VideoSlices list failed.\n");
        return -1;
    }
    printf("get VideoSlices list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase VideoSlices list
    return 0;
}
/**
 * @Method   add_video_slices
 * @Brief
 * @DateTime 2018-08-06T11:29:09+0800
 * @Modify   2018-08-06T11:29:09+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_viid::add_video_slices(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICES);
    std::string sxml = security_message_factory::makeVideoSliceListMessage(deviceId);
    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get VideoSlices list failed.\n");
        return -1;
    }
    printf("get VideoSlices list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase VideoSlices list
    return 0;
}
/**
 * @Method   query_video_slice
 * @Brief
 * @DateTime 2018-08-06T11:31:57+0800
 * @Modify   2018-08-06T11:31:57+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_video_slice(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    suri.append(id);
    
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get VideoSlice failed.\n");
        return -1;
    }
    printf("get VideoSlice success.\n");
    printf("response: %s\n", respData.c_str());
    // pase VideoSlice
    return 0;
}
/**
 * @Method   update_video_slice
 * @Brief
 * @DateTime 2018-08-06T11:34:16+0800
 * @Modify   2018-08-06T11:34:16+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_viid::update_video_slice(const char* ip, int port, const char* id, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    suri.append(id);
    std::string sxml = security_message_factory::makeVideoSliceListMessage(deviceId);
    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update VideoSlice failed.\n");
        return -1;
    }
    printf("update VideoSlice success.\n");
    printf("response: %s\n", respData.c_str());
    // pase VideoSlice
    return 0;
}
/**
 * @Method   delete_video_slice
 * @Brief
 * @DateTime 2018-08-06T11:36:00+0800
 * @Modify   2018-08-06T11:36:00+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_video_slice(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    suri.append(id);
    http_message hm;
    int ret = hm.delete(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete VideoSlice failed.\n");
        return -1;
    }
    printf("delete VideoSlice success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatusList
    return 0;
}
/**
 * @Method   query_videodata
 * @Brief
 * @DateTime 2018-08-06T11:43:35+0800
 * @Modify   2018-08-06T11:43:35+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_videodata(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.get(suri.c_str());
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get Video data failed.\n");
        return -1;
    }
    printf("get Video data success.\n");
    // check data and got base64 binary data
    return 0;
}
/**
 * @Method   add_videodata
 * @Brief
 * @DateTime 2018-08-06T11:45:46+0800
 * @Modify   2018-08-06T11:45:46+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    buff [description]
 * @return   [description]
 */
int security_viid::add_videodata(const char* ip, int port, const char* id, const char* buff) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    if (!buff) {
        printf("buffer empty.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.post(suri.c_str(), buff);
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add Video data failed.\n");
        return -1;
    }
    printf("add Video data success.\n");
    // video data posted
    return 0;
}
/**
 * @Method   delete_videodata
 * @Brief
 * @DateTime 2018-08-06T11:45:57+0800
 * @Modify   2018-08-06T11:45:57+0800
 * @Author   Anyz
 * @return   [description]
 */
int security_viid::delete_videodata(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.delete(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete VideoSlice failed.\n");
        return -1;
    }
    printf("delete VideoSlice success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatus
    return 0;
}
/**
 * @Method   query_images
 * @Brief
 * @DateTime 2018-08-06T12:06:58+0800
 * @Modify   2018-08-06T12:06:58+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_images(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string info = queryCondition(key, value);
    http_message hm;
    int ret = hm.get(suri.c_str(), info);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get image list failed.\n");
        return -1;
    }
    printf("get image list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase image list
    return 0;
}
/**
 * @Method   add_image
 * @Brief
 * @DateTime 2018-08-06T12:27:44+0800
 * @Modify   2018-08-06T12:27:44+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_viid::add_images(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGES);
    suri.append(id);
    std::string sxml = security_message_factory::makeImageListMessage(deviceId);
    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update image list failed.\n");
        return -1;
    }
    printf("update image list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase image list
    return 0;
}
/**
 * @Method   {{tag}}
 * @Brief
 * @DateTime 2018-08-06T14:29:40+0800
 * @Modify   2018-08-06T14:29:40+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_image(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get image failed.\n");
        return -1;
    }
    printf("get image success.\n");
    printf("response: %s\n", respData.c_str());
    // pase image
    return 0;
}
/**
 * @Method   update_image
 * @Brief
 * @DateTime 2018-08-06T14:32:43+0800
 * @Modify   2018-08-06T14:32:43+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::update_image(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeImageMessage(id);
    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update image failed.\n");
        return -1;
    }
    printf("update image success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatusList
    return 0;
}
/**
 * @Method   delete_image
 * @Brief
 * @DateTime 2018-08-06T14:34:21+0800
 * @Modify   2018-08-06T14:34:21+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_image(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete image failed.\n");
        return -1;
    }
    printf("delete image success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatusList
    return 0;
}
/**
 * @Method   query_imageinfo
 * @Brief
 * @DateTime 2018-08-06T14:38:26+0800
 * @Modify   2018-08-06T14:38:26+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_imageinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_INFO);
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get image info failed.\n");
        return -1;
    }
    printf("get image info success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ImageInfo
    return 0;
}
/**
 * @Method   update_imageinfo
 * @Brief
 * @DateTime 2018-08-06T15:16:36+0800
 * @Modify   2018-08-06T15:16:36+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::update_imageinfo(const char* ip, int port, const char* id, const security_image_info_t* info) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeImageInfoMessage(info);
    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update image info ailed.\n");
        return -1;
    }
    printf("update image info success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatus
    return 0;
}
/**
 * @Method   delete_imageinfo
 * @Brief
 * @DateTime 2018-08-06T15:17:14+0800
 * @Modify   2018-08-06T15:17:14+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_imageinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete image infofailed.\n");
        return -1;
    }
    printf("delete image info success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatus
    return 0;
}
/**
 * @Method   query_imagedata
 * @Brief
 * @DateTime 2018-08-06T15:20:13+0800
 * @Modify   2018-08-06T15:20:13+0800
 * @Author   Anyz
 * @return   [description]
 */
int security_viid::query_imagedata(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get image data failed.\n");
        return -1;
    }
    printf("get image data success.\n");
    printf("response: %s\n", respData.c_str());
    // got base64 binary of image
    return 0;
}
/**
 * @Method   add_imagedata
 * @Brief
 * @DateTime 2018-08-06T15:23:56+0800
 * @Modify   2018-08-06T15:23:56+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    buff [description]
 * @return   [description]
 */
int security_viid::add_imagedata(const char* ip, int port, const char* id, const char* buff) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    if (!buff {
        printf("image data invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGES);
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);

    http_message hm;
    int ret = hm.post(suri.c_str(), buff);
    
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add image data failed.\n");
        return -1;
    }
    printf("add image data success.\n");
    // add image data
    return 0;
}
/**
 * @Method   delete_imagedata
 * @Brief
 * @DateTime 2018-08-06T15:25:28+0800
 * @Modify   2018-08-06T15:25:28+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_imagedata(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_IMAGESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete image data failed.\n");
        return -1;
    }
    printf("delete image data success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatus
    return 0;
}
/**
 * @Method   query_files
 * @Brief
 * @DateTime 2018-08-06T15:36:28+0800
 * @Modify   2018-08-06T15:36:28+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_files(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string info = queryCondition(key, value);
    http_message hm;
    int ret = hm.get(suri.c_str(), info);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get file list failed.\n");
        return -1;
    }
    printf("get file list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase FileList
    return 0;
}
/**
 * @Method   add_files
 * @Brief
 * @DateTime 2018-08-06T15:51:02+0800
 * @Modify   2018-08-06T15:51:02+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    imgObj [description]
 * @return   [description]
 */
int security_viid::add_files(const char* ip, int port, const security_image_object_t* imgObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILES);
    std::string sxml = security_message_factory::makeFileListMessage(imgObj);
    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add file list failed.\n");
        return -1;
    }
    printf("add file list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatusList
    return 0;
}
/**
 * @Method   query_file
 * @Brief
 * @DateTime 2018-08-06T15:54:59+0800
 * @Modify   2018-08-06T15:54:59+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_file(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);

    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get file failed.\n");
        return -1;
    }
    printf("get file success.\n");
    printf("response: %s\n", respData.c_str());
    // parse File Object
    return 0;
}
/**
 * @Method   update_file
 * @Brief
 * @DateTime 2018-08-06T16:07:35+0800
 * @Modify   2018-08-06T16:07:35+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    fileObj [description]
 * @return   [description]
 */
int security_viid::update_file(const char* ip, int port, const char* id, const char* security_file_object_t* fileObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeFileObjectMessage(fileObj);
    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update file objectfailed.\n");
        return -1;
    }
    printf("update file object success.\n");
    printf("response: %s\n", respData.c_str());
    // parse File Object
    return 0;
}
/**
 * @Method   {{tag}}
 * @Brief
 * @DateTime 2018-08-06T16:09:19+0800
 * @Modify   2018-08-06T16:09:19+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_file(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);

    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete file object failed.\n");
        return -1;
    }
    printf("delete file object success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatusList
    return 0;
}
/**
 * @Method   query_fileinfo
 * @Brief
 * @DateTime 2018-08-06T16:12:58+0800
 * @Modify   2018-08-06T16:12:58+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_fileinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_INFO);

    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get file info failed.\n");
        return -1;
    }
    printf("get file info success.\n");
    printf("response: %s\n", respData.c_str());
    // parse FileInfo
    return 0;
}
/**
 * @Method   update_fileinfo
 * @Brief
 * @DateTime 2018-08-06T16:21:51+0800
 * @Modify   2018-08-06T16:21:51+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::update_fileinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_INFO);
    std::string sxml = security_message_factory::makeFileInfoMessage(fileInfo);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update file info failed.\n");
        return -1;
    }
    printf("update file info success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   delete_fileinfo
 * @Brief
 * @DateTime 2018-08-06T16:23:00+0800
 * @Modify   2018-08-06T16:23:00+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_fileinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_INFO);

    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete file info failed.\n");
        return -1;
    }
    printf("delete file file success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_filedata
 * @Brief
 * @DateTime 2018-08-06T16:29:23+0800
 * @Modify   2018-08-06T16:29:23+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_filedata(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get file data failed.\n");
        return -1;
    }
    printf("get file data success.\n");
    printf("response: %s\n", respData.c_str());
    // got base64 binary of image
    return 0;
}
/**
 * @Method   add_filedata
 * @Brief
 * @DateTime 2018-08-06T16:30:45+0800
 * @Modify   2018-08-06T16:30:45+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    buff [description]
 * @return   [description]
 */
int security_viid::add_filedata(const char* ip, int port, const char* id, const char* buff) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    if (!buff) {
        printf("buff invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.post(suri.c_str(), buff);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add file data failed.\n");
        return -1;
    }
    printf("add file data success.\n");
    printf("response: %s\n", respData.c_str());
    // got base64 binary of file
    return 0;
}
/**
 * @Method   delete_filedata
 * @Brief
 * @DateTime 2018-08-06T16:31:50+0800
 * @Modify   2018-08-06T16:31:50+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_filedata(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FILESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }

    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_DATA);
    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete file data failed.\n");
        return -1;
    }
    printf("delete file data success.\n");
    printf("response: %s\n", respData.c_str());
    // delete file data success
    return 0;
}
/**
 * @Method   query_persons
 * @Brief
 * @DateTime 2018-08-06T16:35:38+0800
 * @Modify   2018-08-06T16:35:38+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_persons(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONS);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string info = queryCondition(key, value);
    http_message hm;
    int ret = hm.get(suri.c_str(), info);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get person list failed.\n");
        return -1;
    }
    printf("get person list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase PersonList
    return 0;
}
/**
 * @Method   add_persons
 * @Brief
 * @DateTime 2018-08-06T16:44:26+0800
 * @Modify   2018-08-06T16:44:26+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
int security_viid::add_persons(const char* ip, int port, std::vector<security_person_object_t>& personList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONS);
    std::string sxml = security_message_factory::makePersonListMessage(personList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add person list failed.\n");
        return -1;
    }
    printf("add person list success.\n");
    printf("response: %s\n", respData.c_str());
    // add PersonList success
    return 0;
}
/**
 * @Method   update_persons
 * @Brief
 * @DateTime 2018-08-06T17:02:55+0800
 * @Modify   2018-08-06T17:02:55+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    personList [description]
 * @return   [description]
 */
int security_viid::update_persons(const char* ip, int port, std::vector<security_person_object_t>& personList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONS);
    std::string sxml = security_message_factory::makePersonListMessage(personList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update person list failed.\n");
        return -1;
    }
    printf("update person list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatusList
    return 0;
}
/**
 * @Method   delete_persons
 * @Brief    not implemented
 * @DateTime 2018-08-06T16:52:39+0800
 * @Modify   2018-08-06T16:52:39+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_persons(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONS);

    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update person list failed.\n");
        return -1;
    }
    printf("update person list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatusList
    return 0;
}
/**
 * @Method   query_person
 * @Brief
 * @DateTime 2018-08-06T17:00:10+0800
 * @Modify   2018-08-06T17:00:10+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_person(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);

    http_message hm;
    int ret = hm.get(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get person failed.\n");
        return -1;
    }
    printf("get person success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Person Object
    return 0;
}
/**
 * @Method   update_person
 * @Brief
 * @DateTime 2018-08-06T17:05:30+0800
 * @Modify   2018-08-06T17:05:30+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    personObj [description]
 * @return   [description]
 */
int security_viid::update_person(const char* ip, int port, const char* id, const security_person_object_t* personObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makePersonObjectMessage(personObj);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update person failed.\n");
        return -1;
    }
    printf("update person success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   delete_person
 * @Brief
 * @DateTime 2018-08-06T17:06:35+0800
 * @Modify   2018-08-06T17:06:35+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_person(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_PERSONSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);

    http_message hm;
    int ret = hm.del(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete person failed.\n");
        return -1;
    }
    printf("delete person success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}

int security_viid::query_faces(const char* ip, int port, const char* id) {
    
}

int security_viid::add_faces() {
    
}

int security_viid::delete_faces() {
    
}

int security_viid::query_face() {
    
}

int security_viid::add_face() {
    
}

int security_viid::delete_face() {
    
}

int security_viid::query_vehicles() {
    
}

int security_viid::add_vehicles() {
    
}

int security_viid::delete_vehicles() {
    
}

int security_viid::query_vehicle() {
    
}

int security_viid::add_vehicle() {
    
}

int security_viid::delete_vehicles() {
    
}

int security_viid::query_novehicles() {
    
}

int security_viid::add_nonvehicles() {
    
}

int security_viid::delete_nonvehicles() {
    
}

int security_viid::query_nonvehicle() {
    
}

int security_viid::add_nonvehicle() {
    
}

int security_viid::delete_nonvehicle() {
    
}

int security_viid::query_things() {
    
}

int security_viid::add_things() {
    
}

int security_viid::delete_things() {
    
}

int security_viid::query_thing() {
    
}

int security_viid::insert_thing() {
    
}

int security_viid::delete_thing() {
    
}

int security_viid::query_scenes() {
    
}

int security_viid::add_scenes() {
    
}

int security_viid::delete_scenes() {
    
}

int security_viid::query_scene() {
    
}

int security_viid::add_scene() {
    
}

int security_viid::delete_scene() {
    
}

int security_viid::query_cases() {
    
}

int security_viid::add_cases() {
    
}

int security_viid::delete_cases() {
    
}

int security_viid::query_case() {
    
}

int security_viid::add_case() {
    
}

int security_viid::delete_case() {
    
}

int security_viid::query_caseinfo() {
    
}

int security_viid::add_caseinfo() {
    
}

int security_viid::delete_caseinfo() {
    
}

int security_viid::dispositions() {
    
}

int security_viid::query_disposition() {
    
}

int security_viid::update_disposition() {
    
}

int security_viid::delete_disposition() {
    
}

int security_viid::undispostions() {
    
}

int security_viid::disposition_notifications() {
    
}

int security_viid::query_disposition_notification() {
    
}

int security_viid::delete_disposition_notification() {
    
}

int security_viid::subscribes() {
    
}

int security_viid::query_subscribes() {
    
}

int security_viid::update_subscribes() {
    
}

int security_viid::delete_subscribes() {
    
}

int security_viid::unsubscribes() {
    
}

int security_viid::subscribe_notifications() {
    
}

int security_viid::query_subscribe_notifications() {
    
}

int security_viid::update_subscribe_notifications() {
    
}

int security_viid::delete_subscribe_notifications() {
    
}

int security_viid::query_analysis_rules() {
    
}

int security_viid::add_analysis_rules() {
    
}

int security_viid::update_analysis_rules() {
    
}

int security_viid::delete_analysis_rules() {
    
}

int security_viid::query_analysis_rule() {
    
}

int security_viid::add_analysis_rule() {
    
}

int security_viid::update_analysis_rule() {
    
}

int security_viid::delete_analysis_rule() {
    
}

int security_viid::query_video_labels() {
    
}

int security_viid::add_video_labels() {
    
}

int security_viid::update_video_labels() {
    
}

int security_viid::delete_video_labels() {
    
}

int security_viid::query_video_label() {
    
}

int security_viid::add_video_label() {
    
}

int security_viid::update_video_label() {
    
}

int security_viid::delete_video_label() {
    
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
std::string security_viid::addressPrefix(const char* ip, int port) {
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
    suri.append(num2String(port));
    return suri;
}
/**
 * @Method   queryCondition
 * @Brief
 * @DateTime 2018-08-06T15:58:16+0800
 * @Modify   2018-08-06T15:58:16+0800
 * @Author   Anyz
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
std::string security_viid::queryCondition(const char* key, const char* value) {
    std::string s = "?";
    s.append(key);
    s.append("=");
    s.append(value);
    return s;
}






