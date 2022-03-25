//"d:\\ints.txt"
//Gaurav Singh
#include <fstream>
#include<iostream>
#include <limits.h>
#include <stdio.h>

int minimumDist(int dist[], bool Tset[])
{
    int min=INT_MAX,index;

    for(int i=0;i<109;i++)
    {
        if(Tset[i]==false && dist[i]<=min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void Dijkstra(int graph[109][109],int src) // adjacency matrix used is 109x109
{
    int dist[109];
    bool Tset[109];

    for(int i = 0; i<109; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0;

    for(int i = 0; i<109; i++)
    {
        int m=minimumDist(dist,Tset);
        Tset[m]=true;
        for(int i = 0; i<109; i++)
        {
            // Updating the minimum distance for the particular node.
            if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
                dist[i]=dist[m]+graph[m][i];
        }
    }

}
int main()
{
    int myArray[546];                       //As txt file has 547 integers with first one being number of vertices
    int number_of_vertices;
    int graph[109][109];
    std::ifstream file("d:\\ints.txt");// text file has 152*3 +1=  547 integers 1st integer is number of vertex
    if(file.is_open())
    {
        file >> number_of_vertices;// now 1st integer is already read so left are 546
        for(int i = 0; i < 546; i++)
        {
            file >> myArray[i];
        }
    }
    for(int a=0;a<109; a++){
        for(int b=0;b<109;b++){
            graph[a][b]=0;
        }
    }
    for(int a = 0; a < 546; a+=3){

        int node1=myArray[a];//vertex1
        int node2=myArray[a+1];//vertex2
        graph[node1][node2]=myArray[a+2];//updating value of 2 dim matrix
        graph[node2][node1]=myArray[a+2];// making adjacency matrix with values being weights of path between two vertices
    }

    Dijkstra(graph,0);
    return 0;
}
