/**
 * @File     security_vias.cpp
 * @brief    
 * @DateTime 2018/8/4 11:36:40
 * @Author   Anyz
 */
#include "security_message_factory.h"
#include "security_vias.h"
#include "security_rest.h"
#include "http_message.h"

/**
 * @Method   sys_register
 * @Brief
 * @DateTime 2018-08-09T10:51:05+0800
 * @Modify   2018-08-09T10:51:05+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_vias::sys_register(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_REGISTER);
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
        int ret = hm.post(suri, sxml);
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
 * @DateTime 2018-08-09T10:51:30+0800
 * @Modify   2018-08-09T10:51:30+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_vias::sys_unregister(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_UNREGISTER);
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
 * @DateTime 2018-08-09T10:51:46+0800
 * @Modify   2018-08-09T10:51:46+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @param    deviceId [description]
 * @return   [description]
 */
int security_vias::sys_keepalive(const char* ip, int port, const char* deviceId) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_KEEPALIVE);
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
 * @DateTime 2018-08-09T10:51:56+0800
 * @Modify   2018-08-09T10:51:56+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
int security_vias::sys_synctime(const char* ip, int port) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_TIME);

    http_message hm;
    int ret = hm.get(suri, SECURITY_STRING_EMPTY);
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

int security_vias::add_tasks(const char* ip, int port, security_tasks_t& taskList) {
    return 0;
}

int security_vias::query_task(const char* ip, int port, attr_conditions_t& conditions) {
    return 0;
}

int security_vias::update_task(const char* ip, int port, security_tasks_t& taskList) {
    return 0;
}

int security_vias::delete_task(const char* ip, int port, security_idlist_t& idList, std::string values) {
    return 0;
}

int security_vias::add_task_controls(const char* ip, int port, security_task_controls_t& taskControlList) {
    return 0;
}

int security_vias::task_statuses(const char* ip, int port, const char* key, const char* value) {
    return 0;
}

int security_vias::add_videoslices(const char* ip, int port, security_videoslices_t& videoSliceList) {
    return 0;
}

int security_vias::query_videoslices(const char* ip, int port, attr_conditions_t& conditions) {
    return 0;
}

int security_vias::add_videoslices_data(const char* ip, int port, const char* taskid, const char* vsid, const char* buff) {
    return 0;
}

int security_vias::query_videoslices_data(const char* ip, int port, const char* taskid, const char* vsid, char** buff) {
    return 0;
}

int security_vias::delete_videoslices_data(const char* ip, int port, const char* taskid, const char* vsid) {
    return 0;
}

int security_vias::add_images(const char* ip, int port, const char* taskid, security_images_t& imageList) {
    return 0;
}

int security_vias::query_images(const char* ip, int port, const char* taskid, attr_conditions_t& conditions) {
    return 0;
}

int security_vias::add_images_data(const char* ip, int port, const char* taskid, const char* imageid, const char* buff) {
    return 0;
}

int security_vias::query_images_data(const char* ip, int port, const char* taskid, const char* imageid, const char** buff) {
    return 0;
}

int security_vias::delete_images_data(const char* ip, int port, const char* taskid, const char* imageid) {
    return 0;
}

int security_vias::add_video_labels(const char* ip, int port, const char* taskid, security_videolabel_all_contents_t& allContents) {
    return 0;
}

int security_vias::query_video_labels(const char* ip, int port, const char* taskid, attr_conditions_t& conditions) {
    return 0;
}

int security_vias::add_analysis_rules(const char* ip, int port, security_analysis_rules_t& analysisRules) {
    return 0;
}

int security_vias::query_analysis_rules(const char* ip, int port, attr_conditions_t& conditions) {
    return 0;
}

int security_vias::update_analysis_rules(const char* ip, int port, security_analysis_rules_t& analysisRules) {
    return 0;
}

int security_vias::delete_analysis_rules(const char* ip, int port, std::vector<std::string>& idList, std::string values) {
    return 0;
}
/**
 * @Method   sys_query_analysis_capability
 * @Brief
 * @DateTime 2018-08-09T11:38:13+0800
 * @Modify   2018-08-09T11:38:13+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    suri [description]
 * @return   [description]
 */
int security_vias::sys_query_analysis_capability(const char* ip, int port) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_SYSCAPA_ANALCAPA);

    http_message hm;
    int ret = hm.get(suri);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get analysis capability failed.\n");
        return -1;
    }

    printf("get analysis capability success.\n");
    printf("response: %s\n", respData.c_str());
    // 
    return 0;
}
/**
 * @Method   sys_query_enhancement_and_restoration_capability
 * @Brief
 * @DateTime 2018-08-09T11:38:02+0800
 * @Modify   2018-08-09T11:38:02+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    suri [description]
 * @return   [description]
 */
int security_vias::sys_query_enhancement_and_restoration_capability(const char* ip, int port) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_SYSCAPA_ENHAN_AND_RESTORCAPA);

    http_message hm;
    int ret = hm.get(suri);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get enhancement and restoration capability failed.\n");
        return -1;
    }

    printf("get enhancement and restoration capability success.\n");
    printf("response: %s\n", respData.c_str());
    // 
    return 0;
}
/**
 * @Method   sys_query_retrieval_capability
 * @Brief
 * @DateTime 2018-08-09T11:37:52+0800
 * @Modify   2018-08-09T11:37:52+0800
 * @Author   Anyz
 * @param    ip [description]
 * @param    suri [description]
 * @return   [description]
 */
int security_vias::sys_query_retrieval_capability(const char* ip, int port) {
    std::string suri = addressPrefix(ip, port);
    if (suri.empty()) {
        printf("address incorrect.\n");
        return -1;
    }
    suri.append(SECURITY_URL_PATH_VIAS_SYSCAPA_RETRIEVALCAPA);

    http_message hm;
    int ret = hm.get(suri);
    std::string respData;
    respData = hm.message();
    if (SECURITY_REST_HTTP_RESPONSE_200 != hm.errorCode()) {
        printf("get retrieval capability failed.\n");
        return -1;
    }

    printf("get retrieval capability success.\n");
    printf("response: %s\n", respData.c_str());
    // 
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
std::string security_vias::addressPrefix(const char* ip, int port) {
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
std::string security_vias::queryCondition(const char* key, const char* value) {
    std::string s = "?";
    s.append(key);
    s.append("=");
    s.append(value);
    return s;
}
