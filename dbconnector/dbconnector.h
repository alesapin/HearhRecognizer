#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H
#include "cards/detectedcard.h"
#include "mongo/client/dbclient.h"
#include "mongo/bson/bsonobj.h"
#include <QString>
#include <vector>
class DBConnector
{
    QString url;
    mongo::DBClientConnection* connection;
public:
    DBConnector(QString url);
    void connect();
    std::vector<DetectedCard> getCardsByStats(int mana,int health,int attack);
    ~DBConnector();
};

#endif // DBCONNECTOR_H
