#include<iostream>
#include<queue>
using namespace std;
struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode * left, * right;

    MinHeapNode(char data, unsigned freq){
        left=right=NULL;
        this->data=data;
        this->freq=freq;

    }
};
struct compare{
    bool operator()(MinHeapNode * l,MinHeapNode * r){
        return(l->freq>r->freq);
    }
};

void printCodes(struct MinHeapNode * root, string str){
    if(! root)
    return;
    if(root->data != '$')
    cout<<root->data<<";"<<str<<"\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void Huffmanncodes(char data[], int freq[],int size){
    struct MinHeapNode * left, * right, * top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare > minHeap;
    for(int i=0;i<size;i++){
        minHeap.push(new MinHeapNode(data[i], freq[i]));}
        while(minHeap.size()!=1){
            left=minHeap.top();
            minHeap.pop();
            right=minHeap.top();
            minHeap.pop();
            top=new MinHeapNode('$',left->freq+right->freq);
            top->left=left;
            top->right=right;
            minHeap.push(top);
        }
        printCodes(minHeap.top(),"");
    }
    int main(){
        char arr[]={'a','b','c','d','e','f','g'};
        int freq[]={12,15,10,19,23,20,16};
        int size=sizeof(arr)/sizeof(arr[0]);
        Huffmanncodes(arr,freq,size);
        return 0;
    }

