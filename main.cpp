#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    int size;
    srand(time(NULL));
    cout<<"Enter size: ";
    cin>>size;
    cout<<endl;

    int **mas=new int *[size];
    for (int i=0;i<size;i++)
        mas[i]=new int [size];

    bool **mas_bool=new bool*[size];
    for (int i=0;i<size;i++)
        mas_bool[i]=new bool[size];
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            mas_bool[i][j]=true;

    cout<<"Array of colors:"<<endl;
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            mas[i][j]=rand()%5+0;
            cout<<mas[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int value;
    vector<int> colors;

    cout<<"Select color:"<<endl;
    cout<<"Symbol - exit"<<endl<<"1-red"<<endl<<"2-orange"<<endl<<"3-yellow"<<endl
       <<"4-green"<<endl;;
    try{
        while(cin>>value){
            colors.push_back(value);
            if(value<=0||value>4)
                throw 1;
        }
        colors.shrink_to_fit();
        copy(colors.begin(),colors.end(), ostream_iterator<int>(cout," "));

    }
    catch(int){
        cout<<"We have only 4 colors...";
        return 1;
    }

    bool **search_square=new bool*[size];
    for (int i=0;i<size;i++)
        search_square[i]=new bool[size];

    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            search_square[i][j]=false;

    for(int k=0; k<colors.size(); k++){
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<size;j++)
            {
                value=colors[k];
                if((mas[i][j]==value&&mas[i][j])){
                    search_square[i][j]=true;
                }
            }
        }
    }
    cout<<endl;

    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            cout<<search_square[i][j]<<" ";
        }
        cout<<endl;
    }
    static int counter=0;
    bool key=false;
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if(search_square[i][j]==true)
            {
                counter+=1;
                if(j!=(size-1)&&search_square[i][j+1]==true){
                    if(i!=(size-1)&&search_square[i+1][j]==true){
                        if(search_square[i+1][j+1]==true){
                            cout<<"Max square: 2X2"<<endl;
                            search_square[i][j]=false;
                            search_square[i][j+1]=false;
                            search_square[i+1][j]=false;
                            search_square[i+1][j+1]=false;
                            key=true;
                        }
                    }
                }
            }
        }
    }
    if(!key&&counter>0)
        cout<<"Max square: 1X1"<<endl;
    cout<<endl;
    for(int i=0; i<size; i++){
        delete []mas[i];
        delete []search_square[i];
    }
    delete []mas;
    delete []search_square;
    return 0;
}
