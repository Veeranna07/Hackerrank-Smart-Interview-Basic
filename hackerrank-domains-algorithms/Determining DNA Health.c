#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

typedef struct TreeNode {
    char ch;
    int* ids;
    int idsLen;
    bool isBlue;
    struct TreeNode* child;
    struct TreeNode* next;
    struct TreeNode* suffix;
    struct TreeNode* blueSuffix;
} TreeNode;

TreeNode* initNode() {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->ch = 0;
    node->ids = NULL;
    node->idsLen = 0;
    node->isBlue = false;
    node->child = NULL;
    node->next = NULL;
    node->suffix = NULL;
    node->blueSuffix = NULL;
    return node;
}

void fillSuffix(TreeNode* root, int size) {
    TreeNode** queue = malloc(size*sizeof(TreeNode*));
    queue[0] = root;
    int head = 0;
    int tail = 1;
    while (head<tail) {
        TreeNode* node = queue[head++];
        TreeNode* child = node->child;
        while (child != NULL) {
            TreeNode* parent_suf = node->suffix;
            bool found_suf = false;
            while (!found_suf && parent_suf != NULL) {
                TreeNode* parent_suf_child = parent_suf->child;
                while (parent_suf_child != NULL && parent_suf_child->ch != child->ch) {
                    parent_suf_child = parent_suf_child->next;
                }
                if (parent_suf_child != NULL) {
                    child->suffix = parent_suf_child;
                    found_suf = true;
                } else {
                    parent_suf = parent_suf->suffix;
                }
            }
            if (!found_suf) child->suffix = root;
            
            queue[tail++] = child;
            child = child->next;
        }
    }
    free(queue);
}

void fillBlueSuffix(TreeNode* root, int size) {
    TreeNode** queue = malloc(size*sizeof(TreeNode*));
    queue[0] = root;
    int head = 0;
    int tail = 1;
    while (head<tail) {
        TreeNode* node = queue[head++];
        TreeNode* child = node->child;
        while (child != NULL) {
            TreeNode* parent_suf = node->suffix;
            bool found_suf = false;
            while (!found_suf && parent_suf != NULL) {
                TreeNode* parent_suf_child = parent_suf->child;
                while (parent_suf_child != NULL && parent_suf_child->ch != child->ch) {
                    parent_suf_child = parent_suf_child->next;
                }
                if (parent_suf_child != NULL && parent_suf_child->isBlue) {
                    child->blueSuffix = parent_suf_child;
                    found_suf = true;
                } else {
                    parent_suf = parent_suf->suffix;
                }
            }
            if (!found_suf) child->blueSuffix = root;
            
            queue[tail++] = child;
            child = child->next;
        }
    }
    free(queue);
}

TreeNode* contructTree(char** genes, int genes_count) {
    TreeNode* root = initNode();
    int size=1;
    for (int i=0; i<genes_count; i++) {
        TreeNode* node = root;
        char* gen = genes[i];
        int len = strlen(gen);
        for (int j=0; j<len; j++) {
            TreeNode* child;
            if (node->child == NULL) {
                child = initNode();
                node->child = child;
                size++;
            } else {
                child = node->child;
                while (child->ch != gen[j] && child->next != NULL) child = child->next;
                if (child->ch != gen[j]) {
                    child->next = initNode();
                    child = child->next;
                    size++;
                }
            }
            node = child;
            node->ch = gen[j];
            if (j==len-1) {
                node->isBlue = true;
                if (node->idsLen == 0) {
                    node->ids = malloc(sizeof(int));
                } else {
                    node->ids = realloc(node->ids, (node->idsLen+1)*sizeof(int));
                }
                node->ids[node->idsLen] = i;
                node->idsLen++;
            }
        }
    }
    fillSuffix(root, size);
    fillBlueSuffix(root, size);
    return root;
}

TreeNode* getChildNode(TreeNode* node, char ch) {
    TreeNode* child = node->child;
    while (child != NULL && child->ch != ch) child = child->next;
    return child;
}

long calHealth(TreeNode* tree, int* health, int first, int last, char* d) {
    long result = 0;
    TreeNode* cur = tree;
    for (int i=0; i<strlen(d); i++) {
        TreeNode* child = getChildNode(cur, d[i]);
        while (child == NULL && cur->suffix != NULL) {
            cur = cur->suffix;
            child = getChildNode(cur, d[i]);
        }
        if (child != NULL) cur = child;
        TreeNode* blue_suffix = cur;
        while (blue_suffix != NULL) {
            for (int i=0; i<blue_suffix->idsLen; i++) {
                if (blue_suffix->ids[i]>=first && blue_suffix->ids[i]<=last) {
                    result += health[blue_suffix->ids[i]];
                }
            }
            blue_suffix = blue_suffix->blueSuffix;
        }
    }
    return result;
}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);
    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** genes_temp = split_string(readline());
    char** genes = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        char* genes_item = *(genes_temp + i);
        *(genes + i) = genes_item;
    }
    
    TreeNode* tree = contructTree(genes, n);

    char** health_temp = split_string(readline());
    int* health = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        char* health_item_endptr;
        char* health_item_str = *(health_temp + i);
        int health_item = strtol(health_item_str, &health_item_endptr, 10);
        if (health_item_endptr == health_item_str || *health_item_endptr != '\0') { exit(EXIT_FAILURE); }
        *(health + i) = health_item;
    }

    char* s_endptr;
    char* s_str = readline();
    int s = strtol(s_str, &s_endptr, 10);
    if (s_endptr == s_str || *s_endptr != '\0') { exit(EXIT_FAILURE); }

    long* dna_healths = malloc(s*sizeof(long));

    for (int s_itr = 0; s_itr < s; s_itr++) {
        char** firstLastd = split_string(readline());

        char* first_endptr;
        char* first_str = firstLastd[0];
        int first = strtol(first_str, &first_endptr, 10);
        if (first_endptr == first_str || *first_endptr != '\0') { exit(EXIT_FAILURE); }

        char* last_endptr;
        char* last_str = firstLastd[1];
        int last = strtol(last_str, &last_endptr, 10);
        if (last_endptr == last_str || *last_endptr != '\0') { exit(EXIT_FAILURE); }

        char* d = firstLastd[2];
        dna_healths[s_itr] = calHealth(tree, health, first, last, d);
    }
    
    long minHealth = 1000000000000000000;
    long maxHealth = 0;
    for (int i=0; i<s; i++) {
        if (minHealth>dna_healths[i]) minHealth=dna_healths[i];
        if (maxHealth<dna_healths[i]) maxHealth=dna_healths[i];
    }
    printf("%ld %ld", minHealth, maxHealth);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
