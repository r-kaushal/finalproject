
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
#include <jsonrpccpp/client/connectors/httpclient.h>



using namespace jsonrpc;
using namespace std;

int main(){



  HttpServer httpserver1(7377); // this server is for receiving information requests from the car.
 Myhw5Server s1(httpserver1,
JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  cout << "Motorcycle Server waiting for message... \n";

  
  while(!s1.infoRequest){
  s1.StartListening();
  }
  if(s1.infoRequest){
    cout << " \n The motorcycles have a message from a car. Here is the message: \n" << endl;
  }
   s1.StopListening();
  

if(s1.infoRequest){
Motorcycle motoRight = Motorcycle();  // we will put some info in motoRight soon
  motoRight.setScore(96.0);
  motoRight.setAge(20.0);
  motoRight.setName("Right Motorcycle");
  motoRight.setPassengers(1);
  motoRight.setAvgWeight(156.5);


 HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv, filler;
  filler["Location"] = "Home!";
  
    cout << " \n The motorcycles now send their data: \n" << endl;

 
  // moving "motorcycle object" to the car, but the car really just needs the dump2Json(), so that it can analyze the data of the motorcyle. 

  try {
    myv = myClient.move("move", "Motorcycle",
			motoRight.dump2JSON(),
			filler,
			"Motorcycle Right");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << "\n The data of the right motorcycle has been sent." << endl; // this is printing out the transfer motorcycle's data when it is run


  Motorcycle motoLeft = Motorcycle();  // we will put some info in motoRight soon
  motoLeft.setScore(86.0);
  motoLeft.setAge(18.0);
  motoLeft.setName("Left Motorcycle");
  motoLeft.setEmergency();
  motoLeft.setPassengers(2);
  motoLeft.setAvgWeight(130.5);

 // HttpClient httpclient2("http://127.0.0.1:7375");
 // hw5client myClient2(httpclient2, JSONRPC_CLIENT_V2);
              
  Json::Value myv2, filler2; filler2["Location"] = "Home!"; // ignore, filler
  
  // moving "motorcycle object" to the car, but the car really just needs the dump2Json(), so that it can analyze the data of the motorcyle. 
  try {
    myv2 = myClient.move("move", "Motorcycle",
			motoLeft.dump2JSON(),
			filler2,
			"Motorcycle Left");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv2.toStyledString() << "\n The data of the left motorcycle has been sent." << endl; // this is printing out the transfer motorcycle's data when it is run

  Json::Value complete;
  try {
    complete = myClient.complete();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << complete.toStyledString() << endl; // this is printing out the transfer person's data under HomeServer when it is run
  

HttpServer httpserver(7375);
 Myhw5Server s(httpserver,
JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)


  while(!s.warningReceived){
  s.StartListening();
  }
   s.StopListening();


   if(s.carHit=="Motorcycle Right"){
     motoRight.isDanger = true;
    cout << "The right motorcycle has been warned." << endl;
       motoRight.braceForImpact();
   }
   else{
    motoLeft.isDanger = true;
    cout << "The left motorcycle has been warned." << endl;
    cout << "\n";
     motoLeft.braceForImpact();

   }

}
  

    cout << "\n ";
    return 0;
}

