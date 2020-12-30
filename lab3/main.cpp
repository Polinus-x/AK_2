#include <getopt.h>
#include <iostream>

bool counter[4] = {false, false, false, false};

void PrintHelp(){
    std::cout <<
              "Help. Allowed commands:\n\t"
              "-l / --list\n\t"
              "-v / --variable\n\t"
              "-g / --greet\n\t"
              "-h / --help\n";
}

void ProcessArgs(int argc, char** argv) {
    const char* const short_opts = "l:v:gh";

    const option long_opts[] = {
            {"list", required_argument, nullptr, 'l'},
            {"variable", required_argument, nullptr, 'v'},
            {"greet", no_argument, nullptr, 'g'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true){
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt) {
            case 'l':
                if(!counter[0]){
                    std::cout << "list = " << optarg << std::endl;
                    counter[0] = true;
                }
                break;
            case 'v':
                if(!counter[1]) {
                    std::cout << "variable = " << optarg << std::endl;
                    counter[1] = true;
                }
                break;

            case 'g':
                if(!counter[2]) {
                    std::cout << "Hello user!\n";
                    counter[2] = true;
                }
                break;
            case 'h':
                if(!counter[3]) {
                    PrintHelp();
                    counter[3] = true;
                }
                break;
            case '?':
            default:
                std::cout << "Unknown option! Try again.\n";
        }
    }
}

int main(int argc, char **argv)
{
    ProcessArgs(argc, argv);
    return 0;
}
