#include<stdio.h>
#include<stdlib.h>
int coeff,power,i,max,choice;
struct poly{
	int coeff;
	int power;
	struct poly *next;
}*poly1,*poly2,*polyadd,*polymul,*tmpnode,*newnode;
void node(int coeff, int i){
	newnode=(struct poly*)malloc(sizeof(struct poly));
	newnode->coeff=coeff;
	newnode->power=i;
	newnode->next=NULL;
}
struct poly * getPolynomial(struct poly *p,int max){
	for(i=max;i>=0;i--){
	    printf("Enter the coefficient of X^%d:",i);
	    scanf("%d",&coeff);
		if(p==NULL){
			node(coeff,i);
			p=newnode;
		}
		else{
			node(coeff,i);
			tmpnode=p;
			while(tmpnode->next!=NULL){
				tmpnode=tmpnode->next;
			}
			tmpnode->next=newnode;
		}
	}
	return p;
}
void addNode(){
	if(poly1->power > poly2->power){
		node(poly1->coeff,poly1->power);
		poly1=poly1->next;
		
	}
	else if(poly1->power < poly2->power){
	    node(poly2->coeff,poly2->power);
		poly2=poly2->next;
	}
	else{
	    node(poly1->coeff+poly2->coeff,poly1->power);
		poly1=poly1->next;
		poly2=poly2->next;
	}
}
void polyAdd(){
    if(polyadd==NULL){
		addNode();
        polyadd=newnode;
	}
    for(i=0;i<polyadd->power;i++){
	    addNode();
	    tmpnode=polyadd;
		while(tmpnode->next!=NULL){
			tmpnode=tmpnode->next;
		}
		tmpnode->next=newnode;
	}
}
void multiplyNode(int coeff, int power)
{
    if(polymul==NULL){
        node(coeff,power);
        polymul=newnode;
    }
    else{
        node(coeff,power);
        tmpnode=polymul;
        while (tmpnode->next!=NULL){
            tmpnode=tmpnode->next;
        }
        tmpnode->next=newnode;
    }
}
void removeDuplicates(struct poly *ptr1, struct poly *ptr2)
{
    ptr1=polymul;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->power==ptr2->next->power){
                ptr1->coeff=ptr1->coeff+ptr2->next->coeff;
                ptr2->next=ptr2->next->next;
            }
            else{
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void polyMul(struct poly *ptr1, struct poly *ptr2){
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            coeff=ptr1->coeff*ptr2->coeff;
            power=ptr1->power+ptr2->power;
            multiplyNode(coeff,power);
            ptr2=ptr2->next;
        }
        ptr2=poly2;
        ptr1=ptr1->next;
    }
    removeDuplicates(ptr1,ptr2);
}
void print(){
    while(tmpnode->next!=NULL){
		printf("%dX^%d + ",tmpnode->coeff,tmpnode->power);
		tmpnode=tmpnode->next;
	}
	printf("%dX^%d",tmpnode->coeff,tmpnode->power);
}

void main(){
    printf("Polynomial ADT\nEnter the details for two polynomials:-\n");
    printf("Polynomial1\nEnter the max power:");
	scanf("%d",&max);
    poly1=getPolynomial(poly1,max);
    printf("Polynomial2\nEnter the max power:");
 	scanf("%d",&max);
    poly2=getPolynomial(poly2,max);
    printf("Operations\n1.Addition\n2.Multiplication\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            polyAdd();
            tmpnode=polyadd;
            print();
            break;
        case 2:
            polyMul(poly1,poly2);
            tmpnode=polymul;
            print();
            break;
        default:
            printf("Invalid Input...");
    }
}
