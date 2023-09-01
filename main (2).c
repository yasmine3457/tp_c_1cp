  /***TP ALSDD ORGANISED BY YASMINE HAOUAS -BOUFELGHA ZINEB -G 09 ***/


  //------------------THE STRUCTRES USED-----------------------//
    /*  We have uses 2 stuctures , Both structures  provided have their own benefits and advantages,
     and the choice of which one to use depends on the specific requirements and constraints of your application.

The first structure, which is a node-based implementation of a skip list, provides the flexibility to store additional
 information in each node, such as pointers to adjacent nodes in all directions (up, down, left, right),
  and a level number to represent the node's height within the skip list. This level number allows for efficient
   searching and insertion of nodes in the skip list, as nodes at higher levels are skipped over during a search,
    resulting in a faster search time.

On the other hand, the second structure, which is an array-based implementation of a skip list,
 simplifies the node structure by only storing the value and level information for each node.
 This makes the structure more memory-efficient and easier to implement, especially when dealing with large numbers of elements.

Therefore, if your application requires the ability to store additional information in each node,
 such as pointers to adjacent nodes, or if you need to implement more advanced operations on the skip list,
  such as deletion or dynamic resizing, the first structure would be a better choice. However,
   if memory efficiency is a primary concern, or if you are dealing with a large number of elements,
        the second structure would be a more suitable choice.

Overall, it's important to choose the right data structure based on your specific needs and requirements,
 and both structures you provided have their own benefits that can be useful depending on the application. */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX_LEVEL 8
// Definire la structure de maillon utilisé
typedef struct SkipListNode {

    int value;  // le champ de la valeur
    struct SkipListNode *up;  // un pointeur por le haut
    struct SkipListNode *down;  //un pointeur pour le bas
    struct SkipListNode *left;   // un pointeur pour la gauche
    struct SkipListNode *right;   //un pointeur pour la droite
    int level; // stocker le numéro le niveau

} SkipListNode;
//// Definire la structure de skiplist

typedef struct SkipList {
    //au début ya que 2 element la téte et nil
    SkipListNode *head;
    SkipListNode *tail;
    int size;
} SkipList;
//structure de maillon  plus simplifie si l'utilisateur voulez  un essaye de plus de 45000 element
typedef struct Node {
    //2 champs essentielles le valeur d'élement et le niveau pour que on peut l'utiliser dans notre fonctions
    int value;
    int level;
    struct Node **forward;
} Node;
// la 2ème structure pour le 2ème node
typedef struct SkipList2 {
    int level;
    Node *header;
} SkipList2;

                      /*** les fonctions utiliseés  ***/
            //-----pour insérer vous méme sans utiliser randomly ---//
//---------1-----------//
// pour  la structure initiale de skiplist
SkipListNode *createSkipListNode(int value, int level);
// pour  la structure initiale de skiplist
//---------2-----------//
SkipList *createSkipList();
// la création de skiplist complète
//---------3-----------//
int randomLevel();
 //pour choisir un niveau aléatoirement
//---------4-----------//
SkipListNode *search(SkipList *skipList, int value);
// recherche d'un element dans la list par sa valeur
//---------5-----------//
SkipListNode *findPrevNode(SkipListNode *node);
 // recherche de le maillon précédent
//---------6-----------//
void insert(SkipList *skipList, int value);
//insérer une valeur dans skiplist
//---------7-----------//
void delete(SkipList *skipList, int value);
//suprimer une maillon par une valeur
//---------8-----------//
void printSkipList(SkipList *skipList);
 //l'affichage d'elements de skiplist( tous les niveaux)
//---------9-----------//
SkipListNode *searchByPosition(SkipList *skipList, int position);
//recherche un element pour une position donnée { l'elem existe ou non}


