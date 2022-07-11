#include<iostream>

class String {
	public:
		int len;
		char *str;


		String(char *s) {
			this.str = s;
			this.len = strlen(str);
		};
};


int main() {
	String* s = new String("hello world\n");
	std::cout << s.str << " : " << s.len << std::endl;
	return 0;
}
