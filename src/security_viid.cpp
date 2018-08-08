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
/**
 * @Method   query_faces
 * @Brief
 * @DateTime 2018-08-08T10:46:44+0800
 * @Modify   2018-08-08T10:46:44+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_faces(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FACES);
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
        printf("get face list failed.\n");
        return -1;
    }
    printf("get face list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase FaceList
    return 0;
}
/**
 * @Method   update_faces
 * @Brief
 * @DateTime 2018-08-08T10:47:39+0800
 * @Modify   2018-08-08T10:47:39+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
int security_viid::update_faces(const char* ip, int port, std::vector<security_face_object_t>& faceList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FACES);
    std::string sxml = security_message_factory::makeFaceListMessage(faceObj);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update face list failed.\n");
        return -1;
    }
    printf("update face list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatusList
    return 0;
}
/**
 * @Method   delete_faces
 * @Brief
 * @DateTime 2018-08-08T10:49:53+0800
 * @Modify   2018-08-08T10:49:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_faces(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FACES);
    std::string condi;
    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete face list failed.\n");
        return -1;
    }
    printf("delete face list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase ResponseStatusList
    return 0;
}
/**
 * @Method   query_face
 * @Brief
 * @DateTime 2018-08-08T10:54:51+0800
 * @Modify   2018-08-08T10:54:51+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_face(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FACESS);
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
        printf("get face failed.\n");
        return -1;
    }
    printf("get face success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Face Object
    return 0;
}
/**
 * @Method   update_face
 * @Brief
 * @DateTime 2018-08-08T10:57:35+0800
 * @Modify   2018-08-08T10:57:35+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    faceObj [description]
 * @return   [description]
 */
int security_viid::update_face(const char* ip, int port, const security_face_object_t* faceObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FACESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeFaceObjectMessage(faceObj);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update face failed.\n");
        return -1;
    }
    printf("update face success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseList
    return 0;
}
/**
 * @Method   delete_face
 * @Brief
 * @DateTime 2018-08-08T11:01:15+0800
 * @Modify   2018-08-08T11:01:15+0800
 * @Author   Anyz
 * @return   [description]
 */
int security_viid::delete_face(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_FACESS);
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
        printf("delete face failed.\n");
        return -1;
    }
    printf("delete face success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_motorvehiclies
 * @Brief
 * @DateTime 2018-08-08T11:09:18+0800
 * @Modify   2018-08-08T11:09:18+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_motorvehicles(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHIS);
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
        printf("get motorvehicle list failed.\n");
        return -1;
    }
    printf("get motorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase MotorVehicle list
    return 0;
}
/**
 * @Method   add_motorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:12:26+0800
 * @Modify   2018-08-08T11:12:26+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    faceList [description]
 * @return   [description]
 */
int security_viid::add_motorvehicles(const char* ip, int port, std::vector<security_vehicle_object_t>& vehicleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHIS);
    std::string sxml = security_message_factory::makeMotorVehicleListMessage(vehicleList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add motorvehicle list failed.\n");
        return -1;
    }
    printf("add motorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   update_motorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:13:01+0800
 * @Modify   2018-08-08T11:13:01+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    faceList [description]
 * @return   [description]
 */
int security_viid::update_motorvehicles(const char* ip, int port, std::vector<security_vehicle_object_t>& vehicleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHIS);
    std::string sxml = security_message_factory::makeMotorVehicleListMessage(vehicleList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update motorvehicle list failed.\n");
        return -1;
    }
    printf("update motorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   delete_motorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:16:50+0800
 * @Modify   2018-08-08T11:16:50+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_motorvehicles(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHIS);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete motorvehicle list failed.\n");
        return -1;
    }
    printf("delete motorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   query_motorvehicle
 * @Brief
 * @DateTime 2018-08-08T11:20:54+0800
 * @Modify   2018-08-08T11:20:54+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_motorvehicle(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHISS);
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
        printf("get motor vechicle failed.\n");
        return -1;
    }
    printf("get motor vehicle success.\n");
    printf("response: %s\n", respData.c_str());
    // parse MotorVehicle Object
    return 0;
}
/**
 * @Method   add_motorvehicle
 * @Brief
 * @DateTime 2018-08-08T11:23:40+0800
 * @Modify   2018-08-08T11:23:40+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    vehicleObj [description]
 * @return   [description]
 */
