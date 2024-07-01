#pragma once
#include <QTextStream>
#include <QDataStream>
#include <QString>
using namespace std;

struct  struct2
{
    int id;
    QString student_name;
    struct2();
    struct2(int id0, QString st0);
    struct2(const struct2& r);
    struct2& operator=(const struct2& r1){
        id = r1.id;
        student_name = r1.student_name;
        return *this;
    }
    friend bool operator==(const struct2& r1, const struct2& r2){
        if (r1.id == r2.id and r1.student_name == r2.student_name)
            return true;
        else
            return false;
    }
    friend QDataStream &operator>> (QDataStream &in, struct2& r){
        in >> r.id;
        in >> r.student_name;
        return in;
    }
    friend QDataStream &operator<< (QDataStream &os, struct2& r){
        os << r.id;
        os << r.student_name;
        return os;
    }
    friend QTextStream &operator>> (QTextStream &in, struct2& r){
        in >> r.id;
        r.student_name = in.readLine(60);
        return in;
    }
    friend QTextStream &operator<< (QTextStream &os, struct2& r){
        os << r.id << '\t' << r.student_name<< '\n';
        return os;
    }
};

