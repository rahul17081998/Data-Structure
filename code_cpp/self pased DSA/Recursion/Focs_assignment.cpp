#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10000

/**********************************************************/
/************** Stack Datatype and Operations *************/
/**********************************************************/

// stack structure declaration
typedef struct stackADT {
    char opr[MAX];
    int top;
} Stack;

// initialize stack
void initStack (Stack *stack)
{
    stack->top = -1;
}

// check whether stack is empty
int isEmptyStack (Stack *stack)
{
    return (stack->top == -1);
}

// check whether stack is full
int isFullStack (Stack *stack)
{
    return (stack->top == MAX-1);
}

// push an element into stack
void push (Stack *stack, char x)
{
    if (isFullStack(stack))
        printf("Error: Stack is Full!\n");
    else
        stack->opr[++(stack->top)] = x;
}

// pop an element from stack
char pop (Stack *stack)
{
    char x;
    if (isEmptyStack(stack))
        printf("Error: Stack is Empty!\n");
    else
        x = stack->opr[(stack->top)--];
    return x;
}

/**********************************************************/


/**********************************************************/
/*********** Binary Tree Datatype and Operations **********/
/**********************************************************/

// binary tree structure declaration
typedef struct binTree {
    char element;
    struct binTree *leftChild;
    struct binTree *rightChild;
} BT;

// creating a node in binary tree
BT *createNode (char el)
{
    BT *newNode;
    if ( (newNode=(BT *)malloc(sizeof(BT))) == NULL )
        printf("Error: Malloc Error in Creating Node!\n");
    else {
        newNode->element = el;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
    }
    return (newNode);
}

// creating an exact replica of the the binary tree
BT *duplicate(BT *orig)
{
    BT *dup = NULL;
    if(orig != NULL) {
        dup = createNode(orig->element);
        dup->leftChild = duplicate(orig->leftChild);
        dup->rightChild = duplicate(orig->rightChild);
    }
    return (dup);
}

/**********************************************************/


/**********************************************************/
/******************** Utility Functions *******************/
/**********************************************************/

// structure holding propositional values
typedef struct PropVal {
    char prop;
    int val; // '0' for False and '1' for True
} PV;

// scan every propositional values (one by one) from user as input
PV *scanPropValueInput()
{
    unsigned int noProp, i;
    PV *pvarr;
    
    printf("Enter Total Number of Propositions: ");
    scanf("%u",&noProp);
    
    pvarr = (PV *)malloc(noProp * sizeof(PV));
    
    for (i = 0; i < noProp; i++) {
        printf("Enter Proposition [%u] (Format: Name <SPACE> Value): ", i+1);
        scanf(" %c %d", &pvarr[i].prop, &pvarr[i].val);
    }
    return pvarr;
}

// determines whether p is a proposition including 0 or 1
int isProposition (char p)
{
    return ( ((p >= 'a') && (p <= 'z')) || ((p >= 'A') && (p <= 'Z')) || (p == '0') || (p == '1') );
}

// printing the validity and satisfiability flags
void printResult (int valid, int sat)
{
    printf("\nThe Given Formula is: < ");
    valid ? printf("VALID") : printf("INVALID");
    printf(" + ");
    sat ? printf("SATISFIABLE") : printf("UNSATISFIABLE");
    printf(" >\n\n");
}

//display postfix form of propositional formula (from internally represented string)
void displayPfForm(char *pfForm)
{
    int i;
    
    printf("Postfix Representation of Formula:");
    for(i = 0; pfForm[i] != '\0'; i++){
        if ( pfForm[i] == '-' )
            printf(" ->");
        else if (pfForm[i] == '~')
            printf(" <->");
        else
            printf(" %c", pfForm[i]);
    }
    printf("\n");
}

// count number of characters in the formula representing only propositions and operators
int noOfIdsInFormula (char *formula)
{
    int i, len = strlen(formula), count = 0;
    for(i = 0; i < len; i++){
        if ( (formula[i] != '(') && (formula[i] != ')') && (formula[i] != ' ') && (formula[i] != '\t') )
            count++;
    }
    return count;
}

