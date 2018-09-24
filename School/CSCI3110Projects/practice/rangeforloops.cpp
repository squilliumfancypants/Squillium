#include <iostream>
using namespace std;

int main(int argc, char **argv){
	int arr[20] = {5};
	int sum = 0;
	for(int i : arr){
		sum += 1;
	}

	cout << sum << endl;

	return 0;	
}