//-------pour manipuler plus que 45000 maillon -------//
//---------10-----------//
Node *createNode2(int value, int level );
//creation de maillon pour la 2ème structure {pour plus que 45000 maillon}
//---------11-----------//
SkipList2 *createSkipList2();
//creation de skiplist pour la 2ème structure {pour plus que 45000 maillon}
//---------12-----------//
int randomLevel2()  ;
// générer un niveau randmly pour la 2eme structure
//---------13-----------//
void insert2(SkipList2 *skiplist2, int value);
//insérer des valeures
//---------14-----------//
Node *search2(SkipList2 *skiplist2, int value);
//recherche par une valeur dans skiplist
//---------15-----------//
void insertAfter(SkipList2 *skiplist2, int value, Node *after);
//une fonction aide a insérer une valeur dans skiplist
//---------16-----------//
void delete2(SkipList2 *skiplist2, int value);
//supprimer un element par valeur
//---------17-----------//
void printSkipList2(SkipList2 *skiplist2);
//afficher les elements de skiplist (tous les niveaux)
//---------18-----------//
void welcome1();
//draw a box " welcome to our tp "
//---------19-----------//
void intro();
//introduction to the topic of the tp
//---------20----------// )
void Welcome();
//fonction d'affichage (de tp)
//---------21----------//
void welcome2();
//fonction d'affichage
//---------22----------//
void Menu_rep1();
//presentation pour la première partie
//---------23----------//
void Menu_rep2();
//presentation de la 2ème partie


//la fonction main
int main() { //1
    srand(time(NULL));
    SkipList *skipList = createSkipList(); // création d'une skiplist
    int num_elements = 0; // y a rien d'element dand skiplist en attendant l'user pour insérer les valeur
    int choice = 0; //il n a pas encore choisit
    int value = 0; //la valeur initiale de maillon est 0
    SkipListNode *node = NULL; //le moillon pointe sur "nile"
     Welcome();
     printf("   \n");// calling the alsdd_tp_1 function
     welcome2();
     printf("   \n");
     intro();
     printf("   \n");
     welcome1();
     printf("   \n");
     Menu_rep1();
     printf("   \n");
     Menu_rep2();
     printf("   \n");

       // afficher le menu

        printf("\n  -------Skip List Menu ---------\n");



        printf("------------1---------------\n");
        printf("here you have the choice if you want to insert or manipulate the values that you choose \n");
        printf("1. Insert  a Value\n");
        printf("2. Delete a Value\n");
        printf("3. Search  a Value\n");
        printf("4. Search By a Position\n"); // new option to search by position
        printf("5. Print  a Skip List\n");
        printf("-----------------------------\n");
        printf("-----------2------------------\n");
        printf("Here if you want to manipulate more than 45000 sliplist! \n");
        printf("6.manipulating a big number of skip lists \n");
        printf("-------------------------------\n");
        printf("you want to exit !\n");
        printf("7. Exit\n");

        printf("Enter your choice: "); // lire le choix de l'utilisateur

        scanf("%d", &choice);    //lire le choix de l'utilisateur
        // les cas possibles

        switch (choice) { //3
            case 1:
                //insérer un element par une valeur
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(skipList, value);
                printf("Value inserted.\n");
                num_elements++;
                break;
            case 2:
                //supprimer un elemet par valeur
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                delete(skipList, value);
                printf("Value deleted.\n");
                num_elements--;
                break;
            case 3:
                //recherche d'une valeur (un element)
                printf("Enter a value to search for: ");
                scanf("%d", &value);
                node = search(skipList, value);
                if (node != NULL) {
                printf("Value found in the skip list.\n");
                } else {
                printf("Value not found in the skip list.\n");
                }
                break;
                case 4:
                    //recherche un element par position
                printf("Enter a position to search for: ");
                scanf("%d", &value);
                node = searchByPosition(skipList, value);
                if (node != NULL) {
                printf("Value found at position %d in the skip list.\n", value);
                } else {
                printf("No value found at position %d in the skip list.\n", value);
                }
                break;
           case 5:
               //afficher notre skiplist
                printf("\nSkip List:\n");
                printSkipList(skipList);
                break;
           case 6:
               //le cas de plusieure maillons (plus que 45000
                srand((unsigned int) time(NULL));
                SkipList *skiplist = createSkipList2();
                int n;
                printf("Enter the number of nodes: "); //lire le nombre de maillons spécifies
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                int value = rand() % 1000000 + 1;
                insert2(skiplist, value);
                }
                printSkipList2(skiplist); //afficher skiplist
                int choice, element, after;
                printf("Enter 1 to insert, 2 to delete: ");
                scanf("%d", &choice);
                if (choice == 1) {
                printf("Enter an element to be inserted: ");
                scanf("%d", &element);
                printf("Enter the number to insert after: ");
                scanf("%d", &after);
                Node *afterNode = search2(skiplist, after);
                if (afterNode == NULL) {
                 printf("Number not found.\n");
               } else {
               insertAfter(skiplist, element, afterNode); //insertion d'un element
               printSkipList2(skiplist);
              }
              } else if (choice == 2) {
              printf("Enter an element to be deleted: ");
              scanf("%d", &element);
              delete2(skiplist, element);
               printSkipList2(skiplist);
              } else {
              printf("Invalid choice.\n");
             }
            break;
       case 7:
            printf("Exiting...\n"); //le temps pour l'arret de programme
            exit(0);
     default:
            printf("Invalid choice. Please try again.\n"); // when the user entre a number bigger than 7 or less than 1
                    } //3

