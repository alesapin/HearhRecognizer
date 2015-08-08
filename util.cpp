#include "util.h"

Util::Util()
{
}


int Util::levensteinDistance(const QString &s1, const QString &s2)
{
    int s1len = s1.size();
    int s2len = s2.size();

    auto column_start = (decltype(s1len))1;

    auto column = new decltype(s1len)[s1len + 1];
    std::iota(column + column_start, column + s1len + 1, column_start);
    for (auto x = column_start; x <= s2len; x++) {
        column[0] = x;
        auto last_diagonal = x - column_start;
        for (auto y = column_start; y <= s1len; y++) {
            auto old_diagonal = column[y];
            auto possibilities = {
                column[y] + 1,
                column[y - 1] + 1,
                last_diagonal + (s1[y - 1] == s2[x - 1]? 0 : 1)
            };
            column[y] = std::min(possibilities);
            last_diagonal = old_diagonal;
        }
    }
    auto result = column[s1len];
    delete[] column;
    return result;
}

QString Util::maxSubstring(const QString &s1, const QString &s2)
{
    std::tuple<Matrix,ArrowTable> len= maxSubstringLength(s1,s2);
    QString result = maxSubstringRecur(std::get<1>(len),s1,s1.length(),s2.length(),QString(""));
    std::reverse(result.begin(),result.end());
    return result;
}



std::tuple<Matrix, ArrowTable> Util::maxSubstringLength(const QString &s1, const QString &s2)
{
    int m = s1.length()+1;
    int n = s2.length()+1;
    Matrix c(m);
    ArrowTable b(m);
    for(int i = 0; i<m;++i){
        c[i] = std::vector<int>(n);
        b[i] = std::vector<ARROWS>(n);
        for(int j=0;j<n;++j){
            c[i][j] = 0;
            b[i][j] = NO_ARROW;
        }
    }
    for(int i = 1 ;i<m;++i){
        for(int j = 1; j<n;++j){
            if (s1[i-1]==s2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = DIAGONAL_ARROW;
            } else{
                if (c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = UP_ARROW;
                } else {
                    c[i][j] = c[i][j-1];
                    b[i][j] = LEFT_ARROW;
                }
            }
        }
    }
    return std::make_tuple(c,b);
}

QString Util::maxSubstringRecur(const ArrowTable &tbl, const QString &s1, int s1len, int s2len, QString result)
{
    if(s1len == 0 || s2len == 0){
        return result;
    }
    if (tbl[s1len][s2len] == DIAGONAL_ARROW){
        return maxSubstringRecur(tbl,s1,s1len-1,s2len-1,result + s1[s1len-1]);
    }else if (tbl[s1len][s2len] == UP_ARROW){
        return maxSubstringRecur(tbl,s1,s1len-1,s2len,result);
    } else {
        return maxSubstringRecur(tbl,s1,s1len,s2len-1,result);
    }
}
