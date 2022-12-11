
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>
#include "auto_v.h"
#include "auto_v.cpp"


// ecs36b


using namespace jsonrpc;
using namespace std;



class Motorcycle : public auto_v  // the data in here will be replaced by actual motorcycle constructor and other motorcycle functions?

{
	public:
	Motorcycle(){};
	bool isDanger;
    
    /*
public:
    Motorcycle(AbstractServerConnector &connector, serverVersion_t type);
    virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);

virtual Json::Value complete(); bool completed = false;

    std::map<std::string, Thing *> Thing_Map;
    std::map<std::string, Person *> Person_Map; 

	*/
};

#endif