Node* initialize();

void file_initialize(char file_account_holder_name[],int *file_branch_id,char file_address[],char file_PAN_number[],char file_account_number[],char file_deposited_money[],char file_phone_number[]);

Node* makenode(char account_holder_name[],int branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[]);

Node* insert(char filename[],Node* lptr,char account_holder_name[],int branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[]);

void getDetails(char account_holder_name[],int* branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[]);

void variable_initialize(char account_holder_name[],int* branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[]);

void print(Node* lptr);

Node* delete(char filename[],Node* lptr,char account_holder_name[],int branch_id);

void getNumRecords(Node* lptr);

void isEmpty(Node* lptr);

Node* list_unique(Node* lptr);

Node* list_union(Node* list1,Node* list2);

Node* intersect(Node* list1,Node* list2);

Node* skew_symmetric(Node* list1,Node* list2);

Node* deposit_money(Node* lptr);

Node* list_difference(Node* list1,Node* list2);

int next_iteration();

int print_file_names();

void figure(Node** head,Node** list1,Node** list2);
