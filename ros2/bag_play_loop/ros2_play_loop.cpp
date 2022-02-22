#include <iostream>
#include <unistd.h>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<std::string> bag_path;
    std::cout<<argc<<std::endl;
    std::cout<<argv[0]<<", "<<argv[1]<<std::endl;
    if(argc>1){
        for(int i=1; i<argc;i++){
            bag_path.push_back(argv[i]);
        }
    }
    else{
        std::clog<<"[Usage] ./ros2_play_loop <bag_folder_path> <bag_folder_path2> ... \n";
        return 0;
    }

    std::clog <<"   This program loop play ros2 bag file.\n";
    std::clog <<"   It keeps running “forever” until we stop it with CTRL+C\n";

    int program_counter=1;
    while(true)
    {
        std::clog <<"[Number of Runs: "<<program_counter<<"]"<<std::endl;
        for(int i=0; i<argc-1; i++){
            std::string cmd = "ros2 bag play ";
            cmd += bag_path[i];
            std::cout<<cmd<<std::endl;
            system(cmd.c_str());
            sleep(1);
        }
        program_counter+=1;
    }
    return 0;
}