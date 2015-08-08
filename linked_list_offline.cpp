#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int count=0;

typedef struct node
{
    int info;
    node *next;
};

node *insert_data(node *head,int data)
{
    node *temp;
    node *old_temp;
    node *new_temp;

    if(head==NULL)
    {
        temp = new node;
        temp->info = data;
        temp->next = NULL;
        head = temp;
    }

    else
    {
        new_temp=head;
        old_temp = new_temp;
        while(new_temp!=NULL)
        {
            if(new_temp->info<=data)
            {
                old_temp = new_temp;

            }
            new_temp = new_temp->next;

        }
        if(head->info > data)
        {
             temp = new node;
             temp->info = data;
             temp->next = head;
             head = temp;

        }


        else if(old_temp->next == NULL)
        {
             temp = new node;
            temp->info = data;
            temp->next = NULL;
            old_temp->next = temp;
        }

        else
        {

            temp = new node;
            temp->info = data;
            temp->next = old_temp->next;
            old_temp->next = temp;
        }

    }
    count++;

    node *p;
    p=head;
    cout<<"Info total <"<<count<<"> : ";
    while(p!=NULL)
    {
        cout<<p->info<<" -> ";
        p=p->next;
    }
    return head;
}

node *delete_data(node *head,int data)
{
    node *temp;
    node *old_temp;
    node *new_temp;



    if(head!=NULL)
    {
        new_temp=head;
        old_temp = new_temp;

        if(head->info == data)
        {
             count--;
             temp=head->next;
             head = temp;


        }
        else
        {
            int chk=0;//count check
            while(new_temp->next!=NULL)
            {
                 if(new_temp->info==data&&chk==0)
                 {
                     count--;
                     chk=1;
                    old_temp->next = new_temp->next;


                 }


                old_temp = new_temp;
                new_temp = new_temp->next;


            }

            if(new_temp->info==data&&chk==0)
            {
                count--;
                old_temp->next = NULL;

            }

        }



    }

    node *p;
    p=head;
    cout<<"Info : ";
    if(p==NULL) cout<<"No Info.";
    else cout<<"Info total <"<<count<<"> : ";
    while(p!=NULL)
    {
        cout<<p->info<<" -> ";
        p=p->next;
    }
    return head;
}

node *reverse_data(node *head)
{
    node *prev = NULL;
    while(head)
    {
        node *temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }
    head = prev;
    node *p;
    p=head;
    cout<<"Info : ";
    if(p==NULL) cout<<"No Info.";
    else cout<<"Info total <"<<count<<"> : ";
    while(p!=NULL)
    {
        cout<<p->info<<" -> ";
        p=p->next;
    }
    return head;
}

int main()
{
    node *head = NULL;
    int n,data;

    do
    {
        cout<<"\nChoose : ";
        cin>>n;
        if(n==1)
        {
            cin>>data;
            head = insert_data(head,data);
        }
        if(n==2)
        {
            cin>>data;
            head = delete_data(head,data);
        }
        if(n==3)
        {

            head = reverse_data(head);
        }


    }while(n!=4);

    return 0;
}