return 0;
}//1
         //----------l'implementation --------------//
         /****pour la 1ère stucture****/

//---------1-----------//
//creation  de la structure principale de maillon utilisé dans skiplist
SkipListNode *createSkipListNode(int value, int level) {
    SkipListNode *newNode = (SkipListNode *)malloc(sizeof(SkipListNode));
    newNode->value = value;
    newNode->up = NULL;
    newNode->down = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->level = level;
    return newNode;
}

//---------2-----------//
//creation  de  skiplistinitialisé a "0"
SkipList *createSkipList() {
    SkipList *newSkipList = (SkipList *)malloc(sizeof(SkipList));
    SkipListNode *headNode = createSkipListNode(0, MAX_LEVEL);
    SkipListNode *tailNode = createSkipListNode(0, MAX_LEVEL);
    headNode->right = tailNode;
    tailNode->left = headNode;
    newSkipList->head = headNode;
    newSkipList->tail = tailNode;
    newSkipList->size = 0;
    return newSkipList;
}

//---------3-----------//
//génerer un nombre "randomly" de noveaux ( entre 1 et max_level)
int randomLevel() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

 //---------4-----------//
//recherche d'un element par valeur
SkipListNode *search(SkipList *skipList, int value) {
    SkipListNode *currentNode = skipList->head;
    while (currentNode != NULL) {
        if (currentNode->right == NULL || currentNode->right->value > value) {
            if (currentNode->down != NULL) {
                currentNode = currentNode->down;
            } else {
                break;
            }
        } else if (currentNode->right->value == value) {
            return currentNode->right;
        } else {
            currentNode = currentNode->right;
        }
    }
    return NULL;
}

//---------5-----------//
//recherche de l'element  juste  avant notre node recherché pour utiliser cette fonction dans la fonction search byposition
SkipListNode *findPrevNode(SkipListNode *node) {
    while (node->left == NULL) {
        node = node->up;
    }
    return node->left;
}
  //---------6-----------//
//insérer par valeur
void insert(SkipList *skipList, int value) {
    SkipListNode *currentNode = skipList->head;
    SkipListNode *insertNode = NULL;
    SkipListNode *prevNode = NULL;
    while (currentNode != NULL) {
        if (currentNode->right == NULL || currentNode->right->value > value) {
            if (currentNode->down != NULL) {
                prevNode = currentNode;
                currentNode = currentNode->down;
            } else {
                insertNode = createSkipListNode(value, randomLevel());
                insertNode->left = currentNode;
                insertNode->right = currentNode->right;
                if (currentNode->right != NULL) {
                    currentNode->right->left = insertNode;
                }
                currentNode->right = insertNode;
                insertNode->up = NULL;
                insertNode->down = NULL;
                skipList->size++;
                break;
            }
        } else if (currentNode->right->value == value) {
            break;
        } else {
            currentNode = currentNode->right;
        }
    }
    while (rand() < RAND_MAX / 2 && insertNode != NULL) {
        if (prevNode == NULL) {
            prevNode = createSkipListNode(0, MAX_LEVEL);
            prevNode->right = insertNode;
            insertNode->left = prevNode;
            skipList->head = prevNode;
            insertNode->up = NULL;
            insertNode->down = currentNode;
            currentNode->up = insertNode;
            currentNode = currentNode->up;
        } else {
            SkipListNode *newNode = createSkipListNode(value, insertNode->level + 1);
            newNode->left = prevNode;
            newNode->right = prevNode->right;
            if (prevNode->right != NULL) {
                prevNode->right->left = newNode;
            }
            prevNode->right = newNode;
            newNode->up = NULL;
            newNode->down = insertNode;
            insertNode->up = newNode;
            insertNode = newNode;
            prevNode = findPrevNode(prevNode);
        }
    }
}

