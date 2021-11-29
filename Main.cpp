#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * 顺序表
 * @tparam T
 */
template <class T>
class SeqList {
private:
    T* array;
    int max{};
    int last;
public:
    SeqList(int max);
    SeqList(SeqList& L);
    ~SeqList();
    int size();
    int length();
    int search(T& x);
    bool getData(int index, T& x);
    bool setData(int index, T& x);
    bool insert(int index, T& x);
    bool remove(int index, T& x);
    bool isEmpty();
    bool isFull();
    void makeEmpty();
};

template <class T>
SeqList<T>::SeqList(int max) {
    array = new T[max];
    if (array == NULL)cout << "´¢´æ·ÖÅä´íÎó" << endl;
    this->max = max;
    last = -1;
}

template <class T>
SeqList<T>::SeqList(SeqList& L) {
    this->max = L.max;
    this->last = L.last;
    this->array = new T[max];
    if (array == NULL)cout << "´¢´æ·ÖÅä´íÎó" << endl;
    for (int i = 0; i <= last; i++)
    {
        this->array[i] = L.array[i];
    }
}

template <class T>
SeqList<T>::~SeqList() {
    delete[]array;
}

template <class T>
int SeqList<T>::size() {
    return max;
}

template <class T>
int SeqList<T>::length() {
    return last+1;
}

template <class T>
int SeqList<T>::search(T& x) {
    for (int i = 0; i <= last; i++) {
        if (array[i] == x) {
            return i;
        }

    }return -1;
}

template <class T>
bool SeqList<T>::getData(int index, T& x) {
    if (index >= 0 || index <= last) {
        x = array[index];
        return true;
    }
    return false;
}

template <class T>
bool SeqList<T>::setData(int index, T& x) {
    if (index >= 0 || index <= last) {
        array[index] = x;
        return true;
    }
    return false;
}

