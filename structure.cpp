#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100//声明一个常量，表示顺序表的最大长度
typedef int Elem_type;//给数据类型起别名 增强可读性 方便后期修改数据类型

typedef struct {
	Elem_type* data;//顺序表的存储空间指针
	int length;
} SeqList;
//函数作用：定义顺序表结构体 typedef是给结构体起别名，方便后期使用SeqList代替struct SeqList

SeqList* initList() {
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));//在堆中开辟一个顺序表的空间
	L->data = (Elem_type*)malloc(MAXSIZE * sizeof(Elem_type));//在堆中开辟一个顺序表的存储空间
	L->length = 0;
	return L;
}//函数作用：动态分配内存地址初始化
//void initList(SeqList *L) {
//	L->length = 0;
//}//函数作用：初始化顺序表 赋值为0 传入参数为顺序表的地址（指针）

int appendElem(SeqList* L, Elem_type e) {
	if (L->length >= MAXSIZE) {
		cout << "顺序表已满，无法添加元素" << endl;
		return 0;
	}//if判断顺序表是否已满，若已满则输出提示信息并返回0
	L->data[L->length] = e;//将元素e添加到顺序表的末尾
	L->length++;//顺序表长度加1
	return 1;
}//函数作用：在顺序表末尾添加元素 传入参数为顺序表的地址（指针）和要添加的元素

void listElem(SeqList* L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << " ";
	}//遍历顺序表中的元素并输出
	cout << endl;
}//函数作用：遍历顺序表中的元素 传入参数为顺序表的地址（指针）

int insertElem(SeqList* L, int pos, Elem_type e) {
	if (L->length >= MAXSIZE) {
		cout << "顺序表已满，无法插入元素" << endl;
		return 0;
	}//if判断顺序表是否已满，若已满则输出提示信息并返回0
	if (pos<1 || pos>L->length+1) {
		cout << "插入位置错误" << endl;
		return 0;
	}
	if (pos <= L->length) {
		for (int i = L->length - 1; i >= pos-1; i--) {
			L->data[i + 1] = L->data[i];
		}//将插入位置之后的元素后移一位
		L->data[pos - 1] = e;//在指定位置插入元素
		L ->length++;//顺序表长度加1
	}
	return 1;
}//函数作用：在顺序表中指定位置插入元素 传入参数为顺序表的地址（指针）、插入位置和要插入的元素

int deleteElem(SeqList* L, int pos, Elem_type *e) {
	if (L->length == 0) {
		cout << "顺序表为空，无法删除元素" << endl;
		return 0;
	}//if判断顺序表是否为空，若为空则输出提示信息并返回0
	if (pos<1 || pos>L->length) {
		cout << "删除位置错误" << endl;
		return 0;
	}
	*e = L->data[pos - 1];//将删除位置的元素赋值给e 
	if (pos < L->length) {
	for (int i = pos; i < L->length; i++) {
		L->data[i-1] = L->data[i];
	}//将删除位置之后的元素前移一位
 }
	L->length--;//顺序表长度减1
	return 1; 
}//函数作用：在顺序表中指定位置删除元素 传入参数为顺序表的地址（指针）、删除位置和指向被删除元素的指针


int findElem(SeqList* L, Elem_type e) {
	for (int i = 0;i < L->length;i++){
		if (L->data[i] == e) {
			return i + 1;
	   }
	}//遍历顺序表中的元素，若找到指定元素则返回其位置（从1开始计数）
	return 0;//若未找到元素则返回0
}//函数作用：在顺序表中查找指定元素的位置 传入参数为顺序表的地址（指针）和要查找的元素



int main(int argc, char const *argv[]){
	SeqList* list = initList();//声明一个顺序表变量 在堆中开辟一个顺序表的空间 并将其地址赋值给list
	cout << "顺序表初始化完成，当前长度为：" << list->length << endl;
	cout << "目前占用的内存空间为" << sizeof(list->data) << "字节" << endl;
	//sizeof(list->data)计算顺序表的存储空间大小，单位为字节

	appendElem(list, 10);//在顺序表末尾添加元素10
	appendElem(list, 20);//在顺序表末尾添加元素20
	appendElem(list, 30);//在顺序表末尾添加元素30
	appendElem(list, 40);//在顺序表末尾添加元素40
	listElem(list);//遍历顺序表中的元素并输出
	insertElem(list, 3, 25);//在顺序表的第3个位置插入元素25
	listElem(list);//遍历顺序表中的元素并输出
	Elem_type delete_data;
	int locate;
	cout << "请输入要删除的元素位置：";
	cin >> locate;
	deleteElem(list, locate, &delete_data);//删除顺序表的第2个位置的元素
	cout << "被删除的元素为：" << delete_data << endl;
	listElem(list);//遍历顺序表中的元素并输出 
	Elem_type find_data;
	cout << "请输入要查找的元素：";
	cin >> find_data;
	cout << "查找的元素位置为第" << findElem(list, find_data) << "位" << endl;

	delete list;//释放顺序表的存储空间

	system("pause");
	return 0;


}//顺序表插入数据的最好时间复杂度是O(1)，插入最后一个元素时不需要移动其他元素
 //在最坏情况下，需要将顺序表中所有元素后移一位，时间复杂度为O(n)