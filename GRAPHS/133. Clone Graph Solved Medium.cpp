PROBLEM:https://leetcode.com/problems/clone-graph/description/

/*

  IDEA IS SIMPLE
  1.since first node is given......create a copy of it
  2.take a map to check that for each node we have created a clone or not
  3.now call dfs
  4.visit neighbour
  5.now we have two scenario
   scene 1: its copy is not made previously..........then do the following
   i)create a copy of it
   ii)update in map that we have created its copy
   iii)connect the cloned node with its parent clone
   iv) call recursion to do further things

  scene 2: its copy is  made previously
   i)connect the cloned node with its parent clone
 6.return clone

  */

/*
  TIME COMPLEXITY: O(V+E)

  SC:AUXILIARY STACK SPACE ONLY
  */

class Solution {
public:
    unordered_map<Node*,Node*>mp; // to store node,clone_node
    void traverse(Node* node,Node* clone_node){
       // vector<Node*> l1=graph->neighbors;
        //vector<Node*> newNeighbour;
        // for(auto it:l1){
        //     if(mp.find(it)==mp.end()){
        //         Node* newNode=new Node(it->val);
        //         newNeighbour.push_back(newNode);
        //         root->neighbours=newNeighbour;
        //         traverse(it,newNode,mp);
        //     }

        // }

        /*
         fresh code starts here

         */

        //lets visit the neighbours of node

        for(Node* n:node->neighbors){

            //if clone of given node is not present

            if(mp.find(n)==mp.end()){
                //create a new clone of neighbour
                Node* clone=new Node(n->val);
                mp[n]=clone;
                //connecting cloned nodes

                clone_node->neighbors.push_back(clone);
                //recursively call its adjacent nodes

                traverse(n,clone);


            }
            else{
                clone_node->neighbors.push_back(mp[n]);
            }
        }



    }
    Node* cloneGraph(Node* node) {
      // unordered_map<Node*,int>mp;
      if(node==NULL)
       return NULL;
      mp.clear();
      //lets first create clone of the first given node

       Node* clone_node=new Node(node->val);
       mp[node]=clone_node;
       //calling our dfs function
       traverse(node,clone_node);
       return clone_node;
    }
};
  
