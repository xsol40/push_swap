int main()
{
	t_stack *node1 = malloc(sizeof(t_stack));
	t_stack *node2 = malloc(sizeof(t_stack));
	t_stack *node3 = malloc(sizeof(t_stack));
	t_stack *node4 = malloc(sizeof(t_stack));
	t_stack *node5 = malloc(sizeof(t_stack));
	t_stack *node6 = malloc(sizeof(t_stack));
	node1->nb = 30;
	node2->nb = 90;
	node3->nb = 50;
	node4->nb = 70;
	node5->nb = 90;
	node6->nb = 5;
	node1->next = node2;
	node2->next= node3;
	node3->next = node4;
	node4->next = NULL;
	node5->next = node6;
	node6->next = NULL;
	t_stack	*current = node1;
	while (current)
	{
		printf("%d\n", current->nb);
		current = current->next;
	}
	printf("***********************************\n");
	ft_ss(&node1, &node5);
	current = node1;
	while (current)
	{
		printf("stack a :%d\n", current->nb);
		current = current->next;
	}
	current = node5;
	while (current)
	{
		printf("stack b ;%d\n", current->nb);
		current = current->next;
	}
}