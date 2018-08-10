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
#define SpeedType      double
#define LongitudeType  double
#define LatitudeType   double

/**
 * @Struct   security_image_info_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_image_info {
    SecurityString id;
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
    double         shotPlaceLongitude;
    double         shotPlaceLatitude;
    SecurityString HorizontalShotDirection;
    SecurityString VerticalShotDirection;
    SecurityString securityLevel;
    int            width;
    int            height;
    SecurityString cameraManufacturer;
    SecurityString cameraVersion;
    int            apertureValue;
    int            isoSensitivity;
    int            focalLength;
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
    int            fileSize;
} security_image_info_t;
/**
 * @Struct   security_subimage_info_t
 * @Brief
 * @DateTime 2018-08-10T11:18:46+0800
 * @Modify   2018-08-10T11:18:46+0800
 * @Author   Anyz
 */
typedef struct _security_subimage_info_t {
    int             id;
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
typedef SecurityArray<security_subimage_info_t> security_subimage_infos_t;
/**
 * @Struct   security_image_t
 * @Brief
 * @DateTime 2018/8/10 11:19:14
 * @Modify   2018/8/10 11:19:20
 * @Author   Anyz
 */
typedef struct _security_image_t {

} security_image_t;
/**
 * @Struct   security_file_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_file {
    SecurityString id;
    SecurityString infoKind;
    SecurityString source;
    SecurityString name;
    SecurityString storagePath;
    SecurityString hash;
    SecurityString format;
    SecurityString title;
    SecurityString securityLevel;
    SecurityString submiterName;
    SecurityString submiterOrg;
    SecurityString entryTime;
    int            size;
} security_file_t;
/**
 * @Struct   security_file_info_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_file_info {
    SecurityString id;
    SecurityString infoKind;
    SecurityString source;
    SecurityString name;
    SecurityString storagePath;
    SecurityString hash;
    SecurityString format;
    SecurityString title;
    SecurityString securityLevel;
    SecurityString submiterName;
    SecurityString submiterOrg;
    SecurityString entryTime;
    int            size;
} security_file_info_t;
/**
 * @Struct   security_person_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_person_t {
    SecurityString id;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    int            leftTopX;
    int            leftTopY;
    int            rightBottomX;
    int            rightBottomY;
    SecurityString locationMarkTime;
    SecurityString appearTime;
    SecurityString idtype;
    int            idNumber;
    SecurityString name;
    SecurityString usedName;
    SecurityString alias;
    int            genderCode;
    int            ageUpLimit;
    int            ageLowerLimit;
    int            ethicCode;
    int            nationalityCode;
    int            nativeCityCode;
    int            residenceAdminDivision;
    int            chineseAccentCode;
    SecurityString org;
    SecurityString jobCategory;
    int            accompanyNumber;
    int            heightUpLimit;
    int            heightLowerLimit;
    int            bodyType;
    SecurityString skinColor;
    SecurityString hairStyle;
    SecurityString hairColor;
    SecurityString gesture;
    int            status;
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
    int            isDriver;
    int            isForeigner;
    SecurityString passportType;
    SecurityString immigrantTypeCode;
    int            isSuspectedTerrorist;
    int            suspectedTerroristNumber;
    int            isCriminalInvolved;
    SecurityString criminalInvolvedSpecialisationCode;
    SecurityString bodySpecialMark;
    SecurityString crimeMethod;
    SecurityString crimeCharacterCode;
    int            escapedCriminalNumber;
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
    security_subimage_infos_t subImageList;
} security_person_t;
typedef SecurityArray<security_person_t>                    security_persons_t;
/**
 * @Struct   security_face_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
typedef struct _security_face_t {
    int            id;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    int            leftTopX;
    int            leftTopY;
    int            rightBottomX;
    int            rightBottomY;
    SecurityString locationMarkTime;
    SecurityString appearTime;
    SecurityString disappearTime;
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
    SecurityString style;
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
    security_subimage_infos_t  subimageInfo;
} security_face_t;
typedef SecurityArray<security_face_t>                      security_faces_t;

/**
 * @Struct   security_motorvehicle_t
 * @Brief
 * @DateTime 2018/8/10 11:43:12
 * @Modify   2018/8/10 11:43:18
 * @Author   Anyz
 */
typedef struct _security_motorvehicle_t {
    SecurityString id;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString tollgateId;
    SecurityString deviceId;
    SecurityString storageUrl1;
    SecurityString storageUrl2;
    SecurityString storageUrl3;
    SecurityString storageUrl4;
    SecurityString storageUrl5;
    int            leftTopX;
    int            leftTopY;
    int            rightBottomX;
    int            rightBottomY;
    SecurityString markTime;
    SecurityString appearTime;
    SecurityString disappearTime;
    SecurityString laneNo;
    SecurityString hasPlate;
    SecurityString plateClass;
    SecurityString PlateColor;
    SecurityString PlateNo;
    SecurityString plateNoAttach;
    SecurityString plateDescribe;
    int            isDecked;
    int            isAltered;
    int            isCovered;
    SpeedType      speed;
    SecurityString direction;
    SecurityString drivingStatusCode;
    SecurityString vehicleClass;
    SecurityString vehicleBrand;
    SecurityString vehicleModel;
    SecurityString vehicleStyles;
    SecurityString vehicleLength;
    int            vehicleWidth;
    int            vehicleHeight;
    SecurityString vehicleColor;
    SecurityString vehicleColorDepth;
    SecurityString vehicleHood;
    SecurityString vehicleTrunk;
    SecurityString vehicleWheel;
    SecurityString wheelPrintedPattern;
    SecurityString vehicleWindow;
    SecurityString vehicleRoof;
    SecurityString vehicleDoor;
    SecurityString sideOfVehicle;
    SecurityString carOfVehicle;
    SecurityString rearviewMirror;
    SecurityString vehicleChassis;
    SecurityString vehicleShielding;
    SecurityString filmColor;
    bool           isModified;
    SecurityString hitMarkInfo;
    SecurityString vehicleBodyDesc;
    SecurityString vehicleFrontItem;
    SecurityString descOfFrontItem;
    SecurityString vehicleRearItem;
    SecurityString descOfRearItem;
    int            numOfPassenger;
    SecurityString passTime;
    SecurityString nameOfPassedRoad;
    bool           isSuspicious;
    int            sunvisor;
    int            safetyBelt;
    int            calling;
    SecurityString plateReliability;
    SecurityString plateCharReliability;
    SecurityString brandReliability;
    security_subimage_infos_t subImageList;
} security_motorvehicle_t;
typedef SecurityArray<security_motorvehicle_t>              security_motorvehicles_t;
/**
 * @Struct   security_nonmotorvehicle_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Anyz
 */
typedef struct _security_nonmotorvehicle_t {
    SecurityString id;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    int            leftTopX;
    int            leftTopY;
    int            rightBottomX;
    int            rightBottomY;
    SecurityString markTime;
    SecurityString appearTime;
    SecurityString disappearTime;
    bool           hasPlate;
    SecurityString plateClass;
    SecurityString plateColor;
    SecurityString plateNo;
    SecurityString plateNoAttach;
    SecurityString plateDescribe;
    bool           isDecked;
    bool           isAltered;
    bool           isCovered;
    SpeedType      speed;
    SecurityString drivingStatusCode;
    SecurityString usingPropertiesCode;
    SecurityString vehicleBrand;
    SecurityString vehicleType;
    int            vehicleLength;
    int            vehicleWidth;
    int            vehicleHeight;
    SecurityString vehicleColor;
    SecurityString vehicleHood;
    SecurityString vehicleTrunk;
    SecurityString vehicleWheel;
    SecurityString wheelPrintedPattern;
    SecurityString vehicleWindow;
    SecurityString vehicleRoof;
    SecurityString vehicleDoor;
    SecurityString sideOfVehicle;
    SecurityString carOfVehicle;
    SecurityString rearviewMirror;
    SecurityString vehicleChassis;
    SecurityString vehicleShielding;
    int            filmColor;
    int            isModified;
    security_subimage_infos_t subimageList;
} security_nonmotorvehicle_t;
typedef SecurityArray<security_nonmotorvehicle_t>           security_nonmotorvehicles_t;
/**
 * @Struct   security_thing_t
 * @Brief
 * @DateTime 2018/8/10 13:17:10
 * @Modify   2018/8/10 13:17:13
 * @Author   Anyz
 */
typedef struct _security_thing_t {
    SecurityString id;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    int            leftTopX;
    int            leftTopY;
    int            rightBottomX;
    int            rightBottomY;
    SecurityString markTime;
    SecurityString appearTime;
    SecurityString disappearTime;
    SecurityString name;
    SecurityString shape;
    SecurityString color;
    SecurityString size;
    SecurityString material;
    SecurityString characteristic;
    SecurityString properties;
    SecurityString involvedObjectType;
    SecurityString firearmsAmmunitionType;
    SecurityString toolTraceType;
    SecurityString evidenceType;
    SecurityString caseEvidenceType;
    security_subimage_infos_t subimageList;
} security_thing_t;
typedef SecurityArray<security_thing_t>                     security_things_t;
/**
 * @Struct   security_scene_t
 * @Brief
 * @DateTime 2018/8/10 13:17:10
 * @Modify   2018/8/10 13:17:13
 * @Author   Anyz
 */
typedef struct _security_scene_t {
    SecurityString id;
    SecurityString infoKind;
    SecurityString sourceId;
    SecurityString deviceId;
    SecurityString beginTime;
    SecurityString placeType;
    SecurityString weatherType;
    SecurityString describe;
    SecurityString type;
    SecurityString roadAlignmentType;
    SecurityString roadSurfaceType;
    SecurityString roadCoditionType;
    SecurityString roadJunctionSectionType;
    SecurityString roadLightingType;
    SecurityString illustration;
    SecurityString windDirection;
    SecurityString illumination;
    SecurityString fieldCondition;
    SecurityString temperature;
    SecurityString humidity;
    SecurityString populationDensity;
    SecurityString denseDegree;
    SecurityString importance;
    security_subimage_infos_t subimageList;
} security_scene_t;
typedef SecurityArray<security_scene_t>                     security_scenes_t;
/**
 * @Struct   security_case_t
 * @Brief
 * @DateTime 2018/8/10 13:28:48
 * @Modify   2018/8/10 13:28:52
 * @Author   Anyz
 */
typedef struct _security_case_t {
    SecurityString id;
    SecurityString caseLinkMark;
    SecurityString caseAbstract;
    SecurityString clueId;
    SecurityString timeUpLimit;
    SecurityString timeLowerLimit;
    SecurityString createTime;
    SecurityString placeCode;
    SecurityString placeFullAddress;
    int            suspectNumber;
    SecurityString witnessIds;
    SecurityString creatorName;
    SecurityString creatorIdType;
    SecurityString creatorId;
    SecurityString creatorOrg;
    LongitudeType  longitude;
    LatitudeType   latitude;
    SecurityString motorVehicleIds;
    SecurityString nonMotorVehicleIds;
    SecurityString personIds;
    SecurityString faceIds;
    SecurityString thingIds;
    SecurityString fileIds;
    SecurityString sceneIds;
    SecurityString relateCaseList;
    SecurityString parentCaseId;
    int            state;
} security_case_t;
typedef SecurityArray<security_case_t>                      security_cases_t;
typedef struct _security_caseinfo_t {

} security_caseinfo_t;

typedef struct _security_device_t {

} security_device_t;
typedef SecurityArray<security_device_t> security_devices_t;
typedef struct _security_device_status_t {

} security_device_status_t;
typedef SecurityArray<security_device_status_t> security_device_statuss_t;
typedef struct _security_lane_t {

} security_lane_t;
typedef SecurityArray<security_lane_t> security_lanes_t;
typedef struct _security_tollgate_t {

} security_tollgate_t;
typedef SecurityArray<security_tollgate_t> security_tollgates_t;
typedef struct _security_aps_t {

} security_aps_t;
typedef SecurityArray<security_aps_t> security_apss_t;
typedef struct _security_aps_status_t {

} security_aps_status_t;
typedef SecurityArray<security_aps_status_t> security_aps_statuss_t;
/**
 * @Struct   security_disposition_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Anyz
 */
typedef struct _security_disposition_t {
    SecurityString id;
    SecurityString title;
    SecurityString category;
    SecurityString targetFeature;
    SecurityString targetImageUri;
    int priorityLevel;
    SecurityString applicantName;
    SecurityString applicantInfo;
    SecurityString applicantOrg;
    SecurityString beginTime;
    SecurityString endTime;
    SecurityString createTime;
    int            operateType;
    int            status;
    int            range;
    SecurityString tollgateList;
    SecurityString area;
    SecurityString receiveAddr;
    SecurityString receiveMobile;
    SecurityString reson;
    SecurityString removeOrg;
    SecurityString removePerson;
    SecurityString removeTime;
    SecurityString removeReason;
    security_subimage_infos_t subimageList;
} security_disposition_t;
/**
 * @Struct   security_disposition_notify_t
 * @Brief
 * @DateTime 2018/8/10 13:54:47
 * @Modify   2018/8/10 13:54:50
 * @Author   Anyz
 */
typedef struct _security_disposition_notify_t {
    SecurityString id;
    SecurityString dispositionId;
    SecurityString title;
    SecurityString triggerTime;
    SecurityString cntObjectId;
    security_person_t person;
    security_motorvehicle_t motorVehicle;
} security_disposition_notify_t;
/**
 * @Struct   security_analysis_rule_t
 * @Brief
 * @DateTime 2018/8/10 13:54:47
 * @Modify   2018/8/10 13:54:50
 * @Author   Anyz
 */
typedef struct _security_analysis_rule_t {
    SecurityString analysisRuleId;
    SecurityString videoImageId;
    SecurityString videoImageUrl;
    SecurityString cameraId;
    int            width;
    int            height;
    int            minDuration;
    int            lineMinDuration;
    int            lineMaxDuration;
    int            lineNum;
    int            pointNum;
    int            pointId;
    int            pointX;
    int            pointY;
    int            triggerDirection;
    int            actionType;
    int            beginPointX;
    int            beginPointY;
    int            endPointX;
    int            endPointY;
    int            directionNum;
    int            flowDirection;
    int            targetType;
    int            densityUnit;
} security_analysis_rule_t;
/**
 * @Struct   security_videolabel_t
 * @Brief
 * @DateTime 2018/8/10 13:39:59
 * @Modify   2018/8/10 13:40:04
 * @Author   Anyz
 */
typedef struct _security_videolabel_t {
    SecurityString videoLabelId;
    SecurityString eventSort;
    SecurityString eventRuleId;
    SecurityString videoImageId;
    SecurityString videoImageUrl;
    SecurityString cameraId;
    SecurityString IvaDeviceId;
    SecurityString createTimeAbs;
    int            createTimeRlt;
    SecurityString personId;
    SecurityString faceId;
    SecurityString motorVehicleId;
    SecurityString nonMotorVehicleId;
    SecurityString thingId;
    SecurityString sceneId;
    SecurityString targetColor;
    int            colorCount;
    int            areaPosX;
    int            areaPosY;
    int            areaWidth;
    int            areaHeight;
    int            moveObjectNum;
    int            posX;
    int            posY;
    int            width;
    int            height;
    int            status;
    int            speedVal;
    int            speedRad;
    int            eventLevel;
    SecurityString vehaviorBeginTime;
    SecurityString behaviorBeginTimeRlt;
    int            behaviorBeginFrameNoRlt;
    SecurityString behaviorEndTime;
    SecurityString behaviorEndTimeRlt;
    int            behaviorEndFrameNoRlt;
    SecurityString imagePath;
    SecurityString desc;
    int            targetNum;
    int            personNum;
    int            faceNum;
    int            vehicleNum;
    int            thingNum;
    int            targetDensityAbs;
    int            personDensityAbs;
    int            facenDensityAbs;
    int            vehicleDensityAbs;
    int            targetDensityRlt;
    int            personDensityRlt;
    int            facenDensityRlt;
    int            vehicleDensityRlt;
    int            totalTargetFlowRate;
    int            personFlowRate;
    int            vehicleFlowRate;
    int            flowDirection;
} security_videolabel_t;
/**
 * @Struct   security_subscribe_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Anyz
 */
typedef struct _security_subscribe_t {
    SecurityString id;
    SecurityString title;
    SecurityString detail;
    SecurityString resourceUri;
    SecurityString applicantName;
    SecurityString applicantOrg;
    SecurityString beginTime;
    SecurityString endTime;
    SecurityString receiveAddr;
    int            reportInterval;
    SecurityString reason;
    int            operateType;
    int            status;
    SecurityString cancelOrg;
    SecurityString cancelPerson;
    SecurityString cancelTime;
    SecurityString cancelReson;
} security_subscribe_t;
/**
 * @Struct   security_subscribe_notify_t
 * @Brief
 * @DateTime 2018/8/10 14:31:34
 * @Modify   2018/8/10 14:31:38
 * @Author   Anyz
 */
typedef struct _security_subscribe_notify_t {
    SecurityString              id;
    SecurityString              subscribeId;
    SecurityString              title;
    SecurityString              triggerTime;
    SecurityString              infoIds;
    security_cases_t            caseList;
    security_tollgates_t        tollgateList;
    security_lanes_t            laneList;
    security_devices_t          apeList;
    security_device_statuss_t   deviceStautusList;
    security_apss_t             apsList;
    security_aps_statuss_t      apsStatusList;
    security_persons_t          personList;
    security_faces_t            faceList;
    security_motorvehicles_t    motorVehicleList;
    security_nonmotorvehicles_t nonMotorVehicleList;
    security_things_t           thingList;
    security_scenes_t           sceneList;
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
/**
 * @Struct   security_videolabel_all_content_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Anyz
 */
typedef struct _security_videolabel_all_content_t {

} security_videolabel_all_content_t;

typedef SecurityArray<attr_condition_t>                     attr_conditions_t;
typedef SecurityArray<security_image_info_t>                security_image_infos_t;
typedef SecurityArray<security_image_t>                     security_images_t;
typedef SecurityArray<security_file_t>                      security_files_t;
typedef SecurityArray<security_file_info_t>                 security_file_infos_t;
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
typedef SecurityArray<SecurityString>                       security_idlist_t;

/**
 * @Struct   security_videoslice_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Anyz
 */
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
/**
 * @Struct    security_system_time_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Anyz
 */
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
