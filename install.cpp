// A C++ program that compiles and runs another C++
// program
#include<bits/stdc++.h>
#include<dirent.h>
#include<string>
#include<chrono>
#include<thread>

void comp_list(std::string *str);
bool check_dir(std::string dirStr);

using namespace std;
int main ()
{
    cout << "Compiling cpp and h files in c:\\users\\iedward\\projects\\cppTutorials\n\n";

    // Build command to execute.
    string str = "g++ -std=c++11 -o ";

    string input;
    cout << "Enter a .exe file name: " << endl;
    cin >> input;

    str.append(input);
    for(int i = 0; i < 20; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << '-';
    }
    printf("\n");

    comp_list(&str);

    // Convert string to const char * as system requires
    // parameter of type const char *
    const char *command = str.c_str();

    cout << "Compiling file using " << command << endl;
    system(command);

    cout << "\nRunning file ";

    input.insert(0, "./");
    const char *run = input.c_str();
    system(run);

    return 0;
}

void comp_list(std::string *str){
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    DIR *dir;
    struct dirent *ent;
        if ((dir = opendir ("c:\\users\\iedward\\projects\\cppTutorial")) != NULL) {
            /* print all the files within directory */
            while ((ent = readdir (dir)) != NULL) {
                printf("file in dir: %s\n", ent -> d_name);
                if(check_dir(ent -> d_name)){
                    printf ("\tAdded to compilation list: %s\n", ent->d_name);
                    *str += " ";
                    *str += ent->d_name;
                }
            }
            closedir (dir);
        } else {
            /* could not open directory */
            perror ("");
        }
}

bool check_dir(std::string dirStr){
    std::cout << "\n\n\tENTERED CHECK_DIR: " << dirStr << std::endl;
    if(dirStr.at(0) != '.'){
        std::cout << "\n\n\tNO LEADING . " << dirStr << std::endl;
        for(int i = 0; i < dirStr.length(); i++){
            if(dirStr.at(i) == '.'){
                // should be rewritten using string.find();
                if(dirStr.at(++i) == 'h' && i == dirStr.length() - 1)
                    return true;
                else
                    i--;
                if(dirStr.at(++i) == 'c' && dirStr.at(++i) == 'p' && dirStr.at(++i) == 'p' && i == dirStr.length() - 1)
                    return true;
            }
        }
    }
    return false;
}
