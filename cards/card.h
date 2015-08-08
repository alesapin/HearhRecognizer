#ifndef CARD_H
#define CARD_H
#include <vector>
#include <QString>


class Card
{
    QString health;
    QString mana;
    QString attack;
    QString description;
    QString name;
    QString cls;
    QString quanity;
public:
    Card();
    Card(QString h,QString m,QString a,QString d,QString c);
    Card(QString h,QString m,QString a,QString d,QString n,QString c,QString q);
    QString getHealth() const;
    void setHealth(const QString &value);
    QString getMana() const;
    void setMana(const QString &value);
    QString getAttack() const;
    void setAttack(const QString &value);
    QString getDescription() const;
    void setDescription(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    QString getCls() const;
    void setCls(const QString &value);
    QString getQuanity() const;
    void setQuanity(const QString &value);


};

#endif // CARD_H
