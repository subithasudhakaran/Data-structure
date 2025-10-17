{
	do
	{
		int	item,choice;
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter	your	choice:	");
		scanf("%d",&choice);
		switch(choice)
		{
			case	1:printf("Enter	the	element:");
							scanf("%d",&item);
							push(item);
							break;
			case	2:pop();
							break;
			case	3:display();
							break;
			case	4:return(0);
			default:printf("Enter	the	correct	choice.");
							break;														
		}
	}while(1);
