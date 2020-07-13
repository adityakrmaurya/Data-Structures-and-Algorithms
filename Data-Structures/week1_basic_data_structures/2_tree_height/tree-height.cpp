#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
  int key;
  Node *parent;
  std::vector<Node *> children;

  Node() { this->parent = NULL; }

  void setParent(Node *theParent) {
    parent = theParent;
    parent->children.push_back(this);
  }
};

int findHeight(std::vector<Node> &nodes, std::vector<bool> &visited,
               std::vector<int> &height, int i) {
  // Check if root node
  if (nodes[i].parent == NULL) {
    visited[i] = 1;
    return 0;
  }
  // check if node is visited
  if (visited[i]) {
    return height[i];
  }
  // if not visited then visit the node and calculate its height
  visited[i] = 1;
  height[i] = 1 + findHeight(nodes, visited, height, (nodes[i].parent)->key);
  return height[i];
}
int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }
  
  int maxHeight = 0;
  std::vector<bool> visited(n, 0);
  std::vector<int> height(n, 0);
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      // Calculates height of node if not visited
      height[i] = findHeight(nodes, visited, height, i);
    }
    // maxHeight checked
    maxHeight = std::max(height[i], maxHeight);
  }
  std::cout << maxHeight + 1 << std::endl;
  return 0;
}

int main(int argc, char **argv) {
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }

#endif
  return main_with_large_stack_space();
}
