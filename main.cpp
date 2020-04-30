#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>
#include "step1VECTORS.h"
#include "step2TOKENIZING.h"
#include "step3FILLER.h"
#include "step4COMPARING.h"
#include <queue>
#include <regex> 

using namespace std;

int main(){
	string dir;
	cout << "Right Click and Paste the Directory from where files are to be compared: \n" << flush;
  	getline( cin, dir );

	vector<string> FileNames = FILENAMES(dir.c_str());

	//vector<string> FileNames = FILENAMES(s);
	//vector<string> FileNames = FILENAMES(path);

	int N=FileNames.size();

	cout<<N<<" Files Will Be Compared In This Order :"<<endl;
	
	int **FULL=new int*[N];
    for(int i=0;i<N;i++){
        FULL[i]=new int[228];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<228;j++){
            FULL[i][j]=0;
        }
    }
      cout<<"\n";
	for (int i = 0; i < N; i++)
	{
		FileNames[i]=dir+"\\"+FileNames[i];
		cout<<FileNames[i]<<endl;
	}
  cout<<"\n";
	for (int i = 0; i < N; i++)
	{
		vector<char> V;
        V=toStringArr(FileNames[i]);        
        //STEP 2 is here
        char *arr=NULL;
        arr=new char[V.size()];
        	//char arr[V.size()];
        	//copy(V.begin(),V.end(),arr);
        for(int j=0;j<V.size()-1;j++){
            arr[j]=V[j];
        }
        arr[V.size()-1]=' ';
        int *h;
        h=filler(arr);
       	for (int j = 0; j < 228; ++j)
       	{
        	FULL[i][j]=h[j];
       	}
       	V.clear();
       	delete[] arr;
       	arr=NULL;  
	}
	for(int i=0;i<N;i++){
		cout<<endl<<NameArr[i]<<" :: "<<endl;
		for(int j=0;j<228;j++){
			cout<<FULL[i][j]<<" ";
		}
		cout<<endl;
	}
	comparing(FULL,N);
	//getch();	
return 0;
}