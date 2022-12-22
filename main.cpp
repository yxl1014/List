#include <iostream>
#include "strings.h"

using namespace std;

typedef struct Node {
    char *username;
    char *tel;
    char *home;
    Node *next;
} Node;

int dohash(char *tel) {
    int i = 0;
    int sum = 0;
    while (tel[i] != '\0') {
        sum += tel[i];
        i++;
    }
    return sum % 100;
}

Node *add_Node(Node *head, char *username, char *tel, char *home) {
    Node *select = head;
    while (1) {
        if (select == NULL) {
            break;
        }
        if (strcmp(select->tel, tel) == 0) {
            return NULL;
        }
        select = select->next;
    }
    if (head == NULL) {
        Node *p = (Node *) malloc(sizeof(Node));
        p->username = (char *) malloc(strlen(username));
        strcpy(p->username, username);
        p->tel = (char *) malloc(strlen(tel));
        strcpy(p->tel, tel);
        p->home = (char *) malloc(strlen(home));
        strcpy(p->home, home);
        p->next = NULL;
        head = p;
        return head;
    } else {
        Node *p = (Node *) malloc(sizeof(Node));
        p->username = (char *) malloc(strlen(username));
        strcpy(p->username, username);
        p->tel = (char *) malloc(strlen(tel));
        strcpy(p->tel, tel);
        p->home = (char *) malloc(strlen(home));
        strcpy(p->home, home);
        p->next = head;
        head = p;
        return head;
    }
}

Node *delete_node(Node *head, char *tel) {
    Node *t = head;
    Node *tt;
    while (1) {
        if (t == NULL) {
            return NULL;
        }
        if (strcmp(t->tel, tel) == 0) {
            if (t == head) {
                head = t->next;
                free(t);
                return head;
            } else {
                tt->next = t->next;
                free(t);
                return head;
            }
        }
        tt = t;
        t = t->next;
    }
}

Node *select_tel(Node *head, char *tel) {
    Node *t = head;
    while (1) {
        if (t == NULL) {
            return NULL;
        }
        if (strcmp(t->tel, tel) == 0) {
            return t;
        }
        t = t->next;
    }
}


Node *update_tel(Node *head, char *tel, Node *update) {
    Node *t = head;
    while (1) {
        if (t == NULL) {
            return NULL;
        }
        if (strcmp(t->tel, tel) == 0) {
            if (update->username != NULL) {
                free(t->username);
                t->username = (char *) malloc(strlen(update->username));
                strcpy(t->username, update->username);
            }
            if (update->home != NULL) {
                free(t->home);
                t->home = (char *) malloc(strlen(update->home));
                strcpy(t->home, update->home);
            }
            return head;
        }
        t = t->next;
    }
}

void select_all(Node *head) {
    Node *p = head;
    while (p != 0) {
        cout << "tel:" << p->tel << "  " << "username:" << p->username << "  " << "home:" << p->home << endl;
        p = p->next;
    }
}


void display(Node *p) {
    cout << "name:" << p->username << "  " << "tel:" << p->tel << "  " << "home:" << p->home << endl;
}


Node **doAdd(Node *hashMap[100]) {
    printf("+------------��Ӳ���------------+\n");
    printf("+-----------1����������-----------+\n");
    char name[20] = {0};
    scanf("%s", name);
    printf("+-----------2������绰-----------+\n");
    char tel[20] = {0};
    scanf("%s", tel);
    printf("+-----------3�������ַ-----------+\n");
    char home[20] = {0};
    scanf("%s", home);
    Node *head = hashMap[dohash(tel)];
    Node *newNode = add_Node(head, name, tel, home);
    if (newNode != NULL) {
        printf("��ӳɹ�������\n\n");
        hashMap[dohash(tel)] = newNode;
        return hashMap;
    } else {
        printf("�õ绰�Ѵ��ڣ���������ӣ�����\n\n");
        return NULL;
    }
}

Node **doSearch(Node *hashMap[100]) {
    printf("+------------��ѯ����------------+\n");
    printf("������绰��");
    char *tel = (char *) malloc(20);
    memset(tel, 0, 20);
    scanf("%s", tel);
    Node *head = hashMap[dohash(tel)];
    Node *temp = select_tel(head, tel);
    if (temp != NULL) {
        printf("+-----------���û���Ϣ-----------+\n");
        display(temp);
        printf("\n");
    } else {
        printf("���û������ڣ�����\n\n");
    }
    return hashMap;
}

