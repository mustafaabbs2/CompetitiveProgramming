#include <iostream>
#include <unordered_map>
#include <vector>


// Node represents a node in the DAG
struct Node
{
    int data;
    std::vector<Node*> children;

    Node(int val) : data(val) {}
};

// DAG represents the Directed Acyclic Graph
class DAG
{
private:
    std::unordered_map<int, Node*> nodes;

public:
    // Add a node to the DAG
    void addNode(int data) { nodes[data] = new Node(data); }

    // Add a directed edge between two nodes
    void addEdge(int parentData, int childData)
    {
        nodes[parentData]->children.push_back(nodes[childData]);
    }

    // Traverse the DAG using Depth-First Search (DFS)
    void traverseDAG(Node* currentNode)
    {
        if (!currentNode)
        {
            return;
        }

        // Process the current node
        std::cout << currentNode->data << " ";

        // Recursively traverse children
        for (Node* child : currentNode->children)
        {
            traverseDAG(child);
        }
    }

    // Public method to initiate traversal
    void traverseDAG()
    {
        for (const auto& entry : nodes)
        {
            if (entry.second)
            {
                traverseDAG(entry.second);
            }
        }
    }
};

int main()
{
    // Create a DAG
    DAG dag;

    // Add nodes to the DAG
    dag.addNode(1);
    dag.addNode(2);
    dag.addNode(3);
    dag.addNode(4);
    dag.addNode(5);

    // Add edges to form a DAG
    dag.addEdge(1, 2);
    dag.addEdge(1, 3);
    dag.addEdge(2, 4);
    dag.addEdge(3, 5);

    // Traverse the DAG
    std::cout << "DAG traversal: ";
    dag.traverseDAG();
    std::cout << std::endl;

    return 0;
}
