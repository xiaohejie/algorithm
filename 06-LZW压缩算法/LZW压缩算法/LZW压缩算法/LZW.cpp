#include<iostream>
using namespace std;
#define NOT_EXIST -1
typedef struct {
	char** seq;
	int* code;
	int size;
	int maxSize;
} Dictionary;
//将一段字符串添加到字典中
void insertDict(Dictionary* dict, const char* seq) {
	int i = dict->size;
	dict->seq[i] = (char*)malloc(sizeof(char) * strlen(seq) + 1);
	dict->code[i] = i;
	dict->size++;
	strcpy(dict->seq[i], seq);
}
//初始化字典
void initDictionary(Dictionary* dict, int maxSize) {
	dict->maxSize = maxSize;
	dict->size = 0;
	dict->seq = (char**)malloc(sizeof(char*) * maxSize);
	dict->code = (int*)malloc(sizeof(int) * maxSize);

	//过滤掉第0个位置
	insertDict(dict, "#");
	char seq[2] = "A";
	for (int i = 0; i < 26; i++) {
		insertDict(dict, seq);
		seq[0]++;
	}
}

int get_seq_code(Dictionary* dict, const char* seq) {
	for (int i = 0; i < dict->size; i++) {
		if(strcmp(dict->seq[i], seq) == 0){
			return dict->code[i];
		}
	}
	return NOT_EXIST;
}
char* get_code_seq(Dictionary* dict, int code) {
	if (code < 0 || code >= dict->size) {
		return NULL;
	}
	else {
		int i = code;
		return dict->seq[i];
	}
}
//打印整个字典
void printDict(Dictionary* dict) {
	cout << "==================" << endl;
	cout << "Code" << "        " << "Seuence" << endl;
	for (int i = 0; i < dict->size; i++) {
		cout << dict->code[i] << "          " << dict->seq[i] << endl;
	}
	cout << "==================" << endl;
}
//LZW算法
void lzwEncode(const char* text, Dictionary* dict) {
	char current[1000];
	char next;
	int code;
	int i = 0;
	while (i < strlen(text)) {
		sprintf(current, "%c", text[i]);
		next = text[i + 1];
		while (get_seq_code(dict, current) != NOT_EXIST) {
			//如果字典中有current
			sprintf(current, "%s%c", current, next);
			i++;
			next = text[i + 1];
		}
		current[strlen(current) - 1] = '\0';
		next = text[i];
		code = get_seq_code(dict, current);
		sprintf(current, "%s%c", current, next);
		insertDict(dict, current);
		cout << code << "     " <<  current << endl;
	}
}
void lzwDecode(int codes[], int n, Dictionary* dict) {
	int code;
	char prev[1000];
	char* output;
	
	code = codes[0];
	output = get_code_seq(dict, code);
	cout << output;

	int i = 0;
	for (i = 1; i < n; i++) {
		code = codes[i];
		strcpy(prev, output);
		output = get_code_seq(dict, code);
		sprintf(prev, "%s%c", prev, output[0]);
		insertDict(dict, prev);
		cout << output;
	}
	cout << endl;
}
int main() {
	Dictionary dict;
	initDictionary(&dict, 1000);
	printDict(&dict);

	//lzwEncode("TOBEORNOTTOBEORTOBEORNOT", &dict);
	//printDict(&dict);
	/*cout << get_seq_code(&dict, "B") << endl;*/

	int arr[16] = { 20, 15,2,5,15,18,14,15,20,27,29,31,36,30,32,34 };
	lzwDecode(arr, 16, &dict);
	return 0;
}