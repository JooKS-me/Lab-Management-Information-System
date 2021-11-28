#include <string>

using namespace std;

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
