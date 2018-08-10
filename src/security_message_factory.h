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

#define SecurityArray  std::vector
#define SecurityString std::string

/**
 * @Struct   security_image_info_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_image_info {
    SecurityString imageId;
    SecurityString infoKind;
    SecurityString imageSource;
    SecurityString sourceVideoId;
    SecurityString originImageId;
    SecurityString eventSort;
    SecurityString deviceId;
    SecurityString storagePath;
    SecurityString fileHash;
    SecurityString shotTime;
    SecurityString title;
    SecurityString titleNote;
    SecurityString specialName;
    SecurityString keyword;
    SecurityString contentDescription;
    SecurityString subjectCharacter;
    SecurityString shotPlaceFullAddress;
    double      shotPlaceLongitude;
    double      shotPlaceLatitude;
    SecurityString HorizontalShotDirection;
    SecurityString VerticalShotDirection;
    SecurityString securityLevel;
    int         width;
    int         height;
    SecurityString cameraManufacturer;
    SecurityString cameraVersion;
    int         apertureValue;
    int         isoSensitivity;
    int         focalLength;
    SecurityString qualityGrade;
    SecurityString collectorName;
    SecurityString collectorOrg;
    SecurityString collectorIdType;
    SecurityString collectorId;
    SecurityString entryClrk;
    SecurityString entryClrkOrg;
    SecurityString entryClrkIdType;
    SecurityString entryTime;
    SecurityString imageProcFlag;
    int         fileSize;
} security_image_info_t;

typedef struct _security_subimage_info_t {
    int             imageId;
    int             eventSort;
    SecurityString  deviceId;
    SecurityString  storagePath;
    SecurityString  type;
    SecurityString  fileFormat;
    SecurityString  shotTime;
    int             width;
    int             height;
    void*           data;
} security_subimage_info_t;

typedef struct _security_image_t {

} security_image_t;
/**
 * @Struct   security_file_object_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_file {
    SecurityString fileId;
    SecurityString infoKind;
    SecurityString source;
    SecurityString filenName;
    SecurityString storagePath;
    SecurityString fileHash;
    SecurityString fileFormat;
    SecurityString title;
    SecurityString securityLevel;
    SecurityString submiterName;
    SecurityString submiterOrg;
    SecurityString entryTime;
    int         fileSize;
} security_file_t;
/**
 * @Struct   security_file_info_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_file_info {
    SecurityString fileId;
    SecurityString infoKind;
    SecurityString source;
    SecurityString filenName;
    SecurityString storagePath;
    SecurityString fileHash;
    SecurityString fileFormat;
    SecurityString title;
    SecurityString securityLevel;
    SecurityString submiterName;
    SecurityString submiterOrg;
    SecurityString entryTime;
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
    SecurityString personId;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    int leftTopX;
    int leftTopY;
    int rightBottomX;
    int rightBottomY;
    SecurityString locationMarkTime;
    SecurityString personAppearTime;
    int id;
    int idNumber;
    SecurityString name;
    SecurityString usedName;
    SecurityString alias;
    int genderCode;
    int ageUpLimit;
    int ageLowerLimit;
    int ethicCode;
    int nationalityCode;
    int nativeCityCode;
    int residenceAdminDivision;
    int chineseAccentCode;
    SecurityString personOrg;
    SecurityString jobCategory;
    int accompanyNumber;
    int heightUpLimit;
    int heightLowerLimit;
    int bodyType;
    SecurityString skinColor;
    SecurityString hairStyle;
    SecurityString hairColor;
    SecurityString gesture;
    int status;
    SecurityString faceStyle;
    SecurityString facialFeature;
    SecurityString physicalFeature;
    SecurityString bodyFeature;
    SecurityString habitualMovement;
    SecurityString behavior;
    SecurityString behaviorDescription;
    SecurityString appendant;
    SecurityString appendantDescription;
    SecurityString umbrellaColor;
    SecurityString respiratorColor;
    SecurityString capStyle;
    SecurityString capColor;
    SecurityString glassStyle;
    SecurityString glassColor;
    SecurityString scarfColor;
    SecurityString bagStyle;
    SecurityString bagColor;
    SecurityString coatStyle;
    SecurityString coatLength;
    SecurityString coatColor;
    SecurityString trousersStyle;
    SecurityString trousersColor;
    SecurityString trousersLen;
    SecurityString shoesStyle;
    SecurityString shoesColor;
    int         isDriver;
    int         isForeigner;
    SecurityString passportType;
    SecurityString immigrantTypeCode;
    int         isSuspectedTerrorist;
    int         suspectedTerroristNumber;
    int         isCriminalInvolved;
    SecurityString criminalInvolvedSpecialisationCode;
    SecurityString bodySpecialMark;
    SecurityString crimeMethod;
    SecurityString crimeCharacterCode;
    int         escapedCriminalNumber;
    int         isDetainees;
    SecurityString detentionHouseCode;
    SecurityString detaineesIdentity;
    SecurityString detaineesSpecialIdentity;
    SecurityString memberTypeCode;
    int         isVictim;
    SecurityString victimType;
    SecurityString injuredDegree;
    SecurityString corpseConditionCode;
    int         isSuspiciousPerson;
    SecurityString subImageList;
} security_person_t;
/**
 * @Struct   security_face_object_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_face_t {
    int            faceId;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    int            leftTopX;
    int            leftTopY;
    int            rightBottomX;
    int            rightBottomY;
    SecurityString locationMarkTime;
    SecurityString faceAppearTime;
    SecurityString faceDisAppearTime;
    SecurityString idType;
    SecurityString idNumber;
    SecurityString name;
    SecurityString usedName;
    SecurityString alias;
    SecurityString genderCode;
    int            ageUpLimit;
    int            ageLowerLimit;
    SecurityString ethicCode;
    SecurityString nationalityCode;
    SecurityString nativeCityCode;
    SecurityString residenceAdminDivision;
    SecurityString chineseAccentCode;
    SecurityString jobCategory;
    SecurityString accompanyNumber;
    SecurityString skinColor;
    SecurityString hairStyle;
    SecurityString hairColor;
    SecurityString faceStyle;
    SecurityString facialFeature;
    SecurityString physicalFeature;
    SecurityString respiratorColor;
    SecurityString capStyle;
    SecurityString capColor;
    SecurityString glassStyle;
    SecurityString glassColor;
    int            isDriver;
    int            isForeigner;
    SecurityString passportType;
    SecurityString immigrantTypeCode;
    int            isSuspectedTerrorist;
    SecurityString suspectedTerroristNumber;
    int            isCriminalInvolved;
    SecurityString criminalInvolvedSpecialisationCode;
    SecurityString bodySpecialMark;
    SecurityString crimeMethod;
    SecurityString crimeCharacterCode;
    SecurityString escapedCriminalNumber;
    int            isDetainees;
    SecurityString detentionHouseCode;
    SecurityString detaineesIdentity;
    SecurityString detaineesSpecialIdentity;
    SecurityString memberTypeCode;
    int            isVictim;
    SecurityString victimType;
    SecurityString injuredDegree;
    SecurityString corpseConditionCode;
    int            isSuspiciousPerson;
    SecurityString attitude;
    double         similarityDegree;
    SecurityString eyebrowStyle;
    SecurityString noseStyle;
    SecurityString mustacheStyle;
    SecurityString lipStyle;
    SecurityString wrinklePouch;
    SecurityString acneStain;
    SecurityString freckleBirthmark;
    SecurityString scarDimple;
    SecurityString otherFeature;
    security_subimage_info_t  subimageInfo;
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

typedef struct _security_disposition_notify_t {

} security_disposition_notify_t;

typedef struct _security_analysis_rule_t {

} security_analysis_rule_t;

typedef struct _security_videolabel_t {

} security_videolabel_t;

typedef struct _security_subscribe_t {

} security_subscribe_t;

typedef struct _security_subscribe_notify_t {

} security_subscribe_notify_t;

typedef struct _security_task_t {

} security_task_t;

typedef struct _security_task_control_t {

} security_task_control_t;

typedef struct _security_videoslice_info_t {

} security_videoslice_info_t;

typedef struct _attr_condition {
	SecurityString key;
	SecurityString value;
} attr_condition_t;

typedef struct _security_videolabel_all_content_t {

} security_videolabel_all_content_t;

typedef SecurityArray<attr_condition_t>                     attr_conditions_t;
typedef SecurityArray<security_image_info_t>                security_image_infos_t;
typedef SecurityArray<security_image_t>                     security_images_t;
typedef SecurityArray<security_file_t>                      security_files_t;
typedef SecurityArray<security_file_info_t>                 security_file_infos_t;
typedef SecurityArray<security_person_t>                    security_persons_t;
typedef SecurityArray<security_face_t>                      security_faces_t;
typedef SecurityArray<security_motorvehicle_t>              security_motorvehicles_t;
typedef SecurityArray<security_nonmotorvehicle_t>           security_nonmotorvehicles_t;
typedef SecurityArray<security_thing_t>                     security_things_t;
typedef SecurityArray<security_scene_t>                     security_scenes_t;
typedef SecurityArray<security_case_t>                      security_cases_t;
typedef SecurityArray<security_caseinfo_t>                  security_caseinfos_t;
typedef SecurityArray<security_disposition_t>               security_dispositions_t;
typedef SecurityArray<security_disposition_notify_t>        security_disposition_notifys_t;
typedef SecurityArray<security_analysis_rule_t>             security_analysis_rules_t;
typedef SecurityArray<security_videolabel_t>                security_videolabels_t;
typedef SecurityArray<security_subscribe_t>                 security_subscribes_t;
typedef SecurityArray<security_subscribe_notify_t>          security_subscribe_notifys_t;
typedef SecurityArray<security_task_t>                      security_tasks_t;
typedef SecurityArray<security_task_control_t>              security_task_controls_t;

typedef SecurityArray<security_videolabel_all_content_t>    security_videolabel_all_contents_t;
typedef SecurityArray<SecurityString>                          security_idlist_t;

typedef struct _security_videoslice_t {
	security_videoslice_info_t  videoSliceInfo;
    security_persons_t          personList;
    security_faces_t            faceList;
    security_motorvehicles_t    motorVehicleList;
    security_nonmotorvehicles_t nonmotorVehicleList;
    security_things_t           thingList;
    security_scenes_t           sceneList;
    void*                       data;
} security_videoslice_t;

typedef SecurityArray<security_videoslice_t>                security_videoslices_t;

typedef struct _security_system_time_t {
	SecurityString viidServerId;
	SecurityString timeMode;
	SecurityString localTime;
	SecurityString timeZone;
} security_system_time_t;

/**
 * @Class    security_message_factory
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
class security_message_factory {
public:
    static SecurityString makeRegisterMessage(const char* deviceId);
    static SecurityString makeUnregisterMessage(const char* deviceId);
    static SecurityString makeKeepaliveMessage(const char* deviceId);
    static SecurityString makeTimeMessage(const security_system_time_t* sysTime);
    static SecurityString makeAPEListMessage();
    static SecurityString makeVideoSliceListMessage(const security_videoslice_t* videoSlice);
    static SecurityString makeVideoSliceInfoListMessage();
    static SecurityString makeImageListMessage(security_images_t& imageList);
    static SecurityString makeImageObjectMessage(const security_image_t* imgObject);
    static SecurityString makeImageInfoMessage(const security_image_info_t* imageInfo);
    static SecurityString makeFileListMessage(security_files_t& fileList);
    static SecurityString makeFileObjectMessage(const security_file_t* fileObject);
    static SecurityString makeFileInfoMessage(const security_file_info_t* fileInfo);
    static SecurityString makePersonListMessage(security_persons_t& personList);
    static SecurityString makePersonObjectMessage(const security_person_t* personObject);
    static SecurityString makeFaceListMessage(security_faces_t& faceList);
    static SecurityString makeFaceMessage(const security_face_t* faceObject);
    static SecurityString makeMotorVehicleListMessage(security_motorvehicles_t& motorVehicleList);
    static SecurityString makeMotorVehicleMessage(const security_motorvehicle_t* motorVehicle);
    static SecurityString makeNonMotorVehicleListMessage(security_nonmotorvehicles_t& nonmotorVehicleList);
    static SecurityString makeNonMotorVehicleMessage(const security_nonmotorvehicle_t* nonmotorVehicle);
    static SecurityString makeThingListMessage(security_things_t& thingList);
    static SecurityString makeThingMessage(const security_thing_t* thingObject);
    static SecurityString makeSceneListMessage(security_scenes_t& sceneList);
    static SecurityString makeSceneMessage(const security_scene_t* scemeObject);
    static SecurityString makeCaseListMessage(security_cases_t& caseList);
    static SecurityString makeCaseMessage(const security_case_t* caseObject);
    static SecurityString makeCaseInfoMessage(const security_caseinfo_t* caseInfo);
    static SecurityString makeDispositionMessage(const security_disposition_t* disp);
	static SecurityString makeDispositionListMessage(security_dispositions_t& dispList);
    static SecurityString makeDispositionNotifyMessage(const security_disposition_notify_t* dispNoti);
	static SecurityString makeDispositionNotifyListMessage(security_disposition_notifys_t& dispNotifyList);
    static SecurityString makeSubscribeListMessage(security_subscribes_t& subscribeList);
	static SecurityString makeSubscribeNotifyListMessage(security_subscribe_notifys_t& subscribeNotifyList);
    static SecurityString makeAnalysisRuleListMessage(security_analysis_rules_t& analysisRuleList);
    static SecurityString makeAnalysisRuleMessage(const security_analysis_rule_t* analysisRule);
    static SecurityString makeVideoLabelListMessage(security_videolabels_t& videoLabelList);
    static SecurityString makeVideoLabelMessage(const security_videolabel_t* videoLabel);

private:
    static const char* num2String(int port) {static char buff[8]={0}; sprintf(buff, "%d", port); return buff;}
};


#endif
