#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int c;
	int freq;
};
void swap(struct node nodes[],int i ,int j)
{
	struct node tmp = nodes[i];
	nodes[i] = nodes[j];
	nodes[j] = tmp;
}
void heap_modify(struct node nodes[],int i,int heapsize){
	if(i == heapsize) return;
	int min_indx = i;
	int r = 2*i+1;
	int l = 2*i;
	int min = nodes[i].freq;
	if(l <= heapsize)
	if(nodes[l].freq< min){
		min_indx = l;
		min = nodes[l].freq;
		swap(nodes,i,l);
	}
	if(r <= heapsize)
	if(nodes[r].freq < min){
		min_indx = r;
		min = nodes[r].freq;
		swap(nodes,i,r);
	}
	if(i != min_indx)
		heap_modify(nodes,min_indx,heapsize);
}
void build_min_heap(struct node nodes[],int len){
	int i ;
	for(i =(len+1)/2;i>=1;i--)
		heap_modify(nodes,i,len);
}
struct node exact_min(struct node nodes[],int size){
	//if(size <=0) return NULL;
	struct node rootnode = nodes[1];
	if(size == 1) rootnode;
	swap(nodes,1,size);
	heap_modify(nodes,1,size-1);
	return rootnode;
}
void insert_heap(struct node nodes[],struct node parent,int size){
	nodes[size+1] = parent;
	heap_modify(nodes,1,size+1);
}
int huf(char *s){
	int freq[30];
	int i ;
	struct node nodes[28];
	memset(freq,0,sizeof(freq));
	for(i= 0; i< strlen(s);i++){
		if(s[i] != '_' && (s[i] >='A' && s[i]<='Z'))
			freq[s[i]-'A'] ++;
		else if(s[i] == '_')
			freq[28]++;
		else
			return -1;
	}
	int k = 1 ;
	for(i = 0 ;i<30;i++)
		if(freq[i] > 0)
	{
		nodes[k].c = i;
		nodes[k].freq = freq[i];
		k++;
	}
    
	int heapsize = k-1;
	if(heapsize > 1)
		build_min_heap(nodes,heapsize);
	//for(i = 1 ;i<=k;i++) 
	//printf("(%c,%d)",nodes[i].c+'A',nodes[i].freq);
	int codelen = 0;
	if(heapsize == 1 ) codelen =nodes[1].freq;
	while(heapsize >1){
		struct node nodes1 = exact_min(nodes,heapsize--);
		struct node nodes2 = exact_min(nodes,heapsize--);
		struct node parent;
		parent.freq = nodes1.freq+nodes2.freq;
		codelen += parent.freq;
		insert_heap(nodes,parent,heapsize++);
	} 
	return codelen;
}

char s[100000];
int main()
{
	while(scanf("%s",s)){
		if(strcmp(s,"END") ==0 ){
			break;
		}
		int normal = strlen(s)*8;	
		int codelen = huf(s);
		if(codelen >= 0)
			printf("%d %d %.1lf\n",normal,codelen,(double)((double)normal/(double)codelen));
		else
			break;
	}
	return 0;
}
