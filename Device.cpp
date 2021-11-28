#include <string>

using namespace std;

/**
 * 设备类
 */
class Device{
private:
    long long deviceId; //设备编号
    string clazz; //设备种类
    int personId; //设备负责人编号

public:
    long long int getDeviceId() const {
        return deviceId;
    }

    void setDeviceId(long long int deviceId) {
        Device::deviceId = deviceId;
    }

    const string &getClazz() const {
        return clazz;
    }

    void setClazz(const string &clazz) {
        Device::clazz = clazz;
    }

    int getPersonId() const {
        return personId;
    }

    void setPersonId(int personId) {
        Device::personId = personId;
    }

};
