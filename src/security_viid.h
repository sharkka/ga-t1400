/**
 * @File     security_viid.h
 * @brief    
 * @DateTime 2018/8/3 19:06:15
 * @Author   Anyz
 */
#ifndef __SECURITY_VIID_H_
#define __SECURITY_VIID_H_



/**
 * @Class    security_viid
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
class security_viid {
public:
    int    sys_register(const char* ip, int port, const char* deviceId);
    int    sys_unregister(const char* ip, int port, const char* deviceId);
    int    sys_keepalive(const char* ip, int port, const char* deviceId);
    int    sys_synctime(const char* ip, int port);
    int    query_apes(const char* ip, int port, const char* key, const char* value);
    int    update_apes(const char* ip, int port);
    int    query_apss(const char* ip, int port, const char* key, const char* value);
    int    query_tollgates(const char* ip, int port, const char* key, const char* value);
    int    query_lanes(const char* ip, int port, const char* key, const char* value);
    int    query_video_slices(const char* ip, int port, const char* key, const char* value);
    int    add_video_slices(const char* ip, int port, const char* id, const char* deviceId);
    int    query_video_slice(const char* ip, int port, const char* id);
    int    update_video_slice(const char* ip, int port, const char* id, const char* deviceId);
    int    delete_video_slice(const char* ip, int port, const char* id);
    int    query_videodata();
    int    add_videodata();
    int    delete_videodata();
    int    query_images();
    int    add_images();
    int    query_image();
    int    add_image();
    int    query_imageinfo();
    int    add_imageinfo();
    int    delete_imageinfo();
    int    query_imagedata();
    int    add_imagedata();
    int    delete_imagedata();
    int    query_files();
    int    add_files();
    int    query_file();
    int    add_file();
    int    query_fileinfo();
    int    add_fileinfo();
    int    delete_fileinfo();
    int    query_filedata();
    int    add_filedata();
    int    delete_filedata();
    int    query_persons();
    int    add_persons();
    int    delete_persons();
    int    query_person();
    int    add_person();
    int    delete_person();
    int    query_faces();
    int    add_faces();
    int    delete_faces();
    int    query_face();
    int    add_face();
    int    delete_face();
    int    query_vehicles();
    int    add_vehicles();
    int    delete_vehicles();
    int    query_vehicle();
    int    add_vehicle();
    int    delete_vehicles();
    int    query_novehicles();
    int    add_nonvehicles();
    int    delete_nonvehicles();
    int    query_nonvehicle();
    int    add_nonvehicle();
    int    delete_nonvehicle();
    int    query_things();
    int    add_things();
    int    delete_things();
    int    query_thing();
    int    insert_thing();
    int    delete_thing();
    int    query_scenes();
    int    add_scenes();
    int    delete_scenes();
    int    query_scene();
    int    add_scene();
    int    delete_scene();
    int    query_cases();
    int    add_cases();
    int    delete_cases();
    int    query_case();
    int    add_case();
    int    delete_case();
    int    query_caseinfo();
    int    add_caseinfo();
    int    delete_caseinfo();
    int    dispositions();
    int    query_disposition();
    int    update_disposition();
    int    delete_disposition();
    int    undispostions();
    int    disposition_notifications();
    int    query_disposition_notification();
    int    delete_disposition_notification();
    int    subscribes();
    int    query_subscribes();
    int    update_subscribes();
    int    delete_subscribes();
    int    unsubscribes();
    int    subscribe_notifications();
    int    query_subscribe_notifications();
    int    update_subscribe_notifications();
    int    delete_subscribe_notifications();
    int    query_analysis_rules();
    int    add_analysis_rules();
    int    update_analysis_rules();
    int    delete_analysis_rules();
    int    query_analysis_rule();
    int    add_analysis_rule();
    int    update_analysis_rule();
    int    delete_analysis_rule();
    int    query_video_labels();
    int    add_video_labels();
    int    update_video_labels();
    int    delete_video_labels();
    int    query_video_label();
    int    add_video_label();
    int    update_video_label();
    int    delete_video_label();
    
private:
    const char* num2String(int port) {static char buff[32]={0}; sprintf(buff, "%d", port); return buff;}
    std::string queryCondition(const char* key, const char* value);

    std::string addressPrefix(const char* ip, int port);
    std::string makeRegisterMessage(const char* deviceId);
    std::string makeUnregisterMessage(const char* deviceId);
    std::string makeKeepaliveMessage(const char* deviceId);
};


#endif
