// node of singly linked list (used in libft)

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


// node of doubly linked list (for push_swap)

typedef struct	s_deque_node
{
	int					num;		// number to be sorted
	unsigned int		idx;		// input order of the number
	struct s_deque_node	*prev; 		// node previous to the current
	struct s_deque_node	*next;	 	// node next to the current
}	t_deque_node;

types of linear data structure
- stack : has one end, pop and push only at the top of stack possible (last in first out)
- queue : has two ends (front and rear), add at one end, remove at the other end (first in first out)
- deque : has two ends (front and rear), add/remove possible at both ends

for the project: each stack >> deque with doubly linked list << 
