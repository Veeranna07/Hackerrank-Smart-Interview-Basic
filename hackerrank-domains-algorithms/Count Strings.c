#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

char* readline();
char** split_string(char*);


struct NFAnode{
    int *transa;
    int numtransa;
    int *transb;
    int numtransb;
    int term;
};

struct NFA{
    struct NFAnode *nodes;
    int numnodes;
};

struct NFA makeNFA(char *r, int len){
    for(int i = 0; i < len; i++){
        printf("%c", r[i]);
    }
    printf("\n");
    if(len == 1){
        struct NFAnode *nodes = malloc(2*sizeof(struct NFAnode));
        int *templist = malloc(sizeof(int));
        templist[0] = 1;
        if(r[0] == 'a'){
            struct NFAnode temp = {templist, 1, NULL, 0, 0};
            nodes[0] = temp;
        }
        else{
            struct NFAnode temp = {NULL, 0, templist, 1, 0};
            nodes[0] = temp;
        }
        struct NFAnode temp = {NULL, 0, NULL, 0, 1};
        nodes[1] = temp;
        struct NFA toreturn = {nodes, 2};
        return toreturn;
    }
    else{
        assert(r[0] == '(' && r[len - 1] == ')');
        int oneparenpos = 1;
        int numparens = 1;
        while(oneparenpos == 1 || numparens > 1){
            if(r[oneparenpos] == '('){
                numparens++;
            }
            else if(r[oneparenpos] == ')'){
                numparens--;
            }
            oneparenpos++;
        }
        if(r[oneparenpos] == '*'){
            struct NFA tostar = makeNFA(r + 1, len - 3);
            for(int i = 1; i < tostar.numnodes; i++){
                if(tostar.nodes[i].term == 1){
                    if(tostar.nodes[0].numtransa > 0){
                        int oldnumtransa = tostar.nodes[i].numtransa;
                        tostar.nodes[i].numtransa += tostar.nodes[0].numtransa;
                        tostar.nodes[i].transa = realloc(tostar.nodes[i].transa, tostar.nodes[i].numtransa*sizeof(int));
                        for(int j = 0; j < tostar.nodes[0].numtransa; j++){
                            tostar.nodes[i].transa[oldnumtransa + j] = tostar.nodes[0].transa[j];
                        }
                    }

                    if(tostar.nodes[0].numtransb > 0){
                        int oldnumtransb = tostar.nodes[i].numtransb;
                        tostar.nodes[i].numtransb += tostar.nodes[0].numtransb;
                        tostar.nodes[i].transb = realloc(tostar.nodes[i].transb, tostar.nodes[i].numtransb*sizeof(int));
                        for(int j = 0; j < tostar.nodes[0].numtransb; j++){
                            tostar.nodes[i].transb[oldnumtransb + j] = tostar.nodes[0].transb[j];
                        }
                    }
                }
            }
            tostar.nodes[0].term = 1;
            return tostar;
        }
        else if(r[oneparenpos] == '|'){
            struct NFA left = makeNFA(r + 1, oneparenpos - 1);
            struct NFA right = makeNFA(r + oneparenpos + 1, len - oneparenpos - 2);
            
            int numnodes = left.numnodes + right.numnodes - 1;
            struct NFAnode *nodelist = malloc(numnodes*sizeof(struct NFAnode));
            for(int i = 0; i < left.numnodes; i++){
                nodelist[i] = left.nodes[i];
            }
            int oldnumtransa = nodelist[0].numtransa;
            if(right.nodes[0].numtransa > 0){
                nodelist[0].numtransa += right.nodes[0].numtransa;
                nodelist[0].transa = realloc(nodelist[0].transa, nodelist[0].numtransa*sizeof(int));
                for(int i = 0; i < right.nodes[0].numtransa; i++){
                    nodelist[0].transa[i + oldnumtransa] = right.nodes[0].transa[i] + left.numnodes - 1;
                }
            }

            int oldnumtransb = nodelist[0].numtransb;
            if(right.nodes[0].numtransb > 0){
                nodelist[0].numtransb += right.nodes[0].numtransb;
                nodelist[0].transb = realloc(nodelist[0].transb, nodelist[0].numtransb*sizeof(int));
                for(int i = 0; i < right.nodes[0].numtransb; i++){
                    nodelist[0].transb[i + oldnumtransb] = right.nodes[0].transb[i] + left.numnodes - 1;
                }
            }
            nodelist[0].term |= right.nodes[0].term;
            
            for(int i = 1; i < right.numnodes; i++){
                nodelist[left.numnodes + i - 1] = right.nodes[i];
                for(int j = 0; j < nodelist[left.numnodes + i - 1].numtransa; j++){
                    nodelist[left.numnodes + i - 1].transa[j] += left.numnodes - 1;
                }
                for(int j = 0; j < nodelist[left.numnodes + i - 1].numtransb; j++){
                    nodelist[left.numnodes + i - 1].transb[j] += left.numnodes - 1;
                }
            }
            struct NFA toreturn = {nodelist, numnodes};
            return toreturn;
        }
        else{
            struct NFA left = makeNFA(r + 1, oneparenpos - 1);
            struct NFA right = makeNFA(r + oneparenpos, len - oneparenpos - 1);

            int numnodes = left.numnodes + right.numnodes - 1;
            struct NFAnode *nodelist = malloc(numnodes*sizeof(struct NFAnode));

            for(int i = 0; i < left.numnodes; i++){
                nodelist[i] = left.nodes[i];
                if(nodelist[i].term == 1){
                    nodelist[i].term = right.nodes[0].term;

                    int oldnumtransa = nodelist[i].numtransa;
                    if(right.nodes[0].numtransa > 0){
                        nodelist[i].numtransa += right.nodes[0].numtransa;
                        nodelist[i].transa = realloc(nodelist[i].transa, nodelist[i].numtransa*sizeof(int));
                        for(int j = 0; j < right.nodes[0].numtransa; j++){
                            nodelist[i].transa[j + oldnumtransa] = right.nodes[0].transa[j] + left.numnodes - 1;
                        }
                    }

                    int oldnumtransb = nodelist[i].numtransb;
                    if(right.nodes[0].numtransb > 0){
                        nodelist[i].numtransb += right.nodes[0].numtransb;
                        nodelist[i].transb = realloc(nodelist[i].transb, nodelist[i].numtransb*sizeof(int));
                        for(int j = 0; j < right.nodes[0].numtransb; j++){
                            nodelist[i].transb[j + oldnumtransb] = right.nodes[0].transb[j] + left.numnodes - 1;
                        }
                    }
                }
            }
            for(int i = 1; i < right.numnodes; i++){
                nodelist[left.numnodes + i - 1] = right.nodes[i];
                for(int j = 0; j < nodelist[left.numnodes + i - 1].numtransa; j++){
                    nodelist[left.numnodes + i - 1].transa[j] += left.numnodes - 1;
                }
                for(int j = 0; j < nodelist[left.numnodes + i - 1].numtransb; j++){
                    nodelist[left.numnodes + i - 1].transb[j] += left.numnodes - 1;
                }
            }
            struct NFA toreturn = {nodelist, numnodes};
            return toreturn;
        }
    }
    struct NFA toreturn = {NULL, 0};
    return toreturn;
}


