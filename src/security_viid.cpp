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



/**
 * @Method   makeRegisterMessage
 * @Brief
 * @DateTime 2018-08-04T12:15:12+0800
 * @Modify   2018-08-04T12:15:12+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
std::string security_viid::makeRegisterMessage(const char* deviceId) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "Register");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", deviceId);
    sx.addProperity(node1, "type", "DeviceIdType");
    sx.addProperity(node1, "use", "required");
    std::string sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeUnregisterMessage
 * @Brief
 * @DateTime 2018-08-04T12:15:12+0800
 * @Modify   2018-08-04T12:15:12+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
std::string security_viid::makeUnregisterMessage(const char* deviceId) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "UnRegister");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", deviceId);
    sx.addProperity(node1, "type", "DeviceIdType");
    sx.addProperity(node1, "use", "required");
    std::string sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeKeepaliveMessage
 * @Brief
 * @DateTime 2018-08-04T12:15:12+0800
 * @Modify   2018-08-04T12:15:12+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
std::string security_viid::makeKeepaliveMessage(const char* deviceId) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "Keepalive");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", deviceId);
    sx.addProperity(node1, "type", "DeviceIdType");
    sx.addProperity(node1, "use", "required");
    std::string sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeAPEListMessage
 * @Brief
 * @DateTime 2018-08-04T14:24:49+0800
 * @Modify   2018-08-04T14:24:49+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
std::string security_viid::makeAPEListMessage(int minOccurs) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "APEList");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "APEObject");
    sx.addProperity(node1, "type", "APE");
    sx.addProperity(node1, "minOccurs", num2String(minOccurs));
    std::string sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeVideoSliceListMessage
 * @Brief
 * @DateTime 2018-08-06T11:18:46+0800
 * @Modify   2018-08-06T11:18:46+0800
 * @Author   Anyz
 * @param    minOccurs [description]
 * @param    maxOccurs [description]
 * @return   [description]
 */
std::string security_viid::makeVideoSliceListMessage(int minOccurs, int maxOccurs) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "VideoSliceList");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "VideoSlice");
    sx.addProperity(node1, "type", "VideoSliceInfo");
    sx.addProperity(node1, "minOccurs", num2String(minOccurs));
    sx.addProperity(node1, "maxOccurs", num2String(maxOccurs));

    XMLNodeHandle node2 = sx.createChild(node, "element");
    sx.addProperity(node2, "name", "PersonList");
    sx.addProperity(node2, "minOccurs", num2String(minOccurs));
    sx.addProperity(node2, "maxOccurs", num2String(maxOccurs));
    XMLNodeHandle node3 = sx.createChild(node, "element");
    sx.addProperity(node3, "name", "FaceList");
    sx.addProperity(node3, "minOccurs", num2String(minOccurs));
    sx.addProperity(node3, "maxOccurs", num2String(maxOccurs));
    XMLNodeHandle node4 = sx.createChild(node, "element");
    sx.addProperity(node4, "name", "MotorVehicleList");
    sx.addProperity(node4, "minOccurs", num2String(minOccurs));
    sx.addProperity(node4, "maxOccurs", num2String(maxOccurs));
    XMLNodeHandle node5 = sx.createChild(node, "element");
    sx.addProperity(node5, "name", "NonMotorVehicleList");
    sx.addProperity(node5, "minOccurs", num2String(minOccurs));
    sx.addProperity(node5, "maxOccurs", num2String(maxOccurs));
    XMLNodeHandle node6 = sx.createChild(node, "element");
    sx.addProperity(node6, "name", "ThingList");
    sx.addProperity(node6, "minOccurs", num2String(minOccurs));
    sx.addProperity(node6, "maxOccurs", num2String(maxOccurs));
    XMLNodeHandle node7 = sx.createChild(node, "element");
    sx.addProperity(node7, "name", "SceneList");
    sx.addProperity(node7, "minOccurs", num2String(minOccurs));
    sx.addProperity(node7, "maxOccurs", num2String(maxOccurs));

    XMLNodeHandle node8 = sx.createChild(node, "element");
    sx.addProperity(node8, "name", "Data");
    sx.addProperity(node8, "type", "base64Binary");
    sx.addProperity(node8, "minOccurs", num2String(minOccurs));
    sx.addProperity(node8, "maxOccurs", num2String(maxOccurs));

    std::string sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
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
    std::string sxml = makeRegisterMessage(deviceId);
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
    std::string sxml = makeUnregisterMessage(deviceId);
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
    std::string sxml = makeKeepaliveMessage(deviceId);
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
    if (!key || strlen(key) < 5) {
        printf("IP address invalid.\n");
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
    std::string sxml = makeAPEListMessage(deviceId);
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
    if (!key || strlen(key) < 5) {
        printf("IP address invalid.\n");
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
    if (!key || strlen(key) < 5) {
        printf("IP address invalid.\n");
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
    if (!key || strlen(key) < 5) {
        printf("IP address invalid.\n");
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
    if (!key || strlen(key) < 5) {
        printf("IP address invalid.\n");
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
    std::string sxml = makeVideoSliceListMessage(deviceId);
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
    std::string sxml = makeVideoSliceListMessage(deviceId);
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
int security_viid::delete_videodata() {
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

std::string security_viid::queryCondition(const char* key, const char* value) {
    std::string s = "?";
    s.append(key);
    s.append("=");
    s.append(value);
    return s;
}






