#ifndef RECOGNIZEDCARD_H
#define RECOGNIZEDCARD_H
#include <QString>
#include <iostream>
class RecognizedCard
{
    std::size_t health;
    std::size_t mana;
    std::size_t attack;
    QString description;
    QString name;
    QString cls;
    QString quanity;
    std::vector<QString> mechanics;
public:
    RecognizedCard(std::size_t h,std::size_t m,std::size_t a,QString d,QString c,std::vector<QString> mechs);
    RecognizedCard();
    std::size_t getHealth() const;
    void setHealth(const std::size_t &value);
    std::size_t getMana() const;
    void setMana(const std::size_t &value);
    std::size_t getAttack() const;
    void setAttack(const std::size_t &value);
    QString getDescription() const;
    void setDescription(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    QString getCls() const;
    void setCls(const QString &value);
    QString getQuanity() const;
    void setQuanity(const QString &value);
    void addMechanics(QString mech);
    std::vector<QString> getMechanics() const;
    void setMechanics(const std::vector<QString> &value);
};

#endif // RECOGNIZEDCARD_H