// pre-defined priority of in-stack element
int inStackPriority (char operator){
    switch(operator){
        case '!': return 3; break;
        
        case '&':
        case '|': return 2; break;
        
        case '~':
        case '-': return 1; break;
        
        case '(': return 0; break;
        
        default : return -1; break;
    }
}

// pre-defined priority of in-coming element
int inComingPriority (char operator){
    switch(operator){
        case '!': return 4; break;
        
        case '&':
        case '|': return 2; break;
        
        case '~':
        case '-': return 1; break;
        
        case '(': return 4; break;
        
        default : return -1; break;
    }
}

// generate postfix formula from the given input formula
char *genPostFixFormula(char *formula)
{
    int noOfIds = noOfIdsInFormula(formula), i, len = strlen(formula), k;
    char *pf = (char *)malloc((noOfIds+1) * sizeof(char));
    char out;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    initStack(stack); push(stack,'#');
    
    for (i = 0, k = 0; i < len; i++){
        if ( (formula[i] != ' ') && (formula[i] != '\t') ){
            if ( isProposition(formula[i]) )
                pf[k++] = formula[i];
            else if (formula[i] == ')') {
                while ( (out = pop(stack)) != '(')
                    pf[k++] = out;
            }
            else {
                while ( inStackPriority(out = pop(stack)) >= inComingPriority(formula[i]) )
                    pf[k++] = out;
                push(stack, out);
                push(stack, formula[i]);
            }
        }
    }
    while( (out = pop(stack)) != '#' )
        pf[k++] = out;
    pf[k] = '\0';
    
    return pf;
}

/**********************************************************/





/**********************************************************/
/****************** YOUR CODE STARTS HERE *****************/
/**********************************************************/

// returns the value of a proposition that resides in the array pvarr[]
int findPropValue (PV *pvarr, char p)
{
    int i = 0, found = 0, v = -1;
    while(!found) {
        if (pvarr[i].prop == p) {
            found = 1;
            v = pvarr[i].val;
        }
        i++;
    }
    return v;
}

int findBreakPoint(char *pfForm, int start, int end) {
    int i, flag = 0;
    for (i = end; (i >= start) && (flag>=0); i--) {
        if ( (pfForm[i] == '~') || (pfForm[i] == '-') || (pfForm[i] == '&') || (pfForm[i] == '|') )
            flag ++;
        if ( isProposition(pfForm[i]) )
            flag --;
    }
    return (i+1);
}

// expression tree formation from postfix formula string
BT *ETF (char *pfForm, int start, int end)
{
    BT *et;
    int k, len = end - start + 1;
    
    if (len == 1) { // formation for only a 'proposition'
        et = createNode(pfForm[end]);
    }
    else if ( (len > 1) && (pfForm[end] == '!') ) { // formation for '!prop'
        et = createNode(pfForm[end]);
        et->rightChild = ETF(pfForm, start, end-1);
    }
    else if ( (len > 2) && ((pfForm[end] == '~') || (pfForm[end] == '-') || (pfForm[end] == '&') || (pfForm[end] == '|')) ) {
        k = findBreakPoint(pfForm, start, end-1);
        et = createNode(pfForm[end]);
        et->leftChild = ETF(pfForm, start, k-1);
        et->rightChild = ETF(pfForm, k, end-1);
    }
    else {
        et = NULL;
    }
    
    return et;
}

// printing the expresion tree using inorder traversal
void ETP (BT *et)
{
    if (et != NULL) {
        if ( (et->leftChild != NULL) && (et->element != '!'))
            printf(" (");
        ETP(et->leftChild);
        if (et->element == '~')
            printf(" <->");
        else if (et->element == '-')
            printf(" ->");
        else
            printf(" %c", et->element);
        ETP(et->rightChild);
        if ( (et->rightChild != NULL) && (et->element != '!'))
            printf(" )"); 
    }
}

