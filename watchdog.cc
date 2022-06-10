#include<iostream>
#include<string>
#include<vector>
#include<thread>
#include<chrono>
#include<cstdlib>
#include<fstream>

bool process_is_running(std::string process_name){
  std::system(("ps -fC "+ process_name + "| grep " + process_name +" > out.txt").c_str());
  std::string file_content;
  std::getline(std::ifstream("out.txt"), file_content, '\0');
  return file_content.find(process_name)!=std::string::npos;
}

void start_process_in_background(std::string process_name){
  std::system((process_name+" &").c_str());
}

int main(){
  std::vector<std::string> process_names = {"processA", "processB"};
  for(;;){
    for(auto process_name: process_names){
      if(!process_is_running(process_name)){
        start_process_in_background("./"+process_name);
      }
    }
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(50ms);
  }
}
