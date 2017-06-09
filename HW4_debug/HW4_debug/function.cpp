#include <algorithm>
#include <vector>
#include <stack>
#include "function.h"

using namespace std;

//----------------------------------------------------------------------
//add an edge between the A and the B with weight
//if A or B doesn't exist in the graph,
//create new A or B in this graph too
//----------------------------------------------------------------------
void Implement::addEdge(const int label_1, const int label_2 , const int weight)
{
    //If same vertex, do nothing.
    if(label_1 == label_2){return;}
    //Record location of A and B.
    int l1loc = -1, l2loc = -1;
    for(int i = 0; i < VertexArr.size(); i++){
        if(VertexArr[i].label == label_1){
            l1loc = i;
        }
        if(VertexArr[i].label == label_2){
            l2loc = i;
        }
    }
    //If edge already exists between A and B, do nothing.
    if(l1loc != -1 && l2loc != -1){
        if(VertexArr[l1loc].neighbors.size() < VertexArr[l2loc].neighbors.size()){
            for(int i = 0; i < VertexArr[l1loc].neighbors.size(); i++){
                if(VertexArr[l1loc].neighbors[i].label == label_2){
                    return;
                }
            }
        }
        else{
            for(int i = 0; i < VertexArr[l2loc].neighbors.size(); i++){
                if(VertexArr[l2loc].neighbors[i].label == label_1){
                    return;
                }
            }
        }
    }
    //If A and/or B not found, create A and/or B.
    if(l1loc == -1){
        VertexArr.push_back(*new Vertex(label_1));
        l1loc = VertexArr.size() - 1;
    }
    if(l2loc == -1){
        VertexArr.push_back(*new Vertex(label_2));
        l2loc = VertexArr.size() - 1;
    }
    //Add edge with weight.
    Neighbor temp1, temp2;
    temp1.label = label_2;
    temp1.weight = weight;
    temp2.label = label_1;
    temp2.weight = weight;
    VertexArr[l1loc].neighbors.push_back(temp1);
    VertexArr[l2loc].neighbors.push_back(temp2);
    return;}
//----------------------------------------------------------------------
//delete an edge between A and B
//if this edge doesn't exist, then do nothing
//----------------------------------------------------------------------
void Implement::deleteEdge(const int label_1, const int label_2)
{
    //Record location of A and B.
    int l1loc = -1, l2loc = -1;
    for(int i = 0; i < VertexArr.size(); i++){
        if(VertexArr[i].label == label_1){
            l1loc = i;
        }
        if(VertexArr[i].label == label_2){
            l2loc = i;
        }
    }
    //If either A or B doesn't exist, do nothing.
    if(l1loc == -1 || l2loc == -1){
        return;
    }
    //Find and delete edge, or if not found, do nothing.
    else{
        for(int i = 0; i < VertexArr[l1loc].neighbors.size(); i++){
            if(VertexArr[l1loc].neighbors[i].label == label_2){
                VertexArr[l1loc].neighbors.erase(VertexArr[l1loc].neighbors.begin()+i);
                break;
            }
        }
        for(int i = 0; i < VertexArr[l2loc].neighbors.size(); i++){
            if(VertexArr[l2loc].neighbors[i].label == label_1){
                VertexArr[l2loc].neighbors.erase(VertexArr[l2loc].neighbors.begin()+i);
            }
        }
    }
    return;}
//----------------------------------------------------------------------
//delete the vertex A and all edges that connect to A, if A doesn't exist, do nothing
//----------------------------------------------------------------------
void Implement::deleteVertex(const int label)
{
    //Find and delete all edges in A, but record the vertexes.
    vector<int> labels;
    for(int i = 0; i < VertexArr.size(); i++){
        if(VertexArr[i].label == label){
            for(int j = 0; j < VertexArr[i].neighbors.size(); j++){
                labels.push_back(VertexArr[i].neighbors[j].label);
            }
            //Delete edges on A.
            VertexArr[i].neighbors.clear();
            //Delete A.
            VertexArr.erase(VertexArr.begin()+i);
            goto next_step;
        }
    }
    next_step:
    //Delete edges in recorded vertexes.
    for(int i = 0; i < labels.size(); i++){
        //bool check_next = false;
        //for(int j = 0; !check_next && j < VertexArr.size(); j++){
        for(int j = 0; j < VertexArr.size(); j++){
            if(VertexArr[j].label == labels[i]){
                //for(int k = 0; !check_next && k < VertexArr[j].neighbors.size(); k++){
                for(int k = 0; k < VertexArr[j].neighbors.size(); k++){
                    if(VertexArr[j].neighbors[k].label == label){
                        VertexArr[j].neighbors.erase(VertexArr[j].neighbors.begin()+k);
                        //check_next = true;
                    }
                }
            }
        }
    }
    return;}
