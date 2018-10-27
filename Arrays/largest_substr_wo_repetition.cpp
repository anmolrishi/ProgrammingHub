#include <iostream>

int count [257];

std::string findLargestSubstr(const std::string &str){
	// start of current substr, and end of current substr
	int s = 0, e = 0;
	int maxs=0, maxe=0;

	while (s < str.size()){
		while (count[str[e]] == 0 && e < str.size()){
			count[str[e]] ++;
			e++;
		}
		if (e-s > maxe - maxs){
			maxs = s;
			maxe = e;
		}
		count[str[s]] --;
		s++;
	}

	return str.substr(maxs, maxe - maxs);
}

int main(){
	std::cout << "Input string: \n";
	std::string str;
	std::cin >> str;

	std::cout << findLargestSubstr(str) << "\n";

	return 0;
}
