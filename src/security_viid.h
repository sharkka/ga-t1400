/**
 * @File     security_viid.h
 * @brief    
 * @DateTime 2018/8/3 19:06:15
 * @Author   Anyz
 */
#ifndef __SECURITY_VIID_H_
#define __SECURITY_VIID_H_

#include <vector>

#include "security_message_factory.h"


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
    int    update_apes(const char* ip, int port, const char* deviceId);
    int    query_apss(const char* ip, int port, const char* key, const char* value);
    int    query_tollgates(const char* ip, int port, const char* key, const char* value);
    int    query_lanes(const char* ip, int port, const char* key, const char* value);
    int    query_video_slices(const char* ip, int port, const char* key, const char* value);
    int    add_video_slices(const char* ip, int port, const char* deviceId);
    int    query_video_slice(const char* ip, int port, const char* id);
    int    update_video_slice(const char* ip, int port, const char* id, const char* deviceId);
    int    delete_video_slice(const char* ip, int port, const char* id);
    int    query_videodata(const char* ip, int port, const char* id);
    int    add_videodata(const char* ip, int port, const char* id, const char* buff);
    int    delete_videodata(const char* ip, int port, const char* id);
    int    query_images(const char* ip, int port, const char* key, const char* value);
    int    add_images(const char* ip, int port, std::vector<security_image_t>& imageList);
    int    query_image(const char* ip, int port, const char* id);
    int    update_image(const char* ip, int port, const char* id, const security_image_t* imageObject);
    int    delete_image(const char* ip, int port, const char* id);
    int    query_imageinfo(const char* ip, int port, const char* id);
    int    update_imageinfo(const char* ip, int port, const char* id, const security_image_info_t* info);
    int    delete_imageinfo(const char* ip, int port, const char* id);
    int    query_imagedata(const char* ip, int port, const char* id);
    int    add_imagedata(const char* ip, int port, const char* id, const char* buff);
    int    delete_imagedata(const char* ip, int port, const char* id);
    int    query_files(const char* ip, int port, const char* key, const char* value);
    int    update_files(const char* ip, int port, std::vector<security_image_t>& imgList);
    int    query_file(const char* ip, int port, const char* id);
    int    update_file(const char* ip, int port, const char* id, const security_file_t* fileObj);
    int    delete_file(const char* ip, int port, const char* id);
    int    query_fileinfo(const char* ip, int port, const char* id);
    int    update_fileinfo(const char* ip, int port, const char* id, const security_file_info_t* fileInfo);
    int    delete_fileinfo(const char* ip, int port, const char* id);
    int    query_filedata(const char* ip, int port, const char* id);
    int    add_filedata(const char* ip, int port, const char* id, const char* buff);
    int    delete_filedata(const char* ip, int port, const char* id);
    int    query_persons(const char* ip, int port, const char* key, const char* value);
    int    add_persons(const char* ip, int port, std::vector<security_person_t>& personList);
    int    update_persons(const char* ip, int port, std::vector<security_person_t>& personList);
    int    delete_persons(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_person(const char* ip, int port, const char* id);
    int    update_person(const char* ip, int port, const char* id, const security_person_t* personObj);
    int    delete_person(const char* ip, int port, const char* id);
    int    query_faces(const char* ip, int port, const char* key, const char* value);
    int    update_faces(const char* ip, int port, std::vector<security_face_t>& faceList);
    int    delete_faces(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_face(const char* ip, int port, const char* id);
    int    update_face(const char* ip, int port, const char* id, const security_face_t* faceObj);
    int    delete_face(const char* ip, int port, const char* id);
    int    query_motorvehicles(const char* ip, int port, const char* key, const char* value);
    int    add_motorvehicles(const char* ip, int port, std::vector<security_motorvehicle_t>& motorvehicleList);
    int    update_motorvehicles(const char* ip, int port, std::vector<security_motorvehicle_t>& motorvehicleList);
    int    delete_motorvehicles(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_motorvehicle(const char* ip, int port, const char* id);
    int    add_motorvehicle(const char* ip, int port, const char* id, const security_motorvehicle_t* vehicleObj);
    int    delete_motorvehicle(const char* ip, int port, const char* id);
    int    query_nonmotorvehicles(const char* ip, int port, const char* key, const char* value);
    int    add_nonmotorvehicles(const char* ip, int port, std::vector<security_nonmotorvehicle_t>& nvehicleList);
    int    update_nonmotorvehicles(const char* ip, int port, std::vector<security_nonmotorvehicle_t>& nvehicleList);
    int    delete_nonmotorvehicles(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_nonmotorvehicle(const char* ip, int port, const char* id);
    int    add_nonmotorvehicle(const char* ip, int port, const char* id, const security_nonmotorvehicle_t* nvehicleObj);
    int    delete_nonmotorvehicle(const char* ip, int port, const char* id);
    int    query_things(const char* ip, int port, const char* key, const char* value);
    int    add_things(const char* ip, int port, std::vector<security_thing_t>& thingList);
    int    update_things(const char* ip, int port, std::vector<security_thing_t>& thingList);
    int    delete_things(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_thing(const char* ip, int port, const char* id);
    int    add_thing(const char* ip, int port, const char* id, const security_thing_t* thingObj);
    int    delete_thing(const char* ip, int port, const char* id);
    int    query_scenes(const char* ip, int port, const char* key, const char* value);
    int    add_scenes(const char* ip, int port, std::vector<security_scene_t>& sceneList);
    int    update_scenes(const char* ip, int port, std::vector<security_scene_t>& sceneList);
    int    delete_scenes(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_scene(const char* ip, int port, const char* id);
    int    add_scene(const char* ip, int port, const char* id, const security_scene_t* sceneObj);
    int    delete_scene(const char* ip, int port, const char* id);
    int    query_cases(const char* ip, int port, const char* key, const char* value);
    int    add_cases(const char* ip, int port, std::vector<security_case_t>& caseList);
    int    query_case(const char* ip, int port, const char* id);
    int    add_case(const char* ip, int port, const char* id, const security_case_t* caseObj);
    int    delete_case(const char* ip, int port, const char* id);
    int    query_caseinfo(const char* ip, int port, const char* id);
    int    update_caseinfo(const char* ip, int port, const char* id, const security_caseinfo_t* caseInfo);
    int    delete_caseinfo(const char* ip, int port, const char* id);
    int    dispositions(const char* ip, int port, std::vector<security_disposition_t>& dispList);
    int    query_disposition(const char* ip, int port, const char* key, const char* value);
    int    update_disposition(const char* ip, int port, security_disposition_t* disp);
    int    delete_disposition(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    undispositions(const char* ip, int port, const char* id);
    int    disposition_notifications(const char* ip, int port, std::vector<security_disposition_notify_t>& dispnotiList);
    int    query_disposition_notification(const char* ip, int port, const char* key, const char* value);
    int    delete_disposition_notification(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    subscribes(const char* ip, int port, std::vector<security_subscribe_t>& subscribeList);
    int    query_subscribes(const char* ip, int port, const char* key, const char* value);
    int    delete_subscribes(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    unsubscribes(const char* ip, int port, const char* id);
    int    subscribe_notifications(const char* ip, int port, std::vector<security_subscribe_notify_t>& subscribenotiList);
    int    query_subscribe_notifications(const char* ip, int port, const char* key, const char* value);
    int    delete_subscribe_notifications(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_analysis_rules(const char* ip, int port, const char* key, const char* value);
    int    add_analysis_rules(const char* ip, int port, std::vector<security_analysis_rule_t>& analysisRuleList);
    int    update_analysis_rules(const char* ip, int port, std::vector<security_analysis_rule_t>& analysisRuleList);
    int    delete_analysis_rules(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_analysis_rule(const char* ip, int port, const char* id);
    int    add_analysis_rule(const char* ip, int port, const char* id, security_analysis_rule_t* analysisRule);
    int    update_analysis_rule(const char* ip, int port, const char* id, security_analysis_rule_t* analysisRule);
    int    delete_analysis_rule(const char* ip, int port, const char* id);
    int    query_video_labels(const char* ip, int port, const char* key, const char* value);
    int    add_video_labels(const char* ip, int port, std::vector<security_videolabel_t>& videoLabelList);
    int    update_video_labels(const char* ip, int port, std::vector<security_videolabel_t>& videoLabelList);
    int    delete_video_labels(const char* ip, int port, std::vector<std::string>& idList, std::string values);
    int    query_video_label(const char* ip, int port, const char* id);
    int    add_video_label(const char* ip, int port, const char* id, security_videolabel_t* videoLabel);
    int    update_video_label(const char* ip, int port, const char* id, security_videolabel_t* videoLabel);
    int    delete_video_label(const char* ip, int port, const char* id);
    
private:
    const char* num2String(int port) {static char buff[32]={0}; sprintf(buff, "%d", port); return buff;}
    std::string queryCondition(const char* key, const char* value);

    std::string addressPrefix(const char* ip, int port);
};


#endif
