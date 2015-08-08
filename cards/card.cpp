#include "card.h"




QString Card::getHealth() const
{
    return health;
}

void Card::setHealth(const QString &value)
{
    health = value;
}

QString Card::getMana() const
{
    return mana;
}

void Card::setMana(const QString &value)
{
    mana = value;
}

QString Card::getAttack() const
{
    return attack;
}

void Card::setAttack(const QString &value)
{
    attack = value;
}

QString Card::getDescription() const
{
    return description;
}

void Card::setDescription(const QString &value)
{
    description = value;
}

QString Card::getName() const
{
    return name;
}

void Card::setName(const QString &value)
{
    name = value;
}

QString Card::getCls() const
{
    return cls;
}

void Card::setCls(const QString &value)
{
    cls = value;
}

QString Card::getQuanity() const
{
    return quanity;
}

void Card::setQuanity(const QString &value)
{
    quanity = value;
}
Card::Card()
{
}

Card::Card(QString h, QString m, QString a, QString d, QString c)
{
    health = h;
    mana = m;
    attack = a;
    description = d;
    cls = c;
}

Card::Card(QString h, QString m, QString a, QString d, QString n, QString c, QString q)
{
    health = h;
    mana = m;
    attack = a;
    description = d;
    name = n;
    cls = c;
    quanity = q;
}


