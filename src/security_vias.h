/**
 * @File     security_vias.h
 * @brief    
 * @DateTime 2018/8/3 19:06:15
 * @Author   Anyz
 */
#ifndef __SECURITY_VIAS_H_
#define __SECURITY_VIAS_H_

#include "security_message_factory.h"

/**
 * @Class    security_vias
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
class security_vias {
public:
    int    sys_register(const char* ip, int port, const char* deviceId);
    int    sys_unregister(const char* ip, int port, const char* deviceId);
    int    sys_keepalive(const char* ip, int port, const char* deviceId);
    int    sys_synctime(const char* ip, int port);

    int    add_tasks(const char* ip, int port, security_tasks_t& taskList);
    int    query_task(const char* ip, int port, attr_conditions_t& conditions);
    int    update_task(const char* ip, int port, security_tasks_t& taskList);
    int    delete_task(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    add_task_controls(const char* ip, int port, security_task_controls_t& taskControlList);
    int    task_start();
    int    task_pause();
    int    task_stop();
    int    task_statuses(const char* ip, int port, const char* key, const char* value);
    int    add_videoslices(const char* ip, int port, security_videoslices_t& videoSliceList);
    int    query_videoslices(const char* ip, int port, attr_conditions_t& conditions);
    int    add_videoslices_data(const char* ip, int port, const char* taskid, const char* vsid, const char* buff);
    int    query_videoslices_data(const char* ip, int port, const char* taskid, const char* vsid, char** buff);
    int    delete_videoslices_data(const char* ip, int port, const char* taskid, const char* vsid);
    int    add_images(const char* ip, int port, const char* taskid, security_images_t& imageList);
    int    query_images(const char* ip, int port, const char* taskid, attr_conditions_t& conditions);
    int    add_images_data(const char* ip, int port, const char* taskid, const char* imageid, const char* buff);
    int    query_images_data(const char* ip, int port, const char* taskid, const char* imageid, const char** buff);
    int    delete_images_data(const char* ip, int port, const char* taskid, const char* imageid);
    int    add_video_labels(const char* ip, int port, const char* taskid, security_videolabel_all_contents_t& allContents);
    int    query_video_labels(const char* ip, int port, const char* taskid, attr_conditions_t& conditions);
    int    add_analysis_rules(const char* ip, int port, security_analysis_rules_t& analysisRules);
    int    query_analysis_rules(const char* ip, int port, attr_conditions_t& conditions);
    int    update_analysis_rules(const char* ip, int port, security_analysis_rules_t& analysisRules);
    int    delete_analysis_rules(const char* ip, int port, security_idlist_t& idList, std::string values);

    int    sys_query_analysis_capability(const char* ip, int port);
    int    sys_query_enhancement_and_restoration_capability(const char* ip, int port);
    int    sys_query_retrieval_capability(const char* ip, int port);
    

private:
    const char* num2String(int port) {static char buff[32]={0}; sprintf(buff, "%d", port); return buff;}
    std::string queryCondition(const char* key, const char* value);
    std::string addressPrefix(const char* ip, int port);
};


#endif