//---------7-----------//
//supprimer par valeur
void delete(SkipList *skipList, int value) {
    SkipListNode *currentNode = search(skipList, value);
    if (currentNode == NULL) {
        return;
    }
    while (currentNode != NULL) {
        currentNode->left->right = currentNode->right;
        currentNode->right->left = currentNode->left;
        SkipListNode *tempNode = currentNode;
        currentNode = currentNode->up;
        free(tempNode);
    }
    skipList->size--;
}

//---------8-----------//
//afficher une skiplist
void printSkipList(SkipList *skipList) {
    // Iterate through all levels
    for (int level = MAX_LEVEL - 1; level >= 0; level--) {
        printf("Level %d: ", level);
        SkipListNode *currentNode = skipList->head;
        while (currentNode != NULL) {
            if (currentNode->level >= level) {
                printf("%d ", currentNode->value);
            }
            currentNode = currentNode->right;
        }
        printf("\n");
    }
}

//---------9-----------//
//recherche par position
SkipListNode *searchByPosition(SkipList *skipList, int position) {
    SkipListNode *currentNode = skipList->head;
    int currentPos = -1;
    while (currentNode != NULL) {
        if (currentNode->right == NULL || currentPos + currentNode->right->level > position) {
            if (currentNode->down != NULL) {
                currentNode = currentNode->down;
            } else {
                break;
            }
        } else {
            currentPos += currentNode->right->level;
            currentNode = currentNode->right;
            if (currentPos == position) {
                return currentNode;
            }
        }
    }
    return NULL;
}

/****pour la 2ème stucture****/

//---------10-----------//
//creer la structure de maillon
Node *createNode2(int value, int level) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->level = level;
    newNode->forward = (Node **) calloc(level, sizeof(Node *));
    return newNode;
}

//---------11-----------//
//creer skip list
SkipList2 *createSkipList2() {
    SkipList2 *skiplist2 = (SkipList2 *) malloc(sizeof(SkipList2));
    skiplist2->level = 0;
    skiplist2->header = createNode2(0, MAX_LEVEL);
    for (int i = 0; i < MAX_LEVEL; i++) {
        skiplist2->header->forward[i] = NULL;
    }
    return skiplist2;
}

//---------12-----------//
//génerer un " random level"
int randomLevel2() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

