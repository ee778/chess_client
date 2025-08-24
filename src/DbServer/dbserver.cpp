#include "dbserver.h"

DbServer::DbServer() {

}

DbServer *DbServer::getInstance()
{
    static DbServer dbserver;
    return &dbserver;
}

DbServer::~DbServer()
{

}
