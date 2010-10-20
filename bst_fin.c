#include <stdio.h>
#include <stdlib.h>
struct node {
	int dat;
	struct node *left;
	struct node *right;
};

struct node *delete(struct node *, int);

struct node *new(int dat)
{
	struct node *t;

	t = malloc(sizeof(struct node));
	t->dat = dat;
	t->left = 0;
	t->right = 0;
	return t;
}

struct node *insert(struct node *h, struct node *n)
{
	if(h == 0) return n;
	
	if(n->dat < h->dat)
		h->left = insert(h->left, n);
	else
		h->right = insert(h->right, n);

	return h;

}

void inorder(struct node *l)
{
	if(l == 0) return;

        inorder(l->left);
        printf("%d\t",l->dat);
        inorder(l->right);
}

struct node *one_child(struct node *h)
{
        if(h->left != 0)
                return h->left;
        else
                return h->right;
}

int twochild(struct node *h)
{
        int d;
        struct node *p;

        p = h;
        h = h->left;
        while(h->right != 0){
                        p = h;
                        h = h->right;
        }
        d = h->dat;
        p = delete(p, h->dat);
        return d;
}

struct node *delete(struct node *h, int data)
{
	int d;

	if(h == 0){
		printf("no such an element\n");
		return h;
		}
		if(data == h->dat){
			if(h->left == 0 && h->right == 0)
				return NULL;
			else{
				if(h->left != 0 && h->right != 0){
					h->dat = twochild(h);
					return h;
			}else{
				return one_child(h);
			}
			}
		}
		else{
			if(data < h->dat)
				h->left = delete(h->left, data);
			else
				h->right = delete(h->right, data);
		}
	return h;
}
main()
{
	struct node *h = 0;
	int choice,y,data;

        do{
        printf("1.insert\n2.inorder\n3.delete\n");
        scanf("%d",&choice);

        switch(choice){
                case 1:scanf("%d",&data);
                       h=insert(h ,new(data));
                       break;
                case 2:inorder(h);
		       printf("\n");
                       break;
		case 3:scanf("%d",&data);
		       h=delete(h ,data);
		       break;
        }
	scanf("%d",&y);
        }while(y==1);

}
