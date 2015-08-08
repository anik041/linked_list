#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

typedef struct node
{
    int num;
    node *next;
};


node *insert_front_data(node *head)
{
    int info;
    cout<<"Insert:";
    cin>>info;
    node *temp = new node;
    temp->num = info;
    temp->next=head;
    head=temp;
  //  cout<<"inserted"<<head<<endl;
    return head;

}
node *delete_front_data(node *head)
{
    int n = head->num;
    node *temp;
    temp=head->next;
    head=temp;
    cout<<"\n"<<n<<" is deleted"<<endl;
    return head;
}
node *print_data(node *head)
{

    node *temp ;
    temp=head;
    cout<<"numbers : ";
    while(temp!=NULL)
    {
        cout<<temp->num<<" -> ";
        temp = temp->next;
    }

    return head;
}
node *insert_back_data(node *head)
{
    node *temp = new node;
    int info;
    cout<<"Insert:";

    cin>>info;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *temp1 = new node;

    temp1->num = info;
    temp1->next = NULL;

    temp->next = temp1;


    return head;
}
node *delete_back_data(node *head)
{

    node *temp,*old_temp;
    temp=head;
    while(temp->next!=NULL)
    {
        old_temp = temp;
        temp = temp->next;

    }
    old_temp->next = NULL;

    cout<<"\n"<<temp->num<<" is deleted"<<endl;
    return head;
}
node *delete_any_data(node *head)
{
    int info;
    node *temp,*old_temp;
    temp=head;
    cout<<"number to delete : ";
    cin>>info;
    while(temp->next!=NULL)
    {
        if(temp->num==info)
        {
            old_temp->next = temp->next;
            cout<<"\n"<<temp->num<<" is deleted"<<endl;
            return head;
        }
        old_temp=temp;

        temp=temp->next;
    }
    cout<<"\nnothing is deleted"<<endl;
    return head;
}
int main()
{

    node *head=NULL;
    int n;
    do
    {
        cout<<"\nPress 1 to Insert \nPress 2 to delete\nPress 3 to show\nPress 4 to Insert Back\nPress 5 to Delete Back\nPress 6 to Delete any number\nChoose : ";
        cin>>n;
        if(n==1)
        {
            head = insert_front_data(head);
        }
        if(n==2)
        {
            head = delete_front_data(head);
        }
        if(n==3)
        {
            head = print_data(head);
        }
        if(n==4)
        {
            head = insert_back_data(head);
        }
        if(n==5)
        {
            head = delete_back_data(head);
        }
        if(n==6)
        {
            head = delete_any_data(head);
        }

    }while(n>0&&n<10);


    return 0;
}
