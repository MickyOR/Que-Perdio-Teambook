// Construccion de suffix tree en O(n) con algoritmo de Ukkonen
// corre mas lento que un suffix array O(n*logn) xD 
// queda pendiente encontrar implementacion mas eficiente
// Implementacion del algoritmo explicado en el libro de Dan Gusfield
// Detalles de implementacion importantes de https://codeforces.com/blog/entry/16780
struct ukkonen {
  static const int inf = 1e9;
  int root;
  int pos;          // Current position in the string, current i+1
  int remaining;    // Accumulated suffixes from previous phases, current i+1-j
  int activeNode;   // The node at or above s[j..i]
  int activeEdge;   // First character of s[j..i]. Not the character itself, but it's position
  int activeLength; // Length of down path from activeNode to the end of s[j..i]
  vector<int> suffixLink;
  int lastInternal; // Last visited or created internal node
  int currentNodes; // Current node size of the suffix tree
  vector<int> s;    // Original string

  struct treeEdge {
    int start, end; // [start, end)
    int leafStart = -1; // Value of j for leaf representing s[j..m]
  };

  vector<treeEdge> parenteEdge; // node -> tree edge from parent
  vector<unordered_map<int, int>> children; // node -> first letter of edge -> child node
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ USAR ESTO PARA RECORRER EL ARBOL  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  int edgeLength(treeEdge edge) {
    return min(edge.end, pos+1) - edge.start;
  }

  int newNode(int start, int end = inf) {
    int v = currentNodes++;
    parenteEdge[v] = treeEdge{start, end};
    return v;
  }

  void addSuffixLink(int v) {
    if (lastInternal != -1) suffixLink[lastInternal] = v;
    lastInternal = v;
  }

  void nextPhase() {
    int nextChar = s[++pos];
    remaining++;
    lastInternal = -1;
    while (remaining > 0) {
      if (activeLength == 0) activeEdge = pos;
      if (children[activeNode].find(s[activeEdge]) == children[activeNode].end()) {
        // Only enters when active length is 0, i.e. when inserting the last character
        int child = newNode(pos);
        children[activeNode][s[activeEdge]] = child;
        addSuffixLink(activeNode); // Lemma 6.1.1
      }
      else {
        int u = children[activeNode][s[activeEdge]];
        // Walk down
        if (edgeLength(parenteEdge[u]) <= activeLength) {
          activeEdge += edgeLength(parenteEdge[u]);
          activeLength -= edgeLength(parenteEdge[u]);
          activeNode = u;
          continue;
        }
        // Extension rule #3
        if (s[parenteEdge[u].start + activeLength] == nextChar) {
          activeLength++;
          addSuffixLink(activeNode); // Lemma 6.1.1
          break;
        }
        // Extension rule #2
        int midNode = newNode(parenteEdge[u].start, parenteEdge[u].start + activeLength);
        children[activeNode][s[activeEdge]] = midNode;
        int leaf = newNode(pos);
        children[midNode][nextChar] = leaf;
        parenteEdge[u].start += activeLength;
        children[midNode][s[parenteEdge[u].start]] = u;
        addSuffixLink(midNode); // Lemma 6.1.1
      }
      remaining--;
      // Go to first node at or above s[j+1..i]
      if (activeNode == root && activeLength > 0) {
        activeLength--;
        activeEdge = pos - remaining + 1;
      }
      else if (suffixLink[activeNode] != -1) {
        activeNode = suffixLink[activeNode];
      }
      else {
        activeNode = root;
      }
    }
  }

  // It is assumed that the last element of s does not appear anywhere else
  void buildSuffixTree(vector<int> &s) {
    this->s = s;
    int n = 2*s.size(); // maximum amount of nodes
    currentNodes = 1;
    suffixLink.assign(n, -1);
    children.resize(n);
    parenteEdge.resize(n);
    root = activeNode = 0;
    activeLength = 0;
    pos = -1;
    remaining = 0;
    parenteEdge[root] = treeEdge{-1, -1};
    for (int i = 0; i < s.size(); ++i) {
      nextPhase();
    }
    for (int v = 0, j = 0; v < currentNodes; ++v) {
      if (parenteEdge[v].end == inf) {
        parenteEdge[v].end = s.size();
        parenteEdge[v].leafStart = j++;
      }
    }
  }

  // It is assumed that the last element of str does not appear anywhere else
  void buildSuffixTree(string str) {
    vector<int> s;
    for (char c : str) s.push_back((int)c);
    buildSuffixTree(s);
  }
};
