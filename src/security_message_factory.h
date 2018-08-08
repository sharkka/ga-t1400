/**
 * @File     security_message_factory.h
 * @brief    
 * @DateTime 2018/8/3 19:06:15
 * @Author   Anyz
 */
#ifndef __SECURITY_MESSAGE_FACTORY_H_
#define __SECURITY_MESSAGE_FACTORY_H_

#include <string>
#include <vector>

/**
 * @Struct   security_image_info_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_image_info {
    std::string imageId;
    std::string infoKind;
    std::string imageSource;
    std::string sourceVideoId;
    std::string originImageId;
    std::string eventSort;
    std::string deviceId;
    std::string storagePath;
    std::string fileHash;
    std::string shotTime;
    std::string title;
    std::string titleNote;
    std::string specialName;
    std::string keyword;
    std::string contentDescription;
    std::string subjectCharacter;
    std::string shotPlaceFullAddress;
    double      shotPlaceLongitude;
    double      shotPlaceLatitude;
    std::string HorizontalShotDirection;
    std::string VerticalShotDirection;
    std::string securityLevel;
    int         width;
    int         height;
    std::string cameraManufacturer;
    std::string cameraVersion;
    int         apertureValue;
    int         isoSensitivity;
    int         focalLength;
    std::string qualityGrade;
    std::string collectorName;
    std::string collectorOrg;
    std::string collectorIdType;
    std::string collectorId;
    std::string entryClrk;
    std::string entryClrkOrg;
    std::string entryClrkIdType;
    std::string entryTime;
    std::string imageProcFlag;
    int         fileSize;
} security_image_info_t;
/**
 * @Struct   security_file_object_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_file_object {
    std::string fileId;
    std::string infoKind;
    std::string source;
    std::string filenName;
    std::string storagePath;
    std::string fileHash;
    std::string fileFormat;
    std::string title;
    std::string securityLevel;
    std::string submiterName;
    std::string submiterOrg;
    std::string entryTime;
    int         fileSize;
} security_file_object_t;
/**
 * @Struct   security_file_info_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_file_info {
    std::string fileId;
    std::string infoKind;
    std::string source;
    std::string filenName;
    std::string storagePath;
    std::string fileHash;
    std::string fileFormat;
    std::string title;
    std::string securityLevel;
    std::string submiterName;
    std::string submiterOrg;
    std::string entryTime;
    int         fileSize;
} security_file_info_t;
/**
 * @Struct   security_person_object_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_person_t {
    
} security_person_t;
/**
 * @Struct   security_face_object_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_face_t {

} security_face_t;

typedef struct _security_motorvehicle_t {

} security_motorvehicle_t;

typedef struct _security_nonmotorvehicle_t {

} security_nonmotorvehicle_t;

typedef struct _security_thing_t {

} security_thing_t;

typedef struct _security_scene_t {

} security_scene_t;

typedef struct _security_case_t {

} security_case_t;

typedef struct _security_caseinfo_t {

} security_caseinfo_t;

typedef struct _security_disposition_t {

} security_disposition_t;

typedef struct _security_disposition_notification_t {

} security_disposition_notification_t;

typedef struct _security_analysis_rule_t {

} security_analysis_rule_t;

typedef struct _security_videolabel_t {

} security_videolabel_t;


typedef struct _security_subscribe_t {

} security_subscribe_t;







/**
 * @Class    security_message_factory
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
class security_message_factory {
public:
    static std::string makeRegisterMessage(const char* deviceId);
    static std::string makeUnregisterMessage(const char* deviceId);
    static std::string makeKeepaliveMessage(const char* deviceId);
    static std::string makeAPEListMessage(int minOccurs);
    static std::string makeVideoSliceListMessage(int minOccurs, int maxOccurs);
    static std::string makeVideoSliceInfoListMessage();
    static std::string makeImageListMessage(int minOccurs, int maxOccurs);
    static std::string makeImageObjectMessage(const char* uri);
    static std::string makeImageInfoMessage(const security_image_info_t* imageInfo);
    static std::string makeFileListMessage(std::vector<security_file_t>& fileList);
    static std::string makeFileObjectMessage(const security_file_t* fileObject);
    static std::string makeFileInfoMessage(const security_file_info_t* fileInfo);
    static std::string makePersonListMessage(std::vector<security_person_t>& personList);
    static std::string makePersonObjectMessage(const security_person_t* personObject);
    static std::string makeFaceListMessage(std::vector<security_face_t>& faceList);
    static std::string makeFaceMessage(const security_face_t* faceObject);
    static std::string makeMotorVehicleListMessage(std::vector<security_motorvehicle_t>& motorVehicleList);
    static std::string makeMotorVehicleMessage(const security_motorvehicle_t* motorVehicle);
    static std::string makeNonMotorVehicleListMessage(std::vector<security_motorvehicle_t>& motorVehicleList);
    static std::string makeNonMotorVehicleMessage(const security_nonmotorvehicle_t* nonmotorVehicle);
    static std::string makeThingListMessage(std::vector<security_thing_t>& thingList);
    static std::string makeThingMessage(const security_thing_t* thingObject);
    static std::string makeSceneListMessage(std::vector<security_scene_t>& sceneList);
    static std::string makeSceneMessage(const security_scene_t* scemeObject);
    static std::string makeCaseListMessage(std::vector<security_case_t>& caseList);
    static std::string makeCaseMessage(const security_case_t* caseObject);
    static std::string makeCaseInfoMessage(const security_caseinfo_t* caseInfo);
    static std::string makeDispositionMessage(const security_disposition_t* disp);
    static std::string makeDispositionNotifyMessage(const security_disposition_notification_t* dispNoti);
    static std::string makeSubscribeListMessage(std::vector<security_subscribe_t>& subscribeList);
    static std::string makeAnalysisRuleListMessage(std::vector<security_analysis_rule_t>& analysisRuleList);
    static std::string makeAnalysisRuleMessage(const security_analysis_rule_t* analysisRule);
    static std::string makeVideoLabelListMessage(std::vector<security_videolabel_t>& videoLabelList);
    static std::string makeVideoLabelMessage(const security_videolabel_t* videoLabel);

private:
    const char* port2String(int port) {static char buff[8]={0}; sprintf(buff, "%d", port); return buff;}
};


#endif
