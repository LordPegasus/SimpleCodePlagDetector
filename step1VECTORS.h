#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>
#include <regex> 

using namespace std;

vector<string> NameArr;

vector<string> FILENAMES(const char *path){
	vector<string> V;
	struct dirent *entry;
	DIR *dir = opendir(path);
	if(dir!=NULL){
		while( (entry = readdir(dir)) != NULL ){
			string s = entry->d_name;
			/*if(s == "." || s == ".." || s == "output.txt" || s == "2dVector.cpp" || s == "a.exe" || s == "main.cpp" || s == "nice.cpp" || s == "output5.txt" || s == "step1VECTORS.cpp" || s == "step1VECTORS.h" || s == "step2TOKENIZING.cpp" || s == "step2TOKENIZING.h" || s == "step3FILLER.cpp" || s == "step3FILLER.h" || s == "step4COMPARING.cpp" || s == "step4COMPARING.h" ){continue;}
			else{
				V.push_back(s);
				NameArr.push_back(s);
			}*/
            regex b("(1.*)(.c)");
            if(regex_match(s, b)){
                V.push_back(s);
                NameArr.push_back(s); 
            }else{continue;}
		}
	}closedir(dir);
	return V;
}

vector<char> toStringArr(string s){
			string filename = s;
            ifstream fin(" ");
            fin.open( filename.c_str() );
            char my_character ;
            char arr[50000];
            vector<char> v;
            int i=0;
            while (!fin.eof() ) {
                fin.get(my_character);
                if(my_character==' '){
                    arr[i]=' ';
                    v.push_back(arr[i]);
                    i++;
                }
                else if(my_character=='\n'){
                    arr[i]=' ';
                    v.push_back(arr[i]);
                    i++;
                }
                else{
                    arr[i]=my_character;
                    v.push_back(arr[i]);
                    i++;
                }
            }
            fin.close();
            return v; 
}