int security_viid::add_motorvehicle(const char* ip, int port, const security_motorvehicle_object_t* vehicleObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHISS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeMotorVehicleMessage(vehicleObj);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add motor vehicle failed.\n");
        return -1;
    }
    printf("add motor vehicle success.\n");
    printf("response: %s\n", respData.c_str());
    // parse MotorVehicle Object
    return 0;
}
/**
 * @Method   delete_motorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:29:11+0800
 * @Modify   2018-08-08T11:29:11+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_motorvehicle(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_MOTORVEHISS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete motor vehicle failed.\n");
        return -1;
    }
    printf("delete motor vehicle success.\n");
    printf("response: %s\n", respData.c_str());
    // parse MotorVehicle Object
    return 0;
}
/**
 * @Method   query_nonmotorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:33:17+0800
 * @Modify   2018-08-08T11:33:17+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_nonmotorvehicles(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
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
        printf("get nonmotorvehicle list failed.\n");
        return -1;
    }
    printf("get nonmotorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase NonMotorVehicle list
    return 0;
}
/**
 * @Method   add_nonmotorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:35:11+0800
 * @Modify   2018-08-08T11:35:11+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    nvehicleList [description]
 * @return   [description]
 */
int security_viid::add_nonmotorvehicles(const char* ip, int port, std::vector<security_nonmotorvehicle_object_t>& nvehicleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
    std::string sxml = security_message_factory::makeMotorVehicleListMessage(nvehiclieList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add nonmotorvehicle list failed.\n");
        return -1;
    }
    printf("add nonmotorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   update_nonmotorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:36:30+0800
 * @Modify   2018-08-08T11:36:30+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    nvehicleList [description]
 * @return   [description]
 */
int security_viid::update_nonmotorvehicles(const char* ip, int port, std::vector<security_nonmotorvehicle_object_t>& nvehicleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
    std::string sxml = security_message_factory::makeMotorVehicleListMessage(nonvehicleList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update nonmotorvehicle list failed.\n");
        return -1;
    }
    printf("update nonmotorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   delete_nonmotorvehicles
 * @Brief
 * @DateTime 2018-08-08T11:37:04+0800
 * @Modify   2018-08-08T11:37:04+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_nonmotorvehicles(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete nonmotorvehicle list failed.\n");
        return -1;
    }
    printf("delete nonmotorvehicle list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   query_nonmotorvehicle
 * @Brief
 * @DateTime 2018-08-08T11:37:45+0800
 * @Modify   2018-08-08T11:37:45+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_nonmotorvehicle(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHISS);
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
        printf("get non motor vehicle failed.\n");
        return -1;
    }
    printf("get non motor vehicle success.\n");
    printf("response: %s\n", respData.c_str());
    // parse MotorVehicle Object
    return 0;
}
/**
 * @Method   add_nonmotorvehicle
 * @Brief
 * @DateTime 2018-08-08T11:39:23+0800
 * @Modify   2018-08-08T11:39:23+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    nvehicleObj [description]
 * @return   [description]
 */
int security_viid::add_nonmotorvehicle(const char* ip, int port, const security_nonmotorvehicle_object_t* nvehicleObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHISS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeNonMotorVehicleMessage(nvehicleObj);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add non motor vehicle failed.\n");
        return -1;
    }
    printf("add non motor vehicle success.\n");
    printf("response: %s\n", respData.c_str());
    // parse NonMotorVehicle Object
    return 0;
}
/**
 * @Method   delete_nonmotorvehicle
 * @Brief
 * @DateTime 2018-08-08T11:39:56+0800
 * @Modify   2018-08-08T11:39:56+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_nonmotorvehicle(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_NONMOTORVEHISS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete non motor vehicle failed.\n");
        return -1;
    }
    printf("delete non motor vehicle success.\n");
    printf("response: %s\n", respData.c_str());
    // parse NonMotorVehicle Object
    return 0;
}
/**
 * @Method   query_things
 * @Brief
 * @DateTime 2018-08-08T11:48:46+0800
 * @Modify   2018-08-08T11:48:46+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_things(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGS);
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
        printf("get thing list failed.\n");
        return -1;
    }
    printf("get ting list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   add_things
 * @Brief
 * @DateTime 2018-08-08T11:49:26+0800
 * @Modify   2018-08-08T11:49:26+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    thingList [description]
 * @return   [description]
 */
int security_viid::add_things(const char* ip, int port, std::vector<security_thing_object_t>& thingList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGS);
    std::string sxml = security_message_factory::makeThingListMessage(thingList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add thing list failed.\n");
        return -1;
    }
    printf("add thing list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   update_things
 * @Brief
 * @DateTime 2018-08-08T11:50:23+0800
 * @Modify   2018-08-08T11:50:23+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    thingList [description]
 * @return   [description]
 */
int security_viid::update_things(const char* ip, int port, std::vector<security_thing_object_t>& thingList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGS);
    std::string sxml = security_message_factory::makeThingListMessage(thingList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update thing list failed.\n");
        return -1;
    }
    printf("update thing list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   delete_things
 * @Brief
 * @DateTime 2018-08-08T11:50:51+0800
 * @Modify   2018-08-08T11:50:51+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_things(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGS);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete thing list failed.\n");
        return -1;
    }
    printf("delete thing list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   query_thing
 * @Brief
 * @DateTime 2018-08-08T11:51:28+0800
 * @Modify   2018-08-08T11:51:28+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_thing(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGSS);
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
        printf("get thing failed.\n");
        return -1;
    }
    printf("get thing success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Thing Object
    return 0;
}
/**
 * @Method   add_thing
 * @Brief
 * @DateTime 2018-08-08T11:52:14+0800
 * @Modify   2018-08-08T11:52:14+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    thingObj [description]
 * @return   [description]
 */
int security_viid::add_thing(const char* ip, int port, const security_thing_object_t* thingObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeThingMessage(thingObj);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add thing failed.\n");
        return -1;
    }
    printf("add thing success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Thing Object
    return 0;
}
/**
 * @Method   delete_thing
 * @Brief
 * @DateTime 2018-08-08T11:53:32+0800
 * @Modify   2018-08-08T11:53:32+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_thing(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_THINGSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete thing failed.\n");
        return -1;
    }
    printf("delete thing success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Thing Object
    return 0;
}
/**
 * @Method   query_scenes
 * @Brief
 * @DateTime 2018-08-08T11:59:22+0800
 * @Modify   2018-08-08T11:59:22+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_scenes(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENES);
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
        printf("get scene list failed.\n");
        return -1;
    }
    printf("get scene list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   add_scenes
 * @Brief
 * @DateTime 2018-08-08T12:00:09+0800
 * @Modify   2018-08-08T12:00:09+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    sceneList [description]
 * @return   [description]
 */
int security_viid::add_scenes(const char* ip, int port, std::vector<security_scene_object_t>& sceneList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENES);
    std::string sxml = security_message_factory::makeSceneListMessage(sceneList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add scene list failed.\n");
        return -1;
    }
    printf("add scene list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   update_scene
 * @Brief
 * @DateTime 2018-08-08T12:01:57+0800
 * @Modify   2018-08-08T12:01:57+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    sceneList [description]
 * @return   [description]
 */
int security_viid::update_scenes(const char* ip, int port, std::vector<security_scene_object_t>& sceneList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENES);
    std::string sxml = security_message_factory::makeSceneListMessage(sceneList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update scene list failed.\n");
        return -1;
    }
    printf("update scene list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   delete_scenes
 * @Brief
 * @DateTime 2018-08-08T12:03:05+0800
 * @Modify   2018-08-08T12:03:05+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_scenes(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENES);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete scene list failed.\n");
        return -1;
    }
    printf("delete scene list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   query_scene
 * @Brief
 * @DateTime 2018-08-08T12:04:03+0800
 * @Modify   2018-08-08T12:04:03+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_scene(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENESS);
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
        printf("get scene failed.\n");
        return -1;
    }
    printf("get scene success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Scene Object
    return 0;
}
/**
 * @Method   add_scene
 * @Brief
 * @DateTime 2018-08-08T12:05:08+0800
 * @Modify   2018-08-08T12:05:08+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    sceneObj [description]
 * @return   [description]
 */
int security_viid::add_scene(const char* ip, int port, const security_scene_object_t* sceneObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeSceneMessage(sceneObj);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add scene failed.\n");
        return -1;
    }
    printf("add scene success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Scene Object
    return 0;
}
/**
 * @Method   delete_scene
 * @Brief
 * @DateTime 2018-08-08T12:05:20+0800
 * @Modify   2018-08-08T12:05:20+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_scene(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SCENESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete scene failed.\n");
        return -1;
    }
    printf("delete scene success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Scene Object
    return 0;
}
/**
 * @Method   query_cases
 * @Brief
 * @DateTime 2018-08-08T12:10:07+0800
 * @Modify   2018-08-08T12:10:07+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_cases(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASES);
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
        printf("get case list failed.\n");
        return -1;
    }
    printf("get case list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   add_cases
 * @Brief
 * @DateTime 2018-08-08T12:00:09+0800
 * @Modify   2018-08-08T12:00:09+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    sceneList [description]
 * @return   [description]
 */
int security_viid::add_cases(const char* ip, int port, std::vector<security_case_object_t>& caseList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASES);
    std::string sxml = security_message_factory::makeCaseListMessage(caseList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add case list failed.\n");
        return -1;
    }
    printf("add case list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase 
    return 0;
}
/**
 * @Method   query_case
 * @Brief
 * @DateTime 2018-08-08T12:04:03+0800
 * @Modify   2018-08-08T12:04:03+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_case(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASESS);
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
        printf("get case failed.\n");
        return -1;
    }
    printf("get case success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Case Object
    return 0;
}
/**
 * @Method   add_case
 * @Brief
 * @DateTime 2018-08-08T12:05:08+0800
 * @Modify   2018-08-08T12:05:08+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    sceneObj [description]
 * @return   [description]
 */
int security_viid::add_case(const char* ip, int port, const security_case_object_t* caseObj) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeCaseMessage(caseObj);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add case failed.\n");
        return -1;
    }
    printf("add case success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Case Object
    return 0;
}
/**
 * @Method   delete_case
 * @Brief
 * @DateTime 2018-08-08T12:05:20+0800
 * @Modify   2018-08-08T12:05:20+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_case(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete case failed.\n");
        return -1;
    }
    printf("delete case success.\n");
    printf("response: %s\n", respData.c_str());
    // parse Case Object
    return 0;
}
/**
 * @Method   query_caseinfo
 * @Brief
 * @DateTime 2018-08-08T13:34:41+0800
 * @Modify   2018-08-08T13:34:41+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_caseinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASESS);
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
        printf("get case info failed.\n");
        return -1;
    }
    printf("get case info success.\n");
    printf("response: %s\n", respData.c_str());
    // parse FileInfo
    return 0;
}
/**
 * @Method   update_caseinfo
 * @Brief
 * @DateTime 2018-08-08T13:34:51+0800
 * @Modify   2018-08-08T13:34:51+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @param    caseInfo [description]
 * @return   [description]
 */
int security_viid::update_caseinfo(const char* ip, int port, const char* id, const security_case_info_t* caseInfo) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    suri.append(SECURITY_URL_PATH_S_INFO);
    std::string sxml = security_message_factory::makeCaseInfoMessage(caseInfo);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update case info failed.\n");
        return -1;
    }
    printf("update case info success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   delete_caseinfo
 * @Brief
 * @DateTime 2018-08-08T13:35:02+0800
 * @Modify   2018-08-08T13:35:02+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_caseinfo(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_CASESS);
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
        printf("delete case info failed.\n");
        return -1;
    }
    printf("delete case file success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   dispositions
 * @Brief
 * @DateTime 2018-08-08T13:40:39+0800
 * @Modify   2018-08-08T13:40:39+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    dispList [description]
 * @return   [description]
 */
int security_viid::dispositions(const char* ip, int port, std::vector<security_disposition_t>& dispList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPOSITIONS);
    std::string sxml = security_message_factory::makeCaseInfoMessage(dispList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("disposition failed.\n");
        return -1;
    }
    printf("disposition success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_disposition
 * @Brief
 * @DateTime 2018-08-08T13:44:01+0800
 * @Modify   2018-08-08T13:44:01+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_disposition(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPOSITIONS);
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
        printf("get disposition list failed.\n");
        return -1;
    }
    printf("get disposition list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   update_disposition
 * @Brief
 * @DateTime 2018-08-08T13:45:57+0800
 * @Modify   2018-08-08T13:45:57+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    dispList [description]
 * @return   [description]
 */
int security_viid::update_disposition(const char* ip, int port, std::vector<security_disposition_t>& dispList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPOSITIONS);
    std::string sxml = security_message_factory::makeDispositionMessage(dispList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update disposition failed.\n");
        return -1;
    }
    printf("update disposition success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   delete_disposition
 * @Brief
 * @DateTime 2018-08-08T13:46:52+0800
 * @Modify   2018-08-08T13:46:52+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_disposition(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPOSITIONS);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete disposition failed.\n");
        return -1;
    }
    printf("delete disposition success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   undispositions
 * @Brief
 * @DateTime 2018-08-08T13:49:53+0800
 * @Modify   2018-08-08T13:49:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::undispositions(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPOSITIONSS);
    suri.append(id);

    http_message hm;
    int ret = hm.put(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("undisposition failed.\n");
        return -1;
    }
    printf("undisposition success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   disposition_notifacations
 * @Brief
 * @DateTime 2018-08-08T13:57:33+0800
 * @Modify   2018-08-08T13:57:33+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    dispnotiList [description]
 * @return   [description]
 */
int security_viid::disposition_notifications(const char* ip, int port, std::vector<security_disposition_notify_t>& dispnotiList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPNOTI);
    std::string sxml = security_message_factory::makeDispositionNotifyMessage(dispnotiList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("disposition notification failed.\n");
        return -1;
    }
    printf("disposition notification success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_disposition_notifacation
 * @Brief
 * @DateTime 2018-08-08T13:57:28+0800
 * @Modify   2018-08-08T13:57:28+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_disposition_notification(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPNOTI);
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
        printf("get disposition notification list failed.\n");
        return -1;
    }
    printf("get disposition notification list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   delete_disposition_notification
 * @Brief
 * @DateTime 2018-08-08T13:59:46+0800
 * @Modify   2018-08-08T13:59:46+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_disposition_notification(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_DISPNOTI);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete disposition notification failed.\n");
        return -1;
    }
    printf("delete disposition notification success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   subscribes
 * @Brief
 * @DateTime 2018-08-08T14:03:22+0800
 * @Modify   2018-08-08T14:03:22+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    subscribeList [description]
 * @return   [description]
 */
int security_viid::subscribes(const char* ip, int port, std::vector<security_subscribe_t>& subscribeList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRIBES);
    std::string sxml = security_message_factory::makeSubscribeListMessage(subscribeList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("subscribe list failed.\n");
        return -1;
    }
    printf("subscribe list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_subscribes
 * @Brief
 * @DateTime 2018-08-08T14:05:53+0800
 * @Modify   2018-08-08T14:05:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_subscribes(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRIBES);
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
        printf("get subscribe list failed.\n");
        return -1;
    }
    printf("get subscribe list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   update_subscribes
 * @Brief
 * @DateTime 2018-08-08T14:07:16+0800
 * @Modify   2018-08-08T14:07:16+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    subscribeList [description]
 * @return   [description]
 */
int security_viid::update_subscribes(const char* ip, int port, std::vector<security_subscribe_t>& subscribeList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRIBES);
    std::string sxml = security_message_factory::makeSubscribeListMessage(subscribeList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update subscribe list failed.\n");
        return -1;
    }
    printf("update subscribe list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   delete_subscribes
 * @Brief
 * @DateTime 2018-08-08T14:07:53+0800
 * @Modify   2018-08-08T14:07:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_subscribes(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRIBES);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete subscribe list failed.\n");
        return -1;
    }
    printf("delete subscribe list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   unsubscribes
 * @Brief
 * @DateTime 2018-08-08T14:09:53+0800
 * @Modify   2018-08-08T14:09:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::unsubscribes(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRIBESS);
    suri.append(id);

    http_message hm;
    int ret = hm.put(suri.c_str());
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("undisposition failed.\n");
        return -1;
    }
    printf("undisposition success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   subscribe_notifications
 * @Brief
 * @DateTime 2018-08-08T14:16:02+0800
 * @Modify   2018-08-08T14:16:02+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    subscribenotiList [description]
 * @return   [description]
 */
int security_viid::subscribe_notifications(const char* ip, int port, std::vector<security_subscribe_notify_t>& subscribenotiList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRNOTI);
    std::string sxml = security_message_factory::makeDispositionNotifyMessage(subscribenotiList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("subscribe notification failed.\n");
        return -1;
    }
    printf("subscribe notification success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_subscribe_notifications
 * @Brief
 * @DateTime 2018-08-08T14:17:00+0800
 * @Modify   2018-08-08T14:17:00+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_subscribe_notifications(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRNOTI);
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
        printf("get subscribe notification list failed.\n");
        return -1;
    }
    printf("get subscribe notification list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   delete_subscribe_notifications
 * @Brief
 * @DateTime 2018-08-08T14:17:35+0800
 * @Modify   2018-08-08T14:17:35+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_subscribe_notifications(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_SUBSCRIBES);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete subscribe notification list failed.\n");
        return -1;
    }
    printf("delete subscribe notification list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_analysis_rules
 * @Brief
 * @DateTime 2018-08-08T14:20:31+0800
 * @Modify   2018-08-08T14:20:31+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    analysisRuleList [description]
 * @return   [description]
 */
int security_viid::query_analysis_rules(const char* ip, int port, std::vector<security_analysis_rule_t>& analysisRuleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULES);
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
        printf("get analysis rule list failed.\n");
        return -1;
    }
    printf("get analysis rule list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   add_analysis_rules
 * @Brief
 * @DateTime 2018-08-08T14:23:53+0800
 * @Modify   2018-08-08T14:23:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    analysisRuleList [description]
 * @return   [description]
 */
int security_viid::add_analysis_rules(const char* ip, int port, std::vector<security_analysis_rule_t>& analysisRuleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULES);
    if (!key || strlen(key) < 1) {
        printf("key invalid.\n");
        return -1;
    }
    std::string sxml = security_message_factory::makeAnalysisRuleListMessage(analysisRuleList);
    http_message hm;
    int ret = hm.get(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add analysis rule list failed.\n");
        return -1;
    }
    printf("add analysis rule list success.\n");
    printf("response: %s\n", respData.c_str());
    // pase  list
    return 0;
}
/**
 * @Method   update_analysis_rules
 * @Brief
 * @DateTime 2018-08-08T14:26:06+0800
 * @Modify   2018-08-08T14:26:06+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    analysisRuleList [description]
 * @return   [description]
 */
int security_viid::update_analysis_rules(const char* ip, int port, std::vector<security_analysis_rule_t>& analysisRuleList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULES);
    std::string sxml = security_message_factory::makeAnalysisRuleListMessage(analysisRuleList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update analysis rule list failed.\n");
        return -1;
    }
    printf("update analysis rule list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   delete_analysis_rules
 * @Brief
 * @DateTime 2018-08-08T14:27:02+0800
 * @Modify   2018-08-08T14:27:02+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_analysis_rules(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULES);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete analysis rule list failed.\n");
        return -1;
    }
    printf("delete analysis rule list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse ResponseStatus
    return 0;
}
/**
 * @Method   query_analysis_rule
 * @Brief
 * @DateTime 2018-08-08T14:32:23+0800
 * @Modify   2018-08-08T14:32:23+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_analysis_rule(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULESS);
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
        printf("get analysis rule failed.\n");
        return -1;
    }
    printf("get analysis rule success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   add_analysis_rule
 * @Brief
 * @DateTime 2018-08-08T14:34:04+0800
 * @Modify   2018-08-08T14:34:04+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    analysisRule [description]
 * @return   [description]
 */
int security_viid::add_analysis_rule(const char* ip, int port, security_analysis_rule_object_t* analysisRule) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeAnalysisRuleObjectMessage(analysisRule);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add analysis rule failed.\n");
        return -1;
    }
    printf("add analysis rule success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   update_analysis_rule
 * @Brief
 * @DateTime 2018-08-08T14:35:01+0800
 * @Modify   2018-08-08T14:35:01+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    analysisRule [description]
 * @return   [description]
 */
int security_viid::update_analysis_rule(const char* ip, int port, security_analysis_rule_object_t* analysisRule) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULESS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeAnalysisRuleObjectMessage(analysisRule);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update analysis rule failed.\n");
        return -1;
    }
    printf("update analysis rule success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   delete_analysis_rule
 * @Brief
 * @DateTime 2018-08-08T14:35:56+0800
 * @Modify   2018-08-08T14:35:56+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_analysis_rule(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_ANALYSISRULESS);
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
        printf("delete analysis rule failed.\n");
        return -1;
    }
    printf("delete analysis rule success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   query_video_labels
 * @Brief
 * @DateTime 2018-08-08T14:45:43+0800
 * @Modify   2018-08-08T14:45:43+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    key [description]
 * @param    value [description]
 * @return   [description]
 */
int security_viid::query_video_labels(const char* ip, int port, const char* key, const char* value) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELS);
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
        printf("get video label list failed.\n");
        return -1;
    }
    printf("get video label list success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   add_video_labels
 * @Brief
 * @DateTime 2018-08-08T14:45:53+0800
 * @Modify   2018-08-08T14:45:53+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    videoLabel [description]
 * @return   [description]
 */
int security_viid::add_video_labels(const char* ip, int port, std::vector<security_video_label_t>& videoLabelList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeVideoLabelListMessage(videoLabelList);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add video label failed.\n");
        return -1;
    }
    printf("add video label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   update_video_labels
 * @Brief
 * @DateTime 2018-08-08T14:46:25+0800
 * @Modify   2018-08-08T14:46:25+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    videoLabel [description]
 * @return   [description]
 */
int security_viid::update_video_labels(const char* ip, int port, std::vector<security_video_label_t>& videoLabelList) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeVideoLabelListMessage(videoLabelList);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update video label failed.\n");
        return -1;
    }
    printf("update video label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   delete_video_labels
 * @Brief
 * @DateTime 2018-08-08T14:46:32+0800
 * @Modify   2018-08-08T14:46:32+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    idList [description]
 * @param    values [description]
 * @return   [description]
 */
int security_viid::delete_video_labels(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELS);
    std::string condi;

    http_message hm;
    int ret = hm.del(suri.c_str(), condi);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("delete video label failed.\n");
        return -1;
    }
    printf("delete video label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   query_video_label
 * @Brief
 * @DateTime 2018-08-08T14:53:04+0800
 * @Modify   2018-08-08T14:53:04+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::query_video_label(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELSS);
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
        printf("get video label failed.\n");
        return -1;
    }
    printf("get videl label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   add_video_label
 * @Brief
 * @DateTime 2018-08-08T14:53:16+0800
 * @Modify   2018-08-08T14:53:16+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    videoLabel [description]
 * @return   [description]
 */
int security_viid::add_video_label(const char* ip, int port, security_video_label_t* videoLabel) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeVideoLabelMessage(videoLabel);

    http_message hm;
    int ret = hm.post(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("add video label failed.\n");
        return -1;
    }
    printf("add videl label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   update_video_label
 * @Brief
 * @DateTime 2018-08-08T14:53:28+0800
 * @Modify   2018-08-08T14:53:28+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    videoLabel [description]
 * @return   [description]
 */
int security_viid::update_video_label(const char* ip, int port, security_video_label_t* videoLabel) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELSS);
    if (!id || strlen(id) < 1) {
        printf("ID invalid.\n");
        return -1;
    }
    suri.append(id);
    std::string sxml = security_message_factory::makeVideoLabelMessage(videoLabel);

    http_message hm;
    int ret = hm.put(suri.c_str(), sxml);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("update video label failed.\n");
        return -1;
    }
    printf("update videl label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
}
/**
 * @Method   delete_video_label
 * @Brief
 * @DateTime 2018-08-08T14:53:44+0800
 * @Modify   2018-08-08T14:53:44+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    id [description]
 * @return   [description]
 */
int security_viid::delete_video_label(const char* ip, int port, const char* id) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIID_VIDEOLABELSS);
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
        printf("delete video label failed.\n");
        return -1;
    }
    printf("delete videl label success.\n");
    printf("response: %s\n", respData.c_str());
    // parse 
    return 0;
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
