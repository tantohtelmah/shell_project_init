#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *directory;
    struct node *next;
} node;

node *build_path_list() {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    node *head = NULL;
    node *current = NULL;

    while (token != NULL) {
        node *new_node = malloc(sizeof(node));
        new_node->directory = token;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }

        token = strtok(NULL, ":");
    }

    return head;
}

int main(void)
{
	node *head_;
	 head_ = build_path_list();
	printf("%s\n", head_->directory);
	return (0);
}
