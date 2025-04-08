// typedef struct	s_stack
// {
// 	struct s_stack	*prev;
// 	int				nbr;
// 	struct s_stack	*next;
// 	int				local_index;
// 	int				*index_offset;
// }				t_stack;

// int get_index(struct s_stack *node)
// {
// 	return(node->local_index + *(node->index_offset));
// }

// struct s_stack *add_to_empty(int data)
// {
// 	// int	*offset = malloc(sizeof(int));
// 	struct s_stack	*new = malloc(sizeof(struct s_stack));

// 	if (!new)
// 		return (NULL);
// 	// *offset = 1;
// 	new -> prev = new;
// 	new -> nbr = data;
// 	new -> next = new;
// 	// new -> local_index = 0;
// 	// new -> index_offset = offset;
// 	return (new);
// }

// struct s_stack *add_at_beg(struct s_stack *tail, int data)
// {
// 	struct s_stack *new = malloc(sizeof(struct s_stack));
// 	if (!new)
// 		return (NULL);

// 	new->nbr = data;
// 	new->prev = tail;
// 	new->next = tail->next;
// 	// new->index_offset = tail->index_offset;
// 	// new->local_index = 0;  // First node has local_index 0
// 	// // Adjust the shared index_offset to simulate "pushing" everyone else forward
// 	// struct s_stack *temp = tail->next;
// 	// do {
// 	// 	temp->local_index += 1;
// 	// 	temp = temp->next;
// 	// } while (temp != tail->next);
// 	tail->next->prev = new;
// 	tail->next = new;
// 	return (tail);
// }

// struct s_stack *add_at_end(struct s_stack *tail, int data)
// {
// 	struct s_stack *new = malloc(sizeof(struct s_stack));
// 	if (!new)
// 		return (NULL);

// 	new->nbr = data;
// 	new->prev = tail;
// 	new->next = tail->next;
// 	// new->index_offset = tail->index_offset;
// 	// new->local_index = tail->local_index + 1;
// 	tail->next->prev = new;
// 	tail->next = new;

// 	return (new); // New tail
// }

// struct s_stack	*del_first(struct s_stack *tail)
// {
// 	struct s_stack *temp;

// 	if (tail == NULL)
// 		return(tail);
// 	temp = tail -> next;
// 	if (temp == tail)
// 	{
// 		// free(temp->index_offset);
// 		free(temp);
// 		free(tail);
// 		return (NULL);
// 	}
// 	// *(temp->index_offset) -= 1;
// 	tail->next = temp->next;
// 	temp->next->prev = tail;
// 	free(temp);
// 	return (tail);
// }
