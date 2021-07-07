
#include <bits/stdc++.h> 
#include <string>
#include <fstream>
#include <streambuf>


#define MAX_TREE_HT 256

using namespace std; 

// Shannon Fano
struct node { 
  
    // for storing symbol
    string sym;

    // for storing probability or frquency
    float pro;
    int arr[20];
    int top;
};

struct node *p;
typedef struct node node;

// function to find shannon code
void shannon(int l, int h, node p[]) 
{ 
    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
    int i, d, k, j; 
    if ((l + 1) == h || l == h || l > h) { 
        if (l == h || l > h)
            return; 
        p[h].arr[++(p[h].top)] = 0;
        p[l].arr[++(p[l].top)] = 1; 
        return; 
    } 
    else { 
        for (i = l; i <= h - 1; i++) 
            pack1 = pack1 + p[i].pro; 
        pack2 = pack2 + p[h].pro; 
        diff1 = pack1 - pack2; 
        if (diff1 < 0) 
            diff1 = diff1 * -1; 
        j = 2; 
        while (j != h - l + 1) {
            k = h - j; 
            pack1 = pack2 = 0; 
            for (i = l; i <= k; i++) 
                pack1 = pack1 + p[i].pro; 
            for (i = h; i > k; i--) 
                pack2 = pack2 + p[i].pro; 
            diff2 = pack1 - pack2; 
            if (diff2 < 0) 
                diff2 = diff2 * -1; 
            if (diff2 >= diff1) 
                break; 
            diff1 = diff2; 
            j++; 
        } 
        k++; 
        for (i = l; i <= k; i++) 
            p[i].arr[++(p[i].top)] = 1; 
        for (i = k + 1; i <= h; i++) 
            p[i].arr[++(p[i].top)] = 0; 
  
        // Invoke shannon function 
        shannon(l, k, p); 
        shannon(k + 1, h, p); 
    } 
} 
  
// Function to sort the symbols 
// based on their probability or frequency 
void sortByProbability(int n, node p[]) 
{ 
    int i, j; 
    node temp; 
    for (j = 1; j <= n - 1; j++) { 
        for (i = 0; i < n - 1; i++) { 
            if ((p[i].pro) > (p[i + 1].pro)) { 
                temp.pro = p[i].pro; 
                temp.sym = p[i].sym; 
  
                p[i].pro = p[i + 1].pro; 
                p[i].sym = p[i + 1].sym; 
  
                p[i + 1].pro = temp.pro; 
                p[i + 1].sym = temp.sym; 
            } 
        } 
    } 
} 
  
// function to display shannon codes 
void display(int n, node p[]) 
{ 
    int i, j; 
    cout << "\n\n\n\tSymbol\tProbability\tCode"; 
    for (i = n - 1; i >= 0; i--) { 
        cout << "\n\t" << p[i].sym << "\t\t" << p[i].pro << "\t"; 
        for (j = 0; j <= p[i].top; j++) 
            cout << p[i].arr[j]; 
    } 
    cout <<endl;

} 




// Huffman 
map<char, string> codes; 

// to store the frequency of character of the input data 
map<char, int> freq; 

// A Huffman tree node 
struct MinHeapNode 
{ 
    char data;           // One of the input characters 
    int freq;            // Frequency of the character 
    MinHeapNode *left, *right; // Left and right child 