int countStrings(char* r, int l) {
    struct NFA theauto = makeNFA(r, strlen(r));
    
    printf("%d nodes\n", theauto.numnodes);
    for(int i = 0; i < theauto.numnodes; i++){
        printf("node %d a: %d:\t", i, theauto.nodes[i].numtransa);
        for(int j = 0; j < theauto.nodes[i].numtransa; j++){
            printf("%d ", theauto.nodes[i].transa[j]);
        }
        printf("b: %d:\t", theauto.nodes[i].numtransb);
        for(int j = 0; j < theauto.nodes[i].numtransb; j++){
            printf("%d ", theauto.nodes[i].transb[j]);
        }
        printf("t: %d\n", theauto.nodes[i].term);
    }
    printf("\n");

    long moveamask[theauto.numnodes];
    long movebmask[theauto.numnodes];
    for(int i = 0; i < theauto.numnodes; i++){
        moveamask[i] = 0;
        for(int j = 0; j < theauto.nodes[i].numtransa; j++){
            moveamask[i] |= 1<<theauto.nodes[i].transa[j];
        }
        movebmask[i] = 0;
        for(int j = 0; j < theauto.nodes[i].numtransb; j++){
            movebmask[i] |= 1<<theauto.nodes[i].transb[j];
        }
        //printf("i: %d ma: %ld mb: %ld\n", i, moveamask[i], movebmask[i]);
    }

    long *multimovemaskqueue = malloc(sizeof(long));
    multimovemaskqueue[0] = 1;
    int queuesize = 1;
    int queuedone = 0;
    int *statetransa = NULL;
    int *statetransb = NULL;
    while(queuedone < queuesize){
        long currmask = multimovemaskqueue[queuedone];
        queuedone++;
        long nextamask = 0;
        long nextbmask = 0;
        for(int j = 0; j < theauto.numnodes; j++){
            if(((currmask>>j)&1) == 1){
                nextamask |= moveamask[j];
                nextbmask |= movebmask[j];
            }
        }
        int aisinqueue = 0;
        for(int i = 0; i < queuesize; i++){
            if(nextamask == multimovemaskqueue[i]){
                aisinqueue = 1;
                statetransa = realloc(statetransa, queuedone*sizeof(int));
                statetransa[queuedone - 1] = i;
                break;
            }
        }
        if(aisinqueue == 0){
            queuesize++;
            multimovemaskqueue = realloc(multimovemaskqueue, queuesize*sizeof(long));
            multimovemaskqueue[queuesize - 1] = nextamask;

            statetransa = realloc(statetransa, queuedone*sizeof(int));
            statetransa[queuedone - 1] = queuesize - 1;
        }
        int bisinqueue = 0;
        for(int i = 0; i < queuesize; i++){
            if(nextbmask == multimovemaskqueue[i]){
                bisinqueue = 1;
                statetransb = realloc(statetransb, queuedone*sizeof(int));
                statetransb[queuedone - 1] = i;
                break;
            }
        }
        if(bisinqueue == 0){
            queuesize++;
            multimovemaskqueue = realloc(multimovemaskqueue, queuesize*sizeof(long));
            multimovemaskqueue[queuesize - 1] = nextbmask;

            statetransb = realloc(statetransb, queuedone*sizeof(int));
            statetransb[queuedone - 1] = queuesize - 1;
        }

    }

    for(int i = 0; i < queuesize; i++){
        printf("%ld ", multimovemaskqueue[i]);
    }
    printf("\n");

    int logl = 0;
    while(l>>logl > 0){
        logl++;
    }

    long statetransmat[logl][queuesize][queuesize];
    for(int i = 0; i < queuesize; i++){
        for(int j = 0; j < queuesize; j++){
            statetransmat[0][i][j] = 0;
        }
    }

    for(int i = 0; i < queuesize; i++){
        statetransmat[0][i][statetransa[i]] += 1;
        statetransmat[0][i][statetransb[i]] += 1;
    }

    for(int i = 1; i < logl; i++){
        for(int j = 0; j < queuesize; j++){
            for(int k = 0; k < queuesize; k++){
                statetransmat[i][j][k] = 0;
            }
        }

        for(int j = 0; j < queuesize; j++){
            for(int k = 0; k < queuesize; k++){
                for(int m = 0; m < queuesize; m++){
                    statetransmat[i][j][m] = (statetransmat[i][j][m] + statetransmat[i - 1][j][k]*statetransmat[i - 1][k][m])%MOD;
                }
            }
        }
    }

    long state[queuesize];
    for(int i = 0; i < queuesize; i++){
        state[i] = 0;
    }
    state[0] = 1;

    for(int i = 0; i < logl; i++){
        if(((l>>i)&1) == 1){
            long nextstate[queuesize];
            for(int j = 0; j < queuesize; j++){
                nextstate[j] = 0;
            }
            for(int j = 0; j < queuesize; j++){
                for(int k = 0; k < queuesize; k++){
                    nextstate[j] = (nextstate[j] + statetransmat[i][k][j]*state[k])%MOD;
                }
            }
            for(int j = 0; j < queuesize; j++){
                state[j] = nextstate[j];
            }
        }
    }

    int toreturn = 0;
    for(int i = 0; i < queuesize; i++){
        int isterm = 0;
        for(int j = 0; j < theauto.numnodes; j++){
            if(((multimovemaskqueue[i]>>j)&1) == 1 && theauto.nodes[j].term == 1){
                isterm = 1;
                break;
            }
        }
        toreturn = (toreturn + isterm*state[i])%MOD;
    }

    return toreturn%MOD;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** rl = split_string(readline());

        char* r = rl[0];

        char* l_endptr;
        char* l_str = rl[1];
        int l = strtol(l_str, &l_endptr, 10);

        if (l_endptr == l_str || *l_endptr != '\0') { exit(EXIT_FAILURE); }

        int result = countStrings(r, l);

        fprintf(fptr, "%d\n", result);
    }

    fclose(fptr);

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
    if(data[data_length - 1] != '\0'){
        data_length++;
        data = realloc(data, data_length);
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
