#include <fstream>
#include <iostream>

#include "Person.cpp"
#include "Device.cpp"
#include "SeqList.cpp"

using namespace std;

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
        cin >> id >> name >> sex >> age;
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
        personList->insert(personList->size(), person);
    }
}

void View::deletePersonView() {

}

void View::updatePersonView() {

}

void View::queryDeviceView() {

}

void View::insertDeviceView() {

}

void View::deleteDeviceView() {

}

void View::updateDeviceView() {

}
