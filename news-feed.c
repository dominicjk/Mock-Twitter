#include <string.h>
#include <stdio.h>
#include "news-feed.h"

/* the news-feed function will iterate over the news-feed array (the array that contains all tweets) from the last element.
 * if the author of a tweet is the same as someone a already follows, that tweet will get stored in a node. This will be 
 * performed 9 more times (or until the tweet-array is finished). The 10 tweets are then displayed to the user.
 */

void newsfeed(user* a, twitter *system) {
    int count = 0; //count variable to ensure no more than ten tweets are printed
    StackNodePtr stackPtr = NULL;  //initially node will point to NULL
    
    //search through the total tweet array
    for (int i = 0; i <= system -> num_tweets; i++) {
        if (count >= 10) { //break loop if ten tweets are already printed
            break;
        }
        for (int j = a ->num_following; j >= 0; j--) {
            if (count >= 10) { //break loop if ten tweets are already printed
                break;
            }
            //if the author of tweet is someone a follows, then print that tweet
            if (strcmp(a->following[j], system->news_feed[i].author) == 0) {
                StackNodePtr newPtr = malloc(sizeof(StackNode)); //allocate memory for node
                
                //if memory is available, store the message in the node
                if (newPtr != NULL) {
                    strcpy(&newPtr ->message.msg, system -> news_feed[i].msg); //store message
                    strcpy(&newPtr ->message.author, system -> news_feed[i].author); //store author
                    newPtr->nextPtr = stackPtr;
                    stackPtr = newPtr;
                }
                //if no memory is available 
                else {
                    printf("No memory available.\n");
                }

                //printf("%s\n", system -> news_feed[i-1].msg);
                count++;

            }
        }


    }
    
    //if stack is empty 
    if (stackPtr == NULL) {
        puts("The stack is empty\n");
    }
    else {
        printf("10 most recent tweets from the people %s follows\n", a->username);
        // while not the end of the stack
        int i = 0;
        while (stackPtr != NULL) {
            if (i == 0) {
                stackPtr = stackPtr->nextPtr; //point to next node
                printf("\n");
            }
            else {
                //print message and author in that specific node
                printf("==| %s => tweeted by %s\n\n", stackPtr->message.msg, stackPtr->message.author);
                stackPtr = stackPtr->nextPtr; //point to next node
            }
            i++; 
        }
    }
}