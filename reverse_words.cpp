#include <iostream>

std::string reverse(std::string str){
	std::string word;
	std::string res;
	for (const auto &c : str){
		if (c == ' ' || c == '\n'){
			for (int i=word.size()-1 ; i >= 0; i--){
				res += word[i];
			}
			word = "";
			res += c;
		} else
			word += c;
	}
	return res;
}

int main(){
	std::string str;
	std::cin >> str;
	
	std::cout << reverse(str) << "\n";

	return 0;
}