template <class T>
bool SeqList<T>::insert(int index, T& x) {
    if (index < 0 || index >= max)return false;
    for (int i = last; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = x;
    last++;
    return true;
}

template <class T>
bool SeqList<T>::remove(int index, T& x) {
    if (index<0 || index>max)return false;
    x = array[index];
    for (int i = 0; i < last; i++) {
        if (i >= index) {
            array[i] = array[i + 1];
        }
    }
    last--;
    return true;
}

template <class T>
bool SeqList<T>::isEmpty() {
    if (last == -1)
        return true;
    else return false;
}

template <class T>
bool SeqList<T>::isFull() {
    if (last == max - 1)
        return true;
    else return false;
}

template <class T>
void SeqList<T>::makeEmpty() {
    last = -1;
}


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

/**
 * 人员类
 */
class Person {
private:
    int id; //人员编号
    string name; //姓名
    string sex; //性别
    int age; //年龄

public:

    int getId() const {
        return id;
    }

    void setId(int id) {
        Person::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Person::name = name;
    }

    const string &getSex() const {
        return sex;
    }

    void setSex(const string &sex) {
        Person::sex = sex;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Person::age = age;
    }
};

class View {
private:
    SeqList<Device> * deviceList;
    SeqList<Person> * personList;

    void readDeviceList();
    void readPersonList();

    void writeDeviceList();
    void writePersonList();
public:
    View() {
        deviceList = new SeqList<Device>(50);
        personList = new SeqList<Person>(20);
        readPersonList();
        readDeviceList();
    }
    ~View() {
        delete deviceList;
        delete personList;
    }

    bool mainView();
    void queryPersonView();
    void insertPersonView();
    void deletePersonView();
    void updatePersonView();

    void queryDeviceView();
    void insertDeviceView();
    void deleteDeviceView();
    void updateDeviceView();

    bool exitView();
};

void View::readDeviceList() {
    ifstream in("/Users/zhukunshuai/CLionProjects/HelloWorld/device.txt");
    int nums;
    in >> nums;
    for (int i = 0; i < nums; i++) {
        long long deviceId; //设备编号
        string clazz; //设备种类
        int personId; //设备负责人编号
        in >> deviceId >> clazz >> personId;
        Device device;
        device.setDeviceId(deviceId);
        device.setClazz(clazz);
        device.setPersonId(personId);
        deviceList->insert(i, device);
    }
    in.close();
}

void View::readPersonList() {
    ifstream in("/Users/zhukunshuai/CLionProjects/HelloWorld/person.txt");
    int nums;
    in >> nums;
    for (int i = 0; i < nums; i++) {
        int id; //人员编号
        string name; //姓名
        string sex; //性别
        int age; //年龄
        in >> id >> name >> sex >> age;
        Person person;
        person.setId(id);
        person.setName(name);
        person.setSex(sex);
        person.setAge(age);
        personList->insert(i, person);
    }
    in.close();
}

void View::writeDeviceList() {
    ofstream out("/Users/zhukunshuai/CLionProjects/HelloWorld/device.txt");
    int nums = deviceList->length();
    out << nums << endl;
    for (int i = 0; i < nums; i++) {
        Device device;
        deviceList->getData(i, device);
        out << device.getDeviceId() << " " << device.getClazz() << " " << device.getPersonId() << endl;
    }
    out.close();
}

void View::writePersonList() {
    ofstream out("/Users/zhukunshuai/CLionProjects/HelloWorld/person.txt");
    int nums = personList->length();
    out << nums << endl;
    for (int i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        out << person.getId() << " " << person.getName() << " " << person.getSex() << " " << person.getAge() << endl;
    }
    out.close();
}

bool View::mainView() {
    system("clear");
    cout << "**************实验室管理信息系统**************" << endl;
    cout << "1. 查询管理员" << endl;
    cout << "2. 添加管理员" << endl;
    cout << "3. 删除管理员" << endl;
    cout << "4. 修改管理员" << endl;
    cout << "5. 查询设备" << endl;
    cout << "6. 添加设备" << endl;
    cout << "7. 删除设备" << endl;
    cout << "8. 修改设备" << endl;
    cout << "9. 退出" << endl;
    cout << "**************实验室管理信息系统**************" << endl;

    int n;
    cin >> n;
    switch (n) {
        case 1:
            queryPersonView();
            break;
        case 2:
            insertPersonView();
            break;
        case 3:
            deletePersonView();
            break;
        case 4:
            updatePersonView();
            break;
        case 5:
            queryDeviceView();
            break;
        case 6:
            insertDeviceView();
            break;
        case 7:
            deleteDeviceView();
            break;
        case 8:
            updateDeviceView();
            break;
        case 9:
            return !exitView();
        default:
            break;
    }
    return true;
}

bool View::exitView() {
    system("clear");
    cout << "确定要退出吗? <y/n>" << endl;
    char n;
    cin >> n;
    if (n == 'y') {
        writePersonList();
        writeDeviceList();
        return true;
    } else {
        return false;
    }
}

void View::queryPersonView() {
    system("clear");
    cout << "====== 查询管理员界面 ======" << endl;
    int nums = personList->length();
    cout << nums << endl;
    for (int i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        cout << person.getId() << " " << person.getName() << " " << person.getSex() << " " << person.getAge() << endl;
    }
    cout << "输入任意字符退出" << endl;
    char n;
    cin >> n;
}

void View::insertPersonView() {
    system("clear");
    cout << "====== 添加管理员界面 ======" << endl;
    cout << "依次输入 编号、姓名、性别、年龄: ";
    int id, age;
    string name, sex;
    cin >> id >> name >> sex >> age;

    // 判断id是否重复
    int nums = personList->length();
    bool isRepeat = false;
    for (int i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        if (person.getId() == id) {
            isRepeat = true;
            break;
        }
    }

    if (isRepeat) {
        cout << "输入的id重复" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
    } else {
        cout << "请确认: " << endl;
        cout << "编号-" << id << ", 姓名-" << name << ", 性别-" << sex << ", 年龄-" << age << endl;
        cout << "<y/n>: ";

        char n;
        cin >> n;

        if (n == 'y') {
            Person person;
            person.setId(id);
            person.setName(name);
            person.setSex(sex);
            person.setAge(age);
            personList->insert(personList->length(), person);
        }
    }
}

void View::deletePersonView() {
    system("clear");
    cout << "====== 删除管理员界面 ======" << endl;
    int nums = personList->length();
    cout << nums << endl;
    for (int i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        cout << person.getId() << " " << person.getName() << " " << person.getSex() << " " << person.getAge() << endl;
    }
    cout << "请输入需要删除的管理员编号" << endl;
    int id;
    cin >> id;

    int i = 0;
    for (i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        if (person.getId() == id) break;
    }
    if (i == nums) {
        cout << "未找到该管理员" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
        return;
    }

    char isDelDevice;
    cout << "是否需要一并删除其管理的设备" << endl;
    cout << "<y/n>: ";
    cin >> isDelDevice;
    Person person;
    personList->remove(i, person);
    if (isDelDevice == 'y') {
        int deviceNum = deviceList->length();
        // 从后向前遍历，同时删除
        for (int i = deviceNum; i >= 0; i--) {
            Device device;
            deviceList->getData(i, device);
            if (device.getPersonId() == id) {
                Device tmp;
                deviceList->remove(i, tmp);
            }
        }
    }
}

void View::updatePersonView() {
    system("clear");
    cout << "====== 修改管理员界面 ======" << endl;
    int nums = personList->length();
    cout << nums << endl;
    for (int i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        cout << person.getId() << " " << person.getName() << " " << person.getSex() << " " << person.getAge() << endl;
    }
    cout << "请输入需要修改的管理员编号" << endl;
    int id;
    cin >> id;
    int i = 0;
    for (i = 0; i < nums; i++) {
        Person person;
        personList->getData(i, person);
        if (person.getId() == id) break;
    }
    if (i == nums) {
        cout << "没有找到该id!" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
    } else {
        cout << "已找到该管理员" << endl;
        cout << "依次输入更新后的 编号、姓名、性别、年龄: ";
        int newId, age;
        string name, sex;
        cin >> newId >> name >> sex >> age;

        // 判断id是否重复
        bool isRepeat = false;
        for (int i = 0; i < nums; i++) {
            Person person;
            personList->getData(i, person);
            if (person.getId() == newId && newId != id) {
                isRepeat = true;
                break;
            }
        }

        if (isRepeat) {
            cout << "管理员编号重复" << endl;
            cout << "输入任意字符退出" << endl;
            char n;
            cin >> n;
        } else {
            cout << "请确认: " << endl;
            cout << "编号-" << newId << ", 姓名-" << name << ", 性别-" << sex << ", 年龄-" << age << endl;
            cout << "<y/n>: ";

            char n;
            cin >> n;

            if (n == 'y') {
                Person person;
                person.setId(newId);
                person.setName(name);
                person.setSex(sex);
                person.setAge(age);
                personList->setData(i, person);
            }
        }
    }
}

void View::queryDeviceView() {
    system("clear");
    cout << "====== 查询设备界面 ======" << endl;
    int nums = deviceList->length();
    cout << nums << endl;
    for (int i = 0; i < nums; i++) {
        Device device;
        deviceList->getData(i, device);
        cout << device.getDeviceId() << " " << device.getClazz() << " " << device.getPersonId() << endl;
    }
    cout << "输入任意字符退出" << endl;
    char n;
    cin >> n;
}

void View::insertDeviceView() {
    system("clear");
    cout << "====== 添加设备界面 ======" << endl;
    cout << "请依次输入 设备编号、设备类型、管理员编号: ";
    long long deviceId;
    string clazz;
    int personId;
    cin >> deviceId >> clazz >> personId;

    // 判断设备编号是否重复
    int deviceNums = deviceList->length();
    for (int i = 0; i < deviceNums; i++) {
        Device device;
        deviceList->getData(i, device);
        if (device.getDeviceId() == deviceId) {
            cout << "设备编号重复" << endl;
            cout << "输入任意字符退出" << endl;
            char n;
            cin >> n;
            return;
        }
    }

    // 判断管理员编号是否存在
    int personNums = personList->length();
    cout << personNums << endl;
    bool isExistPerson = false;
    for (int i =0; i < personNums; i++) {
        Person person;
        personList->getData(i, person);
        if (person.getId() == personId) {
            isExistPerson = true;
            break;
        }
    }
    if (!isExistPerson) {
        cout << "不存在该管理员" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
        return;
    } else {

        cout << "请确认: deviceId-" << deviceId << ", clazz-" << clazz << ", personId-" << personId << endl;
        cout << "<y/n>: ";
        char n;
        cin >> n;
        if (n == 'y') {
            Device device;
            device.setDeviceId(deviceId);
            device.setClazz(clazz);
            device.setPersonId(personId);
            deviceList->insert(deviceList->length(), device);
        }
    }
}

void View::deleteDeviceView() {
    system("clear");
    cout << "====== 删除设备界面 ======" << endl;
    int nums = deviceList->length();
    cout << nums << endl;
    for (int i = 0; i < nums; i++) {
        Device device;
        deviceList->getData(i, device);
        cout << device.getDeviceId() << " " << device.getClazz() << " " << device.getPersonId() << endl;
    }
    cout << "输入删除的设备编号: ";
    long long id;
    cin >> id;
    int i = 0;
    for (i = 0; i < nums; i++) {
        Device device;
        deviceList->getData(i, device);
        if (device.getDeviceId() == id) {
            break;
        }
    }
    if (nums == i) {
        cout << "未找到该设备" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
        return;
    } else {
        Device tmp;
        deviceList->remove(i, tmp);
    }
}

void View::updateDeviceView() {
    system("clear");
    cout << "====== 修改设备界面 ======" << endl;
    int nums = deviceList->length();
    for (int i = 0; i < nums; i++) {
        Device device;
        deviceList->getData(i, device);
        cout << device.getDeviceId() << " " << device.getClazz() << " " << device.getPersonId() << endl;
    }

    cout << "请依次输入 设备编号、设备类型、管理员编号: ";
    long long deviceId;
    string clazz;
    int personId;
    cin >> deviceId >> clazz >> personId;

    // 判断设备编号是否重复
    bool isExist = false;
    int deviceNums = deviceList->length();
    int i = 0;
    for (i = 0; i < deviceNums; i++) {
        Device device;
        deviceList->getData(i, device);
        if (device.getDeviceId() == deviceId) {
            break;
        }
    }

    if (i == deviceNums) {
        cout << "该设备不存在" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
        return;
    }

    // 判断管理员编号是否存在
    int personNums = personList->length();
    bool isExistPerson = false;
    for (int i = 0; i < personNums; i++) {
        Person person;
        personList->getData(i, person);
        if (person.getId() == personId) {
            isExistPerson = true;
            break;
        }
    }
    if (!isExistPerson) {
        cout << "不存在该管理员" << endl;
        cout << "输入任意字符退出" << endl;
        char n;
        cin >> n;
        return;
    } else {

        cout << "请确认: deviceId-" << deviceId << ", clazz-" << clazz << ", personId-" << personId << endl;
        cout << "<y/n>: ";
        char n;
        cin >> n;
        if (n == 'y') {
            Device device;
            device.setDeviceId(deviceId);
            device.setClazz(clazz);
            device.setPersonId(personId);
            deviceList->setData(i, device);
        }
    }
}

int main() {
    View view;
    while (view.mainView());
    system("clear");
    cout << "________                          \n"
            "\\_____  \\  ___  __  ____  _______ \n"
            " /   |   \\ \\  \\/ /_/ __ \\ \\_  __ \\\n"
            "/    |    \\ \\   / \\  ___/  |  | \\/\n"
            "\\_______  /  \\_/   \\___  > |__|   \n"
            "        \\/             \\/         " << endl;
    int n;
    cin >> n;
}

