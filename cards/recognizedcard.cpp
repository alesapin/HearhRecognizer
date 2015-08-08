#include "recognizedcard.h"


std::size_t RecognizedCard::getHealth() const
{
    return health;
}

void RecognizedCard::setHealth(const std::size_t &value)
{
    health = value;
}

std::size_t RecognizedCard::getMana() const
{
    return mana;
}

void RecognizedCard::setMana(const std::size_t &value)
{
    mana = value;
}

std::size_t RecognizedCard::getAttack() const
{
    return attack;
}

void RecognizedCard::setAttack(const std::size_t &value)
{
    attack = value;
}

QString RecognizedCard::getDescription() const
{
    return description;
}

void RecognizedCard::setDescription(const QString &value)
{
    description = value;
}

QString RecognizedCard::getName() const
{
    return name;
}

void RecognizedCard::setName(const QString &value)
{
    name = value;
}

QString RecognizedCard::getCls() const
{
    return cls;
}

void RecognizedCard::setCls(const QString &value)
{
    cls = value;
}

QString RecognizedCard::getQuanity() const
{
    return quanity;
}

void RecognizedCard::setQuanity(const QString &value)
{
    quanity = value;
}

void RecognizedCard::addMechanics(QString mech)
{
    mechanics.push_back(mech);
}

std::vector<QString> RecognizedCard::getMechanics() const
{
    return mechanics;
}

void RecognizedCard::setMechanics(const std::vector<QString> &value)
{
    mechanics = value;
}

RecognizedCard::RecognizedCard(std::size_t h, std::size_t m, std::size_t a, QString d, QString c, std::vector<QString> mechs)
{
    health = h;
    mana = m;
    attack = a;
    description = d;
    cls = c;
    mechanics = mechs;
}

RecognizedCard::RecognizedCard()
{
}
