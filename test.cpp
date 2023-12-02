#include <bits/stdc++.h>
using namespace std;

int getLen(int end)
{
    int ret = 0;
    while (end)
    {
        end /= 10;
        ret++;
    }

    return ret;
}

string toString(int x, int len)
{
    string ret = "";

    while (x)
    {
        ret = char('0' + x % 10) + ret;
        x /= 10;
        len--;
    }
    while (len--) ret = '0' + ret;

    return ret;
}

int main(int argc, char **argv) {
    //  char *file_path;
    if(argc < 2){
          return EXIT_FAIL;
    }
    else if(argc == 4) {
        // file_path = argv[1];
        // freopen("test.c","r",stdin);
        // freopen("test.out","w",stdout);
        
        string file_pre = argv[1];
        int st = toInt(argv[2]), end = toInt(argv[3]);
        int len = getLen(end);

        for (int i = st; i<= end; i++)
        {
            string file_num = toString(i, len);

            string file_name = file_pre + file_num;

            string in_file = "../test/" + file_name + ".spl";
            
            string out_file = "../out/" + file_name + ".out";

            // ifstream inputFile(in_file);
            // ofstream outputFile(out_file);
            freopen(in_file.c_str(),"r",stdin);
            freopen(out_file.c_str(),"w",stdout);

            cerr << out_file << endl;

            yyparse();

            // string line;

            // while (getline(inputFile, line)) {
            //     // cout << line << endl;
            // // 写入到输出文件
            // outputFile << line << std::endl;
            // }

            // inputFile.close();
            // outputFile.close();
        }
    //     cout<<"para_type------------"<<endl;
    //      for (const auto& pair : para_type) {
    //     std::cout << pair.first << ": " << pair.second.first << ' ' << pair.second.second << std::endl;
    //     }
        
    //     cout<<"func_type------------"<<endl;
    //      for (const auto& pair : func_type) {
    //     std::cout << pair.first << ": " << pair.second << std::endl;
    //     }
        
    //     cout<<"para_args------------"<<endl;
    //      for (const auto& pair : func_args) {
    //     std::cout << pair.first << ": " << std::endl;
    //     for (const auto& pair1: pair.second) {
    //     std::cout << pair1.first << ' ' << pair1.second <<  endl;
    //      cout<<endl;
    //     }
    //      }
        
    //     cout<<"struct_vars------------"<<endl;
    //       for (const auto& pair : struct_vars) {
    //     std::cout << pair.first << ": "<<std::endl;
    //     for (const auto& pair1: pair.second) {
    //     std::cout << pair1.first << ' ' << pair1.second.first << " " << pair1.second.second<< endl;

    //     // cout << getParaType("amy").second << endl;
    // }
    // }

    }
    else
    {
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
