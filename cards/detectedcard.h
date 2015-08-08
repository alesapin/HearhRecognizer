#ifndef DETECTEDCARD_H
#define DETECTEDCARD_H
#include <QString>
#include <vector>
#include "mongo/client/dbclient.h"
#include "mongo/bson/bsonobj.h"
#include "extractor/textextractor.h"
#include <iostream>
class DetectedCard
{
    int mana;
    int health;
    int attack;
    QString description;
    QString name;
    QString type;
    std::vector<QString> mechanics;

public:
    DetectedCard(const mongo::BSONObj& obj);
    DetectedCard();
    int getMana() const;
    void setMana(int value);
    int getHealth() const;
    void setHealth(int value);
    int getAttack() const;
    void setAttack(int value);
    QString getDescription() const;
    void setDescription(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    QString getType() const;
    void setType(const QString &value);
    std::vector<QString> getMechanics() const;
    void setMechanics(const std::vector<QString> &value);

};

#endif // DETECTEDCARD_H
