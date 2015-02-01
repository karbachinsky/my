#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <exception>
#include <queue>
#include <unordered_set>
#include <stdexcept>

//#define DEBUG

const size_t N = 8;

class Node;

typedef std::shared_ptr<Node> node_ref_t;
typedef std::vector<node_ref_t> nodes_t; 

class Node {
public:
    Node(size_t i, size_t j) : i_(i), j_(j) {} 
    void addNode(const node_ref_t node) {
        nodes_.push_back(node);
    }
    const nodes_t getNodes() const {
        return nodes_;
    }

    void setBackNode(const node_ref_t node) {
        back_node_ = node;
    }
    
    const node_ref_t getBackNode() const {
        return back_node_;
    }

    friend bool operator==(const Node&, const Node&);

    size_t getI() const {return i_;}
    size_t getJ() const {return j_;}
private:
    const size_t i_;
    const size_t j_;
    nodes_t nodes_; 
    // Node from which we came here
    node_ref_t back_node_;
};

bool operator==(const Node& x, const Node& y) {
    return x.i_ == y.i_ and x.j_ == y.j_;
}


const std::vector<std::pair<size_t, size_t> > POSIBLE_ACTIONS = {
    {2,1},
    {2,-1},
    {1,2},
    {1,-2},
    {-1,2},
    {-1,-2},
    {-2,1},
    {-2,-1}
};

int main(int argc, char* argv[]) {
    size_t start_i, start_j, end_i, end_j;

    try {
        start_i = std::atoi(argv[1]);
        start_j = std::atoi(argv[2]);
        end_i = std::atoi(argv[3]);
        end_j = std::atoi(argv[4]);

        if (start_i >= N || start_j >= N || end_i >= N || end_j >= N) {
            throw std::runtime_error("");
        }
    }

    catch (std::exception &e) {
        std::cerr << "Bad arguments passed! Note board size is " << N << "x" << N << "." << std::endl;
        return 1;
    }

#ifdef DEBUG
    std::cout << "Starting data: " << start_i << " " << start_j << " " << end_i << " " << end_j << std::endl;
#endif

    std::vector<nodes_t> matrix;       
    matrix.resize(N);

    // Constructing matrix    
    for (size_t i=0; i<N; ++i) {
        matrix[i].resize(N);
        for (size_t j=0; j<N; ++j) {
            matrix[i][j] = std::shared_ptr<Node>(new Node(i,j));
        }
    }

    // Constructing graph
    for (size_t i=0; i<N; ++i) {
        for (size_t j=0; j<N; ++j) {
            for(auto action=POSIBLE_ACTIONS.begin(); action!=POSIBLE_ACTIONS.end(); ++action) {
                size_t new_i = i + action->first;
                size_t new_j = j + action->second;
                if (new_i > 0 && new_j > 0 && new_i < N && new_j < N) {
#ifdef DEBUG
                    std::cout << "add [" << i << "][" << j << "] = [" << new_i << "][" << new_j << "]" << std::endl;
#endif
                    matrix[i][j]->addNode(matrix[new_i][new_j]);    
                }
            }
        }
    }
  
    // Searching. Implementing BFS
    node_ref_t start_node = matrix[start_i][start_j];
    node_ref_t end_node = matrix[end_i][end_j];

    bool is_found = false;

    std::queue<node_ref_t> nodes_queue;
    std::unordered_set<node_ref_t> visited_nodes;
    nodes_queue.push(start_node);
    node_ref_t node;
    
    while (!is_found) {
        if (nodes_queue.empty()) {
            break;
        }

        node = nodes_queue.front();
#ifdef $DEBUG
        std::cout << "Check:  " << node->getI() << " " << node->getJ() << std::endl;
#endif

        if (*node == *end_node) {
            is_found = true;
        }
        else {
            const nodes_t child_nodes = node->getNodes();
            for (auto it=child_nodes.begin(); it!=child_nodes.end(); ++it) { 
                if (visited_nodes.find(*it) == visited_nodes.end()) {
                    (*it)->setBackNode(node);
                    nodes_queue.push(*it);
                }
            }
        }

        visited_nodes.insert(node);

        nodes_queue.pop();
    }

    if (is_found) {
        std::cout << "Found! See the Way we've got it: " << std::endl;
        // Unrolling nodes from aim node
        node_ref_t view_node = node;
        while (view_node != nullptr) {
            std::cout << view_node->getI() << " " << view_node->getJ() << std::endl;
            view_node = view_node->getBackNode();
        }
    }
    else {
        std::cout << "Not found!" << std::endl;
    }
}
