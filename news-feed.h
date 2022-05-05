#ifndef COMP10050_PROJECT_NEWS-FEED_H
#define COMP10050_PROJECT_NEWS-FEED_H

#endif //COMP10050_PROJECT_NEWS-FEED_H

void newsfeed(user* a, twitter *system);

struct stackNode {
    tweet message; /* each listNode contains a character */
    struct stackNode *nextPtr; /* pointer to next node */
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;