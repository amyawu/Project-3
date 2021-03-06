# Project-3

////////////////NOTE///////////////////
Due to the enormous size of our data, it can't be uploaded onto Github.
The full source codes are in the branches. The main branch should be neglected.

////////////////////////// SPLAY TREE FUNCTION DECLARATIONS //////////////////////////
template <typename T>
class SplayTree
{
	/*===PRIVATE NESTED NODE STRUCT===*/
	struct Node 
	{
		// Stores data value and parent, left child, and right child pointers
		T* data;
		Node* parent;
		Node* left;
		Node* right;
		unsigned int count;

		// Constructor
		Node(T* data = nullptr, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
	};

	/*=== VERY IMPORTANT PRIVATE MEMBERS/FUNCTIONS CLUB ===*/
	Node* root;
	Node* maxNode;
	Node* endNode;
	unsigned int numNodes;
	
	void adjustMax();
	// Rotation/Zig-zag operations
	void rotateLeft(Node* N);
	void rotateRight(Node* N);
	void splay(Node* N);

public:
	/*===ITERATOR struct===*/
	struct iterator
	{
		Node* beginPtr;
		Node* nodePtr;
		Node* endPtr;
		unordered_set<Node*> visited;
	public:
		// Constructor
		iterator(Node* nodePtr = nullptr,  Node* endPtr = nullptr);
		// increment operators (++)
		iterator& operator++();			// pre increment
		iterator operator++(int);		// post increment
		// decrement operators (--)
		iterator& operator--();			// pre decrement
		iterator operator--(int);		// post decrement
		// equality (==)
		bool operator==(const iterator& rhs) const;
		// inequality (!=)
		bool operator!=(const iterator& rhs) const;
		// dereference (*)
		const T& operator*() const;
		T& operator*();
		// indirect member access operator
		T* operator->() const;

	};
	// Return iterator begin
	iterator begin();
	// Return iterator end
	iterator end();

	/*=== VERY IMPORTANT FUNCTIONS ===*/
	// Constructor
	SplayTree();
	SplayTree(T& data);
	// empty
	bool empty() const;
	// size
	unsigned int size() const;
	// peek
	T& peek() const;
	// insert
	bool insert(T& val);
	// erase
	void erase(T& val);
	// clear
	void clear();
	// find
	iterator find(T& val);
	// count
	unsigned int count(T& val);
	// Destructor
	~SplayTree();
};
	
	
///////////////////////////////////////////////////////////UNORDERED MAP////////////////////////////////////////////////////////////
	The unordered map is quite self explanatory in the Unordered Map branch. The main branch was a baby code for reading in data for
	both the tree and the map. 
	
