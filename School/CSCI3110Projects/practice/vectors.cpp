#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char ** argv){
	vector<int> v1;
	int size = 50;

	for(int i =0; i < size; i++){
		v1.push_back(i);
	}

	for(auto i : v1){
		cout << v1[i] << " " ;
	}

	cout << endl;

	return 0;
}