Node **doUpdate(Node *hashMap[100]) {
    printf("+------------�޸Ĳ���------------+\n");
    printf("������ɾ����Ϣ�ĵ绰��");
    char *tel = (char *) malloc(20);
    memset(tel, 0, 20);
    scanf("%s", tel);

    printf("+-----------1�������µ�����(�������޸�������null)-----------+\n");
    char newname[20] = {0};
    scanf("%s", newname);
    printf("+-----------2�������µĵ�ַ(�������޸�������null)-----------+\n");
    char newhome[20] = {0};
    scanf("%s", newhome);

    Node *newNode = (Node *) malloc(sizeof(Node));
    if (strcmp(newname, "null") != 0) {
        newNode->username = (char *) malloc(strlen(newname));
        strcpy(newNode->username, newname);
    } else {
        newNode->username = NULL;
    }
    newNode->tel = NULL;
    if (strcmp(newhome, "null") != 0) {
        newNode->home = (char *) malloc(strlen(newhome));
        strcpy(newNode->home, newhome);
    } else {
        newNode->home = NULL;
    }

    Node *head = hashMap[dohash(tel)];
    Node *temp = update_tel(head, tel, newNode);
    if (temp != NULL) {
        printf("�޸ĳɹ�������\n\n");
        hashMap[dohash(tel)] = temp;
    } else {
        printf("���û������ڣ�����\n\n");
    }
    return hashMap;
}

Node **doDelete(Node *hashMap[100]) {
    printf("+------------ɾ������------------+\n");
    printf("������ɾ����Ϣ�ĵ绰��");
    char *tel = (char *) malloc(20);
    memset(tel, 0, 20);
    scanf("%s", tel);
    Node *head = hashMap[dohash(tel)];
    Node *temp = delete_node(head, tel);
    if (temp != NULL || head != temp) {
        printf("ɾ���ɹ�������\n\n");
        hashMap[dohash(tel)] = temp;
    } else {
        printf("���û������ڣ�����\n\n");
    }
    return hashMap;
}

void menu() {
    Node **hashMap = (Node **) malloc(100 * sizeof(Node));
    memset(hashMap, 0, 100 * sizeof(Node));
    for (int i = 0; i < 100; ++i) {
        hashMap[i] = NULL;
    }
    while (1) {
        printf("+---------�绰�����ѯϵͳ---------+\n");
        printf("|                               |\n");
        printf("+-----------1�������Ϣ-----------+\n");
        printf("|                               |\n");
        printf("+-----------2��ɾ����Ϣ-----------+\n");
        printf("|                               |\n");
        printf("+-----------3���޸���Ϣ-----------+\n");
        printf("|                               |\n");
        printf("+-----------4����ѯ��Ϣ-----------+\n");
        printf("|                               |\n");
        printf("+-----------5���˳�--------------+\n");
        printf("|                               |\n");
        printf("+---------�绰�����ѯϵͳ---------+\n");
        printf("��������Ҫִ�еĲ�����");
        int i;
        //����Ҫִ�еĲ���
        scanf("%d", &i);
        switch (i) {
            case 1: {
                Node **t = doAdd(hashMap);
                if (t != NULL)
                    hashMap = t;
                break;
            }
            case 2: {
                Node **t = doDelete(hashMap);
                if (t != NULL)
                    hashMap = t;
                break;
            }
            case 3: {
                Node **t = doUpdate(hashMap);
                if (t != NULL)
                    hashMap = t;
                break;
            }
            case 4: {
                Node **t = doSearch(hashMap);
                if (t != NULL)
                    hashMap = t;
                break;
            }
            case 5:
                return;
            default:
                printf("������Ϣ���󣡣���\n\n");
        }
    }
}


void load()//װ�������ļ���Ϣ
{
    FILE *fp=NULL;
    unsigned int tmp = 0;

    fp = fopen("C:\\Users\\��\\Desktop\\config.txt", "r");
    while(!feof(fp))
    {
        fscanf(fp, "%x\r\n", &tmp);
        printf("tmp:%x\n",tmp);
    }
    fclose(fp);
}

void save() {
    FILE *p;
    FILE *p1;
    p=fopen("C:\\Users\\��\\Desktop\\config.txt","r+");
    p1=fopen("C:\\Users\\��\\Desktop\\config1.txt","w+");
    int i;
    int n=8;
    int a;
    while(!feof(p))
    {
        fscanf(p,"%x\r\n",&a);
        fprintf(p1,"%x\r\n",a);
    }
}

int main() {
    menu();
    //load();
    //save();
}
