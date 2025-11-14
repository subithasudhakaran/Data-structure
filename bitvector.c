#include<stdio.h>
char uni_set[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","y","z"};
char	set1[26],set2[26];
int	bit_vec1[26],bit_vec2[26],result[26];
void	initializeSet()
{
		for(int	i=0;i<26;i++)
		{
			bit_vec1[i]=0;
			bit_vec2[i]=0;
			result[i=0];
		}
}
void	bitVector(char	ary[26],char	bit[26],int	num)
{
	for(int	i=0;i<num1;i++)
	{
		for(int	j=0;j<26;j++)
		{
				char	c=tolower(ary[i]);
				if(c==univ_set[j])
						bit[j]=1;
		}
	}
}	
int	main()
{
	int	num1,num2;
	printf("Enter	the	number	of	elements	in	set1:	");
	scanf("%d",&num1);
	printf("Enter	the	set1	elements:	");
	for(int	i=0;i<num1;i++)
	{
			scanf("%c",set1[i]);
	}
	printf("Enter	the	number	of	elements	in	set2:	");
	scanf("%d",&num2);
	printf("Enter	the	set2	elements:	");
	for(int	i=0;i<num2;i++)
	{
			scanf("%c",set2[i]);
	}
}

