#include<iostream>
#include<fstream>
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;

// Task 1
void read_cstring(char* str, ifstream& in) {
	char* ptr = str;
	while (!in.eof() && in.peek() >= 33 && in.peek() <= 127) {
		in.read(ptr, 1);
		ptr++;
	}
}

// Task 2
int main() {

	// 20 symbols - let's keep things simple
	char text_file_name[20], binary_file_name[20];
	cin >> text_file_name >> binary_file_name;

	// Reading from text file is normal - with >>
	ifstream txt_in(text_file_name);
	int n;
	txt_in >> n;
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++) {
		txt_in >> arr[i];
	}

	// Writing in binary is with "write"
	ofstream bin_out(binary_file_name, ios::binary);
	for (unsigned i = 0; i < n; i++) {
		bin_out.write((char*)(arr + i), sizeof(int));		// (arr + i) is pointer, so no & before it!
	}

	// As array elements are "neighbours" in memory, there is another nice way to write the array in binary:
    // bin_out.write((char*)arr, n * sizeof(int));

	// It's a good practice to close the streams
	txt_in.close();
	bin_out.close();

	return 0;
}