#include<iostream>
using namespace std;
struct Node{
	int ID;
	string name;
	Node*next;
};
Node*head=NULL;
void insertAtEnd(int ID,string name){
	Node*newNode=new Node();
	newNode->ID=ID;
	newNode->name=name;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		cout<<"Patient added at end"<<endl;
		return ;
	}
	Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	cout<<"Patient added at end"<<endl;
}
void insertAtBeginning(int ID,string name){
	Node*newNode=new Node();
	newNode->ID=ID;
	newNode->name=name;
	newNode->next=head;
	head=newNode;
	cout<<"Emergency patient added at Beginning"<<endl;
}
void searchpatient(int ID){
	Node*temp=head;
	while(temp!=NULL){
		if(temp->ID==ID){
			cout<<"Patient Found"<<temp->name<<"(ID:"<<temp->ID<<")"<<endl;
			return;
		}
		temp=temp->next;
	}
	cout<<"Patient not Found"<<endl;
	}
	void Removepatient(){
		if(head==NULL){
			cout<<"No Patients to Remove:"<<endl;
			return;
		}
		Node*temp=head;
		head=head->next;
		cout<<"Removed Patient:"<<temp->name<<"(ID:"<<temp->ID<<")"<<endl;
		delete temp;
	}
	void Displaypatients(){
		if (head==NULL){
			cout<<"No patients in the list:"<<endl;
			return;
		}
		 
		cout<<"....Current Patients...."<<endl;
		Node*temp=head;
		while(temp!=NULL){
			cout<<"ID"<<temp->name<<endl;
			temp=temp->next;
		}
	}
	int main(){
		int choice,ID;
		string name;
		do{
			cout<<".......Hospital patient Management system......."<<endl;
			cout<<"1.Add New patient"<<endl;
			 cout<<"2.Add Emergency patient"<<endl;
			 cout<<"3.Search patient by ID"<<endl;
			 cout<<"4.Remove Treated patient"<<endl;
			 cout<<"5.Display All patints"<<endl;
			 cout<<"6.Exit"<<endl;
			 cout<<"Enter choice"<<endl;
			 cin>>choice;
			 switch(choice){
			 	case 1:
			 		cout<<"Enter patient ID"<<endl;
			 		cin>>ID;
			 		cout<<"Enter patient name"<<endl;
			 		cin>>name;
			 		insertAtEnd(ID,name);
			 		break;
			 		case 2:
			 			cout<<"Enter patient ID"<<endl;
			 			cin>>ID;
			 			cout<<"Enter patient name"<<endl;
			 			cin>>name;
			 			insertAtBeginning(ID,name);
			 			break;
			 			case 3:
			 				cout<<"Enter patient ID to search"<<endl;
			 				cin>>ID;
			 				searchpatient(ID);
			 				break;
			 				case 4:
			 					Removepatient();
			 					break;
			 					case 5:
			 						Displaypatients();
			 						break;
			 						case 6:
			 							cout<<"Existing system..."<<endl;
			 							break;
			 						default:
			 							cout<<"Invalid Option! Try Again"<<endl;
			 }
		}
			 while(choice!=6);
			 return 0;
		}
