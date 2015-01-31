#include <iostream>

using namespace std;


int main(){
    int node;
    int nVert;
    int x, y;
    int graph[6][6] = {0};

    cout<<"Enter the number of vertex:\t";
    cin>>nVert;

    cout<<"Enter the vertexs followed by enter (x y):\t";
    for (int i = 0; i < nVert; i++) {
        cin>>x>>y;
        graph[x-1][y-1] = 1;
    }

    cout<<"\t";

    for (int i = 0; i < 6; i++)
        cout<<i+1<<"\t";
    cout<<endl;

    for (int i = 0; i < 6; i++) {
        cout<<i+1<<"\t";
        for (int j= 0; j < 6; j++) {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter a node :\t";

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if((i == node || j == node) )
        }
    }

    return 0;
}
