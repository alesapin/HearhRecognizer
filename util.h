#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <vector>
#include <tuple>
#include <QDebug>
#include <algorithm>
enum ARROWS{
    NO_ARROW,UP_ARROW,LEFT_ARROW,DIAGONAL_ARROW
};
typedef std::vector<std::vector<int>> Matrix;
typedef std::vector<std::vector<ARROWS>> ArrowTable;

class Util
{
    static std::tuple<Matrix,ArrowTable> maxSubstringLength(const QString& s1,const QString& s2);
    static QString maxSubstringRecur(const ArrowTable& tbl,const QString& s1,int s1len,int s2len,QString result);

public:
    Util();
    static int levensteinDistance(const QString& s1,const QString& s2);
    static QString maxSubstring(const QString& s1,const QString& s2);

};

#endif // UTIL_H