// evaluate the formula from the expression tree from the proposition values provided in varr[] array
int EVAL (BT *et, PV *pvarr)
{
    int result;
    
    if ( isProposition(et->element) ) {
        if (et->element == '0')
            result = 0;
        else if (et->element == '1')
            result = 1;
        else
            result = findPropValue(pvarr, et->element);
    }
    else if ( et->element == '!' )
        result = !EVAL(et->rightChild, pvarr);
    else if ( et->element == '&' )
        result = (EVAL(et->leftChild, pvarr) && EVAL(et->rightChild, pvarr));
    else if ( et->element == '|' )
        result = (EVAL(et->leftChild, pvarr) || EVAL(et->rightChild, pvarr));
    else if ( et->element == '-' )
        result = (!EVAL(et->leftChild, pvarr) || EVAL(et->rightChild, pvarr));
    else
        result = ((EVAL(et->leftChild, pvarr) && EVAL(et->rightChild, pvarr)) || (!EVAL(et->leftChild, pvarr) && !EVAL(et->rightChild, pvarr)));
    
    return result;
}

// convert expression tree to IFF expression tree
BT *IFF (BT *et)
{
    BT *etL, *etR;
    
    if (et != NULL) {
        if (et->element == '!')
            et->rightChild = IFF(et->rightChild);
        if ( (et->element == '&') || (et->element == '|') ) {
            et->leftChild = IFF(et->leftChild);
            et->rightChild = IFF(et->rightChild);
        }
        if (et->element == '-') {
            et->element = '|';
            et->rightChild = IFF(et->rightChild);
            etL = et->leftChild;
            et->leftChild = createNode('!');
            (et->leftChild)->rightChild = IFF(etL);
        }
        if (et->element == '~') {
            et->element = '&';
            etL = et->leftChild;
            etR = et->rightChild;
            et->leftChild = createNode('-');
            et->rightChild = createNode('-');
            (et->leftChild)->leftChild = etL;
            (et->leftChild)->rightChild = etR;
            (et->rightChild)->leftChild = etR;
            (et->rightChild)->rightChild = etL;
            et->leftChild = IFF(et->leftChild);
            et->rightChild = IFF(et->rightChild);
        }
    }
    
    return et;
}

// convert IFF expression tree to NNF expression tree
BT *NNF (BT *etI)
{
    BT *etL, *etR, *etLNew, *etRNew;
    
    if (etI != NULL) {
        if (etI->element == '!') {
            if ( (etI->rightChild)->element == '!')
                return (NNF((etI->rightChild)->rightChild));
            if ( (etI->rightChild)->element == '&' ) {
                etL = (etI->rightChild)->leftChild;
                etR = (etI->rightChild)->rightChild;
                etLNew = createNode('!');
                etLNew->rightChild = etL;
                etRNew = createNode('!');
                etRNew->rightChild = etR;
                etI->element = '|';
                etI->leftChild = NNF(etLNew);
                etI->rightChild = NNF(etRNew);
            }
            if ( (etI->rightChild)->element == '|' ) {
                etL = (etI->rightChild)->leftChild;
                etR = (etI->rightChild)->rightChild;
                etLNew = createNode('!');
                etLNew->rightChild = etL;
                etRNew = createNode('!');
                etRNew->rightChild = etR;
                etI->element = '&';
                etI->leftChild = NNF(etLNew);
                etI->rightChild = NNF(etRNew);
            }
        }
        if ( (etI->element == '&') || (etI->element == '|') ) {
            etI->leftChild = NNF(etI->leftChild);
            etI->rightChild = NNF(etI->rightChild);
        }
    }
    
    return etI;
}

