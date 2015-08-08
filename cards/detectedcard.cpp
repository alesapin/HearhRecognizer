#include "detectedcard.h"


int DetectedCard::getMana() const
{
    return mana;
}

void DetectedCard::setMana(int value)
{
    mana = value;
}

int DetectedCard::getHealth() const
{
    return health;
}

void DetectedCard::setHealth(int value)
{
    health = value;
}

int DetectedCard::getAttack() const
{
    return attack;
}

void DetectedCard::setAttack(int value)
{
    attack = value;
}

QString DetectedCard::getDescription() const
{
    return description;
}

void DetectedCard::setDescription(const QString &value)
{
    description = value;
}

QString DetectedCard::getName() const
{
    return name;
}

void DetectedCard::setName(const QString &value)
{
    name = value;
}

QString DetectedCard::getType() const
{
    return type;
}

void DetectedCard::setType(const QString &value)
{
    type = value;
}

std::vector<QString> DetectedCard::getMechanics() const
{
    return mechanics;
}

void DetectedCard::setMechanics(const std::vector<QString> &value)
{
    mechanics = value;
}


DetectedCard::DetectedCard(const mongo::BSONObj &obj)
{
    health = obj.getIntField("health");
    mana = obj.getIntField("cost");
    attack = obj.getIntField("attack");
    description = QString(obj.getStringField("text"));
    type = QString(obj.getStringField("race"));
    if (type == ""){
        type = "Minion";
    }
    for(int i = 0;i<TextExtractor::MECHANICS.size();++i){
        if(description.indexOf(TextExtractor::MECHANICS[i]) >= 0){
            mechanics.push_back(TextExtractor::MECHANICS[i]);
        }
    }
    name = QString(obj.getStringField("name"));
}

DetectedCard::DetectedCard()
{
}
