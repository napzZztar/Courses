#include <iostream>
#include <vector>

#define arS 20

using namespace std;

int m;
int V;
bool graph[arS][arS] = {0};
int color[arS] = {0};
string colorName[6] = {" ", "Red", "Gre", "Blue", "Yellow", "Black"};

void init();
bool backTrack(); //assigns color to all nodes using with the help of backtrack
void print(); //print the adjacency matrix with color value

int main(){
    init();
    cout<<"Input the number of colors: ";
    cin>>m;
    m++;

    if(backTrack()){ //if backtrack returns false you need more colors
        print();
    }else{
        cout<<"Coloring not possible";
    }

    return 0;
}

void init(){ //assigns the value of the graph
    int edge;
    int s, d;
    cout<<"Please enter the number of edges: ";
    cin>>edge;
    cout<<"Please enter the number of Vertex: ";
    cin>>V;
    cout<<endl<<"Enter the edges(s-d) follwed by enter: ";

    for (int i = 0; i < edge; i++) {
        cin>>s>>d;
        graph[s][d] = 1; //Not a directed graph
        graph[d][s] = 1;
    }

    // graph[1][4] = 1;
    // graph[4][1] = 1;
    // graph[1][2] = 1;
    // graph[2][1] = 1;
    // graph[1][3] = 1;
    // graph[3][1] = 1;
    // graph[2][5] = 1;
    // graph[5][2] = 1;
    // graph[2][9] = 1;
    // graph[9][2] = 1;
    // graph[9][7] = 1;
    // graph[7][9] = 1;
    // graph[7][6] = 1;
    // graph[6][7] = 1;
    // graph[5][8] = 1;
    // graph[8][5] = 1;
    // graph[3][8] = 1;
    // graph[8][3] = 1;
    // graph[3][7] = 1;
    // graph[7][3] = 1;
    // graph[5][6] = 1;
    // graph[6][5] = 1;
    // graph[4][6] = 1;
    // graph[6][4] = 1;
    // graph[9][10] = 1;
    // graph[10][9] = 1;
    // graph[8][10] = 1;
    // graph[10][8] = 1;
    // graph[4][10] = 1;
    // graph[10][4] = 1;
}

bool backTrack(){
    int j;
    bool possible[V][m];

    for (int i = 1; i < V; i++)
        for (int j = 1; j < m; j++)
            possible[i][j] = 1; //making every color available for each node

    for (int i = 1; i < V; i++) {
        for (j = 1; j <= m; j++){
            if(possible[i][j]){ //if this color is still available for this node
                color[i] = j; //assign j as the color 
                possible[i][j] = 0; //make it unavailable
                break;
            }else if(j == m){ //if all 'm' colors are unavailable
                if(i==0) //at the begining of the graph
                    return false;
                i -= 2; //back up a littile bit
            }
        }

        for (int k = 1; k < V; k++) { //making assigned color(j) unavailable for adjacent nodes
            if(graph[i][k])
                possible[k][j] = 0;
        }
    }

    return true;
}

void print(){

    cout<<"\t";
    for (int i = 1; i < V; i++)
        cout<<i<<"("<<colorName[color[i]]<<")\t";  //if you get an error, your compiler's broken. Get a newer one.
    cout<<endl;

    for (int i = 1; i < V; i++) {
        cout<<i<<"("<<colorName[color[i]]<<")\t"; //if you get an error, your compiler's broken. Get a newer one.
        for (int j = 1; j < V; j++) {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
