#include "dbconnector.h"

DBConnector::DBConnector(QString url):url(url)
{
}

void DBConnector::connect()
{
    connection = new mongo::DBClientConnection();
    connection->connect(url.toStdString());
}

std::vector<DetectedCard> DBConnector::getCardsByStats(int mana, int health, int attack)
{
    mongo::BSONObjBuilder b;
    if(health == 5){
        mongo::BSONArrayBuilder bab;
        bab << 3;
        bab << 5;
        mongo::BSONObjBuilder healthQ;
        healthQ.append("$in",bab.arr());
        b.append("health",healthQ.done());
    } else {
        b.append("health",health);
    }

    b.append("cost",mana);
    if(attack == 0){

    }else{
        b.append("attack",attack);
    }
    std::auto_ptr<mongo::DBClientCursor> cursor = connection->query("carddb.cards", b.obj());
    std::vector<DetectedCard> result;
    while(cursor->more()){
        result.push_back(DetectedCard(cursor->next()));
    }
    return result;
}

DBConnector::~DBConnector()
{
    delete connection;
}