//---------13-----------//
//insérer par valeur
void insert2(SkipList2 *skiplist2, int value) {
    Node *update[MAX_LEVEL];
    Node *current = skiplist2->header;
    for (int i = skiplist2->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || current->value != value) {
        int level = randomLevel2();
        if (level > skiplist2->level) {
            for (int i = skiplist2->level + 1; i <= level; i++) {
                update[i] = skiplist2->header;
            }
            skiplist2->level = level;
        }
        Node *newNode = createNode2(value, level);
        for (int i = 0; i < level; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

//---------14-----------//
//recherche par valeur
Node *search2(SkipList2 *skiplist2, int value) {
    Node *current = skiplist2->header;
    for (int i = skiplist2->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current != NULL && current->value == value) {
        return current;
    } else {
        return NULL;
    }
}

//---------15-----------//
//insérer after element
void insertAfter(SkipList2 *skiplist2, int value, Node *after) {
    int level = randomLevel2();
    Node *newNode = createNode2(value, level);
    for (int i = 0; i < level; i++) {
        if (i <= after->level && after->forward[i] != NULL) {
            newNode->forward[i] = after->forward[i];
            after->forward[i] = newNode;
        } else {
            newNode->forward[i] = NULL;
        }
    }
}

//---------16-----------//
//supprimer par valeur
void delete2(SkipList2 *skiplist2, int value) {
    Node *update[MAX_LEVEL];
    Node *current = skiplist2->header;
    for (int i = skiplist2->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current != NULL && current->value == value) {
        for (int i = 0; i <= skiplist2->level; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        free(current->forward);
        free(current);
        while (skiplist2->level > 0 && skiplist2->header->forward[skiplist2->level] == NULL) {
            skiplist2->level--;
        }
        printf("%d deleted successfully.\n", value);
    } else {
        printf("%d not found in the Skip List.\n", value);
    }
}

//---------17-----------//
//afficher skiplist
void printSkipList2(SkipList2 *skiplist2) {
    printf("Skip List:\n");
    for (int i = 0; i <= skiplist2->level; i++) {
        printf("Level %d: ", i);
        Node *node = skiplist2->header->forward[i];
        while (node != NULL) {
            printf("%d ", node->value);
            node = node->forward[i];
        }
        printf("\n");
    }
}

/***les fonctions d'affichages ***/

//---------18-----------//

void welcome1(){
   int width, height, i, j;
   char text[] = "WELCOME  AGAIN TO OUR TP ALSDD organized by - yasmine haouas - and - boufelgha zineb - Group9";

   // Set box dimensions
   width = strlen(text) + 4;
   height = 5;

   // Draw the box
   for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
         if (i == 0 || i == height-1 || j == 0 || j == width-1) {
            // Draw a border character
            printf("*");
         } else if (i == 2 && j == 2) {
            // Draw the text in the center of the box
            printf("%s", text);
            j += strlen(text)-1;
         } else {
            // Draw a blank space
            printf(" ");
         }
      }
      printf("\n");
   }

   return 0;
}
//---------19-----------//

void intro(){
  printf("    o   {what they mean by skiplist! }                                  o    {Hmm that's a big question if         \n");  // head
    printf("   /|\\                                                                /|\\   you want to know see the next }          \n"); // arms
    printf("   / \\                                                                / \\                \n"); // legs
    printf("  /   \\                                                              /   \\                      \n"); // body
    printf(" /     \\                                                            /     \\                              \n");
    printf("/       \\                                                          /       \\                                          \n");
    return 0;
}








void Welcome()
//a function gives as an output presentation of our names , group and our university
{
    system("cls");
    printf("\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("        %c     Haouas Yasmine      %c\n",186,186,186);
    printf("           %c     Boufelgha Zineb      %c\n",186,186,186);
    printf("      %c     GROUPE  : 09      %c\n",186,186,186);
    printf("      %c     skiplist  %c\n",186,186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("     %c   ECOLE   NATIONALE   SUPERIEURE   D'INFORMATIQUE   %c\n",186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n");



}




void welcome2() {
    //it would be good if we use "grafique interface" but C doesn't stand for it like c++
    //but this show in a large size : ALSDD TP 1
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
   printf("\n");
   printf("     AAAAA     L       SSSS    DDDD        DDDD   -   TTTTTTTTTT   PPPPPP   -   11111\n");
   printf("    A     A    L      S    S   D   D       D   D  -       T       P     P  -     11\n");
   printf("   A       A   L      S        D    D      D    D -       T       P     P  -     11\n");
   printf("  A         A  L       SSSS    D     D     D     D-       T       PPPPPP   -     11\n");
   printf("  A         A  L            S  D    D      D    D -       T       P        -     11\n");
   printf("  A         A  L      S    S   D   D       D   D  -       T       P        -     11\n");
   printf("   A       A   L      S    S   DDDD        DDDD   -       T       P        -     11\n");
   printf("\n");

   printf("Welcome to ALSDD-TP-1!\n");


}

// implementation of our represation when we use two structures <3

/*********************************************Menu representation 1************************************************/
void Menu_rep1()
{
    printf("       ________________________________________________________________________________________\n");
    printf("      |    _______________________                                                             |\n");
    printf("      |   |                       |                                                            |\n");
    printf("      |   |   REPRESENTATION 01   |                                                            |\n");
    printf("      |   |_______________________|                                                            |\n");
    printf("      |   __________________________________________________________________________________   |\n");
    printf("      |  |   an empty skip list initialize with 0 for every level and you are               |  |\n");
    printf("      |  |   the responsible of inserting new nodes                                         |  |\n");
    printf("      |  |__________________________________________________________________________________|  |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                        MENU:                                           |\n");

    printf("      |  _________________    _________________    _________________    _________________      |\n");
    printf("      | | 1: insert a     |  | 3: search for   |  | 4:inser by      |  | 5: print the    |     |\n");
    printf("      | |    value        |  | a value in      |  |   an entered    |  | skiplist        |     |\n");
    printf("      | | 2: delete       |  |   the skiplist  |  | position        |  |                 |     |\n");
    printf("      | |_________________|  |_________________|  |_________________|  |_________________|     |\n");
    printf("      |                                                                                        |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                SHEMA ILLUSTRATIF:                                      |\n");
    printf("      |                                                                                        |\n");
    printf("      |                  Level 2           Level 1           Level 0                           |    \n");
    printf("      |           __________________ __________________ __________________                     |    \n");
    printf("      |          |        |         |        |         |        |         |                    |     \n");
    printf("      |        0 |--------|-------> |    0   |-------->|    0   |-------->| NULL               |      \n");
    printf("      |          |        |         |        |         |        |         |                    |     \n");
    printf("      |          |        |         |        |         |        |         |                    |      \n");
    printf("      |          |        |         |        |         |        |         |                    |      \n");
    printf("      |        0 |--------|-------> |    0   |-------->|    0   |-------->| NULL               |      \n");
    printf("      |          |        |         |        |         |        |         |                    |     \n");
    printf("      |          |        |         |        |         |        |         |                    |      \n");
    printf("      |          |        |         |        |         |        |         |                    |     \n");
    printf("      |        0 |--------|-------> |    0   |-------->|    0   |-------->| NULL               |     \n");
    printf("      |          |        |         |        |         |        |         |                    |      \n");
    printf("      |________________________________________________________________________________________|\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);


}


/*********************************************Menu representation 2************************************************/
void Menu_rep2()
{
     printf("       ________________________________________________________________________________________\n");
    printf("      |    _______________________                                                             |\n");
    printf("      |   |                       |                                                            |\n");
    printf("      |   |   REPRESENTATION 02   |                                                            |\n");
    printf("      |   |_______________________|                                                            |\n");
    printf("      |   __________________________________________________________________________________   |\n");
    printf("      |  |  this representation provide you a skiplist with random nodes that could         |  |\n");
    printf("      |  |   be more than 50000                                                                |\n");
    printf("      |  |__________________________________________________________________________________|  |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                        MENU:                                           |\n");
    printf("      |                         _________________    _________________                         |\n");
    printf("      |                        | 1:insert after  |  | 2:delete a      |                        |\n");
    printf("      |                        | a value entered |  | node entered    |                        |\n");
    printf("      |                        |    by the user  |  | by the user     |                        |\n");
    printf("      |                        |_________________|  |_________________|                        |\n");
    printf("      |                                                                                        |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                SHEMA ILLUSTRATIF:                                      |\n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | Node |------------>| Node |------------>| Node |------------>| Node |               |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | down |             | down |             | down |             | down |               |   \n");
    printf("      |  | right|------------>| right|------------>| right|------------>| right|----> NULL     |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |     |                     |                     |                     |                |   \n");
    printf("      |     v                     v                     v                     v                |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | Node |------------>| Node |------------>| Node |------------>| Node |               |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | down |             | down |             | down |             | down |               |   \n");
    printf("      |  | right|------------>| right|------------>| right|------------>| right|----> NULL     |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |     |                     |                     |                     |                |   \n");
    printf("      |     v                     v                     v                     v                |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | Node |------------>| Node |------------>| Node |------------>| Node |               |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | down |             | down |             | down |             | down |               |   \n");
    printf("      |  | right|------------>| right|------------>| right|------------>| right|----> NULL     |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |     |                     |                     |                     |                |   \n");
    printf("      |     v                     v                     v                     v                |   \n");
    printf("      |  | Node |------------>| Node |------------>| Node |------------>| Node |               |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | down |             | down |             | down |             | down |               |   \n");
    printf("      |  | right|------------>| right|------------>| right|------------>| right|----> NULL     |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |     |                     |                     |                     |                |   \n");
    printf("      |     v                     v                     v                     v                |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | Node |------------>| Node |------------>| Node |------------>| Node |               |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |  | down |             | down |             | down |             | down |               |   \n");
    printf("      |  | right|------------>| right|------------>| right|------------>| right|----> NULL     |   \n");
    printf("      |  +------+             +------+             +------+             +------+               |   \n");
    printf("      |     |                     |                     |                     |                |   \n");
    printf("      |     v                     v                     v                     v                |   \n");
    printf("      |    NULL                  NULL                  NULL                  NULL              |   \n");
    printf("      |________________________________________________________________________________________|\n");

printf("Let's get started our dear user \n");

}

