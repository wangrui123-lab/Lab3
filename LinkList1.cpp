#include <iostream>
using namespace std;// 定义链表节点结构体
typedef int DataType;
struct Node
{
	DataType data; //数据域 
	Node* next; //指针域 
};
/*函数功能:初始化一个带头结点的单链表
 *函数形参：无 *函数返回值: 返回单链表的头指针，Node*类型
 */
Node* InitLinkList() {
	Node* head = new Node;
	if (head) {
		head->next = NULL;
	}
	return head;
}
/*函数功能:采用头插法创建单链表
 *函数形参:一个单链表的头指针Node*head
 *函数返回值:插入成功返回true，否则返回false，bool类型
*/
bool CreateLinkList_head(Node* head)
{
	int data;
	cout << "请输入要插入的数据:";
	cin >> data;
	Node* p = new Node;//申请结点空间 
	if (p)//申请成功 
	{
		p->data = data;//数据域赋值 
		p->next = head->next;//指针域赋值
		head->next = p;
		return true;
	}
	return false;
}
/*函数功能:采用尾插法建立单链表
 *函数形参:一个单链表的头指针Node*head
 *函数返回值:插入成功返回true，否则返回false，bool类型
*/
bool CreateLinkList_tail(Node* head)
{
	int data;
	cout << "请输入要插入的数据";
	cin >> data;
	Node* p = new Node;//申请接点空间
	if (p)//申请成功 
	{
		p->data = data;
		p->next = NULL;
		//遍历找到链表的最后一个结点
		Node* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = p;
		return true;
	}
	return false;
}
/*函数功能:判断链表是否为空
 *函数形参:一个单链表的头指针Node*head
*函数返回值:为空返回 true，否则返回 false
 */
bool IsEmpty(Node* head)
{
	return(head->next == NULL);
}
/*函数功能:计算链表的长度
 *函数形参:一个单链表的头指针Node*head
*函数返回值:链表长度 (int 类型)
*/
int LengthLinkList(Node* head)
{
	int count = 0;
	Node* p = head->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
/*函数功能:输出链表的内容
 *函数形参:一个单链表的头指针Node*head
*函数返回值: 无 (void)
 */
void PrintLinkList(Node* head)
{
	Node* p = head->next;
	if (p == NULL) {
		cout << "链表为空，无数据输出！" << endl;
		return;
	}
	cout << "链表内容:";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	//1.初始化链表
	Node* head = InitLinkList();
	//2.测试头插法
	cout << "测试头插法" << endl;
	CreateLinkList_head(head);
	CreateLinkList_head(head);
	PrintLinkList(head);
	//3.测试尾插法
	cout << "测试尾插法" << endl;
	CreateLinkList_tail(head);
	CreateLinkList_tail(head);
	PrintLinkList(head);
	//4.测试判空
	cout << "链表是否为空:" << (IsEmpty(head) ? "是" : "否") << endl;
	//5.测试长度
	cout << "链表长度为:" << LengthLinkList(head) << endl;
	return 0;
}