// convert NNF expression tree to CNF expression tree
BT *CNF (BT *etN)
{
    BT *etLR, *etRL, *etL, *etR, *etDup;
    
    if (etN != NULL){
        if (etN->element == '&') {
            etN->leftChild = CNF(etN->leftChild);
            etN->rightChild = CNF(etN->rightChild);
        }
        if (etN->element == '|') {
            etN->leftChild = CNF(etN->leftChild);
            etN->rightChild = CNF(etN->rightChild);
            
            if ((etN->leftChild)->element == '&') {
                //etLL = (etN->leftChild)->leftChild;
                etLR = (etN->leftChild)->rightChild;
                etR = etN->rightChild;
                etDup = duplicate(etR);
                etN->element = '&';
                (etN->leftChild)->element = '|';
                etN->rightChild = createNode('|');
                //(etN->leftChild)->leftChild = etLL;
                (etN->leftChild)->rightChild = etR;
                (etN->rightChild)->leftChild = etLR;
                (etN->rightChild)->rightChild = etDup;
                //etN->leftChild = CNF(etN->leftChild);
                //etN->rightChild = CNF(etN->rightChild);
            }
            if ((etN->rightChild)->element == '&') {
                etRL = (etN->rightChild)->leftChild;
                //etRR = (etN->rightChild)->rightChild;
                etL = etN->leftChild;
                etDup = duplicate(etL);
                etN->element = '&';
                (etN->rightChild)->element = '|';
                etN->leftChild = createNode('|');
                (etN->leftChild)->leftChild = etL;
                (etN->leftChild)->rightChild = etRL;
                (etN->rightChild)->leftChild = etDup;
                //(etN->rightChild)->rightChild = etRR;
                //etN->leftChild = CNF(etN->leftChild);
                //etN->rightChild = CNF(etN->rightChild);
            }
            if ((etN->leftChild)->element == '|') {
                etN->leftChild = CNF(etN->leftChild);
            }
            if ((etN->rightChild)->element == '|') {
                etN->rightChild = CNF(etN->rightChild);
            }
        }
    }
    
    return etN;
}

// convert NNF expression tree to DNF expression tree
BT *DNF (BT *etN)
{
    BT *etLR, *etRL, *etL, *etR, *etDup;
    
    if (etN != NULL){
        if (etN->element == '|') {
            etN->leftChild = DNF(etN->leftChild);
            etN->rightChild = DNF(etN->rightChild);
        }
        if (etN->element == '&') {
            etN->leftChild = DNF(etN->leftChild);
            etN->rightChild = DNF(etN->rightChild);
            
            if ((etN->leftChild)->element == '|') {
                //etLL = (etN->leftChild)->leftChild;
                etLR = (etN->leftChild)->rightChild;
                etR = etN->rightChild;
                etDup = duplicate(etR);
                etN->element = '|';
                (etN->leftChild)->element = '&';
                etN->rightChild = createNode('&');
                //(etN->leftChild)->leftChild = etLL;
                (etN->leftChild)->rightChild = etR;
                (etN->rightChild)->leftChild = etLR;
                (etN->rightChild)->rightChild = etDup;
            }
            if ((etN->rightChild)->element == '|') {
                etRL = (etN->rightChild)->leftChild;
                //etRR = (etN->rightChild)->rightChild;
                etL = etN->leftChild;
                etDup = duplicate(etL);
                etN->element = '|';
                (etN->rightChild)->element = '&';
                etN->leftChild = createNode('&');
                (etN->leftChild)->leftChild = etL;
                (etN->leftChild)->rightChild = etRL;
                (etN->rightChild)->leftChild = etDup;
                //(etN->rightChild)->rightChild = etRR;
            }
            if ((etN->leftChild)->element == '&') {
                etN->leftChild = DNF(etN->leftChild);
            }
            if ((etN->rightChild)->element == '&') {
                etN->rightChild = DNF(etN->rightChild);
            }
        }
    }
    
    return etN;
}

// exhaustive value generation for propositions and case-by-case evaluation
void exhaustiveEval(BT *et, int n, PV *pvarr, int i, int *result, int *k)
{
    int j;
    if (i == n) {
        printf("\t{");
        for(j=0; j<n; j++)
            printf(" (%c = %d)", pvarr[j].prop, pvarr[j].val);
        printf(" }  :  ");
        result[(*k)++] = EVAL(et, pvarr);
        printf("%d\n", result[(*k)-1]);
        return;
    }
    
    pvarr[i].val = 0;
    exhaustiveEval(et, n, pvarr, i+1, result, k);
    
    pvarr[i].val = 1;
    exhaustiveEval(et, n, pvarr, i+1, result, k);
}

