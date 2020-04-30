#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

void comparing(int **ar, int size)
{

//size=total number of test cases
    float tc=0;//tc=total comparisons
    float cy=0;//cy=total copied indexes
    float p=0;//p=percentage of similarty
    for(int r_main=0; r_main<size; r_main++)// r_main the primary file that is being compared 
    {
        tc=0;
        cy=0;
        p=0;

        for(int r=0; r<size; r++)// r the secondary file that is being compared
        {

            tc=0;
            cy=0;
            p=0;
            if(r_main!=r)
            {
                tc=0;
                cy=0;
                p=0;
                for(int i=0; i<228; i++)
                {

                    tc=tc+ar[r_main][i];

                    if(ar[r][i]!=0 || ar[r_main][i]!=0)
                    {
                        int x=0;
                        if(ar[r_main][i]<=ar[r][i])
                            x=ar[r_main][i];
                        else
                            x=ar[r][i];

                        cy=cy+x;
                    }
                }

                //tc=227;
                p=cy/tc;
                p=p*100;
                //cout<<cy<<" "<<tc<<endl;
                cout<<"\n-->>\t"<<"\""<<NameArr[r_main]<<"\""<<" and "<<"\""<<NameArr[r]<<"\""<<" \t"<<"programes have "<<p<<" percent similarity."<<endl;

            }
            else
                continue;
        }
    }
}