//----------------------------------------------------------------------
//return the degree of vertex A, return 0 if A doesn't exist
//----------------------------------------------------------------------
int Implement::degree(const int label)
{
    for(int i = 0; i < VertexArr.size(); i++){
        if(VertexArr[i].label == label){
            int degrees = VertexArr[i].neighbors.size();
            return degrees;
        }
    }
    return 0;}
//----------------------------------------------------------------------
//return the total edge weight of vertex A, return 0 if A doesn't exist
//----------------------------------------------------------------------
int Implement::weight(const int label)
{
    for(int i = 0; i < VertexArr.size(); i++){
        if(VertexArr[i].label == label){
            int weight = 0;
            for(int j = 0; j < VertexArr[i].neighbors.size(); j++){
                weight += VertexArr[i].neighbors[j].weight;
            }
            return weight;
        }
    }
    return 0;}
//----------------------------------------------------------------------
//return true(bool) if there is at least one path between A & B, else return false(bool),
//if A or B doesn't exist in the graph, return false
//----------------------------------------------------------------------
bool Implement::isExistPath(const int label_1, const int label_2)
{
    //If same vertex, true.
    if(label_1 == label_2){
        return true;
    }
    //Use DFS. Return true if found.
    bool visited[1500000] = {false};
    stack<int> s;
    s.push(label_1);
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!visited[v]){
            visited[v] = true;
            for(int i = 0; i < VertexArr.size(); i++){
                if(VertexArr[i].label == v){
                    for(int j = 0; j < VertexArr[i].neighbors.size(); j++){
                        if(VertexArr[i].neighbors[j].label == label_2){
                            return true;
                        }
                        if(!visited[VertexArr[i].neighbors[j].label]){
                            s.push(VertexArr[i].neighbors[j].label);
                        }
                    }
                }
            }
        }
    }
    return false;}
//----------------------------------------------------------------------
//delete all vertexes and edges in the graph
//----------------------------------------------------------------------
void Implement::deleteGraph()
{
    for(int i = 0; i < VertexArr.size(); i--){
        //Delete edges.
        VertexArr[i].neighbors.clear();
    }
    //Delete vertexes.
    VertexArr.clear();
    return ;}
//----------------------------------------------------------------------
//return the numbers of the component, if this graph doesn't have any vertex, then return 0
//----------------------------------------------------------------------
int Implement::number_of_component()
{
    //Use DFS. Component++ each time. Return component when done.
    int components = 0;
    bool visited[1500000] = {false};
    stack<int> s;
    for(int k = 0; k < VertexArr.size(); k++){
        if(!visited[VertexArr[k].label]){
            components++;
            visited[VertexArr[k].label] = true;
            for(int j = 0; j < VertexArr[k].neighbors.size(); j++){
                if(!visited[VertexArr[k].neighbors[j].label]){
                    s.push(VertexArr[k].neighbors[j].label);
                }
            }
            while(!s.empty()){
                int v = s.top();
                s.pop();
                if(!visited[v]){
                    bool check_next = false;
                    visited[v] = true;
                    for(int i = 0; !check_next && i < VertexArr.size(); i++){
                        if(VertexArr[i].label == v){
                            for(int j = 0; j < VertexArr[i].neighbors.size(); j++){
                                if(!visited[VertexArr[i].neighbors[j].label]){
                                    s.push(VertexArr[i].neighbors[j].label);
                                }
                            }
                            check_next = true;
                        }
                    }
                }
            }
        }
    }
    
    return components;}