// exhaustive search for checking validity / satisfiability
void CHECK (BT *et)
{
    unsigned int i, noProp;
    int valid = 1, sat = 0, k=0, noEval;
    int *result;
    PV *pvarr;
    
    printf("\nEnter Number of Propositions: ");
    scanf("%u", &noProp);
    printf("Enter Proposition Names (<SPACE> Separated): ");
    pvarr = (PV *)malloc(noProp * sizeof(PV));
    for (i = 0; i < noProp; i++) {
        scanf(" %c", &(pvarr[i].prop));
    }
    
    printf("Evaluations of the Formula:\n");
    noEval = pow(2,noProp);
    result = (int *)malloc(noEval * sizeof(int));
    exhaustiveEval(et, noProp, pvarr, 0, result, &k);
    for (i = 0; valid && (i<noEval); i++){
        if (!result[i])
            valid = 0;
    }
    for (i = 0; !sat && (i<noEval); i++){
        if (result[i])
            sat = 1;
    }
    
    printResult(valid,sat);
}

/**********************************************************/
/******************* YOUR CODE ENDS HERE ******************/
/**********************************************************/





// main routine
int main ()
{
    char formula[MAX], *pfForm;
    int len, i;
    
    BT *et, *etI, *etN, *etDup, *etC, *etD;
    int *varr;
    PV *pvarr;
    int result;
    
    // scan propositional formula from user input
    printf("\nEnter Propositional Logic Formula: ");
    scanf("%[^\n]", formula);
    
    // internal formula string with operators as, AND (&), OR (|), NOT (!), IMPLY (-) and IFF (~)
    len = strlen(formula);
    for(i = 0; i < len; i++){
        if(formula[i] == '<'){ // denoting iff operator (<->) using ~
            formula[i] = ' ';
            formula[i+1] = '~';
        }
        if(formula[i] == '>'){ // denoting imply operator (->) using -
            formula[i] = ' ';
        }
    }
    
    // postfix form generation from represented formula string
    pfForm = genPostFixFormula(formula);
    
    // display postfix form of the internally represented formula
    displayPfForm(pfForm);
    
    // internal postfix formula string with operators as, AND (&), OR (|), NOT (!), IMPLY (-) and IFF (~)
    printf("\n++++ PostFix Format of the Propositional Formula ++++\n('-' used for '->' and '~' used for '<->')\n");
    printf("YOUR INPUT STRING: %s\n", pfForm);
    
    
    
    /**********************************************************/
    /********** YOUR CODE ENABLES THE FOLLOWING PARTS *********/
    /**********************************************************/
    
    printf("\n++++ Expression Tree Generation ++++");
    et = ETF(pfForm, 0, strlen(pfForm)-1);
    printf("\nOriginal Formula (from Expression Tree):");
    ETP(et);
    printf("\n");
    
    printf("\n++++ Expression Tree Evaluation ++++\n");
    pvarr = scanPropValueInput();
    result = EVAL(et, pvarr);
    printf("\nThe Formula is Evaluated as: ");
    (result) ? printf("True\n") : printf("False\n");
    
    printf("\n++++ IFF Expression Tree Conversion ++++");
    etI = IFF(et);
    printf("\nFormula in Implication Free Form (IFF from Expression Tree):");
    ETP(etI);
    printf("\n");
    
    printf("\n++++ NNF Expression Tree Conversion ++++");
    etN = NNF(etI);
    printf("\nFormula in Negation Normal Form (NNF from Expression Tree):");
    ETP(etN);
    printf("\n");
    
    etDup = duplicate(etN); // keeping a duplicate copy for DNF conversion
    
    printf("\n++++ CNF Expression Tree Conversion ++++");
    etC = CNF(etN);
    printf("\nFormula in Conjunctive Normal Form (CNF from Expression Tree):");
    ETP(etC);
    printf("\n");
    
    printf("\n++++ DNF Expression Tree Conversion ++++");
    etD = DNF(etDup);
    printf("\nFormula in Disjunctive Normal Form (DNF from Expression Tree):");
    ETP(etD);
    printf("\n");
    
    printf("\n++++ Exhaustive Search from Expression Tree for Validity / Satisfiability Checking ++++");
    CHECK (et);
    
    /**********************************************************/
    
    
    
    return 0;
}