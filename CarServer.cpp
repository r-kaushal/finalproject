
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
 #include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include "Person.h"
#include "Thing.h"
#include <time.h>
#include "GPS_DD.h"
#include "hw5server.cpp"
#include "hw5client.h"
#include "Motorcycle.h"
#include "Car.h"
#include "auto_v.h"

using namespace jsonrpc;
using namespace std;

int main(){

  //  HttpClient httpclient("http://127.0.0.1:7376");
  // hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
   Json::Value myv, filler;
  // filler["Location"] = "Grandma's Home";




  HttpClient httpclient1("http://127.0.0.1:7377/%22");
   hw5Client myClient1(httpclient1, JSONRPC_CLIENT_V2);
   // Json::Value myv, filler;
   filler["Location"] = "";

    Json::Value InfoRequest;

    InfoRequest["InfoRequest"] = "A car may hit your motorcycle. Please send information.";

    try {
    myv = myClient1.move("move", "InfoRequest",
            InfoRequest,
            filler,
            "InfoRequest");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }
    cout << " \n Sending the following message : \n " << myv.toStyledString();





    HttpServer httpserver(7374);
 Myhw5Server s(httpserver,
JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)


  // Json::Value myv, filler;
  

    cout << " \n The following is data that will be received from the motorcycles. (Will show after running motorcycle)" << endl;

  
  while(!s.completed){
    s.StartListening();
  }
      s.StopListening();

 
    Car car;
		Motorcycle motoLeft;
    Motorcycle motoRight; // we will put some info in motoLeft soon
    

    int counter = 0;
    for(auto i = s.Motorcycle_Map.begin(); i != s.Motorcycle_Map.end(); i++){

          if(counter==0){
          motoRight.JSON2Object(s.Motorcycle_Map[i->first]->dump2JSON());
          }
        else{
          motoLeft.JSON2Object(s.Motorcycle_Map[i->first]->dump2JSON());
    }

    counter++;

    
      }

   string motoHit = car.chooseCrash(motoLeft,motoRight);
    cout << "\n The car will hit " << motoHit << "\n";

     HttpClient httpclient("http://127.0.0.1:7375/%22");
   hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
   // Json::Value myv, filler;
   filler["Location"] = "";

    Json::Value Warning;

    Warning["Warning"] = "The car is going to hit " + motoHit;
    Warning["Carhit"] = motoHit; // motoHit defined on line 71

    try {
    myv = myClient.move("move", "Warning",
            Warning,
            filler,
            "Motorcycle Right");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << "Here is the message that will be sent to the motorcycles: " << endl;
  cout << myv.toStyledString() << endl; // this is printing out the transfer motorcycle's data when it is run





  cout << "\n ";
return 0;
}