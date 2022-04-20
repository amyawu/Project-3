# Project-3

Important Splay Tree Functions and Members:
/*===ITERATOR CLASS===*/
    class iterator
    {
    public:
        // Constructor
        iterator(Node* nodePtr = nullptr,  Node* endPtr = nullptr);
        // increment operators (++)
        iterator& operator++();            // pre increment
        iterator operator++(int);        // post increment
        // decrement operators (--)
        iterator& operator--();            // pre decrement
        iterator operator--(int);        // post decrement
        // equality (==)
        bool operator==(const iterator& rhs) const;
        // inequality (!=)
        bool operator!=(const iterator& rhs) const;
        // dereference (*)
        const Node& operator*() const;
        Node& operator*();
    };
    // Return iterator begin
    iterator begin();
    // Return iterator end
    iterator end();

/*=== VERY IMPORTANT FUNCTIONS ===*/
	// Constructor
	SplayTree();
	SplayTree(T& data);
	// Copy constructor
	SplayTree(const SplayTree& other);
	// Copy assignment operator
	SplayTree& operator=(const SplayTree& other);
	// empty
	bool empty() const;
	// size
	unsigned int size() const;
	// peak
	T& peak() const;
	// insert
	bool insert(T& val);
	// pop
	T& pop();
	// erase
	void erase(iterator position);
	void erase(const T& val);
	// clear
	void clear();
	// find
	iterator find(const T& val) const;
	// count
	unsigned int count(const T& val) const;
	// Destructor
	~SplayTree();