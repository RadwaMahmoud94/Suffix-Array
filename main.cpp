#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<bits/stdc++.h>
#define NumberOfCharcter 10000
using namespace std;
//struct : suffix has feature like id of suffix and character
struct sfx
{
    int sfxId;

    char *sfxChar;
};
/*******************************************************************/
/*function compare return intger value (0,1) refer to which of them is smaller suffix
this function takes 2 suffix as paramters and compare between them */
int  compareSfx(sfx suffix1,sfx suffix2)
{
    int i=0;
    int key=-1;
    while(key==-1)
    {
        /*if (suffix1.sfxChar[i] ==NULL)
                {
                    key =0;
                    break;
                }*/
        if (suffix1.sfxChar[i]<suffix2.sfxChar[i])
        {
            key=1;
        }
        else if (suffix1.sfxChar[i]>suffix2.sfxChar[i])
        {
            key=0;
        }

        i++;
    }
    return key;
}
/*******************************************************************/
/*this function build suffix array by taking original string and its length
then inserting ids and characters for each suffix
then sorting it lexicographically */
sfx *insertArray( char* x,int n)
{
    sfx* arr= new sfx[n];
    for (int i=0; i < n; i++)
    {
        // cout<<i<<endl;
        arr[i].sfxId=i;
        arr[i].sfxChar= x+i;
    }
    sort(arr,arr+n,compareSfx);
    return arr;

}
/*******************************************************************/
//
/*char* scanFile()
{  char *buf = new char [NumberOfCharcter];
    FILE* file;
    file=fopen("genome.txt", "r");
    char* read = new char [70];
    fscanf(file, "%[^\n\r] ", read); // Ignore this line

    while(strlen(buf)<10000)
    {
      read[0]=0;
      fscanf (file, "%s", read);
      strcat(buf,read);
    //  cout<<buf;

    }
  //  cout<<endl<< sizeof(buf);
    fclose(file);
   // fflush(NULL);
    return buf;
}*/
char* scanFile()
{
    char *buf = new char [NumberOfCharcter];
	FILE* file;
	file=fopen("genome.txt", "r");
    char* read = new char [10000];
    buf[0]=0;
    read[0]=0;
    fscanf(file, "%[^\n\r] ", read); // Ignore this line

	while(strlen(buf)<10000) // Print the first valid 10 reads and their complements (20 printed reads)
	{
    read[0]=0; fscanf (file, "%s", read); strcat(buf,read);

   }
    fclose(file);
   // fflush(NULL);
    return buf;
}

int main()
{
    char *object=scanFile();
   // cout<< object;
    sfx* s = insertArray(object,10000);
    for(int i=0; i<10000; i++)
        cout<<s[i].sfxId<<"    ,  "<<s[i].sfxChar<<endl;

    return 0;
}
