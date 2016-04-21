
/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class ListNode
{
public:
	ListNode(); 
	int &data(); 
	const int data() const; 

private:
	int data_;
	ListNode *next;
	friend class CPPList; 

}; // class ListNode类定义结束.


/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class CPPList
{
public:
	// CPPList类构造函数.
	CPPList(); 

	// CPPList类析构函数
	~CPPList(); 

	// CPPList类接口.
public:
	// 列表是否为空
	bool is_empty(); 

	// 列表元素个数
	int size() ; 

	// 返回list有效节点的起始位置begin及终止位置end
	// 这些节点应从begin开始，到end结束，但【不包括】end本身
	// 因此当list为空时，返回值应满足begin==end
	ListNode *begin(); 
	ListNode *end(); 
	const ListNode *begin() const; 
	const ListNode *end() const; 

	// 根据current获取下一跳节点，应判断current有效性
	// 无效则直接返回NULL
	ListNode *next(const ListNode *current); 
	const ListNode *next(const ListNode *current) const; 
	
	// 尾部追加数据
	void append(int); 

	// 在current之前差远数据，应判断current有效性
	// 无效则无需动作
	void insert(ListNode *current, int); 

	// 删除current当前节点，应判断current有效性
	// 无效则无需动作
	void remove(ListNode *current); 

	// 清空数据
	void clear(); 

	// CPPList类私有型成员变量.
private:
	int size_;
	ListNode *first;
	ListNode *last;
}; // class CPPList类定义结束.

