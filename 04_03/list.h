#ifndef LIST_H
#define LIST_H

class List;

class Node {
	private:
		int val_;
		Node *next_;

        Node(int n)
		: val_(n), next_(nullptr) {}

        int operator*() const {
            return val_;
        }

        bool operator==(const Node& rhs) const {
            return (val_ == rhs.val_) && (next_ == rhs.next_);
        }

        bool operator!=(const Node& rhs) const {
            return !(*this == rhs);
        }

    public:
        friend Node& operator+(const Node&, const Node&);
        friend std::ostream& operator<<(std::ostream&, const Node&);        
		friend class List;
};

class List {
	private:
		Node *head_;
		Node *tail_;

	public:
		List()
		: head_(nullptr), tail_(nullptr) {}

		void append(int);

		class myIter {
			private:
				Node *ptr_;

			public:
				explicit myIter(Node *ptr = nullptr)
				: ptr_(ptr) {}

				Node operator*() const {
                    return *ptr_;
				}

                bool operator==(const myIter& rhs) const {
                    if ((ptr_ == nullptr) && (rhs.ptr_ == nullptr)) {
                        return true;
                    }

                    else if ((ptr_ == nullptr) || (rhs.ptr_ == nullptr)) {
                        return false;
                    }
                    
                    return ptr_ == rhs.ptr_;
                }

                bool operator!=(const myIter& rhs) const {
                    return !(*this == rhs);
                }

                myIter& operator++() {
                    if (ptr_ != nullptr) {
                        ptr_ = ptr_->next_;
                    }
                    return *this;
                }

                myIter operator++(int) {
                    myIter temp(*this);
                    ++*this;
                    return temp;
                }
		};

		myIter begin() {
			return myIter(head_);
		}

		myIter end() {
			return myIter();
		}
};

class Add {
    public:
        template <typename T>
        T operator() (T a, T b) {
            return a + b;
        }
};

template <typename ptr_t>
void display(ptr_t first, ptr_t last) {
	while (first != last) {
		std::cout << *first << " ";
		first++; 
	}

	std::cout << "\n";
}

template <typename T, typename ptr_t, typename op_t>
T acc3(ptr_t first, ptr_t last, T init, op_t op) {
    while (first != last) {
        init = op(init, *first);
        ++first;
    }

    return init;
}
#endif