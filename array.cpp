#include<cstddef>
#include<ios>
#include<iostream>
#include<iterator>
#include<type_traits>
#include<vector>

template <typename T, uint32_t N>
class array {
	private:
		T elements[N];
	public:
		using value_type = T;
		using reference = T&;
		using const_reference = const T&;
		using pointer = value_type*;
		using const_pointer = const value_type *;
		using size_type = uint32_t;
		
		array() = default;
		array(const array&) = default;
		array<T, N>& operator=(const array&) = default;
		~array() = default;
		
		pointer data() noexcept { return elements; }
		const_pointer data() const noexcept { return elements; }
		
		reference front() { return elements[0]; }
		const_reference front() const { return elements[0]; }
		
		reference back() { return elements[N-1]; }
		const_reference back() const { return elements[N-1]; }
		
		reference operator[](size_t I) { return elements[I]; }
		const_reference operator[](size_t I) const {return elements[I]; }
		
		class array_iterator {
			private:
				pointer ptr;
				
			public:
				using value_type = T;
				using reference = T&;
				using difference_type = std::ptrdiff_t;
				using iterator_category = std::random_access_iterator_tag;
				
				array_iterator() : ptr{nullptr} {}
				array_iterator(pointer p) : ptr{p} {}
				
				array_iterator(const array_iterator& iter) : ptr{iter.ptr} {}
				array_iterator& operator=(const array_iterator& iter) {
					ptr = iter.ptr;
					return (*this);
				}
				
				reference operator*() { return *ptr; }
				const_reference operator*() const { return *ptr; }
				
				bool operator==(array_iterator other) {
					return ptr == other.ptr;
				}
				
				bool operator!=(array_iterator other) {
					return !(*this == other);
				}
				
				array_iterator& operator++() {
					++ptr;
					return (*this); 
				}
				
				array_iterator& operator--() {
					--ptr;
					return (*this);
				}
				
				array_iterator operator++(int) {
					array_iterator temp = (*this);
					++(*this);
					return temp;
				}
				
				array_iterator operator--(int) {
					array_iterator temp = (*this);
					--(*this);
					return temp;
				}
				
				array_iterator operator+(size_t off) {
					return { ptr + off };
				}
				
				array_iterator operator-(size_t off) {
					return { ptr - off };
				}
				
				std::ptrdiff_t operator-(array_iterator other) {
					return ptr - other.ptr;
				}
				
				array_iterator& operator+=(size_t offset) {
					ptr += offset;
					return (*this);
				}
				
				array_iterator& operator-=(size_t offset) {
					ptr -= offset;
					return (*this);
				}
		};
			
		using iterator = array_iterator;
			
		iterator begin() { return iterator(elements); }
		iterator end() { return iterator(elements + N); }
			
		uint32_t size() const { return N; }
};

int main(int argc, char *argv[]) {
	array<int, 4> A;

	std::cout << A.size() << std::endl;


	array<int, 4>::iterator begin, end, other;

	begin = end;

 	A[0] = 45;
  	A[1] = 100;
  	A[2] = 200;
  	A[3] = 23;

  	std::cout << A[0] << std::endl;
  	std::cout << A.front() << std::endl;
  	
  	A.front() = 10;
  	std::cout << A[0] << std::endl;

  	std::cout << std::is_same<array<int, 6>::value_type, int>::value << std::endl;

  	for (array<int, 4>::iterator first = std::begin(A), 
       	last = std::end(A); first != last; ++first) {
    			std::cout << "[array]: " << *first << std::endl;
  		}

  	std::cout << std::boolalpha << std::is_same<
     		std::iterator_traits<array<int, 4>::iterator>::iterator_category, 
      		std::bidirectional_iterator_tag
      	>::value << std::endl;

  	std::cout << std::boolalpha << std::is_same<
      		std::iterator_traits<typename std::vector<int>::iterator>::iterator_category,
      		std::random_access_iterator_tag
    	>::value << std::endl;

  	std::vector<int> V{10, 20, 30, 40, 50 , 60};

 	for (array<int, 4>::iterator first = std::begin(A), last = std::end(A); first != last; ++first)
    		std::cout << "[array]: " << *first << std::endl;

	return 0;
}
