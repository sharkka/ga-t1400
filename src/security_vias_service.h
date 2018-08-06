/**
 * @File     security_vias_service.h
 * @brief    
 * @DateTime 2018/8/3 19:06:15
 * @Author   Anyz
 */
#ifndef __SECURITY_VIAS_SERVICE_H_
#define __SECURITY_VIAS_SERVICE_H_



/**
 * @Class    security_vias_service
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
class security_vias_service {
public:
    int    sys_register();
    int    sys_unregister();
    int    sys_keepalive();
    int    sys_sync_time();
    int    add_tasks();
    int    query_task();
    int    update_task();
    int    delete_task();
    int    add_task_controls();
    int    task_start();
    int    task_pause();
    int    task_stop();
    int    task_statuses();
    int    add_videoslices(int taskid);
    int    query_videoslices(int taskid);
    int    add_videoslices_file(int taskid, int vsid);
    int    query_videoslices_file(int taskid, int vsid);
    int    delete_videoslices_file(int taskid, int vsid);
    int    add_images(int taskid);
    int    query_images(int taskid);
    int    add_images_data(int taskid);
    int    query_images_data(int taskid);
    int    delete_images_data(int taskid);
    int    add_video_labels(int taskid);
    int    query_video_labels(int taskid);
    int    add_analysis_rules();
    int    query_analysis_rules();
    int    update_analysis_rules();
    int    delete_analysis_rules();

    int    sys_query_capability_analysis_capability();
    int    sys_query_capability_enhancement_and_restoration_capability();
    int    sys_query_retrieval_capability();
    

private:
    const char* port2String(int port) {static char buff[8]={0}; sprintf(buff, "%d", port); return buff;}
    std::string makeRegisterMessage(const char* deviceId);
};


#endif
