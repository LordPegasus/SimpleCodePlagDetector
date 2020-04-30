#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>

using namespace std;


int* filler(char* str){
  int* arr=new int[228];
  //int FULL[N][228];
  for(int i=0;i<228;i++){
    arr[i]=0;
  }
    char *token = strtok(str," <>(){}[],;:\t");
    int row=0;
    while (token!=NULL)
    {

        row=tokenizing(token);
        //cout<<"Token is: "<<"\n[ "<<token<<" ]\n"<<" and VALUE IS : "<<row<<endl;
        //cout<<token<<""<<col<<endl;
        arr[row]++;
        token = strtok(NULL," <>(){}[],;:\t");
        row++;
    }
    //cout<<"---------------------------------"<<endl;
return arr;

}