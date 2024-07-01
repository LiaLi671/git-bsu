//struct_books
#pragma once
#include <QTextStream>
#include <QDataStream>
#include <QString>
using namespace std;
struct struct1
{
    int Amount;
    double Cost;
    QString Name;
    struct1();
    struct1(int a0, double c0, QString n0);
    struct1(const struct1& r);
    struct1& operator=(const struct1& r1){
        Amount = r1.Amount;
        Cost = r1.Cost;
        Name = r1.Name;
        return *this;
    }
    friend bool operator==(const struct1& r1, const struct1& r2){
        if (r1.Name == r2.Name)
            return true;
        else
            return false;
    }
    friend QDataStream &operator>> (QDataStream &in, struct1& r){
        in >> r.Name;
        in >> r.Amount;
        in >> r.Cost;
        return in;
    }
    friend QDataStream &operator<< (QDataStream &os, struct1& r){
        os << r.Name;
        os << r.Amount;
        os << r.Cost;
        return os;
    }
    friend QTextStream &operator>> (QTextStream &in, struct1& r){
        r.Name = in.readLine(60);
        in >> r.Amount;
        in >> r.Cost;
        return in;
    }
    friend QTextStream &operator<< (QTextStream &os, struct1& r){
        os << r.Name << '\t' << r.Amount<< '\t' <<r.Cost << '\n';
        return os;
    }
};

