#include<iostream>
#include<fstream>
#include "json/json.h"

using namespace std;

int main () {

  cout << "Test \n";

 /* string json_example =  "{"encoding" : "UTF-8", \
                            "plug-ins" : [\
                                           \"python",\
                                           \"c++",\
                                           "ruby"\
                                          ],\
                             "indent" :  { "length" : 3, "use_space": true }\
                            }\";

*/
//  string json_string = "{\"name\":\"latha\",\"age\":25}";
  std::ifstream json_file("my.json");

  Json::Reader reader;
  Json::Value root;
   
  bool parse_success = reader.parse(json_file, root, false);

 if(parse_success) {
      cout<<"Parsed success \n";
  } else {
     cout<<"Failed to parse \n";
  }

}