    MinHeapNode(char data, int freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 

// utility function for the priority queue 
struct compare 
{ 
    bool operator()(MinHeapNode* l, MinHeapNode* r) 
    { 
        return (l->freq > r->freq); 
    } 
}; 

// utility function to print characters along with 
// there huffman value 
void printCodes(struct MinHeapNode* root, string str) 
{ 
    if (!root) 
        return; 
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 

// utility function to store characters along with 
// there huffman value in a hash table, here we 
// have C++ STL map 
void storeCodes(struct MinHeapNode* root, string str) 
{ 
    if (root==NULL) 
        return; 
    if (root->data != '$') 
        codes[root->data]=str; 
    storeCodes(root->left, str + "0"); 
    storeCodes(root->right, str + "1"); 
} 

// STL priority queue to store heap tree, with respect 
// to their heap root node value 
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 

// function to build the Huffman tree and store it 
// in minHeap 
void HuffmanCodes(int size) 
{ 
    struct MinHeapNode *left, *right, *top; 
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++) 
        minHeap.push(new MinHeapNode(v->first, v->second)); 
    while (minHeap.size() != 1) 
    { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        top = new MinHeapNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 
    storeCodes(minHeap.top(), ""); 
} 

// utility function to store map each character with its 
// frequency in input string 
void calcFreq(string str, int n) 
{ 
    for (int i=0; i<str.size(); i++) 
        freq[str[i]]++; 
} 

// function iterates through the encoded string s 
// if s[i]=='1' then move to node->right 
// if s[i]=='0' then move to node->left 
// if leaf node append the node->data to our output string 
string decode_file(struct MinHeapNode* root, string s) 
{ 
    string ans = ""; 
    struct MinHeapNode* curr = root; 
    for (int i=0;i<s.size();i++) 
    { 
        if (s[i] == '0') 
        curr = curr->left; 
        else
        curr = curr->right; 

        // reached leaf node 
        if (curr->left==NULL and curr->right==NULL) 
        { 
            ans += curr->data; 
            curr = root; 
        } 
    } 
    // cout<<ans<<endl; 
    return ans+'\0'; 
}
  
// Driver code 
int main() 
{   
    string file;
    cout<<"Enter file name :"<<endl;
    cin>>file;

    ifstream t(file);
    string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());

    cout<<str<<endl;
    cout<<"Choose the coding algorithm to use :\n1. Huffman Coding\n2. Shannon Fano Coding"<<endl;

    int choice;
    cin >> choice;

    if(choice==1){
        string encodedString, decodedString; 
        calcFreq(str, str.length()); 
        HuffmanCodes(str.length()); 
        cout << "Character With there Frequencies:\n"; 
        for (auto v=codes.begin(); v!=codes.end(); v++) 
            cout << v->first <<' ' << v->second << endl; 

        for (auto i: str) 
            encodedString+=codes[i]; 

        cout << "\nEncoded Huffman data:\n" << encodedString << endl; 

        decodedString = decode_file(minHeap.top(), encodedString); 
        cout << "\nDecoded Huffman Data:\n" << decodedString << endl; 
        
    }
    else if(choice==2){
        map<char, int> syms;
        int len = str.length();
        int i;
        char cur;

        for(i=0;i<len;i++){
            cur = str[i];
            if(syms.find(cur)!=syms.end()){
                syms[cur] = syms[cur]+1;
            }
            else{
                syms[cur]=1;
            }
        }

        p = new node[syms.size()];

        int n, j;
        float total = 0;
        string ch;
        node temp;
        
        n = syms.size();
        // Input number of symbols
        cout << "Total number of symbols\t: ";
        cout << n << endl;
        
        float *x  = new float[n];
        i=0;

        map <char, int> symIndex;

        cout<<"Occurences of vaious symbols : "<<endl;
        for (map<char,int>::iterator it = syms.begin(); it != syms.end(); ++it) {
            p[i].sym += it->first;
            p[i].pro = it->second/(float)len;
            cout<<p[i].sym<<" "<<it->second<<endl;

            symIndex[it->first] = i;
            i++;
        }
        // Input symbols  
      
        // Sorting the symbols based on 
        // their probability or frequency 
        sortByProbability(n, p);
      
        for (i = 0; i < n; i++)
            p[i].top = -1;
      
        // Find the shannon code
        shannon(0,n-1,p);
      
        // Display the codes
        display(n,p);

        cout<<"Encoded file : "<<endl;
        int index;
        string encoding;
        for(i=0;i<len;i++){
            char c = str[i];
            index = symIndex[c];
            for (j = 0; j <= p[index].top; j++){
                cout << p[index].arr[j];
                // encoding = encoding+p[index].arr[j];
            }
        }
        cout<<endl;

    }
    else{
        cout<<"Invalid choice"<<endl;
    }
     
    return 0; 
}
