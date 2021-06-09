/* Disjoint Set Data Structure Implementation Using Array.
Following operations can be performed on the elemnets of this ds;

1) Union (x, y)
    -> Merge the set containing x and the set containing y, and the representative of
    the set will be the element with highest rank (if we are working on union by rank)
2) Find (x)
    -> Find the parent or the representative of the set which contain the element x
3) Make set(x)
    -> Creates a new set with only one element in it, which is x
    
Initially, in disjoint set data structure all the nodes or vertices are parent 
of itself. 
*/
class DisjointSet {
    private:
        map<int, int> parent;
        map<int, int> rank; // to store the rank of the root of the node
    public:
        DisjointSet(int size) {
            for(int i=1; i<=size; i++) makeSet(i);
        }
    
        DisjointSet() { return; }
    
        void makeSet(int i) {
            parent[i] = i;
            rank[i] = 1;
        }
    
        int findParent(int i) {
            if(parent[i] == i) return i;
            // if i is the parent of itself, then we have reached the root node
            // i.e. the element which represents the set
            
            // otherwise find the parent of the parent of i
            return findParent(parent[i]);
        }
    
        void performUnion(int x, int y) {
            int parentX = findParent(x);
            int parentY = findParent(y);
            
            if(parentX == parentY) 
                return;
            /* If both the elements are already present in the same set, then
            no need to perform union, hence return */
            
            if(rank[x] > rank[y]) {
                /* connect the set whose rank is less to the set whose rank is more...bcoz
                if we do so then the overall rank of the resulting set will be less */
                
                parent[parentY] = parentX;
            } else if(rank[x] < rank[y]) {
                parent[parentX] = parentY;
            } else {
                parent[parentX] = parentY;
                
                rank[parentX]++;
            }
        }
};

int main() {
    /* Suppose we have n nodes, on which we want to perform disjoint set operations
    Initially, all the nodes are parent of itself. */
    
    DisjointSet ds;
    
    ds.makeSet(5);
    ds.makeSet(10);
    ds.makeSet(15);
    ds.makeSet(20);
    
    cout << ds.findParent(5) << " " << ds.findParent(10) << " " << ds.findParent(15) << " " << ds.findParent(20);
    cout << endl;
    
    ds.performUnion(5, 20);
    cout << ds.findParent(5) <<  " " << ds.findParent(20) << endl;
    
    ds.performUnion(15, 20);
    ds.performUnion(10, 5);
    
    cout << ds.findParent(5) << " " << ds.findParent(10) << " " << ds.findParent(15) << " " << ds.findParent(20);
    cout << endl;
}
