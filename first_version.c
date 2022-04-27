#include <stdio.h>
#include <string.h>
#include "create_twitter.h"

void create_twitter_system(twitter * twitter_system) {
    int n;
    printf("number of users for twitter system: \n");
    scanf("%d", &n);
    if (n > MAX_USERS) {
        printf("number of user is too big\nre-enter a value");
        scanf("%d", &n);
    }
    twitter_system -> num_users = 0;
    twitter_system -> num_tweets = 0;

    printf("Enter a user into the command pannel, then press <enter> to input another user:\n");
    for (int i = 0; i < n + 1; i++) {
        //use fgets to retrieve the username for each user
        fgets(&twitter_system -> users[i - 1] .username, USR_LENGHT, stdin);
        //declare length of each username
        int size = strlen(twitter_system -> users[i - 1].username);
        //set default values to each user
        twitter_system -> users -> num_followers = 0;
        twitter_system -> users -> num_following = 0;
        //replace newline character with null termination character
        twitter_system -> users[i - 1].username[size - 1] = '\0';

        twitter_system -> num_users ++;
    }
}