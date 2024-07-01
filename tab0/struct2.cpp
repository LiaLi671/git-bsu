#include "struct2.h"
#include <QString>
using namespace std;

struct2::struct2(){
    id = 0;
    student_name = "..";
}
struct2::struct2(int id0, QString s0) : id(id0), student_name(s0) {}
struct2::struct2(const struct2& r) {
    student_name = r.student_name;
    id = r.id;
}
