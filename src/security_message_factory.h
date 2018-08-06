/**
 * @File     security_message_factory.h
 * @brief    
 * @DateTime 2018/8/3 19:06:15
 * @Author   Anyz
 */
#ifndef __SECURITY_MESSAGE_FACTORY_H_
#define __SECURITY_MESSAGE_FACTORY_H_

#include <string>

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
    static std::string makeImageInfoMessage(const security_image_info_t* info);
    static std::string makeFileListMessage(const security_file_object_t* fo);
    static std::string makeFileObjectMessage(const security_file_object_t* fo);
    static std::string makeFileInfoMessage(const security_file_object_t* fo);

private:
    const char* port2String(int port) {static char buff[8]={0}; sprintf(buff, "%d", port); return buff;}
};


#endif
