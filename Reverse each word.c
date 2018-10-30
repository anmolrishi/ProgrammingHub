#include <stdio.h>
#define swap(a, b) ((&(a) == &(b)) ? (a) : (a) ^= (b), (b) ^= (a), (a) ^= (b))

int main() {
	int l, r, i;
	char *str;
	while(~scanf("%m[^\n]", &str)) {
		for(l = r = i = 0; ; i++) {
			if(str[i] == '\0') {
				r = i - 1;
				while(l < r) {
					swap(str[l], str[r]);
					l++, r--;
				}
				return 0 * puts(str);
			} else if(str[i] == ' ') {
				r = i - 1;
				while(l < r) {
					swap(str[l], str[r]);
					l++, r--;
				}
				l = i + 1;
			}
		}
	}